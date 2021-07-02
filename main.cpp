#include<windows.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>

void init(void);
void tampil(void);
void mouse (int button, int state, int x,int y);
void keyboard(unsigned char,int,int);
void ukuran(int,int);
void mouseMotion(int x, int y);
void lantai();
void entrance();
void taman();
void tamanDalam();
void tengah_tingkat_1();
void pilar_tengah();
void tengah_tingkat_2();
void seperempatBola(int scaley, int scalex, GLfloat r);
void setengahLingkaran();
void lisSetengahLingkaran();
void lisKacaDome();
void mobil();
void timer(int);
void kapsul_tengah();
void pilar_tengah();

//alim
void tingkat_1();
void tingkat_2();
void tingkat_3();
void tambah_tingkat_3();
void pilar_1();
void pilar_1_mundur();
void pilar_2();
void pilar_2_mundur();
void kapsul_1();
void kapsul_2();
void payung();
void payung2();

//hans
void fondasi();
void atap();
void gedungtambahan();
void scalegedung();
void tingkat1_kiri_gedungA();
void tingkat2_kiri_gedungA();
void tingkat3_kiri_gedungA();
void gedungA();
void tabung();
void tabungmiring();

//calvin
void tingkat1_kiri();
void tingkat2_kiri();
void tingkat3_kiri();


float x_pos = 0.0f;
float delta = 0.05f;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("ALPHA FAUSTA IKRAR SETYADI - 672019219");
    init();

    glutTimerFunc(0, timer, 0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glLineWidth(2.0);

    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);

    // lighting
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);
    is_depth=1;

    glMatrixMode(GL_MODELVIEW);

    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f,0.0f,0.0f);
    glRotatef(yrot, 0.0f, 1.0f,0.0f);
    glTranslatef(-87.50,0.0,-29.0);

    //Fungsi Alpha==========================================================================
    lantai(); //lantai dasar untuk pemetaan
    taman(); //taman depan
    tamanDalam(); //taman area hijau
    entrance();
    tengah_tingkat_1(); //lt 1 di bawah dome
    pilar_tengah();
    tengah_tingkat_2(); //lt2 di bawah dome (sejajar dome)
    kapsul_tengah();
   


    glPushMatrix();
    glColor4f(0.95,0.75,0.95,0.95);
    glTranslatef(77.75, 8.0, 15.01);
    glRotatef(270.0, 0.0, 0.0, 0.01);
    setengahLingkaran(); //kaca setengah lingkaran
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9,0.9,0.9);
    glTranslatef(77.75, 8.0, 15.0);
    glRotatef(90.0, 0.0, 0.0, 0.01);
    lisSetengahLingkaran(); //lis kaca setengah lingkaran
    glPointSize(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9,0.7,0.5);
    glTranslatef(77.75,8.0,15.0);
    glRotatef(-0.8, 0.01, 0.0, 0);
    glRotatef(179.0, 0, 0.01, 0);
    seperempatBola(100, 100,10.25); //dome
    glPopMatrix();

    lisKacaDome();
    mobil();
  
    //panggil fungsi calvin=================================================
    tingkat1_kiri();
    tingkat2_kiri();
    tingkat3_kiri();


    //panggil fungsi alim-----------------------------------------------------------------------------------------------------------
    tingkat_1();
    tingkat_2();
    tingkat_3();
    tambah_tingkat_3();
    pilar_1();
    pilar_1_mundur();
    pilar_2();
    pilar_2_mundur();
    kapsul_1();
    kapsul_2();
    payung();
    payung2();

    //========================================================================================
    
    //Fungsi hans
    glPushMatrix();
    glTranslatef(112.0,12.5,5.4);
    scalegedung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40.0,12.5,5.4);
    scalegedung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(161.0,12.5,35.0);
    scalegedung();
    glPopMatrix();

    glPushMatrix();
    glRotated(90.0,0.0,90.0,0.0);
    glTranslatef(-25.3,12.5,5.0);
    scalegedung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.8,0.0,5.8);
    tabungmiring();
    glPopMatrix();
    
    //===========================================================================================
    glPopMatrix();
    glutSwapBuffers();
}

