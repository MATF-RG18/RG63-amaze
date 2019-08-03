#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>

//variables for width and depth
static int window_width, window_height;

//callback functions
static void on_display(void);
static void on_reshape(int width, int height);

int main(int argc, char** argv){

	//initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);


    //window initialization
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("AMAZE");

    //calling the callback functions
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);

    //color that cleans the view
    glClearColor(0.75, 0.75, 0.75, 0);

    //making the lines bolder
    glLineWidth(3);


    //entering the main loop
    glutMainLoop();

	return 0;
}

void on_display(void){

	//cleaning out the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//setting the view
    glViewport(0, 0,window_width, window_height);

    //Setting the angle, width-height ratio, near and far clipping plain
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 1, 1500);

    //implementing the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(12.5, 12.5, 50,
    	     12, 12, 0,
    	     0, 0, 1);

    //the coordinate system
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);                        
        glVertex3f(10,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();

    //floor
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();

    glTranslatef(25, 25, 0);
    glScalef(50, 50, 0.2);
    glutSolidCube(1);

    glPopMatrix();

    //maze matrix
    int M[51][51];
    int i=0, j=0;

    //file pointer
    FILE *fp;
    fp = fopen("MAZE.txt", "r");

    //I wrote a matrix with ones and zeroes
    //1 - there is a wall there 0 - there is no wall there
    //here we scan that matrix from a file
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
       if (!fscanf(fp, " %d", &M[i][j])) 
           break;
      }
      printf("%d \n", M[i][j]);
    }
    
    fclose(fp);
    

    //here we draw the maze
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            if(M[i][j] == 1){
                printf("sam usao ovde?\n");
                glColor3f(0,0,0);
                glPushMatrix();

                glTranslatef(i, j, 0);
                glScalef(1, 1, 10);
                glutSolidCube(1);

                glPopMatrix();
            }
        }
    }
    

    // the picture gets drawn
    glutSwapBuffers();
	}

	//when we reshape the window this function activates
static void on_reshape(int width, int height){
     window_width = width;
     window_height = height;
}