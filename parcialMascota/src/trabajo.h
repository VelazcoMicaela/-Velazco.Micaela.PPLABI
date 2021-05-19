/*
 * almuerzo.h
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
 */

#ifndef ALMUERZO_H_
#define ALMUERZO_H_

#include "tipo.h"

typedef struct
{
	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif /* ALMUERZO_H_ */
/*inicializar *
 * buscar libre*
 * buscar*
 *
 * mostrar almuerzo*
 * mostrar almuerzos*
 */

int inicializarTrabajo(eTrabajo trabajo[], int len);
int buscarLibreTrabajo(eTrabajo trabajo[], int len, int* indice);
int buscarTrabajo(eTrabajo trabajo[], int len, int* pId, int id);
int mostrarArrayTrabajo(eTrabajo trabajo[], eServicio tipo[],int lenTrab, int lenTip, eMascota mascota[], int lenMas);

int cargarTrabajo(eTrabajo trabajo[], int lenTrab,int* pLegajo, eServicio tipo[], int lenTip);
int bajaTrabajo(eTrabajo trabajo[], int len, eServicio tipo[], int lenTip, eMascota mascota[], int lenMas);

int modificarTrabajo(eTrabajo* trabajo, int len, eServicio tipo[], int lenTip, eMascota mascota[], int lenMas);
//int menuModificacionAlmuerzo(eTrabajo* trabajo, eTipo tipo[], int lenTip, eMascota trabajo[], int lenMas);



int mostrarUnTrabajo(eTrabajo trabajo, eServicio tipo[], int len, eMascota mascota[], int lenMas);


int hardcodearTrabajo(eTrabajo trabajo[], int len, int cant, int* pLegajo);
