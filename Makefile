#-- nom du programme, sources et obj
TARGET=Corsaire
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

#-- répertoire d'instalation de SFML
SFMLDIR=/usr/lib

#-- options du compilateur et du linker
CC=g++
CCFLAGS=-W -Wall -pedantic -g -Wno-long-long
IFLAGS=-I$(SFMLDIR)/include -I ./include
LDFLAGS=-L$(SFMLDIR)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#-- cible principale
all : $(TARGET)

#-- commande du linker pour produire un executable
$(TARGET) : $(OBJ)
	@echo Linking $@
	$(CC) $^ -o $@ $(LDFLAGS)
	@echo

#-- dépendances des fichiers sources
src/Game.o : include/Game.h
src/SplashScreen.o : include/SplashScreen.h

#-- commande du compilateur pour chaque fichier source
%.o : %.cpp
	@echo Compiling $< ....
	$(CC) -c $< $(IFLAGS) -o $@ $(CCFLAGS)
	@echo

.PHONY: clean

clean :
		@echo cleaning...
		rm -f $(OBJ) $(TARGET) src/*~ include/*~ *~
		@echo

run :
	./$(TARGET)
