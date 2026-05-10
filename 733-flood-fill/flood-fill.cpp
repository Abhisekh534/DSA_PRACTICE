class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int ocolor, vector<vector<bool>>&visited){
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sr==n || sc<0 || sc==m || visited[sr][sc] || image[sr][sc]!=ocolor) return;

        visited[sr][sc] = true;

        dfs(image, sr, sc+1, color, ocolor, visited);
        dfs(image, sr, sc-1, color, ocolor, visited);
        dfs(image, sr+1, sc, color, ocolor, visited);
        dfs(image, sr-1, sc, color, ocolor, visited);

        image[sr][sc] = color;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ocolor = image[sr][sc];
        if(ocolor==color) return image;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(image, sr, sc, color, ocolor, visited);


        return image;
    }
};