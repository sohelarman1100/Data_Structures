#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n,t,p=0,q=0,a;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n>>m;
        deque <int> de;
        cout<<"Case "<<i<<":"<<endl;
        for(j=1; j<=m; j++)
        {
            string s;
            cin>>s;
            if(s=="pushLeft" && de.size()<n)
            {
                cin>>a;
                de.push_front(a);
                cout<<"Pushed in left: "<<a<<endl;
            }
            else if(s=="pushRight" && de.size()<n)
            {
                cin>>a;
                de.push_back(a);
                cout<<"Pushed in right: "<<a<<endl;
            }
            else if((de.size()>=n && s=="pushLeft") || (s.size()>=n && s=="pushRight"))
            {
                cin>>a;
                cout<<"The queue is full"<<endl;
            }
            if(s=="popLeft" && de.size()>0)
            {
                cout<<"Popped from left: "<<de.front()<<endl;
                de.pop_front();
            }
            else if(s=="popRight" && de.size()>0)
            {
                cout<<"Popped from right: "<<de.back()<<endl;
                de.pop_back();
            }
            else if((de.size()==0 && s=="popRight") || (de.size()==0 && s=="popLeft"))
                cout<<"The queue is empty"<<endl;
        }
    }
}

