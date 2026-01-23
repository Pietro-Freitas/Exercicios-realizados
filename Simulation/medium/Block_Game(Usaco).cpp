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
    int n; cin >> n;
    vector<int> total_blocks(26, 0);

    for(int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(char c : s1) freq1[c - 'a']++;
        for(char c : s2) freq2[c - 'a']++;

        for(int j = 0; j < 26; j++) {
            total_blocks[j] += max(freq1[j], freq2[j]);
        }
    }

    for(int i = 0; i < 26; i++) {
        cout << total_blocks[i] << endl;
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