/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc unwind-dw2.o (gcc 3.2-ee-040921), 0x316e20-0x319788: the DWARF2 frame unwinder (CFA and
 * location-expression interpreters, context update/install, _Unwind_RaiseException and friends
 * from unwind.inc). The EE build unwinds 176 DWARF columns, its _Unwind_Word is 64 bits and the
 * register size table is filled once under DIntr/EIntr. Linked unit (linked_units.tsv), C with
 * -fexceptions like the original libgcc build. */

/* tsystem.h */
typedef unsigned int size_t;
extern void *memcpy (void *, const void *, size_t);
extern void *memset (void *, int, size_t);
extern size_t strlen (const char *);
extern void abort (void) __attribute__ ((__noreturn__));
#define NULL ((void *) 0)
asm ("memset = func_002fde18");

/* DW_OP_div calls libgcc's __divdi3 (0x311dd0, linked unit _divdi3.c, which keeps the name
   func_00311dd0); the build's global __divdi3 symbol is bound elsewhere.  */
asm ("__divdi3 = func_00311dd0");

/* EE kernel: DIntr returns whether interrupts were enabled. */
extern int DIntr (void);
extern int EIntr (void);

/* unwind.h */
typedef unsigned _Unwind_Word __attribute__ ((__mode__ (__word__)));
typedef signed _Unwind_Sword __attribute__ ((__mode__ (__word__)));
typedef unsigned _Unwind_Ptr __attribute__ ((__mode__ (__pointer__)));
typedef unsigned _Unwind_Internal_Ptr __attribute__ ((__mode__ (__pointer__)));
typedef unsigned _Unwind_Exception_Class __attribute__ ((__mode__ (__DI__)));

typedef enum
{
  _URC_NO_REASON = 0,
  _URC_FOREIGN_EXCEPTION_CAUGHT = 1,
  _URC_FATAL_PHASE2_ERROR = 2,
  _URC_FATAL_PHASE1_ERROR = 3,
  _URC_NORMAL_STOP = 4,
  _URC_END_OF_STACK = 5,
  _URC_HANDLER_FOUND = 6,
  _URC_INSTALL_CONTEXT = 7,
  _URC_CONTINUE_UNWIND = 8
} _Unwind_Reason_Code;

struct _Unwind_Exception;

typedef void (*_Unwind_Exception_Cleanup_Fn) (_Unwind_Reason_Code,
					      struct _Unwind_Exception *);

struct _Unwind_Exception
{
  _Unwind_Exception_Class exception_class;
  _Unwind_Exception_Cleanup_Fn exception_cleanup;
  _Unwind_Word private_1;
  _Unwind_Word private_2;
} __attribute__((__aligned__));

typedef int _Unwind_Action;

#define _UA_SEARCH_PHASE	1
#define _UA_CLEANUP_PHASE	2
#define _UA_HANDLER_FRAME	4
#define _UA_FORCE_UNWIND	8
#define _UA_END_OF_STACK	16

struct _Unwind_Context;

typedef _Unwind_Reason_Code (*_Unwind_Stop_Fn)
     (int, _Unwind_Action, _Unwind_Exception_Class,
      struct _Unwind_Exception *, struct _Unwind_Context *, void *);

typedef _Unwind_Reason_Code (*_Unwind_Personality_Fn)
     (int, _Unwind_Action, _Unwind_Exception_Class,
      struct _Unwind_Exception *, struct _Unwind_Context *);

/* dwarf2.h */
enum dwarf_call_frame_info
  {
    DW_CFA_advance_loc = 0x40,
    DW_CFA_offset = 0x80,
    DW_CFA_restore = 0xc0,
    DW_CFA_nop = 0x00,
    DW_CFA_set_loc = 0x01,
    DW_CFA_advance_loc1 = 0x02,
    DW_CFA_advance_loc2 = 0x03,
    DW_CFA_advance_loc4 = 0x04,
    DW_CFA_offset_extended = 0x05,
    DW_CFA_restore_extended = 0x06,
    DW_CFA_undefined = 0x07,
    DW_CFA_same_value = 0x08,
    DW_CFA_register = 0x09,
    DW_CFA_remember_state = 0x0a,
    DW_CFA_restore_state = 0x0b,
    DW_CFA_def_cfa = 0x0c,
    DW_CFA_def_cfa_register = 0x0d,
    DW_CFA_def_cfa_offset = 0x0e,
    DW_CFA_def_cfa_expression = 0x0f,
    DW_CFA_expression = 0x10,
    DW_CFA_offset_extended_sf = 0x11,
    DW_CFA_def_cfa_sf = 0x12,
    DW_CFA_def_cfa_offset_sf = 0x13,
    DW_CFA_MIPS_advance_loc8 = 0x1d,
    DW_CFA_lo_user = 0x1c,
    DW_CFA_hi_user = 0x3f,
    DW_CFA_GNU_window_save = 0x2d,
    DW_CFA_GNU_args_size = 0x2e,
    DW_CFA_GNU_negative_offset_extended = 0x2f
  };

#define DW_CIE_ID	  0xffffffff
#define DW_CFA_extended   0

