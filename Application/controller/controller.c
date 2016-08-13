

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

Con_coeffs con_coeffs;
Signals signals;

signals.e[5] = {0,0,0,0,0};
signals.u[6] = {0,0,0,0,0,0};


void controller(Signals *s, Con_coeffs *c)
{
	s->u[1] = c->a1*s->u[2] + c->a2*s->u[3] + c->a3*s->u[4] + c->a4*s->u[5] + c->a5*s->u[6] + c->b1*s->e[1] + c->b2*s->e[2] + c->b3*s->e[3] + c->b4*s->e[4] + c->b5*s->e[5];
}

void increment(Signals *s)
{
	s->u[6] = s->u[5];
	s->u[5] = s->u[4];
	s->u[4] = s->u[3];
	s->u[3] = s->u[2];
	s->u[2] = s->u[1];
	
	s->e[5] = s->e[4];
	s->e[4] = s->e[3];
	s->e[2] = s->e[1];
}
