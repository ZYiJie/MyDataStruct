#include<iostream>
#include <stack>
#include <fstream>  //�ļ����⺯��
#define LEN 20
using namespace std;
typedef struct POS {
	int x;
	int y;
};
char step = 'a'; //�������ı��
stack <POS> path; //����·������
int flag = 0; //�ж��Թ��Ƿ��ѱ������յ�


void findpath(int maze[LEN][LEN], POS current, POS end) {
	//Ҫ��
	//ͨ����������·�����ݹ��ҵ���һ��ͨ·�ķ��򣬵����յ��·��������push��ջ�������ݹ�����еĽ���ǵ���ģ�
	POS direction[4] = { {1,0},{0,1},{-1,0},{0,-1} };
	POS next;
	int i;
	for (i = 0; i < 4; i++) {
		next.x = current.x + direction[i].x;
		next.y = current.y + direction[i].y;
		if (maze[next.x][next.y] == 1) {
			maze[next.x][next.y] = step++;
			if (next.x != end.x || next.y != end.y) {
				findpath(maze, next, end);

			}
			else {
				flag = 1;
				path.push(next);
				return;
			}
			path.push(next);
			if (!flag) {
				int temp = 1;
				int x, y;
				for (int j = 0; j < 4; j++) {
					x = next.x + direction[i].x;
					y = next.y + direction[i].y;
					if (maze[x][y] == 1) temp = 0;
				}
				if (temp) path.pop();
			}
		}
	}
}
void outmaze(int arr[LEN][LEN], int m, int n) {
	//����Թ�
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void outpath() {
	//���ջ�д����·�����꣨ջ�ղ������
	POS temp;
	if (flag) {
		while (!path.empty()) {
			temp = path.top();
			cout << "[" << temp.x << ", " << temp.y << "]-->";
			path.pop();
		}
		cout << "END" << endl;
	}
	else cout << "No path!!" << endl;
}
int main()
{
	int arr[LEN][LEN] = { 0 };
	int m, n;
	POS begin, end; //�����յ�λ��
	cout << "Input the row and column number: " << endl;
	cin >> m;
	cin >> n;
	ifstream infile;   //������
	infile.open("maze.txt", ios::in);
	if (!infile.is_open())
		cout << "Open file failure" << endl;
	while (!infile.eof())            // ��δ���ļ�����һֱѭ��
	{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				infile >> arr[i][j];
		}
	}
	infile.close();   //�ر��ļ�
	outmaze(arr, m, n);
	begin.x = 0;
	begin.y = 0;
	end.x = m - 1;
	end.y = n - 1; //�����±�=�����С-1
	findpath(arr, begin, end);
	outpath();
	//outmaze(arr, m, n);
	getchar();
	getchar();
	return 0;
}