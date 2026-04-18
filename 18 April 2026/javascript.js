/**
 * @param {number} n
 * @return {number}
 */
function reverseNumber(n){
    let ans=0;
    while(n>0){
        ans=(ans*10+n%10);
        n=Math.floor(n/10);
    }
    return ans;
}
var mirrorDistance = function(n) {
    return Math.abs(n-reverseNumber(n));
};