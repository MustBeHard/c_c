## Gemini的鼓励让我压力倍增
# 接连两个代码都出现了低级错误

.section .data
	tips:	.string "loops continuing~~~~~%ld\n"
	final:	.string "the result is %d\n The end.\n"
.section .text

.global main

main:
	
	movq	$10,	%r14
	movq	$0,		%rbx

loops:
	addq	$10,	%rbx
	leaq	tips(%rip),	%rdi
	movq	%rbx,	%rsi
	movq	$0,		%rax
	call printf

	decq	%r14
	cmpq	$0,		%r14
	jg	loops

	leaq	final(%rip),	%rdi
	movq	%rbx,	%rsi
	movq	$0,	%rax
	call printf

end:
	movq $60, %rax
	movq $0,  %rdi
	syscall
	
