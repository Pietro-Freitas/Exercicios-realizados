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
const int MAX = 1e5+10;

int v[MAX];
ii seg[4*MAX];


ii combine(ii a, ii b) {
    if(a.f < b.f) return a;
    if(b.f < a.f) return b;
    return {a.f, a.s + b.s};
}

ii build(int p, int l, int r){
    if(l == r) return seg[p] = {v[l], 1};
    int m = (l+r) / 2;
    return seg[p] = combine(build(2*p, l, m), build(2*p+1, m+1, r));
}

ii query(int a, int b, int p, int l, int r){
    if(b < l or a > r) return {INF, 0};
    if(a <= l and r <= b) return seg[p];
    int m = (l+r) / 2;
    return combine(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

ii update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = {x, 1};
    int m = (l+r) / 2;
    return seg[p] = combine(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

void solve() {
    int n,q; cin >> n >> q;
    FOR(i, 0,  n) cin >> v[i];
    build(1, 0, n-1);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            // update
            int i, x; cin >> i >> x;
            update(i, x, 1, 0, n-1);
        } else {
            // query
            int a, b; cin >> a >> b; b--;
            auto x = query(a, b, 1, 0, n-1);
            cout << x.f << " " << x.s << endl;
        }
    }
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