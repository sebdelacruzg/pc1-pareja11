## Actividad 1- CC232

### Integrantes
- De la Cruz Guanilo Alfredo Sebastian

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