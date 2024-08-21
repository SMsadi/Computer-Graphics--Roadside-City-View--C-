#include <iostream>

using namespace std;
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#define PI 3.1416

bool night=false;
bool day=true;
bool rain=false;

GLfloat busposition = 0.0f;
GLfloat busspeed = 0.05f;
GLfloat cngposition = 0.0f;
GLfloat cngspeed = 0.04f;
GLfloat positionOfCloud=0.0f;
GLfloat Speed4 =0.005;
GLfloat positionOfCloud2=0.0f;
GLfloat Speed5 =0.007;
GLfloat positionSun = 0.0f;
GLfloat Speed9 =0.005;
GLfloat boatposition = 0.04f;
GLfloat boatspeed = 0.01f;

GLfloat rainSpeed=0.1f; //rain
GLfloat rainPos = 0.0f;
GLfloat rainSpeedX=0.1f;
GLfloat rainPosX = 0.0f;


void DrawCircle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 300; i++)
        {
            double theta = 2.0f * 3.1416f * i /300;//get current angle
            double x = r * cosf(theta);//calculate x
            double y = r * sinf(theta);//calculate y
            glVertex2f(x + cx, y + cy);//output vertex
        }
    glEnd();
    glFlush();
}

void update1(int value)
{
    //cloud 1 movement

    if(positionOfCloud < -1.30)
    positionOfCloud = 1.0f;
    positionOfCloud -=Speed4;


    glutPostRedisplay();
    glutTimerFunc(100, update1, 0);
}
void update2(int value)
{
    //cloud 2 movement

    if(positionOfCloud2 < -1.30)
    positionOfCloud2 = 1.0f;
    positionOfCloud2 -=Speed5;

    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}

void update3(int value)
{
    //sun Rise
    if(positionSun < -0.9)
    positionSun = 0.0f;
    positionSun -=Speed9;


    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}

void update5(int value)
{
     //rain movement part
     if(rainPos<-.001)
     {
        rainPos=.5;
     }
    if(rainPosX<-0.1)
    {
        rainPosX=.05;
    }
    if(rain)
    {
        rainPos-=rainSpeed;
        rainPosX-=rainSpeedX;
    }

	glutPostRedisplay();
	glutTimerFunc(100, update5, 0);
}

void init()
{
    glClearColor(1,1,1,0);
    glShadeModel(GL_SMOOTH);// Enable Smooth Shading
    glClearDepth(1.0f);// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);// Enables Depth Testing
}

void daysky() /////Day Sky///
{
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(1.0, 0.15);
        glVertex2f(-1.0, 0.15);
        glColor4f(0.4f, 0.8f, 1.0f, 1.0f);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);
    glEnd();

}

void dayriver()///////////Day River//////////
{
    glBegin(GL_QUADS);
        glColor3ub(0,0,0);//black road
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(1.0f, 0.15f);
        glVertex2f(1.0f, 0.13f);
        glVertex2f(-1.0f, 0.13f);

        glColor3ub(100, 160, 255);
        glColor3ub(0,0,255);  // blue river
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(1.0f, 0.15f);
        glColor4f(0.4f, 0.8f, 1.0f, 1.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
    glEnd();
}


void cloud1()
{
    glPushMatrix();
    glTranslatef(-positionOfCloud, 0.05f, 0.0f);
        glColor3ub(255, 240, 255);
        DrawCircle(0.5f,0.90f, .05f);
        DrawCircle(0.55f,0.87f, .05f);
        DrawCircle(0.45f,0.87f, .05f);
        DrawCircle(0.52f,0.83f, .05f);
        DrawCircle(0.60f,0.85f, .05f);

        glEnd();
    glPopMatrix();
}

void cloud2()
{

    glPushMatrix();
    glTranslatef(-positionOfCloud2, 0.05f, 0.0f);
    glTranslatef(-positionOfCloud2, 0.05f, 0.0f);
        glColor3ub(255, 240, 255);
        DrawCircle(-0.5f,0.85f, .05f);
        DrawCircle(-0.55f,0.82f, .05f);
        DrawCircle(-0.45f,0.82f, .05f);
        DrawCircle(-0.52f,0.79f, .05f);
        DrawCircle(-0.60f,0.81f, .05f);
        glEnd();
    glPopMatrix();
}



void sun()
{
     //sun (move)
    glPushMatrix();
    glTranslatef(0.0f,-positionSun, 0.0f);
    glColor3ub(255, 255, 0);
    DrawCircle(0.21f, 0.22f, 0.075f);
    glEnd();
    glPopMatrix();
}

void nightsky()/////Night Sky////
{
    glColor3ub(0,0,0); /////Black Night sky////
    glBegin(GL_QUADS);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1.0, 0.15);
    glVertex2f(-1.0, 0.15);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glEnd();

}

void moon()
{
    glColor3ub(0,0,0);

    DrawCircle(-0.85, 0.885,0.06);

    glColor3f(1.0f ,1.0f, 1.0f);
    DrawCircle(-0.87, 0.88,0.06);
}

void nightriver()//////////Night River//////
{
    glBegin(GL_QUADS);
        glColor3f(0.4f ,0.5f, 0.5f);//gray road
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(1.0f, 0.15f);
        glVertex2f(1.0f, 0.13f);
        glVertex2f(-1.0f, 0.13f);

        glColor3f(0.0f, 0.0f, 0.2f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
        glColor3f(0.9f, 1.0f, 0.7f);  //   Shaded Deep Blue river
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(1.0f, 0.15f);

    glEnd();
}

void stars()
{
    glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(247, 240, 188);
    glVertex2f(0.8f,0.95f);
    glVertex2f(0.9f,0.9f);
    glVertex2f(0.95f,0.7f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.7f,0.9f);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.5f,0.75f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.3f,0.7f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.15f,0.75f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.4f,0.8f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.9f,0.9f);
    glVertex2f(-0.95f,0.7f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.5f,0.75f);
    glVertex2f(-0.4f,0.9f);
    glVertex2f(-0.3f,0.7f);
    glVertex2f(-0.25f,0.9f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.15f,0.75f);
    glVertex2f(-0.1f,0.7f);
    glVertex2f(0.8f,0.75f);
    glVertex2f(0.9f,0.7f);
    glVertex2f(0.95f,0.5f);
    glVertex2f(0.8f,0.6f);
    glVertex2f(0.7f,0.7f);
    glVertex2f(0.6f,0.6f);
    glVertex2f(0.5f,0.55f);
    glVertex2f(0.4f,0.7f);
    glVertex2f(0.3f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.25f,0.5f);
    glVertex2f(0.1f,0.7f);
    glVertex2f(0.15f,0.55f);
    glVertex2f(0.0f,0.6f);
    glVertex2f(-0.7f,0.7f);
    glVertex2f(-0.8f,0.75f);
    glVertex2f(-0.4f,0.6f);
    glVertex2f(-0.8f,0.75f);
    glVertex2f(-0.9f,0.7f);
    glVertex2f(-0.95f,0.5f);
    glVertex2f(-0.8f,0.6f);
    glVertex2f(-0.7f,0.7f);
    glVertex2f(-0.6f,0.6f);
    glVertex2f(-0.5f,0.55f);
    glVertex2f(-0.4f,0.7f);
    glVertex2f(-0.3f,0.5f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.25f,0.5f);
    glVertex2f(-0.15f,0.55f);
    glVertex2f(-0.1f,0.7f);
    glEnd();

}

//---------CNG Start-------//
//---------CNG front light-------//

void ncng()
{
        glBegin(GL_QUADS);
        glColor3ub(255, 235, 153);
        glVertex2f(0.27f, -0.77f);
        glVertex2f(0.27f, -0.73f);
        glColor3f(0.33f ,0.33f, 0.33f);
        glVertex2f(0.15f, -0.65f);
        glVertex2f(0.15f, -0.85f);
        glEnd();


}
//---------CNG front light-------//

