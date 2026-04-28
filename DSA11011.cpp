#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node (int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

Node *r;

bool insert(Node *p, int u, int v, char c) {
  if(!p) {
    return false;
  }
  if(p -> val == u) {
    if(c == 'L') {
      p -> left = new Node(v);
    } else {
      p -> right = new Node(v);
    }
    return true;
  }
  if(insert(p -> left, u, v, c)) {
    return true;
  }
  return insert(p -> right, u, v, c);
}

bool F(Node *p) {
  if(p -> left == NULL && p -> right == NULL) {
    return true;
  }
  if(p -> left != NULL && p -> right != NULL) {
    return F(p -> left) && F(p -> right); 
  }
  return false;
}

void solve() { 
  int n;
  cin >> n;
  int u, v;
  char c;
  cin >> u >> v >> c;
  r = new Node(u);
  insert(r, u, v, c);
  for(int i = 1; i < n; i++) {
    cin >> u >> v >> c;
    insert(r, u, v, c);
  }
  if(F(r)) {
    cout << 1;
  } else {
    cout << 0;
  }
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
