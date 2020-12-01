#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/**
 * @brief Classe FiguraGeometrica
 */
class FiguraGeometrica{
protected:
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
