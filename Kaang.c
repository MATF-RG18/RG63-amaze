#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include "Kaang.h"

void draw_Kaang(){
	
	//Kaang Kong

	//material parameters

	//Obsidian
	float mat_ambient_Obsidian[] ={ 0.05375f, 0.05f, 0.06625f, 0.82f };
	float mat_diffuse_Obsidian[] ={ 0.18275f, 0.17f, 0.22525f, 0.82f};
	float mat_specular_Obsidian[] ={0.332741f, 0.328634f, 0.346435f, 0.82f };
	float shine_Obsidian =38.4f ;

	//Ruby
	float mat_ambient_Ruby[] ={ 0.1745f, 0.01175f, 0.01175f, 0.55f };
	float mat_diffuse_Ruby[] ={0.61424f, 0.04136f, 0.04136f, 0.55f };
	float mat_specular_Ruby[] ={0.727811f, 0.626959f, 0.626959f, 0.55f };
	float shine_Ruby =76.8f ;

    //Polished copper
	float mat_ambient_Copper[] = { 0.2295f, 0.08825f, 0.0275f, 1.0f };
	float mat_diffuse_Copper[] = {0.5508f, 0.2118f, 0.066f, 1.0f };
	float mat_specular_Copper[] = {0.580594f, 0.223257f, 0.0695701f, 1.0f };
	float shine_Copper = 51.2f ;


    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);
    
    //body and arms, they move together when animated
    glPushMatrix();
    
    glTranslatef(0, 0, 1.7);
    glRotatef(Kaang_move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);

    //body
    glPushMatrix();

    glTranslatef(0, 0, 4.1);
    glRotatef(-55, 1, 0, 0);
    glScalef(4, 2, 5);
    
    glutSolidCube(1);

    glPopMatrix();


	//Arms
    glPushMatrix();

    glTranslatef(-2.65, 1.5, 2.5);
    glScalef(1.3, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(2.65, 1.5, 2.5);
    glScalef(1.3, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Copper);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Copper);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Copper);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Copper);
    glPushMatrix();

    glTranslatef(2.65, 1.5, 0);
    glScalef(1.8, 1.8, 4);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2.65, 1.5, 0);
    glScalef(1.8, 1.8, 4);
    glutSolidCube(1);

    glPopMatrix();

    //head
    glPushMatrix();

    glTranslatef(0, 2.5, 5);
    glScalef(1.2, 1.2, 1.2);
    glRotatef(-5, 1, 0, 0);


    //base

    //lower
    glPushMatrix();

    glTranslatef(0, 0.3, 0);
    glScalef(2, 1, 1);  
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    //upper
    glPushMatrix();

    glTranslatef(0, -0.5, 0.5);
    glScalef(2, 2, 2);   
    glutSolidCube(1);

    glPopMatrix();


    //ears
    glPushMatrix();

    glTranslatef(1.1, -0.5, 1.2);
    glScalef(0.3, 0.3, 0.5);
   
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1.1, -0.5, 1.2);
    glScalef(0.3, 0.3, 0.5);
   
    glutSolidCube(1);
    glPopMatrix();

    //eyes
    glPushMatrix();

    glTranslatef(0.5, 0.4, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.5, 0.4, 1);
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

    glPopMatrix();

    glPopMatrix();

	//back legs
    glPushMatrix();

    glTranslatef(-1, -1, 1.5);
    glScalef(1.3, 1, 4);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(1, -1, 1.5);
    glScalef(1.3, 1, 4);
    glutSolidCube(1);

    glPopMatrix();
  
}