#include "cutellipsoid.h"
#include "figurageometrica.h"
#include <math.h>

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter=xcenter,this->ycenter=ycenter,this->zcenter=zcenter,this->rx=rx,this->ry=ry,this->rz=rz;
}

void cutEllipsoid::draw(Sculptor &s)
{
    int i,j,k;
    int xc,yc,zc;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;

    for(i=xc-rx;i<=xc+rx;i++){
        for(j=yc-ry;j<=yc+ry;j++){
            for(k=zc-rz;k<=zc+rz;k++){
                float d = pow(float(i-xc)/rx,2)+pow(float(j-yc)/ry,2)+pow(float(k-zc)/rz,2);
                if(d <=1.0){
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
