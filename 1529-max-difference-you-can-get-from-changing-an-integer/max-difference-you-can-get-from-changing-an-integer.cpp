class Solution 
{
public:
    int maxDiff(int num) 
    {
        // Step 1: Convert the number to string
        string s = to_string(num);

        // Step 2: Make two versions — one for max, one for min
        string max_s = s;
        string min_s = s;

        // Step 3: Make the max version
        // Find the first digit that is not 9
        for (char c : s) 
        {
            if (c != '9') 
            {
                // Replace all occurrences of this digit with '9'
                for (char &ch : max_s) 
                {
                    if (ch == c)
                        ch = '9';
                }
                break; // only one transformation allowed
            }
        }

        // Step 4: Make the min version
        if (s[0] != '1') 
        {
            // If the first digit isn't 1, replace all of it with 1
            char to_replace = s[0];
            for (char &ch : min_s) 
            {
                if (ch == to_replace)
                {
                    ch = '1';
                }
            }
        } 
        else 
        {
            // If first digit is 1, find a digit ≠ 0 or 1 to replace with 0
            for (int i = 1; i < s.size(); i++) 
            {
                if (s[i] != '0' && s[i] != '1') 
                {
                    char to_replace = s[i];
                    for (char &ch : min_s) 
                    {
                        if (ch == to_replace)
                        {
                            ch = '0';
                        }
                    }
                    break;
                }
            }
        }

        // Step 5: Convert both versions to integers
        int max_val = stoi(max_s);
        int min_val = stoi(min_s);

        // Step 6: Return the difference
        return max_val - min_val;
    }
};