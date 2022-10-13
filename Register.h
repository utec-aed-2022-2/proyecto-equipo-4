//
// Created by juaquin on 09/10/22.
//

#ifndef PROYECTO_EQUIPO_4_REGISTER_H
#define PROYECTO_EQUIPO_4_REGISTER_H


#include <string>

struct Register {
    std::string emisor;
    std::string receptor;
    float monto;
    std::string fecha;

    Register() = default;

    Register(const std::string &line);

    operator std::string() const;
};


#endif //PROYECTO_EQUIPO_4_REGISTER_H
