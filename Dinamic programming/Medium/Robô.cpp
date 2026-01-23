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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;

ll n, m;
vector<vector<ll>> dp;
vector<vector<int>>grid;

int gridTraveler(int i, int j, vector<vector<int>>grid){
    if(i < 0 || j < 0) return 0;
    if(grid[i-1][j-1] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i ==1 || j == 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = gridTraveler(i, j-1, grid) + gridTraveler(i-1, j,grid);
}

void solve() {
    cin >> n >> m;
    grid.assign(n+2, vector<int>(m+2,0));
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> grid[i][j];
    dp.assign(n+2, vector<ll>(m+2, -1));
    cout << gridTraveler(n,m, grid) << endl;
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