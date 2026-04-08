# Reporte de Optimización y Sanitización

## 1. Comparación de Builds
Se compiló el proyecto utilizando distintas banderas de optimización para evaluar el comportamiento del ejecutable. Dado que nuestro algoritmo es $O(\log n)$, los tiempos de ejecución en casos pequeños son casi instantáneos en todos los builds, pero se notan diferencias en tamaño y estabilidad:

| Build | Comando | Tamaño Ejecutable (aprox) | Tiempo Total | Facilidad de Depuración |
| :--- | :--- | :--- | :--- | :--- |
| **Debug** | `-O0 -g` | Mayor tamaño | Base | Excelente (símbolos completos) |
| **Debug Opt.** | `-Og -g` | Intermedio | Ligeramente más rápido | Buena |
| **Release** | `-O2 -DNDEBUG` | Pequeño | Muy rápido | Difícil (código reordenado) |
| **Compacto** | `-Os` | El más pequeño | Rápido | Difícil |

**Observaciones:** Todos los builds mantuvieron la correctitud (pasaron los tests). No se arrojaron *warnings* relevantes al usar `-Wall -Wextra -Wpedantic`.

## 2. Reporte de Sanitizers (ASan y UBSan)
Se configuró el entorno (`CMakeLists.txt`) con las banderas `-fsanitize=address,undefined`. 
* **Observación:** Las pruebas locales se realizaron en Windows (MSYS2/UCRT64), entorno que no incluye `libasan` por defecto, por lo que se validó de forma teórica.

## 3. Benchmark y Microoptimización
Se comparó nuestra solución algorítmica frente a una búsqueda lineal ingenua $O(n)$.
* **Fuerza Bruta $O(n)$:** ~29.99 ms
* **Búsqueda Binaria $O(\log n)$:** ~0.0037 ms
* **Conclusión:** Una mejora en la elección del algoritmo tiene un impacto muchísimo más masivo (8000x más rápido) que cualquier microoptimización o cambio de bandera de compilación (ej. pasar de `-O0` a `-O2`).