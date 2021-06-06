//
// Created by mavros on 28/5/21.
//

#ifndef PROYECTOII_LETSPLAY_DIRECTION_H
#define PROYECTOII_LETSPLAY_DIRECTION_H

#include <vector>

/**
 * Lista de los 4 tipos de direcciones
 */
enum class direction {UP, DOWN, LEFT, RIGHT};

/**
 * vector con todas las direciones utilizado para retornar una dirección aleatoria
 */
static std::vector<direction> ALL_DIRECTIONS({direction::UP, direction::DOWN, direction::LEFT, direction::RIGHT});

#endif //PROYECTOII_LETSPLAY_DIRECTION_H
