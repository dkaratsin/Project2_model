#include <stdlib.h>
#include <glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cmath>


#define M_PI 3.14159265358979323846
const int windowWidth = 1000, windowHeight = 1000;
int option = 0;
int cameraOption = 0;
int animation_angle = 0;

typedef struct treenode
{
    void (*f)();
    struct treenode* sibling;
    struct treenode* child;
} treenode;

treenode torso_node, neck_node, head_node,
fru_leg_node, frl_leg_node, fr_toe_node,
flu_leg_node, fll_leg_node, fl_toe_node,
bru_leg_node, brl_leg_node, br_toe_node,
blu_leg_node, bll_leg_node, bl_toe_node;

void reshape(int newWidth, int newHeight) {
    glutReshapeWindow(1000, 1000);
}

void idle(void) {
    if (option == 1 || option == 2 || option == 3) {
        if (animation_angle < 60) {
            animation_angle++;
        }
    }
    else {
        animation_angle = 0;
    }



    glutPostRedisplay();
}

void menu(int menuOption) {
    if (menuOption == 1) {
        option = 1;
        animation_angle = 0;
    }
    if (menuOption == 2) {
        option = 2;
        animation_angle = 0;
    }
    if (menuOption == 3) {
        option = 3;
        animation_angle = 0;
    }
    if (menuOption == 4) {
        option = 4;
    }
    if (menuOption == 5) {
        if (cameraOption == 1) {
            cameraOption = 0;
        }
        else {
            cameraOption = 1;
        }
        
    }
    glutPostRedisplay();
}



void torso() {

    if(option == 2){
        glRotated(-animation_angle, 1, 0, 0);
    }
    glColor3ub(255, 0, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 20, 20, 100, 10, 10);
    gluDeleteQuadric(quadObj);
}

void neck() {
    
    glColor3ub(0, 255, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    glTranslated(0, 10, 97);
    if (option == 3 ) {
        glRotated(-20+(0.7*animation_angle), 1.0, 0.0, 0.0);
    }
    else {
        glRotated(-20, 1.0, 0.0, 0.0);
    }
    gluCylinder(quadObj, 5, 5, 20, 10, 10);
    gluDeleteQuadric(quadObj);
    
}

void head() {
    glColor3ub(0, 0, 255);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, 0, 30);
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluSphere(quadObj,15,10,10);
    gluDeleteQuadric(quadObj);  
}

