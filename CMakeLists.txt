cmake_minimum_required(VERSION 3.22.3)
project(proyecto_equipo_4)

set(CMAKE_CXX_STANDARD 17)
add_executable(proyecto_equipo_4 main.cpp sha256.cpp sha256.h Block.h BlockChain.h BlockChain.cpp List.h ForwardList.h ChainHash.h)
