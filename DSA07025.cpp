// @author: tranDuyAnh
/*
Biểu thức dưới dạng hậu tố là phép biểu diễn biểu thức trong đó phép toán được đặt sau hai toán hạng. Ví dụ AB+CD-* (tương ứng với biểu thức trung tố (A+B)*(C-D).

Hãy viết chương trình tính toán giá trị của biểu thức hậu tố.

input:
3

7

2 3 1 * + 9 –

7

8 7 5 * + 9 –

3

-10 -4 +

output:
-4

34

-14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

bool is_num(string s) {
	for(char c : s) {
		if(c >= '0' && c <= '9') {
			return true;
		}
	}
	return false;
}

string calc(string a, string b, string c) {
	if(c == "+") {
		return to_string(stoll(a) + stoll(b));
	} else 
	if(c == "*") {
		return to_string(stoll(a) * stoll(b));
	} else
	if(c == "/") {
		return to_string(stoll(a) / stoll(b));
	} else {
		return to_string(stoll(a) - stoll(b));
	}
}

void solve() {
	int n;
	cin >> n;
	vector<string> A(n);
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	stack<string> st;
	for(int i = 0; i < n; i++) {
		if(is_num(A[i])) {
			st.push(A[i]);
		} else {
			string b = st.top(); st.pop();
			string a = st.top(); st.pop();
			st.push(calc(a, b, A[i]));
		}
	}
	cout << st.top(); 	
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		solve();
		cout << '\n';
	}
  return 0;  
}
