#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef UTN_H_
#define UTN_H_

int get_myGets(char *pResultado, int len);
int utn_getInt(int *pResultado, int len, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos, int flagSigned);
int utn_getFloat(float *pResultado, int len, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos, int flagSigned);
int utn_getName(char *pResultado, int len, char *mensaje, char *mensajeError,
		int reintentos);
int utn_getText(char *pResultado, int len, char *mensaje, char *mensajeError,
		int reintentos);
int utn_getDni(char *pResultado, char *mensaje, char *mensajeError, int reintentos);
int utn_getTarjeta(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);
int utn_getCuit(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);

#endif /* UTN_H_ */
