#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ALIVE 1
#define DEAD 0 
#define birthLimit 5 
#define deathLimit 3 

void initGrid(int **Grid,int rows, int cols, float chanceToStartAlive){
    srand(time(NULL));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Grid[i][j] = (rand() < chanceToStartAlive * RAND_MAX) ? ALIVE : DEAD;
        }
        
    }
    
}

int countAliveNeighbors(int **Grid, int rows, int cols, int x, int y){
    int aliveNeighbors = 0;
    for (int i = -1; i <= 1 ; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0) continue;
            int Nx = x + i ;
            int Ny = y + j ;
            if(Nx >= 0 && Nx < rows && Ny >= 0 && Ny < cols){
                aliveNeighbors += Grid[Nx][Ny];
            }
        }
        
    }
    return aliveNeighbors ;
}

void updateGrid(int **Grid, int rows, int cols){

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int aliveNeighbors = countAliveNeighbors(Grid,rows,cols,i,j);

            // Règle de naissance
            if (Grid[i][j] == DEAD && aliveNeighbors >= birthLimit) {
                Grid[i][j] = ALIVE; // La cellule devient vivante
            }
            // Règle de mort
            else if (Grid[i][j] == ALIVE && aliveNeighbors < deathLimit) {
                Grid[i][j] = DEAD; // La cellule devient morte
            }
                
        }
        
    }
    
}

void Show(int **Grid,int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Grid[i][j] == 0 ? printf(". ") : printf("# ");
        }

        printf("\n");
        
    }
}

int main(int argc, char const *argv[])
{
    int rows = 40;
    int cols = 40;
    float chanceToStartAlive = 0.45 ;
    int nbIteration = 5;
  

    int **Grid = (int **)calloc(rows,sizeof(int *));
    if(Grid == NULL){
        perror("Erreur lors de l'allocation mémoire pour les lignes");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < rows; i++)
    {
        Grid[i] = (int *)calloc(cols,sizeof(int));
        if (Grid[i] == NULL)
        {
            perror("Erreur lors de l'allocation mémoire pour les colonnes");
            for (int j = 0; j < i; j++)
            {
                free(Grid[j]);
            }
            free(Grid);
            return EXIT_FAILURE; 
            
        }
        
    }

    initGrid(Grid,rows,cols,chanceToStartAlive);
    int res = 0;
    do
    {
        printf("Iteration %d :\n", res + 1);
        Show(Grid,rows,cols);
        updateGrid(Grid,rows,cols);
        res++;
    } while (res < nbIteration);
    
    for (int i = 0; i < rows; i++)
    {
        free(Grid[i]);
    }
    free(Grid);
    
    
    return 0;
}
