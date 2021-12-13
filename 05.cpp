#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"

using namespace std;
using namespace atcoder;
using _int = int;

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(n) FOR(__i, n)
#define int long long
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vull vector<ull>
#define ALL(c) c.begin(), c.end()
#define SORT(x) sort(ALL(x))
#define SZ(x) ((int) x.size())
#define pb push_back
#define ii pair<int, int>
#define MOD 1000000007
#define MOD2 998244353
#define vii vector<pair<int,int>>
template<typename T>
bool chmin(T& a, const T b) { return a > b ? a = b, true : false; }

template<typename T>
bool chmax(T& a, const T b) { return a < b ? a = b, true : false; }

template<typename T>
T sgn(const T a) { return (a > 0) - (a < 0); }
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
      (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

#define vc vector<char>
#define vvc vector<vector<char>>
#define mpow pow_mod

//auto toDec = bind(static_cast<_int(*)(const string&, size_t*, _int)>(stoi), placeholders::_1,(size_t*) nullptr, 2);
vvi grid(1000, vi(1000, 0));
void setrow(int r, int s, int e){
    FOR(i, e-s+1) grid[r][i+s]++;
}
void setcol(int c, int s, int e) {
    FOR(i, e-s+1) grid[i+s][c]++;
}

void setdiag(int x0, int y0, int x1, int y1) {
    if (x0<x1) {
        if (y0 < y1) {
            FOR(i, x1-x0+1) grid[x0+i][y0+i]++;
        } else {
            FOR(i, x1-x0+1) grid[x0+i][y0-i]++;
        }
    }else{
        if (y0 < y1) {
            FOR(i, x0-x1+1) grid[x1+i][y1-i]++;
        } else {
            FOR(i, x0-x1+1) grid[x1+i][y1+i]++;
        }
    }
}

_int main(void)
{
    int x0, y0, x1, y1;
    vector<pair<ii, ii>> ls;
    string s;
    int ma = 0;
    while(getline(cin, s)) {
        sscanf(s.c_str(), "%lld,%lld -> %lld,%lld", &x0, &y0, &x1, &y1);
        ls.pb({{x0, y0}, {x1, y1}});
    }

    for(auto [a, b] : ls) {
        auto [x0, y0] = a;
        auto [x1, y1] = b;
        if (x0 == x1) setrow(x0, min(y0, y1), max(y0,y1));
        else if (y1 == y0) setcol(y0, min(x0,x1), max(x0,x1));
    }
    int res = 0;
    FOR(i, 1000) {
        FOR(j,1000) {
            res += grid[i][j] > 1;
        }
    }
    cout << res;
}

