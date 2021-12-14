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


_int main(void)
{
    string tmpl;
    getline(cin, tmpl);
    string s;
    getline(cin, s);
    map<string, string> rs;
   cout << tmpl << endl;

    while(getline(cin,s)){
        string f, a,  t;
        stringstream(s) >> f >> a >> t;
//        cout << f << '-' << t << endl;;
        rs.insert({f, t});
    }
//    cout << rs.size() << endl;
    map<string, vi> odp;
    for(auto& [f, _] : rs) {
        vi v(26, 0);
        for(char c : f) v[c-'A']++;
        odp.insert({f, v});
    }
    REP(40) {
        map<string, vi> ndp;
        for(auto [f, t] : odp) {
            vi v(26, 0);
            string s;
            s.append(1, f.front());
            s.append(rs.find(f)->second);
         //   cout << s << endl;
            if(auto it = odp.find(s); it != odp.end()) {
                FOR(i, 26) v[i] += it->second[i];
            }
            swap(s[0], s[1]);
            s[1] = f.back();
          //  cout << s << endl;
            if(auto it = odp.find(s); it != odp.end()) {
                FOR(i, 26) v[i] += it->second[i];
            }
            v[s[0]-'A']--;

            ndp.insert({f, v});
        }
        odp = ndp;
//        string newtmp;
//        newtmp.append(1, tmpl[0]);
//        FOR(i, tmpl.size()-1) {
//            string key;
//            key.append(1, tmpl[i]);
//            key.append(1, tmpl[i+1]);
//            if(auto it = rs.find(key); it != rs.end()) {
//                newtmp.append(it->second);
//            }
//            newtmp.append(1, tmpl[i+1]);
//        }
////        cout << newtmp.size() << endl;
////        cout << newtmp << endl;
//        tmpl = newtmp;
    }
    vi v(26, 0);
    //v[tmpl[tmpl.size()-1] - 'A']++;
    FOR(i, tmpl.size()-1) {
        v[tmpl[i] - 'A']--;
        string s;
        s.append(1, tmpl[i]);
        s.append(1, tmpl[i+1]);
        if(auto it = odp.find(s); it != odp.end()) {
            FOR(i, 26) v[i] += it->second[i];
          //  cout << it->first << endl;
          //  v = it->second;
          //  FOR(i, 26) if(v[i]) cout << (char)(i+'A') << ' ' << v[i] << endl;
        }
    }
//    unordered_map<char, int> res;
//    for(char c : tmpl) {
//        res[c]++;
//    }
    int mi = numeric_limits<int64_t>::max(), ma = 0;
    FOR(i, v.size()) {
        int b = v[i];
        if (b==0) continue;
        //cout << x << ' ' << i << endl;
        if(chmax(ma, b)) cout << (char)(i+'A') << " ma " << b << endl;
        if(chmin(mi, b)) cout << (char)(i+'A') << " mi " << b << endl;
    }
    cout << ma - mi;
}


