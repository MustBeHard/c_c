.section .data
	danger_level: .quad 120
	threshold:	.quad	100

.text

.global main

main:
	
	movq	danger_level(%rip),	%rax  #警告级别
	movq	threshold(%rip),	%rdx

	cmpq	%rdx,	%rax	## 目标 去比较 源

	ja		alart			## 如果目标ax在dx之上，那么警告


	movq $60,	%eax		## 没触发就自然进行
	movq $0,	%rdi
	syscall

alart:						
	movq $60,	%eax
	movq $1,	%rdi
	syscall

