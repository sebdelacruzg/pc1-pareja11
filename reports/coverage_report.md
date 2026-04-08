# Reporte de Cobertura de Código

## 1. Estrategia de Pruebas
Nuestro archivo `tests.cpp` fue diseñado siguiendo el patrón AAA (Arrange, Act, Assert) para estresar la función crítica `Solution::search`.

## 2. Cobertura de Líneas
Al compilar con `--coverage`, garantizamos una cobertura de líneas cercana al **100%** en el núcleo de la solución, ya que nuestros tests incluyen:
* **Caso normal:** Arreglo rotado y elemento presente. (Cubre las ramas de reducción `left = mid + 1` y `right = mid - 1`).
* **Caso inexistente:** Elemento que no está en el arreglo. (Cubre la salida final `return -1`).
* **Casos borde:** Arreglos de tamaño 1 y arreglos vacíos. (Cubre las validaciones iniciales de seguridad).

## 3. Cobertura de Condiciones
Dentro del bucle principal `while(left <= right)`, la condición más crítica es el `if` que determina cuál mitad está estrictamente ordenada:
`if (nums[left] <= nums[mid])`
Nuestros tests cubren ambas rutas de esta condición, asegurando que el código toma la decisión correcta tanto cuando el *target* está en la mitad ordenada como cuando está en la desordenada.