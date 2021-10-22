#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct {
	char name[20];
	int age;
}SElemType;

typedef struct StackNode {
	SElemType data;
	StackNode* next;
} StackNode, * LinkStack;

Status InitStack_L(LinkStack& S)
{
	S = NULL;
	return OK;
}

Status DestroyStack_L(LinkStack& S)
{
	StackNode* sp = S;
	while (sp) {
		S = S->next;
		delete sp;
		sp = S;
	}
	return OK;
}

Status ClearStack_L(LinkStack& S)
{
	StackNode* sp = S;
	while (sp) {
		S = S->next;
		delete sp;
		sp = S;
	}
	return OK;
}

bool StackEmpty_L(LinkStack S)
{
	if (S)
		return false;
	else
		return true;
}

int StackLength_L(LinkStack S)
{
	int count = 0;
	StackNode* sp = S;
	while (sp) {
		count++;
		sp = sp->next;
	}
	return count;
}

Status GetTop_L(LinkStack S, SElemType& se)
{
	if (!S)
		return ERROR;
	se = S->data;
	return OK;
}

Status Push_L(LinkStack& S, SElemType se)
{
	StackNode* sp = new StackNode;
	sp->data = se;
	sp->next = S;
	S = sp;
	return OK;
}

Status Pop_L(LinkStack& S, SElemType& se)
{
	if (!S)
		return ERROR;
	StackNode* sp = S;
	se = S->data;
	S = S->next;
	delete sp;
	return OK;
}

Status StackTraverse(LinkStack S)
{
	if (S->next)
		StackTraverse(S->next);
	std::cout << "My name is " << S->data.name
		<< ". And I'm " << S->data.age
		<< " years old." << std::endl;
	return OK;
}

int main()
{
	using namespace std;

	LinkStack S;
	SElemType se;
	InitStack_L(S);
	cout << "��ǰջ�ĳ���Ϊ" << StackLength_L(S) << endl;
	Push_L(S, { "zhangsan", 11 });
	Push_L(S, { "lisi", 12 });
	Push_L(S, { "wangwu", 13 });
	cout << "���ڿ�ʼ����ջ\n";
	StackTraverse(S);
	cout << "�������һ��Ԫ�ز������\n";
	Pop_L(S, se);
	std::cout << "My name is " << se.name
		<< ". And I'm " << se.age
		<< " years old." << std::endl;
	cout << "���ڿ�ʼ����ջ\n";
	StackTraverse(S);
	cout << "��ǰջ�ĳ���Ϊ" << StackLength_L(S) << endl;
	cout << "��ǰջ�Ƿ�Ϊ��" << StackEmpty_L(S) << endl;
	cout << "���ڿ�ʼ���ջ\n";
	ClearStack_L(S);
	cout << "��ǰջ�ĳ���Ϊ" << StackLength_L(S) << endl;
	DestroyStack_L(S);
	return 0;
}