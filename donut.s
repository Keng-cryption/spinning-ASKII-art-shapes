	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	mov	w9, #11296                      ; =0x2c20
	movk	w9, #1, lsl #16
Lloh0:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh1:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #18, lsl #12            ; =73728
	sub	sp, sp, #3104
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	sub	x9, x29, #48
	str	x9, [sp, #16]                   ; 8-byte Folded Spill
	str	wzr, [x9, #28]
	mov	w8, #35                         ; =0x23
	str	w8, [x9, #20]
	mov	w8, #70                         ; =0x46
	str	w8, [x9, #24]
	movi	d0, #0000000000000000
	str	s0, [x9, #16]
	str	s0, [x9, #12]
	mov	w8, #213                        ; =0xd5
	str	w8, [x9, #8]
	mov	w8, #72                         ; =0x48
	str	w8, [x9, #4]
	mov	w8, #15336                      ; =0x3be8
	str	w8, [x9]
	mov	x9, #15336                      ; =0x3be8
	add	x8, sp, #119
	add	x8, x8, x9
	strb	wzr, [x8]
	adrp	x8, l_.str@PAGE
	add	x8, x8, l_.str@PAGEOFF
	str	x8, [sp, #104]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	b	LBB0_1
LBB0_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_2 Depth 2
                                        ;       Child Loop BB0_4 Depth 3
                                        ;     Child Loop BB0_19 Depth 2
	add	x0, sp, #119
	mov	x2, #15336                      ; =0x3be8
	mov	w1, #32                         ; =0x20
	bl	_memset
	add	x0, sp, #3, lsl #12             ; =12288
	add	x0, x0, #3168
	mov	x1, #61344                      ; =0xefa0
	bl	_bzero
	movi	d0, #0000000000000000
	str	s0, [sp, #100]
	b	LBB0_2
LBB0_2:                                 ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Loop Header: Depth=2
                                        ;       Child Loop BB0_4 Depth 3
	ldr	s0, [sp, #100]
	mov	w8, #62915                      ; =0xf5c3
	movk	w8, #16584, lsl #16
	fmov	s1, w8
	fcmp	s0, s1
	b.pl	LBB0_18
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_2 Depth=2
	movi	d0, #0000000000000000
	str	s0, [sp, #96]
	b	LBB0_4
LBB0_4:                                 ;   Parent Loop BB0_1 Depth=1
                                        ;     Parent Loop BB0_2 Depth=2
                                        ; =>    This Inner Loop Header: Depth=3
	ldr	s0, [sp, #96]
	mov	w8, #62915                      ; =0xf5c3
	movk	w8, #16584, lsl #16
	fmov	s1, w8
	fcmp	s0, s1
	b.pl	LBB0_16
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_4 Depth=3
	ldr	s0, [sp, #96]
	bl	_sinf
	str	s0, [sp, #92]
	ldr	s0, [sp, #96]
	bl	_cosf
	str	s0, [sp, #88]
	ldr	s0, [sp, #100]
	bl	_sinf
	str	s0, [sp, #84]
	ldr	s0, [sp, #100]
	bl	_cosf
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	str	s0, [sp, #80]
	ldr	s0, [x8, #16]
	bl	_sinf
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	str	s0, [sp, #76]
	ldr	s0, [x8, #16]
	bl	_cosf
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	str	s0, [sp, #72]
	ldr	s0, [x8, #12]
	bl	_sinf
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	str	s0, [sp, #68]
	ldr	s0, [x8, #12]
	bl	_cosf
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	str	s0, [sp, #64]
	ldr	s0, [sp, #80]
	fmov	s1, #2.00000000
	fadd	s0, s0, s1
	str	s0, [sp, #60]
	ldr	s0, [sp, #92]
	ldr	s1, [sp, #60]
	fmul	s0, s0, s1
	ldr	s1, [sp, #76]
	ldr	s2, [sp, #84]
	ldr	s3, [sp, #72]
	fmul	s2, s2, s3
	fmadd	s0, s0, s1, s2
	fmov	s1, #5.00000000
	fadd	s1, s0, s1
	fmov	s0, #1.00000000
	fdiv	s0, s0, s1
	str	s0, [sp, #56]
	ldr	s0, [sp, #92]
	ldr	s1, [sp, #60]
	fmul	s0, s0, s1
	ldr	s1, [sp, #72]
	ldr	s2, [sp, #84]
	ldr	s3, [sp, #76]
	fmul	s2, s2, s3
	fnmsub	s0, s0, s1, s2
	str	s0, [sp, #52]
	ldr	s0, [sp, #88]
	ldr	s1, [sp, #60]
	fmul	s0, s0, s1
	ldr	s1, [sp, #64]
	ldr	s2, [sp, #52]
	ldr	s3, [sp, #68]
	fmul	s2, s2, s3
	fnmsub	s0, s0, s1, s2
	str	s0, [sp, #48]
	ldr	s0, [sp, #88]
	ldr	s1, [sp, #60]
	fmul	s0, s0, s1
	ldr	s1, [sp, #68]
	ldr	s2, [sp, #52]
	ldr	s3, [sp, #64]
	fmul	s2, s2, s3
	fmadd	s0, s0, s1, s2
	str	s0, [sp, #44]
	ldr	s0, [x8, #24]
	scvtf	s0, s0
	ldr	s1, [sp, #56]
	fmul	s0, s0, s1
	ldr	s1, [sp, #48]
	mov	w9, #1121189888                 ; =0x42d40000
	fmov	s2, w9
	fmadd	s0, s0, s1, s2
	fcvtzs	w9, s0
	str	w9, [sp, #40]
	ldr	s0, [x8, #20]
	scvtf	s0, s0
	ldr	s1, [sp, #56]
	fmul	s0, s0, s1
	ldr	s1, [sp, #44]
	mov	w8, #1108344832                 ; =0x42100000
	fmov	s2, w8
	fmadd	s0, s0, s1, s2
	fcvtzs	w8, s0
	str	w8, [sp, #36]
	ldr	w8, [sp, #40]
	ldr	w10, [sp, #36]
	mov	w9, #213                        ; =0xd5
	mul	w9, w9, w10
	add	w8, w8, w9
	str	w8, [sp, #32]
	ldr	s0, [sp, #84]
	ldr	s1, [sp, #76]
	ldr	s2, [sp, #92]
	ldr	s3, [sp, #80]
	fmul	s2, s2, s3
	ldr	s3, [sp, #72]
	fmul	s2, s2, s3
	fnmsub	s0, s0, s1, s2
	ldr	s1, [sp, #64]
	ldr	s2, [sp, #92]
	ldr	s3, [sp, #80]
	fmul	s2, s2, s3
	ldr	s3, [sp, #76]
	fmul	s2, s2, s3
	fnmsub	s2, s0, s1, s2
	ldr	s0, [sp, #84]
	ldr	s1, [sp, #72]
	fmsub	s2, s0, s1, s2
	ldr	s0, [sp, #88]
	ldr	s1, [sp, #80]
	fmul	s0, s0, s1
	ldr	s1, [sp, #68]
	fmsub	s1, s0, s1, s2
	fmov	s0, #8.00000000
	fmul	s0, s0, s1
	fcvtzs	w8, s0
	str	w8, [sp, #28]
	ldr	w8, [sp, #40]
	tbnz	w8, #31, LBB0_14
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_4 Depth=3
	ldr	w8, [sp, #40]
	subs	w8, w8, #213
	b.ge	LBB0_14
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_4 Depth=3
	ldr	w8, [sp, #36]
	tbnz	w8, #31, LBB0_14
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_4 Depth=3
	ldr	w8, [sp, #36]
	subs	w8, w8, #72
	b.ge	LBB0_14
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_4 Depth=3
	ldr	s0, [sp, #56]
	ldrsw	x9, [sp, #32]
	add	x8, sp, #3, lsl #12             ; =12288
	add	x8, x8, #3168
	ldr	s1, [x8, x9, lsl #2]
	fcmp	s0, s1
	b.le	LBB0_14
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_4 Depth=3
	ldr	s0, [sp, #56]
	ldrsw	x9, [sp, #32]
	add	x8, sp, #3, lsl #12             ; =12288
	add	x8, x8, #3168
	str	s0, [x8, x9, lsl #2]
	ldr	x8, [sp, #104]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	ldr	w8, [sp, #28]
	subs	w8, w8, #0
	b.le	LBB0_12
	b	LBB0_11
LBB0_11:                                ;   in Loop: Header=BB0_4 Depth=3
	ldr	w8, [sp, #28]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	b	LBB0_13
LBB0_12:                                ;   in Loop: Header=BB0_4 Depth=3
	mov	w8, #0                          ; =0x0
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	b	LBB0_13
LBB0_13:                                ;   in Loop: Header=BB0_4 Depth=3
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	ldr	w9, [sp, #4]                    ; 4-byte Folded Reload
	add	x8, x8, w9, sxtw
	ldrb	w8, [x8]
	ldrsw	x10, [sp, #32]
	add	x9, sp, #119
	add	x9, x9, x10
	strb	w8, [x9]
	b	LBB0_14
LBB0_14:                                ;   in Loop: Header=BB0_4 Depth=3
	b	LBB0_15
LBB0_15:                                ;   in Loop: Header=BB0_4 Depth=3
	ldr	s0, [sp, #96]
	mov	w8, #55050                      ; =0xd70a
	movk	w8, #15523, lsl #16
	fmov	s1, w8
	fadd	s0, s0, s1
	str	s0, [sp, #96]
	b	LBB0_4
LBB0_16:                                ;   in Loop: Header=BB0_2 Depth=2
	b	LBB0_17
LBB0_17:                                ;   in Loop: Header=BB0_2 Depth=2
	ldr	s0, [sp, #100]
	mov	w8, #23593                      ; =0x5c29
	movk	w8, #15759, lsl #16
	fmov	s1, w8
	fadd	s0, s0, s1
	str	s0, [sp, #100]
	b	LBB0_2
LBB0_18:                                ;   in Loop: Header=BB0_1 Depth=1
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	str	wzr, [sp, #24]
	b	LBB0_19
LBB0_19:                                ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp, #24]
	subs	w8, w8, #72
	b.ge	LBB0_22
	b	LBB0_20
LBB0_20:                                ;   in Loop: Header=BB0_19 Depth=2
	ldr	w8, [sp, #24]
	mov	w9, #213                        ; =0xd5
	mul	w9, w8, w9
	add	x8, sp, #119
	add	x0, x8, w9, sxtw
	adrp	x8, ___stdoutp@GOTPAGE
	ldr	x8, [x8, ___stdoutp@GOTPAGEOFF]
	ldr	x3, [x8]
	mov	x1, #1                          ; =0x1
	mov	x2, #213                        ; =0xd5
	bl	_fwrite
	mov	w0, #10                         ; =0xa
	bl	_putchar
	b	LBB0_21
LBB0_21:                                ;   in Loop: Header=BB0_19 Depth=2
	ldr	w8, [sp, #24]
	add	w8, w8, #1
	str	w8, [sp, #24]
	b	LBB0_19
LBB0_22:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	s0, [x8, #16]
	mov	w9, #55050                      ; =0xd70a
	movk	w9, #15651, lsl #16
	fmov	s1, w9
	fadd	s0, s0, s1
	str	s0, [x8, #16]
	ldr	s0, [x8, #12]
	mov	w9, #55050                      ; =0xd70a
	movk	w9, #15523, lsl #16
	fmov	s1, w9
	fadd	s0, s0, s1
	str	s0, [x8, #12]
	mov	w0, #30000                      ; =0x7530
	bl	_usleep
	b	LBB0_1
	.loh AdrpLdrGot	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	".,-~:;=!*#$@"

l_.str.1:                               ; @.str.1
	.asciz	"\033[2J"

l_.str.2:                               ; @.str.2
	.asciz	"\033[H"

.subsections_via_symbols
