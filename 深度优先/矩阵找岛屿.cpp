//
// Created by Zhangjun on 2020/4/19.
//
//  给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，
//  计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或
//  垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。


#include<iostream>
#include<set>
#include <vector>

using namespace std;

int dfs(vector<vector<char>> &grid,int r,int c,int num){
    if(!(r>=0 && r<grid.size() && c>=0 && c<grid[0].size()))
        return num;
    if(grid[r][c] != '1')
        return num;
    grid[r][c] = '2';
    num++;
    num = dfs(grid,r-1,c,num);
    num = dfs(grid,r+1,c,num);
    num = dfs(grid,r,c-1,num);
    num = dfs(grid,r,c+1,num);
    return num;
}

int numISlands(vector<vector<char>> &grid){
    if(grid.size() == 0 || grid[0].size() ==0)
        return 0;
    int count = 0;
    for(int r=0;r<grid.size();r++){
        for(int c=0;c<grid[0].size();c++){
            if(grid[r][c] == '1'){
                int num = 0;
                num = dfs(grid,r,c,num);
                count++;
                cout<<"no."<<count<<":"<<num<<endl;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid{{'1','1','0','0','0'},
                              {'1','1','0','0','0'},
                              {'0','0','1','0','0'},
                              {'0','0','0','1','1'}};

//    vector<vector<char>> grid{{'1','1','1','1','0'},
//                              {'1','1','0','1','0'},
//                              {'1','1','0','0','0'},
//                              {'0','0','0','0','0'}};
    int res = 0;
    res = numISlands(grid);
    cout<<res<<endl;
}
//输入:
//11000
//11000
//00100
//00011
//输出: 3

//输入:
//11110
//11010
//11000
//00000
//输出: 1