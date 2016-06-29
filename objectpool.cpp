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

