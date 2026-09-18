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
    vector<int> w(n);
    for(int i=0;i<n;i++) cin>>w[i];
    string s;
    cin>>s; 
    priority_queue<pair<int,int>> pq1;  // max heap(extro)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2; //min heap(intro)
    for(int i=0;i<n;i++) pq2.push({w[i],i});
    for(int i=0;i<2*n;i++){
        int x = s[i]-'0';
        if(x==0){
            auto it = pq2.top();
            pq2.pop();
            pq1.push(it);
            cout<<it.second+1<<" ";
        }
        else{
            auto it = pq1.top();
            pq1.pop();
            cout<<it.second+1<<" ";
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}