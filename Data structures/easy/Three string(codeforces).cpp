/*
    Se o código não passar vc é gay 
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF max_int
const int MAX = 100;


void solve(){
	string a, b, c; cin >> a >> b >> c;
	bool ans = false;

	for(int i = 0; i < a.size(); i++){
		if(a[i] == c[i] || b[i] == c[i]) ans = true;
		else{
			ans = false;
			break;
		}
	}

	cout << (ans == true ? "YES" : "NO") << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	#endif

	int t = 1;
	cin >> t;
	while(t--) solve();

	return 0;
}