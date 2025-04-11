class Solution {
public:
    bool isSymmetricIntegers(int n) {
        string str = to_string(n);
        if(str.length() % 2 != 0) return false;
        int i = 0, j = str.length()-1;
        int left_sum = 0, right_sum = 0;
        while(i <= j) {
            left_sum += str[i]-'0';
            right_sum += str[j]-'0';
            i++;
            j--;
        }
        if(left_sum == right_sum) return true;
        return false;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        while(low <= high) {
            if(isSymmetricIntegers(low)) {
                count++;
            }
            low++;
        }
        return count;
    }
};