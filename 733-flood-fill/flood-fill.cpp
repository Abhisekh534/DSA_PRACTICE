class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int ocolor){
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sr==n || sc<0 || sc==m || image[sr][sc]!=ocolor  || image[sr][sc]==color) return;

        image[sr][sc] = color;

        dfs(image, sr, sc+1, color, ocolor);
        dfs(image, sr, sc-1, color, ocolor);
        dfs(image, sr+1, sc, color, ocolor);
        dfs(image, sr-1, sc, color, ocolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ocolor = image[sr][sc];

        dfs(image, sr, sc, color, ocolor);


        return image;
    }
};