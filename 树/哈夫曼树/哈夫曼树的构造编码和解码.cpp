#include <iostream>
#include <vector>
#include"MyHuffmanTree.h"
using namespace std;


int main() {
	TreeNode *root=NULL;
	vector <TreeNode*> arr;
	int input[26][2] = {0},i=0;
	cout << "Please input: ";
	while (1) {
		//将字符串中的字母输入二维数组，字母及其出现次数
		char temp = getchar();
		if (temp == '\n') break;
		if (isalpha(temp)) {
			int flag = 1;
			if (temp < 'a') temp += 32;
			for (int j = 0; j < i; j++) {
				if (input[j][0] == temp) {
					flag = 0;
					input[j][1]++;
				}
			}
			if (flag) {
				input[i][0] = temp;
				input[i++][1]++;
			}
		}
		else continue;
	}
	root = CreateHuffmanTree(input,i);
	//for (int j = 0; j < i; j++) {//突然发现不用进行排序
	//	//对该二维数组从小到大进行冒泡排序
	//	for (int k = 0; k < j; k++) {
	//		if (input[k][1] > input[k + 1][1]) {
	//			int temp;
	//			temp = input[k][1];
	//			input[k][1] = input[k + 1][1];
	//			input[k + 1][1] = temp;
	//			temp = input[k][0];
	//			input[k][0] = input[k + 1][0];
	//			input[k + 1][0] = temp;
	//		}
	//	}
	//}
	code(root, 0,input,i);
	cout << endl;
	int ch;
	string result;
	//while ((getchar()) != '\n');
	cout << "Words ==> Codes: ";
	while (1) {
		ch = getchar();
		if (ch == '\n') break;
		//if (ch < 'a') ch += 32;
		for (int j = 0; j < i; j++) {
			if (str[j][0] == ch) 
				result.append(str[j].substr(1, str[j].length() - 1)) ;
		}
	}
	cout << result<<endl;
	cout << "Codes ==> Words: ";
	string result2;
	string mystr;
	cin >> mystr;
	for (int j = 0; j < mystr.length();) {
			for (int k = 0; k < i; k++) {
				string temp = str[k].substr(1, str[k].length() - 1);
				string sub_mystr = mystr.substr(j, temp.length());
				if (temp == sub_mystr) {
					cout << str[k][0];
					j += temp.length();
				}
		}
	}
	getchar();
	getchar();
	return 0;
}