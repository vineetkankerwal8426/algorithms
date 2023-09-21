#include<iostream>
#include<vector>
using namespace std;

//count the number of path for going to end; 
//  {[],[],[],
//   [],[],[],
//   [],[],[]}

int countpath(int r,int c){
    if(r==1 || c ==1){
        return 1;
    }
    int left = countpath(r-1,c);
    int right = countpath(r,c-1);
    return left + right;
}


//print the actual path in an array. d= down, r= right;

vector<string> path(string p,int r, int c){
    if(r==1 && c==1){
        vector<string> list;
        list.push_back(p);
        // cout<<p<<endl;
        return list;
    }
    vector<string> list;
    if (r>1){
        vector<string>left = path(p+'D',r-1,c) ;
        list.insert(list.end(),left.begin(),left.end());
    }

    if(c>1){
        vector<string>right = path(p+'R',r,c-1);
        list.insert(list.end(),right.begin(),right.end());
    }
    return list;
}