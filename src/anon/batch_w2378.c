/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */

/* 00317ee8 is libgcc's __frame_state_for (gcc 3.2 unwind-dw2.c), written from the GCC source. */
typedef unsigned int _Unwind_Word __attribute__((__mode__(__word__)));
typedef signed int _Unwind_Sword __attribute__((__mode__(__word__)));
typedef unsigned int _Unwind_Ptr __attribute__((__mode__(__pointer__)));
void *func_002fde18(void *, int, unsigned int);
#define DWARF_FRAME_REGISTERS 176
#define PRE_GCC3_DWARF_FRAME_REGISTERS 176
struct dwarf_eh_bases { void *tbase; void *dbase; void *func; };
struct _Unwind_Context {
  void *reg[DWARF_FRAME_REGISTERS+1];
  void *cfa;
  void *ra;
  void *lsda;
  struct dwarf_eh_bases bases;
  _Unwind_Word args_size;
};
typedef struct {
  struct frame_state_reg_info {
    struct {
      union { _Unwind_Word reg; _Unwind_Sword offset; const unsigned char *exp; } loc;
      enum { REG_UNSAVED, REG_SAVED_OFFSET, REG_SAVED_REG, REG_SAVED_EXP } how;
    } reg[DWARF_FRAME_REGISTERS+1];
    struct frame_state_reg_info *prev;
  } regs;
  _Unwind_Sword cfa_offset;
  _Unwind_Word cfa_reg;
  const unsigned char *cfa_exp;
  enum { CFA_UNSET, CFA_REG_OFFSET, CFA_EXP } cfa_how;
  _Unwind_Ptr pc;
  void *personality;
  _Unwind_Sword data_align;
  _Unwind_Word code_align;
  unsigned char retaddr_column;
  unsigned char fde_encoding;
  unsigned char lsda_encoding;
  unsigned char saw_z;
  void *eh_ptr;
} _Unwind_FrameState;
typedef struct frame_state {
  void *cfa;
  void *eh_ptr;
  long cfa_offset;
  long args_size;
  long reg_or_offset[PRE_GCC3_DWARF_FRAME_REGISTERS+1];
  unsigned short cfa_reg;
  unsigned short retaddr_column;
  char saved[PRE_GCC3_DWARF_FRAME_REGISTERS+1];
} frame_state;
int func_00317d80(struct _Unwind_Context *, _Unwind_FrameState *);
#define uw_frame_state_for func_00317d80
#define memset func_002fde18

struct frame_state *
func_00317ee8 (void *pc_target, struct frame_state *state_in)
{
  struct _Unwind_Context context;
  _Unwind_FrameState fs;
  int reg;

  memset (&context, 0, sizeof (struct _Unwind_Context));
  context.ra = pc_target + 1;

  if (uw_frame_state_for (&context, &fs) != 0)
    return 0;

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
