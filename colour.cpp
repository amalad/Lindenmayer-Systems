#include "colour.h"

Colour::Colour(){
    this->R = 0;
    this->G = 0;
    this->B = 0;
}

Colour::Colour(double R, double G, double B){
    this->R = R;
    this->G = G;
    this->B = B;
}

void Colour::SetR(double R){
    this->R = R;
}

void Colour::SetG(double G){
    this->G = G;
}

void Colour::SetB(double B){
    this->B = B;
}