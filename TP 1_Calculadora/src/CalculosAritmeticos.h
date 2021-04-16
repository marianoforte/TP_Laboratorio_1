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
float SumaOperandos(float primerNumero, float segundoNumero);

/**< Prototipo de la funci�n de sustracci�n */
float RestaOperandos(float primerNumero, float segundoNumero);

/**< Prototipo de la funci�n de divisi�n */
float DivisionOperandos(float dividendo, float divisor);

/**< Prototipo de la funci�n de producto */
float MultiplicacionOperandos(float primerNumero, float segundoNumero);

/**< Prototipo de la funci�n de factorial */
unsigned long long int Factorial(double primerNumero);

/**< Prototipo de validaci�n de la funci�n factorial */
void ValidacionFactorial(float numero);

#endif /* CALCULOSARITMETICOS_H_ */
