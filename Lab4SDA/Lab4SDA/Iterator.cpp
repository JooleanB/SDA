#include "Iterator.h"
#include "LO.h"
#include<exception>

//teta(1)
Iterator::Iterator(LO& lo) : lista(lo){
    /* de adaugat */
    this->curent = lista.prim;
}
//teta(1)
void Iterator::prim() {
    /* de adaugat */
    this->curent = lista.prim;
}
//teta(1)
void Iterator::urmator(){
    /* de adaugat */
    if (!valid()) {
        throw std::exception();
    }
    this->curent = lista.urmator[this->curent];
}

//teta(1)
void Iterator::predecesor() {
    /* de adaugat */
    if (!valid()) {
        throw std::exception();
    }
    this->curent = lista.predecesor[this->curent];
}
//teta(1)
bool Iterator::valid() const{
    /* de adaugat */
    if (this->curent != -1) {
        return true;
    }
    return false;
}

//teta(1)
TElement Iterator::element() const{
    /* de adaugat */
    if (valid()) {
        return lista.valori[this->curent];
    }
    return -1;
}

/*TElement Iterator::elimina() {
    if (valid()) {
        int curent_vechi = this->curent;
        urmator();
        TElement val = lista.sterge(curent_vechi);
        return val;
    }
    else
        throw std::exception();
}*/


