#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "Sword_and_shield.h"

void draw_sword(){
	//sword

    float mat_ambient_Silver[] ={ 0.19225f, 0.19225f, 0.19225f, 1.0f };
	float mat_diffuse_Silver[] ={ 0.50754f, 0.50754f, 0.50754f, 1.0f};
	float mat_specular_Silver[] ={0.508273f, 0.508273f, 0.508273f, 1.0f };
	float shine_Silver = 51.2f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Silver);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Silver);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Silver);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Silver);

    GLUquadricObj *quadObj = gluNewQuadric();

    //tip
	glBegin(GL_TRIANGLES);

		glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(0.3, 0, 8);
        glVertex3f(0, 0, 8.5);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(-0.3, 0, 8);
        glVertex3f(0, 0, 8.5);

    glEnd();

    //blade
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(0.3, 0, 8);
        glVertex3f(0.3, 0, 0);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(-0.3, 0, 8);
        glVertex3f(-0.3, 0, 0);

    glEnd();

    //sword handle
    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glRotatef(90, 0, 1, 0);

    gluCylinder(quadObj, 0.1, 0.1, 2, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -2.5);

    gluCylinder(quadObj, 0.15, 0.15, 2.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 0, 0);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 0);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    //pommel
    glPushMatrix();
    glTranslatef(0, 0, -2.5);

    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();


}

void draw_shield(){

	//Gold
	float mat_ambient_Gold[]={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
	float mat_diffuse_Gold[]={0.75164f, 0.60648f, 0.22648f, 1.0f };
	float mat_specular_Gold[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
	float shine_Gold =51.2f ;


    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

	GLUquadricObj *quadObj = gluNewQuadric();

	//shield 

	//base
	glBegin(GL_TRIANGLES);

		glNormal3f(1, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1.5, 0, 4);
        glVertex3f(0, 0, 4);

        glNormal3f(-1, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(-1.5, 0,4);
        glVertex3f(0, 0, 4);

        glNormal3f(1, 1, 0);
        glVertex3f(0, 0, 4);
        glVertex3f(1.5, 0, 4);
        glVertex3f(0, 0, 6);

        glNormal3f(-1, 1, 0);
        glVertex3f(0, 0, 4);
        glVertex3f(-1.5, 0, 4);
        glVertex3f(0, 0, 6);
    glEnd();

    //the rim and some decorations
    glPushMatrix();
    glRotatef(20.556, 0, 1, 0);

    gluCylinder(quadObj, 0.08, 0.08, 4.272, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-20.556, 0, 1, 0);

    gluCylinder(quadObj, 0.08, 0.08, 4.272, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, 4);
    glRotatef(-36.87, 0, 1, 0);



    gluCylinder(quadObj, 0.08, 0.08, 2.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 4);
    glRotatef(36.87, 0, 1, 0);
 


    gluCylinder(quadObj, 0.08, 0.08, 2.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.5, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 6);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.75, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 3);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 5);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


}