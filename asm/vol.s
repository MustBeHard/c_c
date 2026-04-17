.section .data
	radius:	.quad 5
	height: .quad 10
	fmt: .string "Volume is: %ld\n"

.section .text

.global main

main:

##先清理栈，标记
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	$9,		%rsp

##把参数加载
	movq	radius(%rip),	%rdi
	movq	height(%rip),	%rax

##计算 volume = radius X radius X height X 3
	
	imulq	%rdi,	%rdi
	imulq	%rdi,	%rax
	imulq	$3,		%rax

##开始配置参数
	leaq	fmt(%rip),	%rdi
	movq	%rax,		%rsi
	movq	$0,			%rax

	call printf

##系统退出
	movq	$60,	%rax
	movq	$0,		%rdi
	syscall
