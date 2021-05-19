/*
 * sector.c
 *
 *  Created on: 7 may. 2021
 *      Author: Asus
 */
#include "mascota.h"
#include "color.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

#include "informes.h"
#include "fecha.h"
#include "tipo.h"
#include "servicio.h"

int cargarDescripcionColor(int id, eColor color[], int len, char desc[])
{
	int error=-1;

	if(color!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(color[i].id==id)
			{
				strcpy(desc,color[i].nombreColor);
				error=0;
				break;
			}
		}
	}
	return error;
}

void mostrarSector(eColor color)
{
	printf(" %d     %8s\n",color.id,color.nombreColor);
}


int mostrarArrayColore(eColor color[], int len)
{
	int error=-1;

	if(color!=NULL&& len>0)
	{
		printf("Id   Descripcion\n");
		for(int i=0; i<len; i++)
		{
			mostrarSector(color[i]);
		}
		error=0;
	}

	return error;
}





