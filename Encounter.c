//this file is too big but I have to many files already
// and it has to many variables (it would be hard to link everything)
//and I'm out of time.. so...
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<math.h>
#include "DEER.h"
#include "Fenrys.h"
#include "Kaang.h"
#include "Whirly.h"
#include "Abraxos.h"
#include "Keyboard.h"
#include "Encounter.h"
#include "image.h"
#include "Sword_and_shield.h"
#include "Powers.h"

#define FILENAME0 "brick4_b.bmp"

static GLuint names[2];

//animation timers
void wolf_attack_timer(int value);
void ice_blast_timer(int value);
void lightning_timer(int value);

//attack animation parameters
extern int first_time_ind = 0;
int wolf_attack = 0;
int ice_blast_1 = 0, ice_blast_2 = 0, ice_blast_3 = 0;
extern int ice_blast_move = 0;

//health
extern int deer_health = 5;
extern int foe_health = 5;

//so i know in timer functions witch foe im fighting
int bad_guy_here = 0;

//lightning animation
int lightning_strike_1 = 0;
int lightning_strike_2 = 0;
int lightning_strike_3 = 0;
int get_ready = 0;
int go = 0;
int lgh_hit = 0;

void Encounter(int bad_guy){
	bad_guy_here = bad_guy;

	//this whole section brings light to our MAZE
    GLfloat light_position[] = {200.0f, 300.0f, 100.0f, 0.0f};

    GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};

    GLfloat light_diffuse[] = {1, 1, 1, 1};

    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1};

    
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	//cleaning out the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//setting the view
    glViewport(0, 0,window_width, window_height);

    //Setting the angle, width-height ratio, near and far clipping plain
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 2, 1500);

    //new camera position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(50, 49, 5,
        49.99, 40, 0,
        0, 0, 1);

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    Image * image;

    image = image_init(0, 0);

    image_read(image, FILENAME0);

    glGenTextures(2, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);


    //bad_guy == 1 -> we encountered the silver wolf Fenrys
    if(bad_guy == 1)
    {
        //I want the timer to be called just once
    	if(first_time_ind == 0){
        //seed for a random number generator
    	srand(time(NULL));
        //attack animation - not just for the wolf but Im to lazy to change it
    	glutTimerFunc(20, wolf_attack_timer, 0);
    	first_time_ind = 1;
    	}

    	//water walls
    	GLfloat diffuse_coeffs_B[] = { 0, 0, 0.7, 1};
    	GLfloat ambient_coeffs_B[] = { 0, 0, 0.7, 1};
    	GLfloat specular_coeffs[] = { 0.3, 0.3, 0.3, 1};
    	GLfloat shininess = 5;

    	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_B);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_B);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    	glPushMatrix();

    	glTranslatef(56, 50, 1);
    	glScalef(1, 100, 12);

    	glutSolidCube(1);

    	glPopMatrix();


    	glPushMatrix();

    	glTranslatef(44, 50, 1);
    	glScalef(1, 100, 12);

    	glutSolidCube(1);

    	glPopMatrix();

    	glPushMatrix();

    	glTranslatef(50, 0, 1);
    	glScalef(100, 1, 12);

    	glutSolidCube(1);

    	glPopMatrix();

        //wolf is here
    	glPushMatrix();

    	glTranslatef(50, 20, 1);
    	glScalef(0.6, 0.6, 0.6);

    	draw_wolf();

    	glPopMatrix();

    	if(wolf_attack == 1){

                //the wolfs attack is drawn here and animated with a timer function
    		    if(ice_blast_1 == 1){
    		    //ice blast #1
    		    glPushMatrix();
    			glTranslatef(50, 23, 2);
    			glScalef(0.3, 0.3, 0.3);
    			draw_ice_blast();

    		    glPopMatrix();

    			}

    		    if(ice_blast_2 == 1){
    		    //ice blast #2
    		    glPushMatrix();
    			glTranslatef(52, 23, 2);
    			glScalef(0.3, 0.3, 0.3);
    		    draw_ice_blast();
    		    
    		    glPopMatrix();
    		    }

    		    if(ice_blast_3 == 1)
    		    {
    		    //ice blast #3
    		    glPushMatrix();
    			glTranslatef(48, 23, 2);
    			glScalef(0.3, 0.3, 0.3);
       			draw_ice_blast();

    		    glPopMatrix();
    		    }

    	}

    }

    //bad_guy == 2 -> we encountered Kaang Kong
    if(bad_guy == 2)
    {
    	if(first_time_ind == 0){
    	srand(time(NULL));
    	glutTimerFunc(20, wolf_attack_timer, 0);
    	first_time_ind = 1;
    	}

    	//Earth walls
    	GLfloat diffuse_coeffs_G[] = { 0, 0.7, 0, 1};
    	GLfloat ambient_coeffs_G[] = { 0, 0.7, 0, 1};
    	GLfloat specular_coeffs[] = { 0.3, 0.3, 0.3, 1};
    	GLfloat shininess = 5;

    	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_G);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_G);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    	glPushMatrix();

    	glTranslatef(56, 50, 1);
    	glScalef(1, 100, 12);

    	glutSolidCube(1);

    	glPopMatrix();


    	glPushMatrix();

    	glTranslatef(44, 50, 1);
    	glScalef(1, 100, 12);

    	glutSolidCube(1);

    	glPopMatrix();

    	glPushMatrix();

    	glTranslatef(50, 0, 1);
    	glScalef(100, 1, 12);

    	glutSolidCube(1);

    	glPopMatrix();

    	//Kaang kong
    	glPushMatrix();

    	glTranslatef(50, 20, 1);
    	glScalef(0.6, 0.6, 0.6);

    	draw_Kaang();

    	glPopMatrix();

        //'Wolf'_attack
    	if(wolf_attack == 1){

                //'ice'_blast - kaang weilds a staff
    		    if(ice_blast_1 == 1){
    		    //staff blast #1
    		    glPushMatrix();
    			glTranslatef(50, 23, 2);
    			glRotatef(-90, 1, 0, 0);
    			draw_kaangs_staff();

    		    glPopMatrix();

    			}

    		    if(ice_blast_2 == 1){
    		    //staff blast #2
    		    glPushMatrix();
    			glTranslatef(52, 23, 2);
    			glRotatef(-90, 1, 0, 0);
				draw_kaangs_staff();    		    
    		    glPopMatrix();
    		    }

    		    if(ice_blast_3 == 1)
    		    {
    		    //staff blast #3
    		    glPushMatrix();
    			glTranslatef(48, 23, 2);
    			glRotatef(-90, 1, 0, 0);
       			draw_kaangs_staff();

    		    glPopMatrix();
    		    }

    	}
    }
    //bad_guy == 3 -> we encountered Whirly
    if(bad_guy == 3)
    {
        if(first_time_ind == 0){
        srand(time(NULL));
        glutTimerFunc(20, wolf_attack_timer, 0);
        first_time_ind = 1;
        }

        //Air walls
        GLfloat diffuse_coeffs_W[] = { 0.7, 0.7, 0.7, 1}; 
        GLfloat ambient_coeffs_W[] = { 0.7, 0.7, 0.7, 1}; 
        GLfloat specular_coeffs[] = { 0.3, 0.3, 0.3, 1};
        GLfloat shininess = 5;

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_W);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_W);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);

        glPushMatrix();

        glTranslatef(56, 50, 1);
        glScalef(1, 100, 12);

        glutSolidCube(1);

        glPopMatrix();


        glPushMatrix();

        glTranslatef(44, 50, 1);
        glScalef(1, 100, 12);

        glutSolidCube(1);

        glPopMatrix();

        glPushMatrix();

        glTranslatef(50, 0, 1);
        glScalef(100, 1, 12);

        glutSolidCube(1);

        glPopMatrix();

        //Whirly
        glPushMatrix();

        glTranslatef(50, 20, 1);
        glScalef(0.35, 0.35, 0.35);

        draw_Whirly();

        glPopMatrix();

        if(wolf_attack == 1){
            //gold
            float mat_ambient_Gold[]={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
            float mat_diffuse_Gold[]={0.75164f, 0.60648f, 0.22648f, 1.0f };
            float mat_specular_Gold[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
            float shine_Gold =51.2f ;
                
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
            glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

            //lightning attack is drawn here
            if(lightning_strike_1 == 1)
            {
            if(get_ready == 1){

                //this little sphere tells us where the lightning is gonna strike
                glPushMatrix();
                glTranslatef(50, 22, 3);

                glutSolidSphere(0.5, 30, 30);
                glPopMatrix();
            }
            if(go == 1){
                glPushMatrix();
                glTranslatef(50, 23, 3);
                draw_lightning_bolt();

                glPopMatrix();
            }
            }
            if(lightning_strike_2 == 1)
            {
            if(get_ready == 1){


                glPushMatrix();
                glTranslatef(48, 22, 3);

                glutSolidSphere(0.5, 30, 30);
                glPopMatrix();
            }
            if(go == 1){
                glPushMatrix();
                glTranslatef(48, 23, 3);
                draw_lightning_bolt();

                glPopMatrix();
            }
            }
            if(lightning_strike_3 == 1)
            {
            if(get_ready == 1){


                glPushMatrix();
                glTranslatef(52, 22, 3);

                glutSolidSphere(0.5, 30, 30);
                glPopMatrix();
            }
            if(go == 1){
                glPushMatrix();
                glTranslatef(52, 23, 3);
                draw_lightning_bolt();

                glPopMatrix();
            }
            }


            //Silver
            float mat_ambient_Silver[] ={ 0.19225f, 0.19225f, 0.19225f, 1.0f };
            float mat_diffuse_Silver[] ={ 0.50754f, 0.50754f, 0.50754f, 1.0f};
            float mat_specular_Silver[] ={0.508273f, 0.508273f, 0.508273f, 1.0f };
            float shine_Silver = 51.2f;

            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Silver);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Silver);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Silver);
            glMaterialf(GL_FRONT, GL_SHININESS, shine_Silver);

            GLUquadricObj *quadObj = gluNewQuadric();

            //the wind attack gets drawn here and animated
            if(ice_blast_1 == 1){
                //wind blast #1
                glPushMatrix();
                glTranslatef(50 + sin(0.1*ice_blast_move), 23 + 0.4*ice_blast_move, 2);
                glPushMatrix();
                glRotatef(ice_blast_move, 0, 0, 1);
                gluCylinder(quadObj, 0, 3, 10, 30, 30);
                glPopMatrix(); 

                glPopMatrix();

            }

            if(ice_blast_2 == 1){
                //wind blast #2
                glPushMatrix();
                glTranslatef(52 + sin(0.1*ice_blast_move), 23 + 0.4*ice_blast_move, 2);
                glPushMatrix();
                glRotatef(ice_blast_move, 0, 0, 1);
                gluCylinder(quadObj, 0, 3, 10, 30, 30);
                glPopMatrix();               
                glPopMatrix();
            }

            if(ice_blast_3 == 1)
            {
                //ice blast #3
                glPushMatrix();
                glTranslatef(48 + sin(0.1*ice_blast_move), 23 + 0.4*ice_blast_move, 2);
                glPushMatrix();
                glRotatef(ice_blast_move, 0, 0, 1);
                gluCylinder(quadObj, 0, 3, 10, 30, 30);
                glPopMatrix(); 

                glPopMatrix();
            }

        }
    }
    //bad_guy == 4 -> we encountered Abraxos
    if(bad_guy == 4)
    {
        if(first_time_ind == 0){
        srand(time(NULL));
        glutTimerFunc(20, wolf_attack_timer, 0);
        first_time_ind = 1;
        }

        //Fire walls
        GLfloat diffuse_coeffs_R[] = { 0.7, 0, 0, 1}; 
        GLfloat ambient_coeffs_R[] = { 0.7, 0, 0, 1}; 
        GLfloat specular_coeffs[] = { 0.3, 0.3, 0.3, 1};
        GLfloat shininess = 5;

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_R);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_R);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);

        glPushMatrix();

        glTranslatef(56, 50, 1);
        glScalef(1, 100, 12);

        glutSolidCube(1);

        glPopMatrix();


        glPushMatrix();

        glTranslatef(44, 50, 1);
        glScalef(1, 100, 12);

        glutSolidCube(1);

        glPopMatrix();

        glPushMatrix();

        glTranslatef(50, 0, 1);
        glScalef(100, 1, 12);

        glutSolidCube(1);

        glPopMatrix();

        //Abraxos
        glPushMatrix();

        glTranslatef(50, 20, 1);
        glScalef(0.38, 0.38, 0.38);

        draw_Abraxos();

        glPopMatrix();

        if(wolf_attack == 1){

            //gold
            float mat_ambient_Gold[]={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
            float mat_diffuse_Gold[]={0.75164f, 0.60648f, 0.22648f, 1.0f };
            float mat_specular_Gold[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
            float shine_Gold =51.2f ;
                
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
            glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

            if(lightning_strike_1 == 1)
            {
            if(get_ready == 1){


                glPushMatrix();
                glTranslatef(50, 22, 3);

                glutSolidSphere(0.5, 30, 30);
                glPopMatrix();
            }
            if(go == 1){
                glPushMatrix();
                glTranslatef(50, 23, 3);
                draw_lightning_bolt();

                glPopMatrix();
            }
            }
            if(lightning_strike_2 == 1)
            {
            if(get_ready == 1){


                glPushMatrix();
                glTranslatef(48, 22, 3);

                glutSolidSphere(0.5, 30, 30);
                glPopMatrix();
            }
            if(go == 1){
                glPushMatrix();
                glTranslatef(48, 23, 3);
                draw_lightning_bolt();

                glPopMatrix();
            }
            }
            if(lightning_strike_3 == 1)
            {
            if(get_ready == 1){


                glPushMatrix();
                glTranslatef(52, 22, 3);

                glutSolidSphere(0.5, 30, 30);
                glPopMatrix();
            }
            if(go == 1){
                glPushMatrix();
                glTranslatef(52, 23, 3);
                draw_lightning_bolt();

                glPopMatrix();
            }
            }

            if(ice_blast_1 == 1){
                //fire blast #1
                glPushMatrix();
                glTranslatef(50, 23 + 0.4*ice_blast_move, 2);
                glScalef(0.5, 0.5, 0.5);
                draw_fire_ball();

                glPopMatrix();

            }

            if(ice_blast_2 == 1){
                //fire blast #2
                glPushMatrix();
                glTranslatef(52, 23 + 0.4*ice_blast_move, 2);
                glScalef(0.5, 0.5, 0.5);
                draw_fire_ball();

                glPopMatrix();
            }

            if(ice_blast_3 == 1)
            {
                //fire blast #3
                glPushMatrix();
                glTranslatef(48, 23 + 0.4*ice_blast_move, 2);
                glScalef(0.5, 0.5, 0.5);
                draw_fire_ball();

                glPopMatrix();
            }

        }
    }

    if(deer_attack == 1){
    glPushMatrix();
    
    glTranslatef(50+2*deer_en_pos_v, 43-deer_attack_velocity, 1 + deer_en_pos_h);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(45, 1, 0, 0);

    //deer_attack - its a skewed triangle (yes thats the best idea I had)
	glBegin(GL_TRIANGLES);

		glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 2);
        glVertex3f(6, 0, -1);
        glVertex3f(0, 0, 0);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 2);
        glVertex3f(-6, 0, -1);
        glVertex3f(0, 0, 0);

    glEnd();
    glPopMatrix();
    }

    //our protagonist
    glPushMatrix();

    glTranslatef(50+2*deer_en_pos_v, 43, 1 + deer_en_pos_h);
    glRotatef(180, 0, 0, 1);
    glScalef(0.4, 0.4, 0.4);
    DEER();

    glPopMatrix();

    //floor
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(0, 0, 0);

        glTexCoord2f(120, 0);
        glVertex3f(100, 0, 0);

        glTexCoord2f(120, 60);
        glVertex3f(100, 100, 0);

        glTexCoord2f(0, 60);
        glVertex3f(0, 100, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    if(En_ind == 0){
    	return;
    }


}