enum dwarf_location_atom
  {
    DW_OP_addr = 0x03,
    DW_OP_deref = 0x06,
    DW_OP_const1u = 0x08,
    DW_OP_const1s = 0x09,
    DW_OP_const2u = 0x0a,
    DW_OP_const2s = 0x0b,
    DW_OP_const4u = 0x0c,
    DW_OP_const4s = 0x0d,
    DW_OP_const8u = 0x0e,
    DW_OP_const8s = 0x0f,
    DW_OP_constu = 0x10,
    DW_OP_consts = 0x11,
    DW_OP_dup = 0x12,
    DW_OP_drop = 0x13,
    DW_OP_over = 0x14,
    DW_OP_pick = 0x15,
    DW_OP_swap = 0x16,
    DW_OP_rot = 0x17,
    DW_OP_xderef = 0x18,
    DW_OP_abs = 0x19,
    DW_OP_and = 0x1a,
    DW_OP_div = 0x1b,
    DW_OP_minus = 0x1c,
    DW_OP_mod = 0x1d,
    DW_OP_mul = 0x1e,
    DW_OP_neg = 0x1f,
    DW_OP_not = 0x20,
    DW_OP_or = 0x21,
    DW_OP_plus = 0x22,
    DW_OP_plus_uconst = 0x23,
    DW_OP_shl = 0x24,
    DW_OP_shr = 0x25,
    DW_OP_shra = 0x26,
    DW_OP_xor = 0x27,
    DW_OP_bra = 0x28,
    DW_OP_eq = 0x29,
    DW_OP_ge = 0x2a,
    DW_OP_gt = 0x2b,
    DW_OP_le = 0x2c,
    DW_OP_lt = 0x2d,
    DW_OP_ne = 0x2e,
    DW_OP_skip = 0x2f,
    DW_OP_lit0 = 0x30,
    DW_OP_lit1 = 0x31,
    DW_OP_lit2 = 0x32,
    DW_OP_lit3 = 0x33,
    DW_OP_lit4 = 0x34,
    DW_OP_lit5 = 0x35,
    DW_OP_lit6 = 0x36,
    DW_OP_lit7 = 0x37,
    DW_OP_lit8 = 0x38,
    DW_OP_lit9 = 0x39,
    DW_OP_lit10 = 0x3a,
    DW_OP_lit11 = 0x3b,
    DW_OP_lit12 = 0x3c,
    DW_OP_lit13 = 0x3d,
    DW_OP_lit14 = 0x3e,
    DW_OP_lit15 = 0x3f,
    DW_OP_lit16 = 0x40,
    DW_OP_lit17 = 0x41,
    DW_OP_lit18 = 0x42,
    DW_OP_lit19 = 0x43,
    DW_OP_lit20 = 0x44,
    DW_OP_lit21 = 0x45,
    DW_OP_lit22 = 0x46,
    DW_OP_lit23 = 0x47,
    DW_OP_lit24 = 0x48,
    DW_OP_lit25 = 0x49,
    DW_OP_lit26 = 0x4a,
    DW_OP_lit27 = 0x4b,
    DW_OP_lit28 = 0x4c,
    DW_OP_lit29 = 0x4d,
    DW_OP_lit30 = 0x4e,
    DW_OP_lit31 = 0x4f,
    DW_OP_reg0 = 0x50,
    DW_OP_reg1 = 0x51,
    DW_OP_reg2 = 0x52,
    DW_OP_reg3 = 0x53,
    DW_OP_reg4 = 0x54,
    DW_OP_reg5 = 0x55,
    DW_OP_reg6 = 0x56,
    DW_OP_reg7 = 0x57,
    DW_OP_reg8 = 0x58,
    DW_OP_reg9 = 0x59,
    DW_OP_reg10 = 0x5a,
    DW_OP_reg11 = 0x5b,
    DW_OP_reg12 = 0x5c,
    DW_OP_reg13 = 0x5d,
    DW_OP_reg14 = 0x5e,
    DW_OP_reg15 = 0x5f,
    DW_OP_reg16 = 0x60,
    DW_OP_reg17 = 0x61,
    DW_OP_reg18 = 0x62,
    DW_OP_reg19 = 0x63,
    DW_OP_reg20 = 0x64,
    DW_OP_reg21 = 0x65,
    DW_OP_reg22 = 0x66,
    DW_OP_reg23 = 0x67,
    DW_OP_reg24 = 0x68,
    DW_OP_reg25 = 0x69,
    DW_OP_reg26 = 0x6a,
    DW_OP_reg27 = 0x6b,
    DW_OP_reg28 = 0x6c,
    DW_OP_reg29 = 0x6d,
    DW_OP_reg30 = 0x6e,
    DW_OP_reg31 = 0x6f,
    DW_OP_breg0 = 0x70,
    DW_OP_breg1 = 0x71,
    DW_OP_breg2 = 0x72,
    DW_OP_breg3 = 0x73,
    DW_OP_breg4 = 0x74,
    DW_OP_breg5 = 0x75,
    DW_OP_breg6 = 0x76,
    DW_OP_breg7 = 0x77,
    DW_OP_breg8 = 0x78,
    DW_OP_breg9 = 0x79,
    DW_OP_breg10 = 0x7a,
    DW_OP_breg11 = 0x7b,
    DW_OP_breg12 = 0x7c,
    DW_OP_breg13 = 0x7d,
    DW_OP_breg14 = 0x7e,
    DW_OP_breg15 = 0x7f,
    DW_OP_breg16 = 0x80,
    DW_OP_breg17 = 0x81,
    DW_OP_breg18 = 0x82,
    DW_OP_breg19 = 0x83,
    DW_OP_breg20 = 0x84,
    DW_OP_breg21 = 0x85,
    DW_OP_breg22 = 0x86,
    DW_OP_breg23 = 0x87,
    DW_OP_breg24 = 0x88,
    DW_OP_breg25 = 0x89,
    DW_OP_breg26 = 0x8a,
    DW_OP_breg27 = 0x8b,
    DW_OP_breg28 = 0x8c,
    DW_OP_breg29 = 0x8d,
    DW_OP_breg30 = 0x8e,
    DW_OP_breg31 = 0x8f,
    DW_OP_regx = 0x90,
    DW_OP_fbreg = 0x91,
    DW_OP_bregx = 0x92,
    DW_OP_piece = 0x93,
    DW_OP_deref_size = 0x94,
    DW_OP_xderef_size = 0x95,
    DW_OP_nop = 0x96
  };

#define DW_EH_PE_absptr		0x00
#define DW_EH_PE_omit		0xff
#define DW_EH_PE_uleb128	0x01
#define DW_EH_PE_udata2		0x02
#define DW_EH_PE_udata4		0x03
#define DW_EH_PE_udata8		0x04
#define DW_EH_PE_sleb128	0x09
#define DW_EH_PE_sdata2		0x0A
#define DW_EH_PE_sdata4		0x0B
#define DW_EH_PE_sdata8		0x0C
#define DW_EH_PE_signed		0x08
#define DW_EH_PE_pcrel		0x10
#define DW_EH_PE_textrel	0x20
#define DW_EH_PE_datarel	0x30
#define DW_EH_PE_funcrel	0x40
#define DW_EH_PE_aligned	0x50
#define DW_EH_PE_indirect	0x80

/* unwind-pe.h */
static unsigned int
size_of_encoded_value (unsigned char encoding)
{
  if (encoding == DW_EH_PE_omit)
    return 0;

  switch (encoding & 0x07)
    {
    case DW_EH_PE_absptr:
      return sizeof (void *);
    case DW_EH_PE_udata2:
      return 2;
    case DW_EH_PE_udata4:
      return 4;
    case DW_EH_PE_udata8:
      return 8;
    }
  abort ();
}

static _Unwind_Ptr
base_of_encoded_value (unsigned char encoding, struct _Unwind_Context *context)
{
  if (encoding == DW_EH_PE_omit)
    return 0;

  switch (encoding & 0x70)
    {
    case DW_EH_PE_absptr:
    case DW_EH_PE_pcrel:
    case DW_EH_PE_aligned:
      return 0;

    case DW_EH_PE_textrel:
      return _Unwind_GetTextRelBase (context);
    case DW_EH_PE_datarel:
      return _Unwind_GetDataRelBase (context);
    case DW_EH_PE_funcrel:
      return _Unwind_GetRegionStart (context);
    }
  abort ();
}

static const unsigned char *
read_uleb128 (const unsigned char *p, _Unwind_Word *val)
{
  unsigned int shift = 0;
  unsigned char byte;
  _Unwind_Word result;

  result = 0;
  do
    {
      byte = *p++;
      result |= (byte & 0x7f) << shift;
      shift += 7;
    }
  while (byte & 0x80);

  *val = result;
  return p;
}

static const unsigned char *
read_sleb128 (const unsigned char *p, _Unwind_Sword *val)
{
  unsigned int shift = 0;
  unsigned char byte;
  _Unwind_Word result;

  result = 0;
  do
    {
      byte = *p++;
      result |= (byte & 0x7f) << shift;
      shift += 7;
    }
  while (byte & 0x80);

  /* Sign-extend a negative value.  */
  if (shift < 8 * sizeof(result) && (byte & 0x40) != 0)
    result |= -(1L << shift);

  *val = (_Unwind_Sword) result;
  return p;
}

