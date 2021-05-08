/*
 * controller.c
 * creates game of life and runs the game
 *  Created on: Oct 30, 2018
 *      Author: adaskin
 */

#include "SDL2/SDL.h"
#include "gameoflife.h"

/*do not change any of this*/
extern SDL_bool done;

int main(int argc, char* argv[])
{
	/*initializes window*/
	initSDLWindow();

	/*initializes Grid with the given initial state*/
	/*FARKLI BASLANGIC DURUMLARINI BURDAKI 1 degerini degestirerek yapabilirsiniz*/
	initGrid(2);

	/*draws initial grid*/
	drawGrid();

	/* repeat until window is closed */
	while (!done) {
		/*check user events: e.g. click to close x*/
		checkEvents();
		/* update grid by the rules */
		updateGrid();

		/*draws new updated grid*/
		drawGrid();

		SDL_Delay(1000); /*sleep(1);*/
	}

	/*quit everything*/
	quitAll();
	return 0;
}
