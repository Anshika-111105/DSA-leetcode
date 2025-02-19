class Solution {
public:
void generateHappyStrings(int n, string current, vector<string> &happyStrings, char lastChar)
{
    if (current.length() == n)
    {
        happyStrings.push_back(current);
        return;
    }
    
    for (char c : {'a', 'b', 'c'})
    {
        if (c != lastChar)
        {
            generateHappyStrings(n, current + c, happyStrings, c);
        }
    }
}

string getHappyString(int n, int k)
{
    vector<string> happyStrings;
    generateHappyStrings(n, "", happyStrings, '\0');
    
    if (k > happyStrings.size())
        return "";
    
    return happyStrings[k - 1];
}

};