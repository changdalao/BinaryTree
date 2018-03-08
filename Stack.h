#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t top;
	size_t end;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);

void StackInit(Stack* s)
{
	assert(s);
	s->end = s->top = 0;
	s->_array = NULL;
}

void StackPush(Stack* s, DataType x)
{
	assert(s);
	if (s->end == s->top)
	{
		size_t size = s->end > 0 ? s->end * 2 : 3;
		s->_array = (DataType*)realloc(s->_array, sizeof(DataType)*size);
		assert(s);
		s->end = size;
	}
	s->_array[s->top++] = x;	
}

void StackPop(Stack* s)
{
	assert(s);
	--s->top;
}

DataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->top-1];
}

size_t StackSize(Stack* s)
{
	assert(s);
	return s->top;
}

//·µ»Ø0¾ÍÊÇ¿Õ
int StackEmpty(Stack* s)
{
	assert(s);
	return s->top;
}

//void test1()
//{
//	Stack s1;
//	StackInit(&s1);
//	StackPush(&s1, 1);
//	StackPush(&s1, 2);
//	StackPush(&s1, 3);
//	StackPush(&s1, 4);
//	StackPush(&s1, 5);
//	while (StackEmpty(&s1))
//	{
//		printf("%d ", StackTop(&s1));
//		StackPop(&s1);
//	}
//	printf("\n");
//}
