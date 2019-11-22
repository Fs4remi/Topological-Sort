#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int SIZE = 19;
int matrix[SIZE][SIZE]={
       //0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0th row
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//Phys 135-1
        {0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},//Math 130-2
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},//Math 225-3
        {0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},//CS 101-4
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},//CS 221-5
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 311-6
        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0},//CS 201-7
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 421-8
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1},//CS 301-9
        {0,0,0,0,0,0,0,0,0,9,0,0,0,1,0,0,1,0,1},//CS 211-10
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},//MATH 131-11
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//stat 316-12
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 411-13
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 230-14
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 401-15
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 321-16
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//CS 441-17
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}//CS 413-18
};
string namesOfClasses [SIZE] = {"NAN","Phys 135","Math 130","Math 225","CS 101","CS 221","CS 311","CS 201","CS 421","CS 301","CS 211","MATH 131","STAT 316","CS 411","CS 230","CS 401","CS 321","CS 441","CS 413"};

/*
const int SIZE = 6;
int matrix[SIZE][SIZE] ={
        {0,0,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,1,0,0,0},
        {0,1,0,1,0,1},
        {0,0,0,1,0,0}
};
string namesOfClasses[SIZE] = {"NAN", "A","B","C","D","E"};*/
string getClassName(int i);
int areAllVisited(bool []);
void topologicalSort(stack<int>&);
void dfs(int, bool [],stack<int>&);

int main() {
    stack <int> topologicalSortResult;
    topologicalSort(topologicalSortResult);
    cout<<topologicalSortResult.size()<<endl;
    while(!topologicalSortResult.empty()){
        int num = topologicalSortResult.top();
        cout <<getClassName(num) << "->";
        topologicalSortResult.pop();
    }
    return 0;
}
string getClassName(int i){
    if(i <= SIZE && i > 0)
        return namesOfClasses[i];
    else
        return namesOfClasses[0];
}
void topologicalSort(stack<int>& results){
    bool visited [SIZE] = {false};
    visited[0]=true;
    int indexOfVertex = areAllVisited(visited);
    while( indexOfVertex != -1){
        dfs(indexOfVertex, visited,results);
        indexOfVertex = areAllVisited(visited);
    }
}
int areAllVisited(bool array[]){
    for(int i = 0; i < SIZE; i++){
        if(!array[i])
            return i;
    }
    return -1;
}
void dfs(int vertex, bool visited[],stack <int>& results){ //stack <int> topologicalSortResult;
    visited[vertex]=true;
    for(int i = 1; i <= SIZE;i++){
        if(matrix[vertex][i] == 1 && !visited[i]){
            dfs(i, visited,results);
        }
    }
    results.push(vertex);
}
