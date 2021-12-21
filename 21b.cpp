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


_int main(void) {
    int a, b;
    scanf("Player 1 starting position: %lld\n", &a);
    scanf("Player 2 starting position: %lld", &b);
    printf("a: %lld b:%lld\n", a, b);
    int nor = 0;
    auto d = [&, i = 0]() mutable {
        int res = 0;
        nor += 3;
        REP(3) res += (++i) % 100;
 //       printf("d=%lld\n", res);
        return res;
    };
    vector<vector<vvi>> dp(22, vector<vvi>(22, vvi(11, vi(11, 0))));
    dp[0][0][a][b] = 1;
    REP(10000) {
        vector<vector<vvi>> ndp(22, vector<vvi>(22, vvi(11, vi(11, 0))));
        FOR(i, 11) FOR(j,11) FOR(k, 22) {
            ndp[21][k][i][j] = dp[21][k][i][j];
            ndp[k][21][i][j] = dp[k][21][i][j];
        }
        bool found = false;
        if (__i % 2) {
            FOR(q, 21) FOR(w, 21) FOR(e, 11) FOR(r, 11) {
                if (!dp[q][w][e][r]) continue;
                found = true;
                FOR(i, 3)
                    FOR(j, 3)
                        FOR(k, 3) {
                            int b = r + i + j + k + 3;
                            b = ((b-1)%10)+1;
                            int bw = w+b;
                            ndp[q][min(bw,21ll)][e][b] += dp[q][w][e][r];
                        }
            }
        }
        else {
            FOR(q, 21) FOR(w, 21) FOR(e, 11) FOR(r, 11) {
                if (!dp[q][w][e][r]) continue;
                found = true;
                FOR(i, 3)
                    FOR(j, 3)
                        FOR(k, 3) {
            //                printf("%lld ", i+k+j+3);
                            int a = e + i + j + k + 3;
                            a = ((a-1)%10)+1;
                            int aw = q+a;
                            ndp[min(aw,21ll)][w][a][r] += dp[q][w][e][r];
                        }
            }
        }
        dp = ndp;
        if (!found) break;
        printf("loop#%lld\n", __i);
     //   FOR(q, 20) FOR(w, 20) FOR(e, 11) FOR(r, 11) {
     //           if (dp[q][w][e][r]) printf("dp[%lld][%lld][%lld][%lld] = %lld\n", q, w, e,r, dp[q][w][e][r]);
     //   }
//        printf("aw: %lld\nbw: %lld\n", aw, bw);
//        if (aw > 999 || bw > 999){ printf("%lld", min(aw,bw)*nor); return 0;}
    }
    int aw = 0, bw = 0;
    FOR(i, 11) FOR(j,11) FOR(k, 21) {
        aw += dp[21][k][i][j];
    }
    FOR(i, 11) FOR(j,11) FOR(k, 21) {
        bw += dp[k][21][i][j];
    }
    printf("%lld\n", max(bw, aw));

}



