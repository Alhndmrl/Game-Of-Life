/*Alihan Demirel
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 */
#include<stdio.h>
#include "gameoflife.h"
int grid[M][N] = {0};   /*M and N are constants defined in gameOfLife.h*/
int neighbors[M][N]={0}; 	/* neighbors sayısını tutan iki boyutlu bir dizi */

/**
 * initializes the grid with the chosen initial state
 */
 /* grid==1 ise canlı grid==0 ise ölüdür */
int initGrid(int initialState){
   
    for(int a = 0; a < M; a++){ /* gridin tüm elemanlarını sıfırlar */
        for (int b = 0; b < N; b++){
            grid[a][b] = 0;
        }
    }
    if(initialState==1){ /* 1 secilirse blinkerları yerlestirir */
		for(int x=5;x<M;x=x+10){ /* blinkerları yerlestirmek icin döngü*/
			
			grid[x-1][x] = 1;  /* kosegen uzerine blinkerları yerlestirir*/
			grid[x][x] = 1;
			grid[x+1][x] = 1;

		}
		
	} else if(initialState==2){ /* 2 secilirse gliderları yerlestirir */
		
		for(int x=5;x<M;x=x+10){ /* gliderları yerlestirmek icin döngü*/
			
			grid[x-1][x] = 1;     /* kosegen uzerine  gliderları yerlestirir*/
			grid[x][x] = 1;
			grid[x+1][x] = 1;
			grid[x+1][x-1] = 1;
			grid[x][x-2] = 1;
		}		
	}
	return 0;
}

/**
 * returns the number of live neighbors of the cell
 * at position (x, y) on the grid
 */
/* hücrelerin etrafındaki canlı hucreleri saymasını saglayan fonksiyon */
int getNumberOfLiveNeighbors(int x, int y){ 
	
    int neighbors=0; /*neighbors sayısını 0 dan baslatır */
    for(int i=x-1; i<=x+1 ;i++){
		for(int j=y-1; j<=y+1 ;j++){
			if(!(i==x && j==y)){
				if(i < M && j < N && i >= 0 && j >= 0){
					if(grid[i][j]==1){
						neighbors++; /* her komsu buldugunda neighbors 1 artar */
					}
				}
			}
		}
	}		
	return neighbors;
}

/**
 * updates each cell by following the update rules of the game of life
 */
int updateGrid(){
	
	int i,j; /* degisken tanımlama*/
    /* getNumberOfLiveNeighbors fonksiyonundan neighbors sayılarını alır neighbors dizisine atar */
	for(i=0;i<M;i++){ 
		for(j=0;j<N;j++){	
			neighbors[i][j]=getNumberOfLiveNeighbors(i,j);
		} 
	}            
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){	
			if(grid[i][j]==1){  
				/*canlı hucrenin 2 den kucuk veya 3 ten fazla canlı komsusu varsa oldurur */
				if((neighbors[i][j]>3 || neighbors[i][j]<2) ) 
					grid[i][j]=0;
				/*canlı hucrenin 2 veya 3 komsusu varsa yasamaya devam eder */
				if(neighbors[i][j]==2 || neighbors[i][j]==3) 
					grid[i][j]=1;
			}
			
			if(grid[i][j]==0){    
				/* olu hucrenin 3 canlı komsusu varsa canlandırır */
				if(neighbors[i][j]==3 )
					grid[i][j]=1;
			}
		}
	}
	return 0;
}

