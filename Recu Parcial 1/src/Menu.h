#ifndef MENU_H_
#define MENU_H_
#include "Informes.h"
#include "Cliente.h"
#include "Pedido.h"

void MenuOpciones(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);
int MenuImprimir(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);
int MenuInformes(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad);

#endif /* MENU_H_ */
