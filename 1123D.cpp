#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        if(i%2==0){
            vec.push_back({a[i],i%2});
        }
        else vec.push_back({a[i],i%2});
    }
    sort(vec.begin(),vec.end());
    if(n%2==0){
        for(int i=0;i<n;i+=2){
            if(vec[i].second==vec[i+1].second){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    else{
        if(vec[0].second==1){
            cout<<"NO"<<endl;
            return;
        }
        for(int i=1;i<n;i+=2){
            if(vec[i].second==vec[i+1].second){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
