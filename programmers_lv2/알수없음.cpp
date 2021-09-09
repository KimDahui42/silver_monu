//망한 풀이지만 문제를 잃어서 일단 푼 곳 까지 올림...
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int cnt = 0, cr = 0, cc = 0, nr = 0, nc = 0;
vector<vector<vector<bool>>>visit(4, vector<vector<bool>>(500, vector<bool>(500, false)));
vector<string>map;
vector<int>v;
enum D{e,w,s,n};
int sGo[4][2]{ {0,1},{0,0},{1,-1},{-1,0} };
int lGo[4][2]{ {-1,0},{1,-1},{0,1},{0,0} };
int rGo[4][2]{ {1,-1},{-1,0},{0,0},{0,1} };
int face;
void east(int cnt,int size) {
    face = e;
    cr = cc = 0;
    while (1) {
        visit[e][cr][cc] = true;
        switch (map[cr][cc]){
        case 'S':
            nr += sGo[face][0];
            nc += sGo[face][0];
            break;
        case 'L':
            nr += lGo[face][0];
            nc += lGo[face][0];
            switch (face){
            case e:
                face = n;
                break;
            case w:
                face = s;
                break;
            case s:
                face = e;
                break;
            case n:
                face = w;
                break;
            }
            break;
        case'R':
            nr += rGo[face][0];
            nc += rGo[face][0];
            switch (face) {
            case e:
                face = s;
                break;
            case w:
                face = n;
                break;
            case s:
                face = w;
                break;
            case n:
                face = e;
                break;
            }
            break;
        }
        if (nr == -1) nr = size-1;
        else if (nr == size) nr = 0;
        if (nc == -1) nc = size - 1;
        else if (nc == size) nc = 0;
        if (visit[e][nr][nc] == true) {
            if (nr == 0 && nc == 0) v.push_back(cnt);
            else cnt = -1;
            return;
        }
        cnt++;
    }
}
void west(int cnt, int size) {
    face = w;
    cr = cc = 0;
    while (1) {
        visit[w][cr][cc] = true;
        switch (map[cr][cc]) {
        case 'S':
            nr += sGo[face][0];
            nc += sGo[face][0];
            break;
        case 'L':
            nr += lGo[face][0];
            nc += lGo[face][0];
            switch (face) {
            case e:
                face = n;
                break;
            case w:
                face = s;
                break;
            case s:
                face = e;
                break;
            case n:
                face = w;
                break;
            }
            break;
        case'R':
            nr += rGo[face][0];
            nc += rGo[face][0];
            switch (face) {
            case e:
                face = s;
                break;
            case w:
                face = n;
                break;
            case s:
                face = w;
                break;
            case n:
                face = e;
                break;
            }
            break;
        }
        if (nr == -1) nr = size - 1;
        else if (nr == size) nr = 0;
        if (nc == -1) nc = size - 1;
        else if (nc == size) nc = 0;
        if (visit[w][nr][nc] == true) {
            if (nr == 0 && nc == 0) v.push_back(cnt);
            else cnt = -1;
            return;
        }
        cnt++;
    }
}
void south(int cnt, int size) {
    face = s;
    while (1) {
        cr = cc = 0;
        visit[s][cr][cc] = true;
        switch (map[cr][cc]) {
        case 'S':
            nr += sGo[face][0];
            nc += sGo[face][0];
            break;
        case 'L':
            nr += lGo[face][0];
            nc += lGo[face][0];
            switch (face) {
            case e:
                face = n;
                break;
            case w:
                face = s;
                break;
            case s:
                face = e;
                break;
            case n:
                face = w;
                break;
            }
            break;
        case'R':
            nr += rGo[face][0];
            nc += rGo[face][0];
            switch (face) {
            case e:
                face = s;
                break;
            case w:
                face = n;
                break;
            case s:
                face = w;
                break;
            case n:
                face = e;
                break;
            }
            break;
        }
        if (nr == -1) nr = size - 1;
        else if (nr == size) nr = 0;
        if (nc == -1) nc = size - 1;
        else if (nc == size) nc = 0;
        if (visit[s][nr][nc] == true) {
            if (nr == 0 && nc == 0) v.push_back(cnt);
            else cnt = -1;
            return;
        }
        cnt++;
    }
}
void north(int cnt, int size) {
    face = n;
    cr = cc = 0;
    while (1) {
        visit[n][cr][cc] = true;
        switch (map[cr][cc]) {
        case 'S':
            nr += sGo[face][0];
            nc += sGo[face][0];
            break;
        case 'L':
            nr += lGo[face][0];
            nc += lGo[face][0];
            switch (face) {
            case e:
                face = n;
                break;
            case w:
                face = s;
                break;
            case s:
                face = e;
                break;
            case n:
                face = w;
                break;
            }
            break;
        case'R':
            nr += rGo[face][0];
            nc += rGo[face][0];
            switch (face) {
            case e:
                face = s;
                break;
            case w:
                face = n;
                break;
            case s:
                face = w;
                break;
            case n:
                face = e;
                break;
            }
            break;
        }
        if (nr == -1) nr = size - 1;
        else if (nr == size) nr = 0;
        if (nc == -1) nc = size - 1;
        else if (nc == size) nc = 0;
        if (visit[n][nr][nc] == true) {
            if (nr == 0 && nc == 0) v.push_back(cnt);
            else cnt = -1;
            return;
        }
        cnt++;
    }
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    map.assign(grid.begin(), grid.end());
    int size = grid[0].size();
    for(int i=0;i<4;i++) {
        east(0,size);
        west(0,size);
        south(0,size);
        north(0,size);
    }
    answer.assign(v.begin(), v.end());
    return answer;
}
int main() {
    vector<string>grid = { "SL","LR" };
    vector<int>answer=solution(grid);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << endl;
    return 0;
    
}
