bin/main:obj/main.o obj/fun.o obj/user.o obj/ticket.o obj/admin.o
	gcc obj/main.o obj/fun.o obj/user.o obj/ticket.o obj/admin.o -o bin/main -Wall

obj/%.o:src/%.c
	gcc -c $^ -Iinclude -o $@


.PHONY:clean

clean:
	rm -rf bin/main obj/*.o