void cng()
{


        //border
    glLineWidth(2.5);

	glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.4f, -0.6f);

        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.4f, -0.9f);

        glVertex2f(0.32f, -0.9f);
        glVertex2f(0.4f, -0.9f);

        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.3f, -0.88f);

        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.4f, -0.4f);


        glVertex2f(0.3f, -0.77f);
        glVertex2f(0.4f, -0.77f);

        glVertex2f(0.4f, -0.76f);
        glVertex2f(0.55f, -0.76f);

        glVertex2f(0.4f, -0.45f);
        glVertex2f(0.55f, -0.45f);

        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.55f, -0.76f);

        glVertex2f(0.54f, -0.45f);
        glVertex2f(0.54f, -0.76f);

        glVertex2f(0.52f, -0.45f);
        glVertex2f(0.52f, -0.76f);

        glVertex2f(0.5f, -0.45f);
        glVertex2f(0.5f, -0.76f);

        glVertex2f(0.48f, -0.45f);
        glVertex2f(0.48f, -0.76f);

        glVertex2f(0.46f, -0.45f);
        glVertex2f(0.46f, -0.76f);

        glVertex2f(0.44f, -0.45f);
        glVertex2f(0.44f, -0.76f);

        glVertex2f(0.42f, -0.45f);
        glVertex2f(0.42f, -0.76f);

        glVertex2f(0.4f, -0.48f);
        glVertex2f(0.55f, -0.48f);

        glVertex2f(0.4f, -0.51f);
        glVertex2f(0.55f, -0.51f);

        glVertex2f(0.4f, -0.54f);
        glVertex2f(0.55f, -0.54f);

        glVertex2f(0.4f, -0.57f);
        glVertex2f(0.55f, -0.57f);

        glVertex2f(0.4f, -0.6f);
        glVertex2f(0.55f, -0.6f);

        glVertex2f(0.4f, -0.63f);
        glVertex2f(0.55f, -0.63f);

        glVertex2f(0.4f, -0.66f);
        glVertex2f(0.55f, -0.66f);

        glVertex2f(0.4f, -0.69f);
        glVertex2f(0.55f, -0.69f);

        glVertex2f(0.4f, -0.72f);
        glVertex2f(0.55f, -0.72f);

        glVertex2f(0.55f, -0.9f);
        glVertex2f(0.55f, -0.45f);

        glVertex2f(0.55f, -0.9f);
        glVertex2f(0.4f, -0.9f);

        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.6f, -0.45f);

        glVertex2f(0.6f, -0.85f);
        glVertex2f(0.6f, -0.45f);

        glVertex2f(0.6f, -0.85f);
        glVertex2f(0.55f, -0.85f);

        glVertex2f(0.6f, -0.45f);
        glVertex2f(0.75f, -0.48f);

        glVertex2f(0.75f, -0.48f);
        glVertex2f(0.75f, -0.75f);

        glVertex2f(0.75f, -0.75f);
        glVertex2f(0.6f, -0.75f);


        glVertex2f(0.6f, -0.48f);
        glVertex2f(0.75f, -0.50f);

        glVertex2f(0.6f, -0.51f);
        glVertex2f(0.75f, -0.53f);

        glVertex2f(0.6f, -0.54f);
        glVertex2f(0.75f, -0.56f);

        glVertex2f(0.6f, -0.57f);
        glVertex2f(0.75f, -0.59f);

        glVertex2f(0.6f, -0.60f);
        glVertex2f(0.75f, -0.62f);

        glVertex2f(0.6f, -0.63f);
        glVertex2f(0.75f, -0.65f);

        glVertex2f(0.6f, -0.66f);
        glVertex2f(0.75f, -0.68f);

        glVertex2f(0.6f, -0.69f);
        glVertex2f(0.75f, -0.71f);

        glVertex2f(0.6f, -0.72f);
        glVertex2f(0.75f, -0.74f);


        glVertex2f(0.74f, -0.48f);
        glVertex2f(0.74f, -0.75f);

        glVertex2f(0.72f, -0.48f);
        glVertex2f(0.72f, -0.75f);

        glVertex2f(0.7f, -0.475f);
        glVertex2f(0.7f, -0.75f);

        glVertex2f(0.68f, -0.46f);
        glVertex2f(0.68f, -0.75f);

        glVertex2f(0.66f, -0.465f);
        glVertex2f(0.66f, -0.75f);

        glVertex2f(0.64f, -0.45f);
        glVertex2f(0.64f, -0.75f);

        glVertex2f(0.62f, -0.455f);
        glVertex2f(0.62f, -0.75f);


        glVertex2f(0.7f, -0.84f);
        glVertex2f(0.8f, -0.84f);

        glVertex2f(0.7f, -0.84f);
        glVertex2f(0.65f, -0.9f);

        glVertex2f(0.8f, -0.84f);
        glVertex2f(0.85f, -0.9f);

        glVertex2f(0.26f, -0.84f);
        glVertex2f(0.335f, -0.84f);

        glVertex2f(0.335f, -0.84f);
        glVertex2f(0.39f, -0.9f);

        glVertex2f(0.3f, -0.75f);
        glVertex2f(0.4f, -0.75f);

        glVertex2f(0.4f, -0.9f);
        glVertex2f(0.7f, -0.9f);

        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.85f, -0.4f);

        glVertex2f(0.85f, -0.4f);
        glVertex2f(0.85f, -0.9f);







    glEnd();
    //back wheel
    glColor3ub(115, 115, 115);
    glBegin(GL_POLYGON);
            double radius3 = 0.02;
            double ori_x3 = 0.75;
            double ori_y3 = -0.91;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius3;
                    double y = sin(angle2) * radius3;
                    glVertex2d(ori_x3 + x, ori_y3 + y);
                }
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
            double radius2 = 0.05;
            double ori_x2 = 0.75;
            double ori_y2 = -0.91;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius2;
                    double y = sin(angle2) * radius2;
                    glVertex2d(ori_x2 + x, ori_y2 + y);
                }
    glEnd();

//ftont wheel
    glColor3ub(115, 115, 115);
    glBegin(GL_POLYGON);
            double radius1 = 0.02;
            double ori_x1 = 0.295;
            double ori_y1 = -0.91;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius1;
                    double y = sin(angle2) * radius1;
                    glVertex2d(ori_x1 + x, ori_y1 + y);
                }
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
            double radius = 0.05;
            double ori_x = 0.295;
            double ori_y = -0.91;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius;
                    double y = sin(angle2) * radius;
                    glVertex2d(ori_x + x, ori_y + y);
                }
    glEnd();

//cng body
   glBegin(GL_QUADS);


//middle
        glColor3ub(0, 51, 0);
        glVertex2f(0.4f, -0.55f);
        glVertex2f(0.4f, -0.65f);
        glVertex2f(0.43f, -0.65f);
        glVertex2f(0.43f, -0.55f);

        glColor3ub(255, 51, 0);
        glVertex2f(0.85f, -0.8f);
        glVertex2f(0.86f, -0.8f);
        glVertex2f(0.86f, -0.85f);
        glVertex2f(0.85f, -0.85f);

        glColor3ub(255, 153, 0);
        glVertex2f(0.85f, -0.75f);
        glVertex2f(0.86f, -0.75f);
        glVertex2f(0.86f, -0.8f);
        glVertex2f(0.85f, -0.8f);


        glColor3ub(0, 51, 0);
        glVertex2f(0.75f, -0.4f);
        glVertex2f(0.85f, -0.4f);
        glVertex2f(0.85f, -0.9f);
        glVertex2f(0.75f, -0.9f);

        glColor3ub(0, 51, 0);
        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.75f, -0.48);
        glVertex2f(0.75f, -0.4f);
        glVertex2f(0.55f, -0.4f);

        glColor3ub(0, 51, 0);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.4f, -0.45f);
        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.55f, -0.4f);

        glColor3ub(0, 102, 0);
        glVertex2f(0.85f, -0.9f);
        glVertex2f(0.55f, -0.9f);
        glVertex2f(0.55f, -0.85f);
        glVertex2f(0.85f, -0.85f);


        glColor3ub(0, 102, 0);
        glVertex2f(0.75f, -0.75f);
        glVertex2f(0.7f, -0.85f);
        glVertex2f(0.85f, -0.9f);
        glVertex2f(0.85f, -0.75f);

        glColor3ub(179, 179, 179);
        glVertex2f(0.6f, -0.45f);
        glVertex2f(0.75f, -0.48f);
        glVertex2f(0.75f, -0.75f);
        glVertex2f(0.6f, -0.75f);

        glColor3ub(0, 102, 0);
        glVertex2f(0.4f, -0.9f);
        glVertex2f(0.55f, -0.9f);
        glVertex2f(0.55f, -0.75f);
        glVertex2f(0.4f, -0.75f);

        glColor3ub(179, 179, 179);
        glVertex2f(0.4f, -0.76f);
        glVertex2f(0.55f, -0.76f);
        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.4f, -0.45f);

        glColor3ub(230, 115, 0);
        glVertex2f(0.35f, -0.65f);
        glVertex2f(0.38f, -0.65f);
        glVertex2f(0.38f, -0.68f);
        glVertex2f(0.35f, -0.68f);

        glColor3ub(255, 255, 255);
        glVertex2f(0.27f, -0.77f);
        glVertex2f(0.3f, -0.77f);
        glVertex2f(0.3f, -0.73f);
        glVertex2f(0.27f, -0.73f);

        glColor3ub(0, 102, 0);
        glVertex2f(0.3f, -0.87f);
        glVertex2f(0.26f, -0.87f);
        glVertex2f(0.26f, -0.77f);
        glVertex2f(0.3f, -0.77f);

        glColor3ub(20, 82, 20);
        glVertex2f(0.75f, -0.75f);
        glVertex2f(0.6f, -0.75f);
        glVertex2f(0.6f, -0.85f);
        glVertex2f(0.7f, -0.85f);


        glColor3ub(51, 204, 51);
        glVertex2f(0.6f, -0.45f);
        glVertex2f(0.75f, -0.48f);
        glVertex2f(0.75f, -0.75f);
        glVertex2f(0.6f, -0.75f);

        glColor3ub(0, 102, 0);
        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.6f, -0.45f);
        glVertex2f(0.6f, -0.85f);
        glVertex2f(0.55f, -0.85f);

        glColor3ub(51, 204, 51);
        glVertex2f(0.4f, -0.45f);
        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.55f, -0.9f);
        glVertex2f(0.4f, -0.9f);
        //front

        glColor3ub(0, 102, 0);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.4f, -0.6f);
        glVertex2f(0.4f, -0.9f);
        glVertex2f(0.3f, -0.9f);
//main body
        glColor3ub(230, 230, 230);
        glVertex2f(0.85f, -0.9f);
        glVertex2f(0.4f, -0.9f);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.85f, -0.4f);

    glEnd();

    glBegin(GL_TRIANGLES);
//front window
        glColor3ub(209, 224, 224);
        glVertex2f(0.31f, -0.58f);
        glVertex2f(0.39f, -0.58f);
        glVertex2f(0.39f, -0.42f);

        glColor3ub(0, 102, 0);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.4f, -0.6f);
        glVertex2f(0.4f, -0.4f);


    glEnd();


}

//---------CNG End-------//
//--------cng move start -------//


void cng(int cngvalue) {

    if(cngposition <-2.0)
        {
             cngposition = 2.0f;
        }
    else if(cngposition > 2)
    {
        cngposition = - 2.0f ;
    }

    cngposition -= cngspeed;

	glutPostRedisplay();


	glutTimerFunc(100, cng, 0);
}

