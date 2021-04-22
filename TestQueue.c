#include"Queue.h"


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	Queuepush(&q, 1);
	Queuepush(&q, 2);
	Queuepush(&q, 3);
	Queuepush(&q, 4);
	
	while (!QueueEmpty(&q))
	{
		printf("%d", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);
}
int main()
{
	TestQueue();

}