static const unsigned char *
read_encoded_value_with_base (unsigned char encoding, _Unwind_Ptr base,
			      const unsigned char *p, _Unwind_Ptr *val)
{
  union unaligned
    {
      void *ptr;
      unsigned u2 __attribute__ ((mode (HI)));
      unsigned u4 __attribute__ ((mode (SI)));
      unsigned u8 __attribute__ ((mode (DI)));
      signed s2 __attribute__ ((mode (HI)));
      signed s4 __attribute__ ((mode (SI)));
      signed s8 __attribute__ ((mode (DI)));
    } __attribute__((__packed__));

  union unaligned *u = (union unaligned *) p;
  _Unwind_Internal_Ptr result;

  if (encoding == DW_EH_PE_aligned)
    {
      _Unwind_Internal_Ptr a = (_Unwind_Internal_Ptr) p;
      a = (a + sizeof (void *) - 1) & - sizeof(void *);
      result = *(_Unwind_Internal_Ptr *) a;
      p = (const unsigned char *) (a + sizeof (void *));
    }
  else
    {
      switch (encoding & 0x0f)
	{
	case DW_EH_PE_absptr:
	  result = (_Unwind_Internal_Ptr) u->ptr;
	  p += sizeof (void *);
	  break;

	case DW_EH_PE_uleb128:
	  {
	    _Unwind_Word tmp;
	    p = read_uleb128 (p, &tmp);
	    result = (_Unwind_Internal_Ptr) tmp;
	  }
	  break;

	case DW_EH_PE_sleb128:
	  {
	    _Unwind_Sword tmp;
	    p = read_sleb128 (p, &tmp);
	    result = (_Unwind_Internal_Ptr) tmp;
	  }
	  break;

	case DW_EH_PE_udata2:
	  result = u->u2;
	  p += 2;
	  break;
	case DW_EH_PE_udata4:
	  result = u->u4;
	  p += 4;
	  break;
	case DW_EH_PE_udata8:
	  result = u->u8;
	  p += 8;
	  break;

	case DW_EH_PE_sdata2:
	  result = u->s2;
	  p += 2;
	  break;
	case DW_EH_PE_sdata4:
	  result = u->s4;
	  p += 4;
	  break;
	case DW_EH_PE_sdata8:
	  result = u->s8;
	  p += 8;
	  break;

	default:
	  abort ();
	}

      if (result != 0)
	{
	  result += ((encoding & 0x70) == DW_EH_PE_pcrel
		     ? (_Unwind_Internal_Ptr) u : base);
	  if (encoding & DW_EH_PE_indirect)
	    result = *(_Unwind_Internal_Ptr *) result;
	}
    }

  *val = result;
  return p;
}

static inline const unsigned char *
read_encoded_value (struct _Unwind_Context *context, unsigned char encoding,
		    const unsigned char *p, _Unwind_Ptr *val)
{
  return read_encoded_value_with_base (encoding,
		base_of_encoded_value (encoding, context),
		p, val);
}

/* unwind-dw2-fde.h */
struct dwarf_eh_bases
{
  void *tbase;
  void *dbase;
  void *func;
};

typedef          int  sword __attribute__ ((mode (SI)));
typedef unsigned int  uword __attribute__ ((mode (SI)));
typedef unsigned int  uaddr __attribute__ ((mode (pointer)));
typedef          int  saddr __attribute__ ((mode (pointer)));
typedef unsigned char ubyte;

struct dwarf_cie
{
  uword length;
  sword CIE_id;
  ubyte version;
  unsigned char augmentation[];
} __attribute__ ((packed, aligned (__alignof__ (void *))));

struct dwarf_fde
{
  uword length;
  sword CIE_delta;
  unsigned char pc_begin[];
} __attribute__ ((packed, aligned (__alignof__ (void *))));

typedef struct dwarf_fde fde;

static inline struct dwarf_cie *
get_cie (struct dwarf_fde *f)
{
  return (void *)&f->CIE_delta - f->CIE_delta;
}

extern fde * _Unwind_Find_FDE (void *, struct dwarf_eh_bases *);

/* gthr (EE): the mutex state and the once flag, set with interrupts disabled. */
static int interupt_was_enabled;

typedef int __gthread_once_t;
#define __GTHREAD_ONCE_INIT 0
#define __GTHREADS 1

static inline int
__gthread_once (__gthread_once_t *once, void (*func) (void))
{
  int run = 0;
  int ie = DIntr ();
  if (*once == 0)
    {
      *once = 1;
      run = 1;
    }
  if (ie)
    EIntr ();
  if (run)
    func ();
  return 0;
}

/* unwind-dw2.c */
#define STACK_GROWS_DOWNWARD 1
#define DWARF_FRAME_REGISTERS 176
#define PRE_GCC3_DWARF_FRAME_REGISTERS DWARF_FRAME_REGISTERS

/* This is the register and unwind state for a particular frame.  */
struct _Unwind_Context
{
  void *reg[DWARF_FRAME_REGISTERS+1];
  void *cfa;
  void *ra;
  void *lsda;
  struct dwarf_eh_bases bases;
  _Unwind_Word args_size;
};

/* Byte size of every register managed by these routines.  */
static unsigned char dwarf_reg_size_table[DWARF_FRAME_REGISTERS];


/* The result of interpreting the frame unwind info for a frame.
   This is all symbolic at this point, as none of the values can
   be resolved until the target pc is located.  */
typedef struct
{
  /* Each register save state can be described in terms of a CFA slot,
     another register, or a location expression.  */
  struct frame_state_reg_info
  {
    struct {
      union {
	_Unwind_Word reg;
	_Unwind_Sword offset;
	const unsigned char *exp;
      } loc;
      enum {
	REG_UNSAVED,
	REG_SAVED_OFFSET,
	REG_SAVED_REG,
	REG_SAVED_EXP,
      } how;
    } reg[DWARF_FRAME_REGISTERS+1];

    /* Used to implement DW_CFA_remember_state.  */
    struct frame_state_reg_info *prev;
  } regs;

  /* The CFA can be described in terms of a reg+offset or a
     location expression.  */
  _Unwind_Sword cfa_offset;
  _Unwind_Word cfa_reg;
  const unsigned char *cfa_exp;
  enum {
    CFA_UNSET,
    CFA_REG_OFFSET,
    CFA_EXP,
  } cfa_how;

  /* The PC described by the current frame state.  */
  void *pc;

  /* The information we care about from the CIE/FDE.  */
  _Unwind_Personality_Fn personality;
  _Unwind_Sword data_align;
  _Unwind_Word code_align;
  unsigned char retaddr_column;
  unsigned char fde_encoding;
  unsigned char lsda_encoding;
  unsigned char saw_z;
  void *eh_ptr;
} _Unwind_FrameState;

/* Read unaligned data from the instruction buffer.  */

union unaligned
{
  void *p;
  unsigned u2 __attribute__ ((mode (HI)));
  unsigned u4 __attribute__ ((mode (SI)));
  unsigned u8 __attribute__ ((mode (DI)));
  signed s2 __attribute__ ((mode (HI)));
  signed s4 __attribute__ ((mode (SI)));
  signed s8 __attribute__ ((mode (DI)));
} __attribute__ ((packed));

static inline void *
read_pointer (const void *p) { const union unaligned *up = p; return up->p; }

static inline int
read_1u (const void *p) { return *(const unsigned char *) p; }

static inline int
read_1s (const void *p) { return *(const signed char *) p; }

static inline int
read_2u (const void *p) { const union unaligned *up = p; return up->u2; }

static inline int
read_2s (const void *p) { const union unaligned *up = p; return up->s2; }

static inline unsigned int
read_4u (const void *p) { const union unaligned *up = p; return up->u4; }

static inline int
read_4s (const void *p) { const union unaligned *up = p; return up->s4; }

static inline unsigned long
read_8u (const void *p) { const union unaligned *up = p; return up->u8; }

static inline unsigned long
read_8s (const void *p) { const union unaligned *up = p; return up->s8; }

/* Get the value of register REG as saved in CONTEXT.  */

inline _Unwind_Word
_Unwind_GetGR (struct _Unwind_Context *context, int index)
{
  /* This will segfault if the register hasn't been saved.  */
  return * (_Unwind_Word *) context->reg[index];
}

/* Overwrite the saved value for register REG in CONTEXT with VAL.  */

inline void
_Unwind_SetGR (struct _Unwind_Context *context, int index, _Unwind_Word val)
{
  * (_Unwind_Word *) context->reg[index] = val;
}

/* Retrieve the return address for CONTEXT.  */

inline _Unwind_Ptr
_Unwind_GetIP (struct _Unwind_Context *context)
{
  return (_Unwind_Ptr) context->ra;
}

/* Overwrite the return address for CONTEXT with VAL.  */

inline void
_Unwind_SetIP (struct _Unwind_Context *context, _Unwind_Ptr val)
{
  context->ra = (void *) val;
}

void *
_Unwind_GetLanguageSpecificData (struct _Unwind_Context *context)
{
  return context->lsda;
}

_Unwind_Ptr
_Unwind_GetRegionStart (struct _Unwind_Context *context)
{
  return (_Unwind_Ptr) context->bases.func;
}

