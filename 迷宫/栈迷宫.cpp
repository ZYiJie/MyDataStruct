
#include <iostream>
#include<vector>
#define STACK_INIT_SIZE  100
#define STACK_INCREMENT  20
using namespace std;

typedef struct elemStruct
{
	int x;//点的x坐标
	int y;//点的y坐标
	//int flag;//点表示，-1代表障碍物，1代表已走过的点，0代表未走过的点
}Elem;

typedef struct stack
{
	Elem *top;//栈顶指针
	Elem *base;//栈底指针
	int size;//栈当前容量
}sqStack;

//初始化栈
void InitStack(sqStack *&S)
{
	//构造一个空栈
	S = (sqStack*)malloc(sizeof(sqStack));
	S->base = S->top = NULL;
	S->size = 0;
	S->base = (Elem *)malloc(sizeof(Elem)*STACK_INIT_SIZE);
	if (!S->base)
	{
		cout << "内存分配失败！" << endl;
		exit(OVERFLOW);
	}
	else {
		S->top = S->base;
		S->size = STACK_INIT_SIZE;
	}
}

//判断栈是否为空
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

//遍历栈
void PrintStack(sqStack *S) {
	if (!isEmptyStack(S)) {
		Elem *p, *top = S->top;
		p = S->top;
		cout << "输出路径的坐标序列：";
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
		cout << "路径为空！" << endl;
	}
}


//倒序遍历
void InversePrintStack(sqStack *S) {
	if (!isEmptyStack(S)) {
		Elem *p, *top = S->top, *base = S->base;
		p = S->base;
		cout << "路径的坐标序列：";
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
		cout << "路径为空！" << endl;
	}
}

//压栈，前进
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

//出栈,后退
Elem* popStack(sqStack *S)
{
	Elem *p, *q;
	p = q = S->top;

	if ((p != S->base) && (--q != S->top))
	{

		S->top = --p;
		return --p;//后退之后，栈顶指针已经向下移动一位，但是弹出的p所指向的当前被弹出内存块中存放的是那一步的（x,y），我们的目的是要取得弹出后栈顶的（x,y）,所以需要返回--p;
	}
	else
	{
		cout << "无法找到迷宫通道！" << endl;
		return NULL;
	}
}


//迷宫寻道
void FindRoad(vector<vector<int>> &maze, int entrancex, int entrancey, int endx, int endy) {
	sqStack *S = NULL;
	//初始化路径（初始化栈）
	Elem  *key = new Elem;//动态分配一Elem的结构型变量
	if (!key)
	{
		cout << "内存分配失败" << endl;
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
			//倒序输出迷宫求解路径
			//PrintStack(S);
			InversePrintStack(S);
			break;
		}
		//计算标志q;
		if (j - 1 >= 0)//检查数组是否越界
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

		//计算标志w;
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

		//计算标志e;
		if (i + 1 < 10)
		{
			if (maze[i + 1][j] == 0)
			{
				e = 1;
			}
			else { e = 0; }
		}
		else { e = 0; }

		//计算标志r;
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

		if (q)//左边一个位置
		{

			maze[i][j - 1] = 1;
			key->x = i;
			key->y = j - 1;
			j = j - 1;
			pushStack(S, key);
			//PrintStack(S);//打印每一步的路径
		}
		else if (w)//右边一个位置
		{

			maze[i][j + 1] = 1;
			key->x = i;
			key->y = j + 1;
			j = j + 1;
			pushStack(S, key);
			//PrintStack(S);
		}
		else if (e)//下
		{
			maze[i + 1][j] = 1;
			key->x = i + 1;
			key->y = j;
			i = i + 1;
			pushStack(S, key);
			//PrintStack(S);
		}
		else if (r)//上
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
			//回退一步
			if (!isEmptyStack(S)) {
				Elem * ss = popStack(S);
				//PrintStack(S);
				i = ss->x;
				j = ss->y;
			}
			else
			{
				cout << "不能找到可行的路径！";
				break;
			}
		}
	}
}


void main()
{
	vector<vector<int>>  maze(100);
	vector<int> cow(10);
	//初始化迷宫矩阵，先全部初始化为0
	for (int i = 0; i < 10; i++)
	{
		maze[i] = cow;
		for (int j = 0; j < 10; j++)
		{
			maze[i].push_back(0);
		}
	}
	//设置障碍物
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
	//entrancex,entrancey入口地址的x和y坐标；endx,endy出口地址的x和y坐标
	int entrancex = 1, entrancey = 1, endx = 8, endy = 8;
	FindRoad(maze, entrancex, entrancey, endx, endy);
	getchar();
	getchar();
}
