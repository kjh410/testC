//#include <iostream>
//using namespace std;
//
//class SelfRef {
//	int num;
//public:
//	SelfRef(int n) : num(n)
//	{
//		cout << "Create object" << endl;
//	}
//	SelfRef* Adder(int n)
//	{
//		num += n;
//		return this;
//	}
//	SelfRef* ShowTwonumber()
//	{
//		cout << num << endl;
//		return this;
//	}
//};
//
//int main(void)
//{
//	SelfRef obj(3);
//	SelfRef *ref = obj.Adder(2);
//
//	obj.ShowTwonumber();
//	ref->ShowTwonumber();
//
//	ref->Adder(1)->ShowTwonumber()->Adder(2)->ShowTwonumber();
//	return 0;
//}


#include "header.h"

extern int a = 10;
static int b = 10;
int lastnode;
int Heap_Push_Minheap(int *heap, int size, int* lastnode, int d)
{
	int tmp, idx, parent;
	if (*lastnode >= size) return 0;
	idx = ++(*lastnode);
	heap[idx] = d;
	while (idx >= 2)
	{
		parent = idx / 2;
		if (heap[parent] < heap[idx]) break;
		tmp = heap[parent];
		heap[parent] = heap[idx];
		heap[idx] = tmp;
		idx = parent;
	}
}
int Heap_Pop_Minheap(int *heap, int *lastnode, int *d)
{
	int idx, ch1, ch2, tmp, minch;
	if (*lastnode == 0)	return -1;
	*d = heap[1];
	idx = 1; ch1 = 2; ch2 = 3;
	heap[1] = heap[(*lastnode)--];
	while (ch1 <= *lastnode)
	{
		if (ch1 == *lastnode)	minch = ch1;
		else					minch = (heap[ch1] < heap[ch2]) ? ch1 : ch2;
		if (heap[idx] < heap[minch])	break;
		tmp = heap[idx];
		heap[idx] = heap[minch];
		heap[minch] = tmp;
		idx = minch;
		ch1 = idx * 2;
		ch2 = ch1 + 1;
	}
}

struct _st1
{
	unsigned char a : 2;
	unsigned char b : 3;
	unsigned char c : 2;
}x;

struct _st2
{
	unsigned int a : 2;
	unsigned int b : 3;
	unsigned int c : 2;
}y;


int main(void)
{
	unsigned short a = 0xffff;
	short b = 0xffff;
	printf("%x %x\n", -a, -b);

	y.a = x.a = 0x2;
	y.b = x.b = 0x5;
	y.c = x.c = 0x1;
	float c = 4.25f;
	printf("%d %d \n", sizeof(x), sizeof(y));
	printf("%#X %#X %#X %#X %#X %#X\n", x.a, x.b, y.a, y.b, x.c, y.c);
	printf("%#.2X %#.8X \n", *(unsigned char*)&x, *(unsigned int*)&y);
	printf("%d\n", c);
	/*short a = 0xfa;
	char b = 0xfa;

	printf("%x %d\n", -a, -a);
	printf("%x %d\n", -b, -b);*/
	return 0;
}