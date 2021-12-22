#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
#include <algorithm>

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
#define sw string_view
#define vc vector<char>
#define vvc vector<vector<char>>
#define PRINTVVI(v) FOR(i, v.size()) { FOR(j, v[i].size()) printf("%lld ", v[i][j]); printf("\n"); }
#define PRINTVVC(v) FOR(i, v.size()) { FOR(j, v[i].size()) printf("%c", v[i][j]); printf("\n"); }

struct step {
    int x0,x1,y0,y1,z0,z1;
    bool add;
};

_int main(void) {

    string s;
    vector<step> steps;
    vi x,y,z;

    while(getline(cin, s)) {
        steps.emplace_back();
        step& an = steps.back();
        an.add = s[1] == 'n';
        if (an.add) {
            sscanf(s.c_str(), "on x=%lld..%lld,y=%lld..%lld,z=%lld..%lld", &an.x0, &an.x1, &an.y0, &an.y1, &an.z0, &an.z1);
        } else {
            sscanf(s.c_str(), "off x=%lld..%lld,y=%lld..%lld,z=%lld..%lld", &an.x0, &an.x1, &an.y0, &an.y1, &an.z0, &an.z1);
        }
        an.x1++;
        an.y1++;
        an.z1++;
        x.pb(an.x0);
        x.pb(an.x1);
        y.pb(an.y0);
        y.pb(an.y1);
        z.pb(an.z0);
        z.pb(an.z1);
    }
    SORT(x);
    SORT(y);
    SORT(z);

    auto getindex = [&](vi& v, int c) -> int {
        return (int)(lower_bound(ALL(v), c) - v.begin());
    };
    int n = x.size();
    vector<vvi> grid(n, vvi(n, vi(n, 0)));

    for(step s : steps) {
        int x0 = getindex(x, s.x0);
        int x1 = getindex(x, s.x1);
        int y0 = getindex(y, s.y0);
        int y1 = getindex(y, s.y1);
        int z0 = getindex(z, s.z0);
        int z1 = getindex(z, s.z1);

        for(int x = x0; x < x1; x++) {
            for(int y = y0; y < y1; y++) {
                for(int z = z0; z < z1; z++) {
                    grid[x][y][z] = s.add;
                }
            }
        }

    }

    int res = 0;
    FOR(xc, n-1) FOR (yc, n-1) FOR(zc, n-1)
        res += grid[xc][yc][zc] * (x[xc+1] - x[xc]) * (y[yc+1] - y[yc]) * (z[zc+1] - z[zc]);

    printf("%lld", res);
}



