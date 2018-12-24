#include <iostream>
#include <queue>
using namespace std;

//��ͷ��㣨��ʾͼ�Ķ��㣩
struct vnode {
	char data;             //�������ݣ��������ַ���ʾ
	struct arcnode * firstarc;   //ָ��ָ���һ���� 
};
//���㣨��ʾͼ�ıߣ�
struct arcnode {
	//int wt;           //Ȩ��
	int adjvex;     //�����±�
	struct arcnode *nextarc;   //ָ��ָ����һ����
};
typedef struct arcnode * Arc;
//ͼ
struct mgraph {
	struct vnode vexs[100];
	int vexsnum, arcnum;     //������������
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

//��ͼ
Graph creategraph() {
	Graph g1;
	char vex;
	g1 = (Graph)malloc(sizeof(struct mgraph));
	g1->arcnum = 0;
	g1->vexsnum = 0;
	printf("���붥�㣬����-�������\n");
	scanf_s("%c", &vex);    //���붥��
	while (vex != '-') {         //����-��ѭ������
		g1->vexsnum++;
		g1->vexs[g1->vexsnum].data = vex;      //����Ľṹ����vexs[]�±��1��ʼ
		g1->vexs[g1->vexsnum].firstarc = NULL;
		scanf_s(" %c", &vex);         //%cǰ��ӿո��ֹ��ȡ�س�
	}
	int i;
	int w;           //�ߵ�Ȩ��
	int adjvex;    //������±�
	char avex;    //�ߵ���һ������
	Arc p, b;
	for (i = 1; i <= g1->vexsnum; i++) {
		printf("����%c�����ڶ��㣬����-�������\n", g1->vexs[i].data);
		scanf_s(" %c", &avex);
		while (avex != '-') {    //����-��ѭ������
			adjvex = findadj(avex, g1);
			//printf("�����%c%c��Ȩ��\n", g1->vexs[i].data, avex);
			//scanf_s("%d", &w);
			b = (Arc)malloc(sizeof(struct arcnode));
			b->adjvex = adjvex;
			//b->wt = w;
			b->nextarc = NULL;
			//����׷�ӽ��
			p = g1->vexs[i].firstarc;
			if (p != NULL) {
				while (p->nextarc != NULL)
					p = p->nextarc;
				p->nextarc = b;
			}
			else
				g1->vexs[i].firstarc = b;
			g1->arcnum++;
			//printf("����%c�����ڶ��㣬����-�������\n", g1->vexs[i].data);
			scanf_s(" %c", &avex);
		}
	}
	return g1;
}

//ͼ�����
void printgraph(Graph g) {
	int i, k;
	Arc p;
	printf("�ڽӱ�: \n");
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
		cout << "     ��Ϊ��" << degree << endl;
	}
	printf("\n");
	printf("��������Ϊ%4d\n", g->vexsnum);
	printf("�ߵ�����Ϊ%4d\n", g->arcnum);
}

int visited[20];  //ȫ������,��¼ͼ�нڵ����״̬
void DFS(Graph &G, int i) {
	visited[i] = 1;
	printf("%c ", G->vexs[i].data);

	Arc p = G->vexs[i].firstarc;
	while (p) {
		if (!visited[p->adjvex]) {
			DFS(G, p->adjvex); //�ݹ���ȱ���
		}
		p = p->nextarc;
	}
}
void DFSTraverse(Graph &G) {
	int i;
	for (i = 1; i <= G->vexsnum; ++i) {
		visited[i] =0;  //��ʼ����������visited��Ԫ��ֵΪfalse
	}
	for (i = 1; i <= G->vexsnum; ++i) {
		if (!visited[i]) { //�ڵ���δ����
			DFS(G, i);
		}
	}
}

/** ���ж��弰��ز���(��ȱ������õ���ѭ������) **/
typedef struct LoopQueue {
	int data[100];
	int front, rear;
}LoopQueue, *Queue; //���нṹ

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
 * ��β����Ԫ��
 */
void EnQueue(Queue &Q, int e) {
	if (!QueueFull(Q)) {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % 100;
	}
}

/**
 * ��ͷɾ��Ԫ��
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
	cout << "������ȱ�����";
	DFSTraverse(g);
	cout <<endl<< "������ȱ�����";
	BFSTraverse(g);
	getchar(); getchar(); 
}