_Unwind_Ptr
_Unwind_GetDataRelBase (struct _Unwind_Context *context)
{
  return (_Unwind_Ptr) context->bases.dbase;
}

_Unwind_Ptr
_Unwind_GetTextRelBase (struct _Unwind_Context *context)
{
  return (_Unwind_Ptr) context->bases.tbase;
}

/* Extract any interesting information from the CIE for the translation
   unit F belongs to.  Return a pointer to the byte after the augmentation,
   or NULL if we encountered an undecipherable augmentation.  */

static const unsigned char *
extract_cie_info (struct dwarf_cie *cie, struct _Unwind_Context *context,
		  _Unwind_FrameState *fs)
{
  const unsigned char *aug = cie->augmentation;
  const unsigned char *p = aug + strlen (aug) + 1;
  const unsigned char *ret = NULL;
  _Unwind_Word utmp;

  /* g++ v2 "eh" has pointer immediately following augmentation string,
     so it must be handled first.  */
  if (aug[0] == 'e' && aug[1] == 'h')
    {
      fs->eh_ptr = read_pointer (p);
      p += sizeof (void *);
      aug += 2;
    }

  /* Immediately following the augmentation are the code and
     data alignment and return address column.  */
  p = read_uleb128 (p, &fs->code_align);
  p = read_sleb128 (p, &fs->data_align);
  fs->retaddr_column = *p++;
  fs->lsda_encoding = DW_EH_PE_omit;

  /* If the augmentation starts with 'z', then a uleb128 immediately
     follows containing the length of the augmentation field following
     the size.  */
  if (*aug == 'z')
    {
      p = read_uleb128 (p, &utmp);
      ret = p + utmp;

      fs->saw_z = 1;
      ++aug;
    }

  /* Iterate over recognized augmentation subsequences.  */
  while (*aug != '\0')
    {
      /* "L" indicates a byte showing how the LSDA pointer is encoded.  */
      if (aug[0] == 'L')
	{
	  fs->lsda_encoding = *p++;
	  aug += 1;
	}

      /* "R" indicates a byte indicating how FDE addresses are encoded.  */
      else if (aug[0] == 'R')
	{
	  fs->fde_encoding = *p++;
	  aug += 1;
	}

      /* "P" indicates a personality routine in the CIE augmentation.  */
      else if (aug[0] == 'P')
	{
	  p = read_encoded_value (context, *p, p + 1,
				  (_Unwind_Ptr *) &fs->personality);
	  aug += 1;
	}

      /* Otherwise we have an unknown augmentation string.
	 Bail unless we saw a 'z' prefix.  */
      else
	return ret;
    }

  return ret ? ret : p;
}


/* Decode a DW_OP stack program.  Return the top of stack.  Push INITIAL
   onto the stack to start.  */

static _Unwind_Word
execute_stack_op (const unsigned char *op_ptr, const unsigned char *op_end,
		  struct _Unwind_Context *context, _Unwind_Word initial)
{
  _Unwind_Word stack[64];	/* ??? Assume this is enough.  */
  int stack_elt;

  stack[0] = initial;
  stack_elt = 1;

