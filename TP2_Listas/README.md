# Programación II
TP2 Listas

## Indicaciones de compilación

Para compilar correctamente este proyecto, son requeridos los siguientes fuentes:
```
- TP2_main.c [codigo principal]
- TP2_Listas.c [codigo con las implementaciones de los ejercicios]
- tipo_elemento
```
Dependiendo de la implementación que de desee ejecutar, es imprescindible utilizar solo uno de los siguientes fuentes:

```
- listas_apuntadores.c
- listas_arreglos.c
- listas_cursores.c
```

---
## Complejidad Algorítmica

> `Punto 4`

> La complejidad de la solución empleada es lineal, ya que en el peor de los casos se tiene que recorrer ambas listas por completo, lo que resultaría en una complejidad O(n), donde n es la cantidad de elementos agregados que posee cada lista.

---

> `Punto 6`

> La complejidad de la solución empleada es cuadrática, ya que hay dos estructuras iterativas anidadas, siendo ambas de complejidad O(n), por lo tanto, O(n * n) = O(n^2).