#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<math.h>
#include "Powers.h"
//here we have all the antagonist powers
void draw_ice_blast(){


//ice blast

    //Turquoise
	float mat_ambient_Tr[]={ 0.1f, 0.18725f, 0.1745f, 0.8f };
	float mat_diffuse_Tr[]={0.396f, 0.74151f, 0.69102f, 0.8f };
	float mat_specular_Tr[] ={0.297254f, 0.30829f, 0.306678f, 0.8f };
	float shine_Tr = 12.8f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Tr);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Tr);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Tr);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Tr);



    glPushMatrix();

    //spinning animation
    glRotatef(ice_blast_move*4, 0, 1, 0);

    GLUquadricObj *quadObj = gluNewQuadric();

    //ice beam
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(-90, 1, 0, 0);

    gluCylinder(quadObj, 0.9, 0.9, 3+ice_blast_move, 30, 30);
    glPopMatrix();

    //ice beam point
    glPushMatrix();

    glTranslatef(0, 5+ice_blast_move, 0);
    glRotatef(90, 1, 0, 0);

    gluCylinder(quadObj, 0, 0.9, 2, 30, 30);
    glPopMatrix();

    //the power concentration
    glPushMatrix();
 	
 	glutSolidSphere(1.3, 30, 30);
    glPopMatrix();

    //ice crystals
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 2.5);
        glVertex3f(-0.5, 0, 4.5);
        glVertex3f(0, 0, 6.5);
        glVertex3f(0.5, 0, 4.5);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, -2.5);
        glVertex3f(-0.5, 0, -4.5);
        glVertex3f(0, 0, -6.5);
        glVertex3f(0.5, 0, -4.5);

        glNormal3f(0, 1, 0);
        glVertex3f(2.5, 0, 0);
        glVertex3f(4.5, 0, 0.5);
        glVertex3f(6.5, 0, 0);
        glVertex3f(4.5, 0, -0.5);

        glNormal3f(0, 1, 0);
        glVertex3f(-2.5, 0, 0);
        glVertex3f(-4.5, 0, 0.5);
        glVertex3f(-6.5, 0, 0);
        glVertex3f(-4.5, 0, -0.5);

    glEnd();

    glPopMatrix();

}

void draw_kaangs_staff(){

    //material parameters
    GLfloat diffuse_coeffs_Brown[] = { 0.2, 0.098, 0, 1};

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
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_Brown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

//kaangs wooden stick
GLUquadricObj *quadObj = gluNewQuadric();
	
//base

    glPushMatrix();

    //growing animation
    gluCylinder(quadObj, 0.2, 0.2, 8 + 0.4*ice_blast_move, 30, 30);
    glPopMatrix();
//handles

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    glPushMatrix();
    glTranslatef(0, 0, 0);

    gluCylinder(quadObj, 0.25, 0.25, 2, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 6 + 0.4*ice_blast_move);

    gluCylinder(quadObj, 0.25, 0.25, 2, 30, 30);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

    glPushMatrix();
    glTranslatef(0, 0, 0);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 2);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 6 + 0.4*ice_blast_move);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 8 + 0.4*ice_blast_move);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

}

void draw_fire_ball(){
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


//fire ball
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

	GLUquadricObj *quadObj = gluNewQuadric();
	
    glPushMatrix();

    //spin animation
    glRotatef(200*ice_blast_move, 1, 0, 0);

    //spikes
   	glPushMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

   	glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    //fire ball base
    glPushMatrix();
 	glutSolidSphere(1, 30, 30);
    glPopMatrix();
    
glPopMatrix();

}

void lightning_mold(){

//just a bunch of cubes together
    glPushMatrix();

    glRotatef(25, 0, 0, 1);
    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glRotatef(-25, 0, 0, 1);
    glTranslatef(0, 1, 0);

    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 2.6, 0);
    glRotatef(35, 0, 0, 1);

    glScalef(0.2, 3, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 4.1, 0);
    glRotatef(-35, 0, 0, 1);


    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 6, 0);
    glRotatef(25, 0, 0, 1);

    glScalef(0.2, 3, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 7.5, 0);
    glRotatef(-25, 0, 0, 1);


    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.2, 8.5, 0);
    glRotatef(25, 0, 0, 1);


    glScalef(0.2, 1, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

}

void draw_lightning_bolt(){
    //Gold
	float mat_ambient_Gold[]={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
	float mat_diffuse_Gold[]={0.75164f, 0.60648f, 0.22648f, 1.0f };
	float mat_specular_Gold[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
	float shine_Gold =51.2f ;
    
//lightning

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

    lightning_mold();

    glPushMatrix();

    glTranslatef(0, 9, 0);
    lightning_mold();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 18, 0);
    lightning_mold();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 27, 0);
    lightning_mold();

    glPopMatrix();




}