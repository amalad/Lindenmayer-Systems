#ifndef COLOUR_H
#define COLOUR_H

/**
 * Class for pixel colours
 */
class Colour{
public:
    /**
     * Double value for R between 0 and 1
     */
    double R;
    /**
     * Double value for G between 0 and 1
     */
    double G;
    /**
     * Double value for B between 0 and 1
     */
    double B;
    
    /**
     * Default constructor
     */
    Colour();
    
    /**
     * Parameterized constructor
     * @param R Double value for R between 0 and 1
     * @param G Double value for G between 0 and 1
     * @param B Double value for B between 0 and 1
     */
    Colour (double R, double G, double B);
    
    /**
     * Set the value of R
     * @param R Double value for R between 0 and 1
     */
    void SetR(double R);
    
    /**
     * Set the value of G
     * @param G Double value for G between 0 and 1
     */
    void SetG(double G);
    
    /**
     * Set the value of B
     * @param B Double value for B between 0 and 1
     */
    void SetB(double B);
};

#endif /* COLOUR_H */

