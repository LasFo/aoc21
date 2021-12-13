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

#define vc vector<char>
#define vvc vector<vector<char>>

_int main(void)
{
    vvc hm;
    string s;
    int res=0;
    while(getline(cin, s)) {
        stringstream ss(s);
        char c;
        hm.pb(vc{});
        while (ss >> c) hm[res].pb(c);
        res++;
    }
//    cout << hm.size() << endl;;
//    for(auto& a : hm) {for(auto c : a) cout << c; cout <<endl;}
    vii bs;
    FOR(i, hm.size()) FOR(j, hm.front().size()) {
        bool b = true;
        if (i > 0) b &= hm[i][j] < hm[i-1][j];
        if (i < hm.size()-1) b &= hm[i][j] < hm[i+1][j];
        if (j < hm.front().size()-1) b &= hm[i][j] < hm[i][j+1];
        if (j > 0) b &= hm[i][j] < hm[i][j-1];
        if (b) {
         //   cout << hm[i][j] << ' ' << i << ' ' << j << endl;
         //   res += hm[i][j] +1 - '0';
            bs.pb({i,j});
        }
    }
    int l0 = 0, l1 =0, l2 = 0;
    for(auto p : bs) {
        queue<ii> q;
        set<ii> vis;
        q.push(p);
     //   printf("%d, %d\n", p.first, p.second);
        while (!q.empty()) {
            auto [i, j] = q.front();
    //        cout << i<< " " << j << endl;
            q.pop();
            vis.insert({i,j});
            if (i > 0 && hm[i-1][j] != '9' &&  hm[i][j] < hm[i-1][j] && !vis.count({i-1,j})) q.push({i-1, j});
            if (j > 0 && hm[i][j-1] != '9' &&  hm[i][j] < hm[i][j-1] && !vis.count({i,j-1})) q.push({i, j-1});
            if (i < hm.size()-1 && hm[i+1][j] != '9' &&  hm[i][j] < hm[i+1][j] && !vis.count({i+1,j})) { q.push({i+1, j});}
            if (j < hm.front().size()-1 && hm[i][j+1] != '9' &&  hm[i][j] < hm[i][j+1] && !vis.count({i,j+1})) q.push({i, j+1});
        }
        if(vis.size() > l0) {l2=l1;l1=l0; l0 = vis.size();}
        else if(vis.size() > l1) {l2=l1;l1=vis.size();}
        else if(vis.size() > l2) {l2=vis.size();}
    }
    cout << l0 << ' ' << l1 << ' '<< l2 << endl;

    res = 0;
    cout << l0*l1*l2;
}

