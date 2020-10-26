import math
from os import system

def main():
	repetir=1
	while repetir:
		system("cls")
		print("\nSelecciona una opcion:",
			"\n\t0-->Salir",
			"\n\t1-->Suma",
			"\n\t2-->Resta",
			"\n\t3-->Division",
			"\n\t4-->Multiplicacion",
			"\n\t5-->Potencia",
			"\n\t6-->Raiz Cuadrada",
			"\n\t7-->Modulo %",
			"\n\t8-->Factorial",
			"\n\t9-->Logaritmo",
			"\n\t10-->Convertidor de unidades",
			"\n\nOpcion numero:")
		opcion = input()
		opcion=numeroFloat(opcion)
		if opcion ==0:
			print("\n\tHasta luego, que tenga un buen dia!!!")
			repetir =0

		elif opcion>0 and opcion<5:
			resultado=operacionBasica(opcion)
			print("\nResultado: ",resultado)

		else:
			print("\n\tOpcion Invalida")
		print("\n\tPresiona cualquier tecla para continuar")
		input()

def numeroFloat(cantidad):
	try:
		numero=float(cantidad)
	except:
		numero=-1
	return numero

def operacionBasica(opcion):
	dig1=-1
	dig2=-1
	resultado=0
	while(dig1==-1):
		print("\nIngresa primer digito positivo: ")
		dig1=input()
		dig1=numeroFloat(dig1)
	while(dig2==-1):
		print("\nIngresa segundo digito positivo: ")
		dig2=input()
		dig2=numeroFloat(dig2)

	if opcion==1:
		resultado=dig1+dig2

	elif opcion==2:
		resultado=dig1-dig2

	elif opcion==3:
		resultado=dig1/dig2

	else:
		resultado=dig1*dig2

	return resultado

main()