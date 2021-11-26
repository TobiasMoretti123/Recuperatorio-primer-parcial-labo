#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int val_isValidInt(char *numero, int flagSigned);
int val_isValidFloat(char *numero, int flagSigned);
int val_isValidName(char *nombre);
int val_isValidDni(char *dni);
int val_isValidTelefono(char *telefono);
int val_isValidTarjeta(char *tarjeta);
int val_isValidCuit(char *cuit);
int val_isValidEmail(char *email);
int val_cantidadDigitos(char *arrayParaVerificar);
int val_cuitDigitoVerificador(char *cuit);

#endif /* VALIDACIONES_H_ */
