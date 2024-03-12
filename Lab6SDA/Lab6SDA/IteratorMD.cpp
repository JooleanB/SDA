#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md) : md(_md) {
    prim();
    /* de adaugat */
}

TElem IteratorMD::element() const {
    if (!valid())
        throw exception();
    return md.Tabela[md.hash(cheie)][index]; // returneaza elementul din tabela de dispersie cu cheia si indexul la care este iteratorul
    //return pair <TCheie, TValoare>  (-1, -1);
}

bool IteratorMD::valid() const {
    auto& Bucket = md.Tabela[md.hash(cheie)]; //bucket va fi vectorul de valori al elementelor de la cheia respectiva
    if (index < Bucket.size()) // daca indexul este mai mic inseamna ca exista elementul respectiv deci iteratorul este valid
        return true;
    return false;
}

void IteratorMD::urmator() {
    if (!valid())
        throw exception();
    vector <TElem> Bucket;
    Bucket = md.Tabela[md.hash(cheie)];
    index++; //cresc indexul
    if (index == Bucket.size()) // in cazul in care am ajuns la finalul vectorului in care stochez elementele cu cheia respectiva
    { // inseamna ca urmatorul o sa fie de la urmatoarea cheie si setez indexul la 0 si noua cheia ca fiind i
        for (int i = cheie + 1; i < md.max_cap; i++)
            if (!md.Tabela[md.hash(i)].empty()) {
                cheie = i;
                index = 0;
                break;
            }
    }

}

void IteratorMD::prim() {

    if (md.size == 0) //daca nu exista nimic in multidictionar
        return;
    for (int i = 0; i < md.max_cap; i++) // altfel il setez pe primul ca fiind prima cheie valida si indexul 0
        if (!md.Tabela[md.hash(i)].empty()) {
            index = 0;
            cheie = i;
            break;
        }
}

