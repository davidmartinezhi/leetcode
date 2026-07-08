#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        info
            input
                - m x n matrix int
                    - int in each row are sorted in asc order. left to right
                    - int in each col are sorted in asc order. top to bottom
                - int target
                
                
            
            output
                - true if target exists, else false
            
            
            constraints
                - range of sizes m and n can have? [1, 300]
                - range of values each cell num can have? [-10^9, 10^9]
                - range of values target can have? [-10^9, 10^9]
            
        example
        
        Input: matrix = 
                    [
                    [1,4,7,11,15],
                    [2,5,8,12,19],
                    [3,6,9,16,22],
                    [10,13,14,17,24],
                    [18,21,23,26,30]
                    ], 
                    target = 5
                    
        brute force
            traverse m x n until we find target
            runtime: o(mxn)
            memory: o(1)
        
        optimize
            rows and cols are sorted, this gives oportunity to a binary search like solutions
            
            runtime: o(log(m)+log(n))?
            
            i could do a binary search on each row. making this runtime: o(rowsxlog(cols))
            
        walkthrough
            17 min 5 sec left
            
            im sure i have to do binary search first to see on wich row the value is in
            then i do another binary search to see if the value is in that row
            
            runtime: o(log(m)+log(n))
            memory: o(1)
            
            well this may not be possible
            okay log(n*m) may be possible
            
            is a 2d binary search basically
        

            Input: matrix = 
                        [
                        [1,4,7,11,15], t
                        [2,5,8,12,19],
                        [3,6,9,16,22],
                        [10,13,14,17,24],
                        [18,21,23,26,30] b
                         s            e
                        ], 
                        target = 5
                        
                        b = 4
                        t = 0
                        
                        s = 0
                        e = 4
                        
                        mh = 0 + (4-0)/2 = 2
                        mv = 2
                        
                        matrix[mh][mv] = 9
                        
                        we can get rid of all the rest
                        
                        target is less
                        
                        b and e = mh and mv
                        
                        
                        b = 2
                        t = 0
                        
                        s = 0
                        e = 2
                        
                        mh = 0 + (2-0)/2 = 1
                        mv = 1  
                        matrix[mh][mv] = 5
                        
                        return true
                        
                        what if we were looking for 8?
                        then only
                        target is greater
                        
                        b = 2
                        t = 2
                        
                        s = 2
                        e = 2   
                        
                        i should use a mark or pivot to know if i should update horizontal or vertical
                        edge
                        
                        7 min left
                        
                        if end is less than target, we know we have to 
                        
                        
                        this is an interesting problem
                        
                        does this need backtracking of some sort?
                        
                        time ran out
                        
        */
        
        int rows = matrix.size(), cols = matrix[0].size();
        int r = 0, c = cols - 1;        // esquina superior derecha, mayor de su fila, menor col

        while(r < rows && c >= 0){
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) c--;   // el valor es muy grande, elimina esta columna
            else r++;                               // el valor es muy chico, elimina esta fila
        }
        return false;
    }
};

/*
runtime: o(n+m)
memory: o(1)

this is the right question to ask:  
    - "¿existe alguna posición en la matriz desde donde cada comparación me deje eliminar algo con seguridad?".
    - eso es lo que asumí con el binary search, pero no podía eliminar una sección de la matriz con seguridad
        al seguir ese approach. 

Entonces el punto que si es una buena guía para saber desde donde es que podemos comenzar
a descartar es o arriba a la derecha o abajo hasta la izquierda. dodne es el mayor horizontal
o el mayor vertical.

En nuestro caso donde comenzamos hasta arriba a la derecha:
    - si el valor es mayor que el target, reducimos la columna.
    - si el valor ahora es menor que el target, aumentamos la row.

    esto nos alinea con una columna donde se encuentra el valor verticalmente
    y luego nos alinea verticalmente


    Esquina superior izquierda (matrix[0][0]):
   es el MÍNIMO de su fila Y de su columna
   todo a su derecha y abajo es mayor
   si es menor que target, no puedes descartar ni fila ni columna con certeza
   → no sirve

Esquina inferior derecha (matrix[m-1][n-1]):
   es el MÁXIMO de su fila Y de su columna
   mismo problema, no descarta limpio
   → no sirve

Esquina superior derecha (matrix[0][n-1]):
   es el MÁXIMO de su fila, MÍNIMO de su columna
   ¡esto sí sirve! (ver paso 4)

Esquina inferior izquierda (matrix[m-1][0]):
   es el MÍNIMO de su fila, MÁXIMO de su columna
   también sirve (simétrico)


si matrix[esquina] > target:
   como es el MENOR de su columna, todos los de abajo son aún mayores
   → el target no puede estar en esta columna → elimínala (mueve a la izquierda)

si matrix[esquina] < target:
   como es el MAYOR de su fila, todos los de la izquierda son aún menores
   → el target no puede estar en esta fila → elimínala (mueve abajo)

literal estos problemas es saber en distintos casos cuales son los posibles casos
y que podemos asumir de la informacion una vez que tomamos un paso o no


Cuando notaste que el binary search 2D no descartaba limpio (que fue exactamente donde te trabaste), esa era la señal para preguntarte: "¿desde qué OTRO punto sí puedo descartar?". En vez de forzar el centro, explorar las esquinas te habría llevado a notar que la superior derecha tiene la propiedad de "máximo de fila, mínimo de columna", que es justo la que deja eliminar una línea por paso.
La pista que tenías: en tu walkthrough escribiste "i should use a mark or pivot to know if I should update horizontal or vertical edge". Estabas cerca, intuías que necesitabas un punto de referencia para decidir qué dimensión descartar. La esquina superior derecha ES ese punto: te dice si descartar columna (horizontal) o fila (vertical) según la comparación

okay, si hace todo el sentido del mundo. si la esquina es mayor, todos los demas numeros
de esa col son mayores entonces ni al caso seguir checandolos. entonces nos movemos a la izquierda
luego si llegamos a un punto donde es menor. sabemos que todo lo que esta en esa row ya es menor
entonces aumentamos la row para descartar.  entonces donde estamos ahora es. todo a la derecha es mayor
y todo arriba es menor. y etsmoa buscando

cuando el binary search central no descarta con certeza, busca un punto con propiedades asimétricas (extremo en una dirección, opuesto en la otra) desde donde cada comparación elimine una porción completa
*/
