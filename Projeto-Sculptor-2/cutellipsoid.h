#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

/**
 * @brief Classe cutEllipsoid
 */
class cutEllipsoid :
        public FiguraGeometrica
{
    /**
     * @brief xcenter
     */
    int xcenter;
    /**
     * @brief ycenter
     */
    int ycenter;
    /**
     * @brief zcenter
     */
    int zcenter;
    /**
     * @brief rx
     */
    int rx;
    /**
     * @brief ry
     */
    int ry;
    /**
     * @brief rz
     */
    int rz;
public:
    /**
     * @brief Guarda as variaveis da elipsoide
     * @param xcenter (x central)
     * @param ycenter (y central)
     * @param zcenter (z central)
     * @param rx (raio de x)
     * @param ry (raio de y)
     * @param rz (raio de z)
     */
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
