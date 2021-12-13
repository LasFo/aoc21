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
    int res = 0;
    int cnt = 0;
    vvc vallines;
    while(getline(cin, s)) {
        stringstream ss(s);
        cout << "START" << s << endl;
        char c;
        vc li;
        int p = 0, sb =0, cc = 0, a = 0;
        cnt = 0;
        while (ss >> c) {
            cnt++;
            bool rem = false;
         //   cout << "read " <<  c << endl;
            switch (c) {
                case ')':
                    rem = true;
                    p++;
                    c = '(';
                    break;
                case ']':
                    rem = true;
                    sb++;
                    c = '[';
                    break;
                case '}':
                    rem = true;
                    cc++;
                    c = '{';
                    break;
                case '>':
                    rem = true;
                    a++;
                    c = '<';
                    break;
                default:
                    li.pb(c);
                    break;
            }
            if (rem) {
                //cout << "rem " << c << endl;
                bool valid = true;
                while(li.size()) {
                    char k = li.back();
                    li.pop_back();
//                    cout << k << endl;
                    switch (k) {
                        case ')':
                            p++;
                            break;
                        case '(':
                            p--;
                            break;
                        case ']':
                            sb++;
                            break;
                        case '[':
                            sb--;;
                            break;
                        case '}':
                            cc++;
                            break;
                        case '{':
                            cc--;
                            break;
                        case '<':
                            a--;
                            break;
                        case '>':
                            a++;
                            break;
                        default:
                            cout << "syntax error\n" << k << endl;
                            return 0;
                    break;
                    }
                    if (p<0 || sb < 0 || cc < 0 || a < 0) { valid = false; break;}
                    if (p==0 || sb == 0 || cc ==0 || a == 0) { valid = true; break;}
                }
                if (!valid) {
                    cout << "removed " << cnt << ' ' << c << endl;
                    if (c == '(') res += 3;
                    if (c == '[') res += 57;
                    if (c == '{') res += 1197;
                    if (c == '<') res += 25137;
                    goto endloop;
                }
            }
        }
        vallines.pb(li);
endloop:;
    }
    vi reses;
    for(vc& vl : vallines) {
//        for(char c : vl) cout << c;
 //       cout << endl;
       res = 0;
       FOR(i, vl.size()) {
               char c = vl[vl.size() - i - 1];
                    res*=5;
            switch (c) {
                case '(':
                    res += 1;
                    break;
                case '[':
                    res += 2;
                    break;
                case '{':
                    res += 3;
                    break;
                case '<':
                    res += 4;
                    break;
                default:
                    cout << "syntax error " << c << endl;
                    return 0;
            }
        }
        cout << res << endl;
        reses.pb(res);
    }
    SORT(reses);
    cout << endl;
    cout << reses[reses.size()/2] << endl;
}

