/*
 * sector.h
 *
 *  Created on: 4 may. 2021
 *      Author: Asus
 */

#ifndef COLOR_H_
#define COLOR_H_
#include "mascota.h"

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;


int cargarDescripcionColor(int id, eColor color[], int len, char desc[]);

void mostrarSector(eColor color);
int mostrarArrayColore(eColor color[], int len);



#endif /* COLOR_H_ */
