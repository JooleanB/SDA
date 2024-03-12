#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

//teta(1)
LO::LO(Relatie r) {
    /* de adaugat */
    this->relatie=r;
    //lista este initial vida
    this->prim= -1;
    //primul element liber este cel dintai
    this->primLiber=0;
    //aloc spatiu
    this->valori= new TElement[cp];
    this->urmator=new int[cp];
    this->predecesor=new int[cp];
    for(int i=0;i<cp;i++)
    {
        urmator[i]=i+1;
        predecesor[i]=i-1;
        predecesor[0]=-1;
    }
    urmator[cp - 1] = -1;
}
//O(cp)-cp capacitatea vectorului
void LO::resize()
{
    TElement* valoriN= new TElement[2*cp];
    int* urmatorN= new int[2*cp];
    int* predecesorN= new int[2*cp];
    for(int i=0;i<2*cp;i++)
    {
        urmatorN[i]=i+1; 
        predecesorN[i]=i-1;
        predecesorN[0]=-1;
    }
    urmatorN[2 * cp - 1] = -1;
    for(int i=0;i<cp-1;i++)
    {
        valoriN[i]=valori[i];
        urmatorN[i]=urmator[i];
        predecesorN[i]=predecesor[i];
    }
    valoriN[cp-1]=valori[cp-1];
    urmatorN[cp-1]=cp;
    predecesorN[cp-1]=cp-1;

    delete[] urmator;
    delete[] valori;
    delete[] predecesor;

    urmator=urmatorN;
    valori=valoriN;
    predecesor=predecesorN;
    cp=2*cp;
}

//teta(1)
int LO::aloca() {
    int i=primLiber;
    primLiber=urmator[primLiber];
    return i;
}

//teta(1)
void LO::dealoca(int poz) {
    urmator[poz]=primLiber;
    predecesor[poz]= -1;
    primLiber=poz;
}

// returnare dimensiune
//teta(n)
int LO::dim() const {
    /* de adaugat */
    int n=0;
    int p=this->prim;
    while(p!= -1)
    {
        p=urmator[p];
        n++;
    }
    return n;
}

// verifica daca LO e vida
//teta(1)
bool LO::vida() const {
    /* de adaugat */
    if (this->prim == -1) {
        return true;
    }
    return false;
}

// returnare element
//arunca exceptie daca i nu e valid
//teta(n)
TElement LO::element(int i) const{
    /* de adaugat */
    if(this->prim== -1||i>=this->dim()||i<0)
        throw std::exception();
    int poz=0;
    int p=this->prim;
    while(poz<i)
    {
        p=urmator[p];
        poz++;
    }
    return valori[p];
}

// sterge element de pe o pozitie i si returneaza elementul sters
//arunca exceptie daca i nu e valid
//O(n)
TElement LO::sterge(int i) {
    /* de adaugat */
    if(this->prim==-1||i<0||i>=this->dim())
        throw std::exception();
    //sterg primul element
    if(i==0)
    {
        int aux=this->prim;
        TElement val=this->valori[prim];
        this->prim=urmator[aux];
        dealoca(aux);
        return val;
    }
    //sterg ultimul element
    if(i==this->dim()-1)
    {
        int poz=0;
        int p=this->prim;
        while(poz<i-1)
        {
            p=urmator[p];
            poz++;
        }
        int aux=urmator[p];
        TElement val=this->valori[aux];
        urmator[p]= -1;
        //daca elementul de pe ultima pozitie nu mai exista nu mai poate sa aiba
        //predecesor
        predecesor[aux]= -1;
        dealoca(aux);
        return val;
    }
    //sterg element din interior
    int poz=0;
    int p=this->prim;
    while(poz<i-1)
    {
        p=urmator[p];
        poz++;
    }
    int aux=urmator[p];
    TElement val=this->valori[aux];
    urmator[p]=urmator[aux];
    predecesor[urmator[aux]]=p;
    dealoca(aux);
    return val;
}

// cauta element si returneaza prima pozitie pe care apare (sau -1)
//O(n)
int LO::cauta(TElement e) const {
    /* de adaugat */
    int p=this->prim;
    int poz=0;
    while(p!= -1)
    {
        if(this->valori[p]==e)
            return poz;
        p=urmator[p];
        poz++;
    }
    return -1;
}

// adaugare element in LO
//O(n)
void LO::adauga(TElement e) {
    /* de adaugat */
    if(dim()+1>=cp)
    {
        resize();
    }
    //daca lista este vida sau il adaug pe prima pozitie
    if(this->vida()==true||this->relatie(e,valori[this->prim])==true)
    {
        int nou=aloca();
        urmator[nou]=this->prim;
        valori[nou]=e;
        this->prim=nou;
        if (urmator[nou] != -1)
            predecesor[urmator[nou]] = nou;
        return;
    }
    //incerc sa il adaug intre doua elemente
    int a=this->prim;
    while(urmator[a]!= -1)
    {
        int b=urmator[a];
        if(this->relatie(valori[a],e)==true && this->relatie(e,valori[b])==true)
        {
            int nou= aloca();
            urmator[a]=nou;
            urmator[nou]=b;
            predecesor[b]=nou;
            predecesor[nou]=a;
            valori[nou]=e;
            return;

        }
        a=urmator[a];
    }
    //trebuie sa il adaug la final
    int nou= aloca();
    urmator[a]=nou;
    urmator[nou]=-1;
    predecesor[nou]=a;
    valori[nou]=e;
}


// returnare iterator
Iterator LO::iterator(){
    return Iterator(*this);
}


//destructor
//teta(n)
LO::~LO() {
    /* de adaugat */
    delete[] valori;
    delete[] urmator;
    delete[] predecesor;
}
