#include <iostream>
#include <vector>
#include "mapa.cpp"
#include "level.cpp"


using namespace std;

class object_pool{
private:
	vector<mapa_sws*> m;
	static object_pool *instance;
	object_pool();
public:
	static object_pool* get_instance(){
		if(instance == NULL)
			instance = new object_pool;
		return instance;
	}

	mapa_sws* get_mapa(){
		if(m.empty())
			return new mapa_sws(filas,columnas);
		else{
			mapa_sws* asd = m.front();
			m.pop_back();
			return asd;
		}
	}
	void return_mapa(mapa_sws* object){
		object->reset();
		m.push_back(object);
	}
};

object_pool::object_pool(){

}

int **level(int x){
    object_pool* pool = object_pool::get_instance();

    mapa_sws *A = new mapa_sws(filas, columnas);
    mapa_sws *B = new mapa_sws(filas, columnas);
    mapa_sws *C = new mapa_sws(filas, columnas);
    mapa_sws *D = new mapa_sws(filas, columnas);
    mapa_sws *E = new mapa_sws(filas, columnas);

    A = pool->get_mapa();
    B = pool->get_mapa();
    C = pool->get_mapa();
    D = pool->get_mapa();
    E = pool->get_mapa();

    A->pull_mapa(0);
    B->pull_mapa(1);
    C->pull_mapa(2);
    D->pull_mapa(3);
    E->pull_mapa(4);

    if(x==0){
        pool->return_mapa(A);
        A = pool->get_mapa();
        return A->get_mapa();
    }
    else if(x==1){
        pool->return_mapa(B);
        B = pool->get_mapa();
        return B->get_mapa();
    }
    else if(x==2){
        pool->return_mapa(C);
        C = pool->get_mapa();
        return C->get_mapa();
    }
    else if(x==3){
        pool->return_mapa(D);
        D = pool->get_mapa();
        return D->get_mapa();
    }
    else if(x==4){
        pool->return_mapa(E);
        E = pool->get_mapa();
        return E->get_mapa();
    }
    else return nullptr;
    //int **mapa = asd[h].get_mapa();
}

