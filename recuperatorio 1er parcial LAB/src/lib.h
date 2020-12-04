/*
 * lib.h
 *
 *  Created on: 3 dic. 2020
 *      Author: EZE_XD
 */

#ifndef LIB_H_
#define LIB_H_

typedef struct
{
	int id;
	int idCliente;
	int equipo;
	int estado;
	int operador;
	int tiempoEstimadoAlquiler;
	int tiempoRealAlquiler;
} eAlquiler;

typedef struct
{
	int id;
	int dni;
	char nombre[20];
	char apellido[20];
	int isEmpty;
}eCliente;

typedef struct
{
	int id;
	char descripcion[20];
}eEquipo;

typedef struct
{
	int id;
	char nombre[20];
}eOperador;

#endif /* LIB_H_ */

char menuAlquilerDeMaquinaria();
int inicializarClientes(eCliente clientes[], int tam);
int buscarLibreClientes(eCliente clientes[], int tam);
int altaCliente(eCliente clientes[], int idCliente, int tam);
void mostrarCliente(eCliente unCliente);
int mostrarClientes(eCliente clientes[], int tam);
int buscarCliente(eCliente clientes[], int tam, int idCliente);
int modificarCliente(eCliente clientes[], int tam);
int bajaCliente(eCliente clientes[], int tam);
int buscarLibreAlquileres(eAlquiler alquileres[], int tam_a);
int mostrarEquipos(eEquipo equipos[], int tam_e);
int mostrarOperadores(eOperador operadores[], int tam_o);
int nuevoAlquiler(eAlquiler alquileres[], eCliente clientes[], eEquipo equipos[], eOperador operadores[], int proximoIdAlquiler, int tam_a, int tam, int tam_e, int tam_o);
int buscarAlquiler(eAlquiler alquileres[], int tam_a, int idAlquiler);
void mostrarAlquiler(eAlquiler unAlquiler);
int mostrarAlquileres(eAlquiler alquileres[], int tam_a);
int finAlquiler(eAlquiler alquileres[], int tam_a);
int asociadoMasAlquileres(eOperador operadores[], eAlquiler alquileres[], int tam, int tam_a);
int promedioRealAlquiler(eAlquiler alquileres[], int tam_a);
