class Solution {
    int[][][] dp=new int[301][27][27];
    public int recursion(int i,int f1,int f2,String word){
        if(i>=word.length())    
            return 0;
        if(dp[i][f1][f2]!=-1)
            return dp[i][f1][f2];
        int x=(word.charAt(i)-'A')/6;
        int y=(word.charAt(i)-'A')%6;
        int x1=f1/6;
        int y1=f1%6;
        int x2=f2/6;
        int y2=f2%6;
        if(f1==26 && f2==26){
            int finger1=0+recursion(i+1,word.charAt(i)-'A',f2,word);
            int finger2=0+recursion(i+1,f1,word.charAt(i)-'A',word);
            return dp[i][f1][f2]=Math.min(finger1,finger2);
        }else if(f2==26){
            int finger1=Math.abs(x1-x)+Math.abs(y1-y)+recursion(i+1,word.charAt(i)-'A',f2,word);
            int finger2=0+recursion(i+1,f1,word.charAt(i)-'A',word);
            return dp[i][f1][f2]=Math.min(finger1,finger2);
        }
        int finger1=Math.abs(x1-x)+Math.abs(y1-y)+recursion(i+1,word.charAt(i)-'A',f2,word);
        int finger2=Math.abs(x2-x)+Math.abs(y2-y)+recursion(i+1,f1,word.charAt(i)-'A',word);
        return dp[i][f1][f2]=Math.min(finger1,finger2);
    }
    public int minimumDistance(String word) {
        for (int i=0;i<301;i++)
            for (int j=0;j<27;j++) 
                Arrays.fill(dp[i][j],-1);
        int n=word.length();
        return recursion(0,26,26,word);
    }
}