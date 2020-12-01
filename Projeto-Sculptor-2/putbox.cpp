#include "putbox.h"
#include "figurageometrica.h"

putBox::putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a)
{
    this->x0=x0,this->x1=x1,this->y0=y0,this->y1=y1,this->z0=z0,this->z1=z1;
    this->r=r,this->g=g,this->b=b,this->a=a;
}

putBox::~putBox()
{
    cout<<"Destrutor putBox\n";
}

void putBox::draw(Sculptor &s)
{
    int i,j,k;
    s.setColor(r,g,b,a);
    if(x0>x1)
        troca(x0,x1);
    if(y0>y1)
        troca(y0,y1);
    if(z0>z1)
        troca(z0,z1);
    for(i=x0;i<=x1;i++){
        for(j=y0;j<=y1;j++){
            for(k=z0;k<=z1;k++){
                s.putVoxel(i,j,k);
            }
        }
    }
}
