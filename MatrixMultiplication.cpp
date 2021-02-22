
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>


//change this for bigger matrix
#define n 4

// maximum size of matrix

int M1[n][n], M2[n][n],M3[n][n];
int counter=0;

//enter matrix values
void* createMatrix(int matrix[n][n]){

 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
         matrix[i][j]=rand()%10;
        }
    }


return matrix;

}


void PrintMatrix(int Matrix[n][n]){


   for(int i=0;i<n; i++){
    for(int j=0; j<n; j++){

        printf("matrix[%d][%d] %d\n",i,j,Matrix[i][j]);

    }

   }

}


// each thread will be multiply one row with one col
void * MatrixMultiply(void *arg){

    int thread=counter++; //each thread will increment counter and therefore multiply a different row*column

for(int i=thread *n/n; i<(thread+1)*n/n; i++){

    for(int j=0; j<n; j++){

        for(int k=0; k<n; k++){

            M3[i][j]=M3[i][j]+ M1[i][k]*M2[k][j];
        }

    }
}


}



// had to intialize matrix 3 to 0 or I was getting garbage value
void *Intialize(int M3[n][n]){
for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            M3[i][j]=0;
        }
    }

return M3;


}

int main()
{

   
    createMatrix(M1);


    createMatrix(M2);
    
    PrintMatrix(M1);
    
    PrintMatrix(M2);


    pthread_t threads[n];

    for(int i=0; i<n; i++){
             int* t;
        pthread_create(&threads[i], NULL, MatrixMultiply, (void*)(t));




    }

     for (int i = 0; i < n; i++){
        pthread_join(threads[i], NULL);
     }

     

     PrintMatrix(M3);








    return 0;
}
