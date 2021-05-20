/*
 ============================================================================
 Name        : estructura.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "servicio.h"
#include "trabajo.h"


#define TAM 11
#define TAMTIP 5
#define TAMCOL 5
#define TAMSER 3
#define TAMTRAB 15

int main(void) {
	setbuf(stdout,NULL);

	eMascota mascota[TAM];
	eTrabajo trabajo[TAMTRAB];

	int respuesta;
	int opcion;
	char salir;
	int idMascota=4000;
	int idTrabajo=3000;
	//int error;

	eTipo tipo[TAMTIP]=
	{
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Gato"},
			{1003, "Roedor"},
			{1004, "Pez"}
	};

	eColor color[TAMCOL]=
		{
				{5000, "Negro"},
				{5001, "Blanco"},
				{5002, "Gris"},
				{5003, "Rojo"},
				{5004, "Azul"}
		};

	eServicio servicio[TAMSER]=
		{
				{2000, "Corte",250},
				{2001, "Desparasitado",300},
				{2002, "Castrado",400},
		};

	if(inicializarMascota(mascota, TAM)==0)
	{
		printf("LISTA MASCOTA INICIALIZADA ------- ");
	}

	if(inicializarTrabajo(trabajo, TAMTRAB)==0)
	{
		printf(" LISTA TRABAJO INICIALIZADA\n");
	}

	if(hardcodearMascota(mascota, TAM, 10, &idMascota)>0)//numero cantidad de mascota q van a entrar hardcodeado
	{
		printf(" Hardcodeo  mascota cargado ------ ");
	}

	if(hardcodearTrabajo(trabajo, TAMTRAB, 10, &idTrabajo)>0)//numero cantidad de trabajo q van a entrar hardcodeado
	{
		printf(" Hardcodeo trabajo cargado\n");
	}


	do
	{
		printf("\n**** ABM MASCOTA ****");
		respuesta=utn_getNumeroEnteroConIntentos(&opcion, "\nSeleccione una opcion\n 1-Alta Mascota\n 2-Modificar Mascota \n 3-Baja Mascota\n 4-Listar Mascota\n "
				"5-Listar Tipos\n 6-Listar Color \n 7-Listar Servicios\n 8-Alta Trabajo\n 9-Listar Trabajo\n 12-Salir ", "ERROR no es una opcion valida\n", 1, 12, 5);

		if(respuesta==0)
		{
			switch(opcion)
			{
				case 1:
					printf("-----Alta Mascota-----\n");

					if(cargarMascota(mascota, TAM,&idMascota,tipo,TAMTIP, color, TAMCOL)==0)
					{
						if(mostrarArrayMascota(mascota, TAM, tipo, TAMTIP, color, TAMCOL)==0)
						{
							printf("Carga exitosa\n");
						}

					}
					break;

				case 3:
					printf("-----Baja Mascota-----\n");
					if(bajaMascota(mascota, TAM,tipo,TAMTIP, color, TAMCOL)==0)
					{
						printf("Baja exitosa\n");
					}
					break;

				case 2:
					printf("-----Modificar Mascota-----\n");
					if(modificarMascota(mascota,TAM,tipo,TAMTIP, color, TAMCOL)==0)
					{
						printf("Modificacion exitosa\n");
					}
					else
					{
						printf("Cancelacion exitosa\n");
					}
					break;

				case 4:
					printf("-----Listar Mascota-----\n");
					mostrarArrayMascota(mascota,TAM,tipo,TAMTIP, color, TAMCOL);
					break;

				case 5:
					printf("-----Listar Tipo-----\n");
					if(mostrarArrayTipo(tipo, TAMTIP)==0)
					{
						printf("\n");
					}
					break;

				case 6:
					printf("-----Listar Colores-----\n");
					if(mostrarArrayColor(color, TAMCOL)==0)
					{
						printf("\n");
					}
					break;

				case 7:
					printf("-----Listar Servicios-----\n");
					if(mostrarArrayServicio(servicio, TAMSER)==0)
					{
						printf("\n");
					}

					break;

				case 8:
					printf("-----Alta Trabajo-----\n");
					if(cargarTrabajo(trabajo, TAMTRAB, &idTrabajo, servicio, TAMSER, mascota, TAM, tipo, TAMTIP, color, TAMCOL)==0)
					{
						if(mostrarArrayTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
						{
							printf("Carga exitosa\n");
						}
					}
					break;


				case 9:
					printf("-----Listar Trabajo-----\n");
					if(mostrarArrayTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
					{
						printf("\n");
					}
					break;

				case 12:
					printf("salir?\n");
					if(utn_getCaracterCorroboraDosCarac(&salir, "Desea salir? S/N\n", "ERROR Ingrese S para salir o N para quedarse", 's', 'n')==0)
					{
						if(salir=='s')
						{
							printf("Gracias, adios");
						}
					}
					break;

				system("pause");
			}
		}
	}while(salir!='s');


	return EXIT_SUCCESS;
}


