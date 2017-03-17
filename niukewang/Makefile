
.PHONEY: all clean
all:fork4 fork3 2 3

3:3.c
	gcc $< -o $@
2:2.c
	gcc $< -o $@
fork4:fork4.c
	gcc $< -o $@
fork3:fork3.c
	gcc $< -o $@

clean:
	rm *.o 
