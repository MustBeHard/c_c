.section .bss

	.lcomm buf,1

.section .text
.global main
main:
	# 系统读入
	movq $0, %rax			#sys_read
	movq $0, %rdi			#arg1, keeyboard
	leaq buf(%rip),%rsi		#arg2, &buff	
	movq $1,	   %rdx		#arg3, len 1
	syscall

	#系统写入屏幕
	movq $1, %rax
	movq $1, %rdi
	movq $1,%rdx
	syscall

	#系统跳出
	movq $60,%rax
	movq $0, %rdi
	syscall
