/*
 * CalculosAritmeticos.h
 *
 *  Created on: Apr 16, 2021
 *      Author: mariano.forte
 */

#ifndef CALCULOSARITMETICOS_H_
#define CALCULOSARITMETICOS_H_

/**< Prototipo de la función de validación de dato ingresado */
int ValidarDato(const char* fm, void* var);

/**< Prototipo de la función de adición */
float SumaOperandos(float primerNumero, float segundoNumero);

/**< Prototipo de la función de sustracción */
float RestaOperandos(float primerNumero, float segundoNumero);

/**< Prototipo de la función de división */
float DivisionOperandos(float dividendo, float divisor);

/**< Prototipo de la función de producto */
float MultiplicacionOperandos(float primerNumero, float segundoNumero);

/**< Prototipo de la función de factorial */
unsigned long long int Factorial(double primerNumero);

/**< Prototipo de validación de la función factorial */
void ValidacionFactorial(float numero);

#endif /* CALCULOSARITMETICOS_H_ */
