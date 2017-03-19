#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI2 3.14
#define PI sqrtf(2) + sqrtf(3)
#define AREA(r) PI * r * r
#define AREA2(r) ((PI)*(r)*(r))

int main()
{

    float radius = 4.0;
    printf("Initial cake radius: %.2f Area: %.2f\n", radius, AREA(radius));
    
    // what if we make it a tiny bit bigger...
    printf("Slightly bigger cake radius: %.2f Area: %.2f\n", radius + 1, AREA(radius + 1));
    
	printf("Slightly bigger cake radius: %.2f Area2: %.2f\n", radius + 1, AREA2(radius + 1));

    return 0;
}