//--------cng move end -------//
//---------Bus Start-------//
void bus()
{

    //Door and window start
        glBegin(GL_QUADS);
        glColor3ub(1,1,1);
        glVertex2f(-0.86f, -0.015f);
        glVertex2f(-0.71f, -0.015f);
        glColor3ub(89, 89, 89);
        glVertex2f(-0.71f, -0.235f);
        glVertex2f(-0.86f, -0.235f);

        glColor3ub(1,1,1);
        glVertex2f(-0.66f, -0.015f);
        glVertex2f(-0.51f, -0.015f);
        glColor3ub(89, 89, 89);
        glVertex2f(-0.51f, -0.235f);
        glVertex2f(-0.66f, -0.235f);

        glColor3ub(1,1,1);
        glVertex2f(-0.46f, -0.015f);
        glVertex2f(-0.31f, -0.015f);
        glColor3ub(89, 89, 89);
        glVertex2f(-0.31f, -0.235f);
        glVertex2f(-0.46f, -0.235f);

        glColor3ub(1,1,1);
        glVertex2f(-0.26f, -0.015f);
        glVertex2f(-0.11f, -0.015f);
        glColor3ub(89, 89, 89);
        glVertex2f(-0.11f, -0.235f);
        glVertex2f(-0.26f, -0.235f);

        glColor3ub(1,1,1);
        glVertex2f(-0.08f, -0.015f);
        glVertex2f(-0.01f, -0.015f);
        glColor3ub(89, 89, 89);
        glVertex2f(-0.01f, -0.435f);
        glVertex2f(-0.08f, -0.435f);

        glColor3ub(1,1,1);
        glVertex2f(0.01f, -0.015f);
        glVertex2f(0.01f, -0.435f);
        glColor3ub(89, 89, 89);
        glVertex2f(0.07f, -0.435f);
        glVertex2f(0.07f, -0.015f);


        glColor3ub(0,0,0);
        glVertex2f(0.0855f, -0.005f);
        glVertex2f(0.1f, -0.005f);
        glColor3ub(89, 89, 89);
        glVertex2f(0.1f, -0.245f);
        glVertex2f(0.0855f, -0.245f);
//Door and window end
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.7f ,0.4f, 0.3f);
        glVertex2f(-0.87f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, -0.25f);
        glVertex2f(-0.87f, -0.25f);


        glVertex2f(-0.67f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.5f, -0.25f);
        glVertex2f(-0.67f, -0.25f);


        glVertex2f(-0.47f, 0.0f);
        glVertex2f(-0.3f, 0.0f);
        glVertex2f(-0.3f, -0.25f);
        glVertex2f(-0.47f, -0.25f);

        glVertex2f(-0.27f, 0.0f);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(-0.1f, -0.25f);
        glVertex2f(-0.27f, -0.25f);

        //side led back
        glColor3f(1.0f ,0.5f, 0.0f);
        glVertex2f(-0.805f, -0.3f);
        glVertex2f(-0.82f, -0.3f);
        glVertex2f(-0.82f, -0.32f);
        glVertex2f(-0.805f, -0.32f);


        //side led front
        glColor3f(1.0f ,0.5f, 0.0f);
        glVertex2f(-0.1f, -0.3f);
        glVertex2f(-0.12f, -0.3f);
        glVertex2f(-0.12f, -0.32f);
        glVertex2f(-0.1f, -0.32f);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3f(0.7f ,0.4f, 0.3f);
        glVertex2f(0.08f, -0.45f);
        glVertex2f(-0.09f, -0.45f);

        glVertex2f(-0.09f, -0.45f);
        glVertex2f(-0.09f, 0.0f);

        glVertex2f(-0.09f, 0.0f);
        glVertex2f(0.08f, 0.0f);

        glVertex2f(0.08f, 0.0f);
        glVertex2f(0.08f, -0.45f);

        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, -0.45f);
        //box
        glVertex2f(-0.59f, -0.35f);
        glVertex2f(-0.3f, -0.35f);


        glVertex2f(-0.3f, -0.35f);
        glVertex2f(-0.3f, -0.48f);

        glVertex2f(-0.3f, -0.48f);
        glVertex2f(-0.59f, -0.48f);

        glVertex2f(-0.59f, -0.48f);
        glVertex2f(-0.59f, -0.35f);

        glVertex2f(-0.49f, -0.35f);
        glVertex2f(-0.49f, -0.48f);

        glVertex2f(-0.38f, -0.35f);
        glVertex2f(-0.38f, -0.48f);



        //back lines
        glVertex2f(-0.805f, -0.4f);
        glVertex2f(-0.805f, -0.48f);

        glVertex2f(-0.81f, -0.4f);
        glVertex2f(-0.81f, -0.48f);

        glVertex2f(-0.815f, -0.4f);
        glVertex2f(-0.815f, -0.48f);

        glVertex2f(-0.82f, -0.4f);
        glVertex2f(-0.82f, -0.48f);

        glVertex2f(-0.825f, -0.4f);
        glVertex2f(-0.825f, -0.48f);

        glVertex2f(-0.83f, -0.4f);
        glVertex2f(-0.83f, -0.48f);

        glVertex2f(-0.835f, -0.4f);
        glVertex2f(-0.835f, -0.48f);

        glVertex2f(-0.84f, -0.4f);
        glVertex2f(-0.84f, -0.48f);

        glVertex2f(-0.845f, -0.4f);
        glVertex2f(-0.845f, -0.48f);

        glVertex2f(-0.85f, -0.4f);
        glVertex2f(-0.85f, -0.48f);

        glVertex2f(-0.855f, -0.4f);
        glVertex2f(-0.855f, -0.48f);

        glVertex2f(-0.86f, -0.48f);
        glVertex2f(-0.86f, -0.48f);

        //front glass
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.085f, 0.0f);

        glVertex2f(0.085f, 0.0f);
        glVertex2f(0.085f, -0.25f);

        glVertex2f(0.085f, -0.25f);
        glVertex2f(0.1f, -0.25f);



    glEnd();

    //----------wheel start--------//
     //----back wheel-------//
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
            double radius8 = 0.02;
            double ori_x8 = -0.7;
            double ori_y8 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius8;
                    double y = sin(angle2) * radius8;
                    glVertex2d(ori_x8 + x, ori_y8 + y);
                }
        glEnd();

        glColor3ub(77, 40, 0);
        glBegin(GL_POLYGON);
            double radius7 = 0.05;
            double ori_x7 = -0.7;
            double ori_y7 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius7;
                    double y = sin(angle2) * radius7;
                    glVertex2d(ori_x7 + x, ori_y7 + y);
                }
        glEnd();

        glColor3ub(204, 102, 0);
        glBegin(GL_POLYGON);
            double radius6 = 0.06;
            double ori_x6 = -0.7;
            double ori_y6 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius6;
                    double y = sin(angle2) * radius6;
                    glVertex2d(ori_x6 + x, ori_y6 + y);
                }
        glEnd();
    //-----front wheel------//
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
            double radius5 = 0.02;
            double ori_x5 = -0.19;
            double ori_y5 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius5;
                    double y = sin(angle2) * radius5;
                    glVertex2d(ori_x5 + x, ori_y5 + y);
                }
        glEnd();

        glColor3ub(77, 40, 0);
            glBegin(GL_POLYGON);
            double radius4 = 0.05;
            double ori_x4 = -0.19;
            double ori_y4 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius4;
                    double y = sin(angle2) * radius4;
                    glVertex2d(ori_x4 + x, ori_y4 + y);
                }
        glEnd();

        glColor3ub(204, 102, 0);
        glBegin(GL_POLYGON);
            double radius3 = 0.06;
            double ori_x3 = -0.19;
            double ori_y3 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius3;
                    double y = sin(angle2) * radius3;
                    glVertex2d(ori_x3 + x, ori_y3 + y);
                }
        glEnd();


        glColor3f(0.0f ,0.0f, 0.0f);
        glBegin(GL_POLYGON);
            double radius2 = 0.09;
            double ori_x2 = -0.19;
            double ori_y2 = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle2 = 2 * 3.1416 * i / 300;
                    double x = cos(angle2) * radius2;
                    double y = sin(angle2) * radius2;
                    glVertex2d(ori_x2 + x, ori_y2 + y);
                }
        glEnd();

        glColor3f(0.0f ,0.0f, 0.0f);
        glBegin(GL_POLYGON);                        // Middle circle
            double radius = 0.09;
            double ori_x = -0.7;                         // the origin or center of circle
            double ori_y = -0.5;
            for (int i = 0; i <= 300; i++)
                {
                    double angle = 2 * 3.1416 * i / 300;
                    double x = cos(angle) * radius;
                    double y = sin(angle) * radius;
                    glVertex2d(ori_x + x, ori_y + y);
                }
        glEnd();

    //----------wheel end--------//

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f ,0.0f, 0.0f);
        glVertex2f(-0.7f, 0.1f);
        glVertex2f(-0.7f, 0.13f);
        glVertex2f(-0.75f, 0.1f);

        glColor3f(0.0f ,0.0f, 0.0f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.2f, 0.13f);
        glVertex2f(-0.15f, 0.1f);

	glEnd();

    glBegin(GL_QUADS);



//back light & banker
        glColor3f(0.0f ,0.0f, 0.0f);
        glVertex2f(-0.87f, -0.47f);
        glVertex2f(-0.87f, -0.52f);
        glVertex2f(-0.92f, -0.52f);
        glVertex2f(-0.92f, -0.47f);

        glColor3f(1.0f ,0.0f, 0.0f);
        glVertex2f(-0.9f, -0.4f);
        glVertex2f(-0.9f, -0.45f);
        glVertex2f(-0.91f, -0.45f);
        glVertex2f(-0.91f, -0.4f);
//front light & banker
        glColor3f(0.0f ,0.0f, 0.0f);
        glVertex2f(0.09f, -0.47f);
        glVertex2f(0.09f, -0.51f);
        glVertex2f(0.11f, -0.51f);
        glVertex2f(0.11f, -0.47f);

        glColor3f(1.0f ,1.0f, 1.0f);
        glVertex2f(0.1f, -0.4f);
        glVertex2f(0.1f, -0.45f);
        glVertex2f(0.11f, -0.45f);
        glVertex2f(0.11f, -0.4f);

//main yellow box
        glColor3ub(72, 48, 80);
        glVertex2f(-0.9f, -0.5f);
        glVertex2f(0.1f, -0.5f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.9f, 0.1f);


    glEnd();



}

//---------Bus end-------//
//---------BUS front light -------//

void nbus()
{
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 128);
        glVertex2f(0.11f, -0.45f);
        glVertex2f(0.11f, -0.4f);
        glColor3f(0.33f ,0.33f, 0.33f);
        glVertex2f(0.35f, -0.2f);
        glVertex2f(0.35f, -0.6f);
        glEnd();





}
//---------BUS front light -------//
//--------Bus move start -------//

void bus(int busvalue) {

    if(busposition <-2.0)
        {
             busposition = 2.0f;
        }
    else if(busposition > 2)
    {
        busposition = - 2.0f ;
    }

    busposition += busspeed;

	glutPostRedisplay();


	glutTimerFunc(100, bus, 0);
}

//--------Bus move end -------//

