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
    left = NULL;
    right = NULL;
  }
};

Node *A, *B;

bool insert(Node *r, int u, int v, char c) {
  if(!r) {
    return false;
  }
  if(r -> val == u) {
    if(c == 'L') {
      r -> left = new Node(v);
    } else {
      r -> right = new Node(v);
    }
    return true;
  }
  if(insert(r -> left, u, v, c)) {
    return true;
  }
  return insert(r -> right, u, v, c);
}

bool same(Node *x, Node *y) {
  if(x == NULL && y == NULL) {
    return true;
  }
  if(x != NULL && y != NULL) {
    if(x -> val == y -> val) {
      return same(x -> left, y -> left) && same(x -> right, y -> right);
    }
    return false;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  int u, v;
  char c;
  cin >> u >> v >> c;
  A = new Node(u);
  insert(A, u, v, c);
  for(int i = 1; i < n; i++) {
    cin >> u >> v >> c;
    insert(A, u, v, c);
  }
  cin >> n;
  cin >> u >> v >> c;
  B = new Node(u);
  insert(B, u, v, c);
  for(int i = 1; i < n; i++) {
    cin >> u >> v >> c;
    insert(B, u, v, c);
  }
  cout << (same(A, B) ? 1 : 0);
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
