
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1e4 + 10;

void solve(){
	int n, m, ans =0; char l;
	map<int, int> le, e;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m >> l;
		if( l == 'E') le[m]++;
		else e[m]++;
	}
	for(auto p : le){
		int size = p.first;
		ans += min(le[size], e[size]);
	}
	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	int t = 1;
	// cin >> t;
	while(t--) solve();

	return 0;
}