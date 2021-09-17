#include <vector>

using namespace std;

int move(vector<vector<int>>&map, int x1,int y1,int x2,int y2) {
    int ans = map[x1][y1],curr,before=0;
    int x = x1, y = y1;
    for (int i = 0; i < y2 - y1; i++) {
        x = x1; y = y1 + i;
        curr = map[x][y];
        if (i == 0) before = map[x + 1][y];
        map[x][y] = before;
        ans = (ans > curr) ? curr : ans;
        before = curr;
    }
    for (int i = 0; i < x2 - x1; i++) {
        x = x1 + i; y = y2;
        curr = map[x][y];
        map[x][y] = before;
        ans = (ans > curr) ? curr : ans;
        before = curr;
    }
    for (int i = y2-y1; i > 0; i--) {
        x = x2; y = y1+i;
        curr = map[x][y];
        map[x][y] = before;
        ans = (ans > curr) ? curr : ans;
        before = curr;
    }
    for (int i = x2-x1; i >0; i--) {
        x = x1 + i; y = y1;
        curr = map[x][y];
        map[x][y] = before;
        ans = (ans > curr) ? curr : ans;
        before = curr;
    }
    return ans;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>map(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = (i * columns + j + 1);
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        int x1, x2, y1, y2;
        x1 = queries[i][0]-1; y1 = queries[i][1]-1;
        x2 = queries[i][2]-1; y2 = queries[i][3]-1;
        answer.push_back(move(map, x1, y1, x2, y2));
    }
    return answer;
}
