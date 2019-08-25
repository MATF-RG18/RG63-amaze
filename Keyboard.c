#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "Keyboard.h"

//Deers attack animation
extern int attack_rotation = 0;
extern int deer_attack_velocity = 0;
extern int deer_attack = 0;
int att_ind = 0;

void jump_timer(int value){
    deer_en_pos_h = 0;
    return;
}

void deer_attack_timer(int value){
    if(En_ind == 1){
    deer_attack_velocity += 1;
    if(att_ind == 1 && attack_rotation <= 0)
    {
    att_ind = 0;
    deer_attack = 0;
    deer_attack_velocity = 0;
    return;
    }
    else if(att_ind == 1)
    attack_rotation -=1;
    else if(attack_rotation < 26)
    attack_rotation +=1;
    else if(attack_rotation >= 25)
    att_ind = 1;
    
    glutPostRedisplay();
    glutTimerFunc(20, deer_attack_timer, 0);
}
}

void on_keyboard(unsigned char key, int x, int y)
{
    //file pointer
    FILE *fp;
    fp = fopen("MAZE.txt", "r");
    int M[51][51];
    int i=0, j=0;

    //i need the matrix here too
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
       if (!fscanf(fp, " %d", &M[i][j])) 
           break;
      }
    }
    
    fclose(fp);
    switch (key) {
    case 27:
        //we exit the game
        exit(0);
        break;

//the movement section WORKS it WORKS I don't know how, I don't know WHY but it WORKS, please don't look at it
    case 'w':
    case 'W':
        {
            //walk only if not in an encounter
            if(En_ind == 0){
            //last_deer_direction tells us with way the deer is facing
            //according to that fact we know where to move within the matrix
            //I can't explain it with words better, but I can draw a neat picture to elaborate :D(if anyone cares)
            //here the deer is facing forward if another w is pressed he should go forward
            if(last_deer_direction == 0){
            //the deer moves forward if the path is clear
                if(M[deer_i+1][deer_j] == 0)
                    {
                    deer_motion = 1;
                    //this helps the camera shift with the deer
                    ind_v = 1;
                    ind_h = 0;                    
                    glutTimerFunc(20, on_timer, 0);
                    }
            }
            //here the deer is facing backwards if w is pressed
            // he should continue going backwards because thats his forward now
            //and so on for every key pressed [a, d...]
            else if(last_deer_direction == 1){
                if(M[deer_i-1][deer_j] == 0)
                    {
                    deer_motion = 1;
                    ind_v = -1;
                    ind_h = 0;                    
                    glutTimerFunc(20, on_timer, 1);
                    }
            }
            else if(last_deer_direction == 2){
                if(M[deer_i][deer_j+1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = 1;
                    glutTimerFunc(20, on_timer, 2);
                    }
            }
            else if(last_deer_direction == 3){
                if(M[deer_i][deer_j-1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = -1;
                    glutTimerFunc(20, on_timer, 3);
                    }
            }

            }
            break;
        }
    case 's':
    case 'S':
        {
            if(En_ind == 0){
            if(last_deer_direction == 0){
            if(M[deer_i-1][deer_j] == 0){
            deer_motion = 1;
            ind_v = -1;
            ind_h = 0;
            glutTimerFunc(20, on_timer, 1);
            }
            }
            else if(last_deer_direction == 1){
            if(M[deer_i+1][deer_j] == 0){
            deer_motion = 1;
            ind_v = 1;
            ind_h = 0;
            glutTimerFunc(20, on_timer, 0);
            }
            }
            else if(last_deer_direction == 2){
                if(M[deer_i][deer_j-1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = -1;
                    glutTimerFunc(20, on_timer, 3);
                    }
            }
            else if(last_deer_direction == 3){
                if(M[deer_i][deer_j+1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = 1;
                    glutTimerFunc(20, on_timer, 2);
                    }
            }
        }
            
            break;
        }
    case 'a':
    case 'A':
        {
            if(En_ind == 0){
            if(last_deer_direction == 0){
            if(M[deer_i][deer_j+1] == 0){
            deer_motion = 1;
            ind_h = 1;
            ind_v = 0;
            glutTimerFunc(20, on_timer, 2);
            }
            }
            else if(last_deer_direction == 1){
            if(M[deer_i][deer_j-1] == 0){
            deer_motion = 1;
            ind_h = -1;
            ind_v = 0;
            glutTimerFunc(20, on_timer, 3);
            }
            }
            else if(last_deer_direction == 2){
            if(M[deer_i-1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = -1;
            glutTimerFunc(20, on_timer, 1);
            }
            }
            else if(last_deer_direction == 3){
            if(M[deer_i+1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = 1;
            glutTimerFunc(20, on_timer, 0);
            }
            }
        }
            
            break;
        }
    case 'd':
    case 'D':
        {
            if(En_ind == 0){
            if(last_deer_direction == 0){
            if(M[deer_i][deer_j-1] == 0){
            deer_motion = 1;
            ind_h = -1;
            ind_v = 0;
            
            glutTimerFunc(20, on_timer, 3);
            }
            }
            else if(last_deer_direction == 1){
            if(M[deer_i][deer_j+1] == 0){
            deer_motion = 1;
            ind_h = 1;
            ind_v = 0;
            
            glutTimerFunc(20, on_timer, 2);
            }
            }
            else if(last_deer_direction == 2){
            if(M[deer_i+1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = 1;
            
            glutTimerFunc(20, on_timer, 0);
            }
            }
            else if(last_deer_direction == 3){
            if(M[deer_i-1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = -1;
            
            glutTimerFunc(20, on_timer, 1);
            }
            }
        }
            
            break;
        }
        //deer movement while he is in an Encounter
        //3 locations to move so you can dodge attacks
        case 'L':
        case 'l':
        {
            if(deer_attack == 0){
            deer_en_pos_v = -1;
            glutPostRedisplay();
            }
            break;
        }
        case 'J':
        case 'j':
        {
            if(deer_attack == 0){
            deer_en_pos_v = 1;
            glutPostRedisplay();
            }
            break;
        }

        case 'K':
        case 'k':
        {
            if(deer_attack == 0){
            deer_en_pos_v = 0;
            glutPostRedisplay();
            }
            break;
        }

        case 'I':
        case 'i':
        {
            //I had a plan for jumping but i ran out of time - its pointless now :(
            if(deer_attack == 0){
            deer_en_pos_h = 1;
            glutTimerFunc(500, jump_timer, 0);
            glutPostRedisplay();
            }
            break;
        }
        case 'u':
        case 'U':
        {
            //when you press U the deer attacks
            //if his foe's health is zero the encounter is over everything gets reset
            if(deer_attack == 0){
            deer_attack = 1;
            if(deer_en_pos_v == 0){
                foe_health -= 1;
                if(foe_health == 0 && En_ind == 1){
                    En_ind = 0;
                    foe_health = 5;
                    deer_health = 5;
                    deer_attack = 0;
                    first_time_main_ind = 1;
                    first_time_ind = 0;
                    glutPostRedisplay();
                    break;
                }
            }
            glutTimerFunc(20, deer_attack_timer, 0);
            }
            break;
        }
        //this is where i planned on putting my shield button IF I HAD ONE
    }
}
