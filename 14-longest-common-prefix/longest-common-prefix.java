class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        int mini = Integer.MAX_VALUE;
        for(int i=0; i<n; i++){
            mini = Math.min(mini, strs[i].length());
        }

        String x = "";
        for(int i=0; i<mini; i++){
            char y = strs[0].charAt(i);
            for(int j=1; j<n; j++){
                if(strs[j].charAt(i)!=y) return x;
            }
            x = x + y;
        }

        return x;
    }
}