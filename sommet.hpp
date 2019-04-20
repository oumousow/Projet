//
//  sommet.hpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#ifndef sommet_hpp
#define sommet_hpp
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include "svg.hpp"

class Sommet
{
public:
    
    Sommet(int,double,double); ///constructeur qui reÁoit en paramËtres les donnÈes du sommet
    
    void ajouterVoisin(const Sommet*);
    void afficherData() const;
    void afficherVoisins() const;
    int getId() const;
    void dessiner_sommets(Svgfile& svgout);
    double get_x();
    double get_y();
    ~Sommet();
    
protected:
    
private:
    
    /// DonnÈes spÈcifiques du sommet
    int m_id; // Identifiant
    double m_x, m_y; // Position
    
};


#endif /* sommet_hpp */
