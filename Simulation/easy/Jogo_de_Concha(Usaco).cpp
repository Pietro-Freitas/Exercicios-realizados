/*
    Código elegantemente feito por: Pietro
    Se compilou, envia
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define FOR(i,ini,N) for(int i=ini;i<N;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;

void solve() {
    int n; cin >> n;
    
    vector<int>shells(3);
    shells[0] = 0; shells[1] = 1; shells[2] = 2;
    
    vector<int> count(3);
	for (int i = 0; i < n; i++) {
		int a, b, g; cin >> a >> b >> g; a--, b--, g--;
        swap(shells[a], shells[b]);
        count[shells[g]]++;
	}
    cout << max({count[0], count[1], count[2]}) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}