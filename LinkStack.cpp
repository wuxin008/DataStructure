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

//链栈
typedef struct StackNode {
	SElemType data;
	StackNode* next;
} StackNode, * LinkStack;

//初始化链栈
Status InitStack_L(LinkStack& S)
{
	S = NULL;
	return OK;
}

//销毁链栈
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

//清空链栈
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

//判断链栈是否为空
bool StackEmpty_L(LinkStack S)
{
	if (S)
		return false;
	else
		return true;
}

//求链栈长度
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

//取链栈顶部元素
Status GetTop_L(LinkStack S, SElemType& se)
{
	if (!S)
		return ERROR;
	se = S->data;
	return OK;
}

//将元素压入链栈
Status Push_L(LinkStack& S, SElemType se)
{
	StackNode* sp = new StackNode;
	sp->data = se;
	sp->next = S;
	S = sp;
	return OK;
}

//从链栈顶部取出链栈
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

//遍历链栈
Status StackTraverse(LinkStack S)
{
	if (S->next)
		StackTraverse(S->next);
	std::cout << "My name is " << S->data.name
		<< ". And I'm " << S->data.age
		<< " years old." << std::endl;
	return OK;
}

//测试
int main()
{
	using namespace std;

	LinkStack S;
	SElemType se;
	InitStack_L(S);
	cout << "当前栈的长度为" << StackLength_L(S) << endl;
	Push_L(S, { "zhangsan", 11 });
	Push_L(S, { "lisi", 12 });
	Push_L(S, { "wangwu", 13 });
	cout << "现在开始遍历栈\n";
	StackTraverse(S);
	cout << "弹出最后一个元素并输出：\n";
	Pop_L(S, se);
	std::cout << "My name is " << se.name
		<< ". And I'm " << se.age
		<< " years old." << std::endl;
	cout << "现在开始遍历栈\n";
	StackTraverse(S);
	cout << "当前栈的长度为" << StackLength_L(S) << endl;
	cout << "当前栈是否为空" << StackEmpty_L(S) << endl;
	cout << "现在开始清空栈\n";
	ClearStack_L(S);
	cout << "当前栈的长度为" << StackLength_L(S) << endl;
	DestroyStack_L(S);
	return 0;
}
