//푸는 중

#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int n, m,r,i,j;
int map[300][300];
int cnt, maxi;
enum face{left,down,right,up};
void init() {
	cin >> n >> m >> r;
	maxi = n * m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	return;
}
void print() {
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return;
}
void rotate(int startR,int startC,int endR,int endC){
	if (endR <= startR || endC <= startC) {
		cout << '\n';
		print();
		return;
	}
	int curr, put;
	int temp = map[startR][endC];
	//move left
	for (i = endC; i >=startC; i--) {
		curr = map[startR][i];
		if (i == endC)
			put = map[startR+1][i];
		map[startR][i] = put;
		put = curr;
	}
	//move down
	for (i = startR; i <= endR; i++) {
		curr = map[i][startC];
		map[i][startC] = put;
		put = curr;
	}
	//move right
	for (i = startC; i <= endC; i++) {
		curr = map[i][endR];
		map[i][endR] = put;
		put = curr;
	}
	//move up
	for (i = endR; i >= startR; i--) {
		curr = map[i][endC];
		map[i][endC] = put;
		put = curr;
	}
	rotate(startR+1, startC+1, endR-1, endC-1);
}

int main() {
	init();
	while(r--) rotate(0,0,n-1,m-1);
	cout << "\n answer is.. \n";
	print();
	return 0;
}
