class Solution {
    public int minimumDistance(int[] nums) {
        int ans=1000000,n=nums.length;
        Map<Integer,Integer>next_first_occurence=new HashMap<>();
        int[] next_first_occurence_index=new int[n];
        Arrays.fill(next_first_occurence_index,-1);
        for(int i=n-1;i>=0;i--){
            if(next_first_occurence.containsKey(nums[i])){
                next_first_occurence_index[i]=next_first_occurence.get(nums[i]);
            }
            next_first_occurence.put(nums[i],i);        
        }
        for(int i=0;i<n;i++){
            int firstIndex=i;
            int secondIndex=next_first_occurence_index[i];
            if(secondIndex!=-1){
                int thirdIndex=next_first_occurence_index[secondIndex];
                if(thirdIndex!=-1){
                    ans=Math.min(ans,thirdIndex-firstIndex);
                }
            }
        }
        return ans==1000000?-1:ans<<1;
    }
}