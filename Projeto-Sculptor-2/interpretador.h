#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "figurageometrica.h"
#include <string>

/**
 * @brief Classe Interpretador
 */
class Interpretador{
    /**
     * @brief dimx
     */
    int dimx;
    /**
     * @brief dimy
     */
    int dimy;
    /**
     * @brief dimz
     */
    int dimz;
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
     * @brief Construtor da classe
     */
    Interpretador();
    /**
     * @brief parse
     * @param filename (Nome do arquivo)
     * @return
     */
    vector<FiguraGeometrica *> parse(string filename);
    /**
     * @brief Retorna x
     * @return
     */
    int getX();
    /**
     * @brief Retorna y
     * @return
     */
    int getY();
    /**
     * @brief Retorna z
     * @return
     */
    int getZ();
};


#endif // INTERPRETADOR_H
