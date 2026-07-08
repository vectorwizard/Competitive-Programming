#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n;
    vector<int> a;
    vector<int> prefixsumevens;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    vector<int> odds;
    vector<int> evens;
    for(int i=0;i<n;i++){
        if(a[i]%2==0) evens.push_back(a[i]);
        else odds.push_back(a[i]);
    }
    sort(odds.rbegin(),odds.rend());
    sort(evens.rbegin(),evens.rend());
    int noofevens = evens.size();
    vector<ll> prefixevens(noofevens+1,0);
    for(int i=1;i<=noofevens;i++){
        prefixevens[i] = prefixevens[i-1]+evens[i-1];
    }
    for(int k=1;k<=n;k++){
        if(odds.empty()){
            cout<<"0 ";
            continue;
        }
        int take_evens = min((int)evens.size(),k-1);
        int take_odds = k - take_evens;
        if(take_odds%2==0){
            take_evens--;
            take_odds++;
        }
        if(take_odds>odds.size() || take_evens<0){
            cout<<"0 ";
        }
        else{
            ll score = prefixevens[take_evens] + odds[0];
            cout<<score<<" ";
        }
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