maze: AMAZE.c Powers.c Powers.h Sword_and_shield.c Sword_and_shield.h DEER.c DEER.h Fenrys.c Fenrys.h Kaang.c Kaang.h Whirly.c Whirly.h Abraxos.c Abraxos.h Keyboard.c Keyboard.h Encounter.c Encounter.h image.c image.h
	gcc -o maze AMAZE.c Powers.c Sword_and_shield.c DEER.c Fenrys.c Kaang.c Whirly.c Abraxos.c Keyboard.c Encounter.c image.c -Wall -lGL -lGLU -lglut -lm

.PHONY: clean

clean:
	rm -rf *.o *~ maze