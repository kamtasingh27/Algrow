// Given an array with n objects colored red, white or blue, 
// sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note: Using library sort function is not allowed.

void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int r=0,b=n-1;
    int i=0;
    while(i<=b){
        if(A[i] == 0){
            cout<<"swapping "<<A[i]<<" "<<A[r]<<endl;

            A[i] = A[r];
            A[r++] = 0;
            i++;
        }else if(A[i] == 2){
            A[i] = A[b];
            A[b--] = 2;
        }else{
            i++;
        }
    }    
}
