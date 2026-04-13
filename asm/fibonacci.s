.section .data

	title: .string "\033[32m <SORT>\t <DATA>\033[0m\n"
	sort: .string "%d \t %d\n"
	gate: .quad 5

.text

.global main

main:
	
	pushq %rbp
	movq %rsp,%rbp

# 先打印标头
	movq $title,%rdi
	movq $0,	%rax
	call printf

# 开始初始化
	movq $1,	%rcx		#	计数器归零
	movq $1,	%rdx		#   rax = 1
	movq $0,	%rbx		#   rbx ==0
#sort = rcx data = rdx
	
	movq $sort, %rdi
	movq %rcx,	%rsi
	movq $0,	%rdx

	movq $1,%rax
	pushq %rsi
	pushq %rdx

#call printf

prt:
	addq $1,	%rcx
	movq $sort,	%rdi
	movq %rcx,	%rsi
	addq %rbx,	%rdx
	movq $1,	%rax
	
	pushq %rsi
	pushq %rdx
	
	movq %rdx,	%rbx
	cmpq $5,	%rcx

	jb prt


#再次初始化
movq $1,%rbx

	pp:
	movq $sort,%rdi
	popq %rdx ;
	popq %rsi

	movq $1,%rax
	call printf
	
	addq $1,%rbx

	cmpq $5,%rbx
	jb pp


	



	
#结尾
	movq $60, %rax
	movq $1,  %rdi
	syscall
