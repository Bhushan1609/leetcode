/**
 * @param {string[]} words
 * @param {string} target
 * @param {number} startIndex
 * @return {number}
 */
var closestTarget = function(words, target, startIndex) {
    let n=words.length;
    let ans=Number.MAX_SAFE_INTEGER;
    for(let i=0;i<n;i++){
        if(words[i]==target){
            let dist=Math.abs(i-startIndex);
            ans=Math.min(ans,Math.min(dist,n-dist));
        }
    }
    return ans==Number.MAX_SAFE_INTEGER?-1:ans;
};