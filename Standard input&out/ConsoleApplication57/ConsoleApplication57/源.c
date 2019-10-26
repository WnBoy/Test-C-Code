#include<stdio.h>
#include<math.h>
int main()
{
	float gg(float(*p)(float), float a, float b, int n);
	void fsin(float x);
	void fcos(float x);
	void fexp(float x);
	float a1, a2, b1, b2, c1, c2, z,(*p)(float);
	int n = 20;
	printf("please inter a1 and a2:");
	scanf("%f,%f", &a1, &a2);
	printf("please inter b1 and b2:");
	scanf("%f,%f", &b1, &b2);
	printf("please inter c1 and c2:");
	scanf("%f,%f", &c1, &c2);
	p = fsin;
	z = gg(p, a1, a2, n);
	printf("The gg of sin(x) is:%f\n", z);
	p = fcos;
	z = gg(p, b1, b2, n);
	printf("The gg of cos(x) is:%f\n",z);
	p = fexp;
	z = gg(p, c1, c2, n);
	printf("The gg of exe(x) is:%f\n", z);
	getchar();
	getchar();
	return 0;
}
float gg(float(*p)(float), float a, float b, int n)
{
	int i;
	float x, h, s;
	h = (b - a) / n;
	s = 0;
	x = a;
	for (i = 1;i <=n;i++)
	{
		x = x + h;
		s = s + (*p)(x)*h;
	}
	return (s);
}
void fsin(float x)
{
	return(sin(x));
}
void fcos(float x)
{
	return(cos(x));
}
void fexp(float x)
{
	return(exp(x));
}