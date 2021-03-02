//ekta string pattern onno ekta string text er moddhe ache kina ta ber kora holo kmp er kaj
//kmp er compexity O(n+m).....n=size of text string & m=size of pattern string
//tutorial from youtube chennel loveextendscode

#include<bits/stdc++.h>
using namespace std;

vector<int> create_lps_array(string pattern)
{
    vector<int>lps(pattern.size());//size of lps vector will be same as pattern string;
    int index=0;
    for(int i=1; i<pattern.size();  )
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
    //bool found=false;
    vector<int>lps=create_lps_array(pattern);
    int i=0,j=0,ans=0;  //i will be use for text & j will be use for pattern;
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
        ans=j;
    }
    return ans;
}

int main()
{
    int q,t;
    cin>>t;
    getchar();
    for(q=1; q<=t; q++)
    {
        string pattern,text;
        getline(cin,text);
        pattern=text;
        //cout<<pattern<<endl;
        reverse(pattern.begin(),pattern.end());
        //cout<<pattern<<endl;
        int sz=text.size();
        int ans=kmp(pattern,text);
        printf("Case %d: %d\n",q,sz+(sz-ans));
    }
    return 0;
}