  while (op_ptr < op_end)
    {
      enum dwarf_location_atom op = *op_ptr++;
      _Unwind_Word result, reg, utmp;
      _Unwind_Sword offset, stmp;

      switch (op)
	{
	case DW_OP_lit0:
	case DW_OP_lit1:
	case DW_OP_lit2:
	case DW_OP_lit3:
	case DW_OP_lit4:
	case DW_OP_lit5:
	case DW_OP_lit6:
	case DW_OP_lit7:
	case DW_OP_lit8:
	case DW_OP_lit9:
	case DW_OP_lit10:
	case DW_OP_lit11:
	case DW_OP_lit12:
	case DW_OP_lit13:
	case DW_OP_lit14:
	case DW_OP_lit15:
	case DW_OP_lit16:
	case DW_OP_lit17:
	case DW_OP_lit18:
	case DW_OP_lit19:
	case DW_OP_lit20:
	case DW_OP_lit21:
	case DW_OP_lit22:
	case DW_OP_lit23:
	case DW_OP_lit24:
	case DW_OP_lit25:
	case DW_OP_lit26:
	case DW_OP_lit27:
	case DW_OP_lit28:
	case DW_OP_lit29:
	case DW_OP_lit30:
	case DW_OP_lit31:
	  result = op - DW_OP_lit0;
	  break;

	case DW_OP_addr:
	  result = (_Unwind_Word) (_Unwind_Ptr) read_pointer (op_ptr);
	  op_ptr += sizeof (void *);
	  break;

	case DW_OP_const1u:
	  result = read_1u (op_ptr);
	  op_ptr += 1;
	  break;
	case DW_OP_const1s:
	  result = read_1s (op_ptr);
	  op_ptr += 1;
	  break;
	case DW_OP_const2u:
	  result = read_2u (op_ptr);
	  op_ptr += 2;
	  break;
	case DW_OP_const2s:
	  result = read_2s (op_ptr);
	  op_ptr += 2;
	  break;
	case DW_OP_const4u:
	  result = read_4u (op_ptr);
	  op_ptr += 4;
	  break;
	case DW_OP_const4s:
	  result = read_4s (op_ptr);
	  op_ptr += 4;
	  break;
	case DW_OP_const8u:
	  result = read_8u (op_ptr);
	  op_ptr += 8;
	  break;
	case DW_OP_const8s:
	  result = read_8s (op_ptr);
	  op_ptr += 8;
	  break;
	case DW_OP_constu:
	  op_ptr = read_uleb128 (op_ptr, &result);
	  break;
	case DW_OP_consts:
	  op_ptr = read_sleb128 (op_ptr, &stmp);
	  result = stmp;
	  break;

	case DW_OP_reg0:
	case DW_OP_reg1:
	case DW_OP_reg2:
	case DW_OP_reg3:
	case DW_OP_reg4:
	case DW_OP_reg5:
	case DW_OP_reg6:
	case DW_OP_reg7:
	case DW_OP_reg8:
	case DW_OP_reg9:
	case DW_OP_reg10:
	case DW_OP_reg11:
	case DW_OP_reg12:
	case DW_OP_reg13:
	case DW_OP_reg14:
	case DW_OP_reg15:
	case DW_OP_reg16:
	case DW_OP_reg17:
	case DW_OP_reg18:
	case DW_OP_reg19:
	case DW_OP_reg20:
	case DW_OP_reg21:
	case DW_OP_reg22:
	case DW_OP_reg23:
	case DW_OP_reg24:
	case DW_OP_reg25:
	case DW_OP_reg26:
	case DW_OP_reg27:
	case DW_OP_reg28:
	case DW_OP_reg29:
	case DW_OP_reg30:
	case DW_OP_reg31:
	  result = _Unwind_GetGR (context, op - DW_OP_reg0);
	  break;
	case DW_OP_regx:
	  op_ptr = read_uleb128 (op_ptr, &reg);
	  result = _Unwind_GetGR (context, reg);
	  break;

	case DW_OP_breg0:
	case DW_OP_breg1:
	case DW_OP_breg2:
	case DW_OP_breg3:
	case DW_OP_breg4:
	case DW_OP_breg5:
	case DW_OP_breg6:
	case DW_OP_breg7:
	case DW_OP_breg8:
	case DW_OP_breg9:
	case DW_OP_breg10:
	case DW_OP_breg11:
	case DW_OP_breg12:
	case DW_OP_breg13:
	case DW_OP_breg14:
	case DW_OP_breg15:
	case DW_OP_breg16:
	case DW_OP_breg17:
	case DW_OP_breg18:
	case DW_OP_breg19:
	case DW_OP_breg20:
	case DW_OP_breg21:
	case DW_OP_breg22:
	case DW_OP_breg23:
	case DW_OP_breg24:
	case DW_OP_breg25:
	case DW_OP_breg26:
	case DW_OP_breg27:
	case DW_OP_breg28:
	case DW_OP_breg29:
	case DW_OP_breg30:
	case DW_OP_breg31:
	  op_ptr = read_sleb128 (op_ptr, &offset);
	  result = _Unwind_GetGR (context, op - DW_OP_breg0) + offset;
	  break;
	case DW_OP_bregx:
	  op_ptr = read_uleb128 (op_ptr, &reg);
	  op_ptr = read_sleb128 (op_ptr, &offset);
	  result = _Unwind_GetGR (context, reg) + offset;
	  break;

	case DW_OP_dup:
	  if (stack_elt < 1)
	    abort ();
	  result = stack[stack_elt - 1];
	  break;

	case DW_OP_drop:
	  if (--stack_elt < 0)
	    abort ();
	  goto no_push;

	case DW_OP_pick:
	  offset = *op_ptr++;
	  if (offset >= stack_elt - 1)
	    abort ();
	  result = stack[stack_elt - 1 - offset];
	  break;

	case DW_OP_over:
	  if (stack_elt < 2)
	    abort ();
	  result = stack[stack_elt - 2];
	  break;

	case DW_OP_rot:
	  {
	    _Unwind_Word t1, t2, t3;

	    if (stack_elt < 3)
	      abort ();
	    t1 = stack[stack_elt - 1];
	    t2 = stack[stack_elt - 2];
	    t3 = stack[stack_elt - 3];
	    stack[stack_elt - 1] = t2;
	    stack[stack_elt - 2] = t3;
	    stack[stack_elt - 3] = t1;
	    goto no_push;
	  }

	case DW_OP_deref:
	case DW_OP_deref_size:
	case DW_OP_abs:
	case DW_OP_neg:
	case DW_OP_not:
	case DW_OP_plus_uconst:
	  /* Unary operations.  */
	  if (--stack_elt < 0)
	    abort ();
	  result = stack[stack_elt];

	  switch (op)
	    {
	    case DW_OP_deref:
	      {
		void *ptr = (void *) (_Unwind_Ptr) result;
		result = (_Unwind_Ptr) read_pointer (ptr);
	      }
	      break;

	    case DW_OP_deref_size:
	      {
		void *ptr = (void *) (_Unwind_Ptr) result;
		switch (*op_ptr++)
		  {
		  case 1:
		    result = read_1u (ptr);
		    break;
		  case 2:
		    result = read_2u (ptr);
		    break;
		  case 4:
		    result = read_4u (ptr);
		    break;
		  case 8:
		    result = read_8u (ptr);
		    break;
		  default:
		    abort ();
		  }
	      }
	      break;

	    case DW_OP_abs:
	      if ((_Unwind_Sword) result < 0)
		result = -result;
	      break;
	    case DW_OP_neg:
	      result = -result;
	      break;
	    case DW_OP_not:
	      result = ~result;
	      break;
	    case DW_OP_plus_uconst:
	      op_ptr = read_uleb128 (op_ptr, &utmp);
	      result += utmp;
	      break;

	    default:
	      abort ();
	    }
	  break;

	case DW_OP_and:
	case DW_OP_div:
	case DW_OP_minus:
	case DW_OP_mod:
	case DW_OP_mul:
	case DW_OP_or:
	case DW_OP_plus:
	case DW_OP_le:
	case DW_OP_ge:
	case DW_OP_eq:
	case DW_OP_lt:
	case DW_OP_gt:
	case DW_OP_ne:
	  {
	    /* Binary operations.  */
	    _Unwind_Word first, second;
	  if ((stack_elt -= 2) < 0)
	    abort ();
	  second = stack[stack_elt];
	  first = stack[stack_elt + 1];

	  switch (op)
	    {
	    case DW_OP_and:
	      result = second & first;
	      break;
	    case DW_OP_div:
	      result = (_Unwind_Sword) second / (_Unwind_Sword) first;
	      break;
	    case DW_OP_minus:
	      result = second - first;
	      break;
	    case DW_OP_mod:
	      result = (_Unwind_Sword) second % (_Unwind_Sword) first;
	      break;
	    case DW_OP_mul:
	      result = second * first;
	      break;
	    case DW_OP_or:
	      result = second | first;
	      break;
	    case DW_OP_plus:
	      result = second + first;
	      break;
	    case DW_OP_shl:
	      result = second << first;
	      break;
	    case DW_OP_shr:
	      result = second >> first;
	      break;
	    case DW_OP_shra:
	      result = (_Unwind_Sword) second >> first;
	      break;
	    case DW_OP_xor:
	      result = second ^ first;
	      break;
	    case DW_OP_le:
	      result = (_Unwind_Sword) first <= (_Unwind_Sword) second;
	      break;
	    case DW_OP_ge:
	      result = (_Unwind_Sword) first >= (_Unwind_Sword) second;
	      break;
	    case DW_OP_eq:
	      result = (_Unwind_Sword) first == (_Unwind_Sword) second;
	      break;
	    case DW_OP_lt:
	      result = (_Unwind_Sword) first < (_Unwind_Sword) second;
	      break;
	    case DW_OP_gt:
	      result = (_Unwind_Sword) first > (_Unwind_Sword) second;
	      break;
	    case DW_OP_ne:
	      result = (_Unwind_Sword) first != (_Unwind_Sword) second;
	      break;

	    default:
	      abort ();
	    }
	  }
	  break;

	case DW_OP_skip:
	  offset = read_2s (op_ptr);
	  op_ptr += 2;
	  op_ptr += offset;
	  goto no_push;

	case DW_OP_bra:
	  if (--stack_elt < 0)
	    abort ();
	  offset = read_2s (op_ptr);
	  op_ptr += 2;
	  if (stack[stack_elt] != 0)
	    op_ptr += offset;
	  goto no_push;

	case DW_OP_nop:
	  goto no_push;

	default:
	  abort ();
	}

      /* Most things push a result value.  */
      if ((size_t) stack_elt >= sizeof(stack)/sizeof(*stack))
	abort ();
      stack[++stack_elt] = result;
    no_push:;
    }

  /* We were executing this program to get a value.  It should be
     at top of stack.  */
  if (--stack_elt < 0)
    abort ();
  return stack[stack_elt];
}


/* Decode DWARF 2 call frame information. Takes pointers the
   instruction sequence to decode, current register information and
   CIE info, and the PC range to evaluate.  */

