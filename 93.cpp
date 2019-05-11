class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
       vector<string> res;
       restore(s,4,"",res);
       return res;
    }
    void restore(string s,int k,string str,vector<string>& res)
    {
        if(k==0){
            if (s.empty()) res.push_back(str);
        }
        else{
            for(int i=1;i<=3;i++)
            {
                if(s.size()>=i&&isvalid(s.substr(0,i)))
                {
                    restore(s.substr(i),k-1,str+s.substr(0,i)+(k==1?"":"."),res);
                }
            }
        }
    }
    bool isvalid(string str)
    {
        if((str.size()>1&&str[0]=='0')||stoi(str)>255||stoi(str)<0){
            return false;
        }
        return true;
    }
};
