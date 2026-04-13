.section .data

	num:	.quad 5

.text

.global main

main:

	movq	num(%rip),	%rdx  ##作为比较标准
	movq	$0,			%rax
	movq	$0,			%rcx  ##作为循环的次数记录
	
add_loop:

	addq	$1,		%rcx	#rcx增一后
	addq	%rcx,	%rax	#加到ax里
	cmpq	%rdx,	%rcx	# 比较一下计数器，是否仍然小于等于门槛

	jb add_loop

#只要不高于，就可以继续循环

	 movq %rax,	%rdi
	 movq $60,	%rax
	 syscall


	
