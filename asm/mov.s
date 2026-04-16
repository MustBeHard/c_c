.section .data
	fmt:	.string "%ld\n"
	num:	.quad 10

.text

.global main

main:

	pushq	%rbp
	movq	%rsp,	%rbp

	movq	num(%rip),	%rsi
	movq	%rsi,	%rax
	movq	%rax,	%rbx

	movq	%rbx,	-8(%rbp)
	
	movq	-8(%rbp),	%rcx
	
	leaq	fmt(%rip),	%rdi
	movq	%rcx,	%rsi
	movq	$0,		%rax
	call printf

	movq	$60,	%rax
	movq	$0,		%rdi
	syscall

