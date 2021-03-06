// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left
// corner (row1, col1) and lower right corner (row2, col2).

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// 1.You may assume that the matrix does not change.
// 2.There are many calls to sumRegion function.
// 3.You may assume that row1 ≤ row2 and col1 ≤ col2.

// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left
// corner (row1, col1) and lower right corner (row2, col2).

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// 1.You may assume that the matrix does not change.
// 2.There are many calls to sumRegion function.
// 3.You may assume that row1 ≤ row2 and col1 ≤ col2.

class NumMatrix {
    vector<vector<long>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        sums.resize(m + 1, vector<long>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
    }
};

