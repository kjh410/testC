#if 0
#include <stdio.h>

int *f1(void)
{
	static int a[4] = { 1,2,3,4 };
	return a;
}

int *f2(void)
{
	static int a[4] = { 10, 20, 30, 40 };
	return a;
}

int *(*fa[2])() = { f1, f2 };

int f4(void)
{
	return 1;
}

int *(**func1(void))()
{
	return fa;
}

int *(*func2(int (*p)(void)))()
{
	return func1()[p()];
}

void  main(void)
{
	printf("%d\n", func2(f4)()[3]);
}
#endif

#if 0
#include <stdio.h>
int  add(int a, int b) 
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int(*func[2])(int, int) = { add,sub };

void main(void)
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;

	printf("%s ", **++cpp);
	printf("%s ", *--*++cpp + 3);
	printf("%s ", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);


	printf("%s ", cpp[-1][0]);
}
#endif

#if 0
#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int x = 2, y = 3, z = 4;
	int ***a = (int ***)malloc(4 * sizeof(int (*)[3]));
	int ***b = (int ***)malloc(2 * sizeof(int[3][4]));
	int ***c = (int ***)malloc(x*y*z * sizeof(int));
}


#endif

#if 0
#include <stdio.h>

void main(void)
{
	char a[] = "Motel";
	//char *p = "Motel";

	a[0] = 'H';
	//p[0] = 'H';

	printf("%s", a);
	//printf("%s", p);
}


#endif

