#=#=#=#=#=#=#=#=#
#all : compile tout argument default lorsque omis
#debug : compile le prgm avec les option de debug puis lance gdb
#clean , wclean : nettoie les fichier temporaire de compilation wclean est la version pour windows de clean
#cleanall , wcleanall : nettoie tout les fichiers créer lors de la compilation wcleanall est la version pour windows de cleanall
#debug , wdebug : compile avec l'argument de debug puis lance gdb
#=#=#=#=#=#=#=#=#

#compilateur et argument
CC=gcc
CFLAGS = -Wall -Werror -pedantic
CDEBUGF= -g

#fichier .c contenant le main et nom du programe
TARGET = main.c
MAIN = main

#liste des fichiers .c qui serons transformer en .o
OSRCS= crypto/hashComp.c crypto/hasher.c crypto/primeNumberGenerator.c crypto/rsa.c crypto/sha256.c crypto/truncated_md5.c user/userFactory.c GUI/affichageMenu.c GUI/buffer.c GUI/choice.c GUI/conversionUE.c GUI/getch.c GUI/rechercheMenu.c GUI/strentry.c user/create.c user/login.c utils/HexToDec.c utils/linkedList.c utils/random.c utils/strcut.c
OBJS = $(OSRCS:.c=.o)

#liste des fichier .c qui serons transformer en .so
LSRCS=
DLIBS = $(LSRC:.c=.so)

#liste des libs et des dossier ou trouver les lib en plus /usr/lib avec -L
LIBS = -L./
LFLAGS= -lm

#liste des dossiers ou trouver les headers en plus de /usr/include avec -I
INCLUDES= -I./

all: $(MAIN)
	@echo Programme compiler: $(MAIN)

$(MAIN): $(TARGET) $(OBJS) $(DLIBS)
	@echo compilation du main
	$(CC) $(CFLAGS) $(DLIBS) $(OBJS) -o $(MAIN) $(TARGET) $(INCLUDES) $(LIBS) $(LFLAGS) 

.c.o:
	@echo compilage de $< vers $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.c.so:
	@echo Création de la Librairie $@
	$(CC) $(CFLAGS) $(INCLUDES) -shared -o $@ $<

clean:
	@echo Nettoyage des fichier temporaire de compilation
	rm -r -f *.o *~ ./*/*.o ./*/*~

cleanall:
	@echo Nettoyage de tout les fichiers créer lors de la compilation
	rm -f -r *.o *~ *.so ./*/*.o ./*/*~ $(MAIN)

debug: dbg all
	gdb ./$(MAIN)

lib: $(DLIBS)
	@echo Lib compiler

wclean:
	@echo Nettoyage des fichier temporaire de compilation
	del /S *.o *~

wcleanall:
	@echo Nettoyage de tout les fichiers créer lors de la compilation
	del /S *.o *~ *.so $(MAIN).exe

wdebug: dbg all
	gdb $(MAIN).exe

run: $(MAIN)
	./$(MAIN)

wrun:
	$(MAIN).exe


dbg:
CFLAGS += $(CDEBUGF)
