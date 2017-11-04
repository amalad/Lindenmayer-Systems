#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <string>
#include <map>
#include <vector>
#include <stack>
#include "colour.h"
#include "window.h"
using namespace std;

enum phenotype {NOTHING, MOVE_FORWARD, DRAW_FORWARD, DRAW_CIRCLE, SAVE, RETURN, ROTATE};

/**
 * Class for the phenotype of a symbol
 */
class Phenotype{
public:
    /**
     * Type of the phenotype
     */
    phenotype ptype;
    /**
     * Additional option. Meaning varies according to the phenotype
     */
    double option;
    /**
     * Colour option. Set to black when colour has no meaning for a phenotype
     */
    Colour colour;
    
    /**
     * Default constructor
     */
    Phenotype();
    
    /**
     * Parameteried constructor
     * @param ptype Phenotype
     * @param option [Optional] Length for MOVE_FORWARD and DRAW_FORWARD, radius for DRAW_CIRCLE and angle for ROTATE. Set to 0 for other phenotypes
     * @param colour [Optional] Colour of the constituent pixels for DRAW_FORWARD and DRAW_CIRCLE. Set to black for other phenotypes
     */
    Phenotype (phenotype ptype, double option = 0.0, Colour colour = Colour(0.0, 0.0, 0.0));
};

/**
 * Class for a deterministic context-free Graphical L system
 */
class GraphicalLSystem{
public:
    /**
     * Axiom
     */
    string axiom;
    /**
     * Production rules
     */
    map <char, string> rules;
    /**
     * Generation number
     */
    int n_generation;
    /**
     * Current genotype
     */
    string current_genotype;
    /**
     * Phenotypes for symbols
     */
    map < char, Phenotype > phenotypes;
    
    /**
     * Parameterized constructor
     * @param axiom Axiom
     * @param rules Production rules
     */
    GraphicalLSystem (string axiom, map <char, string> rules);
    
    /**
     * Produces the genotype of the next generation
     * @return Genotype of the next generation
     */
    string GenerateNext();
    
    /**
     * Returns current genotype
     * @return Current genotype
     */
    string GetCurrentGenotype();
    
    /**
     * Adds phenotypes to symbols
     * @param symbol The symbol
     * @param ptype Phenotype
     */
    void AddPhenotype(char symbol, Phenotype ptype);
    
    /**
     * Outputs the phenotype of the current genotype
     * @param window_ptr Graphical window pointer
     * @param x Initial X coordinate
     * @param y Initial y coordinate
     * @param angle Initial angle
     */
    void Draw(Window* window_ptr, int x, int y, double angle);
};

#endif /* LSYSTEM_H */

