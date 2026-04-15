/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
var getMinDistance = function(nums, target, start) {
    let n=nums.length;
    let ans=Number.MAX_SAFE_INTEGER;
    for(let i=0;i<n;i++){
        if(nums[i]==target){
            ans=Math.min(ans,Math.abs(i-start));
        }
    }
    return ans;
};