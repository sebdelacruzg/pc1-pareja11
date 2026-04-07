## Actividad 1- CC232

### Integrantes
- De la Cruz Guanilo Alfredo Sebastian

#### BLOQUE 1

1. Diferencia entre problema, algoritmo, ADT e implementación

- **Problema:**  
  Qué se quiere resolver (ej. ordenar datos).

- **Algoritmo:**  
  Secuencia de pasos matemáticos o lógicos para resolver el problema.

- **ADT (Abstract Data Type):**  
  El contrato o interfaz (operaciones permitidas), sin importar cómo se almacenan los datos.

- **Implementación:**  
  El código real (estructuras de datos en memoria, lenguaje específico).


2. En `bubble_sort.cpp`, ¿qué observable conecta correctitud y costo?

El observable clave es:

- `lastSwapIndex`
- `changed`

**Conexión:**

La correctitud matemática indica que todo lo que está a la derecha del último intercambio ya está ordenado.  
La versión optimizada aprovecha esto para reducir el costo, acortando el rango de iteración en cada pasada.

- Mejor caso: $O(n)$ cuando la lista está casi ordenada.


3. En `power.cpp`, ¿por qué mejora frente a la versión ingenua?

Mejora el rendimiento al pasar de:

- Complejidad lineal: $O(n)$  
- A complejidad logarítmica: $O(\log n)$  

Esto se logra mediante **exponenciación binaria** (técnica de divide y vencerás).


4. En `fibonacci.cpp`, ¿por qué puede ser correcta pero mala en la práctica?

La versión recursiva:

- Es **correcta matemáticamente**
- Pero **ineficiente**

Porque recalcula subproblemas repetidamente:

- Complejidad: $O(2^n)$ (exponencial)

Las versiones iterativas:

- Guardan estado previo
- Complejidad: $O(n)$  
- Son viables en la práctica


5. En `count_ones.cpp`, ¿por qué el tamaño de entrada no coincide con el valor numérico?

El tamaño de entrada ($N$) no es el valor del número, sino:

- La cantidad de **bits necesarios para representarlo**

Ejemplo:

- Un número grande puede representarse en 32 bits → tamaño fijo

Por eso:

- Algunos algoritmos dependen de los bits (no del valor)
- Complejidad ≈ $O(1)$ o proporcional al número de bits encendidos


6. En `demo_adt_secuencia.cpp`, ¿por qué la misma interfaz permite distintas representaciones?

Gracias a la **abstracción (polimorfismo)**. El código cliente interactúa solo con un "contrato" estándar (add, remove, get). Esto permite que internamente una clase use un arreglo estático de tamaño fijo y otra use un arreglo dinámico (std::vector), sin que el cliente note la diferencia.

#### BLOQUE 2
Tabla 

| Archivo                | Salida observable        | Idea algorítmica                                           | Argumento de costo                                      |
|-----------------------|--------------------------|------------------------------------------------------------|----------------------------------------------------------|
| `demo_bubblesort.cpp` | `lastSwapIndex`          | Omitir la porción del arreglo que ya está ordenada         | Baja de $O(n^2)$ a $O(n)$ si hay orden parcial           |
| `demo_power.cpp`      | `powerBF == power`       | Exponenciación binaria (Divide y Vencerás)                 | Reduce multiplicaciones de $O(n)$ a $O(\log n)$          |
| `demo_fibonacci.cpp`  | Uso de variable `prev`   | Memorizar cálculos previos para evitar recomputación       | Baja de $O(2^n)$ a $O(n)$                                |
| `demo_countones.cpp`  | Binario con `bitset<16>` | Operar sobre bits activos o usar máscaras                  | Costo fijo por bits: $O(1)$                              |

Respuestas
1. En `demo_bubblesort.cpp`, ¿qué salida sirve para defender costo y no solo resultado?

El índice lastSwapIndex demuestra empíricamente que el algoritmo detecta la porción ya ordenada y no la vuelve a procesar, probando la reducción del costo a O(n).

2. En `demo_power.cpp`, ¿qué comparación concreta muestra una mejora algorítmica?

Imprimir ambas funciones confirma que producen el mismo resultado, pero la versión optimizada lo logra con saltos exponenciales, evidenciando la caída del costo de O(n) a O(logn).

3. `En demo_fibonacci.cpp`, ¿qué crecimiento se vuelve defendible?


El arrastre del estado (prev) demuestra cómo evitar el recálculo masivo de subproblemas, convirtiendo una explosión exponencial inútil O(2^n) en una ejecución lineal O(n) defendible en la práctica.

4. En `demo_countones.cpp`, ¿qué ejemplo ayuda más a distinguir valor numérico de tamaño en bits?

