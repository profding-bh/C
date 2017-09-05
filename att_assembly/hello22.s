	.data
msg:
	.ascii "Hello,world\0"

	.text
	.global _main
_main:
	# 函数调用的开场白
	pushl %ebp
	movl %esp,%ebp
	andl $-16,%esp

	# 调用
	pushl $msg
	call _puts # 调用C的库函数puts

	# 设置返回值
	movl $0,%eax


	# 函数调用的结束语
	leave
	ret
