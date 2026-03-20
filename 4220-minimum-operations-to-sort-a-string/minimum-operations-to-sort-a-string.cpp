class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string comp = s;
        
        sort(comp.begin(),comp.end());
        if(comp==s) return 0;

        if(n==2) return -1;
        
        int mx = -1; int mn = 1000;
        for(auto x:s){
            mx = max(mx,(int)x);
            mn = min(mn,(int)x);
        }

        //if first character is max and last character is mn then 3
        if((int)s[0]==mx && (int)s[n-1]==mn) 
        {
            for(int i=1;i<n-1;i++){
                if((int)s[i]==mn || (int)s[i]==mx) return 2;
            }
            return 3;
        }
        
        //if first is min or last is max
        if((int)s[0]==mn || (int)s[n-1]==mx) return 1;
        
        //if first is max
        if((int)s[0]==mx) return 2;

        //if only last is mn
        if((int)s[n-1]==mn) return 2;


        return 2;
    }
    
};