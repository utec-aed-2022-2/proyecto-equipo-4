cmake_minimum_required(VERSION 3.21.1)
project(proyecto_equipo_4)

set(CMAKE_CXX_STANDARD 17)
add_executable(proyecto_equipo_4 main.cpp sha256.cpp sha256.h Block.h BlockChain.h ForwardList/List.h ForwardList/ForwardList.h ChainHash.h Register.cpp Register.h Index.h Vector/CircularArray.h AVL/avl.h AVL/node.h Vector/queue.h)
