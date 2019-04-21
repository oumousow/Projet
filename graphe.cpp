//
//  graphe.cpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#include "graphe.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include "sommet.hpp"
#include "svg.hpp"


graphe::graphe(std::string nomFichier, std::string nomFichier1)
{
    
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible douvrir en lecture " + nomFichier );
    
    int ordre;
    ifs >> ordre;
    
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    
    
    int id;
    double x,y;
    
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture donnÈes sommet");
        ifs>>x;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture donnÈes sommet");
        ifs>>y;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture donnÈes sommet");
        
        m_sommets.insert({id,new Sommet{id,x,y}});
    }

    
    int taille;
    ifs >> taille;
    
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    
    std::string id_voisin;
    int id0;
    int s1;
    int s2;
    
    
    std::ifstream ifs1{nomFichier1};
    if (!ifs1)
        throw std::runtime_error( "Impossible douvrir en lecture " + nomFichier1 );
    
    
    int taille1;
    ifs1 >> taille1;
    
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    
    int nbP;
    double p1;
    double p2;
    
    ifs1 >> nbP;
    
    //lecture des aretes
    for (int i=0; i<taille1; ++i)
    {
        ifs>>id0;
        ifs1>>id0;
        ifs>>s1;
        ifs>>s2;
        ifs1>>p1;
        ifs1>>p2;
        
        m_arete.insert({id0, new arete(id0, s1, s2, p1, p2)});
    }
}

void graphe::prim(double poids, Svgfile& svgout)const{
    std::vector< arete*> A1;              // on déclare un vecteur d'arête
    std::vector<Sommet*> S1;              // On déclare un vecteur de dommets
    std::vector<arete*> SomArete;         // Toutes les aretes à déssiner
    std::vector<bool> MarkSommet(m_sommets.size());     // On défini si un sommet est marqué ou pas
    
    for(auto i: m_arete)          // On fait une boucle for pour parcourir les arête
    {
        A1.push_back(i.second);   // On ajoute les arêtes les unes après les autres
    }
    
    std::sort(A1.begin(), A1.end(),[poids](arete* a1, arete* a2){
        return a1->getPoids(poids) < a2->getPoids(poids);
    });
    
    // On tri les arêtes de la plus petite pondération à la plus grande
    
    MarkSommet[0]=true;    // On marque notre premier sommet
    for(int i=0; i<m_sommets.size()-1; i++){
        double PoidsArrMin=1e25;  // On défini un poids minimum lequel sera le référent pour le compraison des pondérations
        int IdArrMin;
    
        for(int j=0; j<A1.size(); j++)
        {
            if(((((MarkSommet[A1[j]->getSommet1()])== true) && ((MarkSommet[A1[j]->getSommet2()])== false)) ||
                (((MarkSommet[A1[j]->getSommet1()])== false) && (MarkSommet[A1[j]->getSommet2()])== true))
               && (A1[j]->getPoids(poids) < PoidsArrMin))
            {
    // Dans cette boucle for, on prends 2 arêtes qu'on marque, puis on demande à l'arête de poids minimum qqu'on avait défini de pointer vers l'arête qui le plus petit poids juste après lui.
                PoidsArrMin=A1[j]->getPoids(poids);
                IdArrMin=A1[j]->getIdArr();
                SomArete.push_back(A1[j]);
                MarkSommet[A1[j]->getSommet1()]=true;
                MarkSommet[A1[j]->getSommet2()]=true;
            }
           
        }
    }
    std::cout<<std::endl;
    std::cout << SomArete.size();
    std::cout<<std::endl;
    // On affiche toutes les arêtes marquées
    for (int j=0; j<SomArete.size(); j++)
    {
        //std::cout <<"Id arete conservee:"<< SomArete[j]->getIdArr() << std::endl;
        std::cout<<"\n"<<SomArete[j]->getSommet1()<<" -------> "<<SomArete[j]->getSommet2()<<std::endl;
        
        
        
        svgout.addDisk(m_sommets.find(SomArete[j]->getSommet1())->second->get_x()+500,m_sommets.find(SomArete[j]->getSommet1())->second->get_y(),5,"black");
        svgout.addText(m_sommets.find(SomArete[j]->getSommet1())->second->get_x()+515, m_sommets.find(SomArete[j]->getSommet1())->second->get_y(),SomArete[j]->getSommet1(), "purple");
        svgout.addDisk(m_sommets.find(SomArete[j]->getSommet2())->second->get_x()+500,m_sommets.find(SomArete[j]->getSommet2())->second->get_y(),5,"black");
        svgout.addText(m_sommets.find(SomArete[j]->getSommet2())->second->get_x()+515, m_sommets.find(SomArete[j]->getSommet2())->second->get_y(),SomArete[j]->getSommet2(), "purple");
        
        svgout.addLine(m_sommets.find(SomArete[j]->getSommet1())->second->get_x() + 500, m_sommets.find(SomArete[j]->getSommet1())->second->get_y(), m_sommets.find(SomArete[j]->getSommet2())->second->get_x() + 500, m_sommets.find(SomArete[j]->getSommet2())->second->get_y(), "black");
        //svgout.addLine((m_sommets.find(SomArete[j]->getSommet1())->second->get_x() + 600, m_sommets.find(SomArete[j]->getSommet1())->second->get_y(),m_sommets.find((SomArete[j]->getSommet2())->second->get_x() + 600, m_sommets.find(SomArete[j]->getSommet2())->second->get_y(), "black");
        svgout.addText((m_sommets.find(SomArete[j]->getSommet1())->second->get_x() + 500 + m_sommets.find(SomArete[j]->getSommet2())->second->get_x() + 500)/2 + 5, (m_sommets.find(SomArete[j]->getSommet1())->second->get_y() + m_sommets.find(SomArete[j]->getSommet2())->second->get_y())/2 - 10, SomArete[j]->getPoids(poids));
        // svgout.addText(((m_sommets.find(SomArete[j]->getSommet1())->second->get_x() + 600 + m_sommets.find(SomArete[j]->getSommet2())->second->get_x() + 600))/2 +5,(((m_sommets.find(SomArete[j]->getSommet1())->second->get_y() + m_sommets.find(SomArete[j]->getSommet2())->second->get_y()))/2 -15, SomArete[j]->getIdArr(),"green"))
    }
}
                           
