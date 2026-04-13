.section .data
	val1: .quad 50
	val2: .quad 20
.text

.global main

main:
	pushq %rbp
	movq %rsp,%rbp  ## 养成习惯，每次运行函数都存储之前的栈状态

	movq	$val1 , %rsi
	movq	(%rsi), %rax	##把val1 存入rax

	movq	$val2,	%rsi
	movq	(%rsi),	%rdx	##把vla2 存入rdx


	subq	%rdx,	%rax	# 现在rax = rax-rdx 50-20 =30
###我的方法，需要控制台 echo $?

#	popq %rbp
#	ret


	## 所谓硬核路线，我照抄
	movq	$60,	%rax
	movq	$1,		%rdi
	syscall
