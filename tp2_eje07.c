Qué es la moda

Moda: el/los valor(es) que más veces aparecen en el conjunto.

Antes de empezar, decidí:

¿Qué hacés si hay empate? (¿devolvés todos los valores empatados o el primero que aparezca?)

¿Qué hacés si el conjunto está vacío? (normalmente: avisar “no hay moda”)

Método A (sin estructuras, solo comparaciones) — O(n²)

Sirve si te limitan a usar variables simples.

Idea: para cada valor, contás cuántas veces aparece recorriendo todo el conjunto; vas guardando el mejor.

Pasos:

Tené una variable para el máximo conteo encontrado hasta ahora (por ejemplo, “max_repeticiones”) y otra para la moda actual (“moda_actual”). Iniciálas con 0 y “sin valor”.

Recorre el conjunto con un índice i.

Tomá el valor en la posición i (llamalo v).

Poné un contador local en 0.

Volvé a recorrer todo el conjunto con un índice j y sumá 1 cada vez que encuentres v.

Al terminar ese conteo:

Si el contador local > max_repeticiones:

Actualizá max_repeticiones con ese contador.

Actualizá moda_actual con v.

(Si querés permitir empates y devolver todas las modas, guardá también una lista de “modas” y manejá:

Si contador local > max_repeticiones: vaciás la lista y metés v.

Si contador local == max_repeticiones: agregás v si no estaba.)

Repetí para todos los i.

Resultado: moda_actual y max_repeticiones (o el conjunto de modas si manejaste empates).

Ventaja: no requiere estructuras adicionales.
Costo: es más lento para conjuntos grandes (doble recorrido).
----------------------------------------------------------------------------------------------------
Método B (ordenando y contando “rachas”) — O(n log n)

Muy práctico y sin estructuras de conteo.

Idea: Si ordenás los valores, los iguales quedan juntos. Luego hacés una pasada contando la longitud de cada “racha” de iguales.

Pasos:

Ordená el conjunto.

Inicializá:

valor_en_curso = primer valor.

conteo_en_curso = 1.

max_repeticiones = 1.

moda_actual = primer valor.

Recorre desde el segundo elemento hasta el final:

Si el valor actual es igual a valor_en_curso: incrementá conteo_en_curso.

Si es distinto:

Compará conteo_en_curso con max_repeticiones:

Si es mayor, actualizá max_repeticiones y moda_actual (o tu lista de modas si permitís empates).

Si es igual y manejás empates, agregalo a la lista.

Reiniciá valor_en_curso al nuevo valor y conteo_en_curso = 1.

Al terminar el recorrido, no olvides comparar la última racha con max_repeticiones.

Resultado: moda_actual y max_repeticiones (o conjunto de modas).

Ventaja: una sola pasada fuerte tras ordenar.
Costo: dependés del ordenamiento (O(n log n)).

Casos especiales a contemplar

Conjunto vacío: devolvés “no hay datos / no hay moda”.

Todos distintos: la moda podría ser “no definida” o cualquiera con frecuencia 1; definilo.

Empates: decidí si devolvés todas las modas o solo la primera que alcanzó el máximo.

Tipos de datos: funciona igual para números, textos, etc. (la igualdad debe estar bien definida).

Ejemplo mental (Método B con ordenación)

Conjunto: [2, 4, 4, 6, 6, 6, 7]

Ordenado: igual.

Rachas:

2 → 1

4 → 2

6 → 3 ← máxima

7 → 1

Moda = 6, frecuencia = 3.