//fungsinya alim
void tingkat_1()
{
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(88.0, 0.0, 0.0);
    glVertex3f(88.0, 4.0, 0.0);
    glVertex3f(151.0, 4.0, 0.0);
    glVertex3f(151.0, 0.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor4f(0.0,0.0,0.0,0.7);
    glVertex3f(88.0, 0.0, 14.0);
    glVertex3f(88.0, 4.0, 14.0);
    glVertex3f(138.5, 4.0, 14.0);
    glVertex3f(138.5, 0.0, 14.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(88.0, 0.0, 0.0);
    glVertex3f(88.0, 4.0, 0.0);
    glVertex3f(88.0, 4.0, 17.0);
    glVertex3f(88.0, 0.0, 17.0);
    glEnd();

    //kiri bawah
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(138.5, 0.0, 13.5);
    glVertex3f(138.5, 4.0, 13.5);
    glVertex3f(138.5, 4.0, 44.0);
    glVertex3f(138.5, 0.0, 44.0);
    glEnd();

    //depan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(135.0, 0.0, 44.0);
    glVertex3f(135.0, 4.0, 44.0);
    glVertex3f(172.0, 4.0, 44.0);
    glVertex3f(172.0, 0.0, 44.0);
    glEnd();

    //kanan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(172.0, 0.0, 27.0);
    glVertex3f(172.0, 4.0, 27.0);
    glVertex3f(172.0, 4.0, 44.0);
    glVertex3f(172.0, 0.0, 44.0);
    glEnd();

    //depan atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(151.0, 0.0, 27.0);
    glVertex3f(151.0, 4.0, 27.0);
    glVertex3f(172.0, 4.0, 27.0);
    glVertex3f(172.0, 0.0, 27.0);
    glEnd();

    //kanan atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(151.0, 0.0, 0.0);
    glVertex3f(151.0, 4.0, 0.0);
    glVertex3f(151.0, 4.0, 27.0);
    glVertex3f(151.0, 0.0, 27.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(88.0, 4.0, 00.0);
    glVertex3f(88.0, 4.0, 17.0);
    glVertex3f(151.0, 4.0, 17.0);
    glVertex3f(151.0, 4.0, 0.0);

    glVertex3f(135.0, 4.0, 17.0);
    glVertex3f(151.0, 4.0, 17.0);
    glVertex3f(151.0, 4.0, 27.0);
    glVertex3f(135.0, 4.0, 27.0);

    glVertex3f(135.0, 4.0, 27.0);
    glVertex3f(172.0, 4.0, 27.0);
    glVertex3f(172.0, 4.0, 44.0);
    glVertex3f(135.0, 4.0, 44.0);
    glEnd();
}

void tingkat_2()
{
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(88.0, 4.0, 0.0);
    glVertex3f(88.0, 8.0, 0.0);
    glVertex3f(151.0, 8.0, 0.0);
    glVertex3f(151.0, 4.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(88.0, 4.0, 14.0);
    glVertex3f(88.0, 8.0, 14.0);
    glVertex3f(138.5, 8.0, 14.0);
    glVertex3f(138.5, 4.0, 14.0);
    glEnd();

    /*
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(88.0, 4.0, 0.0);
    glVertex3f(88.0, 8.0, 0.0);
    glVertex3f(88.0, 8.0, 15.5);
    glVertex3f(88.0, 4.0, 15.5);
    glEnd(); */

    //kiri bawah
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(138.5, 4.0, 14.0);
    glVertex3f(138.5, 8.0, 14.0);
    glVertex3f(138.5, 8.0, 44.0);
    glVertex3f(138.5, 4.0, 44.0);
    glEnd();

    //depan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(136.5, 4.0, 44.0);
    glVertex3f(136.5, 8.0, 44.0);
    glVertex3f(172.0, 8.0, 44.0);
    glVertex3f(172.0, 4.0, 44.0);
    glEnd();

    //kanan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(172.0, 4.0, 27.0);
    glVertex3f(172.0, 8.0, 27.0);
    glVertex3f(172.0, 8.0, 44.0);
    glVertex3f(172.0, 4.0, 44.0);
    glEnd();

    //kanan atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(151.0, 4.0, 0.0);
    glVertex3f(151.0, 8.0, 0.0);
    glVertex3f(151.0, 8.0, 27.0);
    glVertex3f(151.0, 4.0, 27.0);
    glEnd();

    //depan atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(151.0, 4.0, 27.0);
    glVertex3f(151.0, 8.0, 27.0);
    glVertex3f(172.0, 8.0, 27.0);
    glVertex3f(172.0, 4.0, 27.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(88.0, 8.0, 0.0);
    glVertex3f(88.0, 8.0, 15.5);
    glVertex3f(151.0, 8.0, 15.5);
    glVertex3f(151.0, 8.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(136.5, 8.0, 15.5);
    glVertex3f(151.0, 8.0, 15.5);
    glVertex3f(151.0, 8.0, 27.0);
    glVertex3f(136.5, 8.0, 27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(136.5, 8.0, 27.0);
    glVertex3f(172.0, 8.0, 27.0);
    glVertex3f(172.0, 8.0, 44.0);
    glVertex3f(136.5, 8.0, 44.0);
    glEnd();
}

void tingkat_3()
{
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(98.0, 8.0, 0.0);
    glVertex3f(98.0, 12.0, 0.0);
    glVertex3f(151.0, 12.0, 0.0);
    glVertex3f(151.0, 8.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(98.0, 8.0, 13.0);
    glVertex3f(98.0, 11.0, 13.0);
    glVertex3f(139.0, 11.0, 13.0);
    glVertex3f(139.0, 8.0, 13.0);
    glEnd();

    //kotak samping dom========================================================================================
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.0 , 0.0 , 0.0 , 0.7);
    glVertex3f(88.0, 8.0, 15.5);
    glVertex3f(88.0, 11.0, 15.5);
    glVertex3f(98.0, 11.0, 15.5);
    glVertex3f(98.0, 8.0, 15.5);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.0,0.0);
    glVertex3f(88.0, 8.0, 0.0);
    glVertex3f(88.0, 11.0, 0.0);
    glVertex3f(98.0, 11.0, 0.0);
    glVertex3f(98.0, 8.0, 0.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(88.1, 4.0, 0.0);
    glVertex3f(88.1, 8.0, 0.0);
    glVertex3f(88.1, 8.0, 17.0);
    glVertex3f(88.1, 4.0, 17.0);
    glEnd();

    //atas kotak
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(88.0, 12.0, 1.0);
    glVertex3f(88.0, 12.0, 14.5);
    glVertex3f(98.0, 12.0, 14.5);
    glVertex3f(98.0, 12.0, 1.0);
    glEnd();

    //miring depan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.0,0.0);
    glVertex3f(88.0, 12.0, 14.5);
    glVertex3f(88.0, 11.0, 15.5);
    glVertex3f(98.0, 11.0, 15.5);
    glVertex3f(98.0, 12.0, 14.5);
    glEnd();

    for(int i=0 ; i<2 ;i++){
        //segitiga polygon
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.0,0.0);
        glVertex3f(98.0-i*10, 12.0, 14.5);
        glVertex3f(98.0-i*10, 11.0, 14.5);
        glVertex3f(98.0-i*10, 8.0, 14.5);
        glVertex3f(98.0-i*10, 8.0, 15.5);
        glVertex3f(98.0-i*10, 11.0, 15.5);
        glEnd();
    }

    //miring belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.0,0.0);
    glVertex3f(88.0, 12.0, 1.0);
    glVertex3f(88.0, 11.0, 0.0);
    glVertex3f(98.0, 11.0, 0.0);
    glVertex3f(98.0, 12.0, 1.0);
    glEnd();

    //segitiga polygon
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.0,0.0);
        glVertex3f(88.0, 12.0, 1.0);
        glVertex3f(88.0, 11.0, 1.0);
        glVertex3f(88.0, 8.0, 1.0);
        glVertex3f(88.0, 8.0, 0.0);
        glVertex3f(88.0, 11.0, 0.0);
        glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(98.0, 8.0, 0.0);
    glVertex3f(98.0, 12.0, 0.0);
    glVertex3f(98.0, 12.0, 14.5);
    glVertex3f(98.0, 8.0, 14.5);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(88.0, 8.0, 1.0);
    glVertex3f(88.0, 12.0, 1.0);
    glVertex3f(88.0, 12.0, 14.5);
    glVertex3f(88.0, 8.0, 14.5);
    glEnd();

    //kanan atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(151.0, 8.0, 0.0);
    glVertex3f(151.0, 12.0, 0.0);
    glVertex3f(151.0, 12.0, 27.0);
    glVertex3f(151.0, 8.0, 27.0);
    glEnd();

    //kanan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(172.0, 8.0, 27.0);
    glVertex3f(172.0, 12.0, 27.0);
    glVertex3f(172.0, 12.0, 41.5);
    glVertex3f(172.0, 8.0, 41.5);
    glEnd();

    //kiri bawah
    glBegin(GL_QUADS);
    glColor4f(0.0,0.0,0.0,0.7);
    glVertex3f(139.0, 8.0, 13.0);
    glVertex3f(139.0, 11.0, 13.0);
    glVertex3f(139.0, 11.0, 44.0);
    glVertex3f(139.0, 8.0, 44.0);
    glEnd();

    //blkg bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(151.0, 8.0, 27.0);
    glVertex3f(151.0, 12.0, 27.0);
    glVertex3f(172.0, 12.0, 27.0);
    glVertex3f(172.0, 8.0, 27.0);
    glEnd();

    //depan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(139.0, 8.0, 44.0);
    glVertex3f(139.0, 11.0, 44.0);
    glVertex3f(172.0, 11.0, 44.0);
    glVertex3f(172.0, 8.0, 44.0);
    glEnd();

    //tambal trapesium
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(172.0, 8.0, 44.0);
    glVertex3f(172.0, 8.0, 41.5);
    glVertex3f(172.0, 12.0, 41.5);
    glVertex3f(172.0, 11.0, 44.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(98.0, 12.0, 0.0);
    glVertex3f(98.0, 12.0, 10.5);
    glVertex3f(151.0, 12.0, 10.5);
    glVertex3f(151.0, 12.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(141.5, 12.0, 10.5);
    glVertex3f(151.0, 12.0, 10.5);
    glVertex3f(151.0, 12.0, 27.0);
    glVertex3f(141.5, 12.0, 27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(141.5, 12.0, 27.0);
    glVertex3f(172.0, 12.0, 27.0);
    glVertex3f(172.0, 12.0, 41.5);
    glVertex3f(141.5, 12.0, 41.5);
    glEnd();
}

void tambah_tingkat_3()
{
    //atas 1
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(98.0, 12.0, 10.5);
    glVertex3f(139.0, 12.0, 10.5);
    glVertex3f(139.0, 11.0, 13.0);
    glVertex3f(98.0, 11.0, 13.0);
    glEnd();

    //atas 2
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(139.0, 11.0, 13.0);
    glVertex3f(141.5, 12.0, 13.0);
    glVertex3f(141.5, 12.0, 41.5);
    glVertex3f(139.0, 11.0, 41.5);
    glEnd();

    //atas 3
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(141.5, 12.0, 41.5);
    glVertex3f(172.0, 12.0, 41.5);
    glVertex3f(172.0, 11.0, 44.0);
    glVertex3f(141.5, 11.0, 44.0);
    glEnd();

    //tambahh atap
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(139.0, 11.0, 44.0);
    glVertex3f(141.5, 11.0, 44.0);
    glVertex3f(141.5, 12.0, 41.5);
    glVertex3f(139.0, 11.0, 41.5);
    glEnd();

    //tambahh atap2
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(139.0, 11.0, 13.0);
    glVertex3f(141.5, 12.0, 13.0);
    glVertex3f(141.5, 12.0,10.5);
    glVertex3f(139.0, 12.0, 10.5);
    glEnd();
}

//update
void kapsul_1()
{
    //pagar antar kapsul
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(88.0, 4.0, 17.0);
        glVertex3f(88.0, 5.5, 17.0);
        glVertex3f(134.5, 5.5, 17.0);
        glVertex3f(134.5, 4.0, 17.0);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(88.0, 4.0, 16.5);
        glVertex3f(88.0, 5.5, 16.5);
        glVertex3f(134.5, 5.5, 16.5);
        glVertex3f(134.5, 4.0, 16.5);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(88.0, 5.5, 16.5);
        glVertex3f(88.0, 5.5, 17.0);
        glVertex3f(134.5, 5.5, 17.0);
        glVertex3f(134.5, 5.5, 16.5);
        glEnd();


    for(int i = 0 ; i<12 ; i++){
        //bawah
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4 , 4.1 , 17.5); // 17.5
        glVertex3f(91.0+i*4 , 4.1 , 17.5); // 17.5
        glVertex3f(91.5+i*4 , 4.1 , 17.0); // 17.0
        glVertex3f(91.5+i*4 , 4.1 , 16.5); // 16.5
        glVertex3f(91.0+i*4 , 4.1 , 16.0); // 16.0
        glVertex3f(90.5+i*4 , 4.1 , 16.0); // 16.0
        glVertex3f(90.0+i*4 , 4.1 , 16.5); // 16.5
        glVertex3f(90.0+i*4 , 4.1 , 17.0); // 17.0
        glEnd();
        //atas
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4 , 7.1 , 17.5); // 17.5
        glVertex3f(91.0+i*4 , 7.1 , 17.5); // 17.5
        glVertex3f(91.5+i*4 , 7.1 , 17.0); // 17.0
        glVertex3f(91.5+i*4 , 7.1 , 16.5); // 16.5
        glVertex3f(91.0+i*4 , 7.1 , 16.0); // 16.0
        glVertex3f(90.5+i*4 , 7.1 , 16.0); // 16.0
        glVertex3f(90.0+i*4 , 7.1 , 16.5); // 16.5
        glVertex3f(90.0+i*4 , 7.1 , 17.0); // 17.0
        glEnd();

        //selimut=============================
        //1
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 7.1 , 16.0);
        glVertex3f(90.5+i*4 , 7.1 , 16.0);
        glEnd();
        //2
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(91.5+i*4 , 7.1 , 17.0);
        glVertex3f(91.0+i*4 , 7.1 , 17.5);
        glEnd();
        //3
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(91.5+i*4 , 7.1 , 16.5);
        glVertex3f(91.5+i*4 , 7.1 , 17.0);
        glEnd();
        //4
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 7.1 , 16.0);
        glVertex3f(91.5+i*4 , 7.1 , 16.5);
        glEnd();
        //5
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 4.1 , 17.5);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(91.0+i*4 , 7.1 , 17.5);
        glVertex3f(90.5+i*4 , 7.1 , 17.5);
        glEnd();
        //6
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(90.0+i*4 , 4.1 , 16.5);
        glVertex3f(90.0+i*4 , 7.1 , 16.5);
        glVertex3f(90.5+i*4 , 7.1 , 16.0);
        glEnd();
        //7
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.0+i*4 , 4.1 , 17.0);
        glVertex3f(90.0+i*4, 4.1 , 16.5);
        glVertex3f(90.0+i*4 , 7.1 , 16.5);
        glVertex3f(90.0+i*4 , 7.1 , 17.0);
        glEnd();
        //8
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.0+i*4 , 4.1 , 17.0);
        glVertex3f(90.5+i*4 , 4.1 , 17.5);
        glVertex3f(90.5+i*4 , 7.1 , 17.5);
        glVertex3f(90.0+i*4 , 7.1 , 17.0);
        glEnd();

        //lancip atas
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 7.1 , 17.4);
        glVertex3f(91.0+i*4 , 7.1 , 17.4);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glVertex3f(91.0+i*4 , 7.1 , 17.4);
        glVertex3f(91.4+i*4 , 7.1 , 17.0);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glVertex3f(91.4+i*4 , 7.1 , 17.0);
        glVertex3f(91.4+i*4 , 7.1 , 16.5);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glVertex3f(91.4+i*4 , 7.1 , 16.5);
        glVertex3f(91.0+i*4 , 7.1 , 16.1);
        glVertex3f(90.75+i*4, 7.7 , 16.75);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 7.1 , 16.1);
        glVertex3f(91.0+i*4 , 7.1 , 16.1);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 7.1 , 16.1);
        glVertex3f(90.1+i*4 , 7.1 , 16.5);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glVertex3f(90.1+i*4 , 7.1 , 17.0);
        glVertex3f(90.1+i*4, 7.1 , 16.5);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glVertex3f(90.1+i*4 , 7.1 , 17.0);
        glVertex3f(90.5+i*4 , 7.1 , 17.4);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();


         //lancip bawah
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 4.1 , 17.5);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(90.0+i*4 , 4.1 , 16.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glVertex3f(90.0 +i*4, 4.1 , 17.0);
        glVertex3f(90.0 +i*4, 4.1 , 16.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glVertex3f(90.0+i*4 , 4.1 , 17.0);
        glVertex3f(90.5 +i*4, 4.1 , 17.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
    }
}

void kapsul_2()
{
    //pagar antar kapsul
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(135.0, 4.0, 16.75);
    glVertex3f(135.0, 5.5, 16.75);
    glVertex3f(135.0, 5.5, 44.0);
    glVertex3f(135.0, 4.0, 44.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(135.5, 4.0, 16.75);
    glVertex3f(135.5, 5.5, 16.75);
    glVertex3f(135.5, 5.5, 44.0);
    glVertex3f(135.5, 4.0, 44.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(135.0, 4.0, 44.0);
    glVertex3f(136.5, 4.0, 44.0);
    glVertex3f(136.5, 5.5, 44.0);
    glVertex3f(135.0, 5.5, 44.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 240/255.f, 202/255.f);
    glVertex3f(135.0, 5.5, 16.75);
    glVertex3f(135.5, 5.5, 16.75);
    glVertex3f(135.5, 5.5, 44.0);
    glVertex3f(135.0, 5.5, 44.0);
    glEnd();

    for(int i = 0 ; i<6 ; i++){
        //bawah
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(135.0 , 4.1 , 21.5+i*4);
        glVertex3f(135.5 , 4.1 , 21.5+i*4);
        glVertex3f(136.0 , 4.1 , 21.0+i*4);
        glVertex3f(136.0 , 4.1 , 20.5+i*4);
        glVertex3f(135.5 , 4.1 , 20.0+i*4);
        glVertex3f(135.0 , 4.1 , 20.0+i*4);
        glVertex3f(134.5 , 4.1 , 20.5+i*4);
        glVertex3f(134.5 , 4.1 , 21.0+i*4);
        glEnd();
        //atas
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(135.0 , 7.1 , 21.5+i*4);
        glVertex3f(135.5 , 7.1 , 21.5+i*4);
        glVertex3f(136.0 , 7.1 , 21.0+i*4);
        glVertex3f(136.0 , 7.1 , 20.5+i*4);
        glVertex3f(135.5 , 7.1 , 20.0+i*4);
        glVertex3f(135.0 , 7.1 , 20.0+i*4);
        glVertex3f(134.5 , 7.1 , 20.5+i*4);
        glVertex3f(134.5 , 7.1 , 21.0+i*4);
        glEnd();

        //selimut=============================
        //1
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(135.0 , 4.1 , 21.5+i*4);
        glVertex3f(135.5 , 4.1 , 21.5+i*4);
        glVertex3f(135.5 , 7.1 , 21.5+i*4);
        glVertex3f(135.0 , 7.1 , 21.5+i*4);
        glEnd();
        //2
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(135.5 , 4.1 , 21.5+i*4);
        glVertex3f(136.0 , 4.1 , 21.0+i*4);
        glVertex3f(136.0 , 7.1 , 21.0+i*4);
        glVertex3f(135.5 , 7.1 , 21.5+i*4);
        glEnd();
        //3
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(136.0 , 4.1 , 21.0+i*4);
        glVertex3f(136.0 , 4.1 , 20.5+i*4);
        glVertex3f(136.0 , 7.1 , 20.5+i*4);
        glVertex3f(136.0 , 7.1 , 21.0+i*4);
        glEnd();
        //4
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(136.0 , 4.1 , 20.5+i*4);
        glVertex3f(135.5 , 4.1 , 20.0+i*4);
        glVertex3f(135.5 , 7.1 , 20.0+i*4);
        glVertex3f(136.0 , 7.1 , 20.5+i*4);
        glEnd();
        //5
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(135.5 , 4.1 , 20.0+i*4);
        glVertex3f(135.0 , 4.1 , 20.0+i*4);
        glVertex3f(135.0 , 7.1 , 20.0+i*4);
        glVertex3f(135.5 , 7.1 , 20.0+i*4);
        glEnd();
        //6
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(135.0 , 4.1 , 20.0+i*4);
        glVertex3f(134.5 , 4.1 , 20.5+i*4);
        glVertex3f(134.5 , 7.1 , 20.5+i*4);
        glVertex3f(135.0 , 7.1 , 20.0+i*4);
        glEnd();
        //7
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(134.5 , 4.1 , 21.0+i*4);
        glVertex3f(134.5 , 4.1 , 20.5+i*4);
        glVertex3f(134.5 , 7.1 , 20.5+i*4);
        glVertex3f(134.5 , 7.1 , 21.0+i*4);
        glEnd();
        //8
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(134.5 , 4.1 , 21.0+i*4);
        glVertex3f(135.0 , 4.1 , 21.5+i*4);
        glVertex3f(135.0 , 7.1 , 21.5+i*4);
        glVertex3f(134.5 , 7.1 , 21.0+i*4);
        glEnd();

        //lancip atas==============
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(135.0 , 7.1 , 21.4+i*4);
        glVertex3f(135.5 , 7.1 , 21.4+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glVertex3f(135.5 , 7.1 , 21.4+i*4);
        glVertex3f(135.9 , 7.1 , 21.0+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glVertex3f(135.9 , 7.1 , 21.0+i*4);
        glVertex3f(135.9 , 7.1 , 20.5+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glVertex3f(135.9 , 7.1 , 20.5+i*4);
        glVertex3f(135.5 , 7.1 , 20.1+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glVertex3f(135.5 , 7.1 , 20.1+i*4);
        glVertex3f(135.0 , 7.1 , 20.1+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glVertex3f(135.0 , 7.1 , 20.1+i*4);
        glVertex3f(134.6 , 7.1 , 20.5+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glVertex3f(134.6 , 7.1 , 21.0+i*4);
        glVertex3f(134.6 , 7.1 , 20.5+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glVertex3f(134.6 , 7.1 , 21.0+i*4);
        glVertex3f(135.0 , 7.1 , 21.4+i*4);
        glVertex3f(135.25 , 7.7 , 20.75+i*4);
        glEnd();

        //lancip bawah=============
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(135.0 , 4.1 , 21.5+i*4);
        glVertex3f(135.5 , 4.1 , 21.5+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glVertex3f(135.5 , 4.1 , 21.5+i*4);
        glVertex3f(136.0 , 4.1 , 21.0+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glVertex3f(136.0 , 4.1 , 21.0+i*4);
        glVertex3f(136.0 , 4.1 , 20.5+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glVertex3f(136.0 , 4.1 , 20.5+i*4);
        glVertex3f(135.5 , 4.1 , 20.1+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glVertex3f(135.5 , 4.1 , 20.0+i*4);
        glVertex3f(135.0 , 4.1 , 20.0+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glVertex3f(135.0 , 4.1 , 20.0+i*4);
        glVertex3f(134.5 , 4.1 , 20.5+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glVertex3f(134.5 , 4.1 , 21.0+i*4);
        glVertex3f(134.5 , 4.1 , 20.5+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glVertex3f(134.5 , 4.1 , 21.0+i*4);
        glVertex3f(135.0 , 4.1 , 21.5+i*4);
        glVertex3f(135.25 , 3.5 , 20.75+i*4);
        glEnd();
        }
    }

void payung()
{
    //1
    glBegin(GL_TRIANGLES);
    glColor3f(250/255.f, 240/255.f, 202/255.f);
    glVertex3f(100.5-1.8 , 8.1 , 15.5);
    glVertex3f(101.0-1.8 , 8.1 , 15.5);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //2
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(101.0-1.8 , 8.1 , 15.5);
    glVertex3f(101.5-1.8 , 8.1 , 15.0);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //3
    glBegin(GL_TRIANGLES);
    glColor3f(250/255.f, 240/255.f, 202/255.f);
    glVertex3f(101.5-1.8 , 8.1 , 15.0);
    glVertex3f(101.5-1.8 , 8.1 , 14.5);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //4
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(101.5-1.8 , 8.1 , 14.5);
    glVertex3f(101.0-1.8 , 8.1 , 14.0);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //5
    glBegin(GL_TRIANGLES);
    glColor3f(250/255.f, 240/255.f, 202/255.f);
    glVertex3f(100.5-1.8 , 8.1 , 14.0);
    glVertex3f(101.0-1.8 , 8.1 , 14.0);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //6
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(100.5-1.8 , 8.1 , 14.0);
    glVertex3f(100.0-1.8 , 8.1 , 14.5);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //7
    glBegin(GL_TRIANGLES);
    glColor3f(250/255.f, 240/255.f, 202/255.f);
    glVertex3f(100.0-1.8 , 8.1 , 15.0);
    glVertex3f(100.0-1.8 , 8.1 , 14.5);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();
    //8
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(100.0-1.8 , 8.1 , 15.0);
    glVertex3f(100.5-1.8 , 8.1 , 15.5);
    glVertex3f(100.75-1.8 , 8.7 , 14.75);
    glEnd();

    for(int i=0 ; i<23 ; i++){
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(100.5+i*1.6 , 8.1 , 15.5);
        glVertex3f(101.0+i*1.6 , 8.1 , 15.5);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(101.0+i*1.6 , 8.1 , 15.5);
        glVertex3f(101.5+i*1.6 , 8.1 , 15.0);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(101.5+i*1.6 , 8.1 , 15.0);
        glVertex3f(101.5+i*1.6 , 8.1 , 14.5);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(101.5+i*1.6 , 8.1 , 14.5);
        glVertex3f(101.0+i*1.6 , 8.1 , 14.0);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(100.5+i*1.6 , 8.1 , 14.0);
        glVertex3f(101.0+i*1.6 , 8.1 , 14.0);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(100.5+i*1.6 , 8.1 , 14.0);
        glVertex3f(100.0+i*1.6 , 8.1 , 14.5);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(100.0+i*1.6 , 8.1 , 15.0);
        glVertex3f(100.0+i*1.6, 8.1 , 14.5);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(100.0+i*1.6 , 8.1 , 15.0);
        glVertex3f(100.5+i*1.6 , 8.1 , 15.5);
        glVertex3f(100.75+i*1.6 , 8.7 , 14.75);
        glEnd();
    }
}

void payung2()
{
    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    for(int i = 0 ; i<15 ; i++){
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(137.5 , 8.1 , 17.5+i*1.8);
        glVertex3f(138.0 , 8.1 , 17.5+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(138.0 , 8.1 , 17.5+i*1.8);
        glVertex3f(138.5 , 8.1 , 17.0+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(138.5 , 8.1 , 17.0+i*1.8);
        glVertex3f(138.5 , 8.1 , 16.5+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(138.5 , 8.1 , 16.5+i*1.8);
        glVertex3f(138.0 , 8.1 , 16.0+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(137.5 , 8.1 , 16.0+i*1.8);
        glVertex3f(138.0 , 8.1 , 16.0+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(137.5 , 8.1 , 16.0+i*1.8);
        glVertex3f(137.0 , 8.1 , 16.5+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(137.0 , 8.1 , 17.0+i*1.8);
        glVertex3f(137.0 , 8.1 , 16.5+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(137.0 , 8.1 , 17.0+i*1.8);
        glVertex3f(137.5 , 8.1 , 17.5+i*1.8);
        glVertex3f(137.75 , 8.7 , 16.75+i*1.8);
        glEnd();
    }
    glPopMatrix();
}


void pilar_1()
{
        for(int i = 0 ; i<12 ; i++){
            //depan
            glBegin(GL_QUADS);
            glColor3f(0.9,0.7,0.5);
            glVertex3f(90.5+i*4, 0.0, 17.0);
            glVertex3f(90.5+i*4, 4.0, 17.0);
            glVertex3f(91.0+i*4, 4.0, 17.0);
            glVertex3f(91.0+i*4, 0.0, 17.0);
            glEnd();

            //belakang
            glBegin(GL_QUADS);
            glVertex3f(90.5+i*4, 0.0, 16.5);
            glVertex3f(90.5+i*4, 4.0, 16.5);
            glVertex3f(91.0+i*4, 4.0, 16.5);
            glVertex3f(91.0+i*4, 0.0, 16.5);
            glEnd();

            //kiri
            glBegin(GL_QUADS);
            glVertex3f(90.5+i*4, 0.0, 16.5);
            glVertex3f(90.5+i*4, 4.0, 16.5);
            glVertex3f(90.5+i*4, 4.0, 17.0);
            glVertex3f(90.5+i*4, 0.0, 17.0);
            glEnd();

            //kanan
            glBegin(GL_QUADS);
            glVertex3f(91.0+i*4, 0.0, 16.5);
            glVertex3f(91.0+i*4, 4.0, 16.5);
            glVertex3f(91.0+i*4, 4.0, 17.0);
            glVertex3f(91.0+i*4, 0.0, 17.0);
            glEnd();
        }
    }

void pilar_1_mundur()
{
            for(int i = 0 ; i<12 ; i++){
            //depan
            glBegin(GL_QUADS);
            glColor3f(0.9,0.7,0.5);
            glVertex3f(90.5+i*4, 0.0, 15.5);
            glVertex3f(90.5+i*4, 4.0, 15.5);
            glVertex3f(91.0+i*4, 4.0, 15.5);
            glVertex3f(91.0+i*4, 0.0, 15.5);
            glEnd();

            //belakang
            glBegin(GL_QUADS);
            glVertex3f(90.5+i*4, 0.0, 15.0);
            glVertex3f(90.5+i*4, 4.0, 15.0);
            glVertex3f(91.0+i*4, 4.0, 15.0);
            glVertex3f(91.0+i*4, 0.0, 15.0);
            glEnd();

            //kiri
            glBegin(GL_QUADS);
            glVertex3f(90.5+i*4, 0.0, 15.5);
            glVertex3f(90.5+i*4, 4.0, 15.5);
            glVertex3f(90.5+i*4, 4.0, 15.0);
            glVertex3f(90.5+i*4, 0.0, 15.0);
            glEnd();

            //kanan
            glBegin(GL_QUADS);
            glVertex3f(91.0+i*4, 0.0, 15.0);
            glVertex3f(91.0+i*4, 4.0, 15.0);
            glVertex3f(91.0+i*4, 4.0, 15.5);
            glVertex3f(91.0+i*4, 0.0, 15.5);
            glEnd();
        }

        for(int i = 0 ; i<12 ; i++){
            //depan
            glBegin(GL_QUADS);
            glColor3f(0.9,0.7,0.5);
            glVertex3f(90.5+i*4, 0.0+4, 15.5);
            glVertex3f(90.5+i*4, 4.0+4, 15.5);
            glVertex3f(91.0+i*4, 4.0+4, 15.5);
            glVertex3f(91.0+i*4, 0.0+4, 15.5);
            glEnd();

            //belakang
            glBegin(GL_QUADS);
            glVertex3f(90.5+i*4, 0.0+4, 15.0);
            glVertex3f(90.5+i*4, 4.0+4, 15.0);
            glVertex3f(91.0+i*4, 4.0+4, 15.0);
            glVertex3f(91.0+i*4, 0.0+4, 15.0);
            glEnd();

            //kiri
            glBegin(GL_QUADS);
            glVertex3f(90.5+i*4, 0.0+4, 15.5);
            glVertex3f(90.5+i*4, 4.0+4, 15.5);
            glVertex3f(90.5+i*4, 4.0+4, 15.0);
            glVertex3f(90.5+i*4, 0.0+4, 15.0);
            glEnd();

            //kanan
            glBegin(GL_QUADS);
            glVertex3f(91.0+i*4, 0.0+4, 15.0);
            glVertex3f(91.0+i*4, 4.0+4, 15.0);
            glVertex3f(91.0+i*4, 4.0+4, 15.5);
            glVertex3f(91.0+i*4, 0.0+4, 15.5);
            glEnd();
        }
    }

void pilar_2()
{
        for(int i=0 ; i<6 ; i++){
            //depan
            glBegin(GL_QUADS);
            glColor3f(0.9,0.7,0.5);
            glVertex3f(135.0, 0.0, 21.0+i*4);
            glVertex3f(135.0, 4.0, 21.0+i*4);
            glVertex3f(135.5, 4.0, 21.0+i*4);
            glVertex3f(135.5, 0.0, 21.0+i*4);
            glEnd();

            //belakang
            glBegin(GL_QUADS);
            glVertex3f(135.0, 0.0, 20.5+i*4);
            glVertex3f(135.0, 4.0, 20.5+i*4);
            glVertex3f(135.5, 4.0, 20.5+i*4);
            glVertex3f(135.5, 0.0, 20.5+i*4);
            glEnd();

            //kiri
            glBegin(GL_QUADS);
            glVertex3f(135.0, 0.0, 20.5+i*4);
            glVertex3f(135.0, 4.0, 20.5+i*4);
            glVertex3f(135.0, 4.0, 21.0+i*4);
            glVertex3f(135.0, 0.0, 21.0+i*4);
            glEnd();

            //kanan
            glBegin(GL_QUADS);
            glVertex3f(135.5, 0.0, 20.5+i*4);
            glVertex3f(135.5, 4.0, 20.5+i*4);
            glVertex3f(135.5, 4.0, 21.0+i*4);
            glVertex3f(135.5, 0.0, 21.0+i*4);
            glEnd();
    }
}

void pilar_2_mundur()
{
    for(int i=0 ; i<6 ; i++){
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(136.5, 0.0, 20.0+i*4);
        glVertex3f(136.5, 4.0, 20.0+i*4);
        glVertex3f(137.0, 4.0, 20.0+i*4);
        glVertex3f(137.0, 0.0, 20.0+i*4);
        glEnd();

        //belakang
        glBegin(GL_QUADS);
        glVertex3f(136.5, 0.0, 19.5+i*4);
        glVertex3f(136.5, 4.0, 19.5+i*4);
        glVertex3f(137.0, 4.0, 19.5+i*4);
        glVertex3f(137.0, 0.0, 19.5+i*4);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glVertex3f(136.5, 0.0, 19.5+i*4);
        glVertex3f(136.5, 4.0, 19.5+i*4);
        glVertex3f(136.5, 4.0, 20.0+i*4);
        glVertex3f(136.5, 0.0, 20.0+i*4);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glVertex3f(137.0, 0.0, 19.5+i*4);
        glVertex3f(137.0, 4.0, 19.5+i*4);
        glVertex3f(137.0, 4.0, 20.0+i*4);
        glVertex3f(137.0, 0.0, 20.0+i*4);
        glEnd();
    }

        for(int i=0 ; i<6 ; i++){
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(136.5, 0.0+4, 20.0+i*4);
        glVertex3f(136.5, 4.0+4, 20.0+i*4);
        glVertex3f(137.0, 4.0+4, 20.0+i*4);
        glVertex3f(137.0, 0.0+4, 20.0+i*4);
        glEnd();

        //belakang
        glBegin(GL_QUADS);
        glVertex3f(136.5, 0.0+4, 19.5+i*4);
        glVertex3f(136.5, 4.0+4, 19.5+i*4);
        glVertex3f(137.0, 4.0+4, 19.5+i*4);
        glVertex3f(137.0, 0.0+4, 19.5+i*4);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glVertex3f(136.5, 0.0+4, 19.5+i*4);
        glVertex3f(136.5, 4.0+4, 19.5+i*4);
        glVertex3f(136.5, 4.0+4, 20.0+i*4);
        glVertex3f(136.5, 0.0+4, 20.0+i*4);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glVertex3f(137.0, 0.0+4, 19.5+i*4);
        glVertex3f(137.0, 4.0+4, 19.5+i*4);
        glVertex3f(137.0, 4.0+4, 20.0+i*4);
        glVertex3f(137.0, 0.0+4, 20.0+i*4);
        glEnd();
    }
}



void timer(int){
    glutPostRedisplay();
    glutTimerFunc(100/30, timer, 0);
    x_pos += delta;
}

void lantai(){
    //Tanah
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(00.0, -0.02, 00.0);
    glVertex3f(175.0, -0.02, 00.0);
    glVertex3f(175.0, -0.02, 58.0);
    glVertex3f(00.0, -0.02, 58.0);
    glEnd();

    //Lantai dasar MALL UTAMA
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(67.50, 0.0, 0.0);
    glVertex3f(67.50, 0.0, 17.0);
    glVertex3f(17.0, 0.0, 17.0);
    glVertex3f(17.0, 0.0, 52.0);
    glVertex3f(0.0, 0.0, 52.0);
    glEnd();

    //Lantai dasar DOME
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.50, 0.0, 0.0);
    glVertex3f(88.0, 0.0, 0.0);
    glVertex3f(88.0, 0.0, 17.0);
    glVertex3f(67.50, 0.0, 17.0);
    glEnd();

    //Lantai dasar MALL TAMBAHAN
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(88.0, 0.0, 00.0);
    glVertex3f(88.0, 0.0, 17.0);
    glVertex3f(151.0, 0.0, 17.0);
    glVertex3f(151.0, 0.0, 0.0);

    glVertex3f(135.0, 0.0, 17.0);
    glVertex3f(151.0, 0.0, 17.0);
    glVertex3f(151.0, 0.0, 27.0);
    glVertex3f(135.0, 0.0, 27.0);

    glVertex3f(135.0, 0.0, 27.0);
    glVertex3f(172.0, 0.0, 27.0);
    glVertex3f(172.0, 0.0, 44.0);
    glVertex3f(135.0, 0.0, 44.0);
    glEnd();

    //Jalan raya
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(00.0, 0.0, 67.0);
    glVertex3f(175.0, 0.0, 67.0);
    glVertex3f(175.0, 0.0, 58.0);
    glVertex3f(00.0, 0.0, 58.0);
    glEnd();

    //Marka jalan
    for(int i = 0; i <= 16; i+=2){
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(00.0+10*i, 0.01, 62.75);
        glVertex3f(10.0+10*i, 0.01, 62.75);
        glVertex3f(10.0+10*i, 0.01, 62.25);
        glVertex3f(00.0+10*i, 0.01, 62.25);
        glEnd();
    }

}

void taman(){
    //Dasar=====================================================================================================================
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
        glVertex3f(17.0, 0.0, 17.0);
        glVertex3f(135.0, 0.0, 17.0);
        glVertex3f(135.0, 0.0, 58.0);
        glVertex3f(17.0, 0.0, 58.0);
    glEnd();

    //Dasar=====================================================================================================================
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
        glVertex3f(27.0, 0.01, 18.0);
        glVertex3f(125.0, 0.01, 18.0);
        glVertex3f(125.0, 0.01, 20.5);
        glVertex3f(27.0, 0.01, 20.5);
    glEnd();

    //Kolam 1==================================================================================================================
    glColor4f(0.0, 0.0, 1.0, 0.7);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(19.5, 0.2, 32.0);
        glVertex3f(24.5, 0.2, 32.0);
        glVertex3f(24.5, 0.2, 42.0);
        glVertex3f(19.5, 0.2, 42.0);
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
        glVertex3f(19.5, 0.3, 42.0);
        glVertex3f(19.5, 0.0, 42.0);
        glVertex3f(24.5, 0.0, 42.0);
        glVertex3f(24.5, 0.3, 42.0);

        glVertex3f(19.5, 0.3, 32.0);
        glVertex3f(19.5, 0.0, 32.0);
        glVertex3f(24.5, 0.0, 32.0);
        glVertex3f(24.5, 0.3, 32.0);

        glVertex3f(19.5, 0.3, 32.0);
        glVertex3f(19.5, 0.0, 32.0);
        glVertex3f(19.5, 0.0, 42.0);
        glVertex3f(19.5, 0.3, 42.0);

        glVertex3f(24.5, 0.3, 32.0);
        glVertex3f(24.5, 0.0, 32.0);
        glVertex3f(24.5, 0.0, 42.0);
        glVertex3f(24.5, 0.3, 42.0);
    glEnd();
    glPopMatrix();

    //Kolam 2,3,4==============================================================================================================
    for(int i = 0; i < 3; i++){
        //Pohon=============================================
        glColor3f(0.0, 0.8, 0.0);
        glPushMatrix();
        glTranslatef(44+i*32, 1.8, 21.5);
        glutSolidSphere(0.8, 10, 10);
        glPopMatrix();
        glColor3f(106/255.f, 73/255.f, 64/255.f);
        glBegin(GL_QUADS);
            glVertex3f(44.2+i*32, 1.8, 21.3);
            glVertex3f(43.8+i*32, 1.8, 21.3);
            glVertex3f(43.8+i*32, 0.0, 21.3);
            glVertex3f(44.2+i*32, 0.0, 21.3);

            glVertex3f(44.2+i*32, 1.8, 21.7);
            glVertex3f(43.8+i*32, 1.8, 21.7);
            glVertex3f(43.8+i*32, 0.0, 21.7);
            glVertex3f(44.2+i*32, 0.0, 21.7);

            glVertex3f(43.8+i*32, 1.8, 21.7);
            glVertex3f(43.8+i*32, 1.8, 21.3);
            glVertex3f(43.8+i*32, 0.0, 21.3);
            glVertex3f(43.8+i*32, 0.0, 21.7);

            glVertex3f(44.2+i*32, 1.8, 21.7);
            glVertex3f(44.2+i*32, 1.8, 21.3);
            glVertex3f(44.2+i*32, 0.0, 21.3);
            glVertex3f(44.2+i*32, 0.0, 21.7);
        glEnd();

        glPushMatrix();
            glTranslatef(5.5, 0, 0);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44+i*32, 1.8, 21.5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.3);

                glVertex3f(44.2+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 0.0, 21.7);
                glVertex3f(44.2+i*32, 0.0, 21.7);

                glVertex3f(43.8+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.7);

                glVertex3f(44.2+i*32, 1.8, 21.7);
                glVertex3f(44.2+i*32, 1.8, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.7);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(5.5, 0, 4.5);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44+i*32, 1.8, 21.5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.3);

                glVertex3f(44.2+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 0.0, 21.7);
                glVertex3f(44.2+i*32, 0.0, 21.7);

                glVertex3f(43.8+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.7);

                glVertex3f(44.2+i*32, 1.8, 21.7);
                glVertex3f(44.2+i*32, 1.8, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.7);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.0, 0, 4.5);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44+i*32, 1.8, 21.5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.3);

                glVertex3f(44.2+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 0.0, 21.7);
                glVertex3f(44.2+i*32, 0.0, 21.7);

                glVertex3f(43.8+i*32, 1.8, 21.7);
                glVertex3f(43.8+i*32, 1.8, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.3);
                glVertex3f(43.8+i*32, 0.0, 21.7);

                glVertex3f(44.2+i*32, 1.8, 21.7);
                glVertex3f(44.2+i*32, 1.8, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.3);
                glVertex3f(44.2+i*32, 0.0, 21.7);
            glEnd();
        glPopMatrix();


        //Air============================================
        glColor4f(0.0, 0.0, 1.0, 0.7);
        glBegin(GL_QUADS);
            glVertex3f(44.5+i*32, 0.2, 22.0);
            glVertex3f(48.5+i*32, 0.2, 22.0);
            glVertex3f(48.5+i*32, 0.2, 25.5);
            glVertex3f(44.5+i*32, 0.2, 25.5);
        glEnd();

        //Kolam========================================
        glColor3f(0.8, 0.8, 0.8);
        glBegin(GL_QUADS);
            glVertex3f(44.5+i*32, 0.3, 22.0);
            glVertex3f(48.5+i*32, 0.3, 22.0);
            glVertex3f(48.5+i*32, 0.0, 22.0);
            glVertex3f(44.5+i*32, 0.0, 22.0);

            glVertex3f(44.5+i*32, 0.3, 25.5);
            glVertex3f(48.5+i*32, 0.3, 25.5);
            glVertex3f(48.5+i*32, 0.0, 25.5);
            glVertex3f(44.5+i*32, 0.0, 25.5);

            glVertex3f(44.5+i*32, 0.3, 25.5);
            glVertex3f(44.5+i*32, 0.3, 22.0);
            glVertex3f(44.5+i*32, 0.0, 22.0);
            glVertex3f(44.5+i*32, 0.0, 25.5);

            glVertex3f(48.5+i*32, 0.3, 25.5);
            glVertex3f(48.5+i*32, 0.3, 22.0);
            glVertex3f(48.5+i*32, 0.0, 22.0);
            glVertex3f(48.5+i*32, 0.0, 25.5);
        glEnd();
    }


}

void tamanDalam(){
    //Area hijau===============================================================================================================
    glColor3f(0.0, 0.9, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(27.0, 0.01, 27.0);
        glVertex3f(125.0, 0.01, 27.0);
        glVertex3f(125.0, 0.01, 58.0);
        glVertex3f(27.0, 0.01, 58.0);
    glEnd();

    //Area dalam================================================================================================================
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
        glVertex3f(32.0, 0.02, 40.0);
        glVertex3f(118.0, 0.02, 40.0);
        glVertex3f(118.0, 0.02, 55.0);
        glVertex3f(32.0, 0.02, 55.0);

        glVertex3f(32.0, 0.02, 40.0);
        glVertex3f(52.0, 0.02, 40.0);
        glVertex3f(52.0, 0.02, 32.0);
        glVertex3f(32.0, 0.02, 32.0);

        glVertex3f(118.0, 0.02, 40.0);
        glVertex3f(98.0, 0.02, 40.0);
        glVertex3f(98.0, 0.02, 32.0);
        glVertex3f(118.0, 0.02, 32.0);
    glEnd();


    //Pohon pinggir taman belakang=============================================================================================================
    for(int i = 0; i < 20; i++){
        glPushMatrix();
            glTranslatef(-16, 0, 7);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44+i*5, 1.8, 21.5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2+i*5, 1.8, 21.3);
                glVertex3f(43.8+i*5, 1.8, 21.3);
                glVertex3f(43.8+i*5, 0.0, 21.3);
                glVertex3f(44.2+i*5, 0.0, 21.3);

                glVertex3f(44.2+i*5, 1.8, 21.7);
                glVertex3f(43.8+i*5, 1.8, 21.7);
                glVertex3f(43.8+i*5, 0.0, 21.7);
                glVertex3f(44.2+i*5, 0.0, 21.7);

                glVertex3f(43.8+i*5, 1.8, 21.7);
                glVertex3f(43.8+i*5, 1.8, 21.3);
                glVertex3f(43.8+i*5, 0.0, 21.3);
                glVertex3f(43.8+i*5, 0.0, 21.7);

                glVertex3f(44.2+i*5, 1.8, 21.7);
                glVertex3f(44.2+i*5, 1.8, 21.3);
                glVertex3f(44.2+i*5, 0.0, 21.3);
                glVertex3f(44.2+i*5, 0.0, 21.7);
            glEnd();
        glPopMatrix();
    }

    //Pohon pinggir taman depan=============================================================================================================
    for(int i = 0; i < 20; i++){
        glPushMatrix();
            glTranslatef(-16, 0, 35);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44+i*5, 1.8, 21.5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2+i*5, 1.8, 21.3);
                glVertex3f(43.8+i*5, 1.8, 21.3);
                glVertex3f(43.8+i*5, 0.0, 21.3);
                glVertex3f(44.2+i*5, 0.0, 21.3);

                glVertex3f(44.2+i*5, 1.8, 21.7);
                glVertex3f(43.8+i*5, 1.8, 21.7);
                glVertex3f(43.8+i*5, 0.0, 21.7);
                glVertex3f(44.2+i*5, 0.0, 21.7);

                glVertex3f(43.8+i*5, 1.8, 21.7);
                glVertex3f(43.8+i*5, 1.8, 21.3);
                glVertex3f(43.8+i*5, 0.0, 21.3);
                glVertex3f(43.8+i*5, 0.0, 21.7);

                glVertex3f(44.2+i*5, 1.8, 21.7);
                glVertex3f(44.2+i*5, 1.8, 21.3);
                glVertex3f(44.2+i*5, 0.0, 21.3);
                glVertex3f(44.2+i*5, 0.0, 21.7);
            glEnd();
        glPopMatrix();
    }

    //Pohon pinggir taman kiri=============================================================================================================
    for(int i = 0; i < 5; i++){
        glPushMatrix();
            glTranslatef(-16, 0, 11);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44, 1.8, 21.5+i*5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2, 1.8, 21.3+i*5);
                glVertex3f(43.8, 1.8, 21.3+i*5);
                glVertex3f(43.8, 0.0, 21.3+i*5);
                glVertex3f(44.2, 0.0, 21.3+i*5);

                glVertex3f(44.2, 1.8, 21.7+i*5);
                glVertex3f(43.8, 1.8, 21.7+i*5);
                glVertex3f(43.8, 0.0, 21.7+i*5);
                glVertex3f(44.2, 0.0, 21.7+i*5);

                glVertex3f(43.8, 1.8, 21.7+i*5);
                glVertex3f(43.8, 1.8, 21.3+i*5);
                glVertex3f(43.8, 0.0, 21.3+i*5);
                glVertex3f(43.8, 0.0, 21.7+i*5);

                glVertex3f(44.2, 1.8, 21.7+i*5);
                glVertex3f(44.2, 1.8, 21.3+i*5);
                glVertex3f(44.2, 0.0, 21.3+i*5);
                glVertex3f(44.2, 0.0, 21.7+i*5);
            glEnd();
        glPopMatrix();
    }

    //Pohon pinggir taman kanan=============================================================================================================
    for(int i = 0; i < 5; i++){
        glPushMatrix();
            glTranslatef(79, 0, 11);
            glColor3f(0.0, 0.8, 0.0);
            glPushMatrix();
            glTranslatef(44, 1.8, 21.5+i*5);
            glutSolidSphere(0.8, 10, 10);
            glPopMatrix();

            glColor3f(106/255.f, 73/255.f, 64/255.f);
            glBegin(GL_QUADS);
                glVertex3f(44.2, 1.8, 21.3+i*5);
                glVertex3f(43.8, 1.8, 21.3+i*5);
                glVertex3f(43.8, 0.0, 21.3+i*5);
                glVertex3f(44.2, 0.0, 21.3+i*5);

                glVertex3f(44.2, 1.8, 21.7+i*5);
                glVertex3f(43.8, 1.8, 21.7+i*5);
                glVertex3f(43.8, 0.0, 21.7+i*5);
                glVertex3f(44.2, 0.0, 21.7+i*5);

                glVertex3f(43.8, 1.8, 21.7+i*5);
                glVertex3f(43.8, 1.8, 21.3+i*5);
                glVertex3f(43.8, 0.0, 21.3+i*5);
                glVertex3f(43.8, 0.0, 21.7+i*5);

                glVertex3f(44.2, 1.8, 21.7+i*5);
                glVertex3f(44.2, 1.8, 21.3+i*5);
                glVertex3f(44.2, 0.0, 21.3+i*5);
                glVertex3f(44.2, 0.0, 21.7+i*5);
            glEnd();
        glPopMatrix();
    }

    //Kolam 5==============================================================================================================
    glPushMatrix();
    glTranslatef(25, 0, 8);
    glBegin(GL_QUADS);
        glColor3f(0.6, 0.6, 0.6);
        glVertex3f(78.5, 0.03, 33.0);
        glVertex3f(85.0, 0.03, 33.0);
        glVertex3f(85.0, 0.03, 39.0);
        glVertex3f(78.5, 0.03, 39.0);

        glColor4f(0.0, 0.0, 1.0, 0.7);
        glVertex3f(78.5, 0.2, 33.0);
        glVertex3f(85.0, 0.2, 33.0);
        glVertex3f(85.0, 0.2, 39.0);
        glVertex3f(78.5, 0.2, 39.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
        glVertex3f(78.5, 0.3, 33.0);
        glVertex3f(78.5, 0.0, 33.0);
        glVertex3f(85.0, 0.0, 33.0);
        glVertex3f(85.0, 0.3, 33.0);

        glVertex3f(78.5, 0.3, 39.0);
        glVertex3f(78.5, 0.0, 39.0);
        glVertex3f(85.0, 0.0, 39.0);
        glVertex3f(85.0, 0.3, 39.0);

        glVertex3f(78.5, 0.3, 33.0);
        glVertex3f(78.5, 0.0, 33.0);
        glVertex3f(78.5, 0.0, 39.0);
        glVertex3f(78.5, 0.3, 39.0);

        glVertex3f(85, 0.3, 33.0);
        glVertex3f(85, 0.0, 33.0);
        glVertex3f(85, 0.0, 39.0);
        glVertex3f(85, 0.3, 39.0);
    glEnd();
    glPopMatrix();

    //Kolam 6==============================================================================================================
    glPushMatrix();
    glTranslatef(-40, 0, 8);
    glBegin(GL_QUADS);
        glColor3f(0.6, 0.6, 0.6);
        glVertex3f(78.5, 0.03, 33.0);
        glVertex3f(85.0, 0.03, 33.0);
        glVertex3f(85.0, 0.03, 39.0);
        glVertex3f(78.5, 0.03, 39.0);

        glColor4f(0.0, 0.0, 1.0, 0.7);
        glVertex3f(78.5, 0.2, 33.0);
        glVertex3f(85.0, 0.2, 33.0);
        glVertex3f(85.0, 0.2, 39.0);
        glVertex3f(78.5, 0.2, 39.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
        glVertex3f(78.5, 0.3, 33.0);
        glVertex3f(78.5, 0.0, 33.0);
        glVertex3f(85.0, 0.0, 33.0);
        glVertex3f(85.0, 0.3, 33.0);

        glVertex3f(78.5, 0.3, 39.0);
        glVertex3f(78.5, 0.0, 39.0);
        glVertex3f(85.0, 0.0, 39.0);
        glVertex3f(85.0, 0.3, 39.0);

        glVertex3f(78.5, 0.3, 33.0);
        glVertex3f(78.5, 0.0, 33.0);
        glVertex3f(78.5, 0.0, 39.0);
        glVertex3f(78.5, 0.3, 39.0);

        glVertex3f(85, 0.3, 33.0);
        glVertex3f(85, 0.0, 33.0);
        glVertex3f(85, 0.0, 39.0);
        glVertex3f(85, 0.3, 39.0);
    glEnd();
    glPopMatrix();
}

void entrance(){
    glPushMatrix();
        glRotatef(45, 0, 0.01, 0);
        glTranslatef(-23.8, 0, 5);
        //Lantai
        for(int i = 0; i < 6; i += 2){
            glBegin(GL_QUADS);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(26.0, 0.01, 22.0+2*i); //atas
            glVertex3f(22.0, 0.01, 22.0+2*i);
            glVertex3f(22.0, 0.01, 24.0+2*i);
            glVertex3f(26.0, 0.01, 24.0+2*i);
        glEnd();
        }

        //atas
        glBegin(GL_QUADS);
            glColor3f(133/255.f,115/255.f,115/255.f);
            glVertex3f(27.0, 3.8, 27.0); //atas
            glVertex3f(21.0, 3.8, 27.0);
            glVertex3f(21.0, 3.8, 27.2);
            glVertex3f(27.0, 3.8, 27.2);

            glVertex3f(27.0, 3.0, 27.0); //bawah
            glVertex3f(21.0, 3.0, 27.0);
            glVertex3f(21.0, 3.0, 27.2);
            glVertex3f(27.0, 3.0, 27.2);

            glColor3f(123/255.f,105/255.f,105/255.f);
            glVertex3f(27.0, 3.8, 27.0); //belakang
            glVertex3f(21.0, 3.8, 27.0);
            glVertex3f(21.0, 3.0, 27.0);
            glVertex3f(27.0, 3.0, 27.0);

            glVertex3f(27.0, 3.8, 27.2); //depan
            glVertex3f(21.0, 3.8, 27.2);
            glVertex3f(21.0, 3.0, 27.2);
            glVertex3f(27.0, 3.0, 27.2);
        glEnd();
        //pilar kanan
        glBegin(GL_QUADS);
            glColor3f(133/255.f,115/255.f,115/255.f);
            glVertex3f(27.0, 3.8, 27.2); //kanan 1
            glVertex3f(27.0, 3.8, 27.0);
            glVertex3f(27.0, 0.0, 27.0);
            glVertex3f(27.0, 0.0, 27.2);

            glVertex3f(26.0, 3.0, 27.2); //kiri
            glVertex3f(26.0, 3.0, 27.0);
            glVertex3f(26.0, 0.0, 27.0);
            glVertex3f(26.0, 0.0, 27.2);

            glColor3f(123/255.f,105/255.f,105/255.f);
            glVertex3f(26.0, 3.0, 27.0); //depan
            glVertex3f(27.0, 3.0, 27.0);
            glVertex3f(27.0, 0.0, 27.0);
            glVertex3f(26.0, 0.0, 27.0);

            glVertex3f(26.0, 3.0, 27.2); //belakang
            glVertex3f(27.0, 3.0, 27.2);
            glVertex3f(27.0, 0.0, 27.2);
            glVertex3f(26.0, 0.0, 27.2);
        glEnd();

        glPushMatrix();
            glTranslatef(-5, 0, 0);
            glBegin(GL_QUADS);
            glColor3f(133/255.f,115/255.f,115/255.f);
            glVertex3f(27.0, 3.0, 27.2); //kanan 1
            glVertex3f(27.0, 3.0, 27.0);
            glVertex3f(27.0, 0.0, 27.0);
            glVertex3f(27.0, 0.0, 27.2);

            glVertex3f(26.0, 3.8, 27.2); //kiri
            glVertex3f(26.0, 3.8, 27.0);
            glVertex3f(26.0, 0.0, 27.0);
            glVertex3f(26.0, 0.0, 27.2);

            glColor3f(123/255.f,105/255.f,105/255.f);
            glVertex3f(26.0, 3.0, 27.0); //depan
            glVertex3f(27.0, 3.0, 27.0);
            glVertex3f(27.0, 0.0, 27.0);
            glVertex3f(26.0, 0.0, 27.0);

            glVertex3f(26.0, 3.0, 27.2); //belakang
            glVertex3f(27.0, 3.0, 27.2);
            glVertex3f(27.0, 0.0, 27.2);
            glVertex3f(26.0, 0.0, 27.2);
        glEnd();
        glPopMatrix();

    glPopMatrix();
}

void tengah_tingkat_1(){
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(88.0, 0.0, 0.0);
    glVertex3f(88.0, 4.0, 0.0);
    glVertex3f(67.5, 4.0, 0.0);
    glVertex3f(67.5, 0.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor4f(0.0,0.0,0.0,0.7);
    glVertex3f(88.0, 0.0, 14.0);
    glVertex3f(88.0, 4.0, 14.0);
    glVertex3f(67.5, 4.0, 14.0);
    glVertex3f(67.5, 0.0, 14.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(67.5, 0.0, 0.0);
    glVertex3f(67.5, 4.0, 0.0);
    glVertex3f(67.5, 4.0, 14.0);
    glVertex3f(67.5, 0.0, 14.0);
    glEnd();

    //kanan atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(88.0, 0.0, 0.0);
    glVertex3f(88.0, 4.0, 0.0);
    glVertex3f(88.0, 4.0, 14.0);
    glVertex3f(88.0, 0.0, 14.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(88.0, 4.0, 00.0);
    glVertex3f(88.0, 4.0, 17.0);
    glVertex3f(67.5, 4.0, 17.0);
    glVertex3f(67.5, 4.0, 0.0);
    glEnd();
}

void pilar_tengah(){
    glPushMatrix();
    glTranslatef(-23, 0, 0);
    for(int i = 0 ; i<6 ; i++){
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4, 0.0, 17.0);
        glVertex3f(90.5+i*4, 4.0, 17.0);
        glVertex3f(91.0+i*4, 4.0, 17.0);
        glVertex3f(91.0+i*4, 0.0, 17.0);
        glEnd();

        //belakang
        glBegin(GL_QUADS);
        glVertex3f(90.5+i*4, 0.0, 16.5);
        glVertex3f(90.5+i*4, 4.0, 16.5);
        glVertex3f(91.0+i*4, 4.0, 16.5);
        glVertex3f(91.0+i*4, 0.0, 16.5);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glVertex3f(90.5+i*4, 0.0, 16.5);
        glVertex3f(90.5+i*4, 4.0, 16.5);
        glVertex3f(90.5+i*4, 4.0, 17.0);
        glVertex3f(90.5+i*4, 0.0, 17.0);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glVertex3f(91.0+i*4, 0.0, 16.5);
        glVertex3f(91.0+i*4, 4.0, 16.5);
        glVertex3f(91.0+i*4, 4.0, 17.0);
        glVertex3f(91.0+i*4, 0.0, 17.0);
        glEnd();

        for(int i = 0 ; i<6 ; i++){
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4, 0.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 0.0, 15.5);
        glEnd();

        //belakang
        glBegin(GL_QUADS);
        glVertex3f(90.5+i*4, 0.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 4.0, 15.0);
        glVertex3f(91.0+i*4, 0.0, 15.0);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glVertex3f(90.5+i*4, 0.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.0);
        glVertex3f(90.5+i*4, 0.0, 15.0);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glVertex3f(91.0+i*4, 0.0, 15.0);
        glVertex3f(91.0+i*4, 4.0, 15.0);
        glVertex3f(91.0+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 0.0, 15.5);
        glEnd();
    }

    for(int i = 0 ; i<6 ; i++){
        //depan
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4, 0.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 0.0, 15.5);
        glEnd();

        //belakang
        glBegin(GL_QUADS);
        glVertex3f(90.5+i*4, 0.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 4.0, 15.0);
        glVertex3f(91.0+i*4, 0.0, 15.0);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glVertex3f(90.5+i*4, 0.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.5);
        glVertex3f(90.5+i*4, 4.0, 15.0);
        glVertex3f(90.5+i*4, 0.0, 15.0);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glVertex3f(91.0+i*4, 0.0, 15.0);
        glVertex3f(91.0+i*4, 4.0, 15.0);
        glVertex3f(91.0+i*4, 4.0, 15.5);
        glVertex3f(91.0+i*4, 0.0, 15.5);
        glEnd();
        }
    }

    glPopMatrix();
}

void tengah_tingkat_2(){
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(67.5, 4.0, 0.0);
    glVertex3f(67.5, 8.0, 0.0);
    glVertex3f(88.0, 8.0, 0.0);
    glVertex3f(88.0, 4.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor4f(0.95,0.75,0.95,0.95);
    glVertex3f(67.5, 4.0, 15.0);
    glVertex3f(67.5, 8.0, 15.0);
    glVertex3f(88.0, 8.0, 15.0);
    glVertex3f(88.0, 4.0, 15.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(67.5, 4.0, 0.0);
    glVertex3f(67.5, 8.0, 0.0);
    glVertex3f(67.5, 8.0, 15.0);
    glVertex3f(67.5, 4.0, 15.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(88, 4.0, 0.0);
    glVertex3f(88, 8.0, 0.0);
    glVertex3f(88, 8.0, 15.0);
    glVertex3f(88, 4.0, 15.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.87,0.65,0.4);
    glVertex3f(67.5, 8.0, 00.0);
    glVertex3f(67.5, 8.0, 15.0);
    glVertex3f(88.0, 8.0, 15.0);
    glVertex3f(88.0, 8.0, 0.0);
    glEnd();
}

void seperempatBola(int scaley, int scalex, GLfloat r) {
   int i, j;
   GLfloat v[scalex*scaley][10];

   for (i=0; i<scalex; ++i) {
     for (j=0; j<scaley; ++j) {
       v[i*scaley+j][0]=r*cos(j*1*M_PI/scaley)*cos(i*M_PI/(2*scalex));
       v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
       v[i*scaley+j][2]=r*sin(j*1*M_PI/scaley)*cos(i*M_PI/(2*scalex));
     }
   }

   glBegin(GL_QUADS);
     for (i=0; i<scalex-1; ++i) {
       for (j=0; j<scaley; ++j) {
         glVertex3fv(v[i*scaley+j]);
         glVertex3fv(v[i*scaley+(j+1)%scaley]);
         glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
         glVertex3fv(v[(i+1)*scaley+j]);
       }
     }
   glEnd();
 }

void setengahLingkaran(){
    float radius = 10.25;
    float twoPI = 2 * M_PI;

    glBegin(GL_TRIANGLE_FAN);

    for (float i = M_PI; i <= twoPI; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}

void lisKacaDome(){
    glColor4f(0.4, 0.4, 0.4, 0.7);
    glBegin(GL_QUADS);
        glVertex3f(67.5, 5.0, 15.02);
        glVertex3f(67.5, 6.0, 15.02);
        glVertex3f(88.0, 6.0, 15.02);
        glVertex3f(88.0, 5.0, 15.02);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(67.5, 8.0, 15.02);
        glVertex3f(67.55, 9.0, 15.02);
        glVertex3f(87.95, 9.0, 15.02);
        glVertex3f(88.0, 8.0, 15.02);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(68.0, 11.0, 15.02);
        glVertex3f(68.3, 12.0, 15.02);
        glVertex3f(87.2, 12.0, 15.02);
        glVertex3f(87.5, 11.0, 15.02);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(69.5, 14.0, 15.02);
        glVertex3f(70.3, 15.0, 15.02);
        glVertex3f(85.2, 15.0, 15.02);
        glVertex3f(86.0, 14.0, 15.02);
    glEnd();

    //Lis samping
    glColor3f(0.9,0.9,0.9);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(67.5, 4.0, 15.0);
        glVertex3f(67.5, 8.0, 15.0);
        glVertex3f(88.0, 8.0, 15.0);
        glVertex3f(88.0, 4.0, 15.0);
    glEnd();

    //Kanopi depan
    glColor3f(0.5,0.5,0.5);
    glLineWidth(5);
    glBegin(GL_POLYGON);
        glVertex3f(74.5, 8.0, 15.0);
        glVertex3f(74.5, 8.0, 17.0);
        glVertex3f(81.0, 8.0, 17.0);
        glVertex3f(81.0, 8.0, 15.0);
    glEnd();

    //Lis depan
    glColor3f(0.7,0.7,0.7);
    glLineWidth(5);
    glBegin(GL_QUADS);
        glVertex3f(68.5, 9.0, 15.0);
        glVertex3f(68.5, 9.0, 17.0);
        glVertex3f(75.0, 9.0, 17.0);
        glVertex3f(75.0, 9.0, 15.0);

        glVertex3f(68.5, 9.5, 15.0);
        glVertex3f(68.5, 9.5, 17.0);
        glVertex3f(75.0, 9.5, 17.0);
        glVertex3f(75.0, 9.5, 15.0);

        glColor3f(0.75,0.75,0.75);

        glVertex3f(68.5, 9.5, 17.0);
        glVertex3f(68.5, 9.0, 17.0);
        glVertex3f(75.0, 9.0, 17.0);
        glVertex3f(75.0, 9.5, 17.0);

        glColor3f(0.78,0.78,0.78);

        glVertex3f(75.0, 9.5, 15.0);
        glVertex3f(75.0, 9.0, 15.0);
        glVertex3f(75.0, 9.0, 17.0);
        glVertex3f(75.0, 9.5, 17.0);

        glVertex3f(68.5, 9.5, 15.0);
        glVertex3f(68.5, 9.0, 15.0);
        glVertex3f(68.5, 9.0, 17.0);
        glVertex3f(68.5, 9.5, 17.0);
    glEnd();

}

void lisSetengahLingkaran(){
    float radius = 10.26;
    float twoPI = 2 * M_PI;

    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}

void mobil(){
glPushMatrix();
    glPushMatrix();
    glTranslated(140.0-x_pos, 1.0, 60.0);
    glScalef(2.0, 2.0, 2.0);
    glPushMatrix();
        glColor3f(0.95, 0.95, 0.95);              // body
        glScalef(4,1,2);
        glutSolidCube(.5);
        glTranslatef(-.05,.3,0);
        glColor3f(0.95, 0.95, 0.95);
        glScalef(0.6,3,2);
        glutSolidCube(.25);
        glTranslatef(-.12,.001,-.001);
        glScalef(1,1.8,2.48);
        glRotatef(230, 0, 0, 250);
        glutSolidCube(.1);
        glPopMatrix();
        glTranslatef(0,0,.5);
        glPushMatrix();
        glTranslatef(-.4,-.2,0);
        glColor3f(0.4, 0.4, 0.4);
        glutSolidTorus(.1,.2,8,8);       // wheel
        glTranslatef(1,0,0);
        glutSolidTorus(.1,.2,8,8);       // wheel
        glPopMatrix();
        glTranslatef(0,0,-1);
        glPushMatrix();
        glTranslatef(-.4,-.2,0);
        glutSolidTorus(.1,.2,8,8);       // wheel
        glTranslatef(1,0,0);
        glutSolidTorus(.1,.2,8,8);       // wheel
        glPopMatrix();
        glPopMatrix();
glPopMatrix();
glFlush();
}

void kapsul_tengah(){
    //pagar antar kapsul
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(88.0, 4.0, 17.0);
        glVertex3f(88.0, 5.5, 17.0);
        glVertex3f(67.5, 5.5, 17.0);
        glVertex3f(67.5, 4.0, 17.0);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(88.0, 4.0, 16.5);
        glVertex3f(88.0, 5.5, 16.5);
        glVertex3f(67.5, 5.5, 16.5);
        glVertex3f(67.5, 4.0, 16.5);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(88.0, 5.5, 16.5);
        glVertex3f(88.0, 5.5, 17.0);
        glVertex3f(67.5, 5.5, 17.0);
        glVertex3f(67.5, 5.5, 16.5);
        glEnd();

    glPushMatrix();
    glTranslatef(-21, 0, 0);
    for(int i = 0 ; i<5 ; i++){
        //bawah
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4 , 4.1 , 17.5); // 17.5
        glVertex3f(91.0+i*4 , 4.1 , 17.5); // 17.5
        glVertex3f(91.5+i*4 , 4.1 , 17.0); // 17.0
        glVertex3f(91.5+i*4 , 4.1 , 16.5); // 16.5
        glVertex3f(91.0+i*4 , 4.1 , 16.0); // 16.0
        glVertex3f(90.5+i*4 , 4.1 , 16.0); // 16.0
        glVertex3f(90.0+i*4 , 4.1 , 16.5); // 16.5
        glVertex3f(90.0+i*4 , 4.1 , 17.0); // 17.0
        glEnd();
        //atas
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4 , 7.1 , 17.5); // 17.5
        glVertex3f(91.0+i*4 , 7.1 , 17.5); // 17.5
        glVertex3f(91.5+i*4 , 7.1 , 17.0); // 17.0
        glVertex3f(91.5+i*4 , 7.1 , 16.5); // 16.5
        glVertex3f(91.0+i*4 , 7.1 , 16.0); // 16.0
        glVertex3f(90.5+i*4 , 7.1 , 16.0); // 16.0
        glVertex3f(90.0+i*4 , 7.1 , 16.5); // 16.5
        glVertex3f(90.0+i*4 , 7.1 , 17.0); // 17.0
        glEnd();

        //selimut=============================
        //1
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 7.1 , 16.0);
        glVertex3f(90.5+i*4 , 7.1 , 16.0);
        glEnd();
        //2
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(91.5+i*4 , 7.1 , 17.0);
        glVertex3f(91.0+i*4 , 7.1 , 17.5);
        glEnd();
        //3
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(91.5+i*4 , 7.1 , 16.5);
        glVertex3f(91.5+i*4 , 7.1 , 17.0);
        glEnd();
        //4
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 7.1 , 16.0);
        glVertex3f(91.5+i*4 , 7.1 , 16.5);
        glEnd();
        //5
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 4.1 , 17.5);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(91.0+i*4 , 7.1 , 17.5);
        glVertex3f(90.5+i*4 , 7.1 , 17.5);
        glEnd();
        //6
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(90.0+i*4 , 4.1 , 16.5);
        glVertex3f(90.0+i*4 , 7.1 , 16.5);
        glVertex3f(90.5+i*4 , 7.1 , 16.0);
        glEnd();
        //7
        glBegin(GL_QUADS);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.0+i*4 , 4.1 , 17.0);
        glVertex3f(90.0+i*4, 4.1 , 16.5);
        glVertex3f(90.0+i*4 , 7.1 , 16.5);
        glVertex3f(90.0+i*4 , 7.1 , 17.0);
        glEnd();
        //8
        glBegin(GL_QUADS);
        glColor3f(0.9,0.7,0.5);
        glVertex3f(90.0+i*4 , 4.1 , 17.0);
        glVertex3f(90.5+i*4 , 4.1 , 17.5);
        glVertex3f(90.5+i*4 , 7.1 , 17.5);
        glVertex3f(90.0+i*4 , 7.1 , 17.0);
        glEnd();

        //lancip atas
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 7.1 , 17.4);
        glVertex3f(91.0+i*4 , 7.1 , 17.4);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glVertex3f(91.0+i*4 , 7.1 , 17.4);
        glVertex3f(91.4+i*4 , 7.1 , 17.0);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glVertex3f(91.4+i*4 , 7.1 , 17.0);
        glVertex3f(91.4+i*4 , 7.1 , 16.5);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glVertex3f(91.4+i*4 , 7.1 , 16.5);
        glVertex3f(91.0+i*4 , 7.1 , 16.1);
        glVertex3f(90.75+i*4, 7.7 , 16.75);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 7.1 , 16.1);
        glVertex3f(91.0+i*4 , 7.1 , 16.1);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 7.1 , 16.1);
        glVertex3f(90.1+i*4 , 7.1 , 16.5);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glVertex3f(90.1+i*4 , 7.1 , 17.0);
        glVertex3f(90.1+i*4, 7.1 , 16.5);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glVertex3f(90.1+i*4 , 7.1 , 17.0);
        glVertex3f(90.5+i*4 , 7.1 , 17.4);
        glVertex3f(90.75+i*4 , 7.7 , 16.75);
        glEnd();


         //lancip bawah
        //1
        glBegin(GL_TRIANGLES);
        glColor3f(250/255.f, 240/255.f, 202/255.f);
        glVertex3f(90.5+i*4 , 4.1 , 17.5);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //2
        glBegin(GL_TRIANGLES);
        glVertex3f(91.0+i*4 , 4.1 , 17.5);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //3
        glBegin(GL_TRIANGLES);
        glVertex3f(91.5+i*4 , 4.1 , 17.0);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //4
        glBegin(GL_TRIANGLES);
        glVertex3f(91.5+i*4 , 4.1 , 16.5);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //5
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(91.0+i*4 , 4.1 , 16.0);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //6
        glBegin(GL_TRIANGLES);
        glVertex3f(90.5+i*4 , 4.1 , 16.0);
        glVertex3f(90.0+i*4 , 4.1 , 16.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //7
        glBegin(GL_TRIANGLES);
        glVertex3f(90.0 +i*4, 4.1 , 17.0);
        glVertex3f(90.0 +i*4, 4.1 , 16.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
        //8
        glBegin(GL_TRIANGLES);
        glVertex3f(90.0+i*4 , 4.1 , 17.0);
        glVertex3f(90.5 +i*4, 4.1 , 17.5);
        glVertex3f(90.75+i*4 , 3.5 , 16.75);
        glEnd();
    }
    glPopMatrix();
}

//===========================================Gedung Tambahan====================================================

void fondasi(){

    glPushMatrix();
    glTranslatef(-86.5,0.0,-48.0);

    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);//f_top
    glVertex3f( 10.0, 200, 8.0);
    glVertex3f(163.0, 200, 8.0);
    glVertex3f(163.0, 200,88.0);
    glVertex3f( 10.0, 200,88.0);
    glEnd();

    glBegin(GL_QUADS);//f_top
    glVertex3f( 10.0, 180, 8.0);
    glVertex3f( 10.0, 200, 8.0);
    glVertex3f( 10.0, 200,88.0);
    glVertex3f( 10.0, 180,88.0);
    glEnd();

    glBegin(GL_QUADS);//f_top
    glVertex3f(163.0, 180, 8.0);
    glVertex3f(163.0, 200, 8.0);
    glVertex3f(163.0, 200,88.0);
    glVertex3f(163.0, 180,88.0);
    glEnd();

    glBegin(GL_QUADS);//f_top
    glVertex3f( 10.0, 180,88.0);
    glVertex3f( 10.0, 200,88.0);
    glVertex3f(163.0, 200,88.0);
    glVertex3f(163.0, 180,88.0);
    glEnd();

    glBegin(GL_QUADS);//f_top
    glVertex3f( 10.0, 180, 8.0);
    glVertex3f( 10.0, 200, 8.0);
    glVertex3f(163.0, 200, 8.0);
    glVertex3f(163.0, 180, 8.0);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);//f_atas
    glVertex3f(  0.0, 180,-2.0);
    glVertex3f(173.0, 180,-2.0);
    glVertex3f(173.0, 180,98.0);
    glVertex3f(  0.0, 180,98.0);
    glEnd();

    for(int i=0; i<4; i++){
    int y = 40*i;
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);//f_bawah
    glVertex3f(  0.0, y, 0.0);
    glVertex3f(173.0, y, 0.0);
    glVertex3f(173.0, y,96.0);
    glVertex3f(  0.0, y,96.0);
    glEnd();

    glColor3f(0.4,0.1,0.0);
    glBegin(GL_QUADS);//f_dpn
    glVertex3f(  0.0, y+7.0, 96.0);
    glVertex3f(173.0, y+7.0, 96.0);
    glVertex3f(173.0, y, 96.0);
    glVertex3f(  0.0, y, 96.0);
    glEnd();
    glBegin(GL_QUADS);//f_blk
    glVertex3f(  0.0, y+7.0, 0.0);
    glVertex3f(173.0, y+7.0, 0.0);
    glVertex3f(173.0, y, 0.0);
    glVertex3f(  0.0, y, 0.0);
    glEnd();
    }
    glColor4f(1.0,1.0,1.0,0.8);
    glBegin(GL_QUADS);//kacadpn
    glVertex3f(  0.0, 180.0, 95.8);
    glVertex3f(173.0, 180.0, 95.8);
    glVertex3f(173.0, 0.0, 95.8);
    glVertex3f(  0.0, 0.0, 95.8);
    glEnd();
    glBegin(GL_QUADS);//kacablk
    glVertex3f(  0.0, 180.0, 0.2);
    glVertex3f(173.0, 180.0, 0.2);
    glVertex3f(173.0, 0.0, 0.2);
    glVertex3f(  0.0, 0.0, 0.2);
    glEnd();

    glColor4f(0.0,0.5,0.8,0.4);
    glBegin(GL_QUADS);//kacadpn
    glVertex3f(  0.0, 180.0, 96.01);
    glVertex3f(173.0, 180.0, 96.01);
    glVertex3f(173.0, 0.0, 96.01);
    glVertex3f(  0.0, 0.0, 96.01);
    glEnd();
    glBegin(GL_QUADS);//kacablk
    glVertex3f(  0.0, 180.0, -0.01);
    glVertex3f(173.0, 180.0, -0.01);
    glVertex3f(173.0, 0.0, -0.01);
    glVertex3f(  0.0, 0.0, -0.01);
    glEnd();
    glPopMatrix();

    //Depan
    glPushMatrix();
    glTranslatef(-86.5,0.0,-48.0);
    glColor3f(1.0,0.8,0.7);
    glBegin(GL_QUADS);//plrdpn
    glVertex3f(0.0, 180.0, 98.0);
    glVertex3f(7.0, 180.0, 98.0);
    glVertex3f(7.0, -10.0, 98.0);
    glVertex3f(0.0, -10.0, 98.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrkiri
    glVertex3f(0.0, 180.0, 94.0);
    glVertex3f(0.0, 180.0, 98.0);
    glVertex3f(0.0, -10.0, 98.0);
    glVertex3f(0.0, -10.0, 94.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrknn
    glVertex3f(7.0, 180.0, 94.0);
    glVertex3f(7.0, 180.0, 98.0);
    glVertex3f(7.0, -10.0, 98.0);
    glVertex3f(7.0, -10.0, 94.0);
    glEnd();

    for(int i=0;i<6;i++){
    glTranslatef(27.67,0.0,0.0);
    glColor3f(1.0,0.8,0.7);
    glBegin(GL_QUADS);//plrdpn
    glVertex3f(0.0, 180.0, 98.0);
    glVertex3f(7.0, 180.0, 98.0);
    glVertex3f(7.0, -10.0, 98.0);
    glVertex3f(0.0, -10.0, 98.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrkiri
    glVertex3f(0.0, 180.0, 94.0);
    glVertex3f(0.0, 180.0, 98.0);
    glVertex3f(0.0, -10.0, 98.0);
    glVertex3f(0.0, -10.0, 94.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrknn
    glVertex3f(7.0, 180.0, 94.0);
    glVertex3f(7.0, 180.0, 98.0);
    glVertex3f(7.0, -10.0, 98.0);
    glVertex3f(7.0, -10.0, 94.0);
    glEnd();
    }

    glPopMatrix();

    //Belakang
    glPushMatrix();
    glTranslatef(-86.5,0.0,-48.0);
    glColor3f(1.0,0.8,0.7);
    glBegin(GL_QUADS);//plrdpn
    glVertex3f(0.0, 180.0, -2.0);
    glVertex3f(7.0, 180.0, -2.0);
    glVertex3f(7.0, -10.0, -2.0);
    glVertex3f(0.0, -10.0, -2.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrkiri
    glVertex3f(0.0, 180.0,  2.0);
    glVertex3f(0.0, 180.0, -2.0);
    glVertex3f(0.0, -10.0, -2.0);
    glVertex3f(0.0, -10.0,  2.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrknn
    glVertex3f(7.0, 180.0,  2.0);
    glVertex3f(7.0, 180.0, -2.0);
    glVertex3f(7.0, -10.0, -2.0);
    glVertex3f(7.0, -10.0,  2.0);
    glEnd();

    for(int i=0;i<6;i++){
    glTranslatef(27.67,0.0,0.0);
    glColor3f(1.0,0.8,0.7);
    glBegin(GL_QUADS);//plrdpn
    glVertex3f(0.0, 180.0, -2.0);
    glVertex3f(7.0, 180.0, -2.0);
    glVertex3f(7.0, -10.0, -2.0);
    glVertex3f(0.0, -10.0, -2.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrkiri
    glVertex3f(0.0, 180.0,  2.0);
    glVertex3f(0.0, 180.0, -2.0);
    glVertex3f(0.0, -10.0, -2.0);
    glVertex3f(0.0, -10.0,  2.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//plrknn
    glVertex3f(7.0, 180.0,  2.0);
    glVertex3f(7.0, 180.0, -2.0);
    glVertex3f(7.0, -10.0, -2.0);
    glVertex3f(7.0, -10.0,  2.0);
    glEnd();
    }

    glPopMatrix();
}

void atap(){
    glPushMatrix();
    glTranslatef(-86.5,0.0,-48.0);

    glColor3f(1.0,0.8,0.7);
    glBegin(GL_QUADS);//front
    glVertex3f( 10.0, 200,88.0);
    glVertex3f(163.0, 200,88.0);
    glVertex3f(173.0, 185,98.0);
    glVertex3f( 00.0, 185,98.0);
    glEnd();

    glBegin(GL_QUADS);//back
    glVertex3f( 10.0, 200, 8.0);
    glVertex3f(163.0, 200, 8.0);
    glVertex3f(173.0, 185,-2.0);
    glVertex3f( 00.0, 185,-2.0);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//right
    glVertex3f(163.0, 200,88.0);
    glVertex3f(163.0, 200, 8.0);
    glVertex3f(173.0, 185,-2.0);
    glVertex3f(173.0, 185,98.0);
    glEnd();

    glBegin(GL_QUADS);//right
    glVertex3f( 10.0, 200,88.0);
    glVertex3f( 10.0, 200, 8.0);
    glVertex3f( 0.0, 185,-2.0);
    glVertex3f( 0.0, 185,98.0);
    glEnd();

    //
    glColor3f(0.95,0.75,0.65);
    glBegin(GL_QUADS);//front
    glVertex3f(  0.0, 180, 98.0);
    glVertex3f(173.0, 180, 98.0);
    glVertex3f(178.0, 175,103.0);
    glVertex3f( -5.0, 175,103.0);
    glEnd();

    glBegin(GL_QUADS);//back
    glVertex3f(  0.0, 180,-2.0);
    glVertex3f(173.0, 180,-2.0);
    glVertex3f(178.0, 175,-7.0);
    glVertex3f( -5.0, 175,-7.0);
    glEnd();

    glColor3f(0.85,0.65,0.45);
    glBegin(GL_QUADS);//right
    glVertex3f(173.0, 180,98.0);
    glVertex3f(173.0, 180,-2.0);
    glVertex3f(178.0, 175,-7.0);
    glVertex3f(178.0, 175,103.0);
    glEnd();

    glBegin(GL_QUADS);//right
    glVertex3f( 0.0, 180,98.0);
    glVertex3f( 0.0, 180,-2.0);
    glVertex3f(-5.0, 175,-7.0);
    glVertex3f(-5.0, 175,103.0);
    glEnd();

    glPopMatrix();
}

void gedungtambahan(){
    atap();
    fondasi();
    glPushMatrix();
    glTranslatef(-86.5,0.0,-48.0);

    glColor3f(0.95,0.75,0.65);
    glBegin(GL_QUADS);//kacadpn
    glVertex3f(  0.0, 180.0, 96.02);
    glVertex3f(173.0, 180.0, 96.02);
    glVertex3f(173.0, 160.0, 96.02);
    glVertex3f(  0.0, 160.0, 96.02);
    glEnd();
    glBegin(GL_QUADS);//kacablk
    glVertex3f(  0.0, 180.0, -0.02);
    glVertex3f(173.0, 180.0, -0.02);
    glVertex3f(173.0, 160.0, -0.02);
    glVertex3f(  0.0, 160.0, -0.02);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//dindingknn
    glVertex3f(173.01, 180.0,  2.0);
    glVertex3f(173.01, 180.0, 98.0);
    glVertex3f(173.01, -10.0, 98.0);
    glVertex3f(173.01, -10.0,  2.0);
    glEnd();
    glColor3f(0.9,0.7,0.5);
    glBegin(GL_QUADS);//dindingkiri
    glVertex3f(-0.01, 180.0,  2.0);
    glVertex3f(-0.01, 180.0, 98.0);
    glVertex3f(-0.01, -10.0, 98.0);
    glVertex3f(-0.01, -10.0,  2.0);
    glEnd();

    glColor3f(0.9,0.7,0.6);
    glBegin(GL_QUADS);//f_dpn
    glVertex3f(  0.0,  0.0, 96.0);
    glVertex3f(173.0,  0.0, 96.0);
    glVertex3f(173.0,-10.0, 96.0);
    glVertex3f(  0.0,-10.0, 96.0);
    glEnd();
    glBegin(GL_QUADS);//f_blkng
    glVertex3f(  0.0,  0.0, 0.0);
    glVertex3f(173.0,  0.0, 0.0);
    glVertex3f(173.0,-10.0, 0.0);
    glVertex3f(  0.0,-10.0, 0.0);
    glEnd();
    glPopMatrix();
}

void scalegedung(){
    glPushMatrix();
    glScalef(0.09,0.05,0.095);
    gedungtambahan();
    glPopMatrix();
}

void tingkat1_kiri_gedungA(){

    //tingkat 1 kedepan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(17.0, 4.0, 0.0);
    glVertex3f(17.0, 4.0, 52.0);
    glVertex3f(0.0, 4.0, 52.0);
    glEnd();

    //tingkat 1 kekanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(17.0, 4.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(67.0, 4.0, 17.0);
    glVertex3f(17.0, 4.0, 17.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(67.0, 0.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(0.0, 4.0, 0.0);
    glEnd();

     //Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(0.0, 4.0, 52.0);
    glVertex3f(0.0, 0.0, 52.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.2);
    glVertex3f(0.0, 0.0, 52.0);
    glVertex3f(17.0, 0.0, 52.0);
    glVertex3f(17.0, 4.0, 52.0);
    glVertex3f(0.0, 4.0, 52.0);
    glEnd();

    //tingkat 1 kekanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(17.0, 4.0, 17.0);
    glVertex3f(67.0, 4.0, 17.0);
    glVertex3f(67.0, 0.0, 17.0);
    glVertex3f(17.0, 0.0, 17.0);
    glEnd();

    //tingkat 1 kedepan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(17.0, 4.0, 17.0);
    glVertex3f(17.0, 4.0, 52.0);
    glVertex3f(17.0, 0.0, 52.0);
    glVertex3f(17.0, 0.0, 17.0);
    glEnd();

    //tingkat 1 kekanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(67.0, 4.0, 17.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(67.0, 0.0, 0.0);
    glVertex3f(67.0, 0.0, 17.0);
    glEnd();
}

void tingkat2_kiri_gedungA(){
//tingkat 2 kedepan
glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(15.0, 8.0, 52.0);
    glVertex3f(0.0, 8.0, 52.0);
    glEnd();

        //tingkat 2 kekanan
glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(15.0, 8.0, 15.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(0.0, 4.0, 0.0);
    glEnd();

     //Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 8.0, 52.0);
    glVertex3f(0.0, 4.0, 52.0);
    glVertex3f(0.0, 4.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(0.0, 4.0, 52.0);
    glVertex3f(15.0, 4.0, 52.0);
    glVertex3f(15.0, 8.0, 52.0);
    glVertex3f(0.0, 8.0, 52.0);
    glEnd();

     //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(15.0, 4.0, 0.0);
    glVertex3f(15.0, 4.0, 52.0);
    glVertex3f(15.0, 8.0, 52.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(67.0, 4.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glEnd();

    //tingkat 2 kekanan 2
glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.5);
    glVertex3f(15.0, 4.0, 15.0);
    glVertex3f(67.0, 4.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(15.0, 8.0, 15.0);
    glEnd();
}

void tingkat3_kiri_gedungA(){
//tingkat 3 kekanan
glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(57.0, 12.0, 0.0);
    glVertex3f(67.0, 12.0, 0.0);
    glVertex3f(67.0, 12.0, 15.0);
    glVertex3f(57.0, 12.0, 15.0);
    glEnd();

    //tingkat 3 kekanan
glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(10.0, 12.0, 0.0);
    glVertex3f(57.0, 12.0, 0.0);
    glVertex3f(57.0, 12.0, 10.0);
    glVertex3f(10.0, 12.0, 10.0);
    glEnd();

    //tingkat 3 kedepan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(0.0, 12.0, 0.0);
    glVertex3f(10.0, 12.0, 0.0);
    glVertex3f(10.0, 12.0, 52.0);
    glVertex3f(0.0, 12.0, 52.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 12.0, 0.0);
    glVertex3f(0.0, 12.0, 0.0);
    glEnd();

    //Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 8.0, 52.0);
    glVertex3f(0.0, 12.0, 52.0);
    glVertex3f(0.0, 12.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(0.0, 8.0, 52.0);
    glVertex3f(10.0, 8.0, 52.0);
    glVertex3f(10.0, 12.0, 52.0);
    glVertex3f(0.0, 12.0, 52.0);
    glEnd();

    //depan kotak
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(57.0, 8.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(67.0, 12.0, 15.0);
    glVertex3f(57.0, 12.0, 15.0);
    glEnd();

    //tingkat 3 kekanan depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(10.0, 8.0, 10.0);
    glVertex3f(57.0, 8.0, 10.0);
    glVertex3f(57.0, 12.0, 10.0);
    glVertex3f(10.0, 12.0, 10.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(10.0, 8.0, 0.0);
    glVertex3f(10.0, 12.0, 0.0);
    glVertex3f(10.0, 12.0, 52.0);
    glVertex3f(10.0, 8.0, 52.0);
    glEnd();

    //kanan 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.5);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 12.0, 0.0);
    glVertex3f(67.0, 12.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glEnd();

    //kanan 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.5);
    glVertex3f(57.0, 8.0, 0.0);
    glVertex3f(57.0, 12.0, 0.0);
    glVertex3f(57.0, 12.0, 15.0);
    glVertex3f(57.0, 8.0, 15.0);
    glEnd();
}

void gedungA(){
    tingkat1_kiri_gedungA();
    tingkat2_kiri_gedungA();
    tingkat3_kiri_gedungA();
}

void tabung(){

    glColor3f(1.0,0.9,0.7);
    glBegin( GL_TRIANGLE_FAN );//top
    glNormal3f(0.0f,5.0f,0.0f);
    for(int i=0;i<=300;i++)
    {
        glVertex3f(4.3*cos(-i),13.0,5.3*sin(-i));
    }

    glEnd();

    glColor3f(1.0,0.9,0.7);
    glBegin( GL_TRIANGLE_FAN );//bottom
    glNormal3f(0.0f,-1.0f,0.0f);
    glVertex3f(0.0f,-0,0.0f);
    for(int i=0;i<=300;i++)
    {
        glVertex3f(4.3*cos(i),0,5.3*sin(i));
    }

    glEnd();

    for(int j=0;j<=94;j++){
            glColor3f(0.9,0.8,0.6);
            glBegin(GL_QUAD_STRIP);
            for(int i=0;i<300;i++){

            glNormal3f(2*cos(i), 0.0f, 2*sin(i));
            glVertex3f(4.3*cos(i), (j)/7, 5.3*sin(i));
            glVertex3f(4.3*cos(i), (j+1)/7, 5.3*sin(i));
            }
    }
    glEnd();
}

void tabungmiring(){
    glPushMatrix();
    glRotatef(45.0,0.0,45.0,0.0);
    tabung();
    glPopMatrix();
}
void tingkat1_kiri (){

    //tingkat 1 kedepan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(17.0, 4.0, 0.0);
    glVertex3f(17.0, 4.0, 52.0);
    glVertex3f(0.0, 4.0, 52.0);
    glEnd();

    //tingkat 1 kekanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(17.0, 4.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(67.0, 4.0, 17.0);
    glVertex3f(17.0, 4.0, 17.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(67.0, 0.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(0.0, 4.0, 0.0);
    glEnd();

     //Belakang Kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(0.0, 4.0, 52.0);
    glVertex3f(0.0, 0.0, 52.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 0.0, 52.0);
    glVertex3f(17.0, 0.0, 52.0);
    glVertex3f(17.0, 4.0, 52.0);
    glVertex3f(0.0, 4.0, 52.0);
    glEnd();

    //tingkat 1 kekanan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(17.0, 4.0, 17.0);
    glVertex3f(67.0, 4.0, 17.0);
    glVertex3f(67.0, 0.0, 17.0);
    glVertex3f(17.0, 0.0, 17.0);
    glEnd();

    //tingkat 1 kedepan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(17.0, 4.0, 17.0);
    glVertex3f(17.0, 4.0, 52.0);
    glVertex3f(17.0, 0.0, 52.0);
    glVertex3f(17.0, 0.0, 17.0);
    glEnd();

    //tingkat 1 kekanan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(67.0, 4.0, 17.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(67.0, 0.0, 0.0);
    glVertex3f(67.0, 0.0, 17.0);
    glEnd();
}

void tingkat2_kiri(){
//tingkat 2 kedepan
glBegin(GL_QUADS);
   glColor3f(0.4, 0.4, 0.4);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(15.0, 8.0, 52.0);
    glVertex3f(0.0, 8.0, 52.0);
    glEnd();

        //tingkat 2 kekanan
glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(15.0, 8.0, 15.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
   glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(0.0, 4.0, 0.0);
    glEnd();

     //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 8.0, 52.0);
    glVertex3f(0.0, 4.0, 52.0);
    glVertex3f(0.0, 4.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 4.0, 52.0);
    glVertex3f(15.0, 4.0, 52.0);
    glVertex3f(15.0, 8.0, 52.0);
    glVertex3f(0.0, 8.0, 52.0);
    glEnd();

     //kanan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(15.0, 8.0, 15.0);
    glVertex3f(15.0, 4.0, 15.0);
    glVertex3f(15.0, 4.0, 52.0);
    glVertex3f(15.0, 8.0, 52.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
   glColor3f(0.9,0.7,0.6);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 4.0, 0.0);
    glVertex3f(67.0, 4.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glEnd();

    //tingkat 2 kekanan 2
glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(15.0, 4.0, 15.0);
    glVertex3f(67.0, 4.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(15.0, 8.0, 15.0);
    glEnd();
}

void tingkat3_kiri(){
//tingkat 3 kekanan
glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(57.0, 12.0, 0.0);
    glVertex3f(67.0, 12.0, 0.0);
    glVertex3f(67.0, 12.0, 14.0);
    glVertex3f(57.0, 12.0, 14.0);
    glEnd();

    //tingkat 3 kekanan
glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(10.0, 12.0, 0.0);
    glVertex3f(57.0, 12.0, 0.0);
    glVertex3f(57.0, 12.0, 10.0);
    glVertex3f(10.0, 12.0, 10.0);
    glEnd();

    //tingkat 3 kedepan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 12.0, 0.0);
    glVertex3f(10.0, 12.0, 0.0);
    glVertex3f(10.0, 12.0, 52.0);
    glVertex3f(0.0, 12.0, 52.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 12.0, 0.0);
    glVertex3f(0.0, 12.0, 0.0);
    glEnd();

    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.5);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 8.0, 52.0);
    glVertex3f(0.0, 12.0, 52.0);
    glVertex3f(0.0, 12.0, 0.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(0.0, 8.0, 52.0);
    glVertex3f(10.0, 8.0, 52.0);
    glVertex3f(10.0, 12.0, 52.0);
    glVertex3f(0.0, 12.0, 52.0);
    glEnd();

    //depan kotak
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(57.0, 8.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(67.0, 11.0, 15.0);
    glVertex3f(57.0, 11.0, 15.0);
    glEnd();

    //tingkat 3 kekanan depan
glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(12.5, 8.0, 12.5);
    glVertex3f(57.0, 8.0, 12.5);
    glVertex3f(57.0, 11.0, 12.5);
    glVertex3f(12.5, 11.0, 12.5);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0 , 0.7);
    glVertex3f(12.5, 8.0, 12.5);
    glVertex3f(12.5, 11.0, 12.5);
    glVertex3f(12.5, 11.0, 52.0);
    glVertex3f(12.5, 8.0, 52.0);
    glEnd();

    //kanan2
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(10.0, 12.0, 52.0);
    glVertex3f(12.5, 11.0, 52.0);
    glVertex3f(12.5, 8.0, 52.0);
    glVertex3f(10., 8.0, 52.0);
    glEnd();

     //MERAH
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(10.0, 12.0, 10.0);
    glVertex3f(12.5, 12.0, 10.0);
    glVertex3f(12.5, 11.0, 12.5);
    glVertex3f(10.0, 12.0, 12.5);
    glEnd();

    //kanan2 SEBELAH DEPAN MERAH
    glBegin(GL_POLYGON);
   glColor3f(0.9,0.7,0.6);
    glVertex3f(10.0, 12.0, 12.5);
    glVertex3f(12.5, 11.0, 12.5);
    glVertex3f(12.5, 11.0, 52.0);
    glVertex3f(10., 12.0, 52.0);
    glEnd();

    //kanan2 SEBELAH KANAN MERAH
    glBegin(GL_POLYGON);
   glColor3f(0.9,0.7,0.6);
    glVertex3f(12.5, 11.0, 12.5);
    glVertex3f(12.5, 12.0, 10.0);
    glVertex3f(57.0, 12.0, 10.0);
    glVertex3f(57.0, 11.0, 12.5);
    glEnd();

    //kanan 3
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(67.0, 8.0, 0.0);
    glVertex3f(67.0, 12.0, 0.0);
    glVertex3f(67.0, 12.0, 14.0);
    glVertex3f(67.0, 8.0, 14.0);
    glEnd();

    //kanan 3
    glBegin(GL_QUADS);
    glColor3f(0.9,0.7,0.6);
    glVertex3f(57.0, 8.0, 0.0);
    glVertex3f(57.0, 12.0, 0.0);
    glVertex3f(57.0, 12.0, 14.0);
    glVertex3f(57.0, 8.0, 14.0);
    glEnd();

     //kanan 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(57.0, 12.0, 14.0);
    glVertex3f(57.0, 11.0, 15.0);
    glVertex3f(57.0, 8.0, 15.0);
    glVertex3f(57.0, 8.0, 14.0);
    glEnd();

    //kanan 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(67.0, 12.0, 14.0);
    glVertex3f(67.0, 11.0, 15.0);
    glVertex3f(67.0, 8.0, 15.0);
    glVertex3f(67.0, 8.0, 14.0);
    glEnd();

     //kanan 5
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(57.0, 12.0, 14.0);
    glVertex3f(67.0, 12.0, 14.0);
    glVertex3f(67.0, 11.0, 15.0);
    glVertex3f(57.0,11.0, 15.0);
    glEnd();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'w':
        case 'W':
            glTranslatef(0.0,0.0,3.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(3.0,0.0,0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0,0.0,-3.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(-3.0,0.0,0.0);
            break;
        case '7':
            glTranslatef(0.0,3.0,0.0);
            break;
        case '9':
            glTranslatef(0.0,-3.0,0.0);
            break;
        case '2':
            glRotatef(2.0,1.0,0.0,0.0);
            break;
        case '8':
            glRotatef(-2.0,1.0,0.0,0.0);
            break;
        case '6':
            glRotatef(2.0,0.0,1.0,0.0);
            break;
        case '4':
            glRotatef(-2.0,0.0,1.0,0.0);
            break;
        case '1':
            glRotatef(2.0,0.0,0.0,1.0);
            break;
        case '3':
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
        case '5':
            if(is_depth){
                is_depth=0;
                glDisable(GL_DEPTH_TEST);
            } else{
                is_depth=1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    } else{
        mouseDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x-xdiff;
        xrot = y+ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
