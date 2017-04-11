//#include<iostream>
//using namespace std;
//#define STACK_INIT_SIZE 100//初始大小
//#define STACK_INCREMENT 10//增量
////栈的使用
////构建一个栈结构体
//typedef struct Stack
//{
//	int *base;
//	int *top;
//	int stacksize;
//
//}SqStack;
//
////1构造一个空栈S
//void InitStack(SqStack &S)
//{
//	S.base = (int*)malloc(STACK_INIT_SIZE*sizeof(int)); //或者用new 
//	//int *base = new int[100];//这样也可以
//	if (!S.base)
//		exit(0);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;//栈的大小
//}
////2判断是否为空
//bool GetTop(SqStack S,int &e)
//{
//	if (S.top == S.base)//若栈为非空，则用e返回栈顶元素，否则返回0
//		return true;
//	//e = *(S.top - 1);
//	return false ;
//
//}
////3栈的长度
//int StackLength(SqStack S)
//{ 
//	int i=0;
//	while (S.top != NULL)
//	{
//		i++;
//	}
//	/*S = i;*/
//	return i;
//}
////4栈的插入函数
//void Push(SqStack &S,int e)
//{
//	//判断栈是否满,若栈满则追加存储空间
//	if (S.top - S.base >= S.stacksize)
//	{
//
//		S.base = (int*)realloc(S.base, (S.stacksize + STACK_INCREMENT)*sizeof(int));
//		if (!S.base)
//			exit(0);
//		S.top = S.base + S.stacksize;
//		S.stacksize += STACK_INCREMENT;
//	}
//	*S.top++ = e;
//}
////5删除函数
//int  Pop(SqStack &S, int e)//删除e
//{
//	if (S.top == S.base)
//		return 0;
//	e = *--S.top;
//
//}
////6栈的销毁函数
//void Destroy_Stack(SqStack &S)
//{
//	delete ;
//}
//int main()
//{
//
//	return 0;
//}
#include<iostream>
using namespace std;
# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10 //增加栈的长度
//栈结构体
typedef  struct Stack
{
	int  * base;
	int  * top;
	int   stacksize;//当前栈可使用的最大容量
} SqStack;

void InitStack(SqStack &S)//构造一个空栈，并且容量为100
{
	S.base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));//分配储存空间
	//int *base = new int[100];//也可以
	if (!S.base) 
	{ 
		cout << "存储分配失败!!!" << endl; 
	}
	else
	{
		S.top = S.base;
		S.stacksize = STACK_INIT_SIZE;
		cout << "构造成功!!!" << endl;
	}
}

void Push(SqStack &S, int e)//插入元素e为栈顶元素
{
	if (S.top - S.base >= S.stacksize)//判断里面的元素是否满了
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(int));
		if (!S.base)
			cout << "存储分配失败!!!" << endl << endl;
		else
		{
			S.stacksize += STACKINCREMENT;//当前长度为110
			S.top = S.base + S.stacksize;//最大容量为110
		}
	}
	*S.top++ = e;//把e加到最顶端
}

void DisplayStack(SqStack &S) //从栈底到栈顶逐次显示栈中的元素
{
	int *p;
	p = S.base;
	if (S.base == S.top)	
		cout << "当前栈为空栈!!!" << endl << endl;
	else
	{
		cout << "当前栈内元素为: ";
		while (p != S.top)
		{
			cout << *(p) << " ";
			p++;
		}
		cout << endl;
	}
}

int StackLength(SqStack S) //求长度
{
	int *p;
	p = S.base;
	int i = 0;
	while (p != S.top) { p++; i++; }
	return i;
}

void pop(SqStack &S, int &e) //出栈
{
	if (S.top == S.base) cout << "操作失败!!!" << endl << endl;
	else
	{
		e = *--S.top;
		DisplayStack(S);
	}
}
void ClearStack(SqStack &S)//清空
{
	int b;
	while (S.top != S.base)
		b = *--S.top;
	if (S.top == S.base) 
		cout << "顺序栈已清空!!!" << endl << endl;
}

void StackEmpty(SqStack S)//判空
{
	if (S.top == S.base)
		cout << "顺序栈为空!!!" << endl << endl;
	else
		cout << "顺序栈不为空!!!" << endl << endl;
}

void DestroyStack(SqStack &S)
{
	S.base = NULL;
	cout << "顺序栈已销毁!!!" << endl << endl;
}

void GetTop(SqStack S, int &e)//返回栈顶元素
{
	if (S.top == S.base) cout << "操作失败!!!" << endl << endl;
	else
	{
		cout << "栈顶元素为: ";
		e = *(S.top - 1);
		cout << e << endl << endl;
	}
}

int main()
{

	cout << "*  1、构造一个空栈       *" << endl;
	cout << "*  2、输入栈的元素       *" << endl;
	cout << "*  3、输出栈的元素       *" << endl;
	cout << "*  4、求栈的长度         *" << endl;
	cout << "*  5、求栈顶元素         *" << endl;
	cout << "*  6、删除栈顶元素       *" << endl;
	cout << "*  7、清空已存在的栈     *" << endl;
	cout << "*  8、判断栈是否为空     *" << endl;
	cout << "*  0、销毁栈             *" << endl;

	int n, k;
	SqStack S;

	for (n = 0; n<15; n++)
	{
		cout << "请选择0-8:  ";
		cin >> k;
		if (k == 0) { 
			DestroyStack(S);
			n = 15; 
		}
		if (k == 1) 
			InitStack(S);
		if (k == 2)
		{
			int a;
			cout << "输入栈S的元素为: ";
			cin >> a;
			Push(S, a);
			DisplayStack(S);
		}
		if (k == 3) DisplayStack(S);
		if (k == 4) cout << "栈的长度为: " << StackLength(S) << endl << endl;
		if (k == 5) { int c; GetTop(S, c); }
		if (k == 6) { int b; pop(S, b); }
		if (k == 7) ClearStack(S);
		if (k == 8) StackEmpty(S);

	}
	return 0;
}
