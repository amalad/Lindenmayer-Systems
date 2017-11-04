#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <string>
#include <cmath>
#include <GL/glut.h>
#include <GL/gl.h>
#include "colour.h"
using namespace std;

/**
 * Wrapper class for an OpenGL window
 */
class Window{
public:
    /**
     * Width of the window
     */
    int width;
    /**
     * Height of the window
     */
    int height;
    /**
     * Background colour of the window as a combination of its colour and opacity (between 0 and 1)
     */
    pair <Colour, double> background_colour;
    /**
     * Name of the window
     */
    string window_name;
    
    /**
     * Parameterized constructor
     * @param window_name Name of window
     * @param width Width of the window
     * @param height height of the window
     * @param background_colour Background colour of the window as a pair of Colour and opacity (double value between 0 and 1)
     * @param window_position [Optional] Position of the window
     * @param display_mode [Optional] Glut display mode
     * @param ortho2d [Optional] Orthogonal projection matrix
     */
    Window (string window_name, int width, int height, pair <Colour, double> background_colour, vector <int> window_position=vector <int>(), unsigned int display_mode=GLUT_SINGLE|GLUT_RGB, vector <int> ortho2d=vector <int>());
    
    /**
     * Sets the pixel to the given colour
     * @param x Abscissa of the pixel
     * @param y Ordinate of the pixel
     * @param pixel_colour Colour of the pixel
     */
    void SetPixel (int x, int y, Colour pixel_colour){
        glColor3f(pixel_colour.R, pixel_colour.G, pixel_colour.B);
        glVertex2i(x,y);
    }
    
    /**
     * Draws a straight line between two points
     * @param x1 Abscissa of the first point
     * @param y1 Ordinate of the first point
     * @param x2 Abscissa of the second point
     * @param y2 Ordinate of the second point
     * @param line_colour Colour  of the line
     */
    void DrawLine (int x1, int y1, int x2, int y2, Colour line_colour);
    
    /**
     * Draws a circle about the given centre 
     * @param x Abscissa of the centre
     * @param y Ordinate of the centre
     * @param radius Radius of the circle
     * @param circle_colour Colour of the circle
     */
    void DrawCircle (int x, int y, int radius, Colour circle_colour);
    
    /**
     * Displays all the elements in the window
     * @param draw Pointer to the drawing function
     */
    void Display (void (*draw)(void));
    
private:
    /**
     * Utility function for the DrawCircle function
     * @param x Abscissa of the point in one of the eight symmetrical sections
     * @param y Ordinate of the point in one of the eight symmetrical sections
     * @param cx Abscissa of the centre
     * @param cy Ordinate of the centre
     * @param circle_colour Colour of the circle
     */
    void CirclePoints(int x, int y, int cx, int cy, Colour circle_colour);
};

#endif /* WINDOW_H */