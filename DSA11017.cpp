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
	Node (int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

int pos(int x, vector<int> a) {
	for(int i = 0; i < (int) a.size(); i++) {
		if(x == a[i]) {
			return i;
		}
	}
	return -1;
}

Node* build(vector<int> in, vector<int> pre, int&idx, int l, int r) {
	if(l > r) {
		return nullptr;
	}
	int val = pre[idx];
	idx++;
	Node *t = new Node(val);
	int p = pos(val, in);
	t -> left = build(in, pre, idx, l, p - 1);
	t -> right = build(in, pre, idx, p + 1, r);
	return t;
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
	vector<int> pre(n);
	for(int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	vector<int> in(pre.begin(), pre.end());
	sort(in.begin(), in.end());
	int idx = 0;
	print(build(in, pre, idx, 0, n - 1));
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
