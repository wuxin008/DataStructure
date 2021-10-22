#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct {
	char name[20];
	int age;
} SElemType;

//定义顺序栈
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

//初始化栈
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		return OVERFLOW;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//销毁栈
Status DestroyStack(SqStack& S)
{
	if (!S.base)
		return ERROR;
	delete[] S.base;
	return OK;
}

//清空栈
Status ClearStack(SqStack& S)
{
	S.top = S.base;
	return OK;
}

//判断栈是否为空
bool StackEmpty(SqStack S)
{
	if (S.base)
		return false;
	else
		return true;
}

//求栈的长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//返回栈顶元素
SElemType* GetTop(SqStack S)
{
	return S.top;
}

//压入栈
Status Push(SqStack& S, SElemType se)
{
	if (S.top - S.base == S.stacksize)
		return OVERFLOW;
	*S.top++ = se;
	return OK;
}

//弹出并返回其值
Status Pop(SqStack& S, SElemType& se)
{
	if (S.base == S.top)
		return ERROR;
	se = *--S.top;
	return OK;
}

//遍历栈
Status StackTraverse(SqStack S)
{
	SElemType* sp;
	sp = S.base;
	while (sp != S.top) {
		std::cout << "My name is " << sp->name
			<< ". And I'm " << sp->age << " years old."
			<< std::endl;
		sp++;
	}
	return OK;
}

int main()
{
	using namespace std;

	SqStack S;
	SElemType se;
	InitStack(S);
	cout << "目前栈的长度为：" << StackLength(S) << endl;
	Push(S, { "zhangsan", 11 });
	Push(S, { "lisi", 12 });
	Push(S, { "wangwu", 13 });
	cout << "遍历栈:" << endl;
	StackTraverse(S);
	cout << "弹出栈，并输出\n";
	Pop(S, se);
	cout << "My name is " << se.name
		<< ". And I'm " << se.age << " years old."
		<< endl;
	cout << "遍历栈:" << endl;
	StackTraverse(S);
	cout << "目前栈的长度为：" << StackLength(S) << endl;
	ClearStack(S);
	cout << "目前栈的长度为：" << StackLength(S) << endl;
	DestroyStack(S);
	return 0;
}
