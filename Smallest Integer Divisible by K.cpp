class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0)
            return -1;
        long long ans=1;
        map<long long,long long>m;
        long long num=1;
        while(m.find(num%k)==m.end())
        {
            m[num%k]++;
            //cout<<" n : "<<num<<"\n";
            if(num%k==0)
                return ans;
            ans++;
            num=num*10+1;
            num%=k;
        }
        return -1;
    }
};
