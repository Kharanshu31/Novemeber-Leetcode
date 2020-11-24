class Solution {
public:
    int calculate(string s) {
        char sign='+';
        int ans=0,temp=0;
        int med=0;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                temp=0;
                while(i<s.length() && isdigit(s[i]))
                {
                    temp=temp*10+(int)(s[i]-'0');
                    i++;
                }
                if(sign=='+')
                {
                    ans+=med;
                    med=temp;
                }
                else if(sign=='-')
                {
                    ans+=med;
                    med=temp*(-1);
                }
                else if(sign=='*')
                {
                    med*=temp;
                }
                else
                {
                    med/=temp;
                }
                i--;
            } 
            else if(s[i]!=' ')
                sign=s[i];
            //cout<<"sign : "<<sign<<" med : "<<med<<"\n";
        }
        ans+=med;
        return ans;
    }
};
