.PHONY:	all clean clear install uninstall run
BIN=./bin
ROOT=./
OBJ=./object

TARGET=main.exe

all: $(TARGET)

clear:
		make clean

clean:
		rm -rf $(OBJ)/*.o
		make uninstall
		
main.o: main.cpp
		g++ -o $(OBJ)/main.o -c main.cpp

$(TARGET): main.o
		g++ -o $(TARGET) $(OBJ)/main.o
		make install
		
install:
		install $(TARGET)	$(BIN)
		
uninstall:
		rm -rf  $(BIN)/$(TARGET)
		
run:
		$(BIN)/$(TARGET)
		