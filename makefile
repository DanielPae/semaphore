all: semaphore.c
	gcc -o semaphore semaphore.c
run: all
	./semaphore -c 2
