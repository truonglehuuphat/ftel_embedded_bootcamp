class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        // int n = words.length;
        // int min = Integer.MAX_VALUE; 
        // int right = -1;
        // int left = -1;
        // for(int i = startIndex; i < n; i++){
        //     right++;
        //     if(target.equals(words[i]) == true){
        //         break;
        //     }
        // }

        // for(int i = startIndex; i > - n - startIndex ; i--){
        //     int index = (i - 1 + n) % n;
        //     if(i < 0 ) {
        //         index = n + i + 1 ;
        //     }
        //     if(target.equals(words[index]) == true){
        //         break;
        //     }
        //     left++;
        // }
        // if((left == -1) && (right == -1)) return -1;
        // return Math.min(left + 1,right+1); 
        int n = words.length;
        int min = Integer.MAX_VALUE;
        List<Integer> ans = new ArrayList<>();
        System.out.println("n " + n);
        for(int i = 0; i < n; i++){
            if(target.equals(words[i]) == true){
                ans.add(i);
            }
        }
        if(ans.size() == 0) return -1;
        int diff = 0;
        for(int d: ans){
            if (startIndex > d) {
                diff = Math.min(Math.abs(startIndex - d), (d+n-startIndex) % n);
            } else {
                diff = Math.min(Math.abs(startIndex - d), (-d+startIndex+n) % n);
            }
           
           min = Math.min(diff, min);
        }

        return min;
    }
}