#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

// Problem 2
// Fibbonacci Sequence 

int matrix_power(int mat[2][2], int n);
int matrix_multiply(int mat1[2][2], int mat2[2][2]);

// Recursive Attempt 
int fib_recursive(int n){

	if (n == 0) {

		return 0; 
	}

	if (n == 1){

		return 1; 
	}

	if (n >= 2){
		return (fib_recursive(n - 1) + fib_recursive(n - 2));
	}

	else 
		return -1; 
}

// Iterative Attempt 
int fib_iterative(int n){
	int values[n];

	values[0] = 0; 
	values[1] = 1; 

	for (int i = 2; i <= n; i++){
		values[i] = values[i-1] + values[i - 2];
		values[i-2] = 0; // delete old values to save space
	}

	return values[n];

}


// Matrix Attempt 
int fib_matrix(int n){

	if (n == 0)
		return 0; 
	
	// matrix to be raised to nth power
	int mat[2][2] = {{0,1}, {1,1}};
	int base[2] = {0,1};

	// raise matrix to appropriate power
	matrix_power(mat, n);

	// multiply that resulting matrix by the base case [0, 1]
	int result[2]; 

	result[0] = mat[0][0] * base[0] + mat[0][1] * base[1];
	result[1] = mat[1][0] * base[0] + mat[1][1] * base[1];

	return result[0];

}


int matrix_power(int mat[2][2], int n){

	int mat2[2][2] = {{0,1}, {1,1}};
	int mat3[2][2] = {{0,1}, {1,1}};

	for (int i = 0; i <= n-2; i++){
		mat[0][0] = (mat3[0][0] * mat2[0][0]) + (mat3[0][1] * mat2[1][0]);
		mat[0][1] = (mat3[0][0] * mat2[0][1]) + (mat3[0][1] * mat2[1][1]);
		mat[1][0] = (mat3[1][0] * mat2[0][0]) + (mat3[1][1] * mat2[1][0]);
		mat[1][1] = (mat3[1][0] * mat2[0][1]) + (mat3[1][1] * mat2[1][1]);

		mat3[0][0] = mat[0][0];
		mat3[0][1] = mat[0][1];
		mat3[1][0] = mat[1][0];
		mat3[1][1] = mat[1][1];


	}

	return 0; 

}

int main (int argc, char** argv){

	int n = 0; 

	printf("Enter number: ");
	// test number 
	scanf("%d", &n);

    /******************************************************************/
	/* Recursive Function */ 
	/******************************************************************/

	clock_t tic = clock(); 

	int fib_result_R = fib_recursive(n);

	clock_t toc = clock(); 

	printf("The result using recursive function: \n");
	printf("%d\n", fib_result_R);
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	/******************************************************************/
	/* Iterative Function */ 
	/******************************************************************/

	tic = clock(); 

	int fib_result_I = fib_iterative(n);

	toc = clock(); 

	printf("The result using iterative function: \n" );
	printf("%d\n", fib_result_I);
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	/******************************************************************/
	/* Matrix Function */ 
	/******************************************************************/

	tic = clock(); 

	int fib_result_M = fib_matrix(n);

	toc = clock(); 

	printf("The result using the matrix function: \n");
	printf("%d\n", fib_result_M);
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	/******************************************************************/

	return 0; 

}