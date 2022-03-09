	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	_insertion_sort                 ## -- Begin function insertion_sort
	.p2align	4, 0x90
_insertion_sort:                        ## @insertion_sort
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -24(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	movl	-24(%rbp), %eax
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
.subsections_via_symbols
