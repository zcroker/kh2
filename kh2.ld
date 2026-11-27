_start = 0x0010001C;
ENTRY(_start);
INCLUDE out/generated/symbols.ld

SECTIONS {
  /* @CXX_SECTIONS@ */

  . = 0x0037A4B4;
  .ctors : {
    KEEP(*(SORT(.ctors.*)))
    KEEP(*(.ctors))
  }

  . = 0x0037A6E8;
  .dtors : {
    KEEP(*(SORT(.dtors.*)))
    KEEP(*(.dtors))
  }

  . = 0x00400000;
  .cxx_text : {
    *(.text .text.* .gnu.linkonce.t*)
  }

  .cxx_rodata : {
    *(.rodata)
    *(.rodata.*)
    *(.gnu.linkonce.r*)
  }

  /* The game's gp (main sets $gp = 0x37A800). A linked unit built -G8 (a `-G8` token in its
     linked_units.tsv row) reads small-data globals gp-relative; with this _gp their GPREL16
     relocations resolve to the original offsets (the globals get their game addresses from
     symbols.ld). The function path's own .sdata (short literals) goes to .cxx_sdata (after .cxx_bss), inside
     gp's +-32 KB reach; build_elf.py retargets those immediates by content, not by link address. */
  _gp = 0x0037A800;
  .cxx_data : {
    *(.data)
    *(.data.*)
    *(.gnu.linkonce.d*)
  }

  .reginfo : { *(.reginfo) }

  _edata = .;

  .cxx_bss (NOLOAD) : {
    _fbss = .;
    *(.sbss)
    *(.sbss.*)
    *(.scommon)
    *(.bss)
    *(.bss.*)
    *(.gnu.linkonce.b*)
    *(COMMON)
    _end_bss = .;
  }

  /* After everything else: a fixed address here moves no other section. */
  .cxx_sdata 0x00382000 : {
    *(.sdata)
    *(.sdata.*)
    *(.gnu.linkonce.s*)
  }

  /DISCARD/ : {
    *(.MIPS.abiflags)
    *(.comment)
    *(.pdr)
    *(.mdebug*)
    *(.eh_frame)
    *(.gcc_except_table)
    *(.gnu.attributes)
  }
}
