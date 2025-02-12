#include <bits/stdc++.h>
using namespace std;
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define clr(x) memset(x, 0, sizeof(x))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) FOR(i, 0, j, 1)
#define rrep(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef long int li;
typedef long double ld;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int  ulli;
typedef pair<int, int> pii;
typedef pair<lli, lli>	pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli>	vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef unordered_map<int,int> umpii;
typedef unordered_set<int> useti;
typedef unordered_multiset<int> umseti;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())
            return "0";
        stack<char> stk;
        stack<char> tmp;
        string ret="";
        rrep(i,num.length()-1)
            stk.push(num[i]);
        rep(i,k){
            if(stk.empty())
                break;
            tmp.push(stk.top());
            stk.pop();
            while(!stk.empty() && stk.top()>=tmp.top()){
                tmp.push(stk.top());
                stk.pop();
            }
            tmp.pop();//Remove the expected element.
            while(!tmp.empty()){
                stk.push(tmp.top());
                tmp.pop();
            }
            while(!stk.empty() && stk.top()=='0')//Remove Leading Zeroes
                stk.pop();
        }
        if(stk.empty())
            return "0";
        while(!stk.empty()){
            ret+=stk.top();
            stk.pop();
        }
        return ret;
    }
};