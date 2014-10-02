#-- program name, sources and obj --
TARGET=Appli
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

#-- location where SFML header files and libraries are installed --
#SFMLDIR=/home/TP/modules/sujets/SFML-2.1
SFMLDIR=/home/default/Documents/SFML-compiled

#-- compiler/linker settings --
CC=g++
CCFLAGS=-W -Wall -pedantic -g -Wno-long-long
IFLAGS=-I$(SFMLDIR)/include -I./include
LDFLAGS=-L$(SFMLDIR)/lib -lsfml-graphics -lsfml-window -lsfml-system \
        -Wl,-rpath,${SFMLDIR}/lib

#-- main target to obtain --
all : $(TARGET)


#-- linker command to produce the executable file --
$(TARGET) : $(OBJ)
	@echo Linking $@ ...
	$(CC) $^ -o $@ $(LDFLAGS) 
	@echo

#-- source file header files dependencies --
src/Appli.o : include/Pong.h


#-- compiler command for every source file --
%.o : %.cpp 
	@echo Compiling $< ....
	$(CC) -c $< $(IFLAGS) -o $@ $(CCFLAGS) 
	@echo

.PHONY: clean

#-- system-specific command to remove those files --
clean : 
	@echo Cleaning...
	rm -f $(OBJ) $(TARGET) src/*~ include/*~ *~
	@echo

run :
	./$(TARGET)
