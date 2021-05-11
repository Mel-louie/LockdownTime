;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.4 #11941 (Mac OS X x86_64)
;--------------------------------------------------------
	.module main
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _gbt_update
	.globl _gbt_loop
	.globl _gbt_play
	.globl _wait_vbl_done
	.globl _set_interrupts
	.globl _disable_interrupts
	.globl _enable_interrupts
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:41: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src/main.c:43: disable_interrupts();
	call	_disable_interrupts
;src/main.c:45: gbt_play(song_Data, 2, 7);
	ld	de, #0x0702
	push	de
	ld	hl, #_song_Data
	push	hl
	call	_gbt_play
	add	sp, #4
;src/main.c:46: gbt_loop(0);
	xor	a, a
	push	af
	inc	sp
	call	_gbt_loop
	inc	sp
;src/main.c:48: set_interrupts(VBL_IFLAG);
	ld	a, #0x01
	push	af
	inc	sp
	call	_set_interrupts
	inc	sp
;src/main.c:49: enable_interrupts();
	call	_enable_interrupts
;src/main.c:51: while (1)
00102$:
;src/main.c:53: wait_vbl_done();
	call	_wait_vbl_done
;src/main.c:55: gbt_update(); // This will change to ROM bank 1.
	call	_gbt_update
;src/main.c:57: }
	jr	00102$
	.area _CODE
	.area _CABS (ABS)