void graphe::afficher() const
{
    std::cout<<"GRAPHE : "<<std::endl<<std::endl;
    
    std::cout<<"Ordre : "<<m_sommets.size()<<std::endl<<std::endl;
    
    for(auto& it : m_sommets)
    {
        std::cout<<"  sommet : "<<std::endl;
        it.second->afficherData();
        /// it.second->afficherVoisins();
        std::cout<<std::endl<<std::endl;
    }
    
    std::cout<<"Taille : "<<m_arete.size()<<std::endl<<std::endl;
    
    for(auto& it : m_arete)
    {
        std::cout<<"  arete : "<<std::endl;
        it.second->afficherData();
        /// it.second->afficherVoisins();
        std::cout<<std::endl<<std::endl;
    }
    
    
    
}


void graphe::dessiner_graphe(double poids, Svgfile& svgout) 
{
    for(auto& it : m_sommets)
    {
        it.second->dessiner_sommets(svgout);
    }
    
    for (auto& it : m_arete)
    {
        int id1,id2;
        id1 = it.second -> getSommet1();
        id2 = it.second -> getSommet2();
        
        double x1 = m_sommets.find(id1)->second->get_x();
        double y1 = m_sommets.find(id1)->second->get_y();
        //double poids1 = it.second -> get_p1();
        
        double x2 = m_sommets.find(id2)->second->get_x();
        double y2 = m_sommets.find(id2)->second->get_y();
        //double poids2 = it.second -> get_p2();
        
        svgout.addLine(x1, y1, x2, y2, "red");
        svgout.addText((x1+x2)/2 + 5,(y1+y2)/2 + 10,it.second->getPoids(poids));
       
        
    }
}



std::vector<std::vector<bool>> graphe::Stock_solutions(std::vector<bool> vb)
{
    std::vector<std::vector<bool>> test;
    std::vector<bool> test2;
    //
    /*
     std::vector<int> possibilite;
     std::vector<std::vector<int>>vecdec;
     std::vector<std::vector<int>>admi;
     
     int nb_aretes=m_arete.size();
     int nb_sommets=m_sommets.size();
     int diff=nb_aretes-nb_sommets+1;
     
     for(int i=0; i<nb_sommets-1; i++)
     {
     possibilite.push_back(1);
     }
     
     for(int i=0; i<diff; i++)
     {
     possibilite.push_back(0);
     }
     
     std::sort(possibilite.begin(), possibilite.end());
     do
     {
     admi.push_back(possibilite);
     
     }
     while(std::next_permutation(possibilite.begin()),possibilite.end());
     */
     
    
    //
    
    std::sort(vb.begin(), vb.end());
    do
    {
        test.push_back(vb);
        
    }
    while(std::next_permutation(vb.begin(),vb.end()));
    
    
    
    //
     /*
     for(size_t i=0; i< m_arete.size(); i++)
     {
     for(size_t j=0; j< m_sommets.size(); j++)
     {
     std::swap (vb[j], vb[j+1]);
     
     }
     test.push_back(vb);
     }
    */
    
     
     
    for(size_t i=0; i< test.size(); i++)
    {
        for(size_t j=0; j< vb.size(); j++)
        {
            std::cout<< test[i][j];
        }
        std::cout<<std::endl;
    }
    
    
    return test;
    
    
}



void graphe::remplir_vector()
{
    //size_t taille = m_arete.size();
    //int nb_combinaisons = pow(2,taille);
    std::vector<bool> combi_arete (m_sommets.size()-1, 1);
    
    for(size_t i = 0; i < m_arete.size()-m_sommets.size()+1; ++i)
    {
        combi_arete.push_back(0);
    }
    
    Stock_solutions(combi_arete); /// appel mÈthode
}





graphe::~graphe()
{
    //dtor
}


