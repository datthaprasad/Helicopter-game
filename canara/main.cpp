#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<time.h>
#include<stdio.h>


float bspd=0.02;

char name[25];

float b1x=95,b1y=25,X=5,Y=35;

float hm=0.0;

int i=0,sci=1;float scf=1;

char scs[20],slevel[20];


int level=1,lflag=1,wflag=1,win_id,win_id2,fireflag=0,submenu,submenu2,option,option1,option2;
float color[3]={1.0,1.0,1.0};
float a[3]={0.5,0.5,0.5};//gray
float b[3]={0.5,1.0,1.0};//cyan
float c[3]={1.0,0.5,0.0};//orange/brown
float d[3]={1.0,1.0,1.0};//white

void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glLoadIdentity ();
glOrtho(0.0, 100.0, 0.0, 100.0, -1.0 , 0.0);

}

void drawcopter()
{
glColor3fv(color);
glRectf(10,50,20,45);//body
glRectf(2,46,10,48);//tail
glRectf(2,46,4,51);//tail up
glRectf(14,50,16,53);//propeller stand
glRectf(7,54,23,53);//propeller
glColor3f(0.0,0.0,0.0);
glPointSize(6.0);
glBegin(GL_POINTS);
glVertex2f(19.0,48.0);
glEnd();


}
/*
void drawcopter1()
{
glColor3f(1.0,1.0,1.0);
glRectf(10,30,20,25);//body
glRectf(2,26,10,28);//tail
glRectf(2,26,4,31);//tail up
glRectf(14,30,16,33);//propeller stand
glRectf(7,34,23,33);//propeller
//glColor3f(0.0,0.0,0.0);
glPointSize(6.0);
glBegin(GL_POINTS);
glVertex2f(19.0,48.0);
//glEnd();


}*/
void renderBitmapString(float x,float y,float z,void *font,char*string)
{

char *c;
glRasterPos3f(x, y,z);

for(c=string; *c != '\0'; c++)
{
glutBitmapCharacter(font, *c);
}
}


void help()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1,0.1,0.7);
    glRectf(0.0,0.0,600.0,500.0);
    glColor3f(1.0,1.0,0.0);
    renderBitmapString(35,92,0,GLUT_BITMAP_TIMES_ROMAN_24,"USER MANUAL");
    glColor3f(1.0,1.0,1.0);
    renderBitmapString(03,85,0,GLUT_BITMAP_8_BY_13,"'HELICOPTER GAME' in this game score will be increasing as time goes on.");
    renderBitmapString(03,81,0,GLUT_BITMAP_8_BY_13,"On every increse 50 in the score you can enter into new level.In each ");
    renderBitmapString(03,77,0,GLUT_BITMAP_8_BY_13,"level block speed will increases. ");
     glColor3f(1.0,0.0,1.0);
    renderBitmapString(3,70,0,GLUT_BITMAP_HELVETICA_18,"MOUSE INTERACTION");
     glColor3f(1.0,1.0,1.0);
    renderBitmapString(03,65,0,GLUT_BITMAP_HELVETICA_12,"1.CLICK LEFT MOUSE BUTTON TO START.");
    renderBitmapString(03,60,0,GLUT_BITMAP_HELVETICA_12,"2.CLICK AND HOLD LEFT MOUSE BUTTON TO MOVE HELICOPTER UP.");
    renderBitmapString(03,55,0,GLUT_BITMAP_HELVETICA_12,"3.RELEASE LEFT MOUSE BUTTON TO MOVE HELICOPTER DOWN.");
    renderBitmapString(03,50,0,GLUT_BITMAP_HELVETICA_12,"3.CLICK RIGHT MOUSE BUTTON TO GET MENUS.");

    glColor3f(1.0,0.0,1.0);
    renderBitmapString(3,40,0,GLUT_BITMAP_HELVETICA_18,"KEYBOARD INTERACTION");
     glColor3f(1.0,1.0,1.0);
    renderBitmapString(03,35,0,GLUT_BITMAP_HELVETICA_12,"1.PRESS ' h ' TO GET HELP WINDOW.");
    renderBitmapString(03,30,0,GLUT_BITMAP_HELVETICA_12,"2.PRESS ' i ' TO ICONIFY WINDOW.");
    renderBitmapString(03,25,0,GLUT_BITMAP_HELVETICA_12,"3.PRESS ' ESC ' TO CLOSE THE WINDOW.");
    //renderBitmapString(03,20,0,GLUT_BITMAP_HELVETICA_12,"3.CLICK RIGHT MOUSE BUTTON TO GET MENUS.");

    glutPostRedisplay();
    glutSwapBuffers();
    glutMainLoop();

}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);

