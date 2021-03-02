///KMP

///ekta string pattern onno ekta string text er moddhe ache kina ta ber kora holo kmp er kaj
///kmp er compexity O(n+m).....n=size of text string & m=size of pattern string
///tutorial from youtube chennel loveextendscode

#include<bits/stdc++.h>
using namespace std;

vector<int> create_lps_array(string pattern)
{
    vector<int>lps(pattern.size());///size of lps vector will be same as pattern string;
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

void kmp(string pattern, string text)
{
    bool found=false;
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
        if(j==pattern.size())///jokhoni amra pattern er last index e powchate parbo tokhon buja jabe...
///pattern string text er modde sub string hisebe ache karon pattern....
///er sob char text er kono ekta ongser sathe millei pattern er last...
///index e powchano jabe mane j=pattern.size()-1 hobe ar j er ei maner jonno pattern er last char text..
///je ongser sathe match kore oi ongser last char er soman hobe then first if condition e dukbe ar i and j
///er man 1 kore barabe ar tokhon j er man pattern er size er soman hoye jabe tar por ei if condition..
///e asbe tai j==pattern.size()-1 na diye j==pattern.size() deya hoyeche|||
        {
            cout<<"found"<<endl;
            found=true;
            cout<<"index :"<<i-pattern.size()<<endl;///ekhane text er koto num index theke pattern er moto..
            ///sub string ache ta ekhane index num 0 theke hiseb kora hoyeche|||
            j=lps[j-1];///while loop text.size()-1 porjonto cholbe tai j er man update kora lagbe ar koto..
            ///pattern er moto koto gulo sub string ache ta count korte chaile ekti variable cnt niye..
            ///cnt++ korlei hobe||
        }
    }
    if(found==false)
        cout<<"not found"<<endl;
}

int main()
{
    string pattern,text;
    getline(cin,text);
    getline(cin,pattern);
    kmp(pattern,text);
    return 0;
}
