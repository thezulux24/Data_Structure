#se define la matriz con los elementos
mat = [
	[11, 23, 76, 34, 11],
	[14, 30, 92, 30, 101],
	[12, 45, 58, 92, 22],
	[74, 56, 49, 56, 100],
	[99, 5, 28, 47, 99]
	]
#se define la funcion
def f_verificarDiagonales(matriz):
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
print(f_verificarDiagonales(mat))
