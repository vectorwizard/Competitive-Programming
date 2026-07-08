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
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        if(i%2==0) mpp[a[i]] = 0;
        else mpp[a[i]] = 1;
    }
    sort(a.begin(),a.end());
    int first = mpp[a[0]];
    for(int i=1;i<n;i++){
        if(i%2==0){
            if(mpp[a[i]]!=first){
                cout<<"No"<<endl;
                return;
            }
        }
        else{
            if(mpp[a[i]]!=1-first){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}