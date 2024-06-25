class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty())
      return false;

     int m = matrix.size();
     int n = matrix[0].size();
     int l = 0;
     int r = m * n;

    while (l < r) {
       int mid = (l + r) / 2;
       int i = mid / n;
       int j = mid % n;
      if (matrix[i][j] == target)
        return true;
      if (matrix[i][j] < target)
        l = mid + 1;
      else
        r = mid;
    }

    return false;
  }
}; 