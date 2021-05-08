/*
 * commons.h
 *
 *  Created on: Oct 30, 2018
 *      Author: adaskin
 */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_


#define CSIZE 10  	/* edge length for a square cell	*/
/*grid size*/
#define M 50       		/* number of rows    				*/
#define N 50       		/* number of columns 				*/
extern int grid[M][N]; 	/* defined in model.c				*/


/*defined in model.c*/
int getNumberOfLiveNeighbors(int x, int y);
int updateGrid();
int initGrid();

/* defined in view.c*/
int drawGrid();
int initSDLWindow();
int quitAll();
int checkEvents();

#endif /* GAMEOFLIFE_H_ */
