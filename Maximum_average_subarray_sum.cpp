//it shows MLE becuase of using vector int ever  calscaltion and resizing

/*class Solution
 {
public:
double average(vector<double>v)
{
    double sum=0;
    double l=v.size();
    for(int i=0;i<l;i++)
    {
        sum+=v[i];
    }
    double avg=sum/l;
    return avg;
}
 double findMaxAverage(vector<int>&nums,int k)
    {
        vector<double>v;
        for(int i=0;i<k;i++)
        {
            v.push_back(nums[i]);
        }
       double ans=average(v);
       for(int i=k;i<nums.size();i++)
       {
        v.erase(v.begin());
        v.push_back(nums[i]);
        double t=average(v);
        ans=max(ans,t);
       }
       return ans;

    }
};
*/
//AC solution
class Solution
 {
public:
 double findMaxAverage(vector<int>& nums,int k)
    {
        double curr_sum=0;
        double max_sum=INT_MIN;
        for(int i=0;i<k;i++)
        {
            curr_sum+=nums[i];
        }
        max_sum=max(max_sum,curr_sum);
       for(int i=k;i<nums.size();i++)
       {
            curr_sum-=nums[i-k]; //v.erase(v.begin());
            curr_sum+=nums[i];  //v.push_back(nums[i]);
             max_sum=max(max_sum,curr_sum);
       }
       double ans=max_sum/k;
       return ans;
     }
};

