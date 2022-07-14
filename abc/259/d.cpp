#include <bits/stdc++.h>

using ll = long long;
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

#define rep(i,n) for(int i = 0; i < (n); i++)
#define IntToStr(n) to_string(n) //整数を文字列に変換
#define StrToInt(s) stoi(s) //文字列を整数に変換 
#define rev(s) reverse(s.begin(), s.end()) //文字列反転
#define out(n) cout << n << endl

/*
queue: https://cpprefjp.github.io/reference/queue/queue.html
stack: https://cpprefjp.github.io/reference/stack.html
permutation: https://cpprefjp.github.io/reference/algorithm/next_permutation.html
*/

const ll mod = 1e9 + 7;
const int INF = 1000000001;

void solve(){

}

int n;
int S, T;
ll sx, sy, tx, ty;
ll x[101010], y[101010], r[101010];
vector<int> G[101010];
bool used[101010];

bool dfs(int v) {
    used[v] = true;
    if(v == T) {
        return true;
    }
    for(auto u : G[v]) {
        if(used[u]) {
            continue;
        }
        if(dfs(u)) {
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    cin >> sx >> sy >> tx >> ty;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            ll d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(d > (r[i]+r[j])*(r[i]+r[j]) || d < (r[i]-r[j])*(r[i]-r[j])) continue;
            G[i].push_back(j), G[j].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++){
        if((x[i]-sx)*(x[i]-sx) + (y[i]-sy)*(y[i]-sy) == r[i]*r[i]) S = i;
        if((x[i]-tx)*(x[i]-tx) + (y[i]-ty)*(y[i]-ty) == r[i]*r[i]) T = i;
    }

    if(dfs(S)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}