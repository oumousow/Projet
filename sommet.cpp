//
//  sommet.cpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.hpp"

Sommet::Sommet(int id,double x,double y):m_id{id},m_x{x},m_y{y}
{
}

/*void Sommet::ajouterVoisin(const Sommet* voisin){
 m_voisins.push_back(voisin);
 }
 */
void Sommet::afficherData() const{
    std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}

int Sommet::getId() const{
    return m_id;
}

void Sommet::dessiner_sommets(Svgfile &svgout)
{
    svgout.addDisk(m_x, m_y, 5, "red");
}

double Sommet::get_x()
{
    return m_x;
}

double Sommet::get_y()
{
    return m_y;
}

Sommet::~Sommet()
{
    //dtor
}
