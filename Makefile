cc = g++
exe = test
obj = test.o
$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
test.o:test.cpp
	$(cc) -c test.cpp
clean:
	rm -rf *.o test
