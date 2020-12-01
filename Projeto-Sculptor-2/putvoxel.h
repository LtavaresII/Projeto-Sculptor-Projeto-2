#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

/**
 * @brief Classe putVoxel
 */
class putVoxel:
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
     * @param r (cor vermelha)
     * @param g (cor verde)
     * @param b (cor azul)
     * @param a (grau de transparencia)
     */
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
    /**
    * @brief Destruidor da classe
    */
    ~putVoxel();
};

#endif // PUTVOXEL_H
