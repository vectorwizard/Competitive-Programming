#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    map<int,pair<int,int>> mpp;
    vector<int> vec = {4,8,15,16,23,42};
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            mpp[vec[i]*vec[j]] = {vec[i],vec[j]};
        }
    }
    vector<int> ans(6);
    cout<<"?"<<" "<<1<<" "<<2<<endl;
    int x;
    cin>>x;
    int a = mpp[x].first;
    int b = mpp[x].second;
    cout<<"?"<<" "<<2<<" "<<3<<endl;
    cin>>x;
    int c = mpp[x].first;
    int d = mpp[x].second;
    if(a==c){
        ans[0] = b;
        ans[1] = a;
        ans[2] = d;
    }
    else if(a==d){
        ans[0] = b;
        ans[1] = a;
        ans[2] = c;
    }
    else if(b==c){
        ans[0] = a;
        ans[1] = b;
        ans[2] = d;
    }
    else{
        ans[0] = a;
        ans[1] = b;
        ans[2] = c;
    }
    cout<<"?"<<" "<<4<<" "<<5<<endl;
    cin>>x;
    a = mpp[x].first;
    b = mpp[x].second;
    cout<<"?"<<" "<<5<<" "<<6<<endl;
    cin>>x;
    c = mpp[x].first;
    d = mpp[x].second;
    if(a==c){
        ans[3] = b;
        ans[4] = a;
        ans[5] = d;
    }
    else if(a==d){
        ans[3] = b;
        ans[4] = a;
        ans[5] = c;
    }
    else if(b==c){
        ans[3] = a;
        ans[4] = b;
        ans[5] = d;
    }
    else{
        ans[3] = a;
        ans[4] = b;
        ans[5] = c;
    }
    cout<<"!"<<" ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
