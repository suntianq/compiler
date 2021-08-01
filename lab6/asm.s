在第8行重定义了变量
第9行：+ 左运算数d变量类型错误
Uninitialized variable at lineno: 10



# define strings here
	.section   .rodata
_S0:
	.string "%d"
_S1:
	.string "%d"
_S2:
	.string "test:%d\n"

# define variables and temp variables here
	.bss
	.align	4
_a:
	.zero	4
	.align	4
_b:
	.zero	4
	.align	4
_c:
	.zero	4
	.align	4
_d:
	.zero	4
	.align	4
_e:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4
t1:
	.zero	4
	.align	4
t2:
	.zero	4
	.align	4
t3:
	.zero	4
.section .text
	.globl main
	.type main, @function
main:
	pushl $_a
	pushl $_S0
	call scanf
	addl $8,%esp
	pushl $_b
	pushl $_S1
	call scanf
	addl $8,%esp
	movl _d, %eax
	addl _a, %eax
	movl %eax, t0
	movl t0,%eax
	movl %eax,_c
	movl _a, %eax
	addl _b, %eax
	movl %eax, t1
	movl t1,%eax
	movl %eax,_e
	movl _a, %edx
	movl %edx,%eax
	sarl $31, %edx
	movl _b, %ebx
	idivl %ebx
	movl %edx, t2
	movl t2,%eax
	movl %eax,_c
	pushl _c
	pushl $_S2
	call printf
	addl $8,%esp

	movl $0, %eax
	ret
