/* mallocr.c: newlib libc (libc/stdlib/mallocr.c, Doug Lea's malloc 2.6.4 as built for malloc.o's _malloc_r),
 * the copy the game links from the toolchain's libc.a. Linked unit 0x2fd428-0x2fdd68 with its .data at 0x365c50
 * (__malloc_av_ and the malloc statistics, defined here). Third-party code notice: rebuilt to match; not covered
 * by this project's MIT License. malloc was written by Doug Lea and released to the public domain. */
#include "newlib.h"
asm("_sbrk_r = func_002fea70");
void *_sbrk_r(struct _reent *, int);
void _free_r(struct _reent *, void *);
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
#define request2size(req) (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
    (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define is_small_request(nb) (nb < MAX_SMALLBIN_SIZE - SMALLBIN_WIDTH)
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
#define IAV(i) bin_at(i), bin_at(i)
mbinptr __malloc_av_[];
mbinptr __malloc_av_[NAV * 2 + 2] = {
    0, 0,
    IAV(0), IAV(1), IAV(2), IAV(3), IAV(4), IAV(5), IAV(6), IAV(7),
    IAV(8), IAV(9), IAV(10), IAV(11), IAV(12), IAV(13), IAV(14), IAV(15),
    IAV(16), IAV(17), IAV(18), IAV(19), IAV(20), IAV(21), IAV(22), IAV(23),
    IAV(24), IAV(25), IAV(26), IAV(27), IAV(28), IAV(29), IAV(30), IAV(31),
    IAV(32), IAV(33), IAV(34), IAV(35), IAV(36), IAV(37), IAV(38), IAV(39),
    IAV(40), IAV(41), IAV(42), IAV(43), IAV(44), IAV(45), IAV(46), IAV(47),
    IAV(48), IAV(49), IAV(50), IAV(51), IAV(52), IAV(53), IAV(54), IAV(55),
    IAV(56), IAV(57), IAV(58), IAV(59), IAV(60), IAV(61), IAV(62), IAV(63),
    IAV(64), IAV(65), IAV(66), IAV(67), IAV(68), IAV(69), IAV(70), IAV(71),
    IAV(72), IAV(73), IAV(74), IAV(75), IAV(76), IAV(77), IAV(78), IAV(79),
    IAV(80), IAV(81), IAV(82), IAV(83), IAV(84), IAV(85), IAV(86), IAV(87),
    IAV(88), IAV(89), IAV(90), IAV(91), IAV(92), IAV(93), IAV(94), IAV(95),
    IAV(96), IAV(97), IAV(98), IAV(99), IAV(100), IAV(101), IAV(102), IAV(103),
    IAV(104), IAV(105), IAV(106), IAV(107), IAV(108), IAV(109), IAV(110), IAV(111),
    IAV(112), IAV(113), IAV(114), IAV(115), IAV(116), IAV(117), IAV(118), IAV(119),
    IAV(120), IAV(121), IAV(122), IAV(123), IAV(124), IAV(125), IAV(126), IAV(127)
};

unsigned long __malloc_trim_threshold = DEFAULT_TRIM_THRESHOLD;
unsigned long __malloc_top_pad = DEFAULT_TOP_PAD;
char *__malloc_sbrk_base = (char *)(-1);
unsigned long __malloc_max_sbrked_mem = 0;
unsigned long __malloc_max_total_mem = 0;
struct mallinfo __malloc_current_mallinfo = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#define trim_threshold __malloc_trim_threshold
#define top_pad __malloc_top_pad
#define sbrk_base __malloc_sbrk_base
#define max_sbrked_mem __malloc_max_sbrked_mem
#define max_total_mem __malloc_max_total_mem
#define current_mallinfo __malloc_current_mallinfo
#define sbrked_mem (current_mallinfo.arena)

static void malloc_extend_top(struct _reent *reent_ptr, size_t nb)
{
  char*     brk;
  size_t front_misalign;
  size_t correction;
  int correction_failed = 0;
  char*     new_brk;
  size_t top_size;

  mchunkptr old_top     = top;
  size_t old_top_size = chunksize(old_top);
  char*     old_end      = (char*)(chunk_at_offset(old_top, old_top_size));

  size_t    sbrk_size     = nb + top_pad + MINSIZE;
  unsigned long pagesz    = 4096;

  if (sbrk_base != (char*)(-1))
    sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);

  brk = (char*)(_sbrk_r (reent_ptr, sbrk_size));

  if (brk == (char*)(-1) ||
      (brk < old_end && old_top != initial_top))
    return;

  sbrked_mem += sbrk_size;

  if (brk == old_end
      && ((unsigned long)old_end & (pagesz - 1)) == 0)
  {
    top_size = sbrk_size + old_top_size;
    set_head(top, top_size | PREV_INUSE);
  }
  else
  {
    if (sbrk_base == (char*)(-1))
      sbrk_base = brk;
    else
      sbrked_mem += brk - (char*)old_end;

    front_misalign = (unsigned long)chunk2mem(brk) & MALLOC_ALIGN_MASK;
    if (front_misalign > 0)
    {
      correction = (MALLOC_ALIGN_MASK + 1) - front_misalign;
      brk += correction;
    }
    else
      correction = 0;

    correction += pagesz - ((unsigned long)(brk + sbrk_size) & (pagesz - 1));

    new_brk = (char*)(_sbrk_r (reent_ptr, correction));
    if (new_brk == (char*)(-1))
      {
        correction = 0;
        correction_failed = 1;
        new_brk = brk;
      }

    sbrked_mem += correction;

    top = (mchunkptr)brk;
    top_size = new_brk - brk + correction;
    set_head(top, top_size | PREV_INUSE);

    if (old_top != initial_top)
    {
      if (old_top_size < MINSIZE)
      {
        set_head(top, PREV_INUSE);
        return;
      }

      old_top_size = (old_top_size - 3*SIZE_SZ) & ~MALLOC_ALIGN_MASK;
      old_top->size = (old_top->size & PREV_INUSE) | old_top_size;
      chunk_at_offset(old_top, old_top_size          )->size =
        SIZE_SZ|PREV_INUSE;
      chunk_at_offset(old_top, old_top_size + SIZE_SZ)->size =
        SIZE_SZ|PREV_INUSE;
      if (old_top_size >= MINSIZE)
        _free_r (reent_ptr, chunk2mem(old_top));
    }
  }

  if ((unsigned long)sbrked_mem > (unsigned long)max_sbrked_mem)
    max_sbrked_mem = sbrked_mem;
  if ((unsigned long)(sbrked_mem + 0) > (unsigned long)max_total_mem)
    max_total_mem = sbrked_mem + 0;
}

