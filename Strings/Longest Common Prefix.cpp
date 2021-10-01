// Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array.
// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
  
string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    string str;
    int point = 0;
    for(int i = 0; i<A[0].size(); i++){
        point = A[0][i];
        for(int j = 1; j<n; j++){
            if(A[j][i] != point){
                return str;
            }
        }
        str.push_back(point);
    }
    return str;
}
