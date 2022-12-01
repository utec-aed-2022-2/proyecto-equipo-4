//
// Created by juaquin on 09/10/22.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include "Register.h"

Register::Register(const std::string &line) {
    std::stringstream str(line);
    std::cout << line << std::endl;
    getline(str, this->emisor, ',');
    getline(str, this->receptor, ',');
    std::string t;
    getline(str, t, ',');
    this->monto = stof(t);
    getline(str, this->fecha);
}

Register::operator std::string() const {
    std::string s = std::to_string(monto);
    std::replace(s.begin(), s.end(), ',', '.');
    return emisor+","+receptor+","+s+","+fecha;
}
