class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int m = firstList.length;
        int n = secondList.length;
        int i = 0, j = 0;
        List<int[]> res = new ArrayList<>();
        while(i < m && j < n){
            int[] a = firstList[i];
            int[] b = secondList[j];
            int startMax = Math.max(a[0], b[0]);
            int endMin = Math.min(a[1], b[1]);

            if(endMin >= startMax){
                res.add(new int[]{startMax,endMin});
            }

            if(a[1]== endMin) {i++;}
            if(b[1]== endMin) {j++;}
        }
        return res.toArray(new int[0][]);
    }
}