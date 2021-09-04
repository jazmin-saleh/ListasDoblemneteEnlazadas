//
// Created by jasmin saleh on 21/08/2021.
//

#include "LinkedDouble.h"

template<class T>
LinkedDouble<T>::LinkedDouble() {
    head=NULL;
    last=NULL;
}

template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head==NULL && last==NULL;
}

template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {
    Node<T>* newNode = new Node<T>(info);
    if(isEmpty()){
        head=newNode;
        last=newNode;
    }else{
        head->previous = newNode;
        newNode->next=head;
        head=newNode;
    }
}

template<class T>
void LinkedDouble<T>::addNodeLast(T info) {
    Node<T>* newNode = new Node<T>(info);
    if(isEmpty()){
        head=newNode;
        last=newNode;
    }else{
       last->next=newNode;
       newNode->previous=last;
       last=newNode;
    }
}

template<class T>
Node<T> *LinkedDouble<T>::findNode(std::string id) {
    Node<T>* aux=head;
    while (aux !=NULL){
        if (id.compare(aux->info.getId())==0){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
T *LinkedDouble<T>::findInfo(std::string id) {
    Node<T>* aux = head;
    while (aux != NULL){
        if(id.compare(aux->info.getId())==0){
            return &aux->info;
        }
        aux = aux->next;
    }
    return NULL;
}




template<class T>
void LinkedDouble<T>::addNodeAfterTo(Node<T> *node, T info) {
    Node<T> *newNode = new Node<T>(info);
    Node<T> * aux = head;
    if (node != last){
        if (node != NULL){
            while (aux != node){
                aux = aux->next;
            }
            newNode->previous=aux;
            newNode->next = aux->next;
            aux->next->previous = newNode;
            aux->next=newNode;
        }
    }else{
        last->next = newNode;
        newNode->previous = last->previous;
        last = newNode;
    }
}

template<class T>
void LinkedDouble<T>::addNodeBeforeTo(Node<T> *node, T info) {
        Node<T> *newNode = new Node<T>(info);
        Node<T>*aux= head;
    if (node != head){
        if (node !=NULL){
            while (aux != node){
                aux = aux->next;
            }
            newNode->next = aux;
            aux->previous->next=newNode;
            aux->previous = newNode;
        }
    }else{
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}


template<class T>
void LinkedDouble<T>::addNodeSorted(T info) {
    Node<T> *newNode = new Node<T>(info);
    Node<T>* aux = head;
    if (isEmpty()){
        addNodeFirst(info);
    }else{
        if (info.getId().compare(head->info.getId()) <0){
            addNodeFirst(info);
        }else if(info.getId().compare(last->info.getId())>0){
            addNodeLast(info);
        }else{
            while (aux!=NULL && aux->next != NULL){
                if(info.getId().compare(aux->info.getId())>0 && info.getId().compare(aux->next->info.getId())<0){
                    addNodeAfterTo(aux,info);
                    break;
                }
                aux = aux->next;
            }
        }
    }
}

template<class T>
std::vector<T> LinkedDouble<T>::getList(bool forward) {
   std::vector<T> out;
   Node<T>* aux = forward ? head : last;
    while (aux != NULL){
        out.push_back((aux->info));
        aux = forward ? aux->next : aux->previous;
    }
    return  out;
}

template<class T>
T LinkedDouble<T>::deleteNode(Node<T>* node) {
    T info = node->info;
    if (node == head){
        if (node == last){
            last = last->previous;
            head = head->next;
        }else{
            head = head->next;
        }
    }else{
        if (node == last){
            last = last->previous;
           node->previous->next=NULL;
        }else{
            Node<T>* aux = head;
            Node<T>* auxx = aux->next;
            while (aux->next != node){
                aux = aux->next;
                auxx=aux->next;
            }
            aux->next = node->next;
            auxx->next->previous=aux;
        }
    }
    delete(node);
    return info;
}

template<class T>
int LinkedDouble<T>::getSize() {
    int cont =0;
    Node<T>*aux = head;
    while (aux!=NULL){
        aux=aux->next;
        cont++;
    }
    return cont;
}

template<class T>
T *LinkedDouble<T>::getObject(int position) {
    int cont =1;
    Node<T>*aux = head;
    while (aux!=NULL){
        if (cont==position){
            return &aux->info;
        }
        cont++;
        aux=aux->next;
    }
    return NULL;
}
template<class T>
T LinkedDouble<T>::getFirst() {
    return head->info;
}

template<class T>
T LinkedDouble<T>::getLast() {
    return last->info;
}


template<class T>
LinkedDouble<T>::~LinkedDouble() {

}



















