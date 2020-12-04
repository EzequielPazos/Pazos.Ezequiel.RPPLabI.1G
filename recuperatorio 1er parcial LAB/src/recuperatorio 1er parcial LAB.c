/*
 ============================================================================
 Name        : recuperatorio.c
 Author      : Pazos Ezequiel
 Description : recuperatorio 1er parcial LAB
 ============================================================================
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

int main(void) {

	setbuf(stdout, NULL);

	int opcionDeseada;
	char seguir = 's';
	char confirmacion;
	int proximoIdCliente = 1;
	int proximoIdAlquiler = 1;
	int flagPrimerAlta = 0;
	int flagPrimerAlquiler = 0;
	int rta;

	eCliente listaClientes[TAM];
	eAlquiler listaAlquileres[TAM];
	eEquipo listaEquipos[TAM_E] =
	{
			{1000, "AMOLADORA"},
			{1001, "MEZCLADORA"},
			{1002, "TALADRO"},
	};
	eOperador listaOperadores[TAM_O] =
	{
			{1000, "GUILLERMO"},
			{1001, "ELVIO"},
			{1002, "CANDELA"},
	};

	do{
		opcionDeseada = menuAlquilerDeMaquinaria(); //Muestra menu de opciones

		switch(opcionDeseada)
		{
			case 'a': //alta clientes
	        	if(altaCliente(listaClientes, TAM, proximoIdCliente) == 0)
				{
					proximoIdCliente++;
					printf("\n\n >>>Alta exitosa!<<<\n\n");
					flagPrimerAlta = 1;
				}else
				{
					printf("\n\n>>>Problemas para realizar el alta\n\n");
				}
				break;
			case 'b': //modificacion de clientes
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede modificar nada ya que todavia no se ha dado ningun alta!<<<\n\n");
				}else if(modificarCliente(listaClientes, TAM) == 0)
				{
					printf("\n\n >>>Modificacion exitosa!<<<\n\n");
				}else
				{
					printf("\n\n >>>Se ha producido un error en la modificacion<<<\n\n");
				}
				break;
			case 'c': //baja clientes
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede dar de baja ningun cliente ya que todavia no se ha dado ninguno de alta!<<<\n\n");
				}else
				{
					rta = bajaCliente(listaClientes, TAM);
					if(rta == 0)
					{
						printf("\n\n >>>Baja exitosa!<<<\n\n");
					}else if(rta == 2)
					{
						printf("\n\n >>>La baja se ha cancelado por el usuario<<< \n\n");
					}else
					{
						printf("\n\n >>>Se ha producido un error en la baja<<<\n\n");
					}
				}
				break;
			case 'd':
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede dar de alta ningun alquiler ya que todavia no se ha dado ningun cliente de alta!<<<\n\n");
				}else
				{
		        	if(nuevoAlquiler(listaAlquileres, listaClientes, listaEquipos, listaOperadores, proximoIdAlquiler, TAM, TAM_A, TAM_E, TAM_O) == 0)
					{
						proximoIdAlquiler++;
						printf("\n\n >>>Alta exitosa!<<<\n\n");
						flagPrimerAlquiler = 1;
					}else
					{
						printf("\n\n>>>Problemas para realizar el alta\n\n");
					}
				}

	        	break;
			case 'e': //fin alquiler
				if(flagPrimerAlquiler == 0)
				{
					printf("\n\n>>>No se puede finalizar ningun alquiler ya que todavia no se ha dado ninguno de alta!<<<\n\n");
				}else
				{
					rta = finAlquiler(listaAlquileres, TAM_A);
					if(rta == 0)
					{
						printf("\n\n >>>Baja exitosa!<<<\n\n");
					}else if(rta == 2)
					{
						printf("\n\n >>>La baja se ha cancelado por el usuario<<< \n\n");
					}else
					{
						printf("\n\n >>>Se ha producido un error en la baja<<<\n\n");
					}
				}
				break;
			case 'f': //informar tiempo promedio real alquileres
				if(flagPrimerAlquiler == 0)
				{
					printf("\n\n>>>No se puede informar nada ya que todavia no se ha dado ninguna de alta ningun alquiler!<<<\n\n");
				}else
				{
					if(promedioRealAlquiler(listaAlquileres, TAM_A)==0)
					{
						printf("\n>>> promedio mostrado con exito! <<<\n\n");
					}else
					{
						printf("\n>>> Error al intentar mostrar el promedio <<<\n\n");
					}
				}
				break;
			case 'z': //salir
				printf("Confirma que quiere salir? Ingrese s/n\n"); //falta validar que lo que ingresa sea una letra
				fflush(stdin);
				scanf("%c", &confirmacion);
				confirmacion = tolower(confirmacion);
				while(confirmacion != 's' && confirmacion != 'n')
				{
					printf("La respuesta ingresada no es valida. Ingrese s/n\n");
					fflush(stdin);
					scanf("%c", &confirmacion);
					confirmacion = tolower(confirmacion);
				}
				if(confirmacion == 's')
				{
					seguir = 'n';
				}
				break;
			default: //validacion de las otra letras elegidas
				printf("\n>>> La opcion elegida es invalida! <<<\n");
				break;
		}

		system("pause");
	}while(seguir == 's');

	return EXIT_SUCCESS;
}

char menuAlquilerDeMaquinaria()
{
	char opcion;

	system("cls");

	printf("========== ALQUILER MAQUINARIA ==========\n\n");
	printf("A. ALTA DEL CLIENTE\n");
	printf("B. MODIFICAR DATOS DEL CLIENTE\n");
	printf("C. BAJA DEL CLIENTE\n");
	printf("D. NUEVO ALQUILER\n");
	printf("E. FIN DEL ALQUILER\n");
	printf("F. INFORMAR\n");
	printf("Z. SALIR\n\n");
	printf("Ingrese la opcion deseada: ");
	fflush(stdin);
	opcion = tolower(getchar());

	return opcion;
}

