Integrantes:
- Remon Flores, Juaquin Estefano
- Puente Jara, Virginia Norma
- Callinapa Chunga, Johan Fabian

## Proof of Work (PoW)
En este proyecto se implementó una 'prueba de trabajo'. Esta debe demostrar que ha gastado una gran cantidad de poder computacional para validar un bloque. Este proceso se llama minería. El hecho de que se haya hecho algo de trabajo para crear un bloque proporciona valor al sistema. En el caso de Bitcoin, por ejemplo, se requiere que el hash de un bloque comience con una cierta cantidad de ceros utilizando la función SHA-256. Ya que no se puede influir en una función hash, el sistema tiene que probar varias combinaciones para llegar a un valor hash que comience con ese número de ceros. Este es el rompecabezas que los mineros deben resolver y que requiere mucha potencia informática. El número de ceros define la dificultad de la función.


Mediante un while loop se calcula el hash con el algoritmo SHA-256, si el hash es válido, el loop terminará, luego se retorna el hash obtenido:

```cpp
template<typename T>
std::string Block<T>::_calculate_hash() {
    SHA256 sha256;
    std::string t_hash = _hash_block();
    this->nonce = 0;
    do {
        this->nonce++;
        sha256(t_hash + std::to_string(this->nonce));
    } while (!_verify_hash(sha256.getHash()));
    return sha256.getHash();
}
```
En este caso, un hash es válido si sus tres primeros caracteres son iguales a cero:

```cpp
template<typename T>
bool Block<T>::_verify_hash(const std::string &hash_v) {
    return (hash_v.at(0) == '0' && hash_v.at(1) == '0' && hash_v.at(2) == '0');
}
```

Dado que para crear un hash se toman parámetros del bloque y estos no deben cambiar, el hash obtenido sería siempre el mismo. Es por ello que la función hash toma un parámetro adicional llamado nonce.

Por último, al crear un nuevo bloque, se calcula el hash mediante la primera función presentada en esta sección.

```cpp
template<typename T>
Block<T>::Block(const int &id, const int &size, T *registers, std::string &parent_hash): parent_hash(parent_hash) {
    this->size = size;
    this->id = id;
    this->registers = registers;
    this->hash = _calculate_hash();
}
```


 