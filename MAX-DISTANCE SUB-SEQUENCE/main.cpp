#include <iostream>
#include <algorithm>
using namespace std;
int a[100],tgian;
int n,c;
int res=0;

void backtracking(int i,int k,int Max)
{
    if(k==c)
    {
        if(Max>res) res=Max;
    }
    else
    {
       int lo = i, hi = n-1,mid,ans;
       int tgian1 = tgian + a[i];
        while (lo <= hi) {
            mid = (hi+lo)/2;
            if (a[mid] <= tgian1)
            {   ans=mid;
                lo = mid + 1;
            }
            else hi = mid-1;
        }
        cout<<ans<<endl;
        for(int t=ans;t>=i+1;t--)
        {
                int Max1=Max;
                Max=min(Max,a[t]-a[i]);
                k++;
                backtracking(t,k,Max);
                k--;
                Max = Max1;
        }


    }
}
int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a+0,a+0+n);
    tgian = (a[n-1]-a[0])/(c-2);
    backtracking(0,2,tgian);
    cout<<res;

}
