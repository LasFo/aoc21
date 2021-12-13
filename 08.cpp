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
int isin(const vc& a, const vc& b) {
    int res = 0;
    for(char c : a) {
        res += find(b.begin(), b.end(), c) != b.end();
    }
    return res;
}
int isins(const vc& a, const string& b) {
    int res = 0;
    for(char c : a) {
        res += find(b.begin(), b.end(), c) != b.end();
    }
    return res;
}

_int main(void)
{
    string s;
    int res = 0;
    while(getline(cin, s)) {
//        while(cin.peek() != '|') {cout << cin.peek(); cin.ignore();}
        stringstream ss = stringstream(s);
        vvc v(10);
        string d;
        REP(10) {
            ss >> d;
            int ds = d.size();
            switch(ds){
                case 2:
                    for(char c : d) v[1].pb(c);
                    break;
                case 3:
                    for(char c : d) v[7].pb(c);
                    break;
                case 4:
                    for(char c : d) v[4].pb(c);
                    break;
                case 5:
                    if (!v[2].size()) {
                        for(char c : d) v[2].pb(c);
                    } else if (!v[3].size()) {
                        for(char c : d) v[3].pb(c);
                    } else if (!v[5].size()) {
                        for(char c : d) v[5].pb(c);
                    } else {
                        cout << "error!";
                        return 0;
                    }
                    break;
                case 6:
                    if (!v[0].size()) {
                        for(char c : d) v[0].pb(c);
                    } else if (!v[6].size()) {
                        for(char c : d) v[6].pb(c);
                    } else if (!v[9].size()) {
                        for(char c : d) v[9].pb(c);
                    } else {
                        cout << "error!";
                        return 0;
                    }
                    break;
                case 7:
                    for(char c : d) v[8].pb(c);
                    break;
                default:
                    cout << ds << "does not work";
                    return 0;
            }

        }
        vvc results(10);
        vi somerandomvector = {1, 4, 7, 8};
        for (int i : somerandomvector) for(char c : v[i]) results[i].pb(c);
        { // compute 3
            vc a0 = v[2];
            vc a1 = v[3];
            vc a2 = v[5];
            if (isin(results[1], a0) == 2) {for(char c : a0) results[3].pb(c); a0 = a1; a1 = a2;}
            else if (isin(results[1], a1) == 2) {for(char c : a1) results[3].pb(c); a1 = a2;}
            else if (isin(results[1], a2) == 2) for(char c : a2) results[3].pb(c);

            if(isin(results[4], a0) == 3) {
                for (char c : a0) results[5].pb(c);
                for (char c : a1) results[2].pb(c);
            } else {
                for (char c : a1) results[5].pb(c);
                for (char c : a0) results[2].pb(c);
            }
        }
        { // compute
            vc a0 = v[0];
            vc a1 = v[6];
            vc a2 = v[9];
            if (isin(results[1], a0) == 1) {for(char c : a0) results[6].pb(c); a0 = a1; a1 = a2;}
            else if (isin(results[1], a1) == 1) {for(char c : a1) results[6].pb(c); a1 = a2;}
            else if (isin(results[1], a2) == 1) for(char c : a2) results[6].pb(c);

            if(isin(results[4], a0) == 3) {
                for (char c : a0) results[0].pb(c);
                for (char c : a1) results[9].pb(c);
            } else {
                for (char c : a1) results[0].pb(c);
                for (char c : a0) results[9].pb(c);
            }
        }
//        FOR(i,10) {cout << i << ' '; for( char c : results[i]) cout << c; cout << endl;}
        ss.ignore(2);
        int curres = 0;
        REP(4) {
            curres *= 10;
            string s;
            ss >> s;
            FOR(i, 10) {
                vc a = results[i];
                if (a.size() != s.size()) continue;
                if (isins(a, s) == s.size()) curres+=i;
            }
        }
        res += curres;
    }
    cout << res;
}