void* _malloc_r(struct _reent *reent_ptr, size_t bytes)
{
  mchunkptr victim;
  size_t victim_size;
  int idx;
  mchunkptr bin;
  mchunkptr remainder;
  long remainder_size;
  int remainder_index;
  unsigned long block;
  int startidx;
  mchunkptr fwd;
  mchunkptr bck;
  mchunkptr q;

  size_t nb = request2size(bytes);

  __malloc_lock(reent_ptr);

  if (is_small_request(nb))
  {
    idx = smallbin_index(nb);
    q = bin_at(idx);
    victim = last(q);
    if (victim != q)
    {
      victim_size = chunksize(victim);
      unlink(victim, bck, fwd);
      set_inuse_bit_at_offset(victim, victim_size);
      __malloc_unlock(reent_ptr);
      return chunk2mem(victim);
    }
    idx += 2;
  }
  else
  {
    idx = bin_index(nb);
    bin = bin_at(idx);
    for (victim = last(bin); victim != bin; victim = victim->bk)
    {
      victim_size = chunksize(victim);
      remainder_size = long_sub_size_t(victim_size, nb);
      if (remainder_size >= (long)MINSIZE)
      {
        --idx;
        break;
      }
      else if (remainder_size >= 0)
      {
        unlink(victim, bck, fwd);
        set_inuse_bit_at_offset(victim, victim_size);
        __malloc_unlock(reent_ptr);
        return chunk2mem(victim);
      }
    }
    ++idx;
  }

  if ((victim = last_remainder->fd) != last_remainder)
  {
    victim_size = chunksize(victim);
    remainder_size = long_sub_size_t(victim_size, nb);
    if (remainder_size >= (long)MINSIZE)
    {
      remainder = chunk_at_offset(victim, nb);
      set_head(victim, nb | PREV_INUSE);
      link_last_remainder(remainder);
      set_head(remainder, remainder_size | PREV_INUSE);
      set_foot(remainder, remainder_size);
      __malloc_unlock(reent_ptr);
      return chunk2mem(victim);
    }
    clear_last_remainder;
    if (remainder_size >= 0)
    {
      set_inuse_bit_at_offset(victim, victim_size);
      __malloc_unlock(reent_ptr);
      return chunk2mem(victim);
    }
    frontlink(victim, victim_size, remainder_index, bck, fwd);
  }

  if ((block = idx2binblock(idx)) <= binblocks)
  {
    if ((block & binblocks) == 0)
    {
      idx = (idx & ~(BINBLOCKWIDTH - 1)) + BINBLOCKWIDTH;
      block <<= 1;
      while ((block & binblocks) == 0)
      {
        idx += BINBLOCKWIDTH;
        block <<= 1;
      }
    }
    for (;;)
    {
      startidx = idx;
      q = bin = bin_at(idx);
      do
      {
        for (victim = last(bin); victim != bin; victim = victim->bk)
        {
          victim_size = chunksize(victim);
          remainder_size = long_sub_size_t(victim_size, nb);
          if (remainder_size >= (long)MINSIZE)
          {
            remainder = chunk_at_offset(victim, nb);
            set_head(victim, nb | PREV_INUSE);
            unlink(victim, bck, fwd);
            link_last_remainder(remainder);
            set_head(remainder, remainder_size | PREV_INUSE);
            set_foot(remainder, remainder_size);
            __malloc_unlock(reent_ptr);
            return chunk2mem(victim);
          }
          else if (remainder_size >= 0)
          {
            set_inuse_bit_at_offset(victim, victim_size);
            unlink(victim, bck, fwd);
            __malloc_unlock(reent_ptr);
            return chunk2mem(victim);
          }
        }
        bin = next_bin(bin);
        if (idx < MAX_SMALLBIN)
        {
          bin = next_bin(bin);
          ++idx;
        }
      } while ((++idx & (BINBLOCKWIDTH - 1)) != 0);

      do
      {
        if ((startidx & (BINBLOCKWIDTH - 1)) == 0)
        {
          binblocks &= ~block;
          break;
        }
        --startidx;
        q = prev_bin(q);
      } while (first(q) == q);

      if ((block <<= 1) <= binblocks && (block != 0))
      {
        while ((block & binblocks) == 0)
        {
          idx += BINBLOCKWIDTH;
          block <<= 1;
        }
      }
      else
        break;
    }
  }

  remainder_size = long_sub_size_t(chunksize(top), nb);
  if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
  {
    malloc_extend_top(reent_ptr, nb);
    remainder_size = long_sub_size_t(chunksize(top), nb);
    if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
    {
      __malloc_unlock(reent_ptr);
      return 0;
    }
  }

  victim = top;
  set_head(victim, nb | PREV_INUSE);
  top = chunk_at_offset(victim, nb);
  set_head(top, remainder_size | PREV_INUSE);
  __malloc_unlock(reent_ptr);
  return chunk2mem(victim);
}
