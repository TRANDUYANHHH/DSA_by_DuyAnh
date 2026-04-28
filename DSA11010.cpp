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
vector<int> leaf;

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

void print_tree(Node* p) {
  if(!p) {
    return;
  }
  cout << p -> val << ' ';
  print_tree(p -> left);
  print_tree(p -> right);
}

void f(Node *r, int x) {
  if(!r) return;
  if(r -> left == NULL && r -> right == NULL) {
    leaf.push_back(x);
    return;
  }
  f(r -> left, x + 1);
  f(r -> right, x + 1);
}

bool same_level_leaf() {
  return set<int>(leaf.begin(), leaf.end()).size() == 1;
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
  leaf.clear();
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
  f(r, 1);
  if(same_level_leaf() && F(r)) {
    cout << "Yes";
  } else {
    cout << "No";
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
