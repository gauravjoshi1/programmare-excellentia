package gj.code.arrays;

class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 0) return "";
        if (numRows == 1) return s;

        int charIndex = 0, rowIndex = 0, colIndex = 0;
        int rows = numRows;
        int cols = s.length() % 2 == 0 ? s.length()/2 : s.length()/2 + 1;

        char[][] grid = new char[rows][cols];
        StringBuilder sb = new StringBuilder();

        while (charIndex < s.length()) {
            while (charIndex < s.length() && rowIndex < rows) {
                grid[rowIndex++][colIndex] = s.charAt(charIndex++);
            }
            
            rowIndex = rowIndex - 2;
            colIndex += 1;

            while (charIndex < s.length() && rowIndex >= 0) {
                grid[rowIndex--][colIndex++] = s.charAt(charIndex++);
            }

            rowIndex = 1;
            colIndex -= 1;
        }  

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != '\u0000') {
                    sb.append(grid[i][j]);
                }
            }
        }

        return sb.toString();
    }
}
