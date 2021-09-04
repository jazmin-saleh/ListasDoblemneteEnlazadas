//
// Created by jasmin saleh on 3/09/2021.
//

#ifndef LISTASDOBLEMNETEENLAZADAS_GESTION_H
#define LISTASDOBLEMNETEENLAZADAS_GESTION_H
//#include "LinkedDouble.h"
#include "Sim.h"
#include "Gestion.h"
//#include "Node.h"

#include "LinkedDouble.cpp"
#include "Sim.cpp"
#include "Gestion.cpp"
//#include "Node.cpp"

class Gestion{
private:
    LinkedDouble<Sim>* linked;

public:
    Gestion() {
        linked = new LinkedDouble<Sim>();
        linked->addNodeFirst(Sim("2","3163049613","Movistar"));
        linked->addNodeFirst(Sim("1","3163049913","Claro"));
        linked->addNodeLast(Sim("3","3183274799","Tigo"));
        linked->addNodeLast(Sim("4","3153048613","Movi"));
    }

    void addNodeFirst(Sim);

    void addNodeLast(Sim);

    bool contNode(std::string);

    string findNode(std::string);

    bool addNodeAfterTo(string,Sim);

    bool addNodeBeforTo(string,Sim);

    void addNodeSorted(Sim);

    string viewList();

};




#endif //LISTASDOBLEMNETEENLAZADAS_GESTION_H