if((i==730||i==-700)||((b1x<23&&b1x>20) &&b1y<53+hm && b1y+Y>53+hm)||((b1x<20&&b1x>10) && b1y<45+hm && b1y+Y>45+hm)||((b1x<10&&b1x>2) &&b1y<46+hm && b1y+Y>46+hm))
//top and bottom checking           propeller front checking                  lower body checking                            lower tail checking
{


glColor3f(0.6,0.6,0.8);
glRectf(0.0,0.0,100.0,100.0);
glColor3f(1.0,0.0,0.0);
renderBitmapString(37,70,0,GLUT_BITMAP_HELVETICA_18,"GAME OVER!!!");
renderBitmapString(35,60,0,GLUT_BITMAP_HELVETICA_18,"CONGRATULATIONS!!!");
glColor3f(1.0,1.0,1.0);
renderBitmapString(35,55,0,GLUT_BITMAP_TIMES_ROMAN_24,"You");
renderBitmapString(42,55,0,GLUT_BITMAP_TIMES_ROMAN_24,"scored:");
renderBitmapString(50,55,0,GLUT_BITMAP_TIMES_ROMAN_24,scs);
glutPostRedisplay();
glutSwapBuffers();
glutMainLoop();

}

else if(wflag==1)//Welcome Screen
{

wflag=0;

glColor3f(0.6,0.6,0.8);
glRectf(0.0,0.0,100.0,10.0);//floor
glRectf(0.0,100.0,100.0,90.0);//ceil

glColor3f(1.0,1.0,1.0);
renderBitmapString(35,85,0,GLUT_BITMAP_TIMES_ROMAN_24,"CANARA ENGINEERING COLLEGE ");

glColor3f(1.0,1.0,0.0);
renderBitmapString(32,75,0,GLUT_BITMAP_8_BY_13,"MINI PROJECT ON COMPUTER GRAPHICS AND VISUALISATION LABORATORY");
renderBitmapString(40,70,0,GLUT_BITMAP_TIMES_ROMAN_24,"HELICOPTER GAME");

glColor3f(1.0,0.0,0.0);
renderBitmapString(45,60,0,GLUT_BITMAP_TIMES_ROMAN_24,"WELCOME");
glColor3f(1.0,0.0,1.0);
renderBitmapString(45,45,0,GLUT_BITMAP_TIMES_ROMAN_24,"Click To Start");
renderBitmapString(30,40,0,GLUT_BITMAP_9_BY_15,"CLICK AND HOLD LEFT MOUSE BUTTON TO GO UP RELEASE TO GO DOWN");

drawcopter();
//drawcopter1();
glutSwapBuffers();


}

else
{

if(sci%50==0&&lflag==1)
{
lflag=0;
level++;
bspd+=0.01;
}


else if(sci%50!=0&&lflag!=1)
{
lflag=1;
}

glPushMatrix();

glColor3f(0.6,0.6,0.8);
glRectf(0.0,0.0,100.0,10.0);      //ceil
glRectf(0.0,100.0,100.0,90.0);    //floor

glColor3f(0.0,0.0,0.0);   //score
renderBitmapString(1,3,0,GLUT_BITMAP_TIMES_ROMAN_24,"Distance:");
//glColor3f(0.7,0.7,0.7);

sprintf(slevel,"%d",level);   //level
renderBitmapString(80,3,0,GLUT_BITMAP_TIMES_ROMAN_24,"Level:");
renderBitmapString(93,3,0,GLUT_BITMAP_TIMES_ROMAN_24,slevel);

scf+=0.025;
sci=(int)scf;
sprintf(scs,"%d",sci);


renderBitmapString(20,3,0,GLUT_BITMAP_TIMES_ROMAN_24,scs);

glTranslatef(0.0,hm,0.0);


drawcopter();

/*glPushMatrix();
glTranslatef(0.0,hm,0.0);
drawcopter1();
glPopMatrix();*/



if(b1x<-10)
{

b1x=95;
b1y=(rand()%25)+20;
//10 for selling+10 for giving enough space
// block bottom limit 0+20 & top limit 24+20=44

}

else
b1x-=bspd;

glColor3f(1.0,0.0,0.0);
glTranslatef(0.0,-hm,0.0);

glRectf(b1x,b1y,b1x+X,b1y+Y);//block 1

glPopMatrix();
glutPostRedisplay();
glutSwapBuffers();




}

}

