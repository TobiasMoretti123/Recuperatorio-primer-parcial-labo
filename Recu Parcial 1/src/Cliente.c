#include "Cliente.h"
/// \fn int AltaCliente(eCliente[], eLocalidad[], int, int)
/// \brief Da de alta un cliente utilizando la lista de clientes y de localidades
/// \param listaClientes La lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamCliente El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return retorna -1 en caso de error o 0 si salio bien
int AltaCliente(eCliente listaClientes[], eLocalidad listaLocalidad[],
		int tamCliente, int tamLocalidad) {
	int retorno = -1;
	int posicion;
	if (listaClientes != NULL && listaLocalidad != NULL && tamCliente > 0
			&& tamLocalidad > 0) {
		if (BuscarIsEmpty(listaClientes, tamCliente, &posicion) == -1) {
			printf("\nNo hay lugares disponibles");
		} else {
			listaClientes[posicion] = IngresarCliente(listaLocalidad,
					tamLocalidad);
			retorno = 0;
		}
	}
	if (retorno == 0) {
		printf("Dado de alta correctamente ID: %d\n",
				listaClientes[posicion].idCliente);
	}
	return retorno;
}
/// \fn eCliente IngresarCliente(eLocalidad[], int)
/// \brief Ingresa un cliente con su localidad
/// \param listaLocalidad Lista de localidad a mostrar para ingresarla
/// \param tamLocalidad Tamaño de la lista de localidad
/// \return el cliente ingresado
eCliente IngresarCliente(eLocalidad listaLocalidad[], int tamLocalidad) {
	eCliente unCliente;
	char nombre[20];
	char cuit[20];
	char direccion[20];
	int auxLocalidad;
	unCliente.isEmpty = EMPTY;
	if (utn_getName(nombre, 20, "Ingrese nombre empresa: ", "Nombre invalido ",
			4) == 1
			&& utn_getCuit(cuit, "Ingrese cuit: ", "Cuit invalido ", 4) == 1
			&& utn_getText(direccion, 20, "Ingrese direccion: ",
					"Direccion invalida ", 4) == 1) {
		auxLocalidad = IngresarLocalidad(listaLocalidad, tamLocalidad);
		if (auxLocalidad != 0) {
			unCliente.idCliente = GenerarIdCliente();
			strncpy(unCliente.nombreEmpresa, nombre, 20);
			strncpy(unCliente.cuit, cuit, 20);
			strncpy(unCliente.direccion, direccion, 20);
			unCliente.idLocalidad = auxLocalidad;
			unCliente.isEmpty = FULL;
		}
	}
	return unCliente;
}
/// \fn int BajaCliente(eCliente[], int)
/// \brief Da de baja un cliente logicamente utilizando el espacio isEmpty
/// \param listaClientes La lista de clientes a dar de baja
/// \param tamClientes El tamaño de la lista de clientes
/// \return -1 hubo error 0 si se dio de baja correctamente
int BajaCliente(eCliente listaClientes[], int tamClientes) {
	int retorno = -1;
	int opcion;
	int posicion;
	int id;
	if (listaClientes != NULL && tamClientes > 0) {
		if (utn_getInt(&id, 100, "Ingrese el id que desea dar de baja: ",
				"Id invalido ", 1, 1000000, 4, 0) == 1) {
			if (BuscarIdCliente(listaClientes, tamClientes, id, &posicion)
					== -1) {
				printf("\nNo existe este ID");
			} else {
				printf("Usted va a dar de baja a: %d %-15s\n",
						listaClientes[posicion].idCliente,
						listaClientes[posicion].nombreEmpresa);
				if (utn_getInt(&opcion, 2, "Esta Seguro?: 1->SI 0-> NO ",
						"Id invalido ", 0, 1, 4, 0) == 1) {
					if (opcion == 1) {
						printf("Usted dio de baja a: %d %-15s\n",
								listaClientes[posicion].idCliente,
								listaClientes[posicion].nombreEmpresa);
						listaClientes[posicion].isEmpty = EMPTY;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}
/// \fn int ModificarCliente(eCliente[], int, eLocalidad[], int)
/// \brief Modifica la localidad y la direccion de un cliente
/// \param listaClientes La lista de clientes a modificar
/// \param tamClientes El tamaño de la lista de clientes
/// \param listaLocalidad La lista de localidades
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si hubo error 0 si se modifico correctamente
int ModificarCliente(eCliente listaClientes[], int tamClientes,
		eLocalidad listaLocalidad[], int tamLocalidad) {
	int retorno = -1;
	int posicion;
	char direccion[20];
	char auxLocalidad[20];
	int auxIdlocalidad;
	int opcion;
	int id;
	if (listaClientes != NULL && tamClientes > 0) {
		ListarCliente(listaClientes, listaLocalidad, tamClientes, tamLocalidad);
		if (utn_getInt(&id, 100, "Ingrese el id que desea modificar: ",
				"Id invalido ", 1, 1000000, 4, 0) == 1) {
			if (BuscarIdCliente(listaClientes, tamClientes, id, &posicion)
					== -1) {
				printf("No existe este ID\n");
			} else {
				NombrePorIdLocalidad(auxLocalidad, listaLocalidad, tamLocalidad,
						listaClientes[posicion].idLocalidad);
				printf("Usted va a modificar a:\n ID: %-3d\n Nombre: %-15s\n Direccion: %-15s\n Localidad: %-15s\n",
						listaClientes[posicion].idCliente,
						listaClientes[posicion].nombreEmpresa,
						listaClientes[posicion].direccion, auxLocalidad);
				if (utn_getText(direccion, 20, "Ingrese nueva direccion: ",
						"Direccion invalida ", 4) == 1) {
					auxIdlocalidad = IngresarLocalidad(listaLocalidad,
							tamLocalidad);
					if (utn_getInt(&opcion, 2, "Esta Seguro?: 1->SI 0-> NO ",
							"Id invalido ", 0, 1, 4, 0) == 1) {
						if (auxIdlocalidad != 0 && opcion == 1) {
							strncpy(listaClientes[posicion].direccion,
									direccion, 20);
							listaClientes[posicion].idLocalidad =
									auxIdlocalidad;
							printf("Modificado correctamente\n");
						}
					}
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/// \fn int ListarCliente(eCliente[], eLocalidad[], int, int)
/// \brief Lista los clientes con su localidad
/// \param listaClientes La lista de clientes a mostrar
/// \param listaLocalidad La lista de localidades a mostrar
/// \param tamClientes El tamaño de la lista de clientes
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return -1 si no hay elementos en la lista 0 si los hay
int ListarCliente(eCliente listaClientes[], eLocalidad listaLocalidad[],
		int tamClientes, int tamLocalidad) {
	int retorno;
	char nombreLocalidad[120];
	retorno = -1;
	if (listaClientes != NULL && listaLocalidad != NULL && tamClientes >= 0
			&& tamLocalidad >= 0) {
		printf(" ___ _______________ ____________________ _______________ _______________ \n");
		printf("|ID |    Nombre     |       Cuit         |   Direccion   |   Localidad   |\n");
		for (int i = 0; i < tamClientes; i++) {
			if (listaClientes[i].isEmpty == FULL) {
				NombrePorIdLocalidad(nombreLocalidad, listaLocalidad,
						tamLocalidad, listaClientes[i].idLocalidad);
				MostrarCliente(listaClientes[i], nombreLocalidad);
			}
		}
	}
	return retorno;
}
/// \fn int InicialilarListaCliente(eCliente[], int)
/// \brief Inicializa la lista de clientes usando el patron logico de isEmpty
/// \param listaClientes La lista de clientes a inicializar
/// \param tamClientes El tamaño de la lista de clientes
/// \return -1 si hubo error 0 si se inicio correctamente
int InicialilarListaCliente(eCliente listaClientes[], int tamClientes) {
	int retorno = -1;
	if (listaClientes != NULL && tamClientes > 0) {
		for (int i = 0; i < tamClientes; i++) {
			listaClientes[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
/// \fn void MostrarCliente(eCliente, char[])
/// \brief Muestra un cliente con su localidad
/// \param unCliente El cliente a mostrar
/// \param nombreLocalidad El nombre de la localidad a mostrar
void MostrarCliente(eCliente unCliente, char nombreLocalidad[]) {
	printf("|%-3d|%-15s|%-20s|%-15s|%-20s|\n", unCliente.idCliente,
			unCliente.nombreEmpresa, unCliente.cuit, unCliente.direccion,
			nombreLocalidad);
}
/// \fn int BuscarIsEmpty(eCliente[], int, int*)
/// \brief Busca el espacio en la lista de clientes
/// que este empty y retorna su posicion por puntero
/// \param listaClientes La lista de clientes a buscar
/// \param tamClientes El tamaño de la lista de clientes
/// \param posicion La posicion en donde se encuentre vacio
/// \return -1 si hubo error 0 si se encontro
int BuscarIsEmpty(eCliente listaClientes[], int tamClientes, int *posicion) {
	int retorno = -1;
	int i;
	if (listaClientes != NULL && tamClientes >= 0 && posicion != NULL) {
		for (i = 0; i < tamClientes; i++) {
			if (listaClientes[i].isEmpty == EMPTY) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}
/// \fn int BuscarIdCliente(eCliente[], int, int, int*)
/// \brief Busca el id de un cliente y devuelve su posicion por puntero
/// \param listaClientes La lista de clientes a buscar
/// \param tamClientes El tamaño de la lista de clientes
/// \param valorBuscado El id a buscar
/// \param posicion La posicion a buscar
/// \return -1 si hubo error 0 si lo encontro
int BuscarIdCliente(eCliente listaClientes[], int tamClientes, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (listaClientes != NULL && tamClientes >= 0) {
		for (i = 0; i < tamClientes; i++) {
			if (listaClientes[i].isEmpty == FULL) {
				if (listaClientes[i].idCliente == valorBuscado) {
					retorno = 0;
					*posicion = i;
				}
			}
		}
	}
	return retorno;
}
/// \fn void MostrarLocalidad(eLocalidad)
/// \brief Muestro una localidad
/// \param unaLocalidad La localidad a mostrar
void MostrarLocalidad(eLocalidad unaLocalidad) {
	printf("|%-3d|%-15s|\n", unaLocalidad.idLocalidad, unaLocalidad.nombre);
}
/// \fn int IngresarLocalidad(eLocalidad[], int)
/// \brief Ingresa una localidad por un id que debe ser ingresado
/// \param listaLocalidad La lista de localidades
/// \param tamLocalidad El tamaño de la lista de localidades
/// \return 0 si hubo error O el idLocalidad ingresado
int IngresarLocalidad(eLocalidad listaLocalidad[], int tamLocalidad) {
	int auxLocalidad;
	if (listaLocalidad != NULL && tamLocalidad >= 0) {
		printf(" ___ _______________ \n");
		printf("|ID |Nombre         |\n");
		for (int i = 0; i < tamLocalidad; i++) {
			MostrarLocalidad(listaLocalidad[i]);
		}
		if (utn_getInt(&auxLocalidad, 20, "Ingrese la id de la localidad: ",
				"id invalido ", 1, 4, 4, 0) != 1) {
			auxLocalidad = 0;
		}
	}
	return auxLocalidad;
}
/// \fn int BuscarIdLocalidad(eLocalidad[], int, int, int*)
/// \brief Busca el id de la localidad
/// segun un parametro a buscar y la devuelve a modo puntero
/// \param listaLocalidad La lista de localidades a buscar
/// \param tamLocalidad El tamaño de la lista de localidad
/// \param valorBuscado El parametro a buscar
/// \param posicion La posicion donde se encuentra
/// \return -1 si hubo error 0 si logro encontrarla
int BuscarIdLocalidad(eLocalidad listaLocalidad[], int tamLocalidad,
		int valorBuscado, int *posicion) {
	int retorno = -1;
	int i;
	if (listaLocalidad != NULL && tamLocalidad >= 0) {
		for (i = 0; i < tamLocalidad; i++) {
			if (listaLocalidad[i].isEmpty == FULL) {
				if (listaLocalidad[i].idLocalidad == valorBuscado) {
					retorno = 0;
					*posicion = i;
				}
			}
		}
	}
	return retorno;
}
/// \fn int GenerarIdCliente()
/// \brief Genera un id de cliente auto incremental
/// \return El id generado
int GenerarIdCliente() {
	static int contador = 0;
	contador++;
	return contador;
}
/// \fn int ClientesTotales(eCliente[], int)
/// \brief Cuenta cuantos clientes hay en la lista
/// \param listaClientes La lista de clientes a contrar
/// \param tamClientes El tamaño de la lista de clientes
/// \return La cantidad de clientes
int ClientesTotales(eCliente listaClientes[], int tamClientes) {
	int acumulador;
	acumulador = 0;
	if (listaClientes != NULL && tamClientes) {
		for (int i = 0; i < tamClientes; i++) {
			if (listaClientes[i].isEmpty == FULL) {
				acumulador++;
			}
		}
	}
	return acumulador;
}
/// \fn eCliente ObtenerClientePorId(eCliente[], int, int)
/// \brief Obtiene el cliente por el id
/// \param listaClientes La lista de clientes a obtener
/// \param tamCliente El tamaño de la lista de clientes
/// \param id El id para buscar
/// \return el cliente obtenido
eCliente ObtenerClientePorId(eCliente listaClientes[], int tamCliente, int id) {
	eCliente aux;
	if (listaClientes != NULL && tamCliente >= 0 && id >= 0) {
		for (int i = 0; i < tamCliente; i++) {
			if (listaClientes[i].isEmpty == FULL
					&& listaClientes[i].idCliente == id) {
				aux = listaClientes[i];
				break;
			}
		}
	}
	return aux;
}
/// \fn int NombrePorIdLocalidad(char[], eLocalidad[], int, int)
/// \brief Busca el nombre de la localidad por su id
/// \param nombre El nombre a buscar
/// \param listaLocalidad La lista de localidades a buscar
/// \param tamLocalidad El tamaño de la lista de localidades
/// \param idLocalidad El id de la localidad que se busca
/// \return -1 si hubo error 0 si la encontro
int NombrePorIdLocalidad(char nombre[], eLocalidad listaLocalidad[],
		int tamLocalidad, int idLocalidad) {
	int retorno = -1;
	if (listaLocalidad != NULL && nombre != NULL && tamLocalidad >= 0
			&& idLocalidad >= 0) {
		for (int i = 0; i < tamLocalidad; i++) {
			if (listaLocalidad[i].isEmpty == FULL
					&& listaLocalidad[i].idLocalidad == idLocalidad) {
				strcpy(nombre, listaLocalidad[i].nombre);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/// \fn void MostrarClienteCantidad(eCliente, char[], int)
/// \brief Muestra un cliente con la cantidad de pedidos
/// \param unCliente El cliente a mostrar
/// \param nombreLocalidad El nombre de la localidad a mostrar
/// \param cantidad La cantidad a mostrar
void MostrarClienteCantidad(eCliente unCliente, char nombreLocalidad[],
		int cantidad) {
	printf("|%-3d|%-15s|%-20s|%-15s|%-15s|%-10d|\n", unCliente.idCliente,
			unCliente.nombreEmpresa, unCliente.cuit, unCliente.direccion,
			nombreLocalidad, cantidad);
}
