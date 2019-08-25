#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "DEER.h"
#include "Sword_and_shield.h"

void DEER(){


    //sheild
    glPushMatrix();

    glTranslatef(0, -2, 3.1);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 1, 0, 0);
    glScalef(0.6, 0.6, 0.5);
    draw_shield();

    glPopMatrix();


    //White
    float mat_ambient_White[]={ 0.05f,0.05f,0.05f,1.0f };
    float mat_diffuse_White[]={ 0.9f,0.9f,0.9f,1.0f};
    float mat_specular_White[] ={ 0.7f,0.7f,0.7f,1.0f};
    float shine_White = 10.0f;

    GLfloat ambient_coeffs[] = { 0.25f, 0.148f, 0.06475f, 1.0f};
    GLfloat diffuse_coeffs_Light_Brown[] = { 0.4f, 0.2368f, 0.1036f, 1.0f};
    GLfloat diffuse_coeffs_Brown[] = { 0.2, 0.098, 0, 1};
    GLfloat specular_coeffs[] = { 0, 0, 0, 1};
    GLfloat shininess = 10;
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_Brown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    float mat_specular[] ={0.774597f, 0.458561f, 0.200621f, 1.0f };
    float shine =76.8f ;

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    //body

    glPushMatrix();

    glTranslatef(0, 0, 2);
    glScalef(2.7, 4, 2);
    glutSolidCube(1);

    glPopMatrix();

    //tail
    glPushMatrix();

    glTranslatef(0, -2.1, 3);
    glScalef(0.4, 0.4, 0.5);
    glutSolidCube(1);

    glPopMatrix();

    //legs and movement animation
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    //attack animation
    glPushMatrix();
    glRotatef(attack_rotation, 0, 0, 1);

    //neck
    glPushMatrix();

    glTranslatef(0, 2, 3);
    glRotatef(-45, 1, 0, 0);
    glScalef(1, 1, 2);   
    glutSolidCube(1);

    glPopMatrix();

    //head
    glPushMatrix();

    glTranslatef(0, 3, 3.7);
    glScalef(0.7, 0.7, 0.7);
    glRotatef(-22.5, 1, 0, 0);

    //sword
    glPushMatrix();

    glTranslatef(-1.2, 1.5, -0.6);
    glRotatef(-90, 0, 1, 0);
    glRotatef(-90, 0, 0, 1);
    glRotatef(24, 0, 0, 1);
    //glScalef(0.3, 0.3, 0.3);
    draw_sword();

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_Light_Brown);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);

    //mouth
    glPushMatrix();

    glTranslatef(0, 0, -0.5);
    glRotatef(-25, 1, 0, 0);
    glScalef(2, 3, 0.4);
    
    glutSolidCube(1);

    glPopMatrix();


    //base
    glPushMatrix();

    glTranslatef(0, -0.5, 1);
    glScalef(2, 2, 1);   
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glScalef(2, 3, 1);  
    glutSolidCube(1);

    glPopMatrix();

    //ears
    glPushMatrix();

    glTranslatef(1, -0.5, 1.5);
    glRotatef(45, 0, 1, 0);
    glScalef(0.3, 0.3, 0.5);
   
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1, -0.5, 1.5);
    glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 0.5);
   
    glutSolidCube(1);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_White);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_White);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_White);

    //antler number 1

    glPushMatrix();

    glTranslatef(0.5, -0.5, 2);

    glPushMatrix();

    glScalef(0.3, 0.3, 1.5);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 0.75);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    
    glTranslatef(0, 0.75, 1.35);
    glScalef(0.3, 0.3, 1.5);   
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, -0.75, 1.35);
    glScalef(0.3, 0.3, 1.5);   
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.45, 0, 0.75);
	glScalef(0.9, 0.3, 0.3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.9, 0, 1);
    glScalef(0.3, 0.3, 0.9);  
    glutSolidCube(1);

    glPopMatrix();

    //antler number 2

    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glRotatef(180, 0, 0, 1);

    glPushMatrix();

    glScalef(0.3, 0.3, 1.5);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 0.75);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    
    glTranslatef(0, 0.75, 1.35);
    glScalef(0.3, 0.3, 1.5);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, -0.75, 1.35);
    glScalef(0.3, 0.3, 1.5);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.45, 0, 0.75);
    glScalef(0.9, 0.3, 0.3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.9, 0, 1);
    glScalef(0.3, 0.3, 0.9);   
    glutSolidCube(1);

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}