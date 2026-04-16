class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        HashMap<Integer, ArrayList<Integer>>mapp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            mapp.computeIfAbsent(nums[i],k->new ArrayList<>()).add(i);
        }
        List<Integer>ans=new ArrayList<>();
        for(int i=0;i<queries.length;i++){
            int index=queries[i];
            int ele=nums[index];
            ArrayList<Integer>indexes=mapp.get(ele);
            if(indexes.size()==1)
                ans.add(-1);
            else{
                int indexofele=Collections.binarySearch(indexes,index);
                int n=nums.length;
                int m=indexes.size();
                int last=(indexofele-1+m)%m;
                int next=(indexofele+1)%m;
                int prevdist=(index-indexes.get(last)+n)%n;
                int nextdist=(indexes.get(next)-index+n)%n;
                ans.add(Math.min(prevdist,nextdist));
            }
        }
        return ans;
    }
}