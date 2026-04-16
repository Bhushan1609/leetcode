/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
function binarySearch(arr, target) {
    let left = 0,
        right = arr.length;
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
var solveQueries = function(nums, queries) {
    let n=nums.length;
    let mapp=new Map();
    for(let i=0;i<n;i++){
        if(!mapp.has(nums[i]))
            mapp.set(nums[i],[]);
        mapp.get(nums[i]).push(i);
    }    
    for(let i=0;i<queries.length;i++){
        let index=queries[i];
        let ele=nums[index];
        let indexes=mapp.get(ele);
        if(indexes.length==1)
            queries[i]=-1;
        else{
            let indexofele=binarySearch(indexes,index);
            let m=indexes.length;
            let last=(indexofele-1+m)%m;
            let next=(indexofele+1)%m;
            let prevdist=(index-indexes[last]+n)%n;
            let nextdist=(indexes[next]-index+n)%n;
            queries[i]=(Math.min(prevdist,nextdist));
        }
    }
    return queries;
};
