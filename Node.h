//
// Created by jasmin saleh on 21/08/2021.
//

#ifndef LISTASDOBLEMNETEENLAZADAS_NODE_H
#define LISTASDOBLEMNETEENLAZADAS_NODE_H

#include <cstdlib>

template <class T> class LinkedDouble;
template <class T>
class Node {
    friend class LinkedDouble<T>;


private:
    T info;
    Node<T>* next;
    Node<T>* previous;
public:
    Node(){
    next = NULL;
    previous = NULL;
}

    Node(T info) : info(info){
        next=NULL;
        previous=NULL;
    }

    virtual ~Node() {

    }
};


#endif //LISTASDOBLEMNETEENLAZADAS_NODE_H
