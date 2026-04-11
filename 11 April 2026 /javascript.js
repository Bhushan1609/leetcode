/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDistance = function(nums) {
    let ans=1E5,n=nums.length;
    let next_first_occurence=new Map();
    let next_first_occurence_index=new Array(n).fill(-1);
    for(let i=n-1;i>=0;i--){
        if(next_first_occurence.has(nums[i]))
            next_first_occurence_index[i]=next_first_occurence.get(nums[i]);
        next_first_occurence.set(nums[i],i);
    }
    for(let i=0;i<n;i++){
        let firstIndex=i;
        let secondIndex=next_first_occurence_index[i];
        if(secondIndex!=-1){
            let thirdIndex=next_first_occurence_index[secondIndex];
            if(thirdIndex!=-1){
                ans=Math.min(ans,thirdIndex-firstIndex);
            }
        }
    }
    return ans==1E5?-1:ans<<1;
};