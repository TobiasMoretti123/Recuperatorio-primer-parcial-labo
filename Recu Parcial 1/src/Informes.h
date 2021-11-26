#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef INFORMES_H_
#define INFORMES_H_
#define FULL 1
#define EMPTY 0
#define PENDIENTE 1
#define COMPLETADO 2
#include "Menu.h"
#include "Pedido.h"
#include "Cliente.h"
#include "utn.h"
#include "validaciones.h"

int ListarPedidosClientes(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);
int ListarPedidosClientesPendientes(ePedido listaPedido[],
		eCliente listaCliente[], int tamPedido, int tamCliente);
int ListarPedidosClientesProcesados(ePedido listaPedido[],
		eCliente listaCliente[], int tamPedido, int tamCliente);
int CantidadPedidosPendientes(ePedido listaPedido[], int tamPedido,
		int idCliente);
int CantidadPedidosPorLocalidad(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);
int KilosPromedioPorCliente(ePedido listaPedido[], eCliente listaCliente[],
		int tamPedido, int tamCliente);
int MostrarClienteMasPedientes(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);
int MostrarClienteMasProcesados(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);
int MostrarClienteMasPedidos(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);

#endif /* INFORMES_H_ */
