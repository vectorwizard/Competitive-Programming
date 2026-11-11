#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Rect{
    ll x1,y1,x2,y2;
    ll area(){
        if(x1>x2 || y1>y2) return 0;
        return (x2-x1) * (y2-y1);
    }
};

Rect intersect(Rect &a, Rect &b){
    Rect ans;
    ans.x1 = max(a.x1, b.x1);
    ans.x2 = min(a.x2, b.x2);
    ans.y1 = max(a.y1, b.y1);
    ans.y2 = min(a.y2, b.y2);
    if(ans.x1>ans.x2) return {0,0,0,0};
    else return ans;
}

void solve() {
    Rect w,b1,b2;
    cin>>w.x1>>w.y1>>w.x2>>w.y2;
    cin>>b1.x1>>b1.y1>>b1.x2>>b1.y2;
    cin>>b2.x1>>b2.y1>>b2.x2>>b2.y2;
    Rect wb1 = intersect(w,b1);
    Rect wb2 = intersect(w,b2);
    Rect wb1b2 = intersect(wb1,b2);
    ll area = wb1.area() + wb2.area() - wb1b2.area();
    if(area<w.area()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}