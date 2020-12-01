#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

/**
 * @brief Classe cutSphere
 */
class cutSphere:
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
     * @brief radius
     */
    int radius;
public:
    /**
     * @brief Guarda as variaveis da esfera
     * @param xcenter (x central)
     * @param ycenter (y central)
     * @param zcenter (z central)
     * @param radius (raio)
     */
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};


#endif // CUTSPHERE_H
