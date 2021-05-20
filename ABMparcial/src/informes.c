/*
 * informes.c
 *
 *  Created on: 10 may. 2021
 *      Author: Asus
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


#define LLENO 0
#define VACIO 1

int recorrerYMostrarListaTipo(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, int id, float* acomulador)
{
	int error=-1;
	int flag=-1;

	if(tipo!=NULL && lenTip>0 && mascota!=NULL && lenMas>0 && id>0)
	{
		printf("\n    SECTOR %d\n",id);
		printf("Legajo     Nombre  Edad Sexo    Sueldo   F. Ingreso  Sector Descripcion\n");
		for(int i=0; i<lenMas; i++)
		{
			if(mascota[i].idTipo==id&& mascota[i].isEmpty==LLENO)
			{

				*acomulador=mascota[i].edad+*acomulador;
				flag=0;
			}
		}
		if(flag==-1)
		{
			printf("No hay empleado en este sector\n");
		}
		error=0;
	}

	return error;
}


int mostrarTipoYMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas)
{
	int error=-1;
	float total;

	if(tipo!=NULL&& mascota!=NULL && lenTip>0&& lenMas>0)
	{
		for(int i=0; i<lenTip; i++)
		{
			if(recorrerYMostrarListaTipo(tipo, lenTip, mascota, lenMas, tipo[i].id,&total)==0)
			{
				printf("\n");
			}
		}
		error=0;
	}

	return error;
}

