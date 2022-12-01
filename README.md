Integrantes:
- Remon Flores, Juaquin Estefano
- Puente Jara, Virginia Norma
- Callinapa Chunga, Johan Fabian
## BlockChain
La estructura de datos utilizada para el manejo del blockchain es un table hash, donde el key es el id del bloque y el value es la clase template Block como puntero. Además para la construcción del mismo se están usando las clases template ChainHash y ForwardList implementadas en el curso. Asimismo, para el blockchain se tienen operaciones como insertRegister, searchRegister y updateRegister.

## Hashing
Se utilizó el algoritmo SHA o Secure Hash Algorithm, este tiene 4 variantes según el número de bits, en este caso, más específicamente se utilizó SHA-256. Este es uno de los algoritmos más usados por su equilibrio entre seguridad y coste computacional de generación, además de tener una alta resistencia a la colisión. Asimismo, tiene como característica principal que el resultado del hash siempre es una cadena de 64 de letras y números (con una codificación de 256 bits, 32 bytes).

Para obtener el hash de cada bloque se aplica el hash en la concatenación del id del bloque convertido a string, el hash del padre del bloque y el hash de todos los registros dentro del bloque.

```cpp
template<typename T>
std::string Block<T>::_hash_block() {
    SHA256 sha256;
    return sha256(std::to_string(id) + parent_hash + _hash_registers());
}
```

Este último se halla mediante la suma de todos los registros, dependiendo del tipo de dato del registro se tendrá que sobrecargar el operador de suma para que al final esta nos de un string.

```cpp
template<typename T>
std::string Block<T>::_hash_registers() {
    SHA256 sha256;
    std::string text = "";
    for (int i = 0; i < size; i++) {
        text = text + registers[i];
    }
    sha256(text);
    return sha256.getHash();
}
```

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
## Estructuras de Datos
Se utilizaron las siguientes estructuras de datos para organizar la informacion de los bloques de una manera eficiente. Algunos tipos
de estructuras de datos son mas convenientes para realizar ciertas tareas:
### Árbol AVL
El árbol AVL añade una condición de equilibrio de modo que la búsqueda sea amortizada. Este tipo de estructura es usualmente utilizado
para funciones como inserción, búsqueda y eliminación eficiente. 
### Árbol B
El árbol B también es una estructura balanceada. Se utiliza para la búsqueda por rango en una complejidad O(n). A diferencia de otras
estructuras el árbol B hace inserciones y eliminaciones en tiempo logaritmico amortizado. Sin embargo, pueden desperdiciar memoria, ya que algunos nodos no permanecen totalmente ocupados.
### Cadena Hash
La cadena hash es un método para producir muchas claves de un solo uso a partir de una sola clave. Se puede aplicar una función hash sucesivamente a datos adicionales para registrar la cronología de la existencia otros datos. Como en este caso, las funciones hash
son ampliamente utilizadas en la tecnologia blockchain, el bitcoin es ejemplo más conocido.


## Métodos de Blockchain



### Get in range:
Utiliza la estructura del Árbol B para la obtención de datos dentro un cierto rango, si no utiliza dicha estructura. Realiza una búsqueda lineal. En ambos casos la complejidad algoritmica es O(n). A pesar de ello, el árbol B ofrece es mas eficiente en casos 
prácticos de costo amortizado. 

```cpp
BlockChain<T>::getInRange()
```
### Get min:
Halla el dato de menor valor. Utiliza el índice MinHeap. En el caso de la operación inserción la complejidad logaritmica es de 
O(log N). El heap es creado en una complejidad lineal O(n).
```cpp
BlockChain<T>::getMin()
```
## Get max:
De manera similar, get max utiliza el índice MaxHeap.
```cpp
BlockChain<T>::getMax()
```
# Print
Para mostrar el contenido de la blockchain se llama obtiene el valor de la cadena Hash, y se imprime por bloque, siempre y cuando
halla un id para el siguiente. 
```cpp
BlockChain<T>::print()
```
# Start with
Muestra el valor del tipo de atributo requerido que empieza con un string dado. Para ello utiliza el índice Trie. Si no se requiere hace la búsqueda de forma lineal.

```cpp
BlockChain<T>::start_with()
```

 