/*
 * empleado.h
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */
#include "color.h"
#ifndef MASCOTA_H_
#define MASCOTA_H_

#include "mascota.h"



typedef struct
{
	int id;
	char nombre [20];
	int idTipo;
	int idColor;
	float edad;
	int isEmpty;
}eMascota;


void mostrarMascota(eMascota mascota, eColor color[], int len);
int inicializarMascota(eMascota lista[], int len);
int buscarLibreMascota(eMascota lista[], int len,int* indice);
int buscarMascota(eMascota lista[], int len, int* indice, int legajo);
int modificarMascota(eMascota lista[], int len);

int hardcodearMascota(eMascota lista[], int len, int cant, int* pLegajo);
#endif /* MASCOTA_H_ */
