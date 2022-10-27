.PHONY:	all clean install uninstall
BIN=./bin
ROOT=./
OBJ=./object

TARGET=main.exe

all: $(TARGET)

clean:
		rm -rf $(OBJ)/*.o
one.o:	one.cpp
		g++ -o $(OBJ)/one.o -c one.cpp
two.o:	two.cpp
		g++ -o $(OBJ)/two.o -c two.cpp
$(TARGET): one.o two.o
		g++ -o $(TARGET) $(OBJ)/one.o $(OBJ)/two.o
install:
		install $(TARGET)	$(BIN)
uninstall:
		rm -rf  $(BIN)/$(TARGET)