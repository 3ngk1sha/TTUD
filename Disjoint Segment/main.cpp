#include <iostream>

using namespace std;
struct mang{
    int one;
    int two;
};
mang Array[120000];
void sx(int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        if(Array[i].two > Array[j].two)
        {
            mang Tgian;
            Tgian       =   Array[i];
            Array[i]    =   Array[j];
            Array[j]    =   Tgian;
        }
    }
}
int main()
{
    int n;
   cin >> n;
   for(int i=0;i<n;i++)
    cin >> Array[i].one >> Array[i].two;
    sx(n);
    int dem=1;
    mang Check=Array[0];
    for(int i=1;i<n;i++)
    {
        if(Check.two<Array[i].one)
        {
            dem++;
            Check=Array[i];
        }

    }
    cout<<dem;
}
