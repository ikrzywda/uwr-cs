	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	_insertion_sort                 ## -- Begin function insertion_sort
	.p2align	4, 0x90
_insertion_sort:                        ## @insertion_sort
	.cfi_startproc
## %bb.0:
	pushq	%rbp	; pushq - push 8 bytes to rbp register
	.cfi_def_cfa_offset 16 	
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -24(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	movl	-24(%rbp), %eax				; move long
	cmpl	-12(%rbp), %eax
	jge	LBB0_9
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-24(%rbp), %eax
	movl	%eax, -16(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	cmpl	$0, -16(%rbp)
	movb	%al, -25(%rbp)                  ## 1-byte Spill
	jle	LBB0_5
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=2
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	(%rax,%rcx,4), %eax
	movq	-8(%rbp), %rcx
	movl	-16(%rbp), %edx
	subl	$1, %edx
	movslq	%edx, %rdx
	cmpl	(%rcx,%rdx,4), %eax
	setl	%al
	movb	%al, -25(%rbp)                  ## 1-byte Spill
LBB0_5:                                 ##   in Loop: Header=BB0_3 Depth=2
	movb	-25(%rbp), %al                  ## 1-byte Reload
	testb	$1, %al
	jne	LBB0_6
	jmp	LBB0_7
LBB0_6:                                 ##   in Loop: Header=BB0_3 Depth=2
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	(%rax,%rcx,4), %eax
	movl	%eax, -20(%rbp)
	movq	-8(%rbp), %rax
	movl	-16(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	%edx, (%rax,%rcx,4)
	movl	-20(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	-16(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rcx
	movl	%edx, (%rax,%rcx,4)
	movl	-16(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_3
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_8
LBB0_8:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB0_1
LBB0_9:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	l___const.main.arr(%rip), %rsi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	leaq	-48(%rbp), %rdi
	movl	$40, %edx
	callq	_memcpy
	leaq	-48(%rbp), %rdi
	movl	$10, %esi
	callq	_insertion_sort
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB1_2
## %bb.1:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
LBB1_2:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4                               ## @__const.main.arr
l___const.main.arr:
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	0                               ## 0x0

.subsections_via_symbols
