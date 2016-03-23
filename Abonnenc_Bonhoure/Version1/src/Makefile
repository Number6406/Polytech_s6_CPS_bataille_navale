CC = gcc
EXEC = ../bin/main
CFLAGS = -Wall -I ../include
SRCS = main.c grille.c navires.c jeu.c
OBJS = $(SRCS:.c=.o)



all : $(EXEC)


#.c.o : 
#	$(CC) $(CFLAGS) -c $<


$(EXEC) : $(OBJS)
	-@echo Creation de "l'executable" $@
	$(CC) $(OBJS) -o $(EXEC)

clean :
	@echo "Suppression des objets"
	-rm $(OBJS)
