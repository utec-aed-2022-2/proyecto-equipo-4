#include <iostream>
#include "Block.h"
#include "sha256.h"

void test_block(){
    SHA256 sha256;
    sha256("0");
    std::string parent0 = sha256.getHash();
    std::string regis[] = {"juaquin", "remon", "flores"};
    Block<std::string> b(1, 3, regis, parent0);
    std::cout << b.get_id() << std::endl;
    std::cout << b.get_size() << std::endl;
    std::cout << b.get_hash() << std::endl;
}

int main()
{
    test_block();
    return 0;
}