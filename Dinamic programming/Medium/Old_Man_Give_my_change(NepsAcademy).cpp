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
const int MAX = 1e3+10;

vector<int> coins;
vector<int> memo;
int n, m;

bool change(int m){
    if(m == 0) return memo[m] = true;
    if(m < 0) return false;
    if(memo[m] != -1) return memo[m];
    for(int  i = 0; i < n; i++){
        if(change(m-coins[i]) == true) return memo[m] = true;
    }
    return memo[m] = false;
}

void solve() {
    cin >> n >> m;
    int ans;
    coins.resize(n);
    memo.assign(MAX, -1);
    for(auto& i : coins) cin >> i;

    cout << (change(m) == true ? "S" : "N") << endl;
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