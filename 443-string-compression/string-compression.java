class Solution {
    public int compress(char[] chars) {
        int idx=0;
        for(int start=0;start<chars.length;start++)
        {
            int end=start+1;
            while(end<chars.length && chars[start]==chars[end])
            {
                end++;
            }
            int cnt=end-start;
            chars[idx++]=chars[start];
            if(cnt>1)
            {
                for(char ch:Integer.toString(cnt).toCharArray())
                {
                    chars[idx++]=ch;
                }
            }
            start+=cnt-1;
        }
        return idx;
    }
}