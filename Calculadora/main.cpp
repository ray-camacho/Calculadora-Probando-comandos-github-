///Programa que emula una calculadora

///Librerias
#include <iostream>
#include <math.h>
#include <windows.h>
#include <sstream>

///Agrega automaticamente std donde sea necesario, ahorrandonos lineas de codigo
using namespace std;

///Prototipo de funciones
int factorial(int n);
float operacion_basica(int);

///Funcion main
int main()
{
    ///Variables locales
    bool repetir=true;
    string opcion="";
    float resultado=0;
    ///Repetira el menu hasta que el usuario decida salir del ciclo
    while(repetir)
    {
        ///Limpia la pantalla
        system("cls");
        ///Varaibles locales
        opcion="";
        resultado=0;
        ///Menu que visualizara el usuario
        cout<<"\n\t\tSelecciona una opcion: "
        <<"\n\t1-->Salir"
        <<"\n\t2-->Suma"
        <<"\n\t3-->Resta"
        <<"\n\t4-->Division"
        <<"\n\t5-->Multiplicacion"
        <<"\n\t6-->Potencia"
        <<"\n\t7-->Raiz Cuadrada"
        <<"\n\t8-->Modulo %"
        <<"\n\t9-->Factorial"
        <<"\n\t10-->Logaritmo"
        <<"\n\t11-->Convertidor de unidades"
        <<"\n\n\t\tOpcion numero: ";
        ///Guarda la eleccion del usuario
        cin>>opcion;
        ///Convierte de string a int, evitando asi un bug ocasionado por un caracter en donde va un entero
        stringstream geek(opcion);
        int opc = 0;
        geek >> opc;
        ///Realiza la funcion de acuerdo a la eleccion del ususario
        switch(opc)
        {
            ///Opcion salir
            case 1:
                cout<<"\n\tHasta luego, que tenga un buen dia!!!";
                repetir=false;
                break;
            ///Funciones suma, resta, multiplicacion, division, llamando a la funcion operacion_basica
            case 2:
            case 3:
            case 4:
            case 5:
                resultado=operacion_basica(opc);
                cout<<"\n\t\tResultado: "<<resultado;
                break;

            case 9:{
                int n; ///variable local
                cout<<"Ingrese un valor entero :";
                cin>>n;
                if(n >= 0)
                    cout<<factorial(n);///pasamos el valor por parametro
                else
                    cout<<"\n\tOpcion Invalida";
                break;
            }

            ///En caso que se ingrese una opcion invalida
            default:
                cout<<"\n\tOpcion Invalida";
        }
        ///Espera a que el usuario haga click
        cout<<"\n\tPresiona cualquier tecla para continuar";
        cin.get();
        cin.get();
    }
    return 0;
}

///Funcion que se encarga de las operaciones de suma, resta, division y multiplicacion
float operacion_basica(int opcion)
{
    ///Variables locales
    float digito_1=0;
    float digito_2=0;
    float resultado=0;
    string cadena=" ";
    ///Solicita el primer dato y lo convierte de string a float evitando que el usuario ingrese un dato que provoque un error al programa
    cout<<"\nIngresa primer digito positivo: ";
    cin>>cadena;
    stringstream geek(cadena);
    geek >> digito_1;
    ///Solicita el segundo dato y lo convierte de string a float evitando que el usuario ingrese un dato que provoque un error al programa
    cout<<"\nIngresa segundo digito positivo: ";
    cin>>cadena;
    stringstream geek_2(cadena);
    geek_2 >> digito_2;
    ///Realizara la opcion elegida segun el usuario con los datos especificados anteriormente
    switch(opcion)
    {
        case 2:
            resultado=digito_1+digito_2;
            break;
        case 3:
            resultado=digito_1-digito_2;
            break;
        case 4:
            resultado=digito_1/digito_2;
            break;
        default:
            resultado=digito_1*digito_2;
            break;
    }
    ///Devuelve el resultado de los 2 datos anteriores
    return resultado;
}

int factorial(int n)///funcion recursivo
{
    if(n > 1)
        return n * factorial(n - 1);///recursividad
    else if(n ==0 || n == 1)
        return 1;///si el valor de n es 0 o 1, la respuesta es 1
    else
        return -1;/// si se ingresa otro valor, es considerado como un dato de error_category
}
