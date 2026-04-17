.section .data
	age: .quad 10
	tips:	.string "\033[33m---------------------------\033[0m\n"
	adulttips:	.string "You are an adult\n"
	notadult:	.string	"You are not allowed to enter\n"

.section .text

.global main

main:

	leaq	tips(%rip),	%rdi
	movq	$0,			%rax
	call printf

	movq	age(%rip),	%rax

	cmpq	$18,	%rax

	#jump if greater or equal???
	jge	adult

	leaq	notadult(%rip),	%rdi
	movq	$0,	%rax
	call printf
	jmp	end

adult:
	leaq	adulttips(%rip),	%rdi
	movq	$0,	%rax
	call printf

end:
	movq	$60,	%rax
	movq	$0,		%rdi
	syscall


