class Solution {
    public String countAndSay(int n) {
        String seq = "1";
        for(int i =1;i<n;i++){
            seq = sqbuilder(seq);
        }
        return seq;
    }

    public static String sqbuilder(String s){
        int count = 1;
        int i;
        StringBuilder sb = new StringBuilder();
        for(i = 0;i<s.length();i++){
            if(i+1 < s.length() && s.charAt(i)==s.charAt(i+1)){
                count++;
            }
            else{
                sb.append(count);
                sb.append(s.charAt(i));
                count = 1;
            }
            
        }
        return sb.toString();
    }
}