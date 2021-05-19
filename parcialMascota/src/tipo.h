/*
 * comidas.h
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
 */

#ifndef TIPO_H_
#define TIPO_H_

/*mostrar comida*
mostrar array comida*
alta almuerzo- lista de comida y meto el id de la comida, muestra los empleados y meto el legajo en el q se cargue  y cargar la fecha
*/
typedef struct
{
	int id;//1000
	char nombreTipo[20];
}eTipo;


int mostrarTipo(eTipo tipo);
int mostrarArrayTipo(eTipo tipo[], int len);

int cargarDescripcionTipo(eTipo tipo[], int len,int id, char desc[]);

#endif /* TIPO_H_ */
