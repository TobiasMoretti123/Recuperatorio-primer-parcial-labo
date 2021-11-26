#include "Informes.h"
/// \fn int ListarPedidosClientes(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Lista los clientes por pedidos pendientes y su cantidad
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si la lista esta vacia 0 si no lo esta
int ListarPedidosClientes(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int retorno;
	int cantidad;
	char nombreLocalidad[120];
	retorno = -1;
	cantidad = 0;
	if (listaPedido != NULL && listaCliente != NULL && listaLocalidad != NULL
			&& tamPedido >= 0 && tamCliente >= 0 && tamLocalidad >= 0) {
		printf(" ___ _______________ ____________________ _______________ _______________ __________ \n");
		printf("|ID |    Nombre     |       Cuit         |   Direccion   |   Localidad   | Cantidad |\n");
		for (int i = 0; i < tamCliente; i++) {
			if (listaCliente[i].isEmpty == FULL) {
				for (int j = 0; j < tamPedido; j++) {
					if (strcmp(listaPedido[j].estado, "Pendiente") == 0
							&& listaPedido[j].isEmpty == FULL
							&& listaPedido[j].idCliente
									== listaCliente[i].idCliente) {
						cantidad++;
					}
				}
				NombrePorIdLocalidad(nombreLocalidad, listaLocalidad,
						tamLocalidad, listaCliente[i].idLocalidad);
				MostrarClienteCantidad(listaCliente[i], nombreLocalidad,
						cantidad);
				retorno = 0;
			}
			cantidad = 0;
		}
	}
	return retorno;
}
/// \fn int ListarPedidosClientesPendientes(ePedido[], eCliente[], int, int)
/// \brief Muestra los pedidos pendientes
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \return -1 si la lista esta vacia 0 si no lo esta
int ListarPedidosClientesPendientes(ePedido listaPedido[],
		eCliente listaCliente[], int tamPedido, int tamCliente) {
	int retorno;
	eCliente aux;
	retorno = -1;
	if (listaCliente != NULL && listaPedido != NULL && tamPedido >= 0
			&& tamCliente >= 0) {
		printf(" ____________________ _______________ __________ \n");
		printf("|       Cuit         |   Direccion   | Cantidad |\n");
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL
					&& strcmp(listaPedido[i].estado, "Pendiente") == 0) {
				aux = ObtenerClientePorId(listaCliente, tamCliente,
						listaPedido[i].idCliente);
				MostrarPedidoPendiente(aux.cuit, aux.direccion,
						listaPedido[i].cantidad);
			}
			retorno = 0;
		}

	}
	return retorno;
}
/// \fn int ListarPedidosClientesProcesados(ePedido[], eCliente[], int, int)
/// \brief Muestra los pedidos procesados
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \return -1 si la lista esta vacia 0 si no lo esta
int ListarPedidosClientesProcesados(ePedido listaPedido[],
		eCliente listaCliente[], int tamPedido, int tamCliente) {
	int retorno;
	eCliente auxCliente;
	retorno = -1;
	if (listaCliente != NULL && listaPedido != NULL && tamPedido >= 0
			&& tamCliente >= 0) {
		printf(" ____________________ _______________ _____________ _____________ ___________ \n");
		printf("|       Cuit         |   Direccion   |Cantidad HDPE|Cantidad LDPE|Cantidad PP|\n");
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL
					&& strcmp(listaPedido[i].estado, "Completado") == 0) {
				auxCliente = ObtenerClientePorId(listaCliente, tamCliente,
						listaPedido[i].idCliente);
				MostrarPedidoCompletado(auxCliente.cuit, auxCliente.direccion,
						listaPedido[i].HDPE, listaPedido[i].LDPE,
						listaPedido[i].PP);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// \fn int CantidadPedidosPendientes(ePedido[], int, int)
/// \brief Calcula la cantidad de pedidos pendientes que tiene el cliente
/// \param listaPedido La lista de pedidos
/// \param tamPedido El tamaño de la lista de pedidos
/// \param idCliente El id del cliente a calcular
/// \return la cantidad de pedidos pendientes
int CantidadPedidosPendientes(ePedido listaPedido[], int tamPedido,
		int idCliente) {
	int cantidad = 0;
	if (listaPedido != NULL && tamPedido >= 0) {
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].idCliente == idCliente
					&& strcmp(listaPedido[i].estado, "Pendiente") == 0) {
				cantidad++;
			}
		}
	}
	return cantidad;
}
/// \fn int CantidadPedidosPorLocalidad(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Ingresa una localidad y calcula
/// la cantidad de pedidos pendientes de la misma
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return la cantidad de esa localidad
int CantidadPedidosPorLocalidad(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int retorno;
	int acumulador;
	int idLocalidadAux;
	char nombreLocalidad[120];
	retorno = -1;
	acumulador = 0;
	if (listaPedido != NULL && listaCliente != NULL && listaLocalidad != NULL
			&& tamPedido >= 0 && tamCliente >= 0 && tamLocalidad >= 0) {
		idLocalidadAux = IngresarLocalidad(listaLocalidad, tamLocalidad);
		for (int i = 0; i < tamCliente; i++) {
			if (idLocalidadAux
					== listaCliente[i].idLocalidad&& listaCliente[i].isEmpty ==FULL) {
				for (int j = 0; j < tamPedido; j++) {
					if (listaPedido[j].idCliente == listaCliente[i].idCliente
							&& listaPedido[j].isEmpty == FULL
							&& strcmp(listaPedido[j].estado, "Pendiente")
									== 0) {
						retorno = 0;
						acumulador++;
					}
				}
				NombrePorIdLocalidad(nombreLocalidad, listaLocalidad,
						tamLocalidad, idLocalidadAux);
			}
		}
	}
	if (acumulador != 0) {
		printf("La localidad: %-15s Tiene %-3d Pedidos pendientes\n",
				nombreLocalidad, acumulador);
	}
	return retorno;
}
/// \fn int KilosPromedioPorCliente(ePedido[], eCliente[], int, int)
/// \brief Calcula el promedio de kilos de todos los clientes
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \return -1 si hubo error 0 si se calculo correctamente
int KilosPromedioPorCliente(ePedido listaPedido[], eCliente listaCliente[],
		int tamPedido, int tamCliente) {
	int totalClientes;
	int retorno;
	int acumuladorKilos;
	float promedio;
	retorno = -1;
	if (listaCliente != NULL && listaPedido != NULL && tamPedido >= 0
			&& tamCliente >= 0) {
		totalClientes = ClientesTotales(listaCliente, tamCliente);
		acumuladorKilos = AcumularKilos(listaPedido, tamPedido);
		if (totalClientes != 0 && acumuladorKilos != 0) {
			retorno = 0;
			promedio = (float) acumuladorKilos / (float) totalClientes;
			printf("Cantidad de kilos promedio por cliente: %.2f\n", promedio);
		}
	}
	return retorno;
}
/// \fn int MostrarClienteMasPedientes(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Muestra el cliente o los clientes con mas pedidos pendientes
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si la lista esta vacia 0 si no lo esta
int MostrarClienteMasPedientes(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int retorno;
	int flagMaximo;
	int maximo;
	int actual;
	eCliente cliente;
	char nombreLocalidad[120];
	retorno = -1;
	actual = 0;
	flagMaximo = 0;
	if (listaPedido != NULL && listaCliente != NULL && listaLocalidad != NULL
			&& tamPedido >= 0 && tamCliente >= 0 && tamLocalidad >= 0) {
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL
					&& strcmp(listaPedido[i].estado, "Pendiente") == 0) {
				actual = CantidadPedidosPorIdCliente(listaPedido, tamPedido,
						listaPedido[i].idCliente);
			}
			if (flagMaximo == 0 || actual > maximo) {
				maximo = actual;
				cliente = ObtenerClientePorId(listaCliente, tamCliente,
						listaPedido[i].idCliente);
				retorno = 0;
				flagMaximo = 1;
			}
		}
	}
	if (flagMaximo == 1) {
		printf("Cliente con mas pedidos pendientes: \n");
		printf(" ___ _______________ ____________________ _______________ ____________________ \n");
		printf("|ID |    Nombre     |       Cuit         |   Direccion   |     Localidad      |\n");
		NombrePorIdLocalidad(nombreLocalidad, listaLocalidad, tamLocalidad,
				cliente.idLocalidad);
		MostrarCliente(cliente, nombreLocalidad);
	}
	return retorno;
}
/// \fn int MostrarClienteMasProcesados(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Muestra el cliente o los clientes con mas pedidos procesados
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si la lista esta vacia 0 si no lo esta
int MostrarClienteMasProcesados(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int retorno;
	int flagMaximo;
	int maximo;
	int actual;
	eCliente cliente;
	char nombreLocalidad[120];
	retorno = -1;
	actual = 0;
	flagMaximo = 0;
	if (listaPedido != NULL && listaCliente != NULL && listaLocalidad != NULL
			&& tamPedido >= 0 && tamCliente >= 0 && tamLocalidad >= 0) {
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL
					&& strcmp(listaPedido[i].estado, "Completado") == 0) {
				actual = CantidadPedidosPorIdCliente(listaPedido, tamPedido,
						listaPedido[i].idCliente);
			}
			if (flagMaximo == 0 || actual > maximo) {
				maximo = actual;
				cliente = ObtenerClientePorId(listaCliente, tamCliente,
						listaPedido[i].idCliente);
				flagMaximo = 1;
				retorno = 0;
			}
		}
	}
	if (flagMaximo == 1) {
		printf("Cliente con mas pedidos completados: \n");
		printf(" ___ _______________ ____________________ _______________ ____________________ \n");
		printf("|ID |    Nombre     |       Cuit         |   Direccion   |     Localidad      |\n");
		NombrePorIdLocalidad(nombreLocalidad, listaLocalidad, tamLocalidad,
				cliente.idLocalidad);
		MostrarCliente(cliente, nombreLocalidad);
	}
	return retorno;
}
/// \fn int MostrarClienteMasPedidos(ePedido[], eCliente[], eLocalidad[], int, int, int)
/// \brief Muestra el cliente o los clientes con mas pedidos
/// \param listaPedido La lista de pedidos
/// \param listaCliente La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamPedido El tamaño de la lista de pedidos
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si la lista esta vacia 0 si no lo esta
int MostrarClienteMasPedidos(ePedido listaPedido[], eCliente listaCliente[],
		eLocalidad listaLocalidad[], int tamPedido, int tamCliente,
		int tamLocalidad) {
	int retorno;
	int flagMaximo;
	int maximo;
	int actual;
	eCliente cliente;
	char nombreLocalidad[120];
	retorno = -1;
	actual = 0;
	flagMaximo = 0;
	if (listaPedido != NULL && listaCliente != NULL && listaLocalidad != NULL
			&& tamPedido >= 0 && tamCliente >= 0 && tamLocalidad >= 0) {
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL) {
				actual = CantidadPedidosPorIdCliente(listaPedido, tamPedido,
						listaPedido[i].idCliente);
			}
			if (flagMaximo == 0 || actual > maximo) {
				maximo = actual;
				cliente = ObtenerClientePorId(listaCliente, tamCliente,
						listaPedido[i].idCliente);
				flagMaximo = 1;
				retorno = 0;
			}
		}
	}
	if (flagMaximo == 1) {
		printf("Cliente con mas pedidos: \n");
		printf(" ___ _______________ ____________________ _______________ ____________________ \n");
		printf("|ID |    Nombre     |       Cuit         |   Direccion   |     Localidad      |\n");
		NombrePorIdLocalidad(nombreLocalidad, listaLocalidad, tamLocalidad,
				cliente.idLocalidad);
		MostrarCliente(cliente, nombreLocalidad);
	}
	return retorno;
}

