/*
 * Plant.c
 *
 *  Created on: Aug 12, 2016
 *      Author: silenus
 */

#include "plant.h"


const double p_KEMF = 2.4e-2;
const double p_KT = 2.54e-1;
const double p_KE = 1e-6;
const double p_KC = 1;
const double p_KH = 0;
const double p_KG = 0.3;
const double p_BE = 1e-1;
const double p_BC = 1;
const double p_BH = 2;
const double p_JE = 1;
const double p_JH = 1;
const double p_N = 50;
const double p_LA = 1e-2;
const double p_RA = 5;
const double p_MH = 7;
const double p_ME = 2;
const double p_LE = 0.4;
const double p_LH = 0.4;
const double p_g = 9.8;




long double f1(long double t, long double x1, long double x2, long double x3, long double x4, long double x5)
{
	return x3;
}

long double f2(long double t, long double x1, long double x2, long double x3, long double x4, long double x5)
{
	return x4;
}

long double f3(long double t, long double x1, long double x2, long double x3, long double x4, long double x5)
{
	return (x1*(-(p_KC+p_KE)/p_JE) + x3*(-(p_BC+p_BE)/p_JE) + x2*(p_KC/p_JE) + x4*(p_BC/p_JE) + x5*(p_KT*p_N/p_JE) - p_ME*p_LE*p_g*sin(x1*M_PI/180)/p_JE);
}

long double f4(long double t, long double x1, long double x2, long double x3, long double x4, long double x5)
{
	return(x1*(p_KC/p_JH) + x3*(p_BC/p_JH)+ x2*(-(p_KC+p_KH)/p_JH) + x4*(-(p_BC+p_BH)/p_JH) - p_MH*p_LH*p_g*sin(x2*M_PI/180)/p_JH);
}

long double f5(long double t, long double x1, long double x2, long double x3, long double x4, long double x5)
{
	return(x3*(-p_KEMF*p_N/p_LA) + x5*(-p_RA/p_LA) + v(t)*(1/p_LA));
}

long double v(long double t)
{
	// Read from ADC at time t
	// Convert to voltage in volts
	/*if(t<1)
	{
		return(0.0);
	} else
	{
		return(1.0);
	}*/
	return 0.0;
}
