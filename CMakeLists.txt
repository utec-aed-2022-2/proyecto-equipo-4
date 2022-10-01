cmake_minimum_required(VERSION 3.23)
project(proyecto_equipo_4)

set(CMAKE_CXX_STANDARD 17)
add_executable(proyecto_equipo_4 main.cpp sha256.cpp sha256.h Block.cpp Block.h BlockChain.h BlockChain.cpp List.h ForwardList.h ChainHash.cpp ChainHash.h)
