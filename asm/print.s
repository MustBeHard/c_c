.section  .data

	msg: .string "The num is %d, thanks to asm\n"
	val: .quad 666
.text

.global main

main:

	#printf格式依次为 format, v1....

	movq $msg,%rdi
	movq val(%rip),%rsi

	movq $0 , %rax

	call printf

	movq $0,%rdi
	movq $60,%rax
	syscall
