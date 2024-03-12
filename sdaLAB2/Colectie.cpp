#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
    return e1 <= e2;
}

Colectie::Colectie() {
    //Constructor
    head = nullptr;
    size = 0;
}
//COMPLEXITATE
//best theta(1) cand elem e primul de adaugat
//worst theta(n)
//overall O(n)
void Colectie::adauga(TElem e) {
    //Adauga un element in colectie
    if (head == nullptr) {
        //Daca colectia e vida, adauga elementul ca prim element
        head = new Node;
        head->elem = e;
        head->nr = 1;
        head->next = nullptr;
        size++;
    }
    else {
        //Daca colectia nu e vida, cauta locul unde trebuie pus elementul
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && rel(current->elem, e)) {
            if (current->elem == e) {
                //Daca elementul e deja in colectie, ii marim frecventa
                current->nr++;
                size++;
                return;
            }
            previous = current;
            current = current->next;
        }
        //Daca elementul nu e in colectie, il adaug
        Node* newNode = new Node;
        newNode->elem = e;
        newNode->nr = 1;
        newNode->next = current;
        if (previous == nullptr) {
            //Daca elementul e primul in colectie, actualizam head ul
            head = newNode;
        }
        else {
            //Daca elementul NU e primul in colectie, actualizam elem anterior
            previous->next = newNode;
        }
        size++;
    }
}

//COMPLEXITATE
//best theta(1) cand elem e primul
//worst theta(n)
//overall O(n)
bool Colectie::sterge(TElem e) {
    //Scoatem frecventa unui element din colectie.
    // Daca frecventaa este 1, se sterge elementul din colectie
    if (head == nullptr) {
        //Daca colectia e vida return false
        return false;
    }
    else {
        //Daca colecria nu e vida cautam pozitia elem in ea
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && rel(current->elem, e)) {
            if (current->elem == e) {
                //Daca elem se afla in colectie, decrementam frecventa
                current->nr--;
                size--;
                if (current->nr == 0) {
                    //Daca frecventa devine 0, stergem elementul din colectie
                    if (previous == nullptr) {
                        //Daca elem e primul in colectie, actualizam head ul
                        head = current->next;
                    }
                    else {
                        //Daca elem NU e primul din colectie, actualizam elem anterior
                        previous->next = current->next;
                    }
                    delete current;
                }
                return true;
            }
            previous = current;
            current = current->next;
        }
        //Daca elem nu se afla in colectie return false
        return false;
    }
}

//COMPLEXITATE
//best theta(1) cand elem e primul
//worst theta(n)
//overall O(n)
bool Colectie::cauta(TElem elem) const {
    //Verificam daca un elem se afla in colectie
    if (head == nullptr) {
        //Daca colectia e vida return false
        return false;
    }
    else {
        //Daca colectia nu e vida cautam pozitia elem in colectie
        Node* current = head;
        while (current != nullptr && rel(current->elem, elem)) {
            if (current->elem == elem) {
                //Daca am gasit elem return true
                return true;
            }
            current = current->next;
        }
        //Daca nu am gasit elem return false
        return false;
    }
}

//COMPLEXITATE
//best theta(1) cand elem e primul
//worst theta(n)
//overall O(n)
int Colectie::nrAparitii(TElem elem) const {
    //Cautam frecventa unui elem in colectie
    if (head == nullptr) {
        //Daca colectia e vida, return 0
        return 0;
    }
    else {
        //Daca colectia nu e vida cautam pozitia elem in colectie
        Node* current = head;
        while (current != nullptr && rel(current->elem, elem)) {
            if (current->elem == elem) {
                //daca am gasit elementul ii returnam frecventa
                return current->nr;
            }
            current = current->next;
        }
        //daca elem nu e in colectie, return 0
        return 0;
    }
}



int Colectie::dim() const {
    //returnam nr de elemente din colectie
    return size;
}


bool Colectie::vida() const {
    return size == 0;
}


IteratorColectie Colectie::iterator() const {
    return  IteratorColectie(*this);
}


Colectie::~Colectie() {
    //Destructor
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}