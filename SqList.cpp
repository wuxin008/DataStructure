#include<iostream>
#include<string>

using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

/*
* 数据元素：学生个人信息
* name：学生姓名
* ID：学生ID
* 结构体名称：ElemType
*/
typedef struct
{
	string name;
	string ID;
} ElemType;

/*
* ElemType线性表
* 线性表名称SqList
*/
typedef struct
{
	ElemType* elem;
	int Length;
} SqList;

/*
* 函数名：InitList_Sq
* 功能：初始化一个线性表
* 输入参数：L（SqList）类型
* 返回值：Status类型
*			OK为成功初始化
*			否则程序将退出
*/
Status InitList_Sq(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.Length = 0;
	return OK;
}

/*
* 函数名：DestroyList
* 功能：销毁线性表
* 输入参数：L（SqList类型）
* 返回值：无
*/
void DestroyList(SqList& L)
{
	if (L.elem)
		delete[] L.elem;
}

/*
* 函数名：ClearList
* 功能：清空线性表
* 输入参数：L（SqList类型）
* 返回值：无
*/
void ClearList(SqList& L)
{
	L.Length = 0;
}

/*
* 函数名：GetLength
* 功能：求线性表的长度
* 输入参数：L（SqList类型）
* 返回值：int类型
*/
int GetLength(SqList L)
{
	return L.Length;
}

/*
* 函数名：IsEmpty
* 功能：判断线性表是否为空
* 输入参数：L（SqList类型）
* 返回值：Status类型
*			TRUE为非空
*			FALSE为空
*/
Status IsEmpty(SqList L)
{
	if (L.Length == 0)
		return TRUE;
	else
		return FALSE;
}

/*
* 函数名：ListInsert
* 功能：插入一个新元素进线性表
* 输入参数：L（SqList类型）
*			i （int类型）
*			e（ElemType类型）
* 返回值：Status类型
*			ERROR为错误
*			OK为正常
*/
Status ListInsert(SqList& L, int i, ElemType e)
{
	if ((i < 1) || (i > L.Length + 1))
		return ERROR;
	if (L.Length == MAXSIZE)
		return ERROR;
	for (int j = L.Length - 1; j >= i - 1; --j)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.Length;
	return OK;
}

/*
* 函数名：GetElem
* 功能：取出i位置的元素
* 输入参数：L（SqList类型）
*			i （int类型）
*			e（ElemType类型
* 返回值：Status类型
*			ERROR为错误
*			OK为正常
*/
Status GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.Length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

/*
* 函数名：isEqualElem
* 功能：判断两个ElemType类型值是否相等
* 输入参数：e1（ElemType类型）
*			e2（ElemType类型）
* 返回值：int类型
*			1为相等
*			0为不相等
*/
int isEqualElem(ElemType e1, ElemType e2)
{
	if (e1.ID == e2.ID && e1.name == e2.name)
		return 1;
	return 0;
}
/*
* 函数名：LocateElem
* 功能：查找线性表中的某个元素
* 输入参数：L（SqList类型）
*			e（ElemType类型）
* 返回值：int类型
*			查找失败返回0
*			否则返回元素所在位置
*/
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.Length; ++i)
	{
		if (isEqualElem(L.elem[i], e))
			return i + 1;
	}
	return 0;
}
/*
* 函数名：ListDelete
* 功能：功能线性表第i个元素
* 输入参数：L（Sqlist类型）
*			i（int类型）
* 返回值：Status
*			ERROR为错误
*			OK为正确
*/
Status ListDelete(SqList& L, int i)
{
	if ((i < 1) || (i > L.Length))
		return ERROR;
	for (int j = i; j <= L.Length - 1; ++j)
		L.elem[j - 1] = L.elem[j];
	--L.Length;
	return OK;
}
/*
* 函数名：putList
* 功能：输出线性表里的所有值
* 输入参数：L（Sqlist类型）
* 返回值：Status
*			ERROR为错误
*			OK为正确
*/
Status putList(SqList& L)
{
	if (L.Length == 0)
	{
		return ERROR;
	}
	ElemType e;
	cout << "开始输出线性表中的内容:" << endl;
	for (int i = 1; i <= L.Length; ++i) {
		GetElem(L, i, e);
		cout << "姓名为" + e.name + "的学号为" + e.ID << endl;
	}
	cout << "输出完毕" << endl;
}
//测试
int main()
{
	SqList sl;
	if (InitList_Sq(sl))//创建链表
		cout << "线性表创建成功" << endl;
	if (IsEmpty(sl))//判断是否为空表
		cout << "当前线性表为空表" << endl;
	else
		cout << "当前线性表不为空表" << endl;
	ListInsert(sl, 1, { "zhangsan", "zhangsan123" });//插入
	ListInsert(sl, 2, { "lisi", "lisi123" });//插入
	ListInsert(sl, 3, { "wangwu", "wangwu123" });//插入
	putList(sl);//利用取值函数输出链表
	cout << "查找zhangsan位置..." << endl;
	int i = LocateElem(sl, { "zhangsan", "zhangsan123" });//查找
	cout << "为第";
	cout << i;
	cout << "个" << endl;
	cout << "删除第三个元素" << endl;
	ListDelete(sl, 3);//删除
	putList(sl);//输出测试结果
	ClearList(sl);//清空链表
	cout << "执行ClearList函数后" << endl;
	if (IsEmpty(sl))
		cout << "当前线性表为空表" << endl;
	else
		cout << "当前线性表不为空表" << endl;
	DestroyList(sl);//销毁链表
}
