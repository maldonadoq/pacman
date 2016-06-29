#include <allegro.h>
#include "print.cpp"

int live = 3;

class ghosth{
protected:
    BITMAP *enem, *enemy, *die;
    int fdir, _x, _y;
public:
    ghosth(BITMAP *a, BITMAP *b, BITMAP *t,int x, int y);
    const void print_ghosth();
    virtual void move_ghosth(int **) = 0;
    int **crash(int **);
};

ghosth::ghosth(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
}

const void ghosth::print_ghosth(){
    blit(enem, enemy, 0, 0, 0, 0, 30, 30);
    draw_sprite(buffer, enemy, _x, _y);
}
int **ghosth::crash(int **mapa){
    if((py == _y and px == _x) or (_y == back_py and _x == back_px)){
        play_sample(dead,100,150,1000,0);
        live--;
        for(int j=0;j<=5;j++){
            clear(pacman);
            clear(buffer);
            mapa = print_mapa(mapa);

            blit(die, pacman,j*33, 0, 0, 0, 33, 33);
            draw_sprite(buffer, pacman, px, py);

            pantalla(buffer);
            rest(80);
        }
        if(live == 0){
            live = 3;
            alert("your lose!", NULL, NULL, "aceptar\npresione ESC", NULL, 'a', 0);
            return level(h);
            //return mapa;
        }
        posicion_inicial(h);
        return mapa;
    }
    return mapa;
}

//aleatorio
class clyde : public ghosth{
public:
    clyde(BITMAP *a, BITMAP *b, BITMAP *t, int, int);
    void move_ghosth(int **ma);
};

clyde::clyde(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y) : ghosth(a,b,t,x,y){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
}

void clyde::move_ghosth(int **ma){
    print_ghosth();
    mapa = crash(ma);

    if(mapa[_y/30][_x/30] == 2) fdir = rand()%4;

    if(fdir == 0)
        (mapa[_y/30][(_x/30)-1] != 1)?_x-=30: fdir = rand()%4;
    else if(fdir == 1)
        (mapa[_y/30][(_x/30)+1] != 1)?_x+=30: fdir = rand()%4;
    else if(fdir == 2)
        (mapa[(_y/30)-1][_x/30] != 1)?_y-=30: fdir = rand()%4;
    else if(fdir == 3)
        (mapa[(_y/30)+1][_x/30] != 1)?_y+=30: fdir = rand()%4;

    if(_x<=-30) _x = 870;
    else if (_x>=870) _x = -30;
}

class inky : public ghosth{
public:
    inky(BITMAP *a, BITMAP *b, BITMAP *t, int, int);
    void move_ghosth(int **ma);
};

//creep
inky::inky(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y) : ghosth(a,b,t,x,y){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
}

void inky::move_ghosth(int **ma){
    print_ghosth();
    mapa = crash(ma);


    if(_x<=-30) _x = 870;
    else if (_x>=870) _x = -30;
}

//rapidin
class blinky : public ghosth{
public:
    blinky(BITMAP *a, BITMAP *b, BITMAP *t, int, int);
    void move_ghosth(int **ma);
};

blinky::blinky(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y) : ghosth(a,b,t,x,y){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
}

void blinky::move_ghosth(int **ma){
    print_ghosth();
    mapa = crash(ma);

    if(_x<=-30) _x = 870;
    else if (_x>=870) _x = -30;
}
