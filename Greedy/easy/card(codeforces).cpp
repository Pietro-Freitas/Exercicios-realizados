#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF max_int
const int MAX = 1000;

void solve(){
	int n; cin >> n;
	string p; cin >> p;
	int one = 0, z = 0, r = 0;

	for(char c : p){
		if(c == 'n') one++;
		else if(c == 'z')  z++;
		else if(c == 'r') r++;
	}

	for(int i = 0; i < one; i++) cout << 1 << ' ';
	for(int i = 0; i < min(z, r); i++) cout << 0 << ' ';	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	int t = 1;
	// cin >> t;
	while(t--) solve();

	return 0;
}