static void
execute_cfa_program (const unsigned char *insn_ptr,
		     const unsigned char *insn_end,
		     struct _Unwind_Context *context,
		     _Unwind_FrameState *fs)
{
  struct frame_state_reg_info *unused_rs = NULL;

  /* Don't allow remember/restore between CIE and FDE programs.  */
  fs->regs.prev = NULL;

  /* The comparison with the return address uses < rather than <= because
     we are only interested in the effects of code before the call; for a
     noreturn function, the return address may point to unrelated code with
     a different stack configuration that we are not interested in.  We
     assume that the call itself is unwind info-neutral; if not, or if
     there are delay instructions that adjust the stack, these must be
     reflected at the point immediately before the call insn.  */
  while (insn_ptr < insn_end && fs->pc < context->ra)
    {
      unsigned char insn = *insn_ptr++;
      _Unwind_Word reg, utmp;
      _Unwind_Sword offset, stmp;

      if ((insn & 0xc0) == DW_CFA_advance_loc)
	fs->pc += (insn & 0x3f) * fs->code_align;
      else if ((insn & 0xc0) == DW_CFA_offset)
	{
	  reg = insn & 0x3f;
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  offset = (_Unwind_Sword) utmp * fs->data_align;
	  fs->regs.reg[reg].how = REG_SAVED_OFFSET;
	  fs->regs.reg[reg].loc.offset = offset;
	}
      else if ((insn & 0xc0) == DW_CFA_restore)
	{
	  reg = insn & 0x3f;
	  fs->regs.reg[reg].how = REG_UNSAVED;
	}
      else switch (insn)
	{
	case DW_CFA_set_loc:
	  insn_ptr = read_encoded_value (context, fs->fde_encoding,
					 insn_ptr, (_Unwind_Ptr *) &fs->pc);
	  break;

	case DW_CFA_advance_loc1:
	  fs->pc += read_1u (insn_ptr) * fs->code_align;
	  insn_ptr += 1;
	  break;
	case DW_CFA_advance_loc2:
	  fs->pc += read_2u (insn_ptr) * fs->code_align;
	  insn_ptr += 2;
	  break;
	case DW_CFA_advance_loc4:
	  fs->pc += read_4u (insn_ptr) * fs->code_align;
	  insn_ptr += 4;
	  break;

	case DW_CFA_offset_extended:
	  insn_ptr = read_uleb128 (insn_ptr, &reg);
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  offset = (_Unwind_Sword) utmp * fs->data_align;
	  fs->regs.reg[reg].how = REG_SAVED_OFFSET;
	  fs->regs.reg[reg].loc.offset = offset;
	  break;

	case DW_CFA_restore_extended:
	  insn_ptr = read_uleb128 (insn_ptr, &reg);
	  fs->regs.reg[reg].how = REG_UNSAVED;
	  break;

	case DW_CFA_undefined:
	case DW_CFA_same_value:
	case DW_CFA_nop:
	  break;

	case DW_CFA_register:
	  {
	    _Unwind_Word reg2;
	    insn_ptr = read_uleb128 (insn_ptr, &reg);
	    insn_ptr = read_uleb128 (insn_ptr, &reg2);
	    fs->regs.reg[reg].how = REG_SAVED_REG;
	    fs->regs.reg[reg].loc.reg = reg2;
	  }
	  break;

	case DW_CFA_remember_state:
	  {
	    struct frame_state_reg_info *new_rs;
	    if (unused_rs)
	      {
		new_rs = unused_rs;
		unused_rs = unused_rs->prev;
	      }
	    else
	      new_rs = __builtin_alloca (sizeof (struct frame_state_reg_info));

	    *new_rs = fs->regs;
	    fs->regs.prev = new_rs;
	  }
	  break;

	case DW_CFA_restore_state:
	  {
	    struct frame_state_reg_info *old_rs = fs->regs.prev;
	    fs->regs = *old_rs;
	    old_rs->prev = unused_rs;
	    unused_rs = old_rs;
	  }
	  break;

	case DW_CFA_def_cfa:
	  insn_ptr = read_uleb128 (insn_ptr, &fs->cfa_reg);
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  fs->cfa_offset = utmp;
	  fs->cfa_how = CFA_REG_OFFSET;
	  break;

	case DW_CFA_def_cfa_register:
	  insn_ptr = read_uleb128 (insn_ptr, &fs->cfa_reg);
	  fs->cfa_how = CFA_REG_OFFSET;
	  break;

	case DW_CFA_def_cfa_offset:
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  fs->cfa_offset = utmp;
	  /* cfa_how deliberately not set.  */
	  break;

	case DW_CFA_def_cfa_expression:
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  fs->cfa_exp = insn_ptr;
	  fs->cfa_how = CFA_EXP;
	  insn_ptr += utmp;
	  break;

	case DW_CFA_expression:
	  insn_ptr = read_uleb128 (insn_ptr, &reg);
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  fs->regs.reg[reg].how = REG_SAVED_EXP;
	  fs->regs.reg[reg].loc.exp = insn_ptr;
	  insn_ptr += utmp;
	  break;

	  /* From the 2.1 draft.  */
	case DW_CFA_offset_extended_sf:
	  insn_ptr = read_uleb128 (insn_ptr, &reg);
	  insn_ptr = read_sleb128 (insn_ptr, &stmp);
	  offset = stmp * fs->data_align;
	  fs->regs.reg[reg].how = REG_SAVED_OFFSET;
	  fs->regs.reg[reg].loc.offset = offset;
	  break;

	case DW_CFA_def_cfa_sf:
	  insn_ptr = read_uleb128 (insn_ptr, &fs->cfa_reg);
	  insn_ptr = read_sleb128 (insn_ptr, &fs->cfa_offset);
	  fs->cfa_how = CFA_REG_OFFSET;
	  break;

	case DW_CFA_def_cfa_offset_sf:
	  insn_ptr = read_sleb128 (insn_ptr, &fs->cfa_offset);
	  /* cfa_how deliberately not set.  */
	  break;

	case DW_CFA_GNU_window_save:
	  /* ??? Hardcoded for SPARC register window configuration.  */
	  for (reg = 16; reg < 32; ++reg)
	    {
	      fs->regs.reg[reg].how = REG_SAVED_OFFSET;
	      fs->regs.reg[reg].loc.offset = (reg - 16) * sizeof (void *);
	    }
	  break;

	case DW_CFA_GNU_args_size:
	  insn_ptr = read_uleb128 (insn_ptr, &context->args_size);
	  break;

	case DW_CFA_GNU_negative_offset_extended:
	  /* Obsoleted by DW_CFA_offset_extended_sf, but used by
	     older PowerPC code.  */
	  insn_ptr = read_uleb128 (insn_ptr, &reg);
	  insn_ptr = read_uleb128 (insn_ptr, &utmp);
	  offset = (_Unwind_Word) utmp * fs->data_align;
	  fs->regs.reg[reg].how = REG_SAVED_OFFSET;
	  fs->regs.reg[reg].loc.offset = -offset;
	  break;

	default:
	  abort ();
	}
    }
}

/* Given the _Unwind_Context CONTEXT for a stack frame, look up the FDE for
   its caller and decode it into FS.  This function also sets the
   args_size and lsda members of CONTEXT, as they are really information
   about the caller's frame.  */

static _Unwind_Reason_Code
uw_frame_state_for (struct _Unwind_Context *context, _Unwind_FrameState *fs)
{
  struct dwarf_fde *fde;
  struct dwarf_cie *cie;
  const unsigned char *aug, *insn, *end;

  memset (fs, 0, sizeof (*fs));
  context->args_size = 0;
  context->lsda = 0;

  fde = _Unwind_Find_FDE (context->ra - 1, &context->bases);
  if (fde == NULL)
    {
      /* Couldn't find frame unwind info for this function.  Try a
	 target-specific fallback mechanism.  This will necessarily
	 not profide a personality routine or LSDA.  */
      return _URC_END_OF_STACK;
    }

  fs->pc = context->bases.func;

  cie = get_cie (fde);
  insn = extract_cie_info (cie, context, fs);
  if (insn == NULL)
    /* CIE contained unknown augmentation.  */
    return _URC_FATAL_PHASE1_ERROR;

  /* First let's process the defaults in the CIE.  */
  end = (unsigned char *) cie + cie->length + sizeof (cie->length);
  execute_cfa_program (insn, end, context, fs);

  /* Locate augmentation for the fde.  */
  aug = (unsigned char *) fde + sizeof (*fde);
  aug += 2 * size_of_encoded_value (fs->fde_encoding);
  insn = NULL;
  if (fs->saw_z)
    {
      _Unwind_Word i;
      aug = read_uleb128 (aug, &i);
      insn = aug + i;
    }
  if (fs->lsda_encoding != DW_EH_PE_omit)
    aug = read_encoded_value (context, fs->lsda_encoding, aug,
			      (_Unwind_Ptr *) &context->lsda);

  /* Then the insns in the FDE up to our target PC.  */
  if (insn == NULL)
    insn = aug;
  end = (unsigned char *) fde + fde->length + sizeof (fde->length);
  execute_cfa_program (insn, end, context, fs);

  return _URC_NO_REASON;
}

