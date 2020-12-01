#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

/**
 * @brief Classe cutVoxel
 */
class cutVoxel:
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
    cutVoxel(int x,int y, int z);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
