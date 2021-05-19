/*
 * comidas.c
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
 */
#include "tipo.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "color.h"
#include "fecha.h"
#include "mascota.h"
#include "servicio.h"

int mostrarTipo(eTipo tipo)
{
	int error=0;

	printf("%4d  %10s \n",tipo.id, tipo.nombreTipo);

	return error;
}


int mostrarArrayTipo(eTipo tipo[], int len)
{
	int error=-1;

	if(tipo!=NULL && len>0)
	{
		printf("id   nombre\n");
		for(int i=0; i<len; i++)
		{
			mostrarTipo(tipo[i]);
		}
		error=0;
	}
	return error;
}

int cargarDescripcionTipo(eTipo tipo[], int len,int id, char desc[])
{
	int error=-1;

	if(tipo!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(tipo[i].id==id)
			{
				strcpy(desc,tipo[i].nombreTipo);
				error=0;
				break;
			}
		}
	}
	return error;
}
