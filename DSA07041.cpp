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
		stack<int> st;
		int n = (int) s.size();
		st.push(-1);
		int ans = 0;
		for(int i = 0; i < n; i++) {
			char c = s[i];
			if(c == '(') {
				st.push(i);
			} else {
				st.pop();
				if(!st.empty()) {
					ans += 2;
				} else {
					st.push(i);
				}
			}
		}
		cout << ans << '\n';
	}
  return 0;  
}
