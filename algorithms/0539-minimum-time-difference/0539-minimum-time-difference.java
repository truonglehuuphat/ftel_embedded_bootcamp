class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> arr = new ArrayList<>();
        for(String s: timePoints){
            char[] arrStr = s.toCharArray();
            int hour = (arrStr[0]-'0') * 10 + (arrStr[1]-'0');
            int minute = (arrStr[3]-'0') * 10 + (arrStr[4]-'0');
            int totalMin = hour * 60+ minute;
            arr.add(totalMin);
        }
        Collections.sort(arr);
        int min = 10000;
        for(int i = 0 ; i < arr.size()-1; i++){
            for(int j = i + 1; j <  arr.size(); j++){
                // int temp =  subtime(arr.get(i), arr.get(j));
                int temp = Math.min(Math.abs(arr.get(i) - arr.get(j)), 24*60 - Math.abs(arr.get(i) - arr.get(j)));
                if( temp < min) {
                    min = temp;
                }
            }
        }
        return min;
    }
    // int subtime(int time1, int time2){
    //     return Math.min(Math.abs(time1 - time2), 24*60 - Math.abs(time1 - time2));
    // }
}