class Solution {
public:
    int perform(int x,int y, char op){
        if(op == '+')return x+y;
        if(op == '-')return x-y;
        if(op == '*')return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        bool isNumber=1;
        for(int i=0;i<expression.length();i++){
            if(!isdigit(expression[i])){ //if not digit then it's an operator
                isNumber=0;
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto& x:left){
                    for(auto& y:right){
                        int value=perform(x,y,expression[i]);
                        res.push_back(value);
                    }
                }
            }
        }
        if(isNumber==1){
            res.push_back(stoi(expression));
        }
        return res;
        
    }
};