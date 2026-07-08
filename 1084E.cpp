#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 676767677;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int siz = 1e6 + 1;  
vector<bool> primes;
void sieve(){
    for(int i=2;i<=siz;i++){
        if(primes[i]==false) continue;
        for(int j = i*i;j<=siz;j=j+i){
            primes[j] = false;
        }
    }
}
bool is_poss(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            if(primes[i]==true && primes[x/i]==true) return true;
        }
    }
    return false;
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    bool fl = false;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            fl = true;
            break;
        }
    }
    if(fl==false){
        cout<<"Bob"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]==1 || primes[a[i]]==true) continue;
        if(is_poss(a[i])){
            cout<<"Alice"<<endl;
            return;
        }
    }

}

int main() {
    fastio();
    ll t;
    cin>>t;
    primes.assign(1e6+1,true);
    primes[0] = false;
    primes[1] = false;
    sieve();
    while (t--) solve();
    return 0;
}