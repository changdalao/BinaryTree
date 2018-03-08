#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;

typedef struct QueueNode
{
	DataType data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

//½Ó¿Ú²Ù×÷
void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);

void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = NULL;
}

void QueuePush(Queue* q, DataType x)
{
	assert(q);
	QueueNode* node;
	node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_next = NULL;
	node->data = x;
	assert(node);

	if (q->_tail == NULL)
	{
		q->_head = q->_tail = node;
	}
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_head==q->_tail)
	{
		if (q->_head)
		{
			free(q->_head);
			q->_head = q->_tail = NULL;
		}
	}
	else
	{
		QueueNode* next = q->_head->_next;
		free(q->_head);
		q->_head = next;
	}
}

DataType QueueFront(Queue* q)
{
	assert(q);
	
	return q->_head->data;
}

DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->data;
}
size_t QueueSize(Queue* q)
{
	assert(q);
	size_t count = 0;
	while (q->_head)
	{
		q->_head = q->_head->_next;
		++count;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 0 : 1;
}

void test2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}
