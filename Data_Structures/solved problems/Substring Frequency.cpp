
#include<bits/stdc++.h>
using namespace std;

vector<int> create_lps_array(string pattern)
{
    vector<int>lps(pattern.size());///size of lps vector will be same as pattern string;
    int index=0;
    for(int i=1; i<=pattern.size();  )
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            ++index;
            ++i;
        }
        else
        {
            if(index!=0)
                index=lps[index-1];
            else
            {
                lps[i]=index;
                ++i;
            }
        }
    }
    return lps;
}

int kmp(string pattern, string text)
{
    int cnt=0;
    //bool found=false;
    vector<int>lps=create_lps_array(pattern);
    int i=0,j=0;  ///i will be use for text & j will be use for pattern;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            ++i;
            j++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
                ++i;
        }
        if(j==pattern.size())
        {
            j=lps[j-1];
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    getchar();
    for(i=1; i<=t; i++)
    {
        string pattern,text;
        getline(cin,text);
        getline(cin,pattern);
        int k=kmp(pattern,text);
        printf("Case %d: %d\n",i,k);
    }
    return 0;
}

