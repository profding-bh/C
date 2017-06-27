
.PHONEY: all clean
all:fork4 fork3 2 arraytest vfork qishuiping qishuiping2 qishuiping4  time_diff time_diff2 time_diff3 time_diff4 ftime time_diff5 time_diff6 time_diff7 ctod
	
# $<：第一个依赖文件
# $@: 目标文件
# $^: 所有的依赖文件
time_diff7:time_diff7.c
	gcc $< -o $@
time_diff6:time_diff6.c
	gcc $< -o $@
time_diff5:time_diff5.c
	g++ $< -o $@
ftime:ftime.c
	gcc $< -o $@
time_diff4:time_diff4.c
	gcc $< -o $@
time_diff3:time_diff3.c
	gcc $< -o $@
time_diff2:time_diff2.c
	gcc $< -std=c99 -o $@
time_diff:time_diff.c
	gcc $< -std=c99 -o  $@
qishuiping4:qishuiping4.c
	gcc $< -o $@
qishuiping2:qishuiping2.c
	gcc $< -o $@
qishuiping:qishuiping.c
	gcc $< -o $@
arraytest:arraytest.c
3:3.c
	gcc $< -o $@
2:2.c
	gcc $< -o $@
fork4:fork4.c
	gcc $< -o $@
fork3:fork3.c
	gcc $< -o $@

vfork:vfork.c
	gcc $< -o $@
ctod:ctod.c
	gcc $< -o $@
clean:
	rm *.o # $^
