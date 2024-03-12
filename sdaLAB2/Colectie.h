#pragma once

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

    friend class IteratorColectie;

private:
    //colectie reprezentata printr o lista simpla inlantuita cu perechi de elem si frecventa lor
    struct Node {
        TElem elem;
        int nr;
        Node* next;
    };

    Node* head;
    int size;

public:
    //constructorul implicit
    Colectie();

    //adauga un element in colectie
    void adauga(TElem e);

    //sterge o aparitie a unui element din colectie
    //returneaza adevarat daca s-a putut sterge
    bool sterge(TElem e);

    //verifica daca un element se afla in colectie
    bool cauta(TElem elem) const;

    //returneaza numar de aparitii ale unui element in colectie
    int nrAparitii(TElem elem) const;


    //intoarce numarul de elemente din colectie;
    int dim() const;

    //verifica daca colectia e vida;
    bool vida() const;

    //returneaza un iterator pe colectie
    IteratorColectie iterator() const;

    // destructorul colectiei
    ~Colectie();


};