#include "utn.h"
#include "validaciones.h"
#define LEN_DNI 11
#define LEN_CUIT 20
#define LEN_EMAIL 30
#define LEN_TELEFONO 14
#define LEN_TARJETA 20

/// \fn int get_myGets(char*, int)
/// \brief Recibe una cadena con fgets, le remueve el enter del final y devuelve el resultado por referencia
/// \param pResultado Puntero a la direccion de memoria del string
/// \param len Tamaño del array. Limite de caracteres/digitos
/// \return -1si hubo error de validacion, 1 si no hubo errores.
int get_myGets(char *pResultado, int len) {
	int retorno = -1;
	fflush(stdin);
	if (pResultado != NULL && len > 0
			&& fgets(pResultado, len, stdin) == pResultado) {
		fflush(stdin);
		if (pResultado[strnlen(pResultado, len) - 1] == '\n') {
			pResultado[strnlen(pResultado, len) - 1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}
/// \fn int utn_getInt(int*, int, char*, char*, int, int, int, int)
/// \brief Pide un numero entero
/// \param pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
/// \param len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
/// \param mensaje Mensaje que se muestra previo al ingreso
/// \param mensajeError Mensaje que se muestra ante ingreso erróneo
/// \param minimo Valor minimo a recibir
/// \param maximo Valor maximo a recibir
/// \param reintentos Cantidad de reintentos
/// \param flagSigned Indica si recibe negativos (1) o no (0)
/// \return Devuelve 1 si pudo obtener un entero, 0 si no lo pudo obtener, -1 si hubo error de validación
int utn_getInt(int *pResultado, int len, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos, int flagSigned) {
	int retorno = -1;
	char buffer[len];
	int bufferInt;
	if (pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		retorno = 0;
		for (int i = 0; i <= reintentos; reintentos--) {
			printf("%s", mensaje);
			fflush(stdin);
			if (get_myGets(buffer, len) && val_isValidInt(buffer, flagSigned)) {
				bufferInt = atoi(buffer);
				if (bufferInt <= maximo && bufferInt >= minimo) {

					*pResultado = bufferInt;
					retorno = 1;
					break;
				}

			}
			printf("%s", mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
/// \fn int utn_getFloat(float*, int, char*, char*, int, int, int, int)
/// \brief Pide un numero flotante
/// \param pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
/// \param len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
/// \param mensaje Mensaje que se muestra previo al ingreso
/// \param mensajeError Mensaje que se muestra ante ingreso erróneo
/// \param minimo Valor minimo a recibir
/// \param maximo Valor maximo a recibir
/// \param reintentos Cantidad de reintentos
/// \param flagSigned Indica si recibe negativos (1) o no (0)
/// \return Devuelve 1 si pudo obtener un flotante, 0 si no lo pudo obtener, -1 si hubo error de validación
int utn_getFloat(float *pResultado, int len, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos, int flagSigned) {
	int retorno = -1;
	char buffer[len];
	float bufferFloat;
	if (pResultado != NULL && len > 0 && mensaje != NULL && minimo <= maximo
			&& mensajeError != NULL && reintentos >= 0) {
		retorno = 0;
		while (reintentos >= 0) {
			printf("%s", mensaje);
			if (get_myGets(buffer, len)
					&& val_isValidFloat(buffer, flagSigned) == 1) {
				bufferFloat = atof(buffer);
				if (bufferFloat >= minimo && bufferFloat <= minimo) {
					*pResultado = bufferFloat;
					retorno = 1;
					break;
				} else {
					*pResultado = bufferFloat;
					retorno = 1;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
/// \fn int utn_getName(char*, int, char*, char*, int)
/// \brief Pide un nombre
/// \param pResultado Puntero a la dirección de memoria donde guardar el dato obtenido y validado
/// \param len Tamaño del array indica el maximo de caracteres del nombre (hay que descontar el EOF y espacios, si corresponde)
/// \param mensaje Mensaje que se muestra previo al ingreso
/// \param mensajeError Mensaje que se muestra ante ingreso erróneo
/// \param reintentos Cantidad de reintentos
/// \return Devuelve 1 si pudo obtener un nombre, 0 si no lo pudo obtener, -1 si hubo error de validación
int utn_getName(char *pResultado, int len, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -2;
	char buffer[len];
	if (pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		retorno = -1;
		while (reintentos >= 0) {
			printf("%s", mensaje);
			if (get_myGets(buffer, len) && val_isValidName(buffer)) {
				strncpy(pResultado, buffer, len);
				retorno = 1;
				break;
			} else {
				printf("%s", mensajeError);
			}
			reintentos--;
		}
	}
	return retorno;
}
/// \fn int utn_getText(char*, int, char*, char*, int)
/// \brief Pide un texto no vacio
/// \param pResultado Puntero a la dirección de memoria donde guardar el texto obtenido
/// \param len Tamaño del array indica el maximo de caracteres del texto (hay que descontar el EOF)
/// \param mensaje Mensaje que se muestra previo al ingreso
/// \param mensajeError Mensaje que se muestra ante ingreso erróneo
/// \param reintentos Cantidad de reintentos
/// \return Devuelve 1 si pudo obtener un texto, 0 si no lo pudo obtener, -1 si hubo error de validación
int utn_getText(char *pResultado, int len, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -1;
	char buffer[len];
	if (pResultado != NULL && len > 0 && mensaje != NULL) {
		while (reintentos >= 0) {
			printf("%s", mensaje);
			if (get_myGets(buffer, len) && buffer[0] != 0) {
				strncpy(pResultado, buffer, len);
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
/// \fn int utn_getDni(char*, char*, char*, int)
/// \brief Pide un dni
/// \param pResultado Dirección de memoria del array de caracteres donde almacenar el dni
/// \param mensaje Mensaje que se muestra previo al ingreso
/// \param mensajeError Mensaje que se muestra ante ingreso erróneo
/// \param reintentos Cantidad de reintentos
/// \return Devuelve 1 si pudo obtener un dni, 0 si no lo pudo obtener, -1 si hubo error de validación
int utn_getDni(char *pResultado, char *mensaje, char *mensajeError, int reintentos) {
	int retorno = -2;
	char buffer[LEN_DNI];

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		retorno = -1;
		while (reintentos >= 0) {
			printf("%s", mensaje);
			if (get_myGets(buffer, LEN_DNI) && val_isValidDni(buffer)) {
				strncpy(pResultado, buffer, LEN_DNI);
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
/// \fn int utn_getCuit(char*, char*, char*, int)
/// \brief Pide un cuit
/// \param pResultado Dirección de memoria del array de caracteres donde almacenar el cuit
/// \param mensaje Mensaje que se muestra previo al ingreso
/// \param mensajeError Mensaje que se muestra ante ingreso erróneo
/// \param reintentos Cantidad de reintentos
/// \return Devuelve 1 si pudo obtener un cuit, 0 si no lo pudo obtener, -1 si hubo error de validación
int utn_getCuit(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -2;
	char buffer[LEN_CUIT];
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		retorno = -1;
		while (reintentos >= 0) {
			printf("%s", mensaje);
			if (get_myGets(buffer, LEN_CUIT) == 1
					&& val_isValidCuit(buffer) == 0) {
				strncpy(pResultado, buffer, LEN_CUIT);
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