//----------------ROAD START-----------//
void road()
{
    //road middle line start

    glLineWidth(11.5);
    glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f(-0.8f, -0.7f);

        glVertex2f(-0.7f, -0.7f);
        glVertex2f(-0.5f, -0.7f);

        glVertex2f(-0.4f, -0.7f);
        glVertex2f(-0.2f, -0.7f);

        glVertex2f(-0.1f, -0.7f);
        glVertex2f(0.1f, -0.7f);

        glVertex2f(0.2f, -0.7f);
        glVertex2f(0.4f, -0.7f);

        glVertex2f(0.5f, -0.7f);
        glVertex2f(0.7f, -0.7f);

        glVertex2f(0.8f, -0.7f);
        glVertex2f(1.0f, -0.7f);
    glEnd();
//road middle line end

    glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glColor3f(0,0,0);
        glVertex2f(-1.0f, -0.40f);
        glVertex2f(1.0f, -0.40f);
        glVertex2f(1.0f, -0.60f);
        glVertex2f(-1.0f, -0.60f);

        glColor3f(0,0,0);
        glVertex2f(1.0f, -0.60f);
        glVertex2f(-1.0f, -0.60f);
        glColor3f(0.5f ,0.5f, 0.5f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);

    glEnd();
}
//----------------ROAD END-----------//


void boat()////boat Start//////
{
    glBegin(GL_QUADS);
        glColor3f(0.6f ,0.2f, 0.0f);
        glVertex2f(-0.84f, 0.1f);
        glVertex2f(-0.80f, 0.04f);
        glVertex2f(-0.65f, 0.04f);
        glVertex2f(-0.61f, 0.1f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3f(0.4f ,0.0f, 0.1f);
        glVertex2f(-0.75f, 0.1f);
        glVertex2f(-0.75f, 0.30f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.8f ,0.8f, 0.8f);
        glVertex2f(-0.75f, 0.11f);
        glVertex2f(-0.75f, 0.30f);
        glColor3f(0.8f ,0.4f, 0.3f);
        glVertex2f(-0.81f, 0.11f);

        glColor3f(0.8f ,0.8f, 0.8f);
        glVertex2f(-0.75f, 0.13f);
        glVertex2f(-0.75f, 0.30f);
        glColor3f(0.8f ,0.4f, 0.3f);
        glVertex2f(-0.71f, 0.13f);

    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(0.4f ,0.0f, 0.1f);
        glVertex2f(-0.62f, 0.1f);
        glVertex2f(-0.75f, 0.30f);

        glVertex2f(-0.66f, 0.1f);
        glVertex2f(-0.75f, 0.30f);
    glEnd();
}
////////////Boat End//////////

////////Boat Move Start/////
void boat(int boatvalue) {

    if(boatposition <-2.0)
    {
        boatposition = 2.0f;
    }
    else if(boatposition > 2)
    {
        boatposition = - 2.0f ;
    }
    boatposition -= boatspeed;

	glutPostRedisplay();
	glutTimerFunc(100,boat, 0);
}
///////Boat Move End////////

void sidewalk()
{
    glLineWidth(11);
    glBegin(GL_LINES);
        glColor3f(0,0,0);//black lines
        glVertex2f(-0.90, -0.385f);
        glVertex2f(-1.00f, -0.385f);

        glVertex2f(-0.80, -0.385f);
        glVertex2f(-0.70f, -0.385f);

        glVertex2f(-0.60, -0.385f);
        glVertex2f(-0.50f, -0.385f);

        glVertex2f(-0.40, -0.385f);
        glVertex2f(-0.30f, -0.385f);

        glVertex2f(-0.20, -0.385f);
        glVertex2f(-0.10f, -0.385f);

        glVertex2f(0.0, -0.385f);
        glVertex2f(0.10f, -0.385f);

         glVertex2f(0.20, -0.385f);
        glVertex2f(0.30f, -0.385f);

        glVertex2f(0.40, -0.385f);
        glVertex2f(0.50f, -0.385f);

         glVertex2f(0.60, -0.385f);
        glVertex2f(0.70f, -0.385f);

        glVertex2f(0.80, -0.385f);
        glVertex2f(0.90f, -0.385f);

    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.0 , 1.0 , 1.0);//white border
        glVertex2f(-1.0f, -0.37f);
        glVertex2f(-1.0f, -0.40f);
        glVertex2f(1.0f, -0.40f);
        glVertex2f(0.99f, -0.37f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.6f ,0.6f, 0.7f);
        glVertex2f(-1.0f, -0.20f);
        glVertex2f(1.0f, -0.20f);
        glVertex2f(1.0f, -0.40f);
        glVertex2f(-1.0f, -0.40f);
    glEnd();

}

