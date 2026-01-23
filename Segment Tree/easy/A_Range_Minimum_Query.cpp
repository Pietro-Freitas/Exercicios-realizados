/*
    Código elegantemente feito por: Pietro
    Se compilou, envia

    https://codeforces.com/edu/course/3/lesson/18/1/practice/contest/619571/problem/A
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
const int MAX = 1e5 + 10;

int v[MAX];
int seg[4*MAX];

int build(int q, int l, int r){
    if(l == r) return seg[q] = v[l];
    int m = (l+r)/2;
    return seg[q] = min(build(2*q, l, m), build(2*q+1, m+1, r));
}

int query(int i, int j, int q, int l, int r){
    if(j < l or r < i) return INF;
    if(i <= l and r <= j) return seg[q];
    int m = (l+r) / 2;
    return min(query(i, j, 2*q, l, m), query(i, j, 2*q+1, m+1, r));
}

void solve() {
    int n, q; cin >> n;
    memset(seg, -1, sizeof seg);
    memset(v, -1, sizeof v);
    FOR(i, 0, n) cin >> v[i];
    build(1, 0, n-1);
    cin >> q;
    while(q--){
        int i, j; cin >> i >> j;
        int ans = query(i, j, 1, 0, n-1);
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}