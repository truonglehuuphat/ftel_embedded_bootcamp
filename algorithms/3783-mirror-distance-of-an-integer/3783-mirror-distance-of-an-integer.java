class Solution {
    int reverseNum(int x){
        int sum = 0;
        while(x > 0){
            sum = sum * 10 + x % 10;
            x = x /10;
        }
        return sum;
    }

    public int mirrorDistance(int n) {
        int rev = reverseNum(n);
        return Math.abs(rev - n);
    }
}