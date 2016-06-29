#include <allegro.h>
#include <vector>
#include <stdio.h>
#include "objectpool.cpp"

object_pool* object_pool::instance = NULL;

int h=0;

int **level(int x){
    object_pool* pool = object_pool::get_instance();

    mapa_sws *A;
    mapa_sws *B;
    mapa_sws *C;
    mapa_sws *D;
    mapa_sws *E;

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

int **mapa = level(h);

void posicion_inicial(int h){
    if(h==0){
        px = 30*14;
        py = 30*4;
    }
    else if(h==1){
        px = 30*1;
        py = 30*9;
    }
    else if(h==2){
        px = 30*24;
        py = 30*12 ;
    }
    else if(h==3){
        px = 30*14;
        py = 30*11;
    }
    else if(h==4){
        px = 30*14;
        py = 30*8
        ;
    }

    dir = 4;
}

int num_tiles(int **mapa, int id){
    int row, col;
    int _n = 0;
    for (row=0; row<filas; row++)
        for (col=0; col<columnas; col++)
            if (mapa[row][col] == id) ++_n;
    return _n;
}

bool next_level(int **mapa, int x, int y){
    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            if(mapa[i][j] == x or mapa[i][j] == y)
                return false;
    return true;
}

void lol(int px, int py, int f, int c){
    if(px/30 == c and py/30 == f){
        //play_sample(eat,100,150,1000,0);
        mapa[f][c] = 0;
    }
}

int **asd(){
    h++;
    alert("your winner!", NULL, NULL, "aceptar\npresione ESC", NULL, 'a', 0);
    //delete_matriz(mapa);
    posicion_inicial(h);
    //return mapa;
    return level(h);
}

int **print_mapa(int **mapa){
    //inicia_mapa();
	int f, c;
	for(f=0; f<filas;f++)
		for(c=0;c<columnas;c++){
			if(mapa[f][c] == 1)
				draw_sprite(buffer,rock, c*30, f*30);
            else if(mapa[f][c] == 3){
                draw_sprite(buffer,dish1, c*30, f*30);
                lol(px,py,f,c);
                if(next_level(mapa,3,4) == true) return asd();
            }
            else if(mapa[f][c] == 4){
                draw_sprite(buffer,dish2,c*30, f*30);
                lol(px,py,f,c);
                if(next_level(mapa,3,4) == true) return asd();
            }
        }
    return mapa;
}

void pantalla(BITMAP *buffer){
	blit(buffer, screen, 0, 0, 0, 0,880, 600);
}
