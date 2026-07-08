#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> spf;
void sieve(int maxi){
    for(int i=0;i<=maxi;i++){
        spf[i] = i;
    }
    spf[0] = 0;
    spf[1] = 1;
    for(int i=2;i*i<=maxi;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=maxi;j+=i){
                spf[j] = i; 
            }
        }
    }
}
map<int,int> factors;
void factorization(int n){
    while(n>1){
        factors[spf[n]]++;
        n = n/spf[n];
    }
}
void solve() {
    int n;
    cin>>n;
    factors.clear();
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int maxi = *max_element(a.begin(),a.end());
    for(int i=0;i<n;i++){
        factorization(a[i]);
    }
    for(auto it:factors){
        if(it.second%n!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    spf.assign(1e6+1,0);
    sieve(1e6+1);
    while (t--) solve();
    return 0;
}

