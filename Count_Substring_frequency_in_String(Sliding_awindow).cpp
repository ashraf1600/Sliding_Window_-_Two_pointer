#include<bits/stdc++.h>
using namespace std;
int find_substring(string s,string t)
{
	int ans=0;
	int l=t.size();
	string s1;
	for(int i=0;i<l;i++)
	{
		s1+=s[i];
	}
	if(s1==t) ans++;//if matched the substring t with the first three charracter of the main string s
	for(int i=l;i<s.size();i++)//then iterate from the next index(l=t.size())
	{
		 s1+=s[i];
		 s1.erase(s1.begin());
		 if(s1==t) ans++;

	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	string t;
	cin>>t;
	int ans=find_substring(s,t);
	cout<<ans<<endl;
}
