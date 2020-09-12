#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "CalculosAritmeticos.h"

/** \brief Recibe los datos ingresados y los valida para reconocer si es de tipo numérico o caracter
 * \param If condiciona el ingreso de caracteres obtenidos por el scanf a sólo números, si devuelve 1 no se cumplió con
          el formato especificado y muestra un mensaje al usuario aclarando lo que sucede y luego limpia el búfer del teclado
          para que la próxima llamada del scanf pause el programa
 * \param If verifica si el búfer del teclado quedó sucio y luego lo limpia
 * \return Retorna 0 en caso que no ingrese en la iteración, validando que el dato ingresado es de tipo numérico
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
 * \param For realiza una iteración comparando el índice con el largo de la cadena ingresada.
 * \param If crea una condición donde si el dato ingresado no es de tipo entero muestre un mensaje de error,
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
 * \brief Recibe los números ingresados por el usuario y los suma
 * \param Suma es la variable que adquiere la adición de ambos números
 * \return Retorna el resultado de la suma
 */
float SumaOperandos(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

/**
 * \brief Recibe los números ingresados por el usuario y los resta
 * \param Resta es la variable que adquiere la sustracción del segundo número al primero
 * \return Retorna el resultado de la resta
 */
float RestaOperandos(float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

/**
 * \brief Recibe los números ingresados por el usuario y los divide
 * \param Cociente es la variable que adquiere el resultado de la división entre el cociente y el divisor
 * \return Retorna el resultado de la división
 */
float DivisionOperandos(float dividendo, float divisor)
{
    float cociente;
    cociente = dividendo / divisor;
    return cociente;
}

/**
 * \brief Recibe los números ingresados por el usuario y los multiplica
 * \param Producto es la variable que adquiere el resultado de la multiplicación entre los dos números
 * \return Retorna el resultado de la multiplicación
 */
float MultiplicacionOperandos(float primerNumero, float segundoNumero)
{
    float producto;
    producto = primerNumero * segundoNumero;
    return producto;
}

/**
 * \brief Recibe el primer número ingresado por el usuario y lo factorea
 * \param If comprobrueba que el número ingresado sea distinto de 0, dentro contiene un for que realiza una
          iteración multiplicando el número ingresado por el índice de repeticiones
          retornando el resultado factorial
 * \param Else retorna 1 en caso que el número ingresado sea 0, ya que por definición el factorial de 0 es 1
 * \return Retorna el resultado validado de la operación factorial
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
 * \brief Recibe el segundo número ingresado por el usuario y lo factorea
 * \param If comprobrueba que el número ingresado sea distinto de 0, dentro contiene un for que realiza una
          iteración multiplicando el número ingresado por el índice de repeticiones
          retornando el resultado factorial
 * \param Else retorna 1 en caso que el número ingresado sea 0, ya que por definición el factorial de 0 es 1
 * \return Retorna el resultado validado de la operación factorial
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
 * \brief Recibe los datos de de la primera funcion Factorial y verifica si el número ingresado es un entero
 * \param Entero es la variable de comprobación que se le es asignada la variable de entrada float y toma sólo
 *        la parte entera
 * \param Resultado recibe la función Factorial del primer número ingresado por el usuario
 * \param Se asigna el número float ingresado por el usuario a la variable entero para quitarle los decimales
 * \param If quita la parte entera del número dejando sólo la parte decimal
 * \param En caso de que haya parte decimal devuelve un valor 0, caso contrario se le asigna a la variable resultadoPrimerNumero
          la operación de la función Factorial del primer número
 * \return Imprime en pantalla el resultado de la factorización
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
 * \brief Recibe los datos de de la segunda funcion Factorial y verifica si el número ingresado es un entero
 * \param Entero es la variable de comprobación que se le es asignada la variable de entrada float y toma sólo
 *        la parte entera
 * \param Resultado recibe la función Factorial del segundo número ingresado por el usuario
 * \param Se asigna el número float ingresado por el usuario a la variable entero para quitarle los decimales
 * \param If quita la parte entera del número dejando sólo la parte decimal
 * \param En caso de que haya parte decimal devuelve un valor 0, caso contrario se le asigna a la variable resultadoSegundoNumero
          la operación de la función Factorial del segundo número
 * \return Imprime en pantalla el resultado de la factorización
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

/** \brief Animación mostrando la realización de cálculos
 * \param Printf múltiples imprimiendo línea por línea las animaciones
 * \param System ejecuta el comando de terminal limpiando la ventana
 * \param Sleep hace una pausa de 700 milisegundos entre cada línea de cálculo
 * \return Animacion funcional de cálculo de operaciones
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
