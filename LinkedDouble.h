//
// Created by jasmin saleh on 21/08/2021.
//

#ifndef LISTASDOBLEMNETEENLAZADAS_LINKEDDOUBLE_H
#define LISTASDOBLEMNETEENLAZADAS_LINKEDDOUBLE_H

#include "Node.h"
#include <vector>
#include <string>
template <class T>
class LinkedDouble {

public:
    LinkedDouble();

    bool isEmpty();

    void addNodeFirst(T);

    void addNodeLast(T);

    Node<T>* findNode(std::string);

    T* findInfo(std::string);

    std::vector<T> getList(bool);

    T deleteNode(Node<T>*);

    T getFirst();

    T getLast();

    void addNodeAfterTo(Node<T>*,T);

    void addNodeBeforeTo(Node<T>*,T);

    void addNodeSorted(T);

    int getSize();

    T* getObject(int);

    virtual ~LinkedDouble();

private:
    Node<T>* head;
    Node<T>* last;
};


#endif //LISTASDOBLEMNETEENLAZADAS_LINKEDDOUBLE_H