El uso de std::bitset hace visualmente obvio que el algoritmo iterará como máximo la cantidad de bits del tipo de dato (ej. 32 veces), operando en tiempo O(1), sin importar si el número es 10 o 1,000,000.













#### BLOQUE 4

 1. ¿Qué diferencia observable deja demo_const_refs.cpp entre lectura, modificación y copia?

La diferencia es cómo las distintas funciones afectan (o no) al espacio de memoria del vector original:

- **Lectura (sum_readonly):**  
  No hay cambios en el vector original. La función solo lee los datos para calcular la suma.  
  El vector sigue siendo: `{1, 2, 3}`

- **Modificación (append_in_place):**  
  El vector original sufre un cambio directo e irreversible.  
  Al pasarse como referencia mutable (`std::vector<int>&`), se modifica el mismo bloque de memoria.  
  El vector pasa a ser: `{1, 2, 3, 4}`

- **Copia (appended_copy):**  
  El vector original permanece intacto (`{1, 2, 3, 4}`).  
  La función crea y devuelve una nueva lista independiente en otro espacio de memoria con el `99` añadido.  
  Cambios en `copied` no afectan a `original`.


 2. En bench_vector_growth.cpp, ¿qué cambia con reserve?

Lo que cambia es la gestión y reasignación de memoria dinámica:

- **Sin `reserve`:**  
  Más lento. El vector se queda sin espacio y debe reasignar memoria múltiples veces, copiando los datos repetidamente.

- **Con `reserve`:**  
  Más rápido. Se asigna toda la memoria necesaria desde el inicio, evitando realocaciones costosas.


 3. En bench_vector_ops.cpp, ¿por qué push_back, insert(begin()) e insert(middle) no cuestan lo mismo?

Porque `std::vector` almacena elementos de forma contigua en memoria:

- **push_back (al final):**  
  Muy rápido. Usa el siguiente espacio disponible.

- **insert (al medio):**  
  Lento. Debe mover aproximadamente la mitad de los elementos.

- **insert (al inicio):**  
  El más lento. Debe mover todos los elementos en cada inserción.


 4. En bench_cache_effects.cpp, ¿qué intuición deja sobre localidad de memoria?

Demuestra que el rendimiento depende de cómo la CPU interactúa con la caché:

- **Vector secuencial (Rápido):**  
  Datos contiguos → mejor uso de caché.

- **Lista enlazada (Lenta):**  
  Datos dispersos → mala predicción de caché.

- **Vector con acceso aleatorio (Muy lento):**  
  Aunque contiguo, los accesos caóticos generan fallos de caché (*cache misses*).


#### BLOQUE 5

 1. Según Ejercicios0.md, ¿cuál es el orden correcto antes de optimizar?

1. Elegir el algoritmo correcto.  
2. Verificar la correctitud del código.  
3. Medir rendimiento.  
4. Aplicar optimizaciones de compilador (`-O2`, `-O3`, etc.).


 2. ¿Qué quiere mostrar stl_optimizacion_demostracion.cpp?

Que el diseño algorítmico supera al microajuste del compilador:

- **reserve:** Evita realocaciones dinámicas costosas.  
- **nth_element:** Encuentra el k-ésimo elemento en `O(n)` (mejor que `O(n log n)` de `sort`).  
- **partial_sort:** Obtiene el Top-K sin ordenar todo.  
- **lower_bound:** Búsqueda binaria en `O(log n)` con alta eficiencia de caché.


 3. ¿Qué tipo de evidencia puede producir resolver_ejercicios0_v4.2.sh?

- **Reporte final:** Markdown con tablas comparativas.  
- **Métricas:** Tiempos de ejecución y tamaño de binarios.  
- **Trazabilidad:** Logs de compilación, ejecución y warnings.  
- **Artefactos avanzados:** Coverage (`gcov`) y profiling (`gprof`).


 4. ¿Qué limitaciones de entorno menciona INSTRUCCIONES_Ejercicios0_v4.2.md?

Entornos como Git Bash o MSYS2 presentan limitaciones:

- Fallan al enlazar *sanitizers*.  
- Problemas con `gcov` y `gprof`.  

Se recomienda:

- Usar **UCRT64** para compilaciones limpias.  
- O migrar a **WSL/Linux nativo** para herramientas avanzadas.


 5. ¿Por qué esta parte no reemplaza la discusión de correctitud de Semana 1?

- **Semana 0 (Herramientas):**  
  Correctitud mecánica/dinámica.  
  Usa herramientas (sanitizers, coverage) para detectar errores técnicos.

- **Semana 1 (Teoría):**  
  Correctitud lógica/formal.  
  Requiere razonamiento matemático (invariantes, pruebas, casos).  

> Las herramientas detectan errores, pero no prueban que un algoritmo sea correcto.