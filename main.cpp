#include <cstdlib>
#include <iostream>
#include <stack>
#include <math.h>
#include <time.h>
#include "window.h"
#include "lsystem.h"

#define _USE_MATH_DEFINES

using namespace std;

Window *window_ptr;

void drawTree (){ //Gulmohar tree
    //[++++++++MMMMM++++K++++F] To add thickness
    map <char, string> rules;
    rules['S'] = string("FB");
    rules['B'] = string("F[+BLMR]F[-BMR]F[+BL][-BLMR]");
    rules['F'] = string("FN");
    rules['N'] = string("F");
    rules['L'] = string("[G-G][-G+G]--[G-G][-G+G]++++[G-G][-G+G]--");
    rules['R'] = string("Y[MP][/MP][\\MP]");
    GraphicalLSystem l0("S", rules);
    Colour brown(0.545098, 0.270588, 0.0745098);
    Colour green(0, 0.5, 0);
    Colour yellow(1, 0.5, 0);
    Colour red(0.5, 0, 0);
    l0.AddPhenotype('F', Phenotype(DRAW_FORWARD, 10.0, brown));
    l0.AddPhenotype('G', Phenotype(DRAW_FORWARD, 5.0, green));
    l0.AddPhenotype('M', Phenotype(MOVE_FORWARD, 2.0));
    l0.AddPhenotype('K', Phenotype(MOVE_FORWARD, 1.0));
    l0.AddPhenotype('Y', Phenotype(DRAW_CIRCLE, 1.0, yellow));
    l0.AddPhenotype('P', Phenotype(DRAW_CIRCLE, 2.0, red));
    l0.AddPhenotype('[', Phenotype(SAVE));
    l0.AddPhenotype(']', Phenotype(RETURN));
    l0.AddPhenotype('+', Phenotype(ROTATE, +22.5));
    l0.AddPhenotype('-', Phenotype(ROTATE, -22.5));
    l0.AddPhenotype('/', Phenotype(ROTATE, -36));
    l0.AddPhenotype('\\', Phenotype(ROTATE, 36));
    for(int i=0; i<7; i++)
        l0.GenerateNext();
    l0.Draw(window_ptr, 500, 100, 90.0);
}
 
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    pair <Colour, double> bc;
    Colour bc_colour(0.0, 0.0, 0.0);
    bc = make_pair(bc_colour, 0.0);
    Window window = Window ( "window1", 1000, 1000, bc);
    window_ptr = &window;
    window.Display(drawTree);
    return 0;
}
