CC := g++
TARGET = minmax
OBJS = main.o minmax_ispc.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

minmax_ispc.h: minmax_ispc.ispc
	ispc minmax_ispc.ispc -h $@

minmax_ispc.o: minmax_ispc.ispc
	ispc minmax_ispc.ispc -o $@

main.o: main.cpp minmax_ispc.h
	$(CC) -c main.cpp -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.h
