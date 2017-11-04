#include "window.h"

Window::Window(string window_name, int width, int height, pair <Colour, double> background_colour, vector <int> window_position, unsigned int display_mode, vector <int> ortho2d){
    this->height = height;
    this->width = width;
    this->background_colour.first = background_colour.first;
    this->background_colour.second = background_colour.second;
    this->window_name = window_name;
    //Glut initialization
    glutInitDisplayMode(display_mode);
    if (window_position.size()!=0)
        glutInitWindowPosition(window_position[0], window_position[1]);
    else
        glutInitWindowPosition(-1, -1);
    glutInitWindowSize(this->width, this->height);
    glutCreateWindow(this->window_name.c_str());
    glClearColor(this->background_colour.first.R, this->background_colour.first.G, this->background_colour.first.B, this->background_colour.second);
    if(ortho2d.size() == 0)
        gluOrtho2D(0, this->width, 0, this->height);
    //
}

void Window::DrawLine(int x1, int y1, int x2, int y2, Colour line_colour){
    int xl, yl, xr, yr;
    //For left to right convention
    if (x1<x2) {
        xl = x1; yl = y1; xr = x2; yr = y2;
    } else if (x1==x2 && y1<y2) {
        xl = x1; yl = y1; xr = x2; yr = y2;       
    } else {
        xl = x2; yl = y2; xr = x1; yr = y1;
    }
    
    int dx = xr - xl; //Always >= 0
    int dy = yr - yl;
    int d, incrE, incrNE, x, y, xmax;
    
    int negslope = 0; //when slope < 0
    if (dx!=0 && dy < 0) {
        negslope = 1;
        dy = abs(dy);
        yr = 2 * yl - yr;
    }
    
    int switchaxes = 0; //when |slope| > 1
    if (abs(dy) > abs(dx)) {//switchaxes
        switchaxes = 1;
        d = 2 * dx - dy;
        incrE = 2 * dx;
        incrNE = 2 * (dx-dy);
        x = yl;
        y = xl;
        xmax = yr;
    } else {
    d = 2 * dy - dx;
    incrE = 2 * dy;
    incrNE = 2 * (dy-dx);
    x = xl;
    y = yl;
    xmax = xr;
    }
    glBegin(GL_POINTS);
    
    if (switchaxes) SetPixel(y, x + negslope * 2 * (yl - x), line_colour); //switchaxes
    else SetPixel(x, y + negslope * 2 * (yl - y), line_colour);
    
    while (x < xmax){
        if (d <= 0){
            d += incrE;
            x++;
        } else{
            d+=incrNE;
            x++;
            y++;
        }
        if (switchaxes) SetPixel(y, x + negslope * 2 * (yl - x), line_colour); //switchaxes
        else SetPixel(x, y + negslope * 2 * (yl - y), line_colour);
    }
    glEnd();
    glFlush();
}

void Window::DrawCircle(int cx, int cy, int radius, Colour circle_colour){
    int x = 0;
    int y = radius;
    int d = 1-radius;
    int deltaE = 3;
    int deltaSE = -2 * radius + 5;
    glBegin(GL_POINTS);
    CirclePoints(x, y, cx, cy, circle_colour);
    
    while(y>x){
        if (d<0) {
            d += deltaE;
            deltaE +=2;
            deltaSE +=2;
        } else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }
        x++;
        CirclePoints(x, y, cx, cy, circle_colour);
    }
    glEnd();
    glFlush();
}

void Window::Display(void (*draw)(void)){
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc (draw);
    glutMainLoop();
}

void Window::CirclePoints(int x, int y, int cx, int cy, Colour circle_colour){
    SetPixel(cx+x, cy+y, circle_colour);
    SetPixel(cx+x, cy-y, circle_colour);
    SetPixel(cx-x, cy-y, circle_colour);
    SetPixel(cx-x, cy+y, circle_colour);
    SetPixel(cx+y, cy+x, circle_colour);
    SetPixel(cx+y, cy-x, circle_colour);
    SetPixel(cx-y, cy-x, circle_colour);
    SetPixel(cx-y, cy+x, circle_colour);
}