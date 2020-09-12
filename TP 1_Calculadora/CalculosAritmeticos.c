#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "CalculosAritmeticos.h"

/** \brief Recibe los datos ingresados y los valida para reconocer si es de tipo num�rico o caracter
 * \param If condiciona el ingreso de caracteres obtenidos por el scanf a s�lo n�meros, si devuelve 1 no se cumpli� con
          el formato especificado y muestra un mensaje al usuario aclarando lo que sucede y luego limpia el b�fer del teclado
          para que la pr�xima llamada del scanf pause el programa
 * \param If verifica si el b�fer del teclado qued� sucio y luego lo limpia
 * \return Retorna 0 en caso que no ingrese en la iteraci�n, validando que el dato ingresado es de tipo num�rico
 */

int ValidarDato(const char* floatMask, void* variable)
{
    int caracter;
    if(!scanf(floatMask, variable))
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\nError. Eso no es un n%cmero.\n",163);
        return 1;
    }
    if(getchar() != '\n')
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\nError. Eso no es un n%cmero.\n",163);
        return 1;
    }
    return 0;
}

/** \brief Recibe los datos ingresados por el usuario para validar la opcion elegida
 * \param For realiza una iteraci�n comparando el �ndice con el largo de la cadena ingresada.
 * \param If crea una condici�n donde si el dato ingresado no es de tipo entero muestre un mensaje de error,
          haga una pausa en el sistema y devuelva 0
 * \return Retorna 1 en caso que el dato ingresado sea de tipo entero
 */
int ValidarOpcion(char opcion[])
{
    int i;
    for(i=0; i<strlen(opcion); i++)
    {
        if(!(isdigit(opcion[i])))
        {
            printf("\nIngrese s%clo n%cmeros del 1 al 5 por favor.\n\n", 162,163);
            system("pause");
            return 0;
        }
    }
    return 1;
}


/**
 * \brief Recibe los n�meros ingresados por el usuario y los suma
 * \param Suma es la variable que adquiere la adici�n de ambos n�meros
 * \return Retorna el resultado de la suma
 */
