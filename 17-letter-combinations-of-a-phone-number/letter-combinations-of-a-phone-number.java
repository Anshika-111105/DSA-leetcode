class Solution {
     String[] keypad = new String[]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public List<String> letterCombinations(String digits) {
         if (digits == null || digits.isEmpty()) 
            return new ArrayList<>();
        List<String> result = new ArrayList<>();
        StringBuilder current = new StringBuilder();
        backtrack(digits,result,current,0);
        return result;
    }

    public void backtrack(String digits, List<String> result,StringBuilder current,int index) {
        if(index==digits.length()) {
            result.add(current.toString());
            return;
        }

        String letters = keypad[digits.charAt(index)-'0'];
        for(char c : letters.toCharArray()) {
            current.append(c);   // Choose
            backtrack(digits,result,current,index+1);   // Explore next digit
            current.deleteCharAt(current.length()-1);    // Unchoose (Backtrack)
        }

    }

}