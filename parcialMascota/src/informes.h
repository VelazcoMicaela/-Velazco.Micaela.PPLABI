/*
 * informes.h
 *
 *  Created on: 10 may. 2021
 *      Author: Asus
 */


#ifndef INFORMES_H_
#define INFORMES_H_

#include "fecha.h"
#include "servicio.h"
#include "color.h"
#include "mascota.h"
#include "tipo.h"


int recorrerYMostrarListaColor(eColor sector[], int lenSec, eMascota lista[], int lenEmp, int id, float* acomulador);
int mostrarSectoresYEmpleados(eColor sector[], int lenSec, eMascota lista[], int lenEmp);
int totalSueldoSector(eColor sector[], int lenSec, eMascota lista[], int lenEmp, float* acomulador);
int sectorMayorSueldo(eColor sector[], int lenSec, eMascota lista[], int lenEmp);
int totalADepositar(eColor sector[], int lenSec, eMascota lista[], int lenEmp);
/*
//int mostrarAlmuerzoEmpleado(eMascota lista[], int lenEmp, eTrabajo almuerzo[], int lenAlm, eColor sector[], int lenSec, eServicio comida[], int lenCom);
*/
#endif /* INFORMES_H_ */
