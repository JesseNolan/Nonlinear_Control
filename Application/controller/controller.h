#ifndef CONTROLLER_H_
#define CONTROLLER_H_

typedef struct{
	long double a1;
	long double a2;
	long double a3;
	long double a4;
	long double a5;
	long double b1;
	long double b2;
	long double b3;
	long double b4;
	long double b5;
}	Con_coeffs;

typedef struct{
	long double e[5];
	long double u[6];
	long double y[2];
} Signals;



#endif
