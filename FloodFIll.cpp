#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &image, int sr, int sc, int originalColor, int newColor);

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int originalColor = image[sr][sc];
    dfs(image, sr, sc, originalColor, color);

    return image;
}

void dfs(vector<vector<int>> &image, int sr, int sc, int originalColor, int newColor)
{
    if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == newColor || image[sr][sc] != originalColor)
    {
        return;
    }

    image[sr][sc] = newColor;

    dfs(image, sr + 1, sc, originalColor, newColor);
    dfs(image, sr - 1, sc, originalColor, newColor);
    dfs(image, sr, sc + 1, originalColor, newColor);
    dfs(image, sr, sc - 1, originalColor, newColor);
}

int main()
{
    vector<vector<int>> image = 
    {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    for(const auto &row : result)
    {
        for(const auto &col : row)
        {
            cout << col << " ";
        }

        cout << endl;
    }

    return 0;
}