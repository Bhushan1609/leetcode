/**
 * @param {number[]} nums
 * @return {number}
 */
function reverseNumber(num){
    let num1=0;
    while(num>0){
        num1=num1*10+num%10;
        num=Math.floor(num/10);
    }
    return num1;
}
var minMirrorPairDistance = function(nums) {
    let n=nums.length;
    let ans=n+1;
    let map=new Map();
    for(let i=0;i<n;i++){
        if(map.has(nums[i])){
            ans=Math.min(ans,i-map.get(nums[i]));
        }
        map.set(reverseNumber(nums[i]),i);
    }
    return ans==n+1?-1:ans;
};