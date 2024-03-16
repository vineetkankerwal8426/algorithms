// find max and min in an array with divide and conquer strategy


pair<int,int> MinAndMax(vector<int> a,int i,int j){
    if(j-i<2){  //if there are only two or less then two element in an array in particular recursion call
        int mx = max(a[i],a[j]);
        int mn = min(a[i],a[j]);
        return pair(mx,mn);
    }

    int mid = i+(j-i)/2;
    pair<int,int> left = MinAndMax(a,i,mid);  //calculate max and min of left array
    pair<int,int> right = MinAndMax(a,mid+1,j);  //calculate max an min or right array
    int mx = max(left.first,right.first);   //then compair left and right min max
    int mn = min(left.second,right.second);
    return pair(mx,mn);  // return min and max 
}

int main(){
    vector<int> arr = {4,5,2,1,7,3,10,0,44,-2};
    pair<int,int> b = MinAndMax(arr,0,a.size()-1);
    cout<<b.first<<" "<<b.second<<endl;
}