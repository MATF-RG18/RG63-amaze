maze: AMAZE.c DEER.c DEER.h
	gcc -o maze AMAZE.c DEER.c  -Wall -lGL -lGLU -lglut -lm

.PHONY: clean

clean:
	rm -rf *.o *~ maze