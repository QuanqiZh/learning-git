//
//main.c
//Assignment 1A:
//This program can generate a a two-dimensional binary matrix and modify it based on certain
//rules. This assignment focuses more on the coding rules rather than algorithm.
//
// Author: Zhiquan Zhang, created on 8/27/2018
// All rights reserved
//
#include <stdio.h>
#include <stdlib.h>

#define m 5
#define n 8
#define p 0.05

/*
 * function that can generate matrix with assigned row and column
 * it returns a matrix with assigned rows and columns.
 */
int **generate_matrix(int row, int col);

/*
 * function that can initialize the input matrix and output matrix
 * it has no return value and directly initializes the values of the generated two matrixes.
 */
void init_matrix(int **mat1, int **mat2);

/*
 * function that can modify the output matrix according to the rules
 * it has no return value and also directly modifies the values of the initialized two matrixes.
 */
void modify_matrix(int **mat1, int **mat2);

int main(int argc, const char * argv[]){


/************	generate input and output matrix separately with assigned row and column ************/
        int  **mat = generate_matrix(m,n);
        int  **ans = generate_matrix(m,n);
/************	generate input and output matrix separately with assigned row and column ************/


/************	initialize input and output matrix separately ************/
        //let the input matrix has random 1 or 0, let the output matrix filled with 0
        init_matrix(mat,ans);

        //show the input matrix
        printf("\n\n");
/************	initialize input and output matrix separately ************/


/************	modify output matrix according to the rules ************/
        modify_matrix(mat,ans);
/************	modify output matrix according to the rules	************/


/************	show output matrix	************/
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++)
                        {printf("%d ",ans[i][j]);}
                printf("\n");
        }
/************	show output matrix	************/
        return 0;
}

/************	Function Definition ************/
int **generate_matrix(int row, int col){
	// allocate the first dimension's memory
	int **matrix = (int **)malloc(row*sizeof(int *));

	// allocate the second dimension's memory
	for(int i=0;i<row;i++){
		matrix[i] = (int *)malloc(col*sizeof(int));
	}
	return matrix;
}
/************	Function Definition ************/

/************	Function Definition ************/
void init_matrix(int **mat1, int **mat2){
	for(int i=0;i<m;i++){
	                for(int j=0;j<n;j++){
	                //RAND_MAX is the max value of rand() and the element of matrix's possibility of being 0 is 1-p.
	                if(rand()>=p*(RAND_MAX))
	                        mat1[i][j]=0;

	                //the element of matrix's possibility of being 1 is p.
	                else
	                        mat1[i][j]=1;

	                //let the output matrix's elements all be 0
	                mat2[i][j]=0;

	                // show every element
	                printf("%d ",mat1[i][j]);
	        }
	                printf("\n");
	        }
}
/************	Function Definition ************/

/************	Function Definition ************/
void modify_matrix(int **mat1, int **mat2){

	//go through all the elements of the matrix
	for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

            		//find the element equal to 1
                    if(mat1[i][j]==1){
                            for(int r=0;r<m;r++){
                                    for(int s=0;s<n;s++){
                                    		//let the column's elements be 1
                                            mat2[i][s]=1;

                                            //let the row's elements be 1
                                            mat2[r][j]=1;
                                    }
                            }
                    }
            }
    }
}
/************	Function Definition ************/
