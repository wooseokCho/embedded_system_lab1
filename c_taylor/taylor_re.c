//   Program Taylor_ce.c
// Compute sine() using the Taylor series with one to five terms.


#include <stdio.h>
#include <math.h>

// Define PI
#define PI 3.14
#define TERMS	5

int factorial(int m)
{
	int facto = 1;
	for (int i=2; i<=m; ++i)
		facto = facto*i;

	return facto;
}

int main()
{
  	float s[TERMS], e[TERMS];
	int indeg;
	int pwr, facto;
	int n, i, j;		// Loop index
	double angpwr;
	double inrad;
	double pi = atan(1.)*4.;
	double dtr = pi/180.;

	// 1. Get input angle
	printf("Enter angle in degrees: ");
	scanf("%d", &indeg);

	//change to rad
	inrad = indeg*dtr;

	// 2. Compute sine with Math library 
	float s0 = sin(inrad);
	printf("sin(%d)= %g using Math library.\n", indeg, s0);

	// 3. Compute sine using the Taylor series up to n terms
	for (n=1; n<=TERMS; ++n) {
		// Loop to sum term i
		for (i=1; j<=n; ++i) {
			// Compute pwr
			pwr = 2*i - 1;
			// Compute angle^pwr
			angpwr = inrad;
			for (j=2; j<=i; ++j) angpwr *= inrad*inrad;
			// Compute factorial pwr!
			facto = factorial(pwr);
			// Compute sine by Taylor series 
			s[i-1] += angpwr/facto;
		}
	}

	// 4. Compute error
	for (n=1; n<=TERMS; ++n)
		e[i-1] = s[i-1] - s0;

	// 5. Print result
	printf("sin(%d) using Taylor series:\n", indeg);
	for (int i=1; i<=TERMS; ++i) {
		printf("%d terms: sin(%d)= %g, error= %g\n", i, indeg, s[i-1], e[i-1]);
	}

	return 0;
}


