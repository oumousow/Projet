//
//  main.cpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 17/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#include <iostream>
#include "graphe.hpp"
#include <vector>
#include <algorithm>
#include "svg.hpp"

void choixPoids(graphe g, Svgfile& svgout);
//graphe g{"broadway.txt","broadway_weights_0.txt"};


void menu()
{
    std::cout<<std::endl;
    std::cout<<"1: Afficher les graphes"<<std::endl;
    std::cout<<"2: Afficher le graphe prim"<<std::endl;
    std::cout<<"3: Afficher les solutions"<<std::endl;
    std::cout<<"4: Quitter"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

int faireChoix()
{
    int choisir;
    do
    {
        std::cout<<"Faites votre choix:"<<std::endl;
        std::cout<<std::endl;
        std::cin>>choisir;
        std::cout<<std::endl;
    }
    while(choisir <0 || choisir >5);
    return choisir;
}


void quittercode()
{
    std::cout<<"vous avez quitter le code"<<std::endl;
}


void menuPoids()
{
    std::cout<<std::endl;
    std::cout<<"1= poids1"<<std::endl;
    std::cout<<"2= poids1"<<std::endl;
    std::cout<<"3= Retour"<<std::endl;
    std::cout<<std::endl;
}




void appelerMenu(graphe g, Svgfile& svgout)
{
    int choisir=0;
    do
    {
        menu();
        choisir= faireChoix();
        
            switch (choisir) {
                case 1:
                    g.afficher();
                    g.dessiner_graphe(svgout);
                    appelerMenu(g, svgout);
                    break;
                case 2:
                    choixPoids(g, svgout);
                    break;
                case 3:
                    g.remplir_vector();
                    appelerMenu(g, svgout);
                    break;
                case 4:
                    quittercode();
                    break;
            }
    }
    while (choisir <0 || choisir >5) ;
    
}

void choixPoids(graphe g, Svgfile& svgout)
{
    int choisir=0;
    
    do
    {
        menuPoids();
        choisir=faireChoix();
        switch (choisir) {
            case 1:
                g.prim(1, svgout);
                appelerMenu(g, svgout);
                
                break;
            case 2:
                g.prim(2, svgout);
                appelerMenu(g, svgout);
                break;
                
            case 3:
                appelerMenu(g, svgout);
        }
    }
    while (choisir <0 || choisir >5);
    }




int main(int argc, const char * argv[]) {
    Svgfile svgout;
    graphe g{"broadway.txt","broadway_weights_0.txt"};
    //g.afficher();
    g.dessiner_graphe(svgout);
    //g.remplir_vector();
    //g.prim(1, svgout);
    appelerMenu(g, svgout);
    return 0;
}
