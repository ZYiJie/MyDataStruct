#include <iostream>
#include <queue>
using namespace std;

//表头结点（表示图的顶点）
struct vnode {
	char data;             //顶点数据，这里用字符表示
	struct arcnode * firstarc;   //指针指向第一条边 
};
//表结点（表示图的边）
struct arcnode {
	//int wt;           //权重
	int adjvex;     //顶点下标
	struct arcnode *nextarc;   //指针指向下一条边
};
typedef struct arcnode * Arc;
//图
struct mgraph {
	struct vnode vexs[100];
	int vexsnum, arcnum;     //顶点数，边数
} *g;
typedef struct mgraph* Graph;

int findadj(char vexs, Graph g) {
	int i;
	for (i = 1; i <= g->vexsnum; i++) {
		if (vexs == g->vexs[i].data)
			break;
	}
	return i;
}

//建图
Graph creategraph() {
	Graph g1;
	char vex;
	g1 = (Graph)malloc(sizeof(struct mgraph));
	g1->arcnum = 0;
	g1->vexsnum = 0;
	printf("输入顶点，输入-代表结束\n");
	scanf_s("%c", &vex);    //输入顶点
	while (vex != '-') {         //输入-后循环结束
		g1->vexsnum++;
		g1->vexs[g1->vexsnum].data = vex;      //这里的结构数组vexs[]下标从1开始
		g1->vexs[g1->vexsnum].firstarc = NULL;
		scanf_s(" %c", &vex);         //%c前面加空格防止读取回车
	}
	int i;
	int w;           //边的权重
	int adjvex;    //顶点的下标
	char avex;    //边的另一个顶点
	Arc p, b;
	for (i = 1; i <= g1->vexsnum; i++) {
		printf("输入%c的相邻顶点，输入-代表结束\n", g1->vexs[i].data);
		scanf_s(" %c", &avex);
		while (avex != '-') {    //输入-后循环结束
			adjvex = findadj(avex, g1);
			//printf("输入边%c%c的权重\n", g1->vexs[i].data, avex);
			//scanf_s("%d", &w);
			b = (Arc)malloc(sizeof(struct arcnode));
			b->adjvex = adjvex;
			//b->wt = w;
			b->nextarc = NULL;
			//链表追加结点
			p = g1->vexs[i].firstarc;
			if (p != NULL) {
				while (p->nextarc != NULL)
					p = p->nextarc;
				p->nextarc = b;
			}
			else
				g1->vexs[i].firstarc = b;
			g1->arcnum++;
			//printf("输入%c的相邻顶点，输入-代表结束\n", g1->vexs[i].data);
			scanf_s(" %c", &avex);
		}
	}
	return g1;
}

//图的输出
void printgraph(Graph g) {
	int i, k;
	Arc p;
	printf("邻接表: \n");
	for (i = 1; i <= g->vexsnum; i++) {
		printf("%c  ->", g->vexs[i].data);
		p = g->vexs[i].firstarc;
		int degree=0;
		while (p != NULL) {
			degree++;
			printf("%4c", g->vexs[i].data);
			k = p->adjvex;
			printf("%2c", g->vexs[k].data);
			//printf("%2d", p->wt);
			if (p->nextarc != NULL)
				printf("  ->");
			p = p->nextarc;
		}
		cout << "     度为：" << degree << endl;
	}
	printf("\n");
	printf("顶点总数为%4d\n", g->vexsnum);
	printf("边的总数为%4d\n", g->arcnum);
}

int visited[20];  //全局数组,记录图中节点访问状态
void DFS(Graph &G, int i) {
	visited[i] = 1;
	printf("%c ", G->vexs[i].data);

	Arc p = G->vexs[i].firstarc;
	while (p) {
		if (!visited[p->adjvex]) {
			DFS(G, p->adjvex); //递归深度遍历
		}
		p = p->nextarc;
	}
}
void DFSTraverse(Graph &G) {
	int i;
	for (i = 1; i <= G->vexsnum; ++i) {
		visited[i] =0;  //初始化访问数组visited的元素值为false
	}
	for (i = 1; i <= G->vexsnum; ++i) {
		if (!visited[i]) { //节点尚未访问
			DFS(G, i);
		}
	}
}

/** 队列定义及相关操作(广度遍历会用到此循环队列) **/
typedef struct LoopQueue {
	int data[100];
	int front, rear;
}LoopQueue, *Queue; //队列结构

void initQueue(Queue &Q) {
	Q->front = Q->rear = 0;
}

int QueueEmpty(Queue &Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int QueueFull(Queue &Q) {
	if ((Q->rear + 1) % 100 == Q->front) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * 队尾插入元素
 */
void EnQueue(Queue &Q, int e) {
	if (!QueueFull(Q)) {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % 100;
	}
}

/**
 * 队头删除元素
 */
void DeQueue(Queue &Q, int *e) {
	if (!QueueEmpty(Q)) {
		*e = Q->data[Q->front];
		Q->front = (Q->front + 1) % 100;
	}
}
/*************************************************/
void BFSTraverse(Graph &G) {
	int i;
	Queue Q = (Queue)malloc(sizeof(LoopQueue));

	for (i = 1; i <= G->vexsnum; ++i) {
		visited[i] = 0;
	}
	initQueue(Q);

	for (i = 1; i <= G->vexsnum; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			printf("%c ", G->vexs[i].data);
			EnQueue(Q, i);

			while (!QueueEmpty(Q)) {
				DeQueue(Q, &i);
				Arc p = G->vexs[i].firstarc;
				while (p) {
					if (!visited[p->adjvex]) {
						visited[p->adjvex] = 1;
						printf("%c ", G->vexs[p->adjvex].data);
						EnQueue(Q, p->adjvex);
					}
					p = p->nextarc;
				}
			}
		}
	}
}

void main() {
	g = creategraph();
	printgraph(g);
	cout << "深度优先遍历：";
	DFSTraverse(g);
	cout <<endl<< "广度优先遍历：";
	BFSTraverse(g);
	getchar(); getchar(); 
}
