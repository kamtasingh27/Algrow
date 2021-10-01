// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
// Return the sum of the three integers.
// Assume that there will only be one solution


int Solution::threeSumClosest(vector<int> &A, int B) {
    int first,second,third;
    int res = 1000000000,sum;
    vector<int> a;
    for(int i=0; i<A.size(); i++){
        a.push_back(A[i]);
    }
    sort(a.begin(),a.end());
    third = A.size()-1;
    while(first<third){
        first=0;
        second=third-1;
        while(first<second){
            sum = a[first]+a[second]+a[third];
            if(sum==B)  return sum;
            if(abs(B-sum)<abs(B-res))   res = sum;
            if(B>sum)   first++;
            if(B<sum)   second--;
        }
        third--;
    }
    return res;
}
