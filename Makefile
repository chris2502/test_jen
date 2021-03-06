#Source
SRC= ./
#chemin des dossiers et bibliothèques
inc= -I ./
#nom du compilateur
CC= g++
#option de compilation
CXXFLAGS= -Wall -ansi -std=c++17
#liaison avec la biblithèque cppunit
LINKFLAGS= -lcppunit
#nom de l'executable
EXEC= testDuree
all: $(EXEC) clean
#regle de compilation du projet
#les dependances de l'executable. on ajoutera plus les autres .o
$(EXEC) : duree.o testduree.o main.o
	@echo "création  de l'éxécutable $@"
	$(CC) $^ $(CFLAGS) $(LINKFLAGS) -o testDuree
#regle de compilation générique des objets
%.o : $(SRC)%.cc
	@echo "création de l'objet $@"
	$(CC) $(CFLAGS) $(LDFLAGS) $(inc) $<
#suppression des fichiers objets
clean : 
	@rm -rf *.o
#make clean