void colorchange(int option)
{

     if(option==1)
        {color[0]=a[0];
         color[1]=a[1];
          color[2]=a[2];
        }
    if(option==2)
        {color[0]=b[0];
         color[1]=b[1];
          color[2]=b[2];
        }
    if(option==3)
        {color[0]=c[0];
         color[1]=c[1];
          color[2]=c[2];
        }
    if(option==4)
        {color[0]=d[0];
         color[1]=d[1];
          color[2]=d[2];
        }
        if(wflag==0)
               wflag=1;
        display();

}

void levelchange(int option)
{

     if(option==1)
        {
            bspd=0.01;
            X=4;
            Y=32;
        }
    if(option==2)
        {
             bspd=0.02;
            X=5;
            Y=35;
        }
    if(option==3)
        {
            bspd=0.03;
            X=6;
            Y=40;
        }

        if(wflag==0)
               wflag=1;
        display();

}


void keys(unsigned char key,int x,int y);

void menu(int option)
{
    if(option==1)
    {

        glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize (600, 500);
        glutInitWindowPosition (500,100);
        //win_id2=glutCreateSubWindow(win_id,0,0,500,500);
        //init();
        win_id=glutCreateWindow("HELP");
        init();
        glutDisplayFunc(help);
         glutKeyboardFunc(keys);
    }

    if(option==2)
    {

        colorchange(option1);

    }
     if(option==3)
    {

        levelchange(option2);

    }
    if(option==4)
        glutDestroyWindow(win_id);

      display();
}

void moveHeliU(void)
{

hm+=0.05;
i++;
glutPostRedisplay();

}

void moveHeliD()
{

hm-=0.05;
i--;
glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)



{


if (button==GLUT_LEFT_BUTTON&&state == GLUT_DOWN)
     glutIdleFunc(moveHeliU);
 if (button==GLUT_LEFT_BUTTON&&state == GLUT_UP)
      glutIdleFunc(moveHeliD);

}


void keys(unsigned char key,int x,int y)
{

        if(key=='h')
            { glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
                glutInitWindowSize (600, 500);
                glutInitWindowPosition (500,100);
                //win_id2=glutCreateSubWindow(win_id,0,0,500,500);
                //init();
                win_id=glutCreateWindow("HELP");
                init();
                glutDisplayFunc(help);
                 glutKeyboardFunc(keys);
            }

        if(key==27) glutDestroyWindow(win_id);

        if(key=='i') glutIconifyWindow();


}

int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (1500, 700);
glutInitWindowPosition (0,0);
win_id=glutCreateWindow ("2D Copter Game");
init();
glutDisplayFunc(display);

submenu=glutCreateMenu(colorchange);
glutAddMenuEntry("GRAY",1);
glutAddMenuEntry("CYAN",2);
glutAddMenuEntry("ORANGE",3);
glutAddMenuEntry("WHITE",4);

submenu2=glutCreateMenu(levelchange);
glutAddMenuEntry("EASY",1);
glutAddMenuEntry("MEDIUM",2);
glutAddMenuEntry("HARD",3);

glutCreateMenu(menu);
glutAddMenuEntry("HELP",1);
glutAddSubMenu("HELICOPTER COLOR",submenu);
glutAddSubMenu("GAME LEVEL",submenu2);
glutAddMenuEntry("EXIT",4);
glutAttachMenu(GLUT_RIGHT_BUTTON);
 glutMouseFunc(mouse);
 glutKeyboardFunc(keys);
 glutMainLoop();
 return 0;

 }


