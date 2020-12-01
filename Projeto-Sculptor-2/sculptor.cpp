#include "sculptor.h"
#include <cmath>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //Guarda os valores das variaveis
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //Fixa os valores para 0, caso forem menor que 0
    if((nx<=0) || (ny<=0) || (nz<=0) ){
        nx=ny=nz=0;
    }

    int i,j,k;

    // Cria a matriz Voxel em 3 dimensões
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for(i=1;i<nz;i++){
        v[i] = v[i-1] + ny;
    }

    for(i=1;i<nz*ny;i++){
        v[0][i] = v[0][i-1] + nx;
    }

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                v[i][j][k].isOn=false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    // Deleta a matriz Voxel
    if(nx==0||ny==0||nz==0){
        return;
    }
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    // Cores e a opacidade do solido
    rv = r;
    gv = g;
    bv = b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    // Atribui as cores e opacidade para cada voxel
    if((x>=nx)||(y>=ny)||(z>=nz)){
        return;
    }
    if((x<0)||(y<0)||(z<0)){
        return;
    }
    v[x][y][z].isOn = true;
    v[x][y][z].r = rv;
    v[x][y][z].g = gv;
    v[x][y][z].b = bv;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    // Esconde a matriz Voxel do solido
    if((x>=nx)||(y>=ny)||(z>=nz)){
        return;
    }
    if((x<0)||(y<0)||(z<0)){
        return;
    }
    v[x][y][z].isOn=false;
}
void Sculptor::writeOFF(string filename)
{
    int x =nx;
    int y =ny;
    int z =nz;
    char off[x][y][z];
    int i,j,k;
    //Preencher a string com 0 para verificar se é valido
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                off[i][j][k] = 0;
            }
        }
    }

    int nvox = 0;
    ofstream outfile (filename);
    outfile<<"OFF"<<endl;
    //Soma 1 a nvox se o voxel for isOn=true
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn && (off[i][j][k] == 0)){
                    nvox++;
                }
            }
        }
    }
    //8*nvoxels vertices, 6*nvoxels faces e 0 arestas
    outfile<<8*nvox<<" "<<6*nvox<<" "<<0<<endl;

    //Coordenadas dos nvoxels
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn && off[i][j][k] == 0){
                    //Linha 1
                    outfile<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 2
                    outfile<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 3
                    outfile<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 4
                    outfile<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 5
                    outfile<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                    //Linha 6
                    outfile<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                    //Linha 7
                    outfile<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                    //Linha 8
                    outfile<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                }
            }
        }
    }

    //Faces da figura e suas caracteristicas(cores, opacidade)
    int nf=0;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn && (off[i][j][k] == 0)){
                    //Face 1
                    outfile<<"4 "<<0+nf*8<<" "<<3+nf*8<<" "<<2+nf*8<<" "<<1+nf*8<<" "<<fixed<<setprecision(1)<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 2
                        <<"4 "<<4+nf*8<<" "<<5+nf*8<<" "<<6+nf*8<<" "<<7+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 3
                        <<"4 "<<0+nf*8<<" "<<1+nf*8<<" "<<5+nf*8<<" "<<4+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 4
                        <<"4 "<<0+nf*8<<" "<<4+nf*8<<" "<<7+nf*8<<" "<<3+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 5
                        <<"4 "<<3+nf*8<<" "<<7+nf*8<<" "<<6+nf*8<<" "<<2+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 6
                        <<"4 "<<1+nf*8<<" "<<2+nf*8<<" "<<6+nf*8<<" "<<5+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    nf++;
                }
            }
        }
    }
    outfile.close();
    cout<<"Arquivo criado com sucesso"<<endl;
}

void Sculptor::limpaVoxels(void)
{
    std::queue<int> q;
    int x,y,z;
    int lx,ly,lz;
    for(x=1;x<nx-1;x++){
        for(y=1;y<ny-1;y++){
            for(z=1;z<nz-1;z++){
                if((v[x][y][z].isOn == true) &&
                   (v[x+1][y][z].isOn == true) &&
                   (v[x-1][y][z].isOn == true) &&
                   (v[x][y+1][z].isOn == true) &&
                   (v[x][y-1][z].isOn == true) &&
                   (v[x][y][z+1].isOn == true) &&
                   (v[x][y][z-1].isOn == true)){
                    q.push(x);
                    q.push(y);
                    q.push(z);
                }
            }
        }
    }
    while(!q.empty()){
        lx = q.front();q.pop();
        ly = q.front();q.pop();
        lz = q.front();q.pop();
        v[lx][ly][lz].isOn = false;
    }
}

void troca(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
