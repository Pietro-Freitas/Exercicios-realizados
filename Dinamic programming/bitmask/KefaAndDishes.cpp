/*
    Código elegantemente feito por: Pietro
    Se compilou, envia
    https://codeforces.com/problemset/problem/580/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define ii pair<int, int>
#define FOR(i, ini, N) for (int i = ini; i < N; i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define INF 0x3f3f3f3f
const int MAX = 20;

int n;
vector<ll> satisfaction(MAX);
ll g[MAX][MAX];
ll dp[1<<18][18];

ll tsp(int mask, int dish, int m){
    if (__builtin_popcount(mask) == m) return 0;
    if (dp[mask][dish] != -1) return dp[mask][dish];
    ll ans = 0;
    FOR(choice, 0, n){
        if ((mask & (1 << choice)) == 0){
            ans = max(ans,  satisfaction[choice] + g[dish][choice] + tsp((mask | (1 << choice)), choice, m));
        }
    }
    return dp[mask][dish] = ans;
}

void solve(){
    int m, k; cin >> n >> m >> k;
    satisfaction.resize(n);
    memset(dp, -1, sizeof(dp));
    memset(g, 0, sizeof(g));
    for (auto &i : satisfaction) cin >> i;
    FOR(i, 0, k){
        int x, y; ll c; cin >> x >> y >> c; x--, y--;
        g[x][y] = c;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, satisfaction[i] + tsp((1 << i), i, m));
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}