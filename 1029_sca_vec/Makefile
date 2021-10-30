CC := g++
CFLAGS := -mavx2
TARGET = sinx
OBJS = main.o sinx_ispc.o


$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

sinx_ispc.h: sinx.ispc
	ispc sinx.ispc -h $@

sinx_ispc.o: sinx.ispc
	ispc sinx.ispc -o $@

main.o: main.cpp sinx_ispc.h
	$(CC) -c main.cpp -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o
