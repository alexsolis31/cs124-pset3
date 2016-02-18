#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

int fib_recursive(int n); 
int fib_iterative(int n);
int matrix_power(int mat[2][2], int n);
int fib_matrix(int n);

int main (int argc, char* argv[]){

	int input; 

	printf("Enter (1) for Recursive, (2) for Iteration, (3) for Matrix: ");
	// test number 
	scanf("%d", &input);

	int fib_result_R = 0; 
	int prev_fib = 0; 
	int n = 0; 

	clock_t tic = clock(); 

	while (fib_result_R <= 100000000){

		if (input == 1){
			fib_result_R = fib_recursive(n);
			printf("Fibonacci Number %d: ", n);
			printf("%d\n", fib_result_R);
			n++; 

		}

		else if (input == 2){
			fib_result_R = fib_iterative(n);
			printf("Fibonacci Number %d: ", n);
			printf("%d\n", fib_result_R);
			n++; 
		}

		else if (input == 3){
			prev_fib = fib_result_R; 
			fib_result_R = fib_matrix(n);
			printf("Fibonacci Number %d: ", n);
			printf("%d\n", fib_result_R);
			n++; 
		}

	}

	clock_t toc = clock(); 

	printf("The largest possible fib number is:");
	printf("%d\n", prev_fib);
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

   

	return 0; 

}

/******************************************************************/
/* Recursive Function */ 
/******************************************************************/

int fib_recursive(int n){

	if (n == 0) {

		return 0; 
	}

	if (n == 1){

		return 1; 
	}

	if (n >= 2){
		return ((fib_recursive(n - 1) % 65536) + (fib_recursive(n - 2) % 65536));
	}

	else 
		return -1; 
}

/******************************************************************/
/* Iterative Function */ 
/******************************************************************/

int fib_iterative(int n){
	int values[n];

	values[0] = 0; 
	values[1] = 1; 

	for (int i = 2; i <= n; i++){
		values[i] = (values[i-1] % 65536) + (values[i - 2] % 65536);
		values[i-2] = 0; // delete old values to save space
	}

	return values[n];

}


/******************************************************************/
/* Matrix Function */ 
/******************************************************************/

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

	return result[0] % 65536;

}


int matrix_power(int mat[2][2], int n){

	int mat2[2][2] = {{0,1}, {1,1}};
	int mat3[2][2] = {{0,1}, {1,1}};

	for (int i = 0; i <= n-2; i++){
		mat[0][0] = (mat3[0][0] * mat2[0][0])  + (mat3[0][1] * mat2[1][0]);
		mat[0][1] = (mat3[0][0] * mat2[0][1])  + (mat3[0][1] * mat2[1][1]);
		mat[1][0] = (mat3[1][0] * mat2[0][0])  + (mat3[1][1] * mat2[1][0]);
		mat[1][1] = (mat3[1][0] * mat2[0][1])  + (mat3[1][1] * mat2[1][1]);

		mat3[0][0] = mat[0][0];
		mat3[0][1] = mat[0][1];
		mat3[1][0] = mat[1][0];
		mat3[1][1] = mat[1][1];


	}

	return 0; 

}

