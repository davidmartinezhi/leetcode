
Topology sort problems

Course Schedule (207)              detectar si hay ciclo
Course Schedule II (210)           devolver el orden, no solo si es posible
Alien Dictionary (269)             deducir el orden del alfabeto de palabras ordenadas
Minimum Height Trees (310)         variante, pelas hojas por capas
Sequence Reconstruction (444)      verificar si el orden topológico es único
Parallel Courses (1136)            mínimo de semestres, topological por niveles
Sort Items by Groups (1203)        topological sort anidado (grupos e items)

Hacer el clone graph con dfs ahora, y tambien hacerlo recursivo con dfs sin miedo cawn.

igual checae como detectar el cyclo para saber si tenemos o no una Directed Acyclic graph
    - I can do this with topological sort. 
    - literal es hacer un dfs pero marcando con 2 cuando estas en un mismo run
    - si ya regresaste del backtracking lo marcas como 1
    si estas procesando algo con 2 y visitas un 2, significa que hay un ciclo.
