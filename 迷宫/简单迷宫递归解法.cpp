#include<iostream>
#include <stack>
#include <fstream>  //文件流库函数
#define LEN 20
using namespace std;
typedef struct POS {
	int x;
	int y;
};
char step = 'a'; //遍历过的标记
stack <POS> path; //储存路径坐标
int flag = 0; //判断迷宫是否已遍历到终点


void findpath(int maze[LEN][LEN], POS current, POS end) {
	//要求
	//通过设置四条路径，递归找到下一个通路的方向，到达终点后将路径的坐标push进栈（函数递归过程中的结果是倒序的）
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
	//输出迷宫
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void outpath() {
	//输出栈中储存的路径坐标（栈空不输出）
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
	POS begin, end; //起点和终点位置
	cout << "Input the row and column number: " << endl;
	cin >> m;
	cin >> n;
	ifstream infile;   //输入流
	infile.open("maze.txt", ios::in);
	if (!infile.is_open())
		cout << "Open file failure" << endl;
	while (!infile.eof())            // 若未到文件结束一直循环
	{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				infile >> arr[i][j];
		}
	}
	infile.close();   //关闭文件
	outmaze(arr, m, n);
	begin.x = 0;
	begin.y = 0;
	end.x = m - 1;
	end.y = n - 1; //数组下标=数组大小-1
	findpath(arr, begin, end);
	outpath();
	//outmaze(arr, m, n);
	getchar();
	getchar();
	return 0;
}