void fru_leg() {
    glColor3ub(0, 255, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    if (option == 1 || option == 2) {
        glTranslated(10, -15, 90);
        glRotated(90-(animation_angle/float(option)), 1.0, 0.0, 0.0);
    }
    else {
        glTranslated(10, -15, 90);
        glRotated(90, 1.0, 0.0, 0.0);
    }
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
    
}

void frl_leg() {
    glColor3ub(0, 0, 255);
    GLUquadricObj* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    glTranslated(0, 0, 30);
    if (option == 1 || option == 2) {
        glRotated((animation_angle), 1.0, 0.0, 0.0);
    }
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void fr_toe() {
    glColor3ub(255, 0, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, -4, 30);
    glRotated(90, -1, 0, 0);
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 20, 10, 10);
    gluDeleteQuadric(quadObj);
}

void flu_leg() {
    glColor3ub(0, 255, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    if (option == 2) {
        glTranslated(-10, -15, 90);
        glRotated(90 - (animation_angle / float(option)), 1.0, 0.0, 0.0);
    }
    else {
        glTranslated(-10, -15, 90);
        glRotated(90, 1.0, 0.0, 0.0);
    }    
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void fll_leg() {
    glColor3ub(0, 0, 255);
    GLUquadricObj* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    glTranslated(0, 0, 30);
    if (option == 2) {
        glRotated((animation_angle), 1.0, 0.0, 0.0);
    }
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void fl_toe() {
    glColor3ub(255, 0, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, -4, 30);
    glRotated(90, -1, 0, 0);
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 20, 10, 10);
    gluDeleteQuadric(quadObj);
}

void bru_leg() {
    glColor3ub(0, 255, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(10, -15, 5);
    if (option == 2) {
        glRotated(90 + animation_angle, 1.0, 0.0, 0.0);
    }
    else {
        glRotated(90, 1.0, 0.0, 0.0);
    }
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void brl_leg() {
    glColor3ub(0, 0, 255);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, 0, 30);

    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void br_toe() {
    glColor3ub(255, 0, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, -4, 30);
    glRotated(90, -1, 0, 0);
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 20, 10, 10);
    gluDeleteQuadric(quadObj);
}

void blu_leg() {
    glColor3ub(0, 255, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(-10, -15, 5);
    if (option == 2) {
        glRotated(90 + animation_angle, 1.0, 0.0, 0.0);
    }
    else {
        glRotated(90, 1.0, 0.0, 0.0);
    }
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void bll_leg() {
    glColor3ub(0, 0, 255);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, 0, 30);

    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 30, 10, 10);
    gluDeleteQuadric(quadObj);
}

void bl_toe() {
    glColor3ub(255, 0, 0);
    GLUquadricObj* quadObj = gluNewQuadric();
    glTranslated(0, -4, 30);
    glRotated(90, -1, 0, 0);
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluCylinder(quadObj, 4, 4, 20, 10, 10);
    gluDeleteQuadric(quadObj);
}



void myinit(void)
{
    glEnable(GL_DEPTH_TEST);

    torso_node.f = torso;
    torso_node.sibling = NULL;
    torso_node.child = &neck_node;

    neck_node.f = neck;
    neck_node.sibling = &fru_leg_node;
    neck_node.child = &head_node;

    head_node.f = head;
    head_node.sibling = NULL;
    head_node.child = NULL;

    fru_leg_node.f = fru_leg;
    fru_leg_node.sibling = &flu_leg_node;
    fru_leg_node.child = &frl_leg_node;

    frl_leg_node.f = frl_leg;
    frl_leg_node.sibling = NULL;
    frl_leg_node.child = &fr_toe_node;

    fr_toe_node.f = fr_toe;
    fr_toe_node.sibling = NULL;
    fr_toe_node.child = NULL;

    flu_leg_node.f = flu_leg;
    flu_leg_node.sibling = &bru_leg_node;
    flu_leg_node.child = &fll_leg_node;

    fll_leg_node.f = fll_leg;
    fll_leg_node.sibling = NULL;
    fll_leg_node.child = &fl_toe_node;

    fl_toe_node.f = fl_toe;
    fl_toe_node.sibling = NULL;
    fl_toe_node.child = NULL;

    bru_leg_node.f = bru_leg;
    bru_leg_node.sibling = &blu_leg_node;
    bru_leg_node.child = &brl_leg_node;

    brl_leg_node.f = brl_leg;
    brl_leg_node.sibling = NULL;
    brl_leg_node.child = &br_toe_node;

    br_toe_node.f = br_toe;
    br_toe_node.sibling = NULL;
    br_toe_node.child = NULL;

    blu_leg_node.f = blu_leg;
    blu_leg_node.sibling = NULL;
    blu_leg_node.child = &brl_leg_node;

    bll_leg_node.f = brl_leg;
    bll_leg_node.sibling = NULL;
    bll_leg_node.child = &bl_toe_node;

    bl_toe_node.f = br_toe;
    bl_toe_node.sibling = NULL;
    bl_toe_node.child = NULL;

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glViewport(0, 0, 1000, 1000);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-200.0, 200.0, -200.0, 200.0, 200.0, -200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutCreateMenu(menu);

    // Add menu items
    glutAddMenuEntry("raise front leg", 1);
    glutAddMenuEntry("stand up", 2);
    glutAddMenuEntry("bow", 3);
    glutAddMenuEntry("return", 4);
    glutAddMenuEntry("swap perspective",5);
    // Associate a mouse button with menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void traverse(treenode* root) {
    if (root == NULL) return;
    glPushMatrix();
    root->f();
    if (root->child != NULL) {
        traverse(root->child);
    }
    glPopMatrix();
    if (root->sibling != NULL) {
        traverse(root->sibling);
    }
}


void display(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (cameraOption == 0) {
        glRotated(90, 0.0, 1.0, 0.0);
    }
    else {
        glRotated(190, 0, 1, -0.2);
    }
    
    traverse(&torso_node);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); /* default, not needed */
    glutInitWindowSize(windowWidth, windowHeight); /* 1000 x 1000 pixel window */
    glutInitWindowPosition(0, 0); /* place window top left on display */
    glutCreateWindow("Hier"); /* window title */

    glDrawBuffer(GL_BACK);
    myinit(); /* set attributes */
    glutDisplayFunc(display); /* display callback invoked when window opened */
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop(); /* enter event loop */
    return 1;
}