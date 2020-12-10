#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe CutVoxel
 */
class CutVoxel:
        public FiguraGeometrica
{
    /**
     * @brief x
     */
    int x;
    /**
     * @brief y
     */
    int y;
    /**
     * @brief z
     */
    int z;
public:
    /**
     * @brief Guarda as variaveis do voxel
     * @param x
     * @param y
     * @param z
     */
    CutVoxel(int x,int y, int z);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
