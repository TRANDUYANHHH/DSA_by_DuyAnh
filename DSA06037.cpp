/**
 *    author: tranDuyAnh
 **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 1e9;
const ll INF = 1e18;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> b(n);
    forn(i, n){
      cin >> a[i];
      b[i] = {a[i], i};
    }
    sort(all(b));
    vector<int> res;
    int mx = 0;
    forn(i, n - 1){
      int it = lower_bound(all(b), make_pair(a[i], i)) - b.begin();
      mx = max(mx, it);
      if(mx == i){
        res.push_back(i + 1);
      }
    }
    cout << res.size() << endl;
    if(res.size()){
      for(auto x : res){
        cout << x <<  ' ';
      }
    } else {
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
