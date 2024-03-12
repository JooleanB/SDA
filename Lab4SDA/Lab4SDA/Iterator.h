#pragma once


#include "LO.h"

class LO;


class Iterator{
    friend class LO;
private:
    Iterator(LO& lo);
    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
   

    //contine o referinta catre containerul pe care il itereaza
    LO& lista;

    /* aici e reprezentarea  specifica a iteratorului */
    //nodul curent;
    int curent;


public:
    

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void predecesor();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElement element() const;

    //TElement elimina();
};


