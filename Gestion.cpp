//
// Created by jasmin saleh on 3/09/2021.
//

#include "Gestion.h"


void Gestion::addNodeFirst(Sim info) {
    linked->addNodeFirst(info);
}

void Gestion::addNodeLast(Sim info) {
    linked->addNodeLast(info);
}

bool Gestion::contNode(std::string idFind) {
    Node<Sim>* found = linked->findNode(idFind);
    if (found==NULL){
       return false;
    } else{
        return true;
    }
}

string Gestion::findNode(std::string idFind) {
    contNode(idFind);
    if (contNode(idFind)){
        return "No fue encontrada la SIM con Id "+idFind+"\n";
    } else{
        return "La SIM si fue encontrada con Id "+idFind+"\n";
    }

}

bool Gestion::addNodeAfterTo( string id,Sim info) {
    Node<Sim>* encontrar = linked->findNode(id);
    if (encontrar == NULL){
        return false;
    }else{
        linked->addNodeAfterTo(encontrar,info);
        return true;
    }
}


string Gestion::viewList() {
    string view= "";
    for (Sim sim: linked->getList(true)) {
       view+= sim.toString()+"\n";
    }
    return view;
}

bool Gestion::addNodeBeforTo(string id, Sim info) {
    Node<Sim>* encontrar = linked->findNode("4");
    if (encontrar==NULL){
        return false;
    }else{
        //linked->addNodeBeforeTo(encontrar, info);
        return true;
    }
}

Gestion::~Gestion() {

}












