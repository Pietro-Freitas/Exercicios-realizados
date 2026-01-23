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
const int MAX = 21;

int n;
vector<ll>apples(MAX);

ll my_func(int index, ll sum1, ll sum2){
    if(index == n) return abs(sum1 - sum2);

    return min(my_func(index+1, sum1 + apples[index], sum2), my_func(index+1, sum1,apples[index] + sum2));
}

void solve() {
    cin >> n;
    apples.resize(n);
    for(auto& i : apples) cin >> i;
    sort(apples.begin(), apples.end());
    cout << my_func(0, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}