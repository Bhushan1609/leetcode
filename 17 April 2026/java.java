class Solution {
    public int reverseNumber(int num){
        int num1=0;
        while(num>0){
            num1=(num1*10)+num%10;
            num/=10;
        }
        return num1;
    }
    public int minMirrorPairDistance(int[] nums) {
        int n=nums.length;
        int ans=n+1;
        HashMap<Integer,Integer>mapp=new HashMap<>();
        for(int i=0;i<n;i++){
            if(mapp.containsKey(nums[i])){
                ans=Math.min(ans,i-mapp.get(nums[i]));
            }
            mapp.put(reverseNumber(nums[i]),i);
        }
        return ans==n+1?-1:ans;
    }
}