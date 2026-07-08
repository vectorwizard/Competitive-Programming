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
    vector<int> tw_not_th;
    vector<int> th_not_tw;
    vector<int> both;
    vector<int> no;
    for(int i=0;i<n;i++){
        if(a[i]%2==0 && a[i]%3==0){
            both.push_back(a[i]);
        }
        else if(a[i]%2==0){
            tw_not_th.push_back(a[i]);
        }
        else if(a[i]%3==0){
            th_not_tw.push_back(a[i]);
        }
        else no.push_back(a[i]);
    }
    vector<int> ans;
    for(int i=0; i<tw_not_th.size(); i++){
        ans.push_back(tw_not_th[i]);
    }
    for(int i=0; i<no.size(); i++){
        ans.push_back(no[i]);
    }
    for(int i=0; i<th_not_tw.size(); i++){
        ans.push_back(th_not_tw[i]);
    }
    for(int i=0; i<both.size(); i++){
        ans.push_back(both[i]);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
