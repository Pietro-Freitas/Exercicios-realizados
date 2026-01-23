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
    int n, m; cin >> n >> m;
    vector<int> limit(100, 0);
    vector<int> bessie(100, 0);
    int pos = 0;
    FOR(i, 0, n){
        int x, y; cin >> x >> y;
        FOR(j, 0, x) limit[pos++] = y;
    }
    pos =0;
    FOR(i, 0, m){
        int x, y; cin >> x >> y;
        FOR(j, 0, x) bessie[pos++] = y;
    }
    int ans = 0;
    FOR(i, 0, 100){
        if(limit[i] < bessie[i]) ans = max(ans, bessie[i] - limit[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}