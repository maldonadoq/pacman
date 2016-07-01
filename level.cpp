#include <allegro.h>
#include <stdio.h>
#include <conio.h>

void delete_matriz(int **mapa){
    for (int i = 0; i < filas; i++)
        delete[] mapa[i];
    delete[] mapa;
}

void save_map(int **p){
    save = fopen("asd/file.txt","w");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            fprintf(save,"%d",p[i][j]);
            if(j==columnas-1) fprintf(save,"%d\n",p[i][j]);
         }
    }
}

int **fill(){
    //llenar
    int **mapa;
    mapa = new int* [filas];
    for (int i = 0; i < filas; i++)
        mapa[i] = new int[columnas];

    save = fopen("asd/file.txt","r");
    int c;
    int i=0, j=0;
    while((c=getc(save)) != EOF){
        mapa[i][j] = (c-'0');
        j++;
        if(c == '\n'){
            i++;
            j = 0;
        }
    }

    return mapa;
}

int **restart_game(BITMAP *p, int **mapa){
    bool salida = false;

    while(!salida){
        blit(p, screen, 0, 0, 0, 0, 860, 572);
        if(key[KEY_S]){
            salida = true;
            return fill();
        }
        else if(key[KEY_N]){
            salida = true;
        }
    }
    clear_to_color(screen, 0x000000);
    return mapa;
}
