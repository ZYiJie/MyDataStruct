
#include <iostream>
#include<vector>
#define STACK_INIT_SIZE  100
#define STACK_INCREMENT  20
using namespace std;

typedef struct elemStruct
{
	int x;//���x����
	int y;//���y����
	//int flag;//���ʾ��-1�����ϰ��1�������߹��ĵ㣬0����δ�߹��ĵ�
}Elem;

typedef struct stack
{
	Elem *top;//ջ��ָ��
	Elem *base;//ջ��ָ��
	int size;//ջ��ǰ����
}sqStack;

//��ʼ��ջ
void InitStack(sqStack *&S)
{
	//����һ����ջ
	S = (sqStack*)malloc(sizeof(sqStack));
	S->base = S->top = NULL;
	S->size = 0;
	S->base = (Elem *)malloc(sizeof(Elem)*STACK_INIT_SIZE);
	if (!S->base)
	{
		cout << "�ڴ����ʧ�ܣ�" << endl;
		exit(OVERFLOW);
	}
	else {
		S->top = S->base;
		S->size = STACK_INIT_SIZE;
	}
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmptyStack(sqStack *S)
{
	if (S->base == S->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����ջ
void PrintStack(sqStack *S) {
	if (!isEmptyStack(S)) {
		Elem *p, *top = S->top;
		p = S->top;
		cout << "���·�����������У�";
		while (S->top != S->base)
		{
			p = p--;
			cout << "(" << p->x << "," << p->y << ")";
			S->top = p;
		}
		S->top = top;
		cout << endl;
	}
	else
	{
		cout << "·��Ϊ�գ�" << endl;
	}
}


//�������
void InversePrintStack(sqStack *S) {
	if (!isEmptyStack(S)) {
		Elem *p, *top = S->top, *base = S->base;
		p = S->base;
		cout << "·�����������У�";
		while (top != ++base)
		{
			cout << "(" << base->x << "," << base->y << ")";
			S->base = base;
		}
		S->base = p;
		cout << endl;
	}
	else
	{
		cout << "·��Ϊ�գ�" << endl;
	}
}

//ѹջ��ǰ��
void pushStack(sqStack *S, Elem *e) {
	if (S->top - S->base >= S->size)
	{
		S->base = (Elem *)realloc(S->base, sizeof(Elem)*(S->size + STACK_INCREMENT));
		if (!S->base)
		{
			exit(OVERFLOW);
		}
	}
	Elem *p;
	p = S->top;
	*p++ = *e;
	S->top = p;

}

//��ջ,����
Elem* popStack(sqStack *S)
{
	Elem *p, *q;
	p = q = S->top;

	if ((p != S->base) && (--q != S->top))
	{

		S->top = --p;
		return --p;//����֮��ջ��ָ���Ѿ������ƶ�һλ�����ǵ�����p��ָ��ĵ�ǰ�������ڴ���д�ŵ�����һ���ģ�x,y�������ǵ�Ŀ����Ҫȡ�õ�����ջ���ģ�x,y��,������Ҫ����--p;
	}
	else
	{
		cout << "�޷��ҵ��Թ�ͨ����" << endl;
		return NULL;
	}
}


//�Թ�Ѱ��
void FindRoad(vector<vector<int>> &maze, int entrancex, int entrancey, int endx, int endy) {
	sqStack *S = NULL;
	//��ʼ��·������ʼ��ջ��
	Elem  *key = new Elem;//��̬����һElem�Ľṹ�ͱ���
	if (!key)
	{
		cout << "�ڴ����ʧ��" << endl;
	}
	key->x = entrancex;
	key->y = entrancey;
	maze[entrancex][entrancey] = 1;
	InitStack(S);
	pushStack(S, key);
	int i = entrancex, j = entrancey;

	int q = 0, w = 0, e = 0, r = 0;
	while (true)
	{
		if (i == endx && j == endy)
		{
			//��������Թ����·��
			//PrintStack(S);
			InversePrintStack(S);
			break;
		}
		//�����־q;
		if (j - 1 >= 0)//��������Ƿ�Խ��
		{
			if (maze[i][j - 1] == 0)
			{
				q = 1;
			}
			else { q = 0; }
		}
		else
		{
			q = 0;
		}

		//�����־w;
		if (j + 1 < 10)
		{
			if (maze[i][j + 1] == 0)
			{
				w = 1;
			}
			else { w = 0; }
		}
		else
		{
			w = 0;
		}

		//�����־e;
		if (i + 1 < 10)
		{
			if (maze[i + 1][j] == 0)
			{
				e = 1;
			}
			else { e = 0; }
		}
		else { e = 0; }

		//�����־r;
		if (i - 1 >= 0)
		{
			if (maze[i - 1][j] == 0)
			{
				r = 1;
			}
			else
			{
				r = 0;
			}
		}
		else
		{
			r = 0;
		}

		if (q)//���һ��λ��
		{

			maze[i][j - 1] = 1;
			key->x = i;
			key->y = j - 1;
			j = j - 1;
			pushStack(S, key);
			//PrintStack(S);//��ӡÿһ����·��
		}
		else if (w)//�ұ�һ��λ��
		{

			maze[i][j + 1] = 1;
			key->x = i;
			key->y = j + 1;
			j = j + 1;
			pushStack(S, key);
			//PrintStack(S);
		}
		else if (e)//��
		{
			maze[i + 1][j] = 1;
			key->x = i + 1;
			key->y = j;
			i = i + 1;
			pushStack(S, key);
			//PrintStack(S);
		}
		else if (r)//��
		{
			maze[i - 1][j] = 1;
			key->x = i - 1;
			key->y = j;
			i = i - 1;
			pushStack(S, key);
			//PrintStack(S);
		}
		else
		{
			//����һ��
			if (!isEmptyStack(S)) {
				Elem * ss = popStack(S);
				//PrintStack(S);
				i = ss->x;
				j = ss->y;
			}
			else
			{
				cout << "�����ҵ����е�·����";
				break;
			}
		}
	}
}


void main()
{
	vector<vector<int>>  maze(100);
	vector<int> cow(10);
	//��ʼ���Թ�������ȫ����ʼ��Ϊ0
	for (int i = 0; i < 10; i++)
	{
		maze[i] = cow;
		for (int j = 0; j < 10; j++)
		{
			maze[i].push_back(0);
		}
	}
	//�����ϰ���
	for (int j = 0; j < 10; j++)
	{
		maze[0][j] = -1;
		maze[9][j] = -1;
		maze[j][0] = -1;
		maze[j][9] = -1;
	}
	maze[1][3] = maze[1][7] = maze[2][3] = maze[2][7] = -1;
	maze[3][5] = maze[3][6] = maze[4][2] = maze[4][3] = maze[4][4] = -1;
	maze[5][4] = maze[6][2] = maze[6][6] = maze[7][2] = maze[7][3] = maze[7][4] = maze[7][6] = maze[7][7] - 1;
	maze[8][1] = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (maze[i][j] == -1) cout << 0 << " ";
			else cout << 1<< " ";
		cout << endl;
	}
	//entrancex,entrancey��ڵ�ַ��x��y���ꣻendx,endy���ڵ�ַ��x��y����
	int entrancex = 1, entrancey = 1, endx = 8, endy = 8;
	FindRoad(maze, entrancex, entrancey, endx, endy);
	getchar();
	getchar();
}
