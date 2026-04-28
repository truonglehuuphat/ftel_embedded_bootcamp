class Solution {
    public long[] distance(int[] nums) {
        Map<Integer,List<Integer>> mp = new HashMap<>();
        int len = nums.length;
        for(int i = 0 ; i < len; i++){
            mp.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        long[] res = new long[len];
        for(List<Integer> group: mp.values()){
            long sum = 0; 
            for(int idx: group){
                sum += idx;
            }
            long pretotal = 0;
            int sz = group.size();
            for(int i =0 ;i < sz;i++){
                int idx = group.get(i);
                res[idx] = sum - pretotal * 2 + (long)idx*(2* i - sz);
                pretotal +=idx;
            }
        }
        return res;
    }
}