/* freer.c: newlib libc (libc/stdlib/freer.c = mallocr.c with DEFINE_FREE: _free_r and _malloc_trim_r, Doug Lea's
 * malloc 2.6.4), the copy the game links from the toolchain's libc.a. Linked unit 0x302e90-0x3032d0. The malloc
 * state (__malloc_av_ and the statistics) is defined in mallocr.c. Third-party code notice: rebuilt to match; not
 * covered by this project's MIT License. malloc was written by Doug Lea and released to the public domain. */
#include "newlib.h"
asm("_sbrk_r = func_002fea70");
void *_sbrk_r(struct _reent *, int);
void __malloc_lock(struct _reent *);
void __malloc_unlock(struct _reent *);
struct malloc_chunk {
    size_t prev_size;
    size_t size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};
typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;

struct mallinfo {
    int arena, ordblks, smblks, hblks, hblkhd, usmblks, fsmblks, uordblks, fordblks, keepcost;
};

#define SIZE_SZ 4
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define MINSIZE 16
#define PREV_INUSE 1
#define SIZE_BITS 3
#define NAV 128
#define MAX_SMALLBIN 63
#define MAX_SMALLBIN_SIZE 512
#define SMALLBIN_WIDTH 8
#define BINBLOCKWIDTH 4
#define DEFAULT_TRIM_THRESHOLD (128L * 1024L)
#define DEFAULT_TOP_PAD 0

#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 2 * SIZE_SZ))
#define next_bin(b) ((mbinptr)((char *)(b) + 2 * sizeof(mbinptr)))
#define prev_bin(b) ((mbinptr)((char *)(b) - 2 * sizeof(mbinptr)))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define initial_top ((mchunkptr)(bin_at(0)))
#define binblocks (bin_at(0)->size)
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define idx2binblock(ix) ((unsigned long)1 << (ix / BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define long_sub_size_t(x, y) (((x) < (y)) ? -(long)((y) - (x)) : (long)((x) - (y)))
#define frontlink(P, S, IDX, BK, FD) \
{ \
  if (S < MAX_SMALLBIN_SIZE) \
  { \
    IDX = smallbin_index(S); \
    mark_binblock(IDX); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
  else \
  { \
    IDX = bin_index(S); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else \
    { \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd; \
      BK = FD->bk; \
    } \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
}

#define av_ __malloc_av_
extern mbinptr __malloc_av_[];
extern unsigned long __malloc_trim_threshold;
extern unsigned long __malloc_top_pad;
extern char *__malloc_sbrk_base;
extern struct mallinfo __malloc_current_mallinfo;
#define trim_threshold __malloc_trim_threshold
#define top_pad __malloc_top_pad
#define sbrk_base __malloc_sbrk_base
#define current_mallinfo __malloc_current_mallinfo
#define sbrked_mem (current_mallinfo.arena)
#define mem2chunk(mem) ((mchunkptr)((char *)(mem) - 2 * SIZE_SZ))
#define inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size & PREV_INUSE)
#define MORECORE(size) _sbrk_r(reent_ptr, (size))
#define MORECORE_FAILURE -1

int _malloc_trim_r(struct _reent *, size_t);

void _free_r(struct _reent *reent_ptr, void *mem)
{
  mchunkptr p;         /* chunk corresponding to mem */
  size_t hd;           /* its head field */
  size_t sz;           /* its size */
  int       idx;       /* its bin index */
  mchunkptr next;      /* next contiguous chunk */
  size_t nextsz;       /* its size */
  size_t prevsz;       /* size of previous contiguous chunk */
  mchunkptr bck;       /* misc temp for linking */
  mchunkptr fwd;       /* misc temp for linking */
  int       islr;      /* track whether merging with last_remainder */

  if (mem == 0)                              /* free(0) has no effect */
    return;

  __malloc_lock(reent_ptr);

  p = mem2chunk(mem);
  hd = p->size;

  sz = hd & ~PREV_INUSE;
  next = chunk_at_offset(p, sz);
  nextsz = chunksize(next);

  if (next == top)                            /* merge with top */
  {
    sz += nextsz;

    if (!(hd & PREV_INUSE))                    /* consolidate backward */
    {
      prevsz = p->prev_size;
      p = chunk_at_offset(p, -prevsz);
      sz += prevsz;
      unlink(p, bck, fwd);
    }

    set_head(p, sz | PREV_INUSE);
    top = p;
    if ((unsigned long)(sz) >= (unsigned long)trim_threshold)
      _malloc_trim_r(reent_ptr, top_pad);
    __malloc_unlock(reent_ptr);
    return;
  }

  set_head(next, nextsz);                    /* clear inuse bit */

  islr = 0;

  if (!(hd & PREV_INUSE))                    /* consolidate backward */
  {
    prevsz = p->prev_size;
    p = chunk_at_offset(p, -prevsz);
    sz += prevsz;

    if (p->fd == last_remainder)             /* keep as last_remainder */
      islr = 1;
    else
      unlink(p, bck, fwd);
  }

  if (!(inuse_bit_at_offset(next, nextsz)))   /* consolidate forward */
  {
    sz += nextsz;

    if (!islr && next->fd == last_remainder)  /* re-insert last_remainder */
    {
      islr = 1;
      link_last_remainder(p);
    }
    else
      unlink(next, bck, fwd);
  }


  set_head(p, sz | PREV_INUSE);
  set_foot(p, sz);
  if (!islr)
    frontlink(p, sz, idx, bck, fwd);

  __malloc_unlock(reent_ptr);
}

int _malloc_trim_r(struct _reent *reent_ptr, size_t pad)
{
  long  top_size;        /* Amount of top-most memory */
  long  extra;           /* Amount to release */
  char* current_brk;     /* address returned by pre-check sbrk call */
  char* new_brk;         /* address returned by negative sbrk call */

  unsigned long pagesz = 4096;

  __malloc_lock(reent_ptr);

  top_size = chunksize(top);
  extra = ((top_size - pad - MINSIZE + (pagesz-1)) / pagesz - 1) * pagesz;

  if (extra < (long)pagesz)  /* Not enough memory to release */
  {
    __malloc_unlock(reent_ptr);
    return 0;
  }

  else
  {
    /* Test to make sure no one else called sbrk */
    current_brk = (char*)(MORECORE (0));
    if (current_brk != (char*)(top) + top_size)
    {
      __malloc_unlock(reent_ptr);
      return 0;     /* Apparently we don't own memory; must fail */
    }

    else
    {
      new_brk = (char*)(MORECORE (-extra));

      if (new_brk == (char*)(MORECORE_FAILURE)) /* sbrk failed? */
      {
        /* Try to figure out what we have */
        current_brk = (char*)(MORECORE (0));
        top_size = current_brk - (char*)top;
        if (top_size >= (long)MINSIZE) /* if not, we are very very dead! */
        {
          sbrked_mem = current_brk - sbrk_base;
          set_head(top, top_size | PREV_INUSE);
        }
        __malloc_unlock(reent_ptr);
        return 0;
      }

      else
      {
        /* Success. Adjust top accordingly. */
        set_head(top, (top_size - extra) | PREV_INUSE);
        sbrked_mem -= extra;
        __malloc_unlock(reent_ptr);
        return 1;
      }
    }
  }
}
