#include "Informes.h"
#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct {
	int idPedido;
	int isEmpty;
	int idCliente;
	char estado[20];
	int HDPE;
	int LDPE;
	int PP;
	int cantidad;
} ePedido;

int InicializaPedido(ePedido listaPedido[], int tamPedido);
int BuscarLugarPedido(ePedido listaPedido[], int tamPedido, int* posicion);
int CrearPedido(ePedido listaPedido[], int tamPedido);
int ProcesarPedido(ePedido listaPedido[], int tamPedido);
int BuscarPedido(ePedido listaPedido[], int tamPedido, int valorBuscado, int* posicion);
int ListarPedidos(ePedido listaPedido[], int tamPedido);
void MostrarPedidos(ePedido unPedido);
int GenerarIdPedido();
ePedido ObtenerPedidoPorIdPedido(ePedido listaPedidos[], int tamPedido, int idPedido);
int CantidadPedidosPorIdCliente(ePedido listaPedidos[], int tamPedidos,
		int idCliente);
void MostrarPedidoPendiente(char unCuit[], char unaDireccion[], int Kilos);
void MostrarPedidoCompletado(char unCuit[], char unaDireccion[], int HDPE,
		int LDPE, int PP);
int AcumularKilos(ePedido listaPedido[], int tamPedido);

#endif /* PEDIDO_H_ */