typedef struct frame_state
{
  void *cfa;
  void *eh_ptr;
  long cfa_offset;
  long args_size;
  long reg_or_offset[PRE_GCC3_DWARF_FRAME_REGISTERS+1];
  unsigned short cfa_reg;
  unsigned short retaddr_column;
  char saved[PRE_GCC3_DWARF_FRAME_REGISTERS+1];
} frame_state;

struct frame_state * __frame_state_for (void *, struct frame_state *);

/* Called from pre-G++ 3.0 __throw to find the registers to restore for
   a given PC_TARGET.  The caller should allocate a local variable of
   `struct frame_state' and pass its address to STATE_IN.  */

struct frame_state *
__frame_state_for (void *pc_target, struct frame_state *state_in)
{
  struct _Unwind_Context context;
  _Unwind_FrameState fs;
  int reg;

  memset (&context, 0, sizeof (struct _Unwind_Context));
  context.ra = pc_target + 1;

  if (uw_frame_state_for (&context, &fs) != _URC_NO_REASON)
    return 0;

  /* We have no way to pass a location expression for the CFA to our
     caller.  It wouldn't understand it anyway.  */
  if (fs.cfa_how == CFA_EXP)
    return 0;

  for (reg = 0; reg < PRE_GCC3_DWARF_FRAME_REGISTERS + 1; reg++)
    {
      state_in->saved[reg] = fs.regs.reg[reg].how;
      switch (state_in->saved[reg])
	{
	case REG_SAVED_REG:
	  state_in->reg_or_offset[reg] = fs.regs.reg[reg].loc.reg;
	  break;
	case REG_SAVED_OFFSET:
	  state_in->reg_or_offset[reg] = fs.regs.reg[reg].loc.offset;
	  break;
	default:
	  state_in->reg_or_offset[reg] = 0;
	  break;
	}
    }

  state_in->cfa_offset = fs.cfa_offset;
  state_in->cfa_reg = fs.cfa_reg;
  state_in->retaddr_column = fs.retaddr_column;
  state_in->args_size = context.args_size;
  state_in->eh_ptr = fs.eh_ptr;

  return state_in;
}

static void
uw_update_context_1 (struct _Unwind_Context *context, _Unwind_FrameState *fs)
{
  struct _Unwind_Context orig_context = *context;
  void *cfa;
  long i;

  /* Compute this frame's CFA.  */
  switch (fs->cfa_how)
    {
    case CFA_REG_OFFSET:
      /* Special handling here: Many machines do not use a frame pointer,
	 and track the CFA only through offsets from the stack pointer from
	 one frame to the next.  In this case, the stack pointer is never
	 stored, so it has no saved address in the context.  What we do
	 have is the CFA from the previous stack frame.  */
      if (context->reg[fs->cfa_reg] == NULL)
	cfa = context->cfa;
      else
	cfa = (void *) (_Unwind_Ptr) _Unwind_GetGR (context, fs->cfa_reg);
      cfa += fs->cfa_offset;
      break;

    case CFA_EXP:
      /* ??? No way of knowing what register number is the stack pointer
	 to do the same sort of handling as above.  Assume that if the
	 CFA calculation is so complicated as to require a stack program
	 that this will not be a problem.  */
      {
	const unsigned char *exp = fs->cfa_exp;
	_Unwind_Word len;

	exp = read_uleb128 (exp, &len);
	cfa = (void *) (_Unwind_Ptr)
	  execute_stack_op (exp, exp + len, context, 0);
	break;
      }

    default:
      abort ();
    }
  context->cfa = cfa;

  /* Compute the addresses of all registers saved in this frame.  */
  for (i = 0; i < DWARF_FRAME_REGISTERS + 1; ++i)
    switch (fs->regs.reg[i].how)
      {
      case REG_UNSAVED:
	break;
      case REG_SAVED_OFFSET:
	context->reg[i] = cfa + fs->regs.reg[i].loc.offset;
	break;
      case REG_SAVED_REG:
	context->reg[i] = orig_context.reg[fs->regs.reg[i].loc.reg];
	break;
      case REG_SAVED_EXP:
	{
	  const unsigned char *exp = fs->regs.reg[i].loc.exp;
	  _Unwind_Word len;
	  _Unwind_Ptr val;

	  exp = read_uleb128 (exp, &len);
	  val = execute_stack_op (exp, exp + len, &orig_context,
				  (_Unwind_Ptr) cfa);
	  context->reg[i] = (void *) val;
	}
	break;
      }
}

/* CONTEXT describes the unwind state for a frame, and FS describes the FDE
   of its caller.  Update CONTEXT to refer to the caller as well.  Note
   that the args_size and lsda members are not updated here, but later in
   uw_frame_state_for.  */

static void
uw_update_context (struct _Unwind_Context *context, _Unwind_FrameState *fs)
{
  uw_update_context_1 (context, fs);

  /* Compute the return address now, since the return address column
     can change from frame to frame.  */
  context->ra = __builtin_extract_return_addr
    ((void *) (_Unwind_Ptr) _Unwind_GetGR (context, fs->retaddr_column));
}

/* Fill in CONTEXT for top-of-stack.  The only valid registers at this
   level will be the return address and the CFA.  */

#define uw_init_context(CONTEXT)					   \
  do									   \
    {									   \
      /* Do any necessary initialization to access arbitrary stack frames. \
	 On the SPARC, this means flushing the register windows.  */	   \
      __builtin_unwind_init ();						   \
      uw_init_context_1 (CONTEXT, __builtin_dwarf_cfa (),		   \
			 __builtin_return_address (0));			   \
    }									   \
  while (0)

static inline void
init_dwarf_reg_size_table (void)
{
  __builtin_init_dwarf_reg_size_table (dwarf_reg_size_table);
}

static void
uw_init_context_1 (struct _Unwind_Context *context,
		   void *outer_cfa, void *outer_ra)
{
  void *ra = __builtin_extract_return_addr (__builtin_return_address (0));
  _Unwind_FrameState fs;

  memset (context, 0, sizeof (struct _Unwind_Context));
  context->ra = ra;

  if (uw_frame_state_for (context, &fs) != _URC_NO_REASON)
    abort ();

  /* Force the frame state to use the known cfa value.  */
  context->cfa = outer_cfa;
  fs.cfa_how = CFA_REG_OFFSET;
  fs.cfa_reg = 0;
  fs.cfa_offset = 0;

  uw_update_context_1 (context, &fs);

  /* If the return address column was saved in a register in the
     initialization context, then we can't see it in the given
     call frame data.  So have the initialization context tell us.  */
  context->ra = __builtin_extract_return_addr (outer_ra);
}


/* Install TARGET into CURRENT so that we will return to it.  The
   number of registers to install is limited by the size of the
   CONTEXT.  */

#define uw_install_context(CURRENT, TARGET)				 \
  do									 \
    {									 \
      long offset = uw_install_context_1 ((CURRENT), (TARGET));		 \
      void *handler = __builtin_frob_return_addr ((TARGET)->ra);	 \
      __builtin_eh_return (offset, handler);				 \
    }									 \
  while (0)

static long
uw_install_context_1 (struct _Unwind_Context *current,
		      struct _Unwind_Context *target)
{
  long i;

#if __GTHREADS
  {
    static __gthread_once_t once_regsizes = __GTHREAD_ONCE_INIT;
    if (__gthread_once (&once_regsizes, init_dwarf_reg_size_table) != 0
	|| dwarf_reg_size_table[0] == 0)
      init_dwarf_reg_size_table ();
  }
#else
  if (dwarf_reg_size_table[0] == 0)
    init_dwarf_reg_size_table ();
#endif

  for (i = 0; i < DWARF_FRAME_REGISTERS; ++i)
    {
      void *c = current->reg[i];
      void *t = target->reg[i];
      if (t && c && t != c)
	memcpy (c, t, dwarf_reg_size_table[i]);
    }

