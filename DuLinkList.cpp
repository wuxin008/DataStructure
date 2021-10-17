#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

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

typedef struct DuLNode {
	ElemType data;
	DuLNode* prior;
	DuLNode* next;
}DuLNode, * DuLinkList;

Status InitList_DuL(DuLinkList& L)
{
	L = new DuLNode;
	if (!L)
		return OVERFLOW;
	L->prior = NULL;
	L->next = NULL;
	return OK;
}

DuLNode* LocateList_DuL(DuLinkList L, int i)
{
	int n = 1;
	DuLNode* p = L->next;
	while (p && n < i) {
		p = p->next;
		n++;
		n++;
	}
	if (!p || n > i + 1)
		return ERROR;
	return p;
}

Status InsertElem_DuL(DuLinkList& L, int i, ElemType e)
{
	int n = 1;
	DuLNode* p = L;
	while (p && n < i) {
		p = p->next;
		n++;
	}
	if (!p || n > i + 1)
		return ERROR;
	DuLNode* s = new DuLNode;
	s->data = e;
	s->next = p->next;
	s->prior = p;
	if (p->next)
		p->next->prior = s;
	p->next = s;
	return OK;
}

Status DeleteElem_DuL(DuLinkList& L, int i)
{
	int n = 1;
	DuLNode* p = L->next;
	while (p && n < i) {
		p = p->next;
		n++;
	}
	if (!p || n > i)
		return ERROR;
	p->prior->next = p->next;
	if (p->next)
		p->next->prior = p->prior;
	delete p;
	return OK;
}

void putDuL(DuLinkList L)
{
	DuLNode* p = L;
	std::cout << "顺序输出:\n";
	while (p->next) {
		p = p->next;
		std::cout << "My name is " << p->data.getName()
			<< ", and i am " << p->data.getAge()
			<< " years old now." << std::endl;
	}
	std::cout << "倒序输出:\n";
	while (p->prior) {
		std::cout << "My name is " << p->data.getName()
			<< ", and i am " << p->data.getAge()
			<< " years old now." << std::endl;
		p = p->prior;
	}
}

int main()
{
	DuLinkList L;
	InitList_DuL(L);
	for (int i = 1; i <= 3; i++) {
		ElemType e;
		e.setElem();
		InsertElem_DuL(L, i, e);
	}
	InsertElem_DuL(L, 1, ElemType("wuxin", 10));
	putDuL(L);
	std::cout << "\n";
	DeleteElem_DuL(L, 1);
	DeleteElem_DuL(L, 3);
	putDuL(L);
	std::cout << "\n";
}
