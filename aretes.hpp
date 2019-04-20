//
//  aretes.hpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#ifndef aretes_hpp
#define aretes_hpp
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include "svg.hpp"

class arete
{
public:
    
    arete(int id0, int s1, int s2, double poids1, double poids2);
    
    void afficherData() const;
    int getPondération[2];
    double getPonderation1();
    double get_p2();
    double getPoids(int p);
    void dessiner_arete(Svgfile& svgout);
    int getSommet1();
    int getSommet2();
    int getIdArr();
    virtual ~arete();
    
protected:
    
private:
    
    int m_id0,m_s1, m_s2;
    double m_p1, m_p2;
};

#endif /* aretes_hpp */
