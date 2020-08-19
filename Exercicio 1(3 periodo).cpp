#include <iostream>

using namespace std;

class celula
{
private:
    string name;
    celula *next;
public:
    celula(){
        next = NULL;
    }
    //Metodo construtor
    celula(string n,celula* nxt){
    	setName(n);
    	setNext(nxt);
	}

    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }

    void setNext(celula *c){
        next = c;
    }

    celula *getNext(){
        return next;
    }
};

class lista
{
private:
    celula * start;
public:
    lista(){
        start = NULL;
    }
    celula * getStart(){
        return start;
    }
    void insertBegin(string name){
        celula * nw = new celula(name,start);
        //nova->setNome(nome);
        //nova->setProxima(inicio);
        start = nw;
    }
    void show(){
        if(start == NULL){
            cout << "Empty List" << endl;
        }
        else{
            celula *aux = start;
            while(aux != NULL){
                cout << aux->getName() << endl;
                aux = aux->getNext();
            }
        }
    }
};
int main()
{
    lista alunos;
    alunos.insertBegin("Du carai");
    alunos.insertBegin("Virus");
    alunos.insertBegin("Sai");
    alunos.show();
    return 0;
}
