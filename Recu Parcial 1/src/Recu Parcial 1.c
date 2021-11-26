#include "Informes.h"
#define TAMCLIENTE 100
#define TAMPEDIDO 1000
#define TAMLOCALIDAD 4
int main(void) {
	setbuf(stdout, NULL);
	eCliente listaClientes[TAMCLIENTE];
	eLocalidad listaLocalidad[TAMLOCALIDAD] = { { 1, "Avellaneda", FULL }, { 2,
			"Lanus", FULL }, { 3, "CABA", FULL }, { 4, "Burzaco", FULL } };
	ePedido listaPedido[TAMPEDIDO];
	InicialilarListaCliente(listaClientes, TAMCLIENTE);
	InicializaPedido(listaPedido, TAMPEDIDO);
	MenuOpciones(listaPedido, listaClientes, listaLocalidad, TAMPEDIDO,
	TAMCLIENTE, TAMLOCALIDAD);
	return 0;
}
