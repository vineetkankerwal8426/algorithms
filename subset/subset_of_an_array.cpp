#include<iostream>
#include<vector>
using namespace std;

//helper function to calculate all possible subsets of an array
void calculate(vector<int>& nums, vector<vector<int>>&result, vector<int>& sub,int index){
    result.push_back(sub);
    for(int i =index;i<nums.size();i++){
        sub.push_back(nums[i]);
        calculate(nums,result,sub,i+1);
        sub.pop_back();  //delete last element to make the subset array equal to the last recursive call;
    }
}

vector<vector<int>> subset(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> sub;
    calculate(nums,result,sub,0);
    return result;
}