void buildings()
{

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.9f, 0.0f);
        glVertex2f(0.9f, 0.48f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.48f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.48f);
        glVertex2f(0.9f, 0.48f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.488f);
        glVertex2f(0.9f, 0.488f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.95f, 0.52f);
        glVertex2f(0.95f, 0.488f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.933f, 0.0f);
        glVertex2f(0.933f, 0.48f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.966f, 0.0f);
        glVertex2f(0.966f, 0.48f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.33f);
        glVertex2f(0.9f, 0.33f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.20f);
        glVertex2f(0.9f, 0.20f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.27f);
        glVertex2f(0.9f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.40f);
        glVertex2f(0.9f, 0.40f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f ,0.0f, 0.0f);
        glVertex2f(0.91f, 0.48f);
        glVertex2f(0.91f, 0.53f);
        glVertex2f(0.993f, 0.53f);
        glVertex2f(0.993f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.0f ,1.0f, 0.9f, 1.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.48f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.9f, 0.48f);
        glVertex2f(0.9f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.8f, 0.56f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.0f);
        glVertex2f(0.85f, 0.58f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.56f);
        glVertex2f(0.85f, 0.58f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.58f);
        glVertex2f(0.91f, 0.55f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.91f, 0.55f);
        glVertex2f(0.91f, 0.0f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.52f);
        glVertex2f(0.85f, 0.54f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.54f);
        glVertex2f(0.91f, 0.51f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.48f);
        glVertex2f(0.85f, 0.50f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.50f);
        glVertex2f(0.91f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.44f);
        glVertex2f(0.85f, 0.46f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.46f);
        glVertex2f(0.91f, 0.43f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.40f);
        glVertex2f(0.85f, 0.42f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.42f);
        glVertex2f(0.91f, 0.39f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.36f);
        glVertex2f(0.85f, 0.38f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.38f);
        glVertex2f(0.91f, 0.35f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.32f);
        glVertex2f(0.85f, 0.34f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.34f);
        glVertex2f(0.91f, 0.31f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.28f);
        glVertex2f(0.85f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.30f);
        glVertex2f(0.91f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.24f);
        glVertex2f(0.85f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.26f);
        glVertex2f(0.91f, 0.23f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.20f);
        glVertex2f(0.85f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.22f);
        glVertex2f(0.91f, 0.19f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.16f);
        glVertex2f(0.85f, 0.18f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.85f, 0.18f);
        glVertex2f(0.91f, 0.15f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f ,0.7f, 1.0f);
        glVertex2f(0.815f, 0.565f);
        glVertex2f(0.815f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f ,0.7f, 1.0f);
        glVertex2f(0.835f, 0.57f);
        glVertex2f(0.835f, 0.0f);
    glEnd();


    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(1.0f ,0.9f, 0.9f, 1.0f);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.8f, 0.56f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.85f, 0.58f);
        glVertex2f(0.85f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(1.0f ,0.9f, 0.9f, 1.0f);
        glVertex2f(0.91f, 0.0f);
        glVertex2f(0.91f, 0.55f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.85f, 0.58f);
        glVertex2f(0.85f, 0.0f);
    glEnd();


    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(-0.8f, 0.56f);

        glVertex2f(-0.85f, 0.0f);
        glVertex2f(-0.85f, 0.58f);

        glVertex2f(-0.8f, 0.56f);
        glVertex2f(-0.85f, 0.58f);

        glVertex2f(-0.85f, 0.58f);
        glVertex2f(-0.91f, 0.55f);

        glVertex2f(-0.91f, 0.55f);
        glVertex2f(-0.91f, 0.0f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, 0.52f);
        glVertex2f(-0.85f, 0.54f);

        glVertex2f(-0.85f, 0.54f);
        glVertex2f(-0.91f, 0.51f);

        glVertex2f(-0.8f, 0.48f);
        glVertex2f(-0.85f, 0.50f);

        glVertex2f(-0.85f, 0.50f);
        glVertex2f(-0.91f, 0.47f);

        glVertex2f(-0.8f, 0.44f);
        glVertex2f(-0.85f, 0.46f);

        glVertex2f(-0.85f, 0.46f);
        glVertex2f(-0.91f, 0.43f);

        glVertex2f(-0.8f, 0.40f);
        glVertex2f(-0.85f, 0.42f);

        glVertex2f(-0.85f, 0.42f);
        glVertex2f(-0.91f, 0.39f);

        glVertex2f(-0.8f, 0.36f);
        glVertex2f(-0.85f, 0.38f);

        glVertex2f(-0.85f, 0.38f);
        glVertex2f(-0.91f, 0.35f);

        glVertex2f(-0.8f, 0.32f);
        glVertex2f(-0.85f, 0.34f);

        glVertex2f(-0.85f, 0.34f);
        glVertex2f(-0.91f, 0.31f);

        glVertex2f(-0.8f, 0.28f);
        glVertex2f(-0.85f, 0.30f);

        glVertex2f(-0.85f, 0.30f);
        glVertex2f(-0.91f, 0.27f);

        glVertex2f(-0.8f, 0.24f);
        glVertex2f(-0.85f, 0.26f);

        glVertex2f(-0.85f, 0.26f);
        glVertex2f(-0.91f, 0.23f);

        glVertex2f(-0.8f, 0.20f);
        glVertex2f(-0.85f, 0.22f);

        glVertex2f(-0.85f, 0.22f);
        glVertex2f(-0.91f, 0.19f);

        glVertex2f(-0.8f, 0.16f);
        glVertex2f(-0.85f, 0.18f);

        glVertex2f(-0.85f, 0.18f);
        glVertex2f(-0.91f, 0.15f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.815f, 0.565f);
        glVertex2f(-0.815f, 0.0f);

        glVertex2f(-0.835f, 0.57f);
        glVertex2f(-0.835f, 0.0f);
    glEnd();


    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(1.0f ,1.0f, 0.6f, 1.0f);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(-0.8f, 0.56f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(-0.85f, 0.58f);
        glVertex2f(-0.85f, 0.0f);

        glColor4f(1.0f ,1.0f, 0.6f, 1.0f);
        glVertex2f(-0.91f, 0.0f);
        glVertex2f(-0.91f, 0.55f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(-0.85f, 0.58f);
        glVertex2f(-0.85f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, 0.52f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.0f);
        glVertex2f(0.75f, 0.54f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.52f);
        glVertex2f(0.75f, 0.54f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.54f);
        glVertex2f(0.81f, 0.51f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.81, 0.51f);
        glVertex2f(0.81f, 0.0f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.48f);
        glVertex2f(0.75f, 0.50f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.50f);
        glVertex2f(0.81f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.44f);
        glVertex2f(0.75f, 0.46f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.46f);
        glVertex2f(0.81f, 0.43f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.40f);
        glVertex2f(0.75f, 0.42f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.42f);
        glVertex2f(0.81f, 0.39f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.36f);
        glVertex2f(0.75f, 0.38f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.38f);
        glVertex2f(0.81f, 0.35f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.32f);
        glVertex2f(0.75f, 0.34f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.34f);
        glVertex2f(0.81f, 0.31f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.28f);
        glVertex2f(0.75f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.30f);
        glVertex2f(0.81f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.24f);
        glVertex2f(0.75f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.26f);
        glVertex2f(0.81f, 0.23f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.20f);
        glVertex2f(0.75f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.22f);
        glVertex2f(0.81f, 0.19f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.16f);
        glVertex2f(0.75f, 0.18f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.75f, 0.18f);
        glVertex2f(0.81f, 0.15f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.715f, 0.525f);
        glVertex2f(0.715f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.735f, 0.53f);
        glVertex2f(0.735f, 0.0f);
    glEnd();


    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.6f, 0.8f, 1.0f);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, 0.52f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.75f, 0.54f);
        glVertex2f(0.75f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.6f, 0.8f, 1.0f);
        glVertex2f(0.81f, 0.0f);
        glVertex2f(0.81f, 0.51f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.75f, 0.54f);
        glVertex2f(0.75f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, 0.52f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.0f);
        glVertex2f(-0.75f, 0.54f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.52f);
        glVertex2f(-0.75f, 0.54f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.54f);
        glVertex2f(-0.81f, 0.51f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.81, 0.51f);
        glVertex2f(-0.81f, 0.0f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.48f);
        glVertex2f(-0.75f, 0.50f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.50f);
        glVertex2f(-0.81f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.44f);
        glVertex2f(-0.75f, 0.46f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.46f);
        glVertex2f(-0.81f, 0.43f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.40f);
        glVertex2f(-0.75f, 0.42f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.42f);
        glVertex2f(-0.81f, 0.39f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.36f);
        glVertex2f(-0.75f, 0.38f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.38f);
        glVertex2f(-0.81f, 0.35f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.32f);
        glVertex2f(-0.75f, 0.34f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.34f);
        glVertex2f(-0.81f, 0.31f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.28f);
        glVertex2f(-0.75f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.30f);
        glVertex2f(-0.81f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.24f);
        glVertex2f(-0.75f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.26f);
        glVertex2f(-0.81f, 0.23f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.20f);
        glVertex2f(-0.75f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.22f);
        glVertex2f(-0.81f, 0.19f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.16f);
        glVertex2f(-0.75f, 0.18f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.75f, 0.18f);
        glVertex2f(-0.81f, 0.15f);
    glEnd();


    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(-0.715f, 0.525f);
        glVertex2f(-0.715f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(-0.735f, 0.53f);
        glVertex2f(-0.735f, 0.0f);
    glEnd();


    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.8f, 1.0f, 1.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, 0.52f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(-0.75f, 0.54f);
        glVertex2f(-0.75f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.8f, 1.0f, 1.0f);
        glVertex2f(-0.81f, 0.0f);
        glVertex2f(-0.81f, 0.51f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(-0.75f, 0.54f);
        glVertex2f(-0.75f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, 0.63f);

        glVertex2f(-0.65f, 0.0f);
        glVertex2f(-0.65f, 0.65f);

        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.6f, 0.55f);

        glVertex2f(-0.7f, 0.63f);
        glVertex2f(-0.65f, 0.65f);

        glVertex2f(-0.65f, 0.65f);
        glVertex2f(-0.6f, 0.55f);

    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(-0.7f, 0.59f);
        glVertex2f(-0.65f, 0.61f);

        glVertex2f(-0.65f, 0.61f);
        glVertex2f(-0.6f, 0.51f);

        glVertex2f(-0.7f, 0.55f);
        glVertex2f(-0.65f, 0.57f);

        glVertex2f(-0.65f, 0.57f);
        glVertex2f(-0.6f, 0.47f);

        glVertex2f(-0.7f, 0.51f);
        glVertex2f(-0.65f, 0.53f);

        glVertex2f(-0.65f, 0.53f);
        glVertex2f(-0.6f, 0.43f);

        glVertex2f(-0.7f, 0.47f);
        glVertex2f(-0.65f, 0.49f);

        glVertex2f(-0.65f, 0.49f);
        glVertex2f(-0.6f, 0.39f);

        glVertex2f(-0.7f, 0.43f);
        glVertex2f(-0.65f, 0.45f);

        glVertex2f(-0.65f, 0.45f);
        glVertex2f(-0.6f, 0.35f);

        glVertex2f(-0.7f, 0.39f);
        glVertex2f(-0.65f, 0.41f);

        glVertex2f(-0.65f, 0.41f);
        glVertex2f(-0.6f, 0.31f);

        glVertex2f(-0.7f, 0.35f);
        glVertex2f(-0.65f, 0.37f);

        glVertex2f(-0.65f, 0.37f);
        glVertex2f(-0.6f, 0.27f);

        glVertex2f(-0.7f, 0.31f);
        glVertex2f(-0.65f, 0.33f);

        glVertex2f(-0.65f, 0.33f);
        glVertex2f(-0.6f, 0.23f);

        glVertex2f(-0.7f, 0.27f);
        glVertex2f(-0.65f, 0.29f);

        glVertex2f(-0.65f, 0.29f);
        glVertex2f(-0.6f, 0.19f);

        glVertex2f(-0.7f, 0.23f);
        glVertex2f(-0.65f, 0.25f);

        glVertex2f(-0.65f, 0.25f);
        glVertex2f(-0.6f, 0.15f);

        glVertex2f(-0.7f, 0.19f);
        glVertex2f(-0.65f, 0.21f);

        glVertex2f(-0.65f, 0.21f);
        glVertex2f(-0.6f, 0.11f);

    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(-0.67f, 0.645f);
        glVertex2f(-0.67f, 0.0f);

        glVertex2f(-0.68f, 0.64f);
        glVertex2f(-0.68f, 0.0f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.8f, 1.0f, 1.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, 0.63f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(-0.65f, 0.65f);
        glVertex2f(-0.65f, 0.0f);

        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.8f, 1.0f, 1.0f);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.6f, 0.55f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(-0.65f, 0.65f);
        glVertex2f(-0.65f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, 0.63f);

        glVertex2f(0.65f, 0.0f);
        glVertex2f(0.65f, 0.65f);

        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.6f, 0.55f);

        glVertex2f(0.7f, 0.63f);
        glVertex2f(0.65f, 0.65f);

        glVertex2f(0.65f, 0.65f);
        glVertex2f(0.6f, 0.55f);

    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(0.7f, 0.59f);
        glVertex2f(0.65f, 0.61f);

        glVertex2f(0.65f, 0.61f);
        glVertex2f(0.6f, 0.51f);

        glVertex2f(0.7f, 0.55f);
        glVertex2f(0.65f, 0.57f);

        glVertex2f(0.65f, 0.57f);
        glVertex2f(0.6f, 0.47f);

        glVertex2f(0.7f, 0.51f);
        glVertex2f(0.65f, 0.53f);

        glVertex2f(0.65f, 0.53f);
        glVertex2f(0.6f, 0.43f);

        glVertex2f(0.7f, 0.47f);
        glVertex2f(0.65f, 0.49f);

        glVertex2f(0.65f, 0.49f);
        glVertex2f(0.6f, 0.39f);

        glVertex2f(0.7f, 0.43f);
        glVertex2f(0.65f, 0.45f);

        glVertex2f(0.65f, 0.45f);
        glVertex2f(0.6f, 0.35f);

        glVertex2f(0.7f, 0.39f);
        glVertex2f(0.65f, 0.41f);

        glVertex2f(0.65f, 0.41f);
        glVertex2f(0.6f, 0.31f);

        glVertex2f(0.7f, 0.35f);
        glVertex2f(0.65f, 0.37f);

        glVertex2f(0.65f, 0.37f);
        glVertex2f(0.6f, 0.27f);

        glVertex2f(0.7f, 0.31f);
        glVertex2f(0.65f, 0.33f);

        glVertex2f(0.65f, 0.33f);
        glVertex2f(0.6f, 0.23f);

        glVertex2f(0.7f, 0.27f);
        glVertex2f(0.65f, 0.29f);

        glVertex2f(0.65f, 0.29f);
        glVertex2f(0.6f, 0.19f);

        glVertex2f(0.7f, 0.23f);
        glVertex2f(0.65f, 0.25f);

        glVertex2f(0.65f, 0.25f);
        glVertex2f(0.6f, 0.15f);
        //-
        glVertex2f(0.7f, 0.19f);
        glVertex2f(0.65f, 0.21f);

        glVertex2f(0.65f, 0.21f);
        glVertex2f(0.6f, 0.11f);

    glEnd();


    //---||----//
    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(0.67f, 0.645f);
        glVertex2f(0.67f, 0.0f);

        glVertex2f(0.68f, 0.64f);
        glVertex2f(0.68f, 0.0f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.8f, 1.0f, 1.0f);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, 0.63f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.65f, 0.65f);
        glVertex2f(0.65f, 0.0f);

        glColor3ub(100, 160, 255);
        glColor4f(0.5f ,0.8f, 1.0f, 1.0f);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.6f, 0.55f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.65f, 0.65f);
        glVertex2f(0.65f, 0.0f);
    glEnd();
    //------------------------------------//

    //---- 9th building -------------//
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex2f(0.55f, 0.0f);
        glVertex2f(0.55f, 0.55f);

        glVertex2f(0.6f, 0.53f);
        glVertex2f(0.55f, 0.55f);

        glVertex2f(0.55f, 0.55f);
        glVertex2f(0.5f, 0.45f);

        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.45f);

    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(0.5f, 0.41f);
        glVertex2f(0.55f, 0.51f);

        glVertex2f(0.55f, 0.51f);
        glVertex2f(0.6f, 0.49f);
        //-
        glVertex2f(0.5f, 0.37f);
        glVertex2f(0.55f, 0.47f);

        glVertex2f(0.55f, 0.47f);
        glVertex2f(0.6f, 0.45f);
        //-
        glVertex2f(0.5f, 0.33f);
        glVertex2f(0.55f, 0.43f);

        glVertex2f(0.55f, 0.43f);
        glVertex2f(0.6f, 0.41f);
        //-
        glVertex2f(0.5f, 0.30f);
        glVertex2f(0.55f, 0.40f);

        glVertex2f(0.55f, 0.40f);
        glVertex2f(0.6f, 0.39f);
        //-
        glVertex2f(0.5f, 0.22f);
        glVertex2f(0.55f, 0.30f);

        glVertex2f(0.55f, 0.30f);
        glVertex2f(0.6f, 0.29f);
        //-
        glVertex2f(0.5f, 0.18f);
        glVertex2f(0.55f, 0.26f);

        glVertex2f(0.55f, 0.26f);
        glVertex2f(0.6f, 0.25f);
        //-
        glVertex2f(0.55f, 0.22f);
        glVertex2f(0.6f, 0.21f);
        //-
        glVertex2f(0.55f, 0.18f);
        glVertex2f(0.6f, 0.17f);


    glEnd();


    //---||----//
    glBegin(GL_LINES);
        glColor3f(0.5f, 0.6f, 0.6f);
        glVertex2f(0.57f, 0.55f);
        glVertex2f(0.57f, 0.0f);

        glVertex2f(0.58f, 0.535f);
        glVertex2f(0.58f, 0.0f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_QUADS);
        glColor3ub(100, 160, 255);
        glColor4f(1.0f ,1.0f, 0.6f, 1.0f);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.6f, 0.53f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.55f, 0.55f);
        glVertex2f(0.55f, 0.0f);

        glColor3ub(100, 160, 255);
        glColor4f(1.0f ,1.0f, 0.6f, 1.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.45f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(0.55f, 0.55f);
        glVertex2f(0.55f, 0.0f);
    glEnd();
    //------------------------------------//
}

