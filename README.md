# PC1 - Search in Rotated Sorted Array (Pareja 11)

## 1. Información General
* **Integrantes:**
    * De la Cruz Guanilo Alfredo Sebastian
    * Sanchez Cirilo Luis David
* **Problema Asignado:** Search in Rotated Sorted Array.
* **Enlace a LeetCode:** [LeetCode 33](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## 2. Especificación del Problema
* **Descripción:** Encontrar el índice de un valor específico (`target`) dentro de un arreglo de enteros con valores únicos que fue ordenado ascendentemente y luego rotado en un punto desconocido.
* **Entrada:** Un arreglo `std::vector<int> nums` y un entero `target`.
* **Salida:** El índice del `target` (tipo `int`) o -1 si no existe.
* **Tamaño de entrada relevante:** n, definido como la cantidad total de elementos en `nums`.

## 3. Análisis Conceptual
* **Descripción:** Implementamos una Búsqueda Binaria modificada. En cada iteración, calculamos mid y determinamos cuál mitad ([left, mid] o [mid, right]) está estrictamente ordenada. Esto permite decidir si el target está en esa mitad mediante comparaciones directas de límites, descartando el 50% del arreglo en cada paso.
* **Justificación de Determinismo y Factibilidad:** El algoritmo es determinista ya que no utiliza elementos aleatorios; ante la misma entrada, la secuencia de pasos y la salida son idénticas. Es factible porque su costo de memoria es mínimo y su tiempo de ejecución es casi instantáneo incluso para $n$ muy grandes.
* **Argumento de Finitud:** En cada iteración del bucle while (left <= right), la distancia entre los índices se reduce a la mitad. Dado que los índices son enteros, la ventana de búsqueda colapsa inevitablemente, garantizando que el bucle termine.
* **Argumento de Correctitud:**El algoritmo es correcto porque en cada paso evaluamos si el target puede estar en la mitad ordenada. Si no lo está, por eliminación lógica, debe estar en la otra mitad (o no estar en el arreglo), asegurando que nunca descartamos la sección que contiene la solución.
* **Invariante:** "Si el elemento buscado existe, su índice se encuentra dentro del rango [left, right]".
* **Monotonicidad:**Aunque el arreglo no es monótono globalmente debido a la rotación, el algoritmo explota la monotonicidad local de las sub-partes para aplicar la lógica de búsqueda binaria.

## 4. Complejidades y Jerarquía
* **Complejidad Temporal:** 
    *Peor y Promedio: $O(\log n)$ (divisiones sucesivas por 2).
    *Mejor caso: $O(1)$ (si el target está en el primer mid calculado).
* **Complejidad Espacial:** $O(1)$ (se ejecuta in-place con variables auxiliares constantes).
* **Ubicación en la Jerarquía:** Pertenece a la clase Logarítmica, la cual se sitúa por debajo de la Lineal y por encima de la Constante.
* **Alternativa Ingenua:** Búsqueda lineal $O(n)$, la cual es ineficiente para búsquedas repetidas o volúmenes masivos de datos.

## 5. Consideraciones de Ingeniería
* **Robustez, Degeneración y Reutilización:** Se manejan casos de arreglos vacíos, de un solo elemento y no rotados. La lógica está encapsulada en la clase Solution para facilitar su reutilización en diferentes interfaces (tests y benchmark).
* **Instrucciones de Compilación y Ejecución:** 

```bash
# Compilar (usando g++)
g++ -std=c++17 -O2 -I src tests/tests.cpp src/solution.cpp -o test_solution
g++ -std=c++17 -O2 -I src bench/benchmark.cpp src/solution.cpp -o benchmark_app

# Ejecutar Tests
./test_solution

# Ejecutar Benchmark
./benchmark_app
```


## 6. Bloque Experimental y Reportes
### Tabla de Builds
| Build      | Flag | Tamaño | Tiempo (O log n) |
| :--------- | :--- | :----- | :--------------- |
| Depuración | -O0  | 216 KB | 0.172 s          |
| Release    | -O2  | 140 KB | 0.172 s          |
| Compacto   | -Os  | 144 KB | 0.305 s          |

### Micro-benchmark
Se comparó $O(\log n)$ vs $O(n)$ con un arreglo de 10,000,000 de elementos. 
* **Binaria:** 0.001 ms
* **Lineal:** 6.397 ms
* **Mejora:** 6397x más rápido.

* **Discusión sobre Microoptimización vs Algoritmo:** El cambio de algoritmo ($O(n) \to O(\log n)$) generó una mejora de ~6400x, mientras que el cambio de flags de compilación tuvo un impacto casi nulo. Esto demuestra que la complejidad asintótica es el factor determinante.
* **Observaciones de Sanitizers:** Se intentó usar ASan/UBSan. Se documenta que en entornos Windows UCRT64 no se encuentran las librerías nativas, por lo que se validó la robustez mediante pruebas unitarias exhaustivas.   
* **Resumen de Cobertura y Profiling:** Se logró un 100% de cobertura en la lógica de búsqueda. El profiling mostró que el tiempo de CPU se gasta mayormente en la creación de datos, no en la búsqueda.

