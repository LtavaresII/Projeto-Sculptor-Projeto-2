#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe PutBox
 */
class PutBox :
        public FiguraGeometrica
{
private:
    /**
     * @brief x0
     */
    int x0;
    /**
     * @brief x1
     */
    int x1;
    /**
     * @brief y0
     */
    int y0;
    /**
     * @brief y1
     */
    int y1;
    /**
     * @brief z0
     */
    int z0;
    /**
     * @brief z1
     */
    int z1;
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
     * @brief putBox
     * @param x0 (x incial)
     * @param x1 (x final)
     * @param y0 (y incial)
     * @param y1 (y final)
     * @param z0 (z incial)
     * @param z1 (z final)
     * @param r (cor vermelha)
     * @param g (cor verde)
     * @param b (cor azul)
     * @param a (grau de transparencia)
     */
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    /**
    * @brief Destrutor da classe
    */
    ~PutBox();
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // PUTBOX_H
