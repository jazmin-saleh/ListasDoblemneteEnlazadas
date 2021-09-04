//
// Created by jasmin saleh on 21/08/2021.
//

#include "Sim.h"

Sim::Sim() {

}

Sim::Sim(const string &id, const string &number, const string &mark) : id(id), number(number), mark(mark) {

}

const string &Sim::getId() const {
    return id;
}

void Sim::setId(const string &id) {
    Sim::id = id;
}

const string &Sim::getNumber() const {
    return number;
}

void Sim::setNumber(const string &number) {
    Sim::number = number;
}


const string &Sim::getMark() const {
    return mark;
}

void Sim::setMark(const string &mark) {
    Sim::mark = mark;
}

ostream &operator<<(ostream &os, const Sim &sim) {
    os << "id: " << sim.id << " number: " << sim.number << " mark: " << sim.mark;
    return os;
}

Sim::~Sim() {

}

string Sim::toString() {
    return "Id: "+id+" numero: "+number+" marca: "+mark;
}











