#include<iostream>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100][100];
int dp[100][100];
int n,m;
struct point{
int x,y;
};
point s;
stack<point>S;
void init(){
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
cin>>a[i][j];
for(int i=1;i<=n;i++)
    dp[i][0]=0;
for(int j=1;j<=m;j++)
    dp[0][j]=0;
}

void solve(){

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i][j-1]);
}
void put(int n,int m){
    s.x=n;
    s.y=m;
    S.push(s);
    if(n==1&&m==1)return;
    else if(n==1&&m>1){
    put(n,m-1);
    }
    else if(m==1&&n>1){
        put(n-1,m);
    }
    else {
        if(dp[n-1][m]>dp[n][m-1])
            put(n-1,m);
        else put(n,m-1);
    }
}
void print(){
cout<<dp[n][m]<<endl;
while(!S.empty()){
        point a=S.top();
    printf("(%d,%d)\n",a.x,a.y);
    S.pop();
}
}
int main()
{
    while(cin>>n>>m){
        init();
        solve();
        put(n,m);
        print();

    }
    return 0;
}
