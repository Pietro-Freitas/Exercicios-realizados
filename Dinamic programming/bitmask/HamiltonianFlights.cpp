/*
    Código elegantemente feito por: Pietro
    Se compilou, envia
    https://cses.fi/problemset/task/1690
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define f first
#define s second
#define eb emplace_back
#define ii pair<int, int>
#define FOR(i,ini,N) for(int i=ini;i<N;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 20;

vector<vector<int>> g;
int dp[1<<MAX][MAX];

int tsp(int mask, int city, int n){
    if((mask != (1 << n) - 1) && city == n-1) return 0;
    if((mask == (1 << n) - 1) && city == n-1) return 1;
    if(dp[mask][city] != -1) return dp[mask][city];
    int ans = 0;
    for(auto choice : g[city]){
        if(!(mask & (1<<choice))){
            ans =  (ans + tsp((mask | (1<<choice)), choice, n)) % 1000000007;
        }
    }
    return dp[mask][city] = ans;
}

void solve() {
    int n, m; cin >> n >> m;
    g.resize(n);
    memset(dp, -1, sizeof(dp));
    FOR(i,0, m){
        int x, y; cin >> x >> y; x--, y--;
        g[x].eb(y);
    }
    cout << tsp(1, 0, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}