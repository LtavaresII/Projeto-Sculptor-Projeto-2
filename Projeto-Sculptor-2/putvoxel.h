#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe PutVoxel
 */
class PutVoxel:
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
     * @brief Guarda as variaveis do voxel
     * @param x
     * @param y
     * @param z
     * @param r (cor vermelha)
     * @param g (cor verde)
     * @param b (cor azul)
     * @param a (grau de transparencia)
     */
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    void draw(Sculptor &s);
    /**
    * @brief Destruidor da classe
    */
    ~PutVoxel();
};

#endif // PUTVOXEL_H
