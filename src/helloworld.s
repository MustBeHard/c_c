#helloworld.s
#practice printing "hello world " in asembley

.section .data  #数据段？
	#定义字符串
	msg:
		.ascii "Hello World!\n"

.section .text
	.global _start	# main() starts from here

_start:

	#system 自带的 write方法 系统调用号：1
	movq $1, %rax	#立即数，把write方法写入ax寄存器
	movq $1, %rdi	#di 数据段指针？
# 64bit
# rax rbx rcx rdx ...............

# 32bit register
# eax ebx ecx edx edi esi ebp esp
# 16bit
# ax bx cx dx di si bp sp
# 8bit
# ah al ; bh bl;ch cl;dh dl;
# cs:code section ;ds:data section; ss:stack section ; es - fs -gs
#control register: cr0 cr2 cr3 ? 

# mov source dest

# immediately Operator  movl $0x04,%ebx
# b-byte w-word l-long q-quadword
# symbol constant 符号 常数
	value: .long 0x12123fdf
	movl value,%ebx

#length of operator
movl %eax, %ebx
movq %rax, %rbx
movw %ax,	%bx
movb %al,	%bl

#call and jump | ret-return 


# MEMORY REFERENCE
# 间接内存引用 section: dispacement (base,index,scale)
# 

# 寄存器手册
# ax 函数返回值存放;系统调用前需把调用号存入

# bx 内存寻址base基础地址;函数结束前必须复原

# cx count计数，循环指令loop自动递减

# dx data辅助运算，系统调用时存第三个参数

#传参规范：
# di 目标destination
# si 源 source
# dx data寄存器
# cx counter计数

#sp 栈顶指针 bp栈基址指针 base
#ip instruction, 不可直接修改，永远指向下一条指令

#状态，flags
# zf-zero flag sf-sign flag cd/of进位或溢出outflow


# 寄存器练习 （GEMINI）

movq $100,%rax		#立即数必须加$
movq $30,%rbx

#减法，并赋值给cx
movq %rax,%rcx   #先把30从rbx转移到rcx
subq %rbx,%rcx   #sub src,dst ：：rax-rcx --->new rax

#交换
movq %rbx,%rdx
movq %rax,%rbx
movq %rdx,%rax

#---------------计数器模拟乘法

movq $5,%rcx
movq $0,%rdx

my_loop:
addq $10,%rax
subq $1, %rcx

jne my_loop

#第三题-----------

.section .data
	msg:
		.ascii "this is a sentence\n"

.section .text

		.global _start

_start:
	movq $1,%rax
	movq $1,%rdi

	movq $msg,%rsi
	movq $10 ,%rdx

# %RSI 内存寻址

	%rsi 内存地址 (%rsi)内存内的数据 &rsi *rsi
	.section .data
		my_value: 
			.quad 500 
		msg:
			.ascii "hello asm!\n"
		movq $msg, %rsi
		movq (%rsi),%rax

		movq 6(%rsi),%rax  ## &rsi + 6
	
# %rdi dest目的地

	.section .data
		src:	.quad 123
		dst:	.quad 0

#######........
		movq $src, %rsi
		movq $dst, %rdi

		movq (%rsi),%rax
		movq %rax, (%rdi)


## 最难的栈地址 rbp - base pointer

.section .data
	a:
		.long 666
	b:
		.long 0

.section .text
.global _start

_start:
	movq $a, -8(%rbp)
	popq %rax
	
	pushq $0
	pushq %rax

#----------------------
	pushq %rbp  #把现在的栈基址压入栈，同时rsp移动8字节（64bits）

	movq %rsp , %rbp #把现在的栈顶，写入新的栈底，
	subq $16, %rsp 	 


#局部变量的乾坤大挪移
.section .data
	a: .quad 100
	b: .quad 200

_start:
	#依次手动压入栈
	movq $a,%rsi
	movq (%rsi),%rax

	movq $b,%rsi
	movq (%rsi),%rdx

	movq %rsp,%rbp	#确定栈底为止，并且等于栈顶
	
	subq $8,%rsp
	movq %rax,-8(%rbp)

	subq $8,%rsp
	movq %rdx,-16(%rbp)

	
#伪代码解释一下

		movq %rsp,%rbp  确认rep==rbp
		subq $16,%rsp  这次我主动一次申请两个8字节
		movq $11,-8(%rbp)
		movq $33,-16(%rbp)
			我可以说这是一次完美的入栈吗


#从1加到100的练习

	_start:
		movq $0,%rax  累加结果
		movq $0,%rbx	计数器

	addloop:

		addq $1,%rbx
		cmpq $100,%rbx
	 	jne addloop
	
	movq %rbx , %rax


		
		



		 



































	
























