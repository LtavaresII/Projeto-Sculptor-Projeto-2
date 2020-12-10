#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe PutSphere
 */
class PutSphere:
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
     * @brief Guarda as variaveis da esfera
     * @param xcenter (x central)
     * @param ycenter (y central)
     * @param zcenter (z central)
     * @param radius (raio)
     * @param r (cor vermelha)
     * @param g (cor verde)
     * @param b (cor azul)
     * @param a (grau de transparencia)
     */
    PutSphere(int xcenter, int ycenter, int zcenter, int radius,float r, float g, float b, float a);
    /**
    * @brief Destrutor da classe
    */
    ~PutSphere();
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
