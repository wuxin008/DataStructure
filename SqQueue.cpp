#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct {
	char name[20];
	int age;
} QElemType;

//顺序队列
typedef struct {
	QElemType* base;
	int front;
	int rear;
} SqQueue;

//初始化顺序队列
Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXSIZE];
	if (!Q.base)
		return OVERFLOW;
	Q.front = Q.rear = 0;
	return OK;
}

//销毁顺序队列
Status DestroyQueue(SqQueue& Q)
{
	if (!Q.base)
		return ERROR;
	delete[] Q.base;
	return OK;
}

//清空顺序队列
Status ClearQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;
	return OK;
}

//判断顺序队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

//求顺序队列的长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//求顺序队列的队头
Status GetHead(SqQueue Q, QElemType& qe)
{
	qe = {};
	if (Q.front != Q.rear)
		qe = Q.base[Q.front];
	return OK;
}

//顺序队列的入队
Status EnQueue(SqQueue& Q, QElemType qe)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return OVERFLOW;
	Q.base[Q.rear] = qe;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}

//顺序队列的出队
Status DeQueue(SqQueue& Q, QElemType& qe)
{
	if (Q.rear == Q.front)
		return ERROR;
	qe = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

//顺序队列的遍历
Status QueueTraverse(SqQueue Q)
{
	int p = Q.front;
	while (p != Q.rear) {
		std::cout << "My name is " << Q.base[p].name
			<< ". And I'm " << Q.base[p].age
			<< " years old." << std::endl;
		p = (p + 1) % MAXSIZE;
	}
	return OK;
}

//测试
int main()
{
	using namespace std;

	SqQueue Q;
	QElemType qe;
	InitQueue(Q);
	cout << "当前队列的长度为" << QueueLength(Q) << endl;
	EnQueue(Q, { "zhangsan", 11 });
	EnQueue(Q, { "lisi", 12 });
	EnQueue(Q, { "wangwu", 13 });
	cout << "现在开始遍历队列\n";
	QueueTraverse(Q);
	cout << "弹出第一个元素并输出：\n";
	DeQueue(Q, qe);
	cout << "My name is " << qe.name
		<< ". And I'm " << qe.age
		<< " years old." << endl;
	cout << "现在开始遍历队列\n";
	QueueTraverse(Q);
	cout << "当前队列的长度为" << QueueLength(Q) <<endl;
	cout << "当前队列是否为空" << QueueEmpty(Q) << endl;
	cout << "现在开始清空队列\n";
	ClearQueue(Q);
	cout << "当前队列的长度为" << QueueLength(Q) << endl;
	DestroyQueue(Q);
	return 0;
}
