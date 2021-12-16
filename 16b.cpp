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

string hextobin(const string &s){
    string out;
    for(auto i: s){
        uint8_t n;
        if(i <= '9' and i >= '0')
            n = i - '0';
        else
            n = 10 + i - 'A';
        for(int8_t j = 3; j >= 0; --j)
            out.push_back((n & (1<<j))? '1':'0');
    }

    return out;
}

struct pack {
    int ver;
    int typ;
    int val;
    vector<pack*> subps;
    int len;
};
# define sw string_view

int parsev(sw s) {
    int res = 0;
    for(char c : s){
        res = res << 1;
        res += c - '0';
    }
    return res;
}

int frombin(sw s) {
    int res = 0;
    FOR(i, s.size()) {
        res = res << 1;
        res += s[i] - '0';
    }
    return res;
}

ii parsel(sw s) {
    string bin;
    int i =0;
    for(; i < s.size(); i+=5) {
        bin.append(s.substr(i+1, 4));
        if(s[i] == '0') break;
    }
    i+=5;
    return {i, frombin(sw(bin))};
}

pack* parse(string_view s) {
    //cout << "start parsing: " << s << endl;
    pack& p = *new(pack);
    int& c = p.len;
    c = 0;
    p.ver = parsev(s.substr(0, 3));
    res += p.ver;
    c += 3;
    p.typ = parsev(s.substr(3, 3));
    c += 3;
   // printf("v: %lld, t: %lld\n", p.ver, p.typ);
    ii a;
    switch (p.typ) {
        case 4:
            a = parsel(s.substr(c));
            p.val = a.second;
            c += a.first;
         //   printf("parsed parse literal: %lld c: %lld\n", p.val, c);
            return &p;
        default:
            //cout << s[c] << endl;
            if (s[c] == '0') {
                c++;
                int len = parsev(s.substr(c, 15));
                c += 15;
              //  printf("parse subpackage with len: %lld c:%lld\n", len, c);
                while (len) {
                    p.subps.pb(parse(s.substr(c, len)));
                    len -= p.subps.back()->len;
                    c += p.subps.back()->len;
                   // printf("parsed subpackage: %lld\n", c);
                }
            } else if (s[c] == '1') {
                c++;
                int len = parsev(s.substr(c, 11));
                c += 11;
             //   printf("parse multi subpackage: %lld c:%lld\n", len, c);
                FOR(i, len) {
                    p.subps.pb(parse(s.substr(c)));
                    c += p.subps.back()->len;
                    //printf("parsed spkg: %lld\n", c);
                }
            } else {
                cout << " fatal invalid syntax:" << s[7] << endl;
                return &p;
            }
    }
    return &p;
}

int eval(pack* p) {
    if(!p) {printf("fatal nilpointer"); return 42;}
    int r = 0;
//    printf("typ:%lld\n", p->typ);
    switch (p->typ) {
        case 0:
            for(pack* sp : p->subps) r += eval(sp);
            break;
        case 1:
            r = 1;
            for(pack* sp : p->subps) r *= eval(sp);
            break;
        case 2:
            r = eval(p->subps.front());
            for(pack* sp : p->subps) r = min(r, eval(sp));
            break;
        case 3:
            r = eval(p->subps.front());
            for(pack* sp : p->subps) r = max(r, eval(sp));
            break;
        case 4:
            r = p->val;
            break;
        case 5:
            r = eval(p->subps.front()) > eval(p->subps.back());
            break;
        case 6:
            r = eval(p->subps.front()) < eval(p->subps.back());
            break;
        case 7:
            r = eval(p->subps.front()) == eval(p->subps.back());
            break;
    }
    return r;
}
_int main(void)
{
    string s;
    cin >> s;
    string bins = hextobin(s);
    //cout << bins.size() << ' ' << bins << endl;;
    pack *p = parse(bins);
    printf("%lld\n", eval(p));
    cout << res << endl;
}


