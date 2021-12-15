#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
#include <ostream>

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
#define DIR4 {{0,1}, {1,0}, {0,-1}, {-1,0}}
#define DIR8 {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}}
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

#define vc vector<char>
#define vvc vector<vector<char>>
unordered_map<string, vector<string>> adj;
int res = 0;
vvi dp;
void dfs(set<string> vis, bool b, string c) {
//    printf("%s ", c.c_str());
    if (c == "end") {res++;return;}
    if (c.front() >= 'a') vis.insert(c);
    for(string s : adj[c]) {
        if(!vis.count(s))
            dfs(vis, b, s);
        else if (!b && s != "start") {
            dfs(vis, true, s);
        }
    }
    return;
}

_int main(void)
{
    string s;
    vvi v;
    while (getline(cin, s)) {
        char a;
        stringstream ss(s);
        v.pb(vi(0));
        while(ss >> a)  v.back().pb(a - '0');
    }
    int dim = v.size();
    cout << dim << endl;
    vvi dp = vvi(v.size()*5, vi(v.front().size()*5, INT_MAX));
    dp[0][0] = 0;
    queue<ii> q;
    q.push({0,0});
    vii dirs = DIR4;
    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        for(auto [di, dj] : dirs) {
            int x = i + di, y = j+dj;
            if (x >= 0 && y >= 0 && x < dp.size() && y<dp.front().size()) {
                int tx = x/dim;
                int ty = y/dim;
                auto dumb = [](int a, int b) -> int { a = (a+b); if (a>9) return a-9; else return a;};
                int d = dumb(v[x%dim][y%dim], (tx + ty));
              //  cout << i << ' ' << j << endl;
                if (chmin(dp[x][y], dp[i][j] + d)) {
  //                  printf("dp[%lld][%lld]: %lld\n", x, y, dp[x][y]);
  //                  std::flush(cout);
                    q.push({x,y});
                }
            }
        }
    }
    cout << dp[dp.size()-1][dp.front().size() - 1];
}


