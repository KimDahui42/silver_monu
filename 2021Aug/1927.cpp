#include <iostream>
#include <cstdio>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
	priority_queue<int,vector<int>,greater<int>>pq;
	int n, x;
	cin >> n;
		while (n--) {
			scanf("%d", &x);
			if (x) pq.push(x);
			else {
				if (pq.empty())printf("0\n");
				else {
					printf("%d\n", pq.top());
					pq.pop();
				}
			}
		}

}
