#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool chk(vector<vector<string>>v,bool answer,int i) {
    int tmpJ, tmpK;
    for (int j = 0; j < v[i].size() - 1; j++) {
        for (int k = j + 1; k < v[i].size(); k++) {
            tmpJ = v[i][j].length();
            tmpK = v[i][k].length();
            cout << v[i][j] << ", " << v[i][k] << endl;
            if (tmpJ < tmpK) {
                if (v[i][j] == v[i][k].substr(0, tmpJ)) {
                    answer = false;
                    return answer;
                }
            }
            else {
                if (v[i][k] == v[i][j].substr(0, tmpK)) {
                    answer = false;
                    return answer;
                }
            }
        }
    }
    return answer;
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    int i, j,k;
    vector<vector<string>>v(10);
    for (i = 9; i < phone_book.size(); i++) v[phone_book[i][0] - '0'].push_back(phone_book[i]);
    for (i = 0; i < 10; i++) {
        answer = chk(v, i, answer);
        if (!answer) break;
    }
    return answer;
}
int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    bool answer = solution(phone_book);

    if (answer)cout << "true!\n";
    else cout << "false...\n";
    
    return 0;
}