void tree1()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f ,0.4f, 0.0f);//deep green
    glVertex2f(0.75f, -0.12f);
    glVertex2f(0.78f, 0.05f);
    glVertex2f(0.80f, -0.12f);

    glColor3f(0.0f ,0.4f, 0.0f);
    glVertex2f(0.78f, -0.12f);
    glVertex2f(0.80f, 0.0f);
    glVertex2f(0.82f, -0.12f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//middle
    DrawCircle(0.70, 0.40,0.06);
    DrawCircle(0.80, 0.40,0.06);
    DrawCircle(0.75, 0.45,0.06);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(0.67, 0.45,0.06);
    DrawCircle(0.82, 0.45,0.06);
    DrawCircle(0.75, 0.52,0.06);
    DrawCircle(0.82, 0.36,0.06);
    DrawCircle(0.68, 0.35,0.06);
    glEnd();

    glLineWidth(18.5);//middle
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(0.75f, -0.12f);
    glVertex2f(0.75f, 0.40f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//left
    DrawCircle(0.67, 0.28,0.06);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(0.65, 0.25,0.06);
    DrawCircle(0.64, 0.30,0.06);
    glEnd();

    glLineWidth(12.5);//left
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(0.75f, 0.22f);
    glVertex2f(0.70f, 0.27f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//right
    DrawCircle(0.82, 0.24,0.05);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(0.84, 0.26,0.05);
    DrawCircle(0.83, 0.21,0.05);

    glEnd();

    glLineWidth(12.5);//right
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.80f, 0.22f);
    glEnd();


    glFlush();

}
void tree2()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f ,0.4f, 0.0f);//deep green
    glVertex2f(0.0f, -0.15f);
    glVertex2f(0.03f, 0.05f);
    glVertex2f(0.05f, -0.15f);

    glColor3f(0.0f ,0.4f, 0.0f);
    glVertex2f(0.06f, 0.01f);
    glVertex2f(0.08f, -0.15f);
    glVertex2f(0.04f, -0.15f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//middle
    DrawCircle(-0.05, 0.50,0.07);
    DrawCircle(0.05, 0.50,0.07);
    DrawCircle(0.0, 0.55,0.07);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.09, 0.55,0.07);
    DrawCircle(0.0, 0.62,0.07);
    DrawCircle(0.08, 0.45,0.07);
    DrawCircle(0.08, 0.55,0.07);
    DrawCircle(-0.09, 0.45,0.07);
    glEnd();

    glLineWidth(18.5);//middle
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(0.0f, 0.50f);
    glVertex2f(0.0f, -0.15f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//left
    DrawCircle(-0.10, 0.34,0.07);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.14, 0.40,0.07);
    DrawCircle(-0.12, 0.30,0.07);
    glEnd();

    glLineWidth(12.5);//left
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(0.0f, 0.30f);
    glVertex2f(-0.1f, 0.38f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//right
    DrawCircle(0.10, 0.31,0.07);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(0.12, 0.26,0.07);
    DrawCircle(0.13, 0.35,0.07);

    glEnd();

    glLineWidth(12.5);//right
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(0.0f, 0.20f);
    glVertex2f(0.1f, 0.30f);
    glEnd();

    glFlush();

}
void tree3()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f ,0.4f, 0.0f);//deep green
    glVertex2f(-0.25f, -0.10f);
    glVertex2f(-0.23f, 0.02f);
    glVertex2f(-0.21f, -0.10f);

    glColor3f(0.0f ,0.4f, 0.0f);
    glVertex2f(-0.22f, -0.10f);
    glVertex2f(-0.205f, 0.0f);
    glVertex2f(-0.19f, -0.10f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//middle
    DrawCircle(-0.25, 0.27,0.05);
    DrawCircle(-0.28, 0.23,0.04);
    DrawCircle(-0.22, 0.23,0.04);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.29, 0.26,0.05);
    DrawCircle(-0.25, 0.29,0.05);
    DrawCircle(-0.22, 0.26,0.05);
    DrawCircle(-0.25, 0.32,0.05);
    glEnd();

    glLineWidth(18.5);//middle
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(-0.25f, 0.22f);
    glVertex2f(-0.25f, -0.10f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//left
    DrawCircle(-0.325, 0.17,0.05);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.34, 0.15,0.05);
    DrawCircle(-0.345, 0.19,0.05);
    glEnd();

    glLineWidth(12.5);//left
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(-0.25f, 0.12f);
    glVertex2f(-0.31f, 0.17f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//right
    DrawCircle(-0.175, 0.17,0.05);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.16, 0.15,0.05);
    DrawCircle(-0.15, 0.19,0.05);
    glEnd();

    glLineWidth(12.5);//right
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(-0.25f, 0.06f);
    glVertex2f(-0.18f, 0.15f);
    glEnd();

    glFlush();

}
void tree4()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f ,0.4f, 0.0f);//deep green
    glVertex2f(-0.75f, -0.12f);
    glVertex2f(-0.72f, 0.05f);
    glVertex2f(-0.70f, -0.12f);

    glColor3f(0.0f ,0.4f, 0.0f);
    glVertex2f(-0.72f, -0.12f);
    glVertex2f(-0.70f, 0.0f);
    glVertex2f(-0.68f, -0.12f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//middle
    DrawCircle(-0.70, 0.40,0.06);
    DrawCircle(-0.80, 0.40,0.06);
    DrawCircle(-0.75, 0.45,0.06);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.67, 0.45,0.06);
    DrawCircle(-0.82, 0.45,0.06);
    DrawCircle(-0.75, 0.52,0.06);
    DrawCircle(-0.82, 0.36,0.06);
    DrawCircle(-0.68, 0.35,0.06);
    glEnd();

    glLineWidth(18.5);//middle
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(-0.75f, -0.12f);
    glVertex2f(-0.75f, 0.40f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//left
    DrawCircle(-0.83, 0.28,0.06);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.85, 0.25,0.06);
    DrawCircle(-0.86, 0.30,0.06);
    glEnd();

    glLineWidth(12.5);//left
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(-0.75f, 0.22f);
    glVertex2f(-0.80f, 0.27f);
    glEnd();

    glColor3f(0.2f ,0.5f, 0.1f);//right
    DrawCircle(-0.68, 0.23,0.05);
    glColor3f(0.2f ,0.4f, 0.0f);
    DrawCircle(-0.66, 0.25,0.05);
    DrawCircle(-0.67, 0.20,0.05);

    glEnd();

    glLineWidth(12.5);//right
    glBegin(GL_LINES);
    glColor3f(0.3f ,0.0f, 0.0f);
    glVertex2f(-0.75f, 0.15f);
    glVertex2f(-0.70f, 0.22f);
    glEnd();


    glFlush();

}

void allTrees() // all trees scaling
{
    tree1();
    tree2();
    tree3();
    tree4();

    glFlush();
}

void greenfield()
{
        glBegin(GL_QUADS);
        glColor3f(0.2f, 0.6f, 0.1f);  // light green
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, -0.20f);
        glVertex2f(-1.0f, -0.20f);
        glEnd();

        glColor3f(0.2f, 0.6f, 0.1f);
        //middle left
        DrawCircle(0.60, 0.01,0.07);
        DrawCircle(0.51, 0.0,0.07);
        DrawCircle(0.54, 0.08,0.05);
        //middle right
        DrawCircle(-0.60, 0.01,0.07);
        DrawCircle(-0.51, 0.0,0.07);
        DrawCircle(-0.54, 0.08,0.05);
        //left side
        DrawCircle(-1.0, 0.02,0.07);
        DrawCircle(-0.90, 0.02,0.07);
        DrawCircle(-0.95, 0.1,0.05);
        //middle
        DrawCircle(0.0, -0.03,0.09);
        DrawCircle(-0.1, -0.045,0.09);
        //right side
        DrawCircle(1.0, 0.02,0.07);
        DrawCircle(0.90, 0.02,0.07);
        DrawCircle(0.90, 0.1,0.05);
        DrawCircle(0.96, 0.12,0.05);
        DrawCircle(0.93, 0.15,0.05);
        DrawCircle(0.93, 0.20,0.03);

        glEnd();

}

