
#ifndef RK4_H_
#define RK4_H_

//structs to pass to other files
typedef struct {
	long double t;
	long double x1;
	long double x2;
	long double x3;
	long double x4;
	long double x5;
} Step_values;

typedef struct {
	long double k1;
	long double k2;
	long double k3;
	long double k4;
	long double l1;
	long double l2;
	long double l3;
	long double l4;
	long double p1;
	long double p2;
	long double p3;
	long double p4;
	long double m1;
	long double m2;
	long double m3;
	long double m4;
	long double q1;
	long double q2;
	long double q3;
	long double q4;
} RK_coeffs;

extern Step_values curr_step;
extern Step_values next_step;


//function prototypes
Step_values RK_main(Step_values curr_step);
void step1(RK_coeffs *c, Step_values *s);
void step2(RK_coeffs *c, Step_values *s);
void step3(RK_coeffs *c, Step_values *s);
void step4(RK_coeffs *c, Step_values *s);
void nextstep(RK_coeffs *c, Step_values *curr, Step_values *next);

extern long double h;

#endif 
