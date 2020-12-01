#include "putsphere.h"
#include "figurageometrica.h"
#include <math.h>

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter=xcenter,this->ycenter=ycenter,this->zcenter=zcenter,this->radius=radius;
    this->r=r,this->g=g,this->b=b,this->a=a;
}

putSphere::~putSphere()
{
    cout<<"Destrutor putSphere\n";
}

void putSphere::draw(Sculptor &s)
{
    int i,j,k;
    int xc,yc,zc,rs;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;
    rs = radius;

    s.setColor(r, g, b, a);

    for(i=xc-r;i<=xc+r;i++){
        for(j=yc-r;j<=yc+r;j++){
            for(k=zc-r;k<=zc+r;k++){
                float d = pow(float(i-xc)/rs,2)+pow(float(j-yc)/rs,2)+pow(float(k-zc)/rs,2);
                if(d <=1.0){
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
