.PHONEY: all clean
all: sample
	
# $<：第一个依赖文件
# $@: 目标文件
# $^: 所有的依赖文件


#-l:加入某个函数库
#m: 数学库 libm.so or libm.a
#-lm: 表示使用libm.so or libm.a这个函数库。
#-L/path: -L后面跟路径,可以紧贴着写，也可以空格！
#-L: Locate 表示libm.so or libm.a应该到/lib or /usr/lib这2个目录中去找，从这里可以看出-L是追加的。
#linux 默认是将函数库放到/lib 和 /usr/lib中去的。
#
#引入include目录
#-I/usr/include or -I /usr/include,可以紧贴着写，也可以空格！
#-I/path: 后面接的路径就是设置要去搜索相关的include文件的目录。同样的，
#默认值是放置在/usr/include下面

sample:sample.c
	gcc $< -lpthread -o  $@ 

clean:
	rm sample 
