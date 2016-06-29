#include <allegro.h>

void menu(BITMAP *p){
    int parp = 0;
    int y = 0;
    int cont = 0;
    bool salida = false;
    bool carga = false;

    while(!salida){
        if(parp < 25) blit(p, screen, 0, y, 50, 30, 800, 533);
        else blit(p, screen, 800, y, 50, 30, 800, 533);
        if(key[KEY_ENTER]){
            y = 533;
            carga = true;
        }
        if(carga) cont++;
        if(cont > 400) salida = true;

        rest(5);
        if(++parp == 50) parp = 0;
    }
    clear_to_color(screen, 0x000000);
}

void lives(BITMAP *p){
    bool salida = false;
    while(!salida){
        blit(p, screen, 0, 0, 0, 0, 860, 572);
        if(key[KEY_ENTER])
            salida = true;
    }
    clear_to_color(screen, 0x000000);
}

void print_fondo(BITMAP* fondo, BITMAP* buffer){
    masked_blit(fondo, buffer, 0, 0, 0, 0, 600,600);
}
