/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> I(n), D(n);
		I[0] = 1; D[n - 1] = 1;
		for(int i = 1; i < n; i++){
			if(a[i] > a[i - 1]){
				I[i] = I[i - 1] + 1;
			} else {
				I[i] = 1;
			}
		}
		for(int i = n - 2; i >= 0; i--){
			if(a[i] > a[i + 1]){
				D[i] = D[i + 1] + 1;
			} else {
				D[i] = 1;
			}
		}
		int ans = max(I[n - 1], D[0]);
		for(int i = 1; i < n - 1; i++){
			if(a[i] > a[i - 1] && a[i] > a[i + 1]){
				ans = max(ans, 1 + I[i - 1] + D[i + 1]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

