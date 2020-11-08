/*
 * marker.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#include "marker.h"
#include "GuillermoMorel.h"

Marker* placeMarker(int r, int c)
{
	Marker* mP = (Marker*) malloc (sizeof(Marker));
	mP->row = r;
	mP->col = c;

	return mP;
}
