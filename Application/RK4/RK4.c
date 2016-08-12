/*
 * RK4.c
 *
 *  Created on: 12 Aug 2016
 *      Author: silenus
 */
#include "plant.h"
#include "RK4.h"

// Struct accessible only from the source file (not needed in other files)

long double h = 0.005;	//step size in seconds

Step_values curr_step;
Step_values next_step;


Step_values RK_main(Step_values curr_step)
{
	RK_coeffs rk_coeffs;
	Step_values next_step;
	
	step1(&rk_coeffs,&curr_step);
	step2(&rk_coeffs,&curr_step);
	step3(&rk_coeffs,&curr_step);
	step4(&rk_coeffs,&curr_step);
	nextstep(&rk_coeffs,&curr_step,&next_step);
	
	return(next_step);
}

void step1(RK_coeffs *c, Step_values *s)
{
	c->k1 = f1(s->t,s->x1,s->x2,s->x3,s->x4,s->x5);
	c->l1 = f2(s->t,s->x1,s->x2,s->x3,s->x4,s->x5);
	c->p1 = f3(s->t,s->x1,s->x2,s->x3,s->x4,s->x5);
	c->m1 = f4(s->t,s->x1,s->x2,s->x3,s->x4,s->x5);
	c->q1 = f5(s->t,s->x1,s->x2,s->x3,s->x4,s->x5);
}

void step2(RK_coeffs *c,Step_values *s)
{
	c->k2 = f1(s->t+h/2, s->x1+h*c->k1/2, s->x2+h*c->l1/2, s->x3+h*c->p1/2, s->x4+h*c->m1/2, s->x5+h*c->q1/2);
	c->l2 = f2(s->t+h/2, s->x1+h*c->k1/2, s->x2+h*c->l1/2, s->x3+h*c->p1/2, s->x4+h*c->m1/2, s->x5+h*c->q1/2);
	c->p2 = f3(s->t+h/2, s->x1+h*c->k1/2, s->x2+h*c->l1/2, s->x3+h*c->p1/2, s->x4+h*c->m1/2, s->x5+h*c->q1/2);
	c->m2 = f4(s->t+h/2, s->x1+h*c->k1/2, s->x2+h*c->l1/2, s->x3+h*c->p1/2, s->x4+h*c->m1/2, s->x5+h*c->q1/2);
	c->q2 = f5(s->t+h/2, s->x1+h*c->k1/2, s->x2+h*c->l1/2, s->x3+h*c->p1/2, s->x4+h*c->m1/2, s->x5+h*c->q1/2);
}

void step3(RK_coeffs *c, Step_values *s)
{
	c->k3 = f1(s->t+h/2, s->x1+h*c->k2/2, s->x2+h*c->l2/2, s->x3+h*c->p2/2, s->x4+h*c->m2/2, s->x5+h*c->q2/2);
	c->l3 = f2(s->t+h/2, s->x1+h*c->k2/2, s->x2+h*c->l2/2, s->x3+h*c->p2/2, s->x4+h*c->m2/2, s->x5+h*c->q2/2);
	c->p3 = f3(s->t+h/2, s->x1+h*c->k2/2, s->x2+h*c->l2/2, s->x3+h*c->p2/2, s->x4+h*c->m2/2, s->x5+h*c->q2/2);
	c->m3 = f4(s->t+h/2, s->x1+h*c->k2/2, s->x2+h*c->l2/2, s->x3+h*c->p2/2, s->x4+h*c->m2/2, s->x5+h*c->q2/2);
	c->q3 = f5(s->t+h/2, s->x1+h*c->k2/2, s->x2+h*c->l2/2, s->x3+h*c->p2/2, s->x4+h*c->m2/2, s->x5+h*c->q2/2);
}

void step4(RK_coeffs *c, Step_values *s)
{
	c->k4 = f1(s->t+h, s->x1+h*c->k3, s->x2+h*c->l3, s->x3+h*c->p3, s->x4+h*c->m3, s->x5+h*c->q3);
	c->l4 = f2(s->t+h, s->x1+h*c->k3, s->x2+h*c->l3, s->x3+h*c->p3, s->x4+h*c->m3, s->x5+h*c->q3);
	c->p4 = f3(s->t+h, s->x1+h*c->k3, s->x2+h*c->l3, s->x3+h*c->p3, s->x4+h*c->m3, s->x5+h*c->q3);
	c->m4 = f4(s->t+h, s->x1+h*c->k3, s->x2+h*c->l3, s->x3+h*c->p3, s->x4+h*c->m3, s->x5+h*c->q3);
	c->q4 = f5(s->t+h, s->x1+h*c->k3, s->x2+h*c->l3, s->x3+h*c->p3, s->x4+h*c->m3, s->x5+h*c->q3);
}

void nextstep(RK_coeffs *c, Step_values *curr, Step_values *next)
{
	next->t = curr->t + h;
	next->x1 = curr->x1 + (c->k1 + 2*c->k2 + 2*c->k3+ c->k4)*h/6;
	next->x2 = curr->x2 + (c->l1 + 2*c->l2 + 2*c->l3+ c->l4)*h/6;
	next->x3 = curr->x3 + (c->p1 + 2*c->p2 + 2*c->p3+ c->p4)*h/6;
	next->x4 = curr->x4 + (c->m1 + 2*c->m2 + 2*c->m3+ c->m4)*h/6;
	next->x5 = curr->x5 + (c->q1 + 2*c->q2 + 2*c->q3+ c->q4)*h/6;
}

