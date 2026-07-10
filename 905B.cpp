#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,int> mpp;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    bool odd = (((n-k)%2)==1);
    if(odd){
        int cnt = 0;
        for(auto it:mpp){
            if(it.second%2==1) cnt++;
        }
        if((cnt-1)>k){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    else{
        int cnt = 0;
        for(auto it:mpp){
            if(it.second%2==1) cnt++;
        }
        if((cnt)>k){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
