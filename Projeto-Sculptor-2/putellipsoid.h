#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

/**
 * @brief Classe putEllipsoid
 */
class putEllipsoid:
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
    /**
     * @brief r
     */
    float r;
    /**
     * @brief g
     */
    float g;
    /**
     * @brief b
     */
    float b;
    /**
     * @brief a
     */
    float a;
public:
    /**
     * @brief Guarda as variaveis da elipsoide
     * @param xcenter (x central)
     * @param ycenter (y central)
     * @param zcenter (z central)
     * @param rx (raio de x)
     * @param ry (raio de y)
     * @param rz (raio de z)
     * @param r (cor vermelha)
     * @param g (cor verde)
     * @param b (cor azul)
     * @param a (grau de transparencia)
     */
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    /**
    * @brief Destrutor da classe
    */
    ~putEllipsoid();
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
