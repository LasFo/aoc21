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

_int main(void)
{
    string s;
    vvi os;
    int res = 0;
    while(getline(cin, s)) {
        stringstream ss(s);
        char tmp;
        os.pb(vi(0));
        os[res].reserve(s.size());
        while(ss >> tmp) os[res].pb((int) tmp-'0');
        res++;
    }
    vii deltas = DIR8;
    res = 0;
    REP(10000) {
        queue<ii> q;
        set<ii> vis;
        FOR(i, os.size()) FOR(j, os.front().size()) {
            os[i][j]++;
            if(os[i][j] > 9){
                q.push({i,j});
                vis.insert({i,j});
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for(auto [dx, dy]: deltas) {
                int id = i+dx, jd = j+dy;
                if (id >= 0 && id < os.size() && jd >=0 && jd < os[i].size() ) {
                    if(!vis.count({id, jd}) && ++os[id][jd] > 9) {
                        vis.insert({id, jd});
                        q.push({id, jd});
                    }
                }
            }
        }
        res+=vis.size();
        if (vis.size() == os.size() * os.front().size()) {
                cout << "finish" <<  __i << endl;
                break;
        }
        for(auto [i,j] : vis) {
            os[i][j] = 0;
        }
    }
    cout << res;
}

