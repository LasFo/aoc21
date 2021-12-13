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

//const char* cc[] = {"fold along y=7", "fold along x=5"};


const char* cc[] ={
"fold along x=655"
,"fold along y=447"
,"fold along x=327"
,"fold along y=223"
,"fold along x=163"
,"fold along y=111"
,"fold along x=81"
,"fold along y=55"
,"fold along x=40"
,"fold along y=27"
,"fold along y=13"
,"fold along y=6"};

_int main(void)
{
    string s;
    unordered_map<int, set<int>> ds;
    int x,y;
    int xmax = 0, ymax = 0;
    while (scanf("%lld %lld", &x, &y) != -1) {
        ds[x].insert(y);
    }
    char c;
    int b;
    int cnt = 0;
    while(cnt < 12 && sscanf(cc[cnt], "fold along %c=%lld\n", &c, &b) != -1) {
        cout << c << " " << b << endl;
        cnt++;
        unordered_map<int, set<int>> newm;
        if (c == 'x') {
            for(auto& [x,m]:ds)
                if(x > b)
                    newm[x - 2*(x-b)].insert(m.begin(), m.end());
                else if (x < b)
                    newm[x].insert(m.begin(), m.end());
        } else {
            for(auto& [x,m]:ds) for(auto y: m)
                if(y > b)
                    newm[x].insert(y - 2*(y-b));
                else if (y<b)
                    newm[x].insert(y);
        }
        ds = newm;
    }
    cout << endl;
    int res = 0;
    xmax=0;
    ymax=0;
    for(auto& [x,m]:ds){
        chmax(xmax, x);
        for (int y : m) chmax(ymax, y);
        res += m.size();
    }
    cout << xmax << ' ' << ymax << endl;
    vvi r(xmax+1, vi(ymax+1));
    for(auto& [x,m]:ds){
        for (int y : m) r[x][y] = 1;
    }
    FOR(j, r.front().size()) {
        FOR(i, r.size()) {
            if (r[i][j]) {
                cout << "#";
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << res << endl;
}


