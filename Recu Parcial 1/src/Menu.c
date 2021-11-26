#include "Menu.h"
/// \fn void MenuOpciones(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Menu principal donde se encuentran las opciones principales
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
void MenuOpciones(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int opciones;
	int banderaCliente;
	int banderaPedido;
	banderaCliente = 0;
	banderaPedido = 0;
	do {
		printf("\n------------Menu Principal--------------\n");
		if (utn_getInt(&opciones, 2,
				"1.Alta\n2.Modificar\n3.Baja\n4.Crear pedido\n5.Procesar pedido\n6.Imprimir\n7.Informes\n8.Salir\nIngrese opcion: ",
				"Opcion invalida\n", 1, 8, 4, 0) != 1) {
			break;
		}
		switch (opciones) {
		case 1:
			if (AltaCliente(listaCliente, listaLocalidad, tamCliente,
					tamLocalidad) == 0) {
				banderaCliente = 1;
			} else {
				printf("Error en la carga de cliente\n");
			}
			break;
		case 2:
			if (banderaCliente == 1) {
				if (ModificarCliente(listaCliente, tamCliente, listaLocalidad,
						tamLocalidad) == -1) {
					printf("Usted cancelo la modificacion\n");
				}
			} else {
				printf("No puede modificar si no ingreso clientes\n");
			}
			break;
		case 3:
			if (banderaCliente == 1) {
				ListarCliente(listaCliente, listaLocalidad, tamCliente,
						tamLocalidad);
				if (BajaCliente(listaCliente, tamCliente) == -1) {
					printf("Usted cancelo la baja\n");
				}
			} else {
				printf("No puede dar de baja si no ingreso clientes\n");
			}
			break;
		case 4:
			if (banderaCliente == 1) {
				if (ListarCliente(listaCliente, listaLocalidad, tamCliente,
						tamLocalidad) == -1
						&& CrearPedido(listaPedido, tamPedido) == -1) {
					printf("Error al cargar los pedidos\n");
				} else {
					banderaPedido = 1;
				}
			} else {
				printf("No puede crear pedidos sin clientes\n");
			}
			break;
		case 5:
			if (banderaCliente == 1 && banderaPedido == 1) {
				if (ProcesarPedido(listaPedido, tamPedido) == -1) {
					printf("Error al procesar el pedido\n");
				}
			} else {
				printf("No puede procesar sin pedidos o clientes\n");
			}
			break;
		case 6:
			if (banderaCliente == 1 && banderaPedido == 1) {
				if (MenuImprimir(listaPedido, listaCliente, listaLocalidad,
						tamPedido, tamCliente, tamLocalidad) == -1) {
					break;
				}
			} else {
				printf("No puede imprimir sin clientes o pedidos\n");
			}
			break;
		case 7:
			if (banderaCliente == 1 && banderaPedido == 1) {
				if (MenuInformes(listaPedido, listaCliente, listaLocalidad,
						tamPedido, tamCliente, tamLocalidad) == -1) {
					break;
				}
			} else {
				printf("No puede informar sin clientes o pedidos\n");
			}

			break;
		case 8:
			printf("Usted salio del servicio\n");
			break;
		}
	} while (opciones < 8);
}
/// \fn int MenuImprimir(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Menu donde se encuentran las opciones para imprimir
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si hubo error 0 si salio bien
int MenuImprimir(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int opciones;
	int retorno;
	retorno = -1;
	printf("------------Menu Imprimir--------------\n");
	if (utn_getInt(&opciones, 2,
			"1.Imprimir cliente\n2.Imprimir pedidos pendientes\n3.Imprimir pedidos procesados\n4.Volver\nIngrese opcion:",
			"Opcion invalida\n", 1, 4, 4, 0) == 1) {
		retorno = 0;
		switch (opciones) {
		case 1:
			if (ListarPedidosClientes(listaPedido, listaCliente, listaLocalidad,
					tamPedido, tamCliente, tamLocalidad) == -1) {
				printf("No hay pedidos pendientes\n");
			}
			break;
		case 2:
			if (ListarPedidosClientesPendientes(listaPedido, listaCliente,
					tamPedido, tamCliente) == -1) {
				printf("No hay pedidos pendientes\n");
			}
			break;
		case 3:
			if (ListarPedidosClientesProcesados(listaPedido, listaCliente,
					tamPedido, tamCliente) == -1) {
				printf("No hay pedidos procesados\n");
			}
			break;
		}
	}
	return retorno;
}
/// \fn int MenuInformes(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Menu con las opciones para los informes
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si hubo error 0 si salio bien
int MenuInformes(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int opciones;
	int retorno;
	retorno = -1;
	printf("------------Menu Informes--------------\n");
	if (utn_getInt(&opciones, 2,
			"1.Cantidad pendiente por localidad\n2.Promedio de kilos\n3.Cliente con mas pendientes\n4.Cliente con mas procesados\n5.Cliente con mas pedidos\n6.Salir\nIngrese opcion:",
			"Opcion invalida\n", 1, 6, 4, 0) != 1) {
		retorno = 0;
	}
	switch (opciones) {
	case 1:
		if (CantidadPedidosPorLocalidad(listaPedido, listaCliente,
				listaLocalidad, tamPedido, tamCliente, tamLocalidad) == -1) {
			printf("No hay pedidos pendientes para esa localidad\n");
		}
		break;
	case 2:
		if (KilosPromedioPorCliente(listaPedido, listaCliente, tamPedido,
				tamCliente) == -1) {
			printf("No hay clientes o pedidos para calcular\n");
		}
		break;
	case 3:
		if (MostrarClienteMasPedientes(listaPedido, listaCliente,
				listaLocalidad, tamPedido, tamCliente, tamLocalidad) == -1) {
			printf("No hay clientes con pedidos pendientes\n");
		}
		break;
	case 4:
		if (MostrarClienteMasProcesados(listaPedido, listaCliente,
				listaLocalidad, tamPedido, tamCliente, tamLocalidad) == -1) {
			printf("No hay clientes con pedidos procesados\n");
		}
		break;
	case 5:
		if (MostrarClienteMasPedidos(listaPedido, listaCliente, listaLocalidad,
				tamPedido, tamCliente, tamLocalidad) == -1) {
			printf("No hay pedidos o clientes\n");
		}
		break;
	}
	return retorno;
}
