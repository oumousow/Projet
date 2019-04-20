//
//  aretes.cpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#include "aretes.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>

arete::arete(int id0, int s1, int s2, double poids1, double poids2):m_id0{id0}, m_s1{s1}, m_s2{s2}, m_p1{poids1}, m_p2{poids2}
{
    //ctor
}

void arete::afficherData() const{
    std::cout<<"    "<<m_id0<<" : "<<"(Debut arete, Fin arete)=("<<m_s1<<","<<m_s2<<") "<<"Poids 1 : "<<m_p1<<" Poids 2 : "<<m_p2<<std::endl;
}
double arete::getPonderation1(){
    return m_p1;
}

double arete::get_p2()
{ 
    return m_p2;
}

double arete::getPoids(int p) {
    return p == 1 ? m_p1 : m_p2;
}

int arete::getSommet1()
{
    return m_s1;
}

int arete::getSommet2()
{
    return m_s2;
}

int arete::getIdArr()
{
    return m_id0;
}

arete::~arete()
{
    //dtor
}
