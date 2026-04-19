.section .data
	fmt:	.ascii "What you input:%s\n"

.section .bss
	.align 4
	.lcomm var,64

.section .text
.global main

main:

	#调用输入
	movq $0,	%rax
	movq $0,	%rdi
	leaq var(%rip),	%rsi
	movq $64,	%rdx
	syscall

#输出到屏幕
	movq $1,	%rax
	movq $1,	%rdi
	leaq fmt(%rip),%rsi
	movq var(%rip),%rdx
	syscall

	exit:
#系统退出
	movq $60,%rax
	movq $0, %rdi
	syscall

