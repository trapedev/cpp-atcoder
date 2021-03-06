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

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector<int> x = {1, 1, 1, 0, 0, -1, -1, -1}, y = {1, 0, -1, 1, -1, 1, 0, -1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 8; k++) {
                ll now = 0;
                ll X = i, Y = j;
                for(int l = 0; l < n; l++) {
                    now *= 10;
                    now += a[X][Y];
                    X += x[k];
                    Y += y[k];
                    X %= n;
                    X += n;
                    Y %= n;
                    Y += n;
                    X %= n;
                    Y %= n;
                }
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;
    return 0;
}