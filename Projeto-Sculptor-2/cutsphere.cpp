#include "cutsphere.h"
#include "figurageometrica.h"
#include <math.h>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter=xcenter,this->ycenter=ycenter,this->zcenter=zcenter,this->radius=radius;
}

void CutSphere::draw(Sculptor &s)
{
    int i,j,k;
    int xc,yc,zc,rs;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;
    rs = radius;

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
