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
    int n, q; cin >> n >> q;
    vector<int>a(n);
    vector<int>b(n);
    vector<int> c(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    FOR(i,0 ,n) c[i] = max(a[i], b[i]);
    vector<int> best(n);
    int max = -INF;
    for(int i = n-1; i >= 0; i--){
        if(c[i] > max) max = c[i];
        best[i] = max;
    }

    vector<int> sumP(n+1);
    
    FOR(i, 0, n){
        sumP[i + 1] = sumP[i] + best[i];
    }
    vector<int> ans;
    FOR(i, 0 ,q){
        int l, r; cin >> l >> r;
        int sum = sumP[r] - sumP[l-1];
        ans.push_back(sum);
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}