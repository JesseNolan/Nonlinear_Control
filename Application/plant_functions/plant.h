/*
 * plant.h
 *
 *  Created on: Aug 12, 2016
 *      Author: silenus
 */

#ifndef PLANT_H_
#define PLANT_H_

#include "math.h"

long double f1(long double t, long double x1, long double x2, long double x3, long double x4, long double x5);
long double f2(long double t, long double x1, long double x2, long double x3, long double x4, long double x5);
long double f3(long double t, long double x1, long double x2, long double x3, long double x4, long double x5);
long double f4(long double t, long double x1, long double x2, long double x3, long double x4, long double x5);
long double f5(long double t, long double x1, long double x2, long double x3, long double x4, long double x5);
long double v(long double t);


extern const double p_KEMF;
extern const double p_KT;
extern const double p_KE;
extern const double p_KC;
extern const double p_KH;
extern const double p_KG;
extern const double p_BE;
extern const double p_BC;
extern const double p_BH;
extern const double p_JE;
extern const double p_JH;
extern const double p_N;
extern const double p_LA;
extern const double p_RA;
extern const double p_MH;
extern const double p_ME;
extern const double p_LE;
extern const double p_LH;
extern const double p_g;


#endif /* PLANT_H_ */
