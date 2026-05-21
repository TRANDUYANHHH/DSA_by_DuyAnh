// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		stack<string> st;
		stack<int> num;
		int n = (int) s.size();
		for(int i = 0; i < n; i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				int x = 0;
				while(i < n && s[i] >= '0' && s[i] <= '9') {
					x = x * 10 + (s[i] - '0');
					i++;
				}
				num.push(x);
				i--;
			} else
			if(s[i] == '[') {
				st.push(string(1, s[i]));
			} else
			if(s[i] == ']') {
				vector<string> ss;
				while(!st.empty() && st.top() != "[") {
					ss.push_back(st.top());
					st.pop();
				}
				st.pop();
				reverse(ss.begin(), ss.end());
				string xx = "";
				for(string xs : ss) {
					xx += xs;
				}
				int x = num.top();
				num.pop();
				string t = "";
				for(int _ = 0; _ < x; _++) {
					t += xx;
				}
				st.push(t);
			} else {
				st.push(string(1, s[i]));
			}
		}
		vector<string> ss;
		while(!st.empty()) {
			ss.push_back(st.top());
			st.pop();
		}
		reverse(ss.begin(), ss.end());
		for(string xs : ss) {
			cout << xs;
		}
		cout << '\n';
	}
  return 0;  
}
