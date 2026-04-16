/**
 * @param {string} word
 * @return {number}
 */
function recursion(i,f1,f2,word,dp){
    if(i>=word.length)
        return 0;
    if(dp[i][f1][f2] != -1)
        return dp[i][f1][f2];
    let pos=word.charCodeAt(i)-'A'.charCodeAt(0);
    let x=Math.floor(pos/6);
    let y=pos%6;
    let x1=Math.floor(f1/6);
    let y1=f1%6;
    let x2=Math.floor(f2/6);
    let y2=f2%6;
    if(f1==26 && f2==26){
            let finger1=0+recursion(i+1,pos,f2,word,dp);
            let finger2=0+recursion(i+1,f1,pos,word,dp);
            return dp[i][f1][f2]=Math.min(finger1,finger2);
        }else if(f2==26){
            let finger1=Math.abs(x1-x)+Math.abs(y1-y)+recursion(i+1,pos,f2,word,dp);
            let finger2=0+recursion(i+1,f1,pos,word,dp);
            return dp[i][f1][f2]=Math.min(finger1,finger2);
        }
        let finger1=Math.abs(x1-x)+Math.abs(y1-y)+recursion(i+1,pos,f2,word,dp);
        let finger2=Math.abs(x2-x)+Math.abs(y2-y)+recursion(i+1,f1,pos,word,dp);
        return dp[i][f1][f2]=Math.min(finger1,finger2);
}
var minimumDistance = function(word) {
    let dp=Array.from({length:301},()=>Array.from({length:27},()=>Array(27).fill(-1)));
    return recursion(0,26,26,word,dp);
};



