#fish.o: fish.c
#       gcc -c fish.c
fish: fish.o command.o binarycom.o input.o
        gcc -o fish fish.o command.o binarycom.o input.o
fish.o: fish.c
        gcc -c fish.c
command.o: command.c
        gcc -c command.c
binarycom.o: binarycom.c
        gcc -c binarycom.c
input.o : input.c
        gcc -c input.c
