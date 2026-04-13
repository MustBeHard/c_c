.section .data
	fmt:	.string "%d, %d, %d\n"
	va: .quad 20
	vb: .quad 30
	vc: .quad 40

.text

.global main

main:
	
	pushq %rbp
	movq %rsp,	%rbp

	movq va(%rip),	%rax
	pushq %rax

	movq vb(%rip), %rax
	pushq %rax

	movq vc(%rip), %rax
	pushq %rax

	popq %rdi

	movq $60,	%rax
	syscall