float SumaOperandos(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los resta
 * \param Resta es la variable que adquiere la sustracci�n del segundo n�mero al primero
 * \return Retorna el resultado de la resta
 */
float RestaOperandos(float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los divide
 * \param Cociente es la variable que adquiere el resultado de la divisi�n entre el cociente y el divisor
 * \return Retorna el resultado de la divisi�n
 */
float DivisionOperandos(float dividendo, float divisor)
{
    float cociente;
    cociente = dividendo / divisor;
    return cociente;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los multiplica
 * \param Producto es la variable que adquiere el resultado de la multiplicaci�n entre los dos n�meros
 * \return Retorna el resultado de la multiplicaci�n
 */
float MultiplicacionOperandos(float primerNumero, float segundoNumero)
{
    float producto;
    producto = primerNumero * segundoNumero;
    return producto;
}

/**
 * \brief Recibe el primer n�mero ingresado por el usuario y lo factorea
 * \param If comprobrueba que el n�mero ingresado sea distinto de 0, dentro contiene un for que realiza una
          iteraci�n multiplicando el n�mero ingresado por el �ndice de repeticiones
          retornando el resultado factorial
 * \param Else retorna 1 en caso que el n�mero ingresado sea 0, ya que por definici�n el factorial de 0 es 1
 * \return Retorna el resultado validado de la operaci�n factorial
 */
double FactorialPrimerNumero(double primerNumero)
{
    double resultadoPrimerNumero;
    int i;
    resultadoPrimerNumero = 1;
    if(primerNumero != 0)
    {
        for(i=2; i<=primerNumero; i++){
            resultadoPrimerNumero *= i;
        }
        return (resultadoPrimerNumero);
    }
    else
    {
        return 1;
    }
}

/**
 * \brief Recibe el segundo n�mero ingresado por el usuario y lo factorea
 * \param If comprobrueba que el n�mero ingresado sea distinto de 0, dentro contiene un for que realiza una
          iteraci�n multiplicando el n�mero ingresado por el �ndice de repeticiones
          retornando el resultado factorial
 * \param Else retorna 1 en caso que el n�mero ingresado sea 0, ya que por definici�n el factorial de 0 es 1
 * \return Retorna el resultado validado de la operaci�n factorial
 */

double FactorialSegundoNumero(double segundoNumero)
{
    double resultadoSegundoNumero;
    int i;
    resultadoSegundoNumero = 1;
    if(segundoNumero != 0)
    {
        for(i=2; i<=segundoNumero; i++){
            resultadoSegundoNumero *= i;
        }
        return (resultadoSegundoNumero);
    }
    else
    {
        return 1;
    }
}

/**
 * \brief Recibe los datos de de la primera funcion Factorial y verifica si el n�mero ingresado es un entero
 * \param Entero es la variable de comprobaci�n que se le es asignada la variable de entrada float y toma s�lo
 *        la parte entera
 * \param Resultado recibe la funci�n Factorial del primer n�mero ingresado por el usuario
 * \param Se asigna el n�mero float ingresado por el usuario a la variable entero para quitarle los decimales
 * \param If quita la parte entera del n�mero dejando s�lo la parte decimal
 * \param En caso de que haya parte decimal devuelve un valor 0, caso contrario se le asigna a la variable resultadoPrimerNumero
          la operaci�n de la funci�n Factorial del primer n�mero
 * \return Imprime en pantalla el resultado de la factorizaci�n
 */

double ValidacionFactorialPrimerNumero(double primerNumero)
{
    int entero1;
    double resultadoPrimerNumero;
    entero1 = primerNumero;
    if(primerNumero - entero1)
    {
        return 0;
    }
    else
    {
        resultadoPrimerNumero = FactorialPrimerNumero(primerNumero);
        return resultadoPrimerNumero;
    }
}

/**
 * \brief Recibe los datos de de la segunda funcion Factorial y verifica si el n�mero ingresado es un entero
 * \param Entero es la variable de comprobaci�n que se le es asignada la variable de entrada float y toma s�lo
 *        la parte entera
 * \param Resultado recibe la funci�n Factorial del segundo n�mero ingresado por el usuario
 * \param Se asigna el n�mero float ingresado por el usuario a la variable entero para quitarle los decimales
 * \param If quita la parte entera del n�mero dejando s�lo la parte decimal
 * \param En caso de que haya parte decimal devuelve un valor 0, caso contrario se le asigna a la variable resultadoSegundoNumero
          la operaci�n de la funci�n Factorial del segundo n�mero
 * \return Imprime en pantalla el resultado de la factorizaci�n
 */

double ValidacionFactorialSegundoNumero(double segundoNumero)
{
    int entero2;
    double resultadoSegundoNumero;
    entero2 = segundoNumero;
    if(segundoNumero - entero2)
    {
        return 0;
    }
    else
    {
        resultadoSegundoNumero = FactorialSegundoNumero(segundoNumero);
        return resultadoSegundoNumero;
    }
}

/** \brief Animaci�n mostrando la realizaci�n de c�lculos
 * \param Printf m�ltiples imprimiendo l�nea por l�nea las animaciones
 * \param System ejecuta el comando de terminal limpiando la ventana
 * \param Sleep hace una pausa de 700 milisegundos entre cada l�nea de c�lculo
 * \return Animacion funcional de c�lculo de operaciones
 */
void AnimacionCalculos(double primerNumero, double segundoNumero)
{
    printf("\n\n-------------------------------------------------------------------------------\n\n");
    system("cls");
    printf("\n ___________________________________");
    printf("\n|                                   |");
    printf("\n|------[A]=%.2f---------[B]=%.2f----|", primerNumero, segundoNumero);
    printf("\n ___________________________________");
    Sleep(700);
    printf("\n|--------Calculando la Suma---------|");
    Sleep(700);
    printf("\n|--------Calculando la Resta--------|");
    Sleep(700);
    printf("\n|-------Calculando la Division------|");
    Sleep(700);
    printf("\n|----Calculando la Multiplicacion---|");
    Sleep(700);
    printf("\n|-----Calculando los Factoriales----|");
    Sleep(700);
    printf("\n|--------Resultados Listos!!--------|");
    Sleep(700);
    printf("\n|___________________________________|");
    printf("\n\n-------------------------------------------------------------------------------\n");
}
