#include <allegro.h>
#include "print.cpp"
#include "path.cpp"
#include <string.h>
#include <vector>
#include <queue>
#include "singleton.cpp"
#include <stdio.h>
#include <conio.h>

int live = 3;

class ghosth{
protected:
    BITMAP *enem, *enemy, *die;
    int fdir, _x, _y;
    int home;
    int li;
    queue<int> v;
    queue<int> follow;
public:
    ghosth(BITMAP *a, BITMAP *b, BITMAP *t, int, int, int);
    const void print_ghosth();
    virtual void move_ghosth(int **) = 0;
    int **crash(int **);
};

ghosth::ghosth(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y, int _home){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
    home = _home;
}

const void ghosth::print_ghosth(){
    blit(enem, enemy, 0, 0, 0, 0, 30, 30);
    draw_sprite(buffer, enemy, _x, _y);
}


int **ghosth::crash(int **mapa){
    if((py == _y and px == _x) or (_y == back_py and _x == back_px)){
        play_sample(dead,100,150,1000,0);
        li--;
        for(int j=0;j<=5;j++){
            clear(pacman);
            clear(buffer);
            mapa = print_mapa(mapa);

            blit(die, pacman,j*33, 0, 0, 0, 33, 33);
            draw_sprite(buffer, pacman, px, py);

            pantalla(buffer);
            rest(80);
        }
        if(li == 0){
            li = 3;
            string swq = walk_home(mapa,_x/30,_y/30,25,18);
            for(int i=0;i<swq.size();i++){
                int c = swq[i]-'0';
                v.push(c);
            }
            home = 3;
            //alert("your lose!", NULL, NULL, "aceptar\npresione ESC", NULL, 'a', 0);
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
    clyde(BITMAP *a, BITMAP *b, BITMAP *t, int, int, int);
    void move_ghosth(int **ma);
};

clyde::clyde(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y, int _home) : ghosth(a,b,t,x,y,_home){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
    home = _home;
    li = 5;
}

void clyde::move_ghosth(int **ma){
    print_ghosth();
    mapa = crash(ma);

    if(home == 1){

        //rigth = 1| left = 0 | up = 2 | down = 3
        if(mapa[_y/30][_x/30] == 2) fdir = rand()%4;

        if(fdir == 2)
            (mapa[_y/30][(_x/30)-1] != 1)?_x-=30: fdir = rand()%4;
        else if(fdir == 0)
            (mapa[_y/30][(_x/30)+1] != 1)?_x+=30: fdir = rand()%4;
        else if(fdir == 3)
            (mapa[(_y/30)-1][_x/30] != 1)?_y-=30: fdir = rand()%4;
        else if(fdir == 1)
            (mapa[(_y/30)+1][_x/30] != 1)?_y+=30: fdir = rand()%4;

        if(_x<=-30) _x = 870;
        else if (_x>=870) _x = -30;
    }

    else if (home == 3){
        fdir = v.front();
        if(fdir == 0) _x+=30;
        else if(fdir == 2) _x-=30;
        else if(fdir == 1) _y+=30;
        else if(fdir == 3) _y-=30;
        v.pop();
        if(v.empty()) home = 1;
    }

}

class inky : public ghosth{
public:
    inky(BITMAP *a, BITMAP *b, BITMAP *t, int, int, int);
    void move_ghosth(int **ma);
};

//creep
inky::inky(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y, int _home) : ghosth(a,b,t,x,y,_home){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
    home = home;
    li = 2;
}

void inky::move_ghosth(int **ma){
    print_ghosth();
    mapa = crash(ma);

    if(home == 1){
        string swq = walk_home(mapa,_x/30,_y/30,px/30,py/30);
        fdir = swq[0]-'0';
        if(fdir == 0) _x+=30;
        else if(fdir == 2) _x-=30;
        else if(fdir == 1) _y+=30;
        else if(fdir == 3) _y-=30;
        if(_x<=-30) _x = 870;
        else if (_x>=870) _x = -30;
    }

    else if (home == 3){
        fdir = v.front();
        if(fdir == 0) _x+=30;
        else if(fdir == 2) _x-=30;
        else if(fdir == 1) _y+=30;
        else if(fdir == 3) _y-=30;
        v.pop();
        if(v.empty()) home = 1;
    }
}

//rapidin
class blinky : public ghosth{
public:
    blinky(BITMAP *a, BITMAP *b, BITMAP *t, int, int, int);
    void move_ghosth(int **ma);
};

blinky::blinky(BITMAP *a, BITMAP *b, BITMAP *t, int x, int y, int _home) : ghosth(a,b,t,x,y,_home){
    _x = x; _y = y;
    fdir = rand()%4;
    enem = a;
    enemy = b;
    die = t;
    home = _home;
}

void blinky::move_ghosth(int **ma){
    print_ghosth();
    mapa = crash(ma);

    if(_x<=-30) _x = 870;
    else if (_x>=870) _x = -30;
}

