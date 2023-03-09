var1=$(wildcard ./*.c)
var2=$(notdir $(var1))
var3=$(patsubst %c,%o,$(var2))

test : $(var3)
	gcc -o test $^
%.o : %.c
	gcc -c -o $@ $<
.PHONY:clean
clean:
	rm -rf *.o test
