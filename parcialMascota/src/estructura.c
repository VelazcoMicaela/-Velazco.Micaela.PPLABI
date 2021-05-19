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
//#include "informes.h"
#include "color.h"
#include "fecha.h"
#include "mascota.h"
#include "tipo.h"
#include "trabajo.h"
#include "servicio.h"


#define TAM 10
#define TAMCOL 5
#define TAMTIP 5
#define TAMTRAB 15
#define TAMSER 3

int main(void) {
	setbuf(stdout,NULL);

	eMascota mascota[TAM];
	eTrabajo trabajo[TAMTRAB];
	int respuesta;
	int opcion;
	char salir;
	int pIdMas=2000;
	int pIdTrab=3000;
	//int error;

	eColor color[TAMCOL]=
	{
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Gris"},
			{5003, "Rojo"},
			{5004, "Azul"}
	};

	eTipo tipo[TAMTIP]=
	{
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Gato"},
			{1003, "Roedor"},
			{1004, "Pez"}
	};

	eServicio servicios[TAMSER]=
	{
			{100, "Corte",250},
			{101, "Desparasitado",300},
			{102, "Castrado",400}
	};


	if(inicializarMascota(mascota, TAM)==0)
	{
		printf("LISTA INICIALIZADA EMPLEADOS----  ");
	}

	if(inicializarTrabajo(trabajo, TAMTRAB)==0)
	{
		printf("LISTA INICIALIZADA ALMUERZOS\n");
	}

	if(hardcodearMascota(mascota, TAM, 8, &pIdMas)>0)//numero cantidad de empleados q van a entrar hardcodeado
	{
		printf("Hardcodeo mascota cargado --------  ");
	}

	if(hardcodearTrabajo(trabajo, TAMTRAB, 5, &pIdTrab)>0)//numero cantidad de almuerzos q van a entrar hardcodeado
	{
		printf("Hardcodeo trabajo cargado\n");
	}

	do
	{
		printf("\n**** ABM MASCOTAS ****");
		respuesta=utn_getNumeroEnteroConIntentos(&opcion, "\nSeleccione una opcion\n 1-Alta empleado \n 2-Baja empleado\n 3-Modificar empleado\n 4-Listar empleado\n "
				"5-Ordenar empleado\n 6-Mostrar sector \n 7-Informes\n 8-Mostrar por sectores\n 9-Mostrar sector que mas gana \n 10-TOtal a depositar\n 11-Mostrar Almuerzos\n "
				"12-Mostrar Comidas\n 13-Alta Almuerzo\n 14-Baja Almuerzo\n 15-Modificar Almuerzo\n 16-Mostrar Almuerzos de un empleado\n20-Salir\n", "ERROR no es una opcion valida\n", 1, 20, 5);

		if(respuesta==0)
		{
			switch(opcion)
			{
				case 1:
					printf("Alta empleado\n");

					if(cargarMascota(mascota, TAM,&pIdMas,color,TAMCOL)==0)
					{
						printf("Carga exitosa\n");
					}
					break;

				case 2:
					if(bajaMascota(mascota, TAM,color,TAMCOL)==0)
					{
						mostrarArrayMascota(mascota, TAM,color,TAMCOL);
						printf("Baja exitosa\n");
					}
					break;

				case 3:
					printf("Modificar empleado\n");
					modificarMascota(mascota, TAM);
					break;

				case 4:
					mostrarArrayMascota(mascota,TAM,color,TAMCOL);
					break;

				case 5:
					printf("ORDENAR\n");
					if(ordenarArrayMascota(mascota, TAM)==0)
					{
						mostrarArrayMascota(mascota,TAM,color,TAMCOL);
					}
					break;

				case 6:
					printf("MOSTRAR SECTORES\n");
					mostrarArrayColore(color,TAMCOL);
					break;

				case 7:

					if(listarEmpleadosColor(color,TAMCOL, mascota,TAM)==0)
					{
						printf("\n");
					}

					break;

				case 8:
					if(mostrarSectoresYEmpleados(color, TAMCOL, mascota,TAM)==0)
					{
						printf("\n");
					}

					break;

				case 9:
					if(sectorMayorSueldo(color,TAMCOL, mascota,TAM)==0)
					{
						printf("\n");
					}
					break;

				case 10:
					if(totalADepositar(color,TAMCOL, mascota,TAM)==0)
					{
						printf("\n");
					}
					break;

				case 11:
					printf("ALMUERZOS\n");
					if(mostrarArrayTrabajo(trabajo, tipo, TAMTRAB, TAMTIP,mascota, TAM)==0)
					{
						printf("----------------------------------------------------------\n");
					}
					break;

				case 12:
					printf("COMIDA\n");
					if(mostrarArrayTipo(tipo, TAMTIP)==0)
					{
						printf("----------------------------------------------------------\n");
					}
					break;

				case 13:
					printf("ALTA ALMUERZO\n");
					if(cargarTrabajo(trabajo, TAMTIP, &pIdTrab, tipo, TAMTRAB)==0)
					{
						if(mostrarArrayTrabajo(trabajo, tipo, TAMTRAB, TAMTIP, mascota, TAM)==0)
						{
							printf("----------------------------------------------------------\n");
						}

					}
					break;

				case 14:
					printf("BAJA ALMUERZO\n");
					if(bajaTrabajo(trabajo, TAMTIP, tipo, TAMTRAB, mascota, TAM)==0)
					{
						if(mostrarArrayTrabajo(trabajo, tipo, TAMTRAB, TAMTIP, mascota, TAM)==0)
						{
							printf("Baja exitosa\n");
							printf("----------------------------------------------------------\n");
						}
					}

					break;

				case 15:
					printf("MODIFICAR ALMUERZO\n");
					if(modificarTrabajo(trabajo, TAMTRAB, tipo, TAMTIP, mascota, TAM)==0)
					{
						if(mostrarArrayTrabajo(trabajo, tipo, TAMTRAB, TAMTIP, mascota, TAM)==0)
						{
							printf("Modificacion exitosa\n");
							printf("----------------------------------------------------------\n");
						}

					}
					break;

				case 16:
					printf("MOSTRAR ALMUERZOS DE UN EMPLEADO\n");
					if(mostrarAlmuerzoEmpleado(mascota, TAM, trabajo, TAMTRAB, color, TAMCOL, tipo, TAMTIP)==0)
					{
						printf("----------------------------------------------------------\n");
					}
					break;

				case 20:
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


