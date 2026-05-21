// @author: tranDuyAnh

/*
duyet lan luot cac ky tu trong chuoi
neu la ky tu -> them vao cau tra loi
neu la dau ( -> them vao stack
neu la dau ) -> them toan bo phan truoc dau ( vao stack
neu la +, -, *, /, ^ -> them toan bo cac dau co do uu tien lon hon vao stack truoc khi them dau vao stack
cuoi cung la them phan con lai cua stack vao chuoi
*/

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
		stack<char> st;
		string ans = "";
		auto prec = [] (char c) -> int {
			if(c == '^') {
				return 3;
			} 
			if(c == '*' || c == '/') {
				return 2;
			}
			if(c == '+' || c == '-') {
				return 1;
			} 
			return -1;
		};
		auto is_exp = [] (char c) {
			return c == '^';
		};
		for(char c : s) {
			if((c >= 'a' && c <= 'z') || 
				 (c >= 'A' && c <= 'Z') || 
				 (c >= '0' && c <= '9')) {
				ans.push_back(c);
			} else
			if(c == '(') {
				st.push(c);
			} else
			if(c == ')') {
				while(!st.empty() && st.top() != '(') {
					ans.push_back(st.top());
					st.pop();
				}
				st.pop(); 
			} else {
				while(!st.empty() && st.top() != '(' && 
				(prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && !is_exp(c)))) {
					ans.push_back(st.top());
					st.pop();
				}
				st.push(c);
			}
		}	
		while(!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		cout << ans << '\n';
	}
  return 0;  
}
