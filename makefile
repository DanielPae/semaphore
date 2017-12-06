all: semaphore.c
	gcc -o semaphore semaphore.c
run: all
	./semaphore -c 2
	./semaphore -c 5
	./semaphore -v
	./semaphore -r
