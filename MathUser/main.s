	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -48(%rbp)
	movl	$20, -44(%rbp)
	movl	$1, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$3, -24(%rbp)
	movl	$4, -20(%rbp)
	movl	$5, -16(%rbp)
	leaq	-32(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	mean
	movl	%eax, -40(%rbp)
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	add
	movl	%eax, -36(%rbp)
	movl	$10, %edi
	call	putchar
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	printResult
	movl	$10, %edi
	call	putchar
	movl	-40(%rbp), %eax
	movl	%eax, %edi
	call	printResult
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
