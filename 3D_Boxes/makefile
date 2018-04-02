TARGET=boxes
FLAGS=-std=gnu99 -I../ZDK -L../ZDK -lzdk -lncurses -lm

all: $(TARGET)

clean:
	cd .. && if [ -f $(TARGET) ]; then rm $(TARGET); fi;

rebuild: clean all

$(TARGET): *.c *.h
	gcc *.c -o ../$(TARGET) $(FLAGS)