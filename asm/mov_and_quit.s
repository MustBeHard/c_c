.section .data
	a:
		.quad 30
	b:
		.quad 0
.text

.global main

main:
	pushq %rbp
	movq %rsp,%rbp

	movq $a,%rsi	
	movq (%rsi),%rax
	movq %rax,%rdx

	movq $1,%rax
	popq %rbp