  /* We adjust SP by the difference between CURRENT and TARGET's CFA.  */
  if (STACK_GROWS_DOWNWARD)
    return target->cfa - current->cfa + target->args_size;
  else
    return current->cfa - target->cfa - target->args_size;
}

static inline _Unwind_Ptr
uw_identify_context (struct _Unwind_Context *context)
{
  return _Unwind_GetIP (context);
}


/* unwind.inc */

/* Subroutine of _Unwind_RaiseException also invoked from _Unwind_Resume. 

   Unwind the stack calling the personality routine to find both the
   exception handler and intermediary cleanup code.  We'll only locate
   the first such frame here.  Cleanup code will call back into
   _Unwind_Resume and we'll continue Phase 2 there.  */

static _Unwind_Reason_Code
_Unwind_RaiseException_Phase2(struct _Unwind_Exception *exc,
			      struct _Unwind_Context *context)
{
  _Unwind_Reason_Code code;

  while (1)
    {
      _Unwind_FrameState fs;
      int match_handler;

      code = uw_frame_state_for (context, &fs);

      /* Identify when we've reached the designated handler context.  */
      match_handler = (uw_identify_context (context) == exc->private_2
		       ? _UA_HANDLER_FRAME : 0);

      if (code != _URC_NO_REASON)
	/* Some error encountered.  Usually the unwinder doesn't
	   diagnose these types of errors.  That is the job of the
	   personality routine.  */
	return _URC_FATAL_PHASE2_ERROR;

      /* Unwind successful.  Run the personality routine, if any.  */
      if (fs.personality)
	{
	  code = (*fs.personality) (1, _UA_CLEANUP_PHASE | match_handler,
				    exc->exception_class, exc, context);
	  if (code == _URC_INSTALL_CONTEXT)
	    break;
	  if (code != _URC_CONTINUE_UNWIND)
	    return _URC_FATAL_PHASE2_ERROR;
	}

      /* Don't let us unwind past the handler context.  */
      if (match_handler)
	abort ();

      uw_update_context (context, &fs);
    }

  return code;
}


/* Raise an exception, passing along the given exception object.  */

_Unwind_Reason_Code
_Unwind_RaiseException(struct _Unwind_Exception *exc)
{
  struct _Unwind_Context this_context, cur_context;
  _Unwind_Reason_Code code;

  /* Set up this_context to describe the current stack frame.  */
  uw_init_context (&this_context);
  cur_context = this_context;

  /* Phase 1: Search.  Unwind the stack, calling the personality routine
     with the _UA_SEARCH_PHASE flag set.  Do not modify the stack yet.  */
  while (1)
    {
      _Unwind_FrameState fs;

      /* Set up fs to describe the FDE for the caller of cur_context.  The
	 first time through the loop, that means __cxa_throw.  */
      code = uw_frame_state_for (&cur_context, &fs);

      if (code == _URC_END_OF_STACK)
	/* Hit end of stack with no handler found.  */
	return _URC_END_OF_STACK;

      if (code != _URC_NO_REASON)
	/* Some error encountered.  Ususally the unwinder doesn't
	   diagnose these types of errors.  That is the job of the
	   personality routine.  */
	return _URC_FATAL_PHASE1_ERROR;

      /* Unwind successful.  Run the personality routine, if any.  */
      if (fs.personality)
	{
	  code = (*fs.personality) (1, _UA_SEARCH_PHASE, exc->exception_class,
				    exc, &cur_context);
	  if (code == _URC_HANDLER_FOUND)
	    break;
	  else if (code != _URC_CONTINUE_UNWIND)
	    return _URC_FATAL_PHASE1_ERROR;
	}

      /* Update cur_context to describe the same frame as fs.  */
      uw_update_context (&cur_context, &fs);
    }

  /* Indicate to _Unwind_Resume and associated subroutines that this
     is not a forced unwind.  Further, note where we found a handler.  */
  exc->private_1 = 0;
  exc->private_2 = uw_identify_context (&cur_context);

  cur_context = this_context;
  code = _Unwind_RaiseException_Phase2 (exc, &cur_context);
  if (code != _URC_INSTALL_CONTEXT)
    return code;

  uw_install_context (&this_context, &cur_context);
}


/* Subroutine of _Unwind_ForcedUnwind also invoked from _Unwind_Resume.  */

static _Unwind_Reason_Code
_Unwind_ForcedUnwind_Phase2(struct _Unwind_Exception *exc,
			    struct _Unwind_Context *context)
{
  _Unwind_Stop_Fn stop = (_Unwind_Stop_Fn) (_Unwind_Ptr) exc->private_1;
  void *stop_argument = (void *) (_Unwind_Ptr) exc->private_2;
  _Unwind_Reason_Code code, stop_code;

  while (1)
    {
      _Unwind_FrameState fs;
      int action;

      /* Set up fs to describe the FDE for the caller of cur_context.  */
      code = uw_frame_state_for (context, &fs);
      if (code != _URC_NO_REASON && code != _URC_END_OF_STACK)
	return _URC_FATAL_PHASE2_ERROR;

      /* Unwind successful.  */
      action = _UA_FORCE_UNWIND | _UA_CLEANUP_PHASE;
      if (code == _URC_END_OF_STACK)
	action |= _UA_END_OF_STACK;
      stop_code = (*stop) (1, action, exc->exception_class, exc,
			   context, stop_argument);
      if (stop_code != _URC_NO_REASON)
	return _URC_FATAL_PHASE2_ERROR;

      /* Stop didn't want to do anything.  Invoke the personality
	 handler, if applicable, to run cleanups.  */
      if (code == _URC_END_OF_STACK)
	break;
	
      if (fs.personality)
	{
	  code = (*fs.personality) (1, _UA_FORCE_UNWIND | _UA_CLEANUP_PHASE,
				    exc->exception_class, exc, context);
	  if (code == _URC_INSTALL_CONTEXT)
	    break;
	  if (code != _URC_CONTINUE_UNWIND)
	    return _URC_FATAL_PHASE2_ERROR;
	}

      /* Update cur_context to describe the same frame as fs.  */
      uw_update_context (context, &fs);
    }

  return code;
}


/* Raise an exception for forced unwinding.  */

_Unwind_Reason_Code
_Unwind_ForcedUnwind (struct _Unwind_Exception *exc,
		      _Unwind_Stop_Fn stop, void * stop_argument)
{
  struct _Unwind_Context this_context, cur_context;
  _Unwind_Reason_Code code;

  uw_init_context (&this_context);
  cur_context = this_context;

  exc->private_1 = (_Unwind_Ptr) stop;
  exc->private_2 = (_Unwind_Ptr) stop_argument;

  code = _Unwind_ForcedUnwind_Phase2 (exc, &cur_context);
  if (code != _URC_INSTALL_CONTEXT)
    return code;

  uw_install_context (&this_context, &cur_context);
}


/* Resume propagation of an existing exception.  This is used after
   e.g. executing cleanup code, and not to implement rethrowing.  */

void
_Unwind_Resume (struct _Unwind_Exception *exc)
{
  struct _Unwind_Context this_context, cur_context;
  _Unwind_Reason_Code code;

  uw_init_context (&this_context);
  cur_context = this_context;

  /* Choose between continuing to process _Unwind_RaiseException
     or _Unwind_ForcedUnwind.  */
  if (exc->private_1 == 0)
    code = _Unwind_RaiseException_Phase2 (exc, &cur_context);
  else
    code = _Unwind_ForcedUnwind_Phase2 (exc, &cur_context);

  if (code != _URC_INSTALL_CONTEXT)
    abort ();

  uw_install_context (&this_context, &cur_context);
}


/* A convenience function that calls the exception_cleanup field.  */

void
_Unwind_DeleteException (struct _Unwind_Exception *exc)
{
  (*exc->exception_cleanup) (_URC_FOREIGN_EXCEPTION_CAUGHT, exc);
}
