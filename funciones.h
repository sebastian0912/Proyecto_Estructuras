// Segunda Entrega = funciones principales
// 0. Descripcion secuencia FASTA = esta es la forma como funciona las secuencias FASTA
//Debe notarse que siempre empieza con el caracter ’>’ y justo después se presenta una cadena no vacía que
//describe la secuencia. Las siguientes líneas (hasta la siguiente secuencia o hasta el ﬁnal del archivo) contienen
//los datos que describen el código genético. Estas líneas están justiﬁcadas y todas tienen un ancho constante
//(que depende de cada secuencia, es decir, no siempre el ancho es el mismo para todas las secuencias), con la
//posible excepción de la última línea.


// 1. cargar nombre_archivo (Quien lo hace) =   Carga en memoria los datos contenidos en el archivo identiﬁcado por nombre_archivo ,
//                              es decir, utiliza adecuadamente las estructuras lineales para cargar la información de los genomas en
//                              memoria. Si dentro de la misma sesión de trabajo ya se han cargado otros archivos de secuencias (usando
//                              el comando cargar), la información debe sobreescribirse en memoria, es decir, no se deben combinar
//                              informaciones de secuencias de diferentes archivos.

// salida en pantalla:
//(Archivo vacío) nombre_archivo no contiene ninguna secuencia.
//(Archivo erróneo) nombre_archivo no se encuentra o no puede leerse.
//(Una sola secuencia) 1 secuencia cargada correctamente desde nombre_archivo .
//(Varias secuencias) n secuencias cargadas correctamente desde nombre_archivo .

// 2. conteo (Quien lo hace)=  Imprime por pantalla la cantidad de secuencias cargadas en memoria. Sólo requiere indicar el número de secuencias, no sus nombres ni su contenido.

// salida en pantalla:
//              (No hay secuencias cargadas) No hay secuencias cargadas en memoria.
//              (Una sola secuencia)1 secuencia en memoria.
//              (Varias secuencias)n secuencias en memoria.

// 3. listar_secuencias (Quien lo hace) =   imprime en n líneas (una para secuencia) la información básica (cantidad de bases diferentes) de cada secuencia.
//                          Si la secuencia es completa(i.e.no tiene el código ’-’) imprime el segundo     mensaje,   si no, el tercero.

// salida en pantalla:
//(No hay secuencias cargadas) No hay secuencias cargadas en memoria.
//(Secuencia completa de archivo no vacío) Secuencia descripcion_secuencia contiene b bases.
//(Secuencia incompleta de archivo no vacío)Secuencia descripcion_secuencia contiene al menos b bases.

// 4. histograma descripcion_secuencia (Quien lo hace) = Imprime el histograma de una secuencia, en caso de que exista. El histograma se deﬁne como el conteo(frecuencia)
//                                       de cada código en la secuencia.Por cada línea(’\n’ es el caracter de salto de línea) se escribe el código y la cantidad de veces que aparece en la secuencia.El ordenamiento del
//                                       histograma está dado por la Tabla1.

// salida en pantalla:
//(No hay secuencias cargadas) No hay secuencias cargadas en memoria.
//(La secuencia no existe) La secuencia dada no existe.
//(Varias secuencias)La secuencia dada se repite s veces.

// 5. es_subsecuencia secuencia (Quien lo hace) =   Determina si una secuencia, dada por el usuario, existe dentro de las secuencias cargadas.
//                                  Si es así, determina la cantidad de veces en las que esta secuencia dada se repite.No es necesario
//                                  indicar el nombre de la secuencia donde se encuentra la repetición(el conteo es general sobre todas las secuencias cargadas en memoria)

// salida en pantalla:
//(No hay secuencias cargadas) No hay secuencias cargadas en memoria.
//(La secuencia no existe)La secuencia dada no existe.
//(Varias secuencias)La secuencia dada se repite s veces.

// 6. enmascarar secuencia (Quien lo hace) = Enmascara una secuencia dada por el usuario, si existe. Los elementos que pertenecen
//                           a la subsecuencia se enmascaran cambiando cada código por el código ’X’.No es necesario indicar el
//                           nombre de la secuencia donde se realiza el
//                           enmascarado(el proceso es general sobre todas las secuencias cargadas en memoria).

// salida en pantalla:
//(No hay secuencias cargadas) No hay secuencias cargadas en memoria.
//(Escritura exitosa) Las secuencias han sido guardadas en nombre_archivo .
//(Problemas en archivo) Error guardando en nombre_archivo .

// 7. salir (Quien lo hace) = Termina la ejecución de la aplicación.

//salida en pantalla:
//(No tiene salida por pantalla)
