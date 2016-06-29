#include "bitmap.cpp"
#include "begin.cpp"
#include "menu.cpp"
#include "ghosth.cpp"
#include <thread>

using namespace std;

const int ANCHO = 880;
const int ALTO = 600;

void direccion(){
    if(key[KEY_UP])
        dir = 2;
    else if(key[KEY_DOWN])
        dir = 3;
    else if(key[KEY_RIGHT])
        dir = 1;
    else if(key[KEY_LEFT])
        dir = 0;
}

int main(int argc, char const *argv[]){

    inicia_allegro(ANCHO, ALTO);
    inicia_audio(70,70);

    cargar_bitmap();

    //menu(portada);

    //inicia_mapa();

    ghosth *A = new clyde(enem1, enemy1,die, 30*2, 30*3);
    ghosth *B = new clyde(enem2, enemy2,die, 30*15, 30*15);
    ghosth *C = new clyde(enem3, enemy3,die, 30*5, 30*8);
    ghosth *D = new clyde(enem4, enemy4,die, 30*8, 30*13);

    //lives(life);
    mapa = restart_game(restart, mapa);

    posicion_inicial(h);
    //play_sample(start,100,150,1000,1);

    bool t = true;
	while(!key[KEY_ESC] and t){

        back_px = px;
        back_py = py;

        thread th1(direccion);

        if(key[KEY_SPACE]){
            save_map(mapa);
            t = false;
        }

		if(dir==0 and mapa[py/30][(px/30)-1] != 1)
                px-= 30;
        else if(dir==1 and mapa[py/30][(px/30)+1] != 1)
                px+=30;
        else if(dir==2 and mapa[(py/30)-1][px/30] != 1)
                py-=30;
        else if(dir==3 and mapa[(py/30)+1][px/30] != 1)
                py+=30;
        else
            dir = 4;

        if(px<=-30)
            px = 870;
        else if (px>=870)
            px = -30;

        clear(buffer);
        mapa = print_mapa(mapa);
        print_pacman();

        A->move_ghosth(mapa);
        B->move_ghosth(mapa);
        C->move_ghosth(mapa);
        D->move_ghosth(mapa);

		pantalla(buffer);
        rest(70);

        clear(pacman);
        blit(pac, pacman, 4*33, 0, 0, 0, 33, 33);
        draw_sprite(buffer, pacman, px, py);
        pantalla(buffer);
        rest(90);
        th1.join();
	}
    return 0;
}
END_OF_MAIN();
/*
compiler use : g++ -> -std:c++11 C+
pacman ..........................
*/
