#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct {
	char name[20];
	int age;
}QElemType;

//定义链节点
typedef struct QNode
{
	QElemType data;
	QNode* next;
}QNode, * QueuePtr;

//定义链队列
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化链队列
Status InitQueue_L(LinkQueue& Q)
{
	Q.front = Q.rear = new QNode;
	if (!Q.front)
		return OVERFLOW;
	Q.front->next = NULL;
	return OK;
}

//销毁链队列
Status DestroyQueue_L(LinkQueue& Q)
{
	QNode* p = Q.front;
	while (p) {
		Q.front = Q.front->next;
		delete p;
		p = Q.front;
	}
	return OK;
}

//清空链队列
Status ClearQueue_L(LinkQueue& Q)
{
	QNode* p = Q.front->next;
	QNode* q = p;
	while (q) {
		p = p->next;
		delete q;
		q = p;
	}
	return OK;
}

//判断链队列是否为空
bool QueueEmpty_L(LinkQueue Q)
{
	if (Q.front->next)
		return true;
	else
		return false;
}

//求链队列的长度
int QueueLength_L(LinkQueue Q)
{
	int count = 0;
	QNode* p = Q.front->next;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

//返回链队列的头元素
Status GetHead_L(LinkQueue Q, QElemType& qe)
{
	if (Q.front == Q.rear)
		return ERROR;
	qe = Q.front->next->data;
	return OK;
}

//链队列的入队
Status EnQueue_L(LinkQueue& Q, QElemType qe)
{
	QNode* p = new QNode;
	p->data = qe;
	Q.rear->next = p;
	p->next = NULL;
	Q.rear = p;
	return OK;
}

//链队列的出队
Status DeQueue_L(LinkQueue& Q, QElemType& qe)
{
	if (Q.rear == Q.front)
		return ERROR;
	QNode* p = Q.front->next;
	qe = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}

//链队列的遍历
Status QueueTraverse_L(LinkQueue Q)
{
	QNode* p = Q.front->next;
	while (p) {
		std::cout << "My name is " << p->data.name
			<< ". And I'm " << p->data.age
			<< " years old." << std::endl;
		p = p->next;
	}
	return OK;
}

int main()
{
	using namespace std;

	LinkQueue Q;
	QElemType qe;
	InitQueue_L(Q);
	cout << "当前队列的长度为" << QueueLength_L(Q) << endl;
	EnQueue_L(Q, { "zhangsan", 11 });
	EnQueue_L(Q, { "lisi", 12 });
	EnQueue_L(Q, { "wangwu", 13 });
	cout << "现在开始遍历队列\n";
	QueueTraverse_L(Q);
	cout << "弹出第一个元素并输出：\n";
	DeQueue_L(Q, qe);
	cout << "My name is " << qe.name
		<< ". And I'm " << qe.age
		<< " years old." << endl;
	cout << "现在开始遍历队列\n";
	QueueTraverse_L(Q);
	cout << "当前队列的长度为" << QueueLength_L(Q) << endl;
	cout << "当前队列是否为空" << QueueEmpty_L(Q) << endl;
	cout << "现在开始清空队列\n";
	ClearQueue_L(Q);
	cout << "当前队列的长度为" << QueueLength_L(Q) << endl;
	DestroyQueue_L(Q);
	return 0;
}
