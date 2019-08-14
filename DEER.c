#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "DEER.h"

void DEER(){

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

    //legs
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

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_Light_Brown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);

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
}