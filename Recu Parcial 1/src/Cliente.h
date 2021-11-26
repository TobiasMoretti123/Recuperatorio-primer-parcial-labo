#include "Informes.h"
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {
	int idCliente;
	char nombreEmpresa[20];
	char cuit[20];
	char direccion[20];
	int idLocalidad;
	int isEmpty;
} eCliente;

typedef struct {
	int idLocalidad;
	char nombre[20];
	int isEmpty;
} eLocalidad;

int AltaCliente(eCliente listaClientes[], eLocalidad listaLocalidad[],
		int tamCliente, int tamLocalidad);
eCliente IngresarCliente(eLocalidad listaLocalidad[], int tamLocalidad);
int BajaCliente(eCliente listaClientes[], int tamClientes);
int ModificarCliente(eCliente listaClientes[], int tamClientes,
		eLocalidad listaLocalidad[], int tamLocalidad);
int ListarCliente(eCliente listaClientes[],eLocalidad listaLocalidad[], int tamClientes,int tamLocalidad);
int InicialilarListaCliente(eCliente listaClientes[], int tamClientes);
void MostrarCliente(eCliente unCliente, char nombreLocalidad[]);
void MostrarLocalidad(eLocalidad unaLocalidad);
int BuscarIsEmpty(eCliente listaClientes[],int tamClientes,int* posicion);
int BuscarIdCliente(eCliente listaClientes[],int tamClientes,int valorBuscado,int* posicion);
int BuscarIdLocalidad(eLocalidad listaLocalidad[],int tamLocalidad,int valorBuscado,int* posicion);
int IngresarLocalidad(eLocalidad listaLocalidad[], int tamLocalidad);
int GenerarIdCliente();
int ClientesTotales(eCliente listaClientes[], int tamClientes);
eCliente ObtenerClientePorId(eCliente listaClientes[], int tamCliente, int id);
int NombrePorIdLocalidad(char nombre[], eLocalidad listaLocalidad[], int tamLocalidad,
		int idLocalidad);
void MostrarClienteCantidad(eCliente unCliente, char nombreLocalidad[],
		int cantidad);


#endif /* CLIENTE_H_ */
