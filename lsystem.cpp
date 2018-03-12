#include "lsystem.h"

Phenotype::Phenotype(){
    this->ptype = NOTHING;
    this->option = 0.0;
    this->colour = Colour(0.0, 0.0, 0.0);
}

Phenotype::Phenotype(phenotype ptype, double option, Colour colour){
    this->ptype = ptype;
    this->option = option;
    this->colour = colour;
}

GraphicalLSystem::GraphicalLSystem(string axiom, map<char,string> rules) {
    this->axiom = axiom;
    this->rules = rules;
    this->current_genotype = axiom;
}

string GraphicalLSystem::GenerateNext() {
    map<char,string>::iterator it;
    int len = this->current_genotype.length();
    for (int i=len-1; i>=0; i--) {
        it = this->rules.find(this->current_genotype[i]);
        if(it!=this->rules.end()) {
            this->current_genotype.replace(i, 1, it->second);
        }
    }
    this->n_generation += 1;
    return this->current_genotype;
}

string GraphicalLSystem::GetCurrentGenotype() {
    return this->current_genotype;
}

void GraphicalLSystem::AddPhenotype(char symbol, Phenotype ptype) {
    this->phenotypes[symbol] = ptype;
}

void GraphicalLSystem::Draw(Window* window_ptr, int x, int y, double angle) {
    Colour colour;
    stack < pair <pair <int, int>, pair<double, Colour > > > st;
    map<char, Phenotype >::iterator it;
    pair <pair <int, int>, pair<double, Colour > > st_entry;
    
    for (int i=0; i<this->current_genotype.length(); i++) {
        it = this->phenotypes.find(this->current_genotype[i]);
        if (it != this->phenotypes.end()) {
            
            if (it->second.ptype == SAVE) {
                pair <int, int> coordinates = make_pair(x, y);
                pair <double, Colour > second = make_pair(angle, colour);
                st_entry = make_pair(coordinates, second);
                st.push(st_entry);
            }
            else if (it->second.ptype == RETURN) {
                x = st.top().first.first;
                y = st.top().first.second;
                angle = st.top().second.first;
                colour = st.top().second.second;
                st.pop();
            }
            else if (it->second.ptype == ROTATE) {
                angle += it->second.option;
            }
            else if (it->second.ptype == DRAW_CIRCLE) {
                colour = it->second.colour;
                window_ptr->DrawCircle(x,y,it->second.option, colour);
            }
            else if (it->second.ptype == DRAW_FORWARD) {
                colour = it->second.colour;
                int x1 = x + round(cos(angle*M_PI/180)*it->second.option);
                int y1 = y + round(sin(angle*M_PI/180)*it->second.option);
                window_ptr->DrawLine(x, y, x1, y1, colour);
                x = x1, y = y1;
            }
            else if (it->second.ptype == MOVE_FORWARD) {
                x += round(cos(angle*M_PI/180)*it->second.option);
                y += round(sin(angle*M_PI/180)*it->second.option);
            }
        }
    }
}