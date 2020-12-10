#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/**
 * @brief Classe FiguraGeometrica
 */
class FiguraGeometrica{
protected:
    /**
     * @brief r (Cor Vermelho)
     */
    float r;
    /**
     * @brief g (Cor Verde)
     */
    float g;
    /**
     * @brief b (Cor Azul)
     */
    float b;
    /**
     * @brief a (Grau de Transparencia)
     */
    float a;
public:
    /**
     * @brief Destrutor da classe
     */
    virtual ~FiguraGeometrica();
    /**
     * @brief Desenha a matriz sculptor
     * @param s (matriz sculptor)
     */
    virtual void draw(Sculptor &s)=0;
};

#endif // FIGURAGEOMETRICA_H
