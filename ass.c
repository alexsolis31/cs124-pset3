#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include <time.h>




float rand_num()
{

	float N = 100; 
	float X = rand() / (double)(RAND_MAX);
	return X; 
}


int main (int argc, char **argv) {

    time_t seconds;
    seconds = time(NULL);
    srand(seconds);

    float a = rand_num();
    float b = rand_num();
    float c = rand_num();
    float d = rand_num();
    float e = rand_num();
    float f = rand_num();
    float g = rand_num();

    printf("%f\n", a);
    printf("%f\n", b);
    printf("%f\n", c);
    printf("%f\n", d);
    printf("%f\n", e);
    printf("%f\n", f);
    printf("%f\n", g);


}