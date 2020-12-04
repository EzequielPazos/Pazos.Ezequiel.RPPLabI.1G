/*
 * lib.c
 *
 *  Created on: 3 dic. 2020
 *      Author: Ezequiel Pazos
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"
#define TAM 100
#define TAM_E 3
#define TAM_O 3
#define TAM_A 200
#define ALQUILADO 0
#define FINALIZADO 1

int inicializarClientes(eCliente clientes[], int tam)
{
	int error = -1; //falla

	if(clientes != NULL && tam > 0) //verifico si el array esta vacio y si el tamanio de este es mayor a 0
	{
		for(int i=0;i<tam;i++) //recorro array de clientes
		{
			clientes[i].isEmpty = 1; //asigno todos los clientes como vacios
		}
		error = 0; //no hubo errores
	}

	return error;
}

int buscarLibreClientes(eCliente clientes[], int tam)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(clientes[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int altaCliente(eCliente clientes[], int idCliente, int tam)
{
	int error = 1; //falla en el alta
	int indice;
	eCliente nuevoCliente;

	if(clientes !=NULL && tam>0 && idCliente>0)
	{
		system("cls");
		printf("========== ALTA DE CLIENTES ==========\n\n");
		indice = buscarLibreClientes(clientes, tam);

		if(indice==-1) //error sistema completo
		{
			printf("     >>> El sistema esta completo <<<");
		}else
		{
			nuevoCliente.id = idCliente;
			printf("Ingrese el nombre: "); //ingreso del nombre
			fflush(stdin);
			gets(nuevoCliente.nombre);

			printf("Ingrese el apellido: "); //ingreso del apellido
			fflush(stdin);
			gets(nuevoCliente.apellido);

			printf("\nIngrese el DNI: ");  //ingreso del dni
			scanf("%d", &nuevoCliente.dni);

			nuevoCliente.isEmpty = 0;
			clientes[indice] = nuevoCliente;
			printf("\n>Se ha ingresado el cliente al sistema con exito!");
		}
		error = 0;
	}
	return error;
}

void mostrarCliente(eCliente unCliente)
{
	printf("%d %d %20s %20s\n", unCliente.id, unCliente.dni, unCliente.nombre, unCliente.apellido);
}

int mostrarClientes(eCliente clientes[], int tam)
{
	int error = 1;
	int flag = 0;

	if(clientes !=NULL && tam>0)
	{
		printf("  ID  DNI  NOMBRE  APELLIDO \n");
		printf("----------------------------------------\n");

		for(int i=0; i<tam; i++)
		{
			if(clientes[i].isEmpty == 0)
			{
				mostrarCliente(clientes[i]);
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("  No hay ningun cliente en la lista!");
		}
		printf("\n\n");

		error = 0;
	}
	return error;
}

int buscarCliente(eCliente clientes[], int tam, int idCliente)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(clientes[i].id == idCliente)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int modificarCliente(eCliente clientes[], int tam)
{
	int error = 1;
	int idCliente;
	int indice;
	char opcion;
	char seguir = 's';

	if(clientes != NULL && tam > 0)
	{
		system("cls");
		printf("========== MODIFICACION CLIENTES ==========\n\n");
		mostrarClientes(clientes,tam);
		printf(">Ingrese el ID del cliente que desea modificar: ");
		scanf("%d", &idCliente);

		indice = buscarCliente(clientes, tam, idCliente);

		if(indice == -1)
		{
			printf("\n>>> No existe un cliente con esa ID! <<<\n\n");
		}else
		{
			mostrarCliente(clientes[indice]);

			do{
				printf("\n===== MODIFICACIONES =====\n\n");
				printf("A ---> NOMBRE\n");
				printf("B ---> APELLIDO\n\n");
				printf("Z ---> Volver atras\n\n");
				scanf("%c", &opcion);
				fflush(stdin);
				opcion = tolower(getchar());

				switch(opcion)
				{
					case 'a':
						printf("\nIngrese el nombre deseado: ");
						fflush(stdin);
						gets(clientes[indice].nombre);
						printf("\n\nEl cambio de nombre ha sido realizado con exito!\n");
						system("pause");
						break;
					case 'b':
						printf("\nIngrese el apellido deseado: ");
						fflush(stdin);
						gets(clientes[indice].apellido);
						printf("\n\nEl cambio de apellido ha sido realizado con exito!\n");
						system("pause");
						break;
					case 'z':
						seguir = 'n';
						break;
					default:
						printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
						system("pause");
						break;
				}
				error = 0;
			}while(seguir == 's');
		}
	}
	return error;
}

int bajaCliente(eCliente clientes[], int tam)
{
	int error = 1; //error en la baja
	int idCliente;
	int indice;
	char confirma;

	if(clientes != NULL && tam > 0)
	{
		system("cls");
		printf("========== BAJA DE CLIENTES ==========\n\n");
		mostrarClientes(clientes, tam);
		printf("Ingrese el ID del cliente: ");
		scanf("%d", &idCliente);

		indice = buscarCliente(clientes, tam, idCliente);

		if(indice == -1)
		{
			printf(">>> No existe un cliente con esa ID! <<<\n\n");
		}else
		{
			mostrarCliente(clientes[indice]);
			printf("Confirma el borrado?: Ingrese s/n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
			while(confirma !='s' && confirma !='n')
			{
				printf("Confirmacion invalida. Ingrese s/n");
				fflush(stdin);
				scanf("%c", &confirma);
				confirma = tolower(confirma);
			}

			if(confirma =='s')
			{
				clientes[indice].isEmpty = 1;
				error = 0; //borrado correctamente
			}else
			{
				error = 2; //no confirma el borrado
			}
		}
	}
	return error;
}

int buscarLibreAlquileres(eAlquiler alquileres[], int tam_a)
{
	int indice = -1;

	for(int i=0;i<tam_a;i++)
	{
		if(alquileres[i].estado == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int mostrarEquipos(eEquipo equipos[], int tam_e)
{
	int error = 1;

	if(equipos !=NULL && tam_e>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO EQUIPOS ==========\n");
		printf("-------------------------------------\n");
		printf("   ID         EQUIPO   \n");
		for(int i=0; i<tam_e; i++)
		{
			printf("  %4d  %20s \n", equipos[i].id, equipos[i].descripcion); //muestro los equipos
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int mostrarOperadores(eOperador operadores[], int tam_o)
{
	int error = 1;

	if(operadores !=NULL && tam_o>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO EQUIPOS ==========\n");
		printf("-------------------------------------\n");
		printf("   ID         EQUIPO   \n");
		for(int i=0; i<tam_o; i++)
		{
			printf("  %4d  %20s \n", operadores[i].id, operadores[i].nombre); //muestro los operadores
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int nuevoAlquiler(eAlquiler alquileres[], eCliente clientes[], eEquipo equipos[], eOperador operadores[], int proximoIdAlquiler, int tam_a, int tam, int tam_e, int tam_o)
{
	int error = 1; //falla en el alta
	int indice;
	eAlquiler nuevoAlquiler;

	if(alquileres !=NULL && clientes !=NULL && tam_a>0 && tam>0 && proximoIdAlquiler>0)
	{
		system("cls");
		printf("========== NUEVO ALQUILER ==========\n\n");
		indice = buscarLibreAlquileres(alquileres, tam_a);

		if(indice==-1) //error sistema completo
		{
			printf("     >>> El sistema esta completo <<<");
		}else
		{
			nuevoAlquiler.id = proximoIdAlquiler;

			mostrarClientes(clientes, tam);
			printf("Ingrese el ID del cliente que ha alquilado: ");
			scanf("%d", &nuevoAlquiler.idCliente); //falta validar idcliente existente

			mostrarEquipos(equipos, tam_e);

			printf("Ingrese el ID del equipo: "); //ingreso del equipo y falta validacion
			scanf("%d", &nuevoAlquiler.equipo);

			printf("Ingrese el tiempo estimado de alquiler en horas: ");
			scanf("%d", &nuevoAlquiler.tiempoEstimadoAlquiler);

			mostrarOperadores(operadores, tam_o);
			printf("Ingrese el ID del operador: "); //ingreso del operador y falta validacion
			scanf("%d", &nuevoAlquiler.operador);

			nuevoAlquiler.estado = ALQUILADO;

			alquileres[indice] = nuevoAlquiler;
			printf("\n>Se ha ingresado el alquiler al sistema con exito!");
		}
		error = 0;
	}
	return error;
}

int buscarAlquiler(eAlquiler alquileres[], int tam_a, int idAlquiler)
{
	int indice = -1;

	for(int i=0;i<tam_a;i++)
	{
		if(alquileres[i].id == idAlquiler)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int obtenerDescripcionEquipo(eEquipo equipos[], int tam, int idEquipo, char descripcion[])
{
	int error = 1; //falla

	if(equipos != NULL && tam > 0 && idEquipo>0 && descripcion !=NULL) //verificacion de nulos y tamanios
	{
		for(int i=0; i<tam; i++)
		{
			if(equipos[i].id == idEquipo) //recorro el array de equipos en la seccion de id buscando coincidencias con mi id
			{
				strcpy(descripcion, equipos[i].descripcion); //copio los datos en descripcion en caso de coincidir
				error = 0;
				break;
			}
		}
	}
	return error;
}

int obtenerNombreOperador(eOperador operadores[], int tam, int idOperador, char nombre[])
{
	int error = 1; //falla

	if(operadores != NULL && tam > 0 && idOperador>0 && nombre !=NULL) //verificacion de nulos y tamanios
	{
		for(int i=0; i<tam; i++)
		{
			if(operadores[i].id == idOperador) //recorro el array de operadores en la seccion de id buscando coincidencias con mi id
			{
				strcpy(nombre, operadores[i].nombre); //copio los datos en nombre en caso de coincidir
				error = 0;
				break;
			}
		}
	}
	return error;
}

void mostrarAlquiler(eAlquiler unAlquiler)
{
		printf("%d %d %d %d %d %d\n", unAlquiler.id, unAlquiler.idCliente, unAlquiler.equipo, unAlquiler.estado, unAlquiler.operador, unAlquiler.tiempoEstimadoAlquiler);
}

int mostrarAlquileres(eAlquiler alquileres[], int tam_a)
{
	int error = 1;
	int flag = 0;

	if(alquileres !=NULL && tam_a>0)
	{
		printf("  ID  ID-CLIENTE  EQUIPO  ESTADO  OPERADOR  ETA  \n");
		printf("-------------------------------------------------\n");

		for(int i=0; i<tam_a; i++)
		{
			if(alquileres[i].estado == ALQUILADO)
			{
				mostrarAlquiler(alquileres[i]);
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("  No hay ningun cliente en la lista!");
		}
		printf("\n\n");

		error = 0;
	}
	return error;
}

int finAlquiler(eAlquiler alquileres[], int tam_a)
{
	int error = 1; //error en la baja
	int idAlquiler;
	int indice;
	char confirma;

	if(alquileres != NULL && tam_a > 0)
	{
		system("cls");
		printf("========== FIN DEL ALQUILER ==========\n\n");
		mostrarAlquileres(alquileres, tam_a);
		printf("Ingrese el ID del alquiler: ");
		scanf("%d", &idAlquiler);

		indice = buscarAlquiler(alquileres, tam_a, idAlquiler);

		if(indice == -1)
		{
			printf(">>> No existe un alquiler con esa ID! <<<\n\n");
		}else
		{
			mostrarAlquiler(alquileres[indice]);

			printf("Ingrese el tiempo real de alquiler en horas: ");
			scanf("%d", &alquileres[indice].tiempoRealAlquiler);

			printf("Confirma la finalizacion del alquiler?: Ingrese s/n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
			while(confirma !='s' && confirma !='n')
			{
				printf("Confirmacion invalida. Ingrese s/n");
				fflush(stdin);
				scanf("%c", &confirma);
				confirma = tolower(confirma);
			}

			if(confirma =='s')
			{
				alquileres[indice].estado = FINALIZADO;
				error = 0; //finalizado correctamente
			}else
			{
				error = 2; //no confirma la finalizacion
			}
		}
	}
	return error;
}

int asociadoMasAlquileres(eOperador operadores[], eAlquiler alquileres[], int tam, int tam_a)
{
	int error = 1;
	int contadorGuillermo = 0;
	int contadorElvio = 0;
	int contadorCandela = 0;

	if(operadores !=NULL && alquileres !=NULL && tam>0 && tam_a>0)
	{
		for(int i=0; i<tam; i++)
		{
			switch(operadores[i].id)
			{
				case 1000:
					contadorGuillermo++;
					break;
				case 1001:
					contadorElvio++;
					break;
				default:
					contadorCandela++;
			}
		}

		if(contadorGuillermo>contadorElvio && contadorGuillermo>contadorCandela)
		{
			printf("El asociado con mas alquileres es Guillermo");
		}else if(contadorElvio>contadorCandela)
		{
			printf("El asociado con mas alquileres es Elvio");
		}else
		{
			printf("La asociada con mas alquileres es Candela");
		}
		error = 0;
	}

	return error;
}

int promedioRealAlquiler(eAlquiler alquileres[], int tam_a)
{
	int error = 1;
	int acumuladorTiempoReal = 0;
	int cantidadAlquileres = 0;
	float promedioTiempoReal;

	for(int i=0; i<tam_a; i++)
	{
		if(alquileres[i].estado == 1)
		{
			acumuladorTiempoReal = acumuladorTiempoReal + alquileres[i].tiempoRealAlquiler;
			cantidadAlquileres++;
		}
	}

	promedioTiempoReal = (float) acumuladorTiempoReal / cantidadAlquileres;

	printf("El promedio del tiempo real es de: %.2f", promedioTiempoReal);

	error = 0;

	return error;
}
