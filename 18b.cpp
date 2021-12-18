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
#define sw string_view

//auto toDec = bind(static_cast<_int(*)(const string&, size_t*, _int)>(stoi), placeholders::_1,(size_t*) nullptr, 2);

#define vc vector<char>
#define vvc vector<vector<char>>
unordered_map<string, vector<string>> adj;
int res = 0;
struct snum {
    int val = -1;
    snum *l = nullptr;
    snum *r = nullptr;
    snum *p = nullptr;
};

pair<int, snum*> parse(sw s, snum* p) {
//    cout << "start parsing: " << s << endl;
    snum* snu = new(snum);
    snum& sn = *snu;
    sn.p = p;
    int cnt = 0;
    if (s[cnt] == '[') {
        cnt++;
        auto [l, s1] = parse(s.substr(cnt), snu);
       // printf(" for l\n");
        sn.l = s1;
        cnt += l;
        //printf("%c\n", s[cnt]);
        fflush(stdout);
        assert(s[cnt] == ',');
        cnt++;
        auto [r, s0] = parse(s.substr(cnt), snu);
        cnt += r;
  //      printf(" for r\n");
        // closing ]
        cnt++;
        sn.r = s0;
    } else {
        sn.val = s[cnt] - '0';
        //printf("parsed number: %lld", sn.val);
        // assume number are always 1 char
        cnt++;
    }
    return {cnt, snu};
}

void print(snum* snu) {
    if (!snu) return;
    if (snu->val != -1) { printf("%lld", snu->val);}
    if (snu->l) {printf("[");print(snu->l);}
    if (snu->r) {printf(",");print(snu->r);printf("]");}
}

void addl(snum* n, int i) {
  //  printf("addl: i: %lld n: ", i); print(n); printf("\n");
    while (n->p) {
        if (n != n->p->l) {n = n->p->l; break;}
        else n = n->p;
    }
    if (!n->p) return;
    while(n->val == -1) {
        n = n->r;
    }
    n->val += i;
}

void addr(snum* n, int i) {
    while (n->p) {
        if (n != n->p->r) {n = n->p->r; break;}
        else n = n->p;
    }
    if (!n->p) return;
    while(n->val == -1) {
        n = n->l;
    }
    n->val += i;
}

bool explode(snum* s, int d) {
    if(d == 4 && s->val == -1) {
//        printf("exploding: [%lld, %lld]\n", s->l->val, s->r->val);
 //       fflush(stdout);
        addl(s, s->l->val);
        addr(s, s->r->val);
        free(s->l);
        free(s->r);
        s->l = nullptr;
        s->r = nullptr;
        s->val = 0;
        return true;
    }
    int b = false;
    if(s->l) b = explode(s->l, d+1);
    if(!b && s->r) b |= explode(s->r, d+1);
    return b;
}

bool split(snum* s) {
    if(s->val > 9) {
    //    printf("spliting: s:"); print(s); printf("\n"); fflush(stdout);
        snum* l = new(snum);
        snum* r = new(snum);
        l->p = s;
        l->val =  s->val / 2;
        s->l = l;
        r->p = s;
        r->val =  (s->val +1) / 2;
        s->r = r;
        s->val = -1;
    //    printf("splitted into: [%lld, %lld]\n", s->l->val, s->r->val);
        return true;
    }
    int b = false;
    if(s->l) b = split(s->l);
    if(!b && s->r) b |= split(s->r);
    return b;
}

snum* add(snum* l, snum* r) {
    if (!l) return r;
    if (!r) return l;
    snum* snu = new(snum);
    snu->l = l;
    l->p = snu;
    snu->r = r;
    r->p = snu;
  //  printf("merged: ");print(snu); printf("\n"); fflush(stdout);
    while(explode(snu, 0) || split(snu));// {print(snu); printf("\n"); fflush(stdout);}
  //  printf("normalized: ");print(snu); printf("\n");
    return snu;
}

int magnitude(snum* n) {
    if (n->val != -1) {
        return n->val;
    }
    return magnitude(n->l) *3 + magnitude(n->r) *2;
}

_int main(void) {
    string s;
    int res = 0;
    vector<string> as;
    while (cin >> s) {
        as.pb(s);
    }
    FOR(i, as.size()) FOR(j, as.size()) {
        if (i==j) continue;
        auto [_, a] = parse(as[i], nullptr);
        auto [__, b] = parse(as[j], nullptr);
        res = max(magnitude(add(a,b)), res);
    }
    printf("%lld\n", res);
}



