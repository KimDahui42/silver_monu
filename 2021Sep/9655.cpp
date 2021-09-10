#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	string ans;
	cin >> n;
	ans = (n % 2 == 0) ? "CY" : "SK";
	cout << ans<<endl;
	return 0;
}
