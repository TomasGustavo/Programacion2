# Programación II
TP3 Pilas

## Indicaciones de compilación

Para compilar correctamente este proyecto, son requeridos los siguientes fuentes:
```
- TP3_main.c [codigo principal]
- TP3_pilas.c [codigo con las implementaciones de los ejercicios]
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

> La complejidad de la solución empleada es O(n^2) porque se utilizan 2 while, uno para desapilar y otro para volver a apilar la pila original como estaba y los 2 while dependen de la cantidad de elementos dentro de la pila.

---

> `Punto 4`

> La complejidad de la solución empleada es O(log(N)) .Como el número de llamadas recursivas será igual a la cantidad de veces que se puede dividir el número original entre la base hasta que el resultado sea menor que la base, el número de llamadas recursivas es proporcional a log(N) en la base dada.

---

> `Punto 5`

> La complejidad de la solución empleada es O(n^2) porque se utilizan 2 while, uno para desapilar y otro para volver a apilar la pila original como estaba y los 2 while dependen de la cantidad de elementos dentro de la pila.

---

> `Punto 6`

> La complejidad de la solución empleada en manera recursiva es O(n), ya que si o si va sacar todos los elementos de la pila para luego comparlos y volver a agregarlos. 
> En la implementacion iterativa es O(n^2) porque los 2 while utilizados para desapilar y apilar la pila van a depender de la cantidad de elementos que esta contenga.

---

> `Punto 7`

> La complejidad de la solución empleada es O(n^k) porque se utilizan varios while que dependen de la cantidad de elementos que posea la pila en momentos especificos del codigo mientras se ejecuta.

---

> `Punto 8`

> La complejidad de la solución empleada es O(n^k) porque se utilizan varios while que dependen de la cantidad de elementos que posea la pila en momentos especificos del codigo mientras se ejecuta.