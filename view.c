/**
 * view.c
 * provides a view for the grid defined in model.c.
 * It generates a grid on window with two different cell-colors:
 * if the cell has value 0, it is black (dead),
 * otherwise, it is non-black(alive).
 * note: functions are written with the help of libsdl.org.
 *  Created on: Oct 30, 2018
 *      Author: adaskin
 */

#include "SDL2/SDL.h"
#include "gameoflife.h"


/*do not change any of this*/
SDL_bool done = SDL_TRUE; 		/*controls the game loop*/
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

int windowHeight = N*CSIZE;
int windowWidth = M*CSIZE;

/**
 * initializes  window and renderer
 * window size is (windowHeight x windowWidth)
 */
int initSDLWindow(){
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		if (SDL_CreateWindowAndRenderer(windowHeight+1, windowWidth+1,
				0, &window, &renderer) == 0) {
			SDL_SetWindowTitle(window, "Game Of Life in Medeniyet");
			done = SDL_FALSE;
		}

	}
	return done;
}

/**
 * draws a given MxN grid with the cell size csize on the window
 */
int drawGrid(){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			SDL_Rect rect = {CSIZE*j,CSIZE*(i),CSIZE*(j+1),CSIZE*(i+1)};
			if (grid[i][j] == 0){
				/*change color to dead*/
				SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE);
			}
			else{
				/*change color to alive*/
				SDL_SetRenderDrawColor(renderer, 255, 165,0, SDL_ALPHA_OPAQUE);

			}
			/*draw cell with the determined color*/
			SDL_RenderFillRect(renderer,&rect);
		}
	}

	/* draw lines for grid */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	/*draw horizontal*/
	for (int x = 0; x <= windowWidth; x = x+CSIZE){
		SDL_RenderDrawLine(renderer,0, x, windowHeight, x);
	}
	/* draw vertical */
	for (int y = 0; y <= windowHeight; y = y+CSIZE){
		SDL_RenderDrawLine(renderer,y,0, y, windowWidth);
	}


	SDL_RenderPresent(renderer);
	return 0;
}

/**
 * checks for the quit event,
 * returns true if event occurs
 */
int checkEvents(){
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			done = SDL_TRUE; /*the game is over*/
		}
	}
	return done;
}

/**
 * destroys window and renderer
 */
int quitAll(){
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}
	if (window) {
		SDL_DestroyWindow(window);
	}
	SDL_Quit();

	return 0;
}

