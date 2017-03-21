
.PHONEY: all clean
all:fork4 fork3 2 arraytest vfork qishuiping qishuiping2 qishuiping4   
	
	

qishuiping4:qishuiping4.c
	gcc $< -o $@
qishuiping2:qishuiping2.c
	gcc $< -o $@
qishuiping:qishuiping.c
	gcc $< -o $@
arraytest:arraytest.c
	gcc $< -o $@
2:2.c
	gcc $< -o $@
fork4:fork4.c
	gcc $< -o $@
fork3:fork3.c
	gcc $< -o $@

vfork:vfork.c
	gcc $< -o $@
clean:
	rm *.o 
