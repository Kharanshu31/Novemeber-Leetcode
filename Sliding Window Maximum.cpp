class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==0)
            return nums;
        int n=nums.size();
        vector<int>ar;
        priority_queue<pair<int,int>>pq;
        //priority_queue<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && pq.top().second<=i-k)
                pq.pop();
            pq.push({nums[i],i});
            //temp=pq;
            //while(!temp.empty())
            //{
            //    cout<<temp.top().first<<"  "<<temp.top().second<<"\n";
            //    temp.pop();
            //}
            //cout<<"\n\n";
            if(i>=k-1)
                ar.push_back(pq.top().first);
        }
        
        return ar;
    }
};
