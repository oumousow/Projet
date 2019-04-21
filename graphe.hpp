//
//  graphe.hpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//


#include <stdio.h>
#ifndef graphe_hpp
#define graphe_hpp


#include <string>
#include <unordered_map>
#include "sommet.hpp"
#include "aretes.hpp"
#include "svg.hpp"

class graphe
{
public:
    
    graphe(std::string, std::string); ///constructeur qui charge le graphe en mÈmoire
   /* void AjouterPoidsArete(std::string, std::string, int w);
    void union_set(int u, int v);
    void print();
    */
    //int find_set(int);
    //void kruskal() const;
    ~graphe();
    void prim(double poids, Svgfile& svgout)const;
    void afficher() const;
    void dessiner_graphe(double poids,Svgfile& svgout);
    void remplir_vector();
    std::vector<std::vector<bool>>Stock_solutions(std::vector<bool> vb);
    
    
protected:
    
private:
    /// Le rÈseau est constituÈ d'une collection de sommets
    std::unordered_map<int,Sommet*> m_sommets;//stockÈe dans une map (clÈ=id du sommet, valeur= pointeur sur le sommet)
    std::unordered_map<int,arete*> m_arete;//stockÈe dans une map
    
};

#endif /* graphe_hpp */
