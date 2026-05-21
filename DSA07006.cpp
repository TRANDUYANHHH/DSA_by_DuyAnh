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
	string s;
	cin >> s;
	int n = (int) s.size();
	stack<int> st;
	vector<pair<int, int>> pp;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			st.push(i);
		} else
		if(s[i] == ')') {
			pp.emplace_back(st.top(), i);
			st.pop();
		}
	}
	int sz = pp.size();
	set<string> A;
	for(int x = 1; x < (1 << sz); x++) {
		string t = "";
		vector<int> B;
		for(int j = 0; j < sz; j++) {
			if(x & (1 << j)) {
				B.push_back(pp[j].first);
				B.push_back(pp[j].second);
			}
		}
		for(int i = 0; i < n; i++) {
			if(count(B.begin(), B.end(), i) == 0) {
				t.push_back(s[i]);
			}
		}
		A.insert(t);
	}
	for(string x : A) {
		cout << x << '\n';
	}
  return 0;  
}
