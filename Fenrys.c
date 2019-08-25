#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "Fenrys.h"
//he is a very good boy
void draw_wolf(){


    //material parameters
	//Silver
    float mat_ambient_Silver[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
	float mat_diffuse_Silver[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f};
	float mat_specular_Silver[] = {0.208273f, 0.208273f, 0.208273f, 1.0f };
	float shine_Silver = 12.1f;

	//Obsidian
	float mat_ambient_Obsidian[] = { 0.05375f, 0.05f, 0.06625f, 0.82f };
	float mat_diffuse_Obsidian[] = { 0.18275f, 0.17f, 0.22525f, 0.82f};
	float mat_specular_Obsidian[] = {0.332741f, 0.328634f, 0.346435f, 0.82f };
	float shine_Obsidian = 12.1f ;

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Silver);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Silver);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Silver);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Silver);

    //Fenrys

    //body
    glPushMatrix();

    glTranslatef(0, 0, 1.2);
    glScalef(2.6, 4, 1.7);
    glutSolidCube(1);

    glPopMatrix();

    //tail and tail movement animation
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(wolf_move, 0, 0, 1);
    glTranslatef(0, 0, -1.7);
    glTranslatef(0, -2.5, 1.2);
    glRotatef(25, 1, 0, 0);
    glScalef(0.6, 2.5, 0.6);
    glutSolidCube(1);

    glPopMatrix();

    //legs and movement animation
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(wolf_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-wolf_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-wolf_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(wolf_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    //head
    glPushMatrix();

    glTranslatef(0, 2.5, 2.2);
    glScalef(0.8, 0.8, 0.8);
    glRotatef(-5, 1, 0, 0);


    //base
    glPushMatrix();

    glTranslatef(0, -0.5, 0.5);
    glScalef(2, 2, 2);   
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0.3, 0);
    glScalef(1, 3, 1);  
    glutSolidCube(1);

    glPopMatrix();

    //ears
    glPushMatrix();

    glTranslatef(0.6, -0.5, 1.5);
    glScalef(0.5, 0.5, 0.6);
   
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.6, -0.5, 1.5);
    glScalef(0.5, 0.5, 0.6);
   
    glutSolidCube(1);
    glPopMatrix();

    //eyes
    glPushMatrix();

    glTranslatef(0.5, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.5, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Obsidian);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Obsidian);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Obsidian);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Obsidian);

    glPushMatrix();

    glTranslatef(0.4, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.4, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    //nose
    glPushMatrix();

    glTranslatef(0, 1.8, 0.5);
    glScalef(0.3, 0.3, 0.3);  
    glutSolidCube(1);

    glPopMatrix();
    
    glPopMatrix();

}