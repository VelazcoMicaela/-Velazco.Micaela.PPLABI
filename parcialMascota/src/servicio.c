/*
 * comidas.c
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "trabajo.h"
#include "color.h"
#include "mascota.h"
#include "tipo.h"
#include "servicio.h"

int mostrarServicio(eServicio servicio)
{
	int error=-1;

	printf("%4d  %10s %.2f\n",servicio.id, servicio.descripcion,servicio.precio);

	return error;
}


int mostrarArrayServicio(eServicio servicio[], int len)
{
	int error=-1;

	if(servicio!=NULL && len>0)
	{
		printf("id   descripcion precio\n");
		for(int i=0; i<len; i++)
		{
			mostrarTipo(servicio[i]);
		}
		error=0;
	}
	return error;
}

int cargarDescripcionServicio(eServicio servicio[], int len,int id, char desc[])
{
	int error=-1;

	if(servicio!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(servicio[i].id==id)
			{
				strcpy(desc,servicio[i].descripcion);
				error=0;
				break;
			}
		}
	}
	return error;
}
