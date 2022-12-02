//cpp program to find 1's and 2's complement of a binary number

#include<iostream>

using namespace std;

int main()
{
    int n, i, j, k, a[10], b[10], c[10];
    cout<<"Enter the number of bits in the binary number: ";
    cin>>n;
    cout<<"Enter the binary number: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"The 1's complement of the binary number is: ";
    for(i=0; i<n; i++)
    {
        if(a[i]==0)
        {
            b[i]=1;
        }
        else
        {
            b[i]=0;
        }
    }
    for(i=0; i<n; i++)
    {
        cout<<b[i];
    }
    cout<<endl;
    cout<<"The 2's complement of the binary number is: ";
    for(i=n-1; i>=0; i--)
    {
        if(a[i]==0)
        {
            c[i]=1;
            break;
        }
        else
        {
            c[i]=0;
        }
    }
    for(j=i-1; j>=0; j--)
    {
        if(a[j]==0)
        {
            c[j]=0;
        }
        else
        {
            c[j]=1;
        }
    }
    for(k=0; k<n; k++)
    {
        cout<<c[k];
    }
    cout<<endl;
    return 0;
}
