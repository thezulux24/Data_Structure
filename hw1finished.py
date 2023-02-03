"""
Brayan David Zuluaga

"""


#EJERCICIO 1
#se define la matriz con los elementos
mat = [
	[11, 23, 76, 34, 11],
	[14, 30, 92, 30, 101],
	[12, 45, 58, 92, 22],
	[74, 56, 49, 56, 100],
	[99, 5, 28, 47, 99]
	]
#se define la funcion
def verificarDiagonales(matriz):
	#se inicializan dos listas vacias donde se albergaran los valores de las dos diagonales
	diagonalPrincipal = []
	diagonalSecundaria = []
	#ciclo que recorrerá el tamaño de la matriz, en este caso será 5
	for i in range (len(matriz)):
		#se añadiran los valores de la diagonal principal de la matriz a una lista con este nombre,
		#en este caso es sencillo, ya que la diagonal principal se puede determinar como una identidad
		diagonalPrincipal.append( matriz [i] [i])
		#para la diagonal secundaria necesitaremos empezar desde la ultima columna, recordemos que la ultima columna
		#tambien se puede denotar como -1. En este caso iniciaremos en el tamaño de la matriz, que cuenta el numero de filas
		#le restaremos i, ya que este con el paso del ciclo irá aumentado, pero ademas debemos restar 1, ya que 
		#el recorrido empieza de 0
		diagonalSecundaria.append(matriz[i][len(matriz) - i - 1])
	#retorna el valor booleano si se cumple la condición
	return diagonalPrincipal == diagonalSecundaria

#print(verificarDiagonales(mat))

#####################################################################
#####################################################################

#EJERCICIO 2
#se crean listas para comprobar resutados
listaA = [42, 12, 90, 90, 12, 42]
listaB = [42, 12, 90, 90, 123, 42]
def esCapicua(lista):
	resultado = True
	#se hace un ciclo definido para recorrer la lista, recorrerá desde 0 hasta el tamaño de la lista
	for i in range (len(lista)):
		#si el valor de la ubicacion en la lista es diferente a su valor leido alrevez, retornará false
		if lista[i] != lista [-i-1]: #simplemente se hace una leida de lista inverza, desde la posicion -1									#que es equivalente a la ultima posicion, la ir restando 1 se retrocedera la posición.
			resultado= False
	return resultado

#print(esCapicua(listaA))
#print(esCapicua(listaB))

#####################################################################
#####################################################################

#EJERCICIO 3 A)

#se crean listas donde se almacenarán los números
listaA = [40, 10, 22, 12, 33, 33, 33]
listaB = [41, 22, 31, 15, 13, 12, 33, 19]
#se define la funcion
def diferenciaListas (lista1, lista2):
	listaResultado = list()
	for numero in lista1:
		if numero not in lista2:
			listaResultado.append(numero)
		elif numero in lista2:
			lista2.remove(numero)
	return listaResultado


#print(diferenciaListas(listaA,listaB))
#print(diferenciaListas(listaB,listaA))

#####################################################################
#####################################################################

#EJERCICIO 3 B
def lecturaImpresion():
	numeroEjecuciones = int(input())
	for i in range (numeroEjecuciones):
		listaA = input().split()
		listaB = input().split()
		resultado = diferenciaListas(listaA[1::],listaB[1::])
		print(", ".join(resultado))


#lecturaImpresion()


#EJERCICIO 4


def mostrarPrimos (max):
	primos = []
	sumaDigitosPrimos = []
	for i in range (1, max):
		divisibles = 0
		divisor = 1
		while divisor <= i:
			if i % divisor == 0:
				divisibles += 1
			divisor += 1
		if divisibles == 2:
			primos.append (i)
			digitosSuma = sum(int(d) for d in str(i)) #es un generador que convierte cada caracter en un número entero, es decir, cada dígito del número
			if digitosSuma in primos:
				sumaDigitosPrimos.append(i)
	print("Números primos entre 1 y 100:")
	for numero in primos:
		print("-->",str(numero) + ",")
	print("Números entre 1 y 100 con suma de dígitos con valor primo:")
	print(*sumaDigitosPrimos, sep =", ") #en este caso no uso el método .join porque tengo la lista de enteros

#mostrarPrimos(100)

###################################
###################################
#ejercicio 5

disp = {0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]}

def sumarValoresMatriz (matriz, tupla):
	suma = 0
	for fila, columna in tupla: ##fila corresponde al primer valor de la tupla y columna al segundo
		if fila in matriz:  ##si la fila(primer valor de la tupla) se encuentra en la matriz:
			for y, valor in matriz[fila]: #y adopará el primer valor de la tupla *dentro de la matriz* dispersa correspondiente a la ubicacion
                                #"valor" correspondiente al valor (ESTE ES EL QUE SE SUMARÁ AL CONTADOR)  
				if columna == y: ##se recorrerá en ciclo buscando la coincidencia de columna para determinar que se encuentra la ubicacion
                                #de ser así, se sumará al contador el correspondiente a la coordenada de la matriz dispersa que en nuestro caso se llama "valor"
					suma += valor 
	return suma

#print(sumarValoresMatriz(disp, [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)]))