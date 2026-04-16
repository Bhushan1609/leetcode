#include <bits/stdc++.h>
#include <map>
#include <chrono>
#include <random>
#define SPEEDUP cin.tie(NULL)->sync_with_stdio(false)

using namespace std;
using namespace std::chrono;
using ll=long long;
using lld=long double;
using u32=unsigned int;
using u64=unsigned long long;

template <class T,class P>
using pi=pair<T,P>;

#define INT(...)int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...)ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...)string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...)char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...)long double __VA_ARGS__; IN(__VA_ARGS__)

void read(int &a){cin>>a;}
void read(long long &a){cin>>a;}
void read(char &a){cin>>a;}
void read(double &a){cin>>a;}
void read(long double &a){cin>>a;}
void read(string &a){cin>>a;}

template<class T,class S>void read(pair<T,S>&p){read(p.first),read(p.second);}
template<class T>void read(vector<T>&a){for(auto &i:a)read(i);}
template <class T>void read(T &a){cin >> a;}
void IN(){}
template<class Head,class... Tail>void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template<typename T,typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A){os<<A.fi<<" "<<A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os,const vector<T>&A) {
    for(size_t i=0;i<A.size();i++){
        if(i) os<<" ";
        os << A[i];
    }
    return os;
}
void print(){cout << '\n';cout.flush();}
template <class Head,class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout<<head;
    if(sizeof...(Tail)) cout<<" ";
    print(std::forward<Tail>(tail)...);
}

#define dbg(x...){cout<< "("<< #x<<")"<< " = (";Print(x);} 
template<typename T1>void Print(T1 t1) {cout<< t1 << " )" <<endl;} 
template<typename T1,typename... T2>
void Print(T1 t1, T2... t2) {cout<<t1<<" , ";Print(t2...);}

void YES(bool t=1) {print(t?"YES":"NO");}
void NO(bool t=1) {YES(!t);}
void Yes(bool t=1) {print(t?"Yes":"No");}
void No(bool t=1) {Yes(!t);}
void yes(bool t=1) {print(t?"yes":"no");}
void no(bool t=1) {yes(!t);}

#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define pb push_back
#define popb pop_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v),(ll)0)

template <class T>
using vd=vector<T>;
template <class T>
using vdd=vector<vd<T>>;
template <class T>
using vddd=vector<vdd<T>>;
template <class T>
using vdddd=vector<vddd<T>>;
template <class T>
using vddddd=vector<vdddd<T>>;
template <class T>
using q=queue<T>;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-const-variable"
const int mod = 1e9 + 7; 
vd<pi<ll,ll>>gridMoves = {{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
vd<ll>FV(1E6+1),fact(1E6+1),ifact(1E6+1);
#pragma GCC diagnostic pop

/*MaxHeap*/
template <class T>
using pq=priority_queue<T>;
/*MinHeap*/
template <class T>
using pqg=priority_queue<T,vector<T>, greater<T>>;

/*FOR*/
#define FOR1(a) for(ll _=0;_<ll(a);++_)
#define FOR2(i,a) for(ll i=0;i<ll(a);++i)
#define FOR3(i,a,b) for(ll i=a;i<ll(b);++i)
#define FOR4(i,a,b,c) for (ll i =a;i<ll(b);i+=(c))
/*FOR_R*/
#define FOR1_R(a) for (ll i =(a)-1;i>=ll(0);--i)
#define FOR2_R(i,a) for (ll i=(a)-1;i>=ll(0);--i)
#define FOR3_R(i,a,b) for(ll i=(b)-1;i>=ll(a);--i)

// Reference : https://cp-algorithms.com/algebra/module-inverse.html#definition
ll gcd(ll a,ll b){
    if(b>a){
        return gcd(b,a);
    }
    if(b == 0){
        return a;
    } 
    return gcd(b,a % b);
}
// A^B % m
ll expo(ll a, ll b, ll m){
    ll res = 1;
    while(b>0){
        if(b&1) res = (res * a) % m; 
        a=(a*a) % m;
        b=b>>1;
    } 
    return res;
} 
//Pass an array of size 3
void extendgcd(ll a, ll b, ll*v){
    if (b == 0){
        v[0]=1;
        v[1]=0;
        v[2]=a;
        return ;
    } 
    extendgcd(b, a % b, v); 
    ll x = v[1]; v[1] = v[0] - v[1] * (a / b); 
    v[0] = x; 
    return;
} 
//FOR non-prime b, Using extended_euclidean
ll mminv(ll a,ll b){
    ll arr[3]; 
    extendgcd(a, b, arr); 
    return arr[0];
} 
ll mminvprime(ll a,ll b){
    return expo(a, b - 2, b);
}
ll nCr(ll n,ll r,ll m){
    if (r>n || r<0) return 0;
    ll val1 = fact[n]; 
    ll val2 = ifact[n - r]; 
    ll val3 = ifact[r]; 
    return (((val1 * val2) % m) * val3) % m;
}
void combination(ll n,ll m){
    fact[0] = ifact[0] = 1;
    FOR(i,1,n+1) fact[i] = (fact[i-1] * i) % m;

    ifact[n]=expo(fact[n],m-2,m);
    FOR_R(i,1,n) ifact[i]=( ifact[i+1] * (i+1) ) % m;
    return ;
}
vd<ll>sieve(int n){
    int* arr=new int[n + 1]();
    vd<ll>primes; 
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0){
            primes.eb(i);
            for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
        } 
    return primes;
}
ll mod_add(ll a,ll b,ll m){
    a = a % m; 
    b = b % m; 
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a,ll b,ll m){
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m){
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
//only for prime m
ll mod_div(ll a, ll b, ll m){
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
}  

/*Declare 2d/3d(type,name,size,size1,size2,....)*/
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__))))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

/*Read 1d/2d(type,name,size,size1)*/
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)

bool check1(pi<int,int>&a,pi<int,int>&b){
    if(a.fi==b.fi){
        return a.se<=b.se;
    }
    return a.fi<b.fi;
}

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vd<int>ans;
        unordered_map<int,vd<int>>mapp;
        FOR(i,len(nums))
            mapp[nums[i]].push_back((int)i);
        FOR(i,len(queries)){
            int index=queries[i];
            int ele=nums[index];
            auto &indexes=mapp[ele];
            if(len(indexes)==1)
                ans.eb(-1);
            else{
                int indexofele=lower_bound(all(indexes),index)-indexes.begin();
                int n=len(nums);
                int m=len(indexes);
                int last=(indexofele-1+m)%m;
                int next=(indexofele+1)%m;
                int prevdist=(index-indexes[last]+n)%n;
                int nextdist=(indexes[next]-index+n)%n;
                ans.eb(min(prevdist,nextdist));
            }
        }
        return ans;
    }
};

/*
Intially free Variables are assign to 0
change if needed
fill(all(FV),-1);

Interactor test=Interactor(n,true); 

CHECK FOR   
    1)Whenever use SUM check overflow of data_type :)
    2)Using free variables make sure to reassign in multiple test cases
    3)check 1 test case issue
*/
#ifdef LOCAL
void solve() {
    Solution Obj;
    vd<int>nums={5,20,12,14,12,17,13,7,7,5,20,5,5,5,12,19,6};
    vd<int>queries={3,14,2,0,8,12,16,6,7,11,4,10};
    return print(Obj.solveQueries(nums,queries));
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr<<"Time: "<<duration.count()/1000<<" ms"<<endl;
    return 0;
}
#endif