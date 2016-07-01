//#include <allegro.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

static int filas = 20;
static int columnas = 29;

using namespace std;

FILE *save;

class mapa_sws{
private:
    int **ma;
    int fil, col;
	FILE *doc;
public:
    mapa_sws(int , int);
    void pull_mapa(int );
    void reset();
    int **get_mapa();
    void print();
    //int **operator=(int **);
    ~mapa_sws();
};

mapa_sws::mapa_sws(int x, int y){
    fil = x;
    col = y;
    doc = fopen("asd/mapa.txt", "r");
    ma = new int *[fil];
    for(int i=0;i<fil;i++)
        ma[i] = new int [col];

    for(int i=0;i<fil;i++)
        for(int j=0;j<col;j++)
            ma[i][j] = 0;
}

mapa_sws::~mapa_sws(){

}

void mapa_sws::pull_mapa(int x){
    int lines = x*(fil+2);
    int c;
    while((c=getc(doc))!=EOF and lines!=0){
        if(c=='\n') lines--;
	}
    int i=0, j=0;
    while((c=getc(doc))!=EOF and i!=fil){
        ma[i][j] = c-'0';
        j++;
        if(c == '\n'){
            j=0;
            i++;
        }
    }
}

void mapa_sws::reset(){
    ma = get_mapa();
}

int **mapa_sws::get_mapa(){
    return ma;
}

void mapa_sws::print(){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++)
            cout << ma[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;
}

/*int **mapa_sws::operator=(int **x){
    return ma;
}*/
