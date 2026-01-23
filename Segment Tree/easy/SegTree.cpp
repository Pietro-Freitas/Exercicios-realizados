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

vector<int> v(MAX);
int seg[4*MAX];

int build(int p, int l, int r){
    if( l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r){
    if(b < l or a > r) return INF;
    if(a <= l and r <= b) return seg[p];
    int m = (l+r) / 2;

    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int update(int i, int x, int p, int l, int r){
    if(i < l or r < i) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l+r) / 2;
    return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

void solve() {
    int n; cin >> n;
    FOR(i, 0, n) cin >> v[i];
    int ans = build(1, 0, n-1);
    cout << query(a, b, 1, 0, n-1) << endl;
    update(i, x, 1, 0, n-1); //* Muda o valor da posição i para x
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