void vrain()
{

    float x=-1.0;
    float temp=0.9;
    for (int j=0;j<20;j++)
    {
        float y=temp;
        for (int l=0;l<30;l++)
        {
            glPushMatrix();
            glTranslatef(rainPosX,rainPos,0.0f);
            glBegin(GL_LINES);
            glColor3ub(222, 222, 222);
            glVertex2f(x,y);
            x+=.05;
            y+=.1;
            glVertex2f(x,y);
            glEnd();
            y=temp;
            x=x+.1;
            glPopMatrix();
        }
        temp-=.2;x=-1;
    }
}

void busstop()
{
    glBegin(GL_QUADS);
        glColor3f(138, 0, 0);  // roof
        glVertex2f(0.25f, 0.4f);
        glVertex2f(0.85f, 0.4f);
        glVertex2f(0.85f, 0.3f);
        glVertex2f(0.25f, 0.3f);
    glEnd();

    glLineWidth(16.0f);
    glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0); // under roof // orange
        glVertex2f(0.23f, 0.28f);
        glVertex2f(0.87f, 0.28f);
    glEnd();



    glLineWidth(16.0f);
    glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0); // left stand
        glVertex2f(0.3f, 0.28f);
        glVertex2f(0.3f, -0.20f);
    glEnd();

    glLineWidth(16.0f);
    glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0); // right stand
        glVertex2f(0.8f, 0.28f);
        glVertex2f(0.8f, -0.20f);
    glEnd();

    // --------------left seat starts-----------

    glBegin(GL_QUADS);
        glColor3f(138, 0, 0);  // back middle red part
        glVertex2f(0.33f, 0.07f);
        glVertex2f(0.45f, 0.07f);
        glVertex2f(0.45f, -0.025f);
        glVertex2f(0.33f, -0.025f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1); // back part
        glVertex2f(0.3f, 0.1f);
        glVertex2f(0.47f, 0.1f);
        glVertex2f(0.47f, -.05f);
        glVertex2f(0.3f, -0.05f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); // seat line x axis
        glVertex2f(0.3f, -0.05f);
        glVertex2f(0.47f, -0.05f);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); // seat line y axis
        glVertex2f(0.47f, -0.05f);
        glVertex2f(0.49f, -0.08f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); // divide line
        glVertex2f(0.47f, 0.1f);
        glVertex2f(0.47f, -.05f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1);  // below part
        glVertex2f(0.3f, -0.05f);
        glVertex2f(0.47f, -0.05f);
        glVertex2f(0.49f, -0.08f);
        glVertex2f(0.32f, -0.08f);
    glEnd();

    // --------------left seat ends-----------

    // --------------middle seat starts-----------

    glBegin(GL_QUADS);
        glColor3f(138, 0, 0);  // back middle red part
        glVertex2f(0.49f, 0.07f);
        glVertex2f(0.62f, 0.07f);
        glVertex2f(0.62f, -0.025f);
        glVertex2f(0.49f, -0.025f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1);  // back part
        glVertex2f(0.47f, 0.1f);
        glVertex2f(0.64f, 0.1f);
        glVertex2f(0.64f, -.05f);
        glVertex2f(0.47f, -0.05f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); // seat line x axis
        glVertex2f(0.47f, -0.05f);
        glVertex2f(0.64f, -.05f);
    glEnd();

   glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); // seat line y axis
        glVertex2f(0.64f, -.05f);
        glVertex2f(0.66f, -0.08f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1); // below part
        glVertex2f(0.47f, -0.05f);
        glVertex2f(0.64f, -.05f);
        glVertex2f(0.66f, -0.08f);
        glVertex2f(0.49f, -0.08f);
    glEnd();

    // --------------middle seat ends-----------

    // --------------right seat starts-----------

    glBegin(GL_QUADS);
        glColor3f(138, 0, 0);  // back middle red part
        glVertex2f(0.66f, 0.07f);
        glVertex2f(0.78f, 0.07f);
        glVertex2f(0.78f, -0.025f);
        glVertex2f(0.66f, -0.025f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1);  // back part
        glVertex2f(0.643f, 0.1f);
        glVertex2f(0.8f, 0.1f);
        glVertex2f(0.8f, -0.05f);
        glVertex2f(0.643f, -.05f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); //divide line
        glVertex2f(0.64f, 0.1f);
        glVertex2f(0.64f, -.05f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f ,0.1f, 0.4f); // seat line x axis
        glVertex2f(0.643f, -.05f);
        glVertex2f(0.8f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,1);  // below part
        glVertex2f(0.643f, -.05f);
        glVertex2f(0.8f, -0.05f);
        glVertex2f(0.82f, -0.08f);
        glVertex2f(0.66f, -0.08f);
    glEnd();

    // --------------right seat ends-----------
}

//lamppost

void nlamp()
{
        glColor3f(1.0f, 1.0f, 0.0f); //light circle left
        DrawCircle(0.78, 0.52,0.02);



        glColor3f(1.0f, 1.0f, 0.0f); //light circle middle
        DrawCircle(0.82, 0.52,0.02);



        glColor3f(1.0f, 1.0f, 0.0f); //light circle right
        DrawCircle(0.86, 0.52,0.02);



        glBegin(GL_QUADS);
        glColor3ub(255, 235, 153);
        glVertex2f(0.76f, 0.5f);
        glVertex2f(0.88f, 0.5f);
        glColor3f(0.33f ,0.33f, 0.33f);
        glVertex2f(0.9f, 0.4f);
        glVertex2f(0.73f, 0.4f);
        glEnd();
}
void lamppost()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 0.0f); //lamp low
        glVertex2f(0.9, -0.1);
        glVertex2f(0.92f, -0.2f);
        glVertex2f(0.88f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 0.0f); //lamp low
        glVertex2f(0.9, -0.14);
        glVertex2f(0.92f, -0.03f);
        glVertex2f(0.88f, -0.03f);
    glEnd();

    glLineWidth(14.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.4f, 0.5f);   //stand y axis
        glVertex2f(0.9f, -0.03f);
	    glVertex2f(0.9f, 0.6f);
    glEnd();

    glColor3f(0.0f, 0.4f, 0.5f);  //stand circle
    DrawCircle(0.9, 0.61,0.02);

    glLineWidth(18.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.4f, 0.5f);    //stand x axis
        glVertex2f(0.9f, 0.55f);
	    glVertex2f(0.75f, 0.55f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); //light circle left
    DrawCircle(0.78, 0.52,0.02);

    glColor3f(1.0f, 1.0f, 1.0f); //light circle middle
    DrawCircle(0.82, 0.52,0.02);

    glColor3f(1.0f, 1.0f, 1.0f); //light circle right
    DrawCircle(0.86, 0.52,0.02);
}

