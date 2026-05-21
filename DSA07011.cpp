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
		for(char c : s) {
			if(c >= 'A' && c <= 'Z') {
				st.push(string(1, c));
			} else {
				string a = st.top(); st.pop();
				string b = st.top(); st.pop();
				string t = string(1, c) + b + a;
				st.push(t);
			}
		}
		cout << st.top() << '\n';
	}
  return 0;  
}
