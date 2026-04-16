class Solution {
    public long recursion(int i,int j,List<Integer>robot,List<Integer>position,List<List<Long>>dp){
        if(i>=robot.size())
            return 0;
        if(j>=position.size())
            return (long)1e12; 
        if(dp.get(i).get(j)!=-1L)
            return dp.get(i).get(j);
        long value=Math.min(Math.abs(position.get(j)-robot.get(i))+recursion(i+1,j+1,robot,position,dp),recursion(i,j+1,robot,position,dp));
        dp.get(i).set(j,value);
        return value;
    }
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        int n=robot.size();
        int m=factory.length;
        Collections.sort(robot);
        Arrays.sort(factory,Comparator.comparingInt(a->a[0]));
        List<Integer>position=new ArrayList<Integer>();
        for(int i=0;i<m;i++)
            for(int j=0;j<factory[i][1];j++)
                position.add(factory[i][0]);

        List<List<Long>>dp=new ArrayList<>();
        for(int i=0;i<n;i++){
            List<Long>row=new ArrayList<>(Collections.nCopies(position.size(),-1L));
            dp.add(row);
        }
        return recursion(0,0,robot,position,dp);
    }
}