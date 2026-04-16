/**
 * @param {number[]} robot
 * @param {number[][]} factory
 * @return {number}
 */
function recursion(i,j,robot,position,dp){
    if(i>=robot.length)
        return 0;
    if(j>=position.length)
        return 1E12;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=Math.min(Math.abs(position[j]-robot[i])+recursion(i+1,j+1,robot,position,dp),recursion(i,j+1,robot,position,dp));
}
var minimumTotalDistance = function(robot, factory) {
    robot.sort((a,b)=>a-b);
    factory.sort((a,b)=>a[0]-b[0]);
    let position=[];
    for(let i=0;i<factory.length;i++)
        for(let j=0;j<factory[i][1];j++)
            position.push(factory[i][0]);
    let dp=Array.from({length:robot.length},()=>Array(position.length).fill(-1));
    return recursion(0,0,robot,position,dp);
};