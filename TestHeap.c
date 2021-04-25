#include"Heap.h"


int main()
{
	int a[] = { 27,15,19,28,34,65,49,25,37 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPush(&hp, 13);
	return 0;
}