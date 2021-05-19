/*
 * empleado.c
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */
#include "mascota.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "trabajo.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"


#define LLENO 0
#define VACIO 1



void mostrarMascota(eMascota mascota, eColor color[], int len)//
{
	char descripcion[20];

	if(cargarDescripcionColor(mascota.idColor, color,len, descripcion)==0)
	{
		printf("%5d  %10s   %d    %c   %9.2f  %02d/%02d/%d   %d    %10s\n",mascota.id, mascota.idTipo,
			mascota.nombre, mascota.edad, mascota.idColor, descripcion);

	}
	else
	{
		printf("ERROR\n");
	}

}

/*int mostrarArrayMascota(eMascota lista[],int len, eColor color[], int lenCol)
{
	int error=-1;
	int flag=0;

	if(lista!=NULL&& len>0&& color!=NULL&& lenCol>0)
	{
		printf("\nid     Nombre  IdTipo IdColor    Edad\n");
		for(int i=0; i<len; i++)
		{
			if(lista[i].isEmpty==LLENO)
			{
				mostrarMascota(lista[i],color,lenCol);
				flag=1;
			}
		}

		if(flag!=1)
		{
			printf("NO HAY MASCOTA PARA MOSTRAR\n");
		}
		error=0;
	}
	return error;
}*/

int inicializarMascota(eMascota lista[], int len)
{
	int error=-1;

	if(lista!=NULL&&len>0)
	{
		for(int i=0; i<len; i++)
		{
			lista[i].isEmpty=VACIO;
		}
		error=0;
	}

	return error;
}
/*
int cargarMascota(eMascota lista[], int len,int* pLegajo, eColor color[], int lenCol)
{
	int error=-1;
	int indice;
	char respuesta;
	eMascota aux;

	if(lista!=NULL&&pLegajo!=NULL&&len>0)
	{

		while(respuesta!='n')
		{
			if(buscarLibreMascota(lista, len, &indice)==0)
			{
				printf("Legajo %d\n",*pLegajo);

				aux.isEmpty=LLENO;
				lista[indice]=aux;
				lista[indice].id=*pLegajo;
				(*pLegajo)++;
				error=0;


			}
			else
			{
				printf("No hay lugar\n");
			}
			if(utn_getCaracterCorroboraDosCarac(&respuesta, "Desea seguir ingresando empleados? s-n", "ERROR reingrese s-n", 's', 'n'))
			{
				printf("Gracias\n");
			}
		}


	}

	return error;
}

int bajaMascota(eMascota lista[], int len, eColor color[], int lenCol)
{
	int error=-1;
	int legajo;
	int indice;
	char eliminar;

	if(lista!=NULL&&len>0)
	{
		mostrarArrayMascota(lista, len,color,lenCol);
		if(utn_getNumeroEnteroConIntentos(&legajo, "Ingrese legajo ", "ERROR Reingrese legajo entre 2000 y 3000 ", 1999, 3000, 5)==0)
		{
			if(buscarMascota(lista, len, &indice, legajo)==0)
			{
				mostrarMascota(lista[indice],color,lenCol);
				if(utn_getCaracterCorroboraDosCarac(&eliminar, "Desea eliminar? S/N\n", "ERROR Ingrese S para eliminar o N para volver", 's', 'n')==0)
				{
					if(eliminar=='s')
					{
						lista[indice].isEmpty=VACIO;
						error=0;
					}
					else
					{
						printf("Baja cancelada por el usuario\n");
					}
				}
			}
			else
			{
				printf("No hay mascota con legajo %d \n",legajo);
			}
		}

	}

	return error;
}*/

int buscarMascota(eMascota lista[], int len, int* indice, int legajo)
{
	int error=-1;

	if(lista!=NULL&& len>0&& indice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(lista[i].id==legajo && lista[i].isEmpty==LLENO)
			{
				*indice=i;
				error=0;
				break;
			}
		}
	}

	return error;
}

int buscarLibreMascota(eMascota lista[], int len,int* indice)
{
	int error=-1;

	if(lista!=NULL&& indice!=NULL&& len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				*indice=i;
				error=0;
				break;
			}
		}

	}
	return error;
}


/*int ordenarArrayMascota(eMascota lista[], int len)
{
	int error=-1;
	eMascota aux;

	if(lista!=NULL&&len> 0)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1; j<len;j++)
			{
				if(lista[i].legajo<lista[j].legajo ||//de mayor a menor
					(lista[i].legajo==lista[j].legajo &&
					strcmp(lista[i].nombre,lista[j].nombre)<0))//de mayor a menor
				{
					aux=lista[i];
					lista[i]=lista[j];
					lista[j]=aux;
				}
			}
		}
		error=0;
	}
	return error;
}
*/


int modificarMascota(eMascota lista[], int len)
{
	int error=-1;


	if(lista!=NULL&&len>0)
	{


	}

	return error;
}


/*int listarEmpleadosColor(eColor color[], int lenCol, eMascota lista[], int lenMas)
{
	int error=-1;
	int opcion;
	int respuesta;
	float total=0;

	system("cls");

	if(color!=NULL&& lista!=NULL && lenCol>0&& lenMas>0)
	{
		if(mostrarArrayColore(color, lenCol)==0)
		{
			if(utn_getNumeroEnteroConIntentos(&respuesta, "Ingrese 1-listar empleados por color 2- mostrar total de sueldos por color ", "ERROR REINGRESE OPCION", 1, 2, 5)==0)
			{
				if(utn_getNumeroEnteroConIntentos(&opcion, "Ingrese el color a listar empleados ", "ERROR el color no existe ", 500, 504, 5)==0)
				{
					switch(respuesta)
					{
						case 1:
							if(recorrerYMostrarListaSectores(color, lenCol, lista, lenMas, opcion,&total)==0)
							{
								error=0;
							}

						break;

						case 2:
							if(recorrerYMostrarListaSectores(color, lenCol, lista, lenMas, opcion,&total)==0)
							{
								printf("el total del sueldo del color es: %.2f",total);
								error=0;
							}
							break;
					}
				}
			}
		}
	}

	return error;
}

int cargarNombreEmpleadoEnAlmuerzo(eMascota lista[], int lenEmp, int id, char nombre[])
{
	int error=-1;

	if(lista!=NULL && lenEmp>0 && id>0)
	{
		for(int i=0; i<lenEmp; i++)
		{
			if(id==lista[i].legajo)
			{
				strcpy(nombre,lista[i].nombre);
				error=0;
				break;
			}
		}

	}


	return error;
}
*/


int hardcodearMascota(eMascota lista[], int len, int cant, int* pLegajo)
{
	int cantidad=0;

	eMascota unaMas[10]=
	{
			{0,"Donato",1000,5001,1,0},
			{0,"Carmen",1001,5000,2,0},
			{0,"Chepi",1002,5003,3,0},
			{0,"Alex",1003,5003,4,0},
			{0,"German",1004,5004,1,0},
			{0,"Maria",1000,5000,2,0},
			{0,"Daniel",1001,5001,3,0},
			{0,"Andrea",1002,5002,4,0},
			{0,"Candela",1003,5003,1,0},
			{0,"Magdalena",1004,5004,2,0},
	};

	if(lista!=NULL&& unaMas!=NULL&& len>0 && cant>=0 && cant<=len && pLegajo!=NULL)
	{
		for(int i=0; i<cant; i++)
		{
			lista[i]=unaMas[i];

			lista[i].id=*pLegajo;
			(*pLegajo)++;

			cantidad++;
		}
	}

	return cantidad;
}
