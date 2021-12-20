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
    vc iea(512);
    REP(512) {
        scanf("%c", &iea[__i]);
    }
//    FOR(i, 512) printf("%c", iea[i]);
//    printf("\n");
  //  iea[0] = '.';
    string s;
    getline(cin, s);
    getline(cin, s);
    vvc img;
    while (getline(cin, s)) {
        img.pb(vc(s.size()));
        FOR(i, s.size()) img.back()[i] = s[i];
    }
    PRINTVVC(img);
//    return 1;
    int def = 0;
    auto get = [&](int i, int j) -> int {
        if (i<0 || j <0 || i>=img.size() || j>=img.front().size()) return def;
        return img[i][j] == '#';
    };
    REP(50){
        vvc nimg(img.size()+2, vc(img.front().size()+2));
//        printf("def is %lld\n", def);
//        printf("idim: %lld jdim:%lld\n", img.size(), img.front().size()); fflush(stdout);
        for(int i = -1; i < (int)img.size()+1; i++) {
//            printf("sizeof img.front(): %lld\n", img.front().size());
            for(int j = -1; j < (int)img.front().size()+1; j++) {
                int idx = 0;
                FOR(a, 3) FOR(b,3) {
                    idx = idx << 1;
                    idx += get(i+a-1, j+b-1);
        //            printf("get(%lld, %lld) = %lld\n", i+a-1, j+b-1, get(i+a-1, j+b-1));
                }
//                if (idx)
 //               printf("%lld,%lld -> %lld\n", i, j, idx); fflush(stdout);
//                printf("%lld %lld\n", i+1, j+1); fflush(stdout);
                nimg[i+1][j+1] = iea[idx];
//                return 1;
            }
        }
        img = nimg;
        printf("\n");
        PRINTVVC(img);
        printf("\n");
        def = iea[0] == '.' ? false : iea[(__i % 2) * 511] == '#';
    }
    PRINTVVC(img);
    printf("%lld x %lld\n", img.size(), img[0].size());
    int res = 0;
    FOR(i, img.size()) FOR(j, img.front().size()) { res += img[i][j] == '#';}
    printf("%lld", res);

}



