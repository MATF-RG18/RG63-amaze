#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "Whirly.h"

//I ran out of ideas for this one
void draw_Whirly(){

//whirlly

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
	

    //body
    glPushMatrix();
    glRotatef(Whirly_move, 0, 0, 1);
    gluCylinder(quadObj, 0, 6, 12, 30, 30);
    glPopMatrix();

    //arms
    glPushMatrix();

    glTranslatef(-4, -1, 6);
    glRotatef(-125, 1, 0, 0);
    glRotatef(Whirly_move, 0, 0, 1);

    
        
    gluCylinder(quadObj, 0, 2, 7, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -1, 6);
    glRotatef(-125, 1, 0, 0);
    glRotatef(Whirly_move, 0, 0, 1);
    gluCylinder(quadObj, 0, 2, 7, 30, 30);
    glPopMatrix();

    //eyes
    glPushMatrix();

    glTranslatef(2, 5, 10);
    glRotatef(-25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2, 5, 10);
    glRotatef(25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


}