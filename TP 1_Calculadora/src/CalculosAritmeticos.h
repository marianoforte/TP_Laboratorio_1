/*
 * CalculosAritmeticos.h
 *
 *  Created on: Apr 16, 2021
 *      Author: mariano.forte
 */

#ifndef CALCULOSARITMETICOS_H_
#define CALCULOSARITMETICOS_H_

/**< Prototipo de la funci�n de validaci�n de dato ingresado */
int ValidarDato(const char* fm, void* var);

/**< Prototipo de la funci�n de adici�n */
float SumaOperandos(float primerNumero, float segundoNumero, float* suma);

/**< Prototipo de la funci�n de sustracci�n */
float RestaOperandos(float primerNumero, float segundoNumero, float* resta);

/**< Prototipo de la funci�n de divisi�n */
float DivisionOperandos(float dividendo, float divisor, float* cociente);

/**< Prototipo de la funci�n de producto */
float MultiplicacionOperandos(float primerNumero, float segundoNumero, float* producto);

/**< Prototipo de validaci�n de la funci�n factorial */
void MostrarFactorial(float numero, unsigned long long int factorial);

/**< Prototipo de la funci�n de factorial */
unsigned long long int Factorial(float numero, unsigned long long int* factorial);

#endif /* CALCULOSARITMETICOS_H_ */
