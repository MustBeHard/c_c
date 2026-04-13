.section .data

	title: .string "\033[32m <SORT>\t <NUMBER>\033[0m\n"
	sort: .string ">> %d \t %d<<\n"
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
	movq $0,%rcx
	movq $1,%rax

	movq $rax,%rdx

lp: #循环制造数字，入栈
	addq $1,  %rcx		# 每次循环counter+1
	
	cmpq $1,%rcx  		# 如果counter==1 特殊处理，直接压入栈
	je sp 				# 一次性的条件判断

	movq %rax,%rdx		# 再次把rax传给dx
	addq %rdx,%rax		# ax = dx 然后相加

	pushq %rcx
	pushq %rax

	cmpq gate(%rip),%rcx
	jb lp

sp:
	pushq %rcx			#顺序压入栈1 
	pushq %rax  		#把特殊的n=1压入栈
	movq $0,%rdx		# 特殊处理，把dx归零，因为n=1 时，需要和前一个0相加
	jmp lp				# 跳回循环并且从此cx不再是1 这时一次性的处理

#-----------从栈内倒叙打印

	movq $0,%rcx
	
prt_loop:
	
	addq $1,	%rcx
	#格式化打印 压入时先顺序后数据，返回时先出数据后出顺序
	movq $sort, %rdi 	#第一个参数
	popq %rdx   		#第三个参数
	popq %rbx
	movq %rbx,	%rsi 	#第二个参数
	movq $0, 	%rax
	call printf

	cmpq gate(%rip), %rcx
	jb prt_loop
	


	movq $60, %rax
	movq $1,  %rdi
	syscall

	
	
# 最开始，n1 = 1; 		需要存储当前顺序和前一个顺序   
#		  n2 = n1;
#		  n3 = n2+ n1;
#		  n4 = n3+ n2;

#	movq $1, %rax;	#计算相加
#	movq $1, %rcx	#记录顺序是否超过gate

#	movq gate(%rip),%rbx  #作为守门员

	# 打印n =1
#	movq $sort,%rdi
#	movq %rax, %rsi
#	movq %rcx, %rdx
#	movq $0, %rax	
#	call printf

