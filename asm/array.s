.section .data
	list: .quad 6666,4,99991,99991,9,30,31,2,23,-3,-13,54,21,11,412,2121
		  .set COUNT,(.-list)/8

	fmt:	.string "The biggest : sort:%ld number is %ld\n"
.section .text
.global main
main:
	leaq list(%rip),	%rbx	# 获得数组地址
	movq $0,			%r12		#把计数器归零
	movq $0,			%r14

	movq  (%rbx,%r12,8),%r13	# 把数组的数字赋值
	# 先取第一个元素给r13
loops:
	incq %r12
	cmpq $COUNT,	%r12	#比较下标
	jae	 prt
	#如果下标到达临界直接去最后打印

	cmpq (%rbx,%r12,8),%r13
	#如果r13大于数组下一个，那么直接跳回循环，如果不是，更换
	jge loops
	movq (%rbx,%r12,8),%r13
	movq %r12,%r14
	jmp loops
prt:
	movq (%rbx),%rax #把第一个元素取出来
	movq %r13,(%rbx) #把最大数写入数组开头
	movq %rax,(%rbx,%r14,8) #把暂存的原第一元素，填入最大数原来的位置
#我交换了最大数和第一个数，但我懒的打印出来了

	movq %r13,	%rdx
	movq %r14,	%rsi
	leaq fmt(%rip),%rdi

	movq $0,	%rax
	
	call printf
end:
	movq $0,%rdi
	movq $60,%rax
	syscall

