#include "IteratorColectie.h"
#include <exception>
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
    //Constructor
    current = col.head;
}

TElem IteratorColectie::element() const {
    //Returnam elementul spre care arata iteratorul
    if (valid()) {
        return current->elem;
    }
    else {
        throw std::exception();
    }
}

bool IteratorColectie::valid() const {
    //Verificam daca iteratorul e vid
    return current != nullptr;
}

void IteratorColectie::urmator() {
    //Mutam iteratorul spre urmat element
    if (valid()) {
        current = current->next;
    }
    else {
        throw std::exception();
    }
}

void IteratorColectie::prim() {
    //Mutam iteratorul spre primul element
    current = col.head;
}

//FCT NOUA
//COMPLEXITATE
//best:theta(1) cand iteratorul nu e valid
//worst:theta(n) cand se parcurge toata colectia
//overall O(n)

/*
* pseudocod
* daca (valid())
* current <- col.head
* previous<-NIL
* cat timp (current!=NIL && current!=this?current)
* previous<-current
* current<-current?next
* SFcattimp
* daca(previous==NIL) this?current<-NIL
* altfel this?current<-previous
* sfDaca
* altfel arunca exceptie
* sfDaca
* sfAlgoritm
*/
void IteratorColectie::anterior() {
    if (valid()) {
        Colectie::Node* current = col.head;
        Colectie::Node* previous = nullptr;
        //cautam elem anterior
        while (current != nullptr && current != this->current)
        {
            previous = current;
            current = current->next;
        }
        //actualizam iteratorul
        //daca elem e primul
        if (previous == nullptr) this->current = nullptr;
        //daca elem nu e primul
        else this->current = previous;
    }

    else throw std::exception();  
}
