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
    int n, S, x; cin >> n >> S >> x;
    int sumArr = 0;
    bool ans = false;
    vector<int> nums(n);
    for(auto& num : nums){ cin >> num; sumArr += num;}
    if(sumArr == S) ans = true;
    else{
        while(S > sumArr){
            sumArr += x;
        }
        if(sumArr == S) ans = true;
    }

    cout << (ans == true ? "YES" : "NO") << endl;

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