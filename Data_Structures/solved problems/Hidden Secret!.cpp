#include<bits/stdc++.h>
using namespace std;
int ara[26],ara1[26];
int main()
{
    int i,j,k=0,l,m,n,t;
    cin>>t;
    getchar();
    for(i=1; i<=t; i++)
    {
        for(j=0; j<26; j++)
        {
            ara[j]=0;
            ara1[j]=0;
        }
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        //cout<<s1<<endl<<s2<<endl;
        for(j=0; j<s1.size(); j++)
        {
            if((s1[j]>=65 && s1[j]<=90))
                s1[j]=tolower(s1[j]);
            if(s1[j]!=' ')
                ara[s1[j]-97]++;
        }
        for(j=0; j<s2.size(); j++)
        {
            if(s2[j]>=65 && s2[j]<=90)
                s2[j]=tolower(s2[j]);
            if(s2[j]!=' ')
                ara1[s2[j]-97]++;
        }
        for(j=0; j<26; j++)
        {
            if(ara[j]!=ara1[j])
            {
                cout<<"Case "<<i<<": No"<<endl;
                k++;
                break;
            }
        }
        if(k==0)
        {
            cout<<"Case "<<i<<": Yes"<<endl;
        }
        k=0;
       // cout<<s1<<endl<<s2<<endl;
    }
    return 0;
}

