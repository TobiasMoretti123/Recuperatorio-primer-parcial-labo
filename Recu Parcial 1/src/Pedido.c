#include "Pedido.h"
/// \fn int InicializaPedido(ePedido[], int)
/// \brief Inicializa la lista pedidos utilizando el valor logico isEmpty
/// \param listaPedido La lista de pedidos a inicializar
/// \param tamPedido El tamaño de la lista de pedidos
/// \return -1 si hubo error 0 si salio bien
int InicializaPedido(ePedido listaPedido[], int tamPedido) {
	int retorno = -1;
	if (listaPedido != NULL && tamPedido > 0) {
		for (int i; i < tamPedido; i++) {
			listaPedido[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
/// \fn int BuscarLugarPedido(ePedido[], int, int*)
/// \brief Busca un lugar en la lista de pedidos y los devuelve a modo puntero
/// \param listaPedido La lista de pedidos a buscar
/// \param tamPedido El tamaño de la lista de pedidos
/// \param posicion La posicion donde hay un lugar
/// \return -1 si hubo error 0 si encontro lugar
int BuscarLugarPedido(ePedido listaPedido[], int tamPedido, int *posicion) {
	int retorno = -1;
	int i;
	if (listaPedido != NULL && tamPedido >= 0 && posicion != NULL) {
		for (i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == EMPTY) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}
/// \fn int CrearPedido(ePedido[], int)
/// \brief Crea un pedido solo si hay lugar en la lista de pedidos
/// \param listaPedido La lista de pedidos a crear
/// \param tamPedido El tamaño de la lista de pedidos
/// \return -1 si hubo error 0 si salio bien
int CrearPedido(ePedido listaPedido[], int tamPedido) {
	int retorno = -1;
	int posicion;
	int auxKilos;
	int id;
	if (listaPedido != NULL && tamPedido > 0
			&& utn_getInt(&id, 2, "Ingrese el id de cliente: ", "Id invalido ",
					0, 1000000, 4, 0) == 1) {
		if (BuscarLugarPedido(listaPedido, tamPedido, &posicion) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			if (utn_getInt(&auxKilos, 20, "Ingrese kilos totales: ",
					"Peso invalido ", 0, 1000000, 4, 0) == 1) {
				listaPedido[posicion].idPedido = GenerarIdPedido();
				listaPedido[posicion].idCliente = id;
				listaPedido[posicion].cantidad = auxKilos;
				strncpy(listaPedido[posicion].estado, "Pendiente", 20);
				listaPedido[posicion].isEmpty = FULL;
				retorno = 0;
			}
		}
	}
	if (retorno == 0) {
		printf("Se genero pedido con id: %d\n", listaPedido[posicion].idPedido);
	}
	return retorno;
}
/// \fn int ProcesarPedido(ePedido[], int)
/// \brief Procesa un pedido que debe ser ingresado por el id
/// \param listaPedido La lista de pedidos
/// \param tamPedido el tamaño de la lista
/// \return -1 si hubo error 0 si se pudo procesar
int ProcesarPedido(ePedido listaPedido[], int tamPedido) {
	int retorno = -1;
	int posicion;
	int id;
	int kilosHDPE;
	int kilosLDPE;
	int kilosPP;
	if (listaPedido != NULL && tamPedido > 0) {
		ListarPedidos(listaPedido, tamPedido);
		if (utn_getInt(&id, 20, "Ingrese id del pedido: ", "Id invalido ", 100,
				10000000, 4, 0) == 1) {
			if (BuscarPedido(listaPedido, tamPedido, id, &posicion) == -1) {
				printf("\nNo existe este ID");
			} else {
				if (utn_getInt(&kilosHDPE, 20,
						"Ingrese cantidad de kilos HDPE: ",
						"Cantidad invalida ", 0, 1000000, 4, 0) == 1
						&& utn_getInt(&kilosLDPE, 20,
								"Ingrese cantidad de kilos LDPE: ",
								"Cantidad invalida ", 0, 1000000, 4, 0) == 1
						&& utn_getInt(&kilosPP, 20,
								"Ingrese cantidad de kilos PP: ",
								"Cantidad invalida ", 0, 1000000, 4, 0) == 1) {
					listaPedido[posicion].HDPE = kilosHDPE;
					listaPedido[posicion].PP = kilosPP;
					listaPedido[posicion].LDPE = kilosLDPE;
					strncpy(listaPedido[posicion].estado, "Completado", 20);
					retorno = 0;
				}
			}
		}
	}
	if (retorno == 0) {
		printf("Procesamiento realizado\n");
	}
	return retorno;
}
/// \fn int BuscarPedido(ePedido[], int, int, int*)
/// \brief Busca un pedido por un valor y devuelve su posicion a modo puntero
/// \param listaPedido La lista de pedidos a buscar
/// \param tamPedido El tamaño de la lista de pedidos
/// \param valorBuscado El valor a buscar
/// \param posicion La posicion donde se encuentra
/// \return -1 si hubo error 0 si se encontro
int BuscarPedido(ePedido listaPedido[], int tamPedido, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (listaPedido != NULL && tamPedido >= 0) {
		for (i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL) {
				if (listaPedido[i].idPedido == valorBuscado) {
					retorno = 0;
					*posicion = i;
					break;
				}
			}
		}
	}
	return retorno;
}
/// \fn int ListarPedidos(ePedido[], int)
/// \brief Lista los pedidos con todos sus datos
/// \param listaPedido Lista de pedidos
/// \param tamPedido Tamaño de la lista de pedidos
/// \return -1 si la lista esta vacia 0 si no lo esta
int ListarPedidos(ePedido listaPedido[], int tamPedido) {
	int retorno = -1;
	int i;
	if (listaPedido != NULL && tamPedido >= 0) {
		printf(" _________ __________ _______________ __________ \n");
		printf("|ID Pedido|ID Cliente|    Estado     | Cantidad |\n");
		for (i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL) {
				MostrarPedidos(listaPedido[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// \fn void MostrarPedidos(ePedido)
/// \brief Muestra un pedido
/// \param unPedido El pedido a mostrar
void MostrarPedidos(ePedido unPedido) {
	printf("|%-9d|%-10d|%-15s|%-10d|\n", unPedido.idPedido, unPedido.idCliente,
			unPedido.estado, unPedido.cantidad);
}
/// \fn int GenerarIdPedido()
/// \brief Genera un id autoincremental para los pedidos
/// \return El id
int GenerarIdPedido() {
	static int contador = 99;
	contador++;
	return contador;
}
/// \fn ePedido ObtenerPedidoPorIdPedido(ePedido[], int, int)
/// \brief Obtiene un pedido en base a un id
/// \param listaPedidos La lista de pedidos a obtener
/// \param tamPedido El tamaño de la lista de pedidos
/// \param idPedido El id a obtener
/// \return el pedido obtenido
ePedido ObtenerPedidoPorIdPedido(ePedido listaPedidos[], int tamPedido,
		int idPedido) {
	ePedido aux;
	if (listaPedidos != NULL && tamPedido >= 0) {
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedidos[i].isEmpty == FULL
					&& listaPedidos[i].idPedido == idPedido) {
				aux = listaPedidos[i];
				break;
			}
		}
	}
	return aux;
}
/// \fn int CantidadPedidosPorIdCliente(ePedido[], int, int)
/// \brief Calcula la cantidad de pedidos que hay por el id del cliente
/// \param listaPedidos La lista de pedidos
/// \param tamPedidos El tamaño de la lista de pedidos
/// \param idCliente El id del cliente
/// \return La cantidad de pedidos del cliente
int CantidadPedidosPorIdCliente(ePedido listaPedidos[], int tamPedidos,
		int idCliente) {
	int cantPedidos = 0;
	if (listaPedidos != NULL && tamPedidos >= 0) {
		for (int i = 0; i < tamPedidos; i++) {
			if (listaPedidos[i].isEmpty == FULL
					&& listaPedidos[i].idCliente == idCliente) {
				cantPedidos++;
			}
		}
	}
	return cantPedidos;
}
/// \fn void MostrarPedidoPendiente(char[], char[], int)
/// \brief Muestra los pedidos pendientes con datos del cliente
/// \param unCuit El cuit del cliente
/// \param unaDireccion La direccion del cliente
/// \param Kilos Los kilos totales del cliente
void MostrarPedidoPendiente(char unCuit[], char unaDireccion[], int Kilos) {
	printf("|%-20s|%-15s|%-10d|\n", unCuit, unaDireccion, Kilos);
}
/// \fn void MostrarPedidoCompletado(char[], char[], int, int, int)
/// \brief Muestra los datos del pedido procesado con los datos de cliente
/// \param unCuit El cuit del cliente
/// \param unaDireccion La direccion del ciente
/// \param HDPE Los kilos de HDPE
/// \param LDPE Los kilos de LDPE
/// \param PP Los kilos de PP
void MostrarPedidoCompletado(char unCuit[], char unaDireccion[], int HDPE,
		int LDPE, int PP) {
	printf("|%-20s|%-15s|%-13d|%-13d|%-11d|\n", unCuit, unaDireccion, HDPE,
			LDPE, PP);
}
/// \fn int AcumularKilos(ePedido[], int)
/// \brief Acumula todos los kilos de la lista de pedidos
/// \param listaPedido La lista de pedidos
/// \param tamPedido El tamaño de la lista de pedidos
/// \return La cantidad de kilos totales
int AcumularKilos(ePedido listaPedido[], int tamPedido) {
	int acumulador;
	acumulador = 0;
	if (listaPedido != NULL && tamPedido >= 0) {
		for (int i = 0; i < tamPedido; i++) {
			if (listaPedido[i].isEmpty == FULL) {
				acumulador += listaPedido[i].cantidad;
			}
		}
	}
	return acumulador;
}
