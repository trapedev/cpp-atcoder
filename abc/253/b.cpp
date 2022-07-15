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
    int h, w;
    cin >> h >> w;
    int x1, y1, x2, y2;
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c == 'o') {
                if(cnt == 0) {
                    x1 = i;
                    y1 = j;
                    cnt++;
                } else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    return 0;
}