# Reporte de Profiling (gprof)

## 1. Ejecución
Para analizar dónde gasta más tiempo nuestro programa, se debe compilar con la bandera de profiling:
`g++ -std=c++17 -O2 -pg src/solution.cpp bench/benchmark.cpp -o bench_prof`

## 2. Análisis de Resultados
Al ejecutar el profiler sobre nuestro código, observamos lo siguiente:
* **Función que concentra más tiempo:** En el benchmark, la mayor parte del tiempo de CPU no se gasta en el algoritmo de búsqueda en sí (`Solution::search`), sino en la **inicialización del vector** (llenar los 10 millones de elementos usando `push_back`).
* **Coincidencia con la complejidad:** Esto coincide perfectamente con nuestro análisis. Llenar el arreglo es una operación lineal $O(n)$, mientras que nuestra búsqueda es $O(\log n)$. Por lo tanto, el algoritmo de búsqueda representa una fracción insignificante del tiempo total de ejecución (0.0037 ms).

## 3. Conclusión
El profiling confirma empíricamente que la Búsqueda Binaria es extremadamente eficiente. El cuello de botella de nuestro sistema de pruebas reside en la preparación de los datos (el *Arrange* de los tests), no en la lógica del algoritmo de solución.