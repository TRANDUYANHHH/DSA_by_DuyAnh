// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

struct Node {
	int val;
	Node *left, *right;
	Node (int x): val(x), left(nullptr), right(nullptr) {};
};

struct P {
	Node *par;
	int l, r;
	bool is_left;
	P(Node *p, int ll, int rr, bool is) : par(p), l(ll), r(rr), is_left(is) {};
};

int pos(int x, vector<int> in) {
	for(int i = 0; i < (int) in.size(); i++) {
		if(in[i] == x) {
			return i;
		}
	}
	return -1;
}

Node* build(vector<int> in, vector<int> lev) {
	queue<P> q;
	int idx = 0;
	int n = (int) in.size();
	q.push(P(nullptr, 0, n - 1, lev[idx]));
	Node *root;
	while(!q.empty()) {
		auto ff = q.front();
		q.pop();
		int l = ff.l;
		int r = ff.r;
		if(l > r) {
			if(ff.is_left) {
				ff.par -> left = nullptr;
			} else {
				ff.par -> right = nullptr;
			}
			continue;
		}
		int val = lev[idx];
		idx++;
		Node *t = new Node(val);
		if(val == lev[0]) {
			root = t;
		}
		if(ff.par != nullptr) {
			if(ff.is_left) {
				ff.par -> left = t;
			} else {
				ff.par -> right = t;
			}
		}
		int pp = pos(val, in);
		q.push(P(t, l, pp - 1, true));
		q.push(P(t, pp + 1, r, false));
	}
	return root;
}

void print(Node *r) {
	if(r == nullptr) {
		return;
	}
	print(r -> left);
	print(r -> right);
	cout << r -> val << ' ';
}

void solve() {
	int n;
	cin >> n;
	vector<int> in(n), lev(n);
	for(int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> lev[i];
	}
	print(build(in, lev));
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
