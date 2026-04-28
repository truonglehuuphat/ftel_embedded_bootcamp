class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        // int position = 0;
        int nl=0;
        int nr=0;
        int nt=0;
        char[] arr = moves.toCharArray();
        for(char c: moves.toCharArray()){
            if(c=='R'){nr++;}
            else if(c=='L') {nl++;}
            else{nt++;} 
        }
        int maxValue = Math.max((nl+ nt)-nr,(nt + nr) - nl);
        return maxValue;
    }
}