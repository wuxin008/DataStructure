#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Statue;

class ElemType
{
private:
	char name[20];
	int age;
public:
	ElemType()
	{
		std::strcpy(name, "空");
		age = 0;
	}
	ElemType(const char* m_name, int m_age)
	{
		std::strcpy(name, m_name);
		age = m_age;
	}
	int getAge()
	{
		return age;
	}
	void setAge(int m_age)
	{
		age = m_age;
	}
	char* getName()
	{
		return name;
	}
	void setName(const char* m_name)
	{
		std::strcpy(name, m_name);
	}
	bool equal(ElemType e)
	{
		if (std::strcmp(name, e.name) && age == e.age)
			return true;
		else
			return false;
	}
	void setElem()
	{
		using namespace std;
		cout << "请输入姓名：\n";
		cin >> name;
		cout << "请输入年龄：\n";
		cin >> age;
	}
};
//定义链表
typedef struct LNode 
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
//链表初始化
Statue InitList_L(LinkList& L)
{
	L = new LNode;
	//L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
//判断链表是否为空
bool ListEmpty_L(LinkList& L)
{
	if (L->next)
		return 1;
	else
		return 0;
}
//销毁链表
Statue DestroyList_L(LinkList& L)
{
	LNode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

//清空链表
Statue ClearList_L(LinkList& L)
{
	LNode* p, * q;
	q = L->next;
	while (q)
	{
		p = q;
		q = q->next;
		delete p;
	}
	L->next = NULL;
	return OK;
}

//返回链表的长度
int ListLength_L(LinkList L)
{
	int n = 0;
	LNode* p = L->next;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}

//链表取值
Statue GetElem_L(LinkList L, int i, ElemType& e)
{
	LNode* p = L->next;
	int n = 1;
	while (p && n < i)
	{
		n++;
		p = p->next;
	}
	if (!p || n > i)
		return ERROR;
	else
	{
		e = p->data;
		return OK;
	}
}

//链表查找
LNode* LocateElem_L(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p && !(p->data.equal(e)))
	{
		p = p->next;
	}
	return p;
}

//链表插入
Statue InsertElem_L(LinkList& L, int i, ElemType e)
{
	int n = 0;
	LNode* p = L;
	while (p && n < i - 1)
	{
		++n;
		p = p->next;
	}
	if (!p || n > i - 1)
		return ERROR;
	else
	{
		LNode* s = new LNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;
	}
}

//链表删除
Statue DeleteElem_L(LinkList& L, int i)
{
	int n = 0;
	LNode* p = L;
	while (p->next && n < i - 1)
	{
		p = p->next;
		n++;
	}
	if (!(p->next) || n > i - 1)
		return ERROR;
	else
	{
		LNode* q = p->next;
		p->next = q->next;
		delete q;
		return OK;
	}
}

//输出链表
Statue putList_L(LinkList L)
{
	LNode* p = L;
	while (p->next)
	{
		p = p->next;
		std::cout << "My name is " << p->data.getName()
			<< ". I'm " << p->data.getAge() << " years old." << std::endl;
	}
	std::cout << "\n";
	return OK;
}

//头插法创建链表
void CreateList_L(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; ++i)
	{
		ElemType e;
		e.setElem();
		LNode* p = new LNode;
		p->data = e;
		p->next = L->next;
		L->next = p;
	}
}

//尾插法建立链表
void CreateList_R(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; ++i)
	{
		ElemType e;
		e.setElem();
		LNode* p = new LNode;
		p->data = e;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

//测试
int main()
{
	LinkList L;
	InitList_L(L);//初始化链表
	InsertElem_L(L, 1, ElemType("zhangsan", 17));//插入
	InsertElem_L(L, 2, ElemType("lisi", 18));//插入
	InsertElem_L(L, 1, ElemType("wangwu", 16));//插入
	putList_L(L);//输出测试结果
	DeleteElem_L(L, 1);//删除
	putList_L(L);//输出测试结果
	ElemType e;
	GetElem_L(L, 1, e);//取值
	std::cout << "My name is " << e.getName()
		<< ". I'm " << e.getAge() << " years old." << std::endl;//测试取值函数
	if (ListEmpty_L(L))//判断链表是否为空
	{
		std::cout << "the length is " << ListLength_L(L) << ".\n";//不为空则输出链表长度
	}
	ClearList_L(L);//清空链表
	DestroyList_L(L);//销毁链表
	LinkList L1;//测试头插法
	CreateList_L(L1, 4);
	putList_L(L1);

	LinkList L2;//测试尾插法
	CreateList_R(L2, 4);
	putList_L(L2);
}
