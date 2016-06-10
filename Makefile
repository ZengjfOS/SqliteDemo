user: user.o main.o
	gcc user.o main.o -lsqlite3 -o user

user.o: src/user.h
	gcc -c src/user.c

main.o: src/user.h
	gcc -c src/main.c

clean:
	rm -rf *.o user
