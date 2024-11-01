class Solution {
public:
bool isgood(string s)
{
    map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        if(mp[s[i]]==0)
        {
            mp[s[i]]++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
    int countGoodSubstrings(string s)
    {
        int ans=0;
        int l=s.size();
        string t;
        for(int i=0;i<l;i++)
        {
          t.push_back(s[i]) ;
          if(t.size() == 3){
            if(isgood(t))ans++ ;
            t.erase(t.begin()) ;
          }

        }

       return ans;
    }
};
