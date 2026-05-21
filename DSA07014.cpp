#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, char c) {
	if(c == '+') {
		return a + b;
	} else 
	if(c == '*') {
		return a * b;
	} else
	if(c == '/') {
		return a / b;
	} else {
		return a - b;
	}
}

void solve() {
	string s;
	cin >> s;
	stack<int> st;
	for(int i = (int) s.size() - 1; i >= 0; i--) {
		if(s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
		} else {
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			int c = calc(a, b, s[i]);
			st.push(c);
		}
	}
	cout << st.top();
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
		cout << '\n';		
	}
}
