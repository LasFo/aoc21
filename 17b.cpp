#include "bits/stdc++.h"
#include <cstdio>
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
   int xb, xe, yb, ye;
   scanf("target area: x=%lld..%lld, y=%lld..%lld", &xb, &xe, &yb, &ye);
   printf("x: %lld..%lld, y=%lld..%lld\n", xb, xe, yb, ye);
   int xmin, xmax;
   REP(1000) {
       if (__i * (__i+1)/2 >= xb) xmin = min(xmin, __i);
       if (__i <= xe) xmax = max(xmax, __i);
   }
   res = 0;
   auto compute = [=](int x0, int y0) -> bool {
       int x =0, y =0;
       REP(1000) {
           x += x0;
           if(x0) x0--;
           y += y0;
           y0--;
//           printf("x:%lld, y:%lld\n", x, y);
           if (x >= xb && x <= xe && y >= yb && y <= ye) return true;
       }
       return false;
   };
   cout << xmin << ' ' << xmax << endl;

   REP(1000) {
       int y = __i - 500;
       for (int i = xmin; i <= xmax; i++) {
 //          printf("x=%lld, y=%lld\n", i, __i);
           if (compute(i, y)) {
               res++;
           }
       }
   }
   cout << res;
}


