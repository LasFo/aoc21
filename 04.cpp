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

vector<vector<vector<pair<int,bool>>>> bs;
int cnt = 0;
set<int> wins;

pair<bool, int> check_col(vector<vector<pair<int,bool>>>& v, int j) {
    bool w = true;
    FOR(i, 5) {
        w &= v[i][j].second == true;
    }
    int res = 0;
    if (w) {
        FOR(i,5) FOR(j,5) res += v[i][j].first * !v[i][j].second;
    }
    return make_pair(w, res);
}

pair<bool, int> check_row(vector<vector<pair<int,bool>>>& v, int i) {
    bool w = true;
    FOR(j, 5) {
        w &= v[i][j].second == true;
    }
    int res = 0;
    if (w) {
        FOR(i,5) FOR(j,5) res += v[i][j].first * !v[i][j].second;
    }
    return make_pair(w, res);
}

int cmpwin(int n) {
    FOR(k, cnt) {
        auto& ref = bs[k];
        FOR(i, 5) FOR(j, 5) {
            if (ref[i][j].first == n) {
                //cout << n <<  ' ' << k << ' ' << i << ' ' << j << endl;
                ref[i][j].second = true;
                if (auto p = check_row(ref, i); p.first) {
                    cout << "win: " << k << endl;
                    wins.insert(k);
                    if (wins.size() == cnt) return p.second;
                }
                if (auto p = check_col(ref, j); p.first){
                    cout << "win: " << k << endl;
                    wins.insert(k);
                    if (wins.size() == cnt) return p.second;
                }
            }
        }
    }
    return -1;

}

_int main(void)
{
    vi ds;
    string b;
    getline(cin, b);
  //  cout << b << endl;
    stringstream ss = stringstream(b);
    int tmp;
    while (ss >> tmp) {
        ds.pb(tmp);
        if (ss.peek()==',') ss.ignore();
   //     cout << tmp << ' ';
    }
    while (cin){
        bs.pb(vector<vector<pair<int, bool>>>(5, vector<pair<int, bool>>(5, make_pair(0, false))));
        FOR(i, 5) FOR(j, 5) {cin >> bs[cnt][i][j].first; bs[cnt][i][j].second = false;}
        cnt++;
    }
    cnt--;
//    FOR(k, cnt) {
//        FOR(i, 5) {
//            FOR(j,5) cout << bs[k][i][j].first << ' ';
//            cout << '\n';
//        } cout << endl;
//    }
    for(int i : ds) {
//        cout << i << endl;
        int w = cmpwin(i);
        if ( w != -1) { cout << w * i; return 0; }
    }


}