void human()
{
    //******************sitting human starts**********

     glColor3f(0.0f, 0.0f, 0.0f); //left eye
     DrawCircle(0.709, 0.1,0.004);

     glColor3f(0.0f, 0.0f, 0.0f); //right eye
     DrawCircle(0.731, 0.1,0.004);

     glColor3f(0.9f, 0.6f, 0.4f); //face
     DrawCircle(0.72, 0.1,0.03);

     glColor3f(0.9f, 0.6f, 0.4f); //neck
     DrawCircle(0.72, 0.07,0.02);

     glColor3f(0.0f, 0.0f, 0.0f); //hair
     DrawCircle(0.72, 0.12,0.03);

    // **** left paper*******

    glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); //  paper border 1
         glVertex2f(0.652f, 0.06f);
	    glVertex2f(0.72f, 0.03f);
    glEnd();

    glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  paper border 2
        glVertex2f(0.72f, 0.03f);
	    glVertex2f(0.78f, 0.06f);
    glEnd();

    glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  paper border 3
        glVertex2f(0.78f, 0.06f);
	    glVertex2f(0.78f, -0.06f);
    glEnd();

    glLineWidth(3.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  paper border 4
        glVertex2f(0.72f, -0.1f);
        glVertex2f(0.78f, -0.06f);

    glEnd();

    glLineWidth(3.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  paper border 5
        glVertex2f(0.652f, -0.06f);
	    glVertex2f(0.72f, -0.1f);
    glEnd();

    glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  paper border 6
        glVertex2f(0.652f, 0.06f);
	    glVertex2f(0.652f, -0.065f);
    glEnd();

    glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  divide paper
        glVertex2f(0.72f, 0.03f);
	    glVertex2f(0.72f, -0.1f);
    glEnd();

    glLineWidth(1.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  right paper line 1
        glVertex2f(0.73f, 0.01f);
	    glVertex2f(0.77f, 0.03f);
    glEnd();

    glLineWidth(1.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  right paper line 2
        glVertex2f(0.73f, -0.01f);
	    glVertex2f(0.77f, 0.01);
    glEnd();

    glLineWidth(1.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  left paper line 1
        glVertex2f(0.66f, -0.01f);
	    glVertex2f(0.7f, -0.03f);
    glEnd();

    glLineWidth(1.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //  left paper line 2
        glVertex2f(0.66f, -0.03f);
	    glVertex2f(0.7f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.9f, 1.0f); // left paper
        glVertex2f(0.652f, 0.06f);
	    glVertex2f(0.72f, 0.03f);
	    glVertex2f(0.72f, -0.1f);
	    glVertex2f(0.652f, -0.06f);
    glEnd();

// **** right paper*******
    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.9f, 1.0f); // right paper
        glVertex2f(0.72f, 0.03f);
        glVertex2f(0.78f, 0.06f);
	    glVertex2f(0.78f, -0.06f);
	    glVertex2f(0.72f, -0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f); //body // Green
        glVertex2f(0.72, 0.1);
        glVertex2f(0.78f, 0.03f);
        glVertex2f(0.65f, 0.03f);
    glEnd();

 //******************right leg start**********
    glLineWidth(14.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // right leg
        glVertex2f(0.75f, -0.06f);
        glVertex2f(0.75f, -0.2f);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.1f); //right foot
    DrawCircle(0.75, -0.21,0.012);

    glColor3f(0.6f, 0.3f, 0.1f); //right foot
    DrawCircle(0.75, -0.225,0.011);

    glColor3f(0.6f, 0.3f, 0.1f); //right foot
    DrawCircle(0.75, -0.23,0.01);

    //******************right leg end**********

    //******************left leg starts**********

   glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 0.0f); // left thigh
        glVertex2f(0.7f, -0.08f);
        glVertex2f(0.69f, -0.12f);
        glVertex2f(0.66f, -0.06f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 0.0f); //left leg
        glVertex2f(0.7f, -0.08f);
        glVertex2f(0.76f, -0.09f);
        glVertex2f(0.69f, -0.12f);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.1f); //left foot
    DrawCircle(0.78, -0.16,0.012);

    glColor3f(0.6f, 0.3f, 0.1f); //right foot
    DrawCircle(0.79, -0.16,0.011);

    glLineWidth(14.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // left leg
        glVertex2f(0.75f, -0.07f);
        glVertex2f(0.775f, -0.16f);
    glEnd();

    //******************left leg ends**********

    //******************sitting human ends**********

    //******************standing human starts**********

    glLineWidth(3.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // sun glass frame
        glVertex2f(0.17f, 0.11f);
        glVertex2f(0.23f, 0.11f);
    glEnd();

     glColor3f(0.0f, 0.0f, 0.0f); //left sun glass
     DrawCircle(0.185, 0.1,0.01);

     glColor3f(0.0f, 0.0f, 0.0f); //right sun glass
     DrawCircle(0.215, 0.1,0.01);

     glColor3f(1.0f, 1.0f, 0.6f); //face
     DrawCircle(0.2, 0.1, 0.03);

     glColor3f(1.0f, 1.0f, 0.6f); //neck
     DrawCircle(0.2, 0.07,0.02);

     glColor3f(0.0f, 0.0f, 0.0f); //hair
     DrawCircle(0.2, 0.12, 0.03);

     glBegin(GL_TRIANGLES);
        glColor3f(0.7f ,0.2f, 0.9f); //body // chest
        glVertex2f(0.2, 0.1);
        glVertex2f(0.252f, 0.0f);
        glVertex2f(0.148f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.7f ,0.2f, 0.9f);  //body // belly
        glVertex2f(0.165f, 0.0f);
        glVertex2f(0.235f, 0.0f);
        glVertex2f(0.235f, -0.12f);
        glVertex2f(0.165f, -0.12f);
    glEnd();

    glLineWidth(14.0f);
    glBegin(GL_LINES);
        glColor3f(0.7f ,0.2f, 0.9f); // left hand upper //purple
        glVertex2f(0.156f, 0.0f);
        glVertex2f(0.156f, -0.02f);
    glEnd();

    glLineWidth(14.0f);
    glBegin(GL_LINES);
        glColor3f(0.7f ,0.2f, 0.9f); // right hand upper //purple
        glVertex2f(0.244f, 0.0f);
        glVertex2f(0.244f, -0.02f);
    glEnd();

    glLineWidth(12.5f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.6f); // left hand upper
        glVertex2f(0.14f, -0.05f);
        glVertex2f(0.17f, -0.01f);

    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.6f); // left hand lower
        glVertex2f(0.14f, -0.05f);
        glVertex2f(0.17f, -0.07f);
    glEnd();

    glLineWidth(12.5f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.6f); // right hand upper
        glVertex2f(0.23f, -0.01f);
        glVertex2f(0.26f, -0.05f);

    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.6f); // right hand lower
        glVertex2f(0.26f, -0.05f);
        glVertex2f(0.23f, -0.07f);
    glEnd();

    glLineWidth(14.0f);
    glBegin(GL_LINES);
        glColor3f(0.6f, 0.3f, 0.1f); // right leg
        glVertex2f(0.22f, -0.11f);
        glVertex2f(0.22f, -0.24f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); //right foot
    DrawCircle(0.22, -0.265,0.011);

    glColor3f(0.0f, 0.0f, 0.0f); //right foot
    DrawCircle(0.22, -0.25,0.011);

    glLineWidth(14.0f);
    glBegin(GL_LINES);
        glColor3f(0.6f, 0.3f, 0.1f); // left leg
        glVertex2f(0.18f, -0.11f);
        glVertex2f(0.18f, -0.24f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); //left foot
    DrawCircle(0.18, -0.25, 0.011);

    glColor3f(0.0f, 0.0f, 0.0f); //left foot
    DrawCircle(0.18, -0.265, 0.011);

    //******************standing human ends**********
}


//rain Start---------------


void cloudrain1()
{

    glPushMatrix();
    glTranslatef(positionOfCloud2, 0.05f, 0.0f);

        int i;

        GLfloat x=-.5f; GLfloat y=.84f; GLfloat radius =.05f;
        int triangleAmount = 20;
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(96, 96, 96);
            glVertex2f(x, y); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat a=-.55f; GLfloat b=.81f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(a, b); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        a + (radius * cos(i *  twicePi / triangleAmount)),
                    b + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat c=-.45f; GLfloat d=.81f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(c, d); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        c + (radius * cos(i *  twicePi / triangleAmount)),
                    d + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat e=-.52f; GLfloat f=.78f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(e, f); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        e + (radius * cos(i *  twicePi / triangleAmount)),
                    f+ (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat g=-.6f; GLfloat h=.80f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(g, h); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        g + (radius * cos(i *  twicePi / triangleAmount)),
                    h+ (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();
    glPopMatrix();
}
void cloudrain2()
{
    glPushMatrix();
    glTranslatef(positionOfCloud, 0.05f, 0.0f);
        int i;

        GLfloat x=.5f; GLfloat y=.90f; GLfloat radius =.05f;
        int triangleAmount = 20;
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(96, 96, 96);
            glVertex2f(x, y); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat a=.55f; GLfloat b=.87f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(a, b); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        a + (radius * cos(i *  twicePi / triangleAmount)),
                    b + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat c=.45f; GLfloat d=.87f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(c, d); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        c + (radius * cos(i *  twicePi / triangleAmount)),
                    d + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat e=.52f; GLfloat f=.84f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(e, f); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        e + (radius * cos(i *  twicePi / triangleAmount)),
                    f+ (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        GLfloat g=.6f; GLfloat h=.86f;

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(g, h); // center of circle
            for(i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        g + (radius * cos(i *  twicePi / triangleAmount)),
                    h+ (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();
    glPopMatrix();
}
void rainsky()
{
    glBegin(GL_QUADS);
        glColor3ub(128, 128, 128);
        //glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(1.0, 0.15);
        glVertex2f(-1.0, 0.15);
        glColor3ub(64, 64, 64);
        //glColor4f(0.4f, 0.8f, 1.0f, 1.0f);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);
    glEnd();

}

//rain ends---------------


void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //--- day view ---//
    glPushMatrix();
        if(day)
        {
            glPushMatrix();
            glTranslatef(cngposition,0.0f, 0.0f);
            cng();
            glPopMatrix();
            glPushMatrix();
            glTranslatef(busposition,0.0f, 0.0f);
            bus();
            glPopMatrix();
            human();
            busstop();
            lamppost();
            allTrees();
            greenfield();
            glPushMatrix();
            glTranslatef(boatposition,0.0f, 0.0f);
            boat();
            glPopMatrix();
            dayriver();
            sidewalk();
            road();
            buildings();
            cloud2();
            cloud1();
            sun();
            daysky();

        }
    glPopMatrix();
    //--------------------------//

    //----- night view ---------//
    glPushMatrix();
        if(night)
        {
            glPushMatrix();
            glTranslatef(cngposition,0.0f, 0.0f);
            ncng();
            cng();
            glPopMatrix();
            glPushMatrix();
            glTranslatef(busposition,0.0f, 0.0f);
            nbus();
            bus();
            glPopMatrix();
            human();
            busstop();
            lamppost();
            nlamp();
            allTrees();
            greenfield();
            glPushMatrix();
            glTranslatef(boatposition,0.0f, 0.0f);
            boat();
            glPopMatrix();
            nightriver();
            sidewalk();
            road();
            buildings();
            moon();
            stars();
            nightsky();
        }
    glPopMatrix();

    //------rain view start-----
    glPushMatrix();
        if(rain)
        {
            glPushMatrix();
            vrain();
            glTranslatef(cngposition,0.0f, 0.0f);
            ncng();
            cng();
            glPopMatrix();
            glPushMatrix();
            glTranslatef(busposition,0.0f, 0.0f);
            nbus();
            bus();
            glPopMatrix();
            //human();
            busstop();
            lamppost();
            allTrees();
            greenfield();
            nightriver();
            sidewalk();
            road();
            buildings();
            cloudrain1();
            cloudrain2();
            rainsky();
        }
    glPopMatrix();
	glutSwapBuffers();
	glFlush();
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key)
	{
        case 'a':
            busspeed = 0.0f;
            PlaySound(TEXT("door.wav"), NULL, SND_ASYNC);
            break;

        case 's':
            Speed9 = 0.0f;
            break;

        case 'w':
            busspeed = 0.05f;
            break;

        case 'd':
            day=true;
            night=false;
            break;

        case 'n':
            night=true;
            day=false;
            PlaySound(TEXT("cricket-2.wav"), NULL, SND_ASYNC);
            break;

        case 'x':
            exit(0);
            break;
            break;
        case 'r':
            night=false;
            day=false;
            rain=true;
            PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);


            break;
        glutPostRedisplay();
	}
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    cout<<"\n **** WELCOME TO Roadside View of a City ****\n";
    cout<<"\n >> Press 'D' for Day mode <<";
    cout<<"\n >> Press 'N' for Night mode <<";
    cout<<"\n >> Press 'R' for Raining mode <<";
    cout<<"\n >> Press 'A' for Stopping bus <<";
    cout<<"\n >> Press 'W' for Moving bus <<";
    cout<<"\n >> Press 'S' for Stopping Sun <<";
    cout<<"\n >> Press 'X' for Exit <<";

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1600, 900);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Roadside View of a City");
    glutDisplayFunc(myDisplay);
    init();
    glutTimerFunc(100, bus, 0);
    glutTimerFunc(100, cng, 0);
    glutTimerFunc(100, boat, 0);
    glutTimerFunc(100, update5, 0);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutKeyboardFunc(handleKeypress);
    PlaySound(TEXT("bus.wav"), NULL, SND_ASYNC);
    glutMainLoop();
    return 0;
}
