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



void menu()
{
    std::cout<<std::endl;
    std::cout<<"1: Afficher les fichiers"<<std::endl;
    std::cout<<"2: Afficher le graphe et la solution de prim"<<std::endl;
    std::cout<<"3: Afficher les solutions binéaires"<<std::endl;
    std::cout<<"4: Quitter"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

//Pouvoir saisir le choix
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
    while(choisir <0 || choisir >5); // La condition de sortie du code
    return choisir;
}

// condition d'arrêt du code
void quittercode()
{
    std::cout<<"vous quittez le code"<<std::endl;
}

// faire le chois des pooids
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
    while (choisir <0 || choisir >5) ; // La condition de sortie du code
    
}


// Code pour pouvoir choisir le graphe à afficher en fonction du poids choisi
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
                g.dessiner_graphe(1,svgout);

                appelerMenu(g, svgout);
                
                break;
            case 2:
                g.prim(2, svgout);
                g.dessiner_graphe(2,svgout);

                appelerMenu(g, svgout);
                break;
                
            case 3:
                appelerMenu(g, svgout);
        }
    }
    while (choisir <0 || choisir >5); // La condition de sortie du code 
    }




int main(int argc, const char * argv[]) {
    Svgfile svgout;
    graphe g{"manhattan.txt","manhattan_weights_0.txt"};
    appelerMenu(g, svgout);
    return 0;
}
