#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 110;

int n, M;
char m[MAX][MAX];
bool vis[MAX][MAX];
//cima, baixo, esquerda e direita
vector<pair<int,int>> mov = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};

bool val(pair<int, int> u){
    return u.f > 0 and u.s > 0 and u.f < n and u.s < M
    and m[u.f][u.s] == 'H' and !vis[u.f][u.s];
}

pair<int, int> bfs(pair<int,int> s){
    queue<pair<int,int>> q;
    q.push(s), vis[s.f][s.s];

    pair<int,int> v;
    while(!q.empty()){
        v = q.front(); q.pop();
        for(auto u : mov){
            u.f += v.f, u.s = v.s;//new_i = u.f + v.f
            if(val(u)){
                q.push(u), vis[u.f][u.s] = true;
            }
        }
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> M;
    for(int i = 0; i < n; i++) for(int j = 0; j < M; j++) cin >> m[i][j];

    pair<int,int> s;
    for(int i = 0; i < n; i++) for(int j = 0; j < M; j++) if(m[i][j] == 'o') s = {i, j};

    pair<int, int> ans = bfs(s);
    cout << ans.f+1 << " " << ans.s+1 << endl;

    return 0;
}