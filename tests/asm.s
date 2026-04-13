	.section	.rodata
	.LC0: 
		.string	"\033[32mHello Assembly!\033[0m"
      	.text

.globl	say

say:
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	popq	%rbp
	ret

.globl	main

main:
	pushq	%rbp
	movq	%rsp, %rbp
	call	say
	movl	$0, %eax
	popq	%rbp
	ret
