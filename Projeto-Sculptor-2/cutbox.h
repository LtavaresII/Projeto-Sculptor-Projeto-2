#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe CutBox
 */
class CutBox :
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
public:
    /**
     * @brief Guarda as variaveis da caixa
     * @param x0 (x incial)
     * @param x1 (x final)
     * @param y0 (y incial)
     * @param y1 (y final)
     * @param z0 (z incial)
     * @param z1 (z final)
     */
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // CUTBOX_H
