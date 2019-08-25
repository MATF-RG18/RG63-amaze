#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

void on_keyboard(unsigned char key, int x, int y);
extern void jump_timer(int value);
extern int last_deer_direction;
extern int deer_i, deer_j;
extern int deer_motion, ind_v, ind_h;
extern void on_timer(int value);
extern int deer_en_pos_v;
extern int deer_en_pos_h;
extern int foe_health;
extern int deer_health;
extern int En_ind;
extern int first_time_main_ind;
extern int first_time_ind;

#endif