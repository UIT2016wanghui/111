//#include<iostream>
//using namespace std;
//#define STACK_INIT_SIZE 100//��ʼ��С
//#define STACK_INCREMENT 10//����
////ջ��ʹ��
////����һ��ջ�ṹ��
//typedef struct Stack
//{
//	int *base;
//	int *top;
//	int stacksize;
//
//}SqStack;
//
////1����һ����ջS
//void InitStack(SqStack &S)
//{
//	S.base = (int*)malloc(STACK_INIT_SIZE*sizeof(int)); //������new 
//	//int *base = new int[100];//����Ҳ����
//	if (!S.base)
//		exit(0);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;//ջ�Ĵ�С
//}
////2�ж��Ƿ�Ϊ��
//bool GetTop(SqStack S,int &e)
//{
//	if (S.top == S.base)//��ջΪ�ǿգ�����e����ջ��Ԫ�أ����򷵻�0
//		return true;
//	//e = *(S.top - 1);
//	return false ;
//
//}
////3ջ�ĳ���
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
////4ջ�Ĳ��뺯��
//void Push(SqStack &S,int e)
//{
//	//�ж�ջ�Ƿ���,��ջ����׷�Ӵ洢�ռ�
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
////5ɾ������
//int  Pop(SqStack &S, int e)//ɾ��e
//{
//	if (S.top == S.base)
//		return 0;
//	e = *--S.top;
//
//}
////6ջ�����ٺ���
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
# define STACKINCREMENT 10 //����ջ�ĳ���
//ջ�ṹ��
typedef  struct Stack
{
	int  * base;
	int  * top;
	int   stacksize;//��ǰջ��ʹ�õ��������
} SqStack;

void InitStack(SqStack &S)//����һ����ջ����������Ϊ100
{
	S.base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));//���䴢��ռ�
	//int *base = new int[100];//Ҳ����
	if (!S.base) 
	{ 
		cout << "�洢����ʧ��!!!" << endl; 
	}
	else
	{
		S.top = S.base;
		S.stacksize = STACK_INIT_SIZE;
		cout << "����ɹ�!!!" << endl;
	}
}

void Push(SqStack &S, int e)//����Ԫ��eΪջ��Ԫ��
{
	if (S.top - S.base >= S.stacksize)//�ж������Ԫ���Ƿ�����
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(int));
		if (!S.base)
			cout << "�洢����ʧ��!!!" << endl << endl;
		else
		{
			S.stacksize += STACKINCREMENT;//��ǰ����Ϊ110
			S.top = S.base + S.stacksize;//�������Ϊ110
		}
	}
	*S.top++ = e;//��e�ӵ����
}

void DisplayStack(SqStack &S) //��ջ�׵�ջ�������ʾջ�е�Ԫ��
{
	int *p;
	p = S.base;
	if (S.base == S.top)	
		cout << "��ǰջΪ��ջ!!!" << endl << endl;
	else
	{
		cout << "��ǰջ��Ԫ��Ϊ: ";
		while (p != S.top)
		{
			cout << *(p) << " ";
			p++;
		}
		cout << endl;
	}
}

int StackLength(SqStack S) //�󳤶�
{
	int *p;
	p = S.base;
	int i = 0;
	while (p != S.top) { p++; i++; }
	return i;
}

void pop(SqStack &S, int &e) //��ջ
{
	if (S.top == S.base) cout << "����ʧ��!!!" << endl << endl;
	else
	{
		e = *--S.top;
		DisplayStack(S);
	}
}
void ClearStack(SqStack &S)//���
{
	int b;
	while (S.top != S.base)
		b = *--S.top;
	if (S.top == S.base) 
		cout << "˳��ջ�����!!!" << endl << endl;
}

void StackEmpty(SqStack S)//�п�
{
	if (S.top == S.base)
		cout << "˳��ջΪ��!!!" << endl << endl;
	else
		cout << "˳��ջ��Ϊ��!!!" << endl << endl;
}

void DestroyStack(SqStack &S)
{
	S.base = NULL;
	cout << "˳��ջ������!!!" << endl << endl;
}

void GetTop(SqStack S, int &e)//����ջ��Ԫ��
{
	if (S.top == S.base) cout << "����ʧ��!!!" << endl << endl;
	else
	{
		cout << "ջ��Ԫ��Ϊ: ";
		e = *(S.top - 1);
		cout << e << endl << endl;
	}
}

int main()
{

	cout << "*  1������һ����ջ       *" << endl;
	cout << "*  2������ջ��Ԫ��       *" << endl;
	cout << "*  3�����ջ��Ԫ��       *" << endl;
	cout << "*  4����ջ�ĳ���         *" << endl;
	cout << "*  5����ջ��Ԫ��         *" << endl;
	cout << "*  6��ɾ��ջ��Ԫ��       *" << endl;
	cout << "*  7������Ѵ��ڵ�ջ     *" << endl;
	cout << "*  8���ж�ջ�Ƿ�Ϊ��     *" << endl;
	cout << "*  0������ջ             *" << endl;

	int n, k;
	SqStack S;

	for (n = 0; n<15; n++)
	{
		cout << "��ѡ��0-8:  ";
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
			cout << "����ջS��Ԫ��Ϊ: ";
			cin >> a;
			Push(S, a);
			DisplayStack(S);
		}
		if (k == 3) DisplayStack(S);
		if (k == 4) cout << "ջ�ĳ���Ϊ: " << StackLength(S) << endl << endl;
		if (k == 5) { int c; GetTop(S, c); }
		if (k == 6) { int b; pop(S, b); }
		if (k == 7) ClearStack(S);
		if (k == 8) StackEmpty(S);

	}
	return 0;
}
