#include<stdio.h>
#include<stdlib.h>
#define ARSIZE 1000
int main(void)
{
	double number[ARSIZE];
	double value;
	const char*file = "number.dat";
	int i;
	long pos;
	FILE*iofile;
	for (i = 0;i < ARSIZE;i++)
		number[i] = 100.0*i + 1.0 / (i + 1);
	if ((iofile = fopen(file, "w")) == NULL)
	{
		fprintf(stderr, "Coule not open %s for output.\n", file);
		exit(1);
	}
	//fprintf(iofile, "%lf", number);
	fwrite(number, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Coule not open %s for random access.\n", file);
		exit(1);
	}
	printf("Enter an index:");
	scanf("%d", &i);
	while (i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);
		fseek(iofile, pos, SEEK_SET);
	/*	fscanf(iofile, "%lf", &value);*/
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index:\n");
		scanf("%d", &i);
	}
	fclose(iofile);
	puts("Bye!");
	getchar();
	return 0;
}