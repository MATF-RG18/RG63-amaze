#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "Abraxos.h"

void draw_Abraxos(){
	

	//Ruby
	float mat_ambient_Ruby[] ={ 0.1745f, 0.01175f, 0.01175f, 0.55f };
	float mat_diffuse_Ruby[] ={0.61424f, 0.04136f, 0.04136f, 0.55f };
	float mat_specular_Ruby[] ={0.727811f, 0.626959f, 0.626959f, 0.55f };
	float shine_Ruby =76.8f ;

    //Gold
	float mat_ambient_Gold[]={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
	float mat_diffuse_Gold[]={0.75164f, 0.60648f, 0.22648f, 1.0f };
	float mat_specular_Gold[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
	float shine_Gold =51.2f ;


    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);


//Abraxos

	//wings
	glPushMatrix();
	glTranslatef(0, -1, 5);

	glPushMatrix();

	glRotatef(25, 0, 1, 0);

	glPushMatrix();

	glRotatef(25, 0, 0, 1);

	    glBegin(GL_TRIANGLES);

        glVertex3f(2,4,0);
        glVertex3f(2,0,10);
        glVertex3f(2,0,0);

        glVertex3f(2,0,0);
        glVertex3f(2,0,10);
        glVertex3f(-2,-5,10);
    glEnd();

    glPopMatrix();

    glPopMatrix();


	glPushMatrix();

	glRotatef(-25, 0, 1, 0);

    glPushMatrix();

	glRotatef(-25, 0, 0, 1);

	    glBegin(GL_TRIANGLES);

        glVertex3f(-2,4,0);
        glVertex3f(-2,0,10);
        glVertex3f(-2,0,0);

        glVertex3f(-2,0,0);
        glVertex3f(-2,0,10);
        glVertex3f(2,-5,10);
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);


	//head

	glPushMatrix();
	glTranslatef(0, 6, 10.35);
	glRotatef(-25, 1, 0, 0);

	glPushMatrix();

    glTranslatef(0, 0, 0.25);
    glScalef(2, 3, 0.5);
    
    glutSolidCube(1);

    glPopMatrix();

    GLUquadricObj *quadObj = gluNewQuadric();
	

    //snout spike

    glPushMatrix();
    glTranslatef(0, 1, 0.5);

    gluCylinder(quadObj, 0.2, 0, 1, 30, 30);
    glPopMatrix();

	glPushMatrix();

	//face
    glTranslatef(0, -0.75, 0.5);
    glScalef(2, 1.5, 0.5);
    
    glutSolidCube(1);

    glPopMatrix();

    //mouth
    glPushMatrix();

    glTranslatef(0, 0.45, -0.2);
    glRotatef(-25, 1, 0, 0);
    glScalef(2, 2, 0.4);
    
    glutSolidCube(1);

    glPopMatrix();

    //fangs
	glPushMatrix();
    glTranslatef(0.7, 1.35, -0.3);

    gluCylinder(quadObj, 0, 0.1, 0.4, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, 1.35, -0.3);

    gluCylinder(quadObj, 0, 0.1, 0.4, 30, 30);
    glPopMatrix();

    //horns

    glPushMatrix();

    glTranslatef(1, -1.2, 0.55);
    glRotatef(-25, 0, 0, 1);
    glScalef(2, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(1.62, -2, 0.55);
    glRotatef(65, 0, 0, 1);
    glScalef(1, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1, -1.2, 0.55);
    glRotatef(25, 0, 0, 1);
    glScalef(2, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1.62, -2, 0.55);
    glRotatef(-65, 0, 0, 1);
    glScalef(1, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();



    glPopMatrix();

 //body
    glPushMatrix();

    glTranslatef(0, 0, 4.1);
    glScalef(4, 8, 2);
    
    glutSolidCube(1);

    glPopMatrix();

 //legs and movement animation
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(Abraxos_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-2.7, -2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-Abraxos_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-2.7, 2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-Abraxos_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(2.7, -2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(Abraxos_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(2.7, 2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();



    //tail
    glPushMatrix();
    glScalef(1, 0.5, 0.5);
    glTranslatef(0, -4, 4);

    glPushMatrix();

    
    glTranslatef(0, -7.5, 1.5);

    glRotatef(35, 1, 0, 0);
    glScalef(1, 10, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, -15.1, 1.5);

    glRotatef(-35, 1, 0, 0);
    glScalef(1, 10, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, -20, 5);

    glRotatef(-35, 1, 0, 0);
    glScalef(2, 3, 2);
 
    glutSolidCube(1);

    glPopMatrix();
	

    //tail spikes

    glPushMatrix();
    glTranslatef(3.3, -23, 8);

    glRotatef(-90, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glRotatef(-35, 1, 0, 0);
    gluCylinder(quadObj, 0, 0.5, 5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.3, -23, 8);

    glRotatef(-90, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glRotatef(-35, 1, 0, 0);
    gluCylinder(quadObj, 0, 0.5, 5, 30, 30);
    glPopMatrix();

    glPopMatrix();

    //neck
    glPushMatrix();

    
    glTranslatef(0, 5.5, 5.5);

    glRotatef(45, 1, 0, 0);
    glScalef(1, 5, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, 5.5, 8.3);

    glRotatef(-45, 1, 0, 0);
    glScalef(1, 5, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, 4.5, 10.15);

    glRotatef(45, 1, 0, 0);
    glScalef(1, 2, 1);
 
    glutSolidCube(1);

    glPopMatrix();

}