void ice_blast_timer(int value){
    //well here we animate the attacks 
    //when they reach a certain point we check if the deer is there
    //if he is we deduct a health point
	if(En_ind == 1 && (bad_guy_here == 1 || bad_guy_here == 3 || bad_guy_here == 4)){
    Whirly_move += 1;
    if(0.3*ice_blast_move+8+23 <= 50){
    ice_blast_move +=1;

    glutPostRedisplay();
    glutTimerFunc(20, ice_blast_timer, 0);

    }
    else if(0.3*ice_blast_move+8+23 > 50){
    	ice_blast_move = 0;
    	if((ice_blast_1 == 1 && deer_en_pos_v == 0) || (ice_blast_2 == 1 && deer_en_pos_v == 1)
    	|| (ice_blast_3 == 1 && deer_en_pos_v == -1)){
    		deer_health -= 1;
    		if(deer_health == 0){
    			printf("game over!\n");
    			exit(1);
    		}
    	}
    	return;
    }
}
//the kaang animation needed to be pushed back a little beacuse his staff was large to begin with
if(En_ind == 1 && bad_guy_here == 2){
    if(0.3*ice_blast_move+16+23 <= 50){
    ice_blast_move +=1;

    glutPostRedisplay();
    glutTimerFunc(20, ice_blast_timer, 0);

    }
    else if(0.3*ice_blast_move+16+23 > 50){
    	ice_blast_move = 0;
    	if((ice_blast_1 == 1 && deer_en_pos_v == 0) || (ice_blast_2 == 1 && deer_en_pos_v == 1)
    	|| (ice_blast_3 == 1 && deer_en_pos_v == -1)){
    		deer_health -= 1;
    		if(deer_health == 0){
    			printf("game over!\n");
    			exit(1);
    		}
    	}
    	return;
    }
}
}
void lightning_timer(int value){
//first we give a warning so the player can get ready
if(En_ind == 1 && value == 1 && get_ready == 0){
    get_ready = 1;
    glutPostRedisplay();
    glutTimerFunc(200, lightning_timer, 1);
    return;
}
//here the lightning strikes 
if(En_ind == 1 && value == 1 && get_ready == 1){
    go = 1;
    get_ready = 0;
    glutPostRedisplay();
    if(deer_en_pos_v == 0 && lgh_hit == 0 && lightning_strike_1 == 1){
        lgh_hit = 1;
        deer_health -= 1;
    }
    if(deer_en_pos_v == -1 && lgh_hit == 0 && lightning_strike_2 == 1){
        lgh_hit = 1;
        deer_health -= 1;
    }
    if(deer_en_pos_v == -1 && lgh_hit == 0 && lightning_strike_3 == 1){
        lgh_hit = 1;
        deer_health -= 1;
    }
    if(deer_health == 0){
        exit(1);
        }

    glutTimerFunc(100, lightning_timer, 2);
    return;
}
//animation over reset everything
if(En_ind == 1 && value == 2){
    go = 0;
    if(lightning_strike_1 == 1)
    lightning_strike_1 = 0;
    if(lightning_strike_2 == 1)
    lightning_strike_2 = 0;
    if(lightning_strike_3 == 1)
    lightning_strike_3 = 0;
    lgh_hit = 0;
    glutPostRedisplay();
    return;
}

}
void wolf_attack_timer(int value){
	if(value == 0 && En_ind == 1){
        //random number that helps us randomize the attacks
    	int n = rand()%100+1;

        //here we have 3 attack options decided by RNG
    	if(n < 33){
            //clall to lightning
            if(n%3 == 0 && lightning_strike_1 == 0 && (bad_guy_here == 3 || bad_guy_here == 4)){
                lightning_strike_1 = 1;
                glutTimerFunc(20, lightning_timer, 1);
            }

    		wolf_attack = 1;
    		ice_blast_2 = 1;
    		ice_blast_3 = 1;
    		ice_blast_1 = 0;
    		glutTimerFunc(20, ice_blast_timer, 0);
    	}
    	else if(n >= 33 && n < 66){
            if(n%3 == 0 && lightning_strike_2 == 0 && (bad_guy_here == 3 || bad_guy_here == 4)){
                lightning_strike_2 = 1;
                glutTimerFunc(20, lightning_timer, 1);
            }
    		wolf_attack = 1;
    		ice_blast_1 = 1;
    		ice_blast_3 = 1;
    		ice_blast_2 = 0;
    		glutTimerFunc(20, ice_blast_timer, 0);
    	}
    	else{
            if(n%3 == 0 && lightning_strike_3 == 0 && (bad_guy_here == 3 || bad_guy_here == 4)){
                lightning_strike_3 = 1;
                glutTimerFunc(20, lightning_timer, 1);
            }
    		wolf_attack = 1;
    		ice_blast_1 = 1;
    		ice_blast_2 = 1;
    		ice_blast_3 = 0;
    		glutTimerFunc(20, ice_blast_timer, 0);
    	}

    	glutTimerFunc(1600, wolf_attack_timer, 0);
   	}

}