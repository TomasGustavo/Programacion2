# Programación II
TP3 Pilas

## Indicaciones de compilación

Para compilar correctamente este proyecto, son requeridos los siguientes fuentes:
```
- TP3_main.c [código principal]
- TP3_pilas.c [código con las implementaciones de los ejercicios]
- tipo_elemento
```
Dependiendo de la implementación que se desee ejecutar, es imprescindible utilizar solo uno de los siguientes fuentes:

```
- pilas_apuntadores.c
- pilas_arreglos.c
```

---
## Complejidad Algorítmica

> `Punto 3`

> La complejidad de la solución empleada es O(n) porque hay varios ciclos que dependen de la cantidad de elementos de la pila, pero no se encuentran anidados.

---

> `Punto 4`

> La complejidad de la solución empleada es O(n), ya que se utiliza la pila para almacenar el resultado de la conversion, sin haber ciclos anidados que aumenten la complejidad del ejercicio.

---

> `Punto 5`

> La complejidad de la solución empleada es O(n) porque hay varios ciclos que dependen de la cantidad de elementos de la pila, pero no se encuentran anidados.

---

> `Punto 6`

> La complejidad de la solución empleada tanto de manera recursiva como iterativa es O(n), ya que si o si en ambas implementaciones, va sacar todos los elementos de la pila para luego compararlos y volver a agregarlos. 

---

> `Punto 7`

> La complejidad de la solución empleada es O(n^2) porque se utilizan dos ciclos anidados para recorrer ambas pilas, lo que en el peor de los casos, la longitud de ambas seria igual.

---

> `Punto 8`

> La complejidad de la solución empleada es O(n^2) porque a pesar que hay varios ciclos que dependen de la cantidad de elementos que posea la pila, solo hay un nivel de anidación, lo que se volvería critico en el peor de los casos, siendo complejidad cuadrática.