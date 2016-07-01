#include <iostream>

using namespace std;

class nodo{
    public:
        int dato;
        nodo* sig;
        nodo(int);
        virtual ~nodo();
};

nodo::nodo(int a){
    dato=a;
    sig=NULL;
}
nodo::~nodo(){}



class cola{

public:
    static cola* getinstancia(){
        if (unico == NULL)
            unico = new cola();
        return unico;
    }
    nodo* primero;
    nodo* ultimo;
        
    void push(int );
    void print();
    int pop();
    bool clear();
    virtual ~cola(); 

private:
        cola();
        static cola* unico;
};


cola::cola(){
    primero = NULL;
    ultimo = NULL;
}

void cola::push(int x){
    if (!primero){
        primero=new nodo(x);
        ultimo=primero;
    }
    else{
        ultimo->sig=new nodo(x);
        ultimo=ultimo->sig;
    }
}

void cola::print(){

    nodo* temp;
    temp=primero;
    while(temp!=NULL){
        cout <<temp->dato<<endl;
        temp=temp->sig;
    }
}

int cola::pop(){
	int w = primero->dato;
	nodo *temp = primero;
	primero = temp->sig;
	delete(temp);
	return w;
}

bool cola::clear(){
	if(!primero)
		return false;
}

cola::~cola(){   }

cola* cola::unico=NULL;