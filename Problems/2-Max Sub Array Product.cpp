/*
Problem Statement
You are given an array “arr'' of integers. Your task is to find the contiguous subarray within the array which has the largest product of its elements. You have to report this maximum product.
An array c is a subarray of array d if c can be obtained from d by deletion of several elements from the beginning and several elements from the end.

For e.g.- The non-empty subarrays of an array [1,2,3] will be- [1],[2],[3],[1,2],[2,3],[1,2,3].
For Example:
If arr = {-3,4,5}.
All the possible non-empty contiguous subarrays of “arr” are {-3}, {4}, {5}, {-3,4}, {4,5} and {-3,4,5}.
The product of these subarrays are -3, 4, 5, -12, 20 and -60 respectively.
The maximum product is 20. Hence, the answer is 20.
Follow Up:
Can you solve this in linear time and constant space complexity?
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then, the T test cases follow.
The first line of each test case contains a single integer N, denoting the number of elements of the array “arr”.
The second line of each test case contains N space separated integers denoting the elements of the array “arr”.
Output Format:
For each test case, print the maximum product of the contiguous non-empty subarray of the array “arr”.

Output for each test case will be printed in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 5000
-100 <= arr[i] <= 100
where N is the size of the array “arr”.

Time limit: 1 second
Sample Input 1:
2
4
3 5 -2 -4
5
2 4 3 5 6
Sample Output 1:
120
720
Explanation For Sample 1:
For the first test case, all the possible non-empty contiguous subarrays of “arr” are {3}, {5}, {-2}, {-4}, {3,5}, {5,-2}, {-2,-4}, {3,5,-2}, {5,-2,-4} and {3,5,-2,-4}.
The product of these subarrays are 3, 5, -2, -4, 15, -10, 8, -30, 40 and 120 respectively.
So, the maximum product is 120.
For the second test case, since all the elements in the array “arr” are positive, we get the maximum product subarray by multiplying all the elements in the array. So, the maximum product is 720.
Sample Input 2:
2
4
6 0 2 -4
3
-1 -3 -4
Sample Output 2:
6
12
*/
int  maxSubArrayProduct(int arr[],int n){
    int max_ending_here=1;
    int min_ending_here=1;
    int max_so_far=0;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            max_ending_here=max_ending_here*arr[i];
            min_ending_here=min(min_ending_here*arr[i],1);
        }else if(arr[i]==0){
            max_ending_here=1;
            min_ending_here=0;
        }
        else{
            int temp=max_ending_here;
            max_ending_here=max(min_ending_here*arr[i],1);
            min_ending_here=temp*arr[i];
        }
        max_so_far=max(max_so_far,max_ending_here);
    }
    return max_so_far;
}
