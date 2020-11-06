class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=1e6+1;
        int ans=1;
        while(l<r)
        {
            int mid=(l+r)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                sum+=nums[i]/mid;
                if(nums[i]%mid)
                    sum++;
            }

            //cout<<" sum : "<<sum<<"  mid : "<<mid<<"\n";
            if(sum>threshold)
            {
                l=mid+1;
                ans=max(ans,mid+1);
            }
            else
            {
                r=mid;
            }
        }

        return ans;
    }
};
