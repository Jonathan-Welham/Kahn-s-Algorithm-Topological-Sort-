/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/kahns-topological-sort/submissions/code/1322597110
 * Title: hw8_2.cpp
 * Abstract: This program conducts the topological sorting based on the Kahns algorithm
 * Author: Jonathan Welham
 * ID: 6781
 * Date: 04/06/2020
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;




vector<int> bfs(vector<vector<int>> &v1, vector<int> &in);

int main(){

    int vertices;
    int edges;
    int to;
    int from;

    cin >> vertices >> edges;

    vector<vector<int>> v1(vertices);

    vector<int> indegree(vertices,0);

    for(int i = 0; i < edges; i++){
        cin >> to;
        cin >> from;

        indegree[from]++;
        v1[to].push_back(from);
    }

    for(int i= 0; i < indegree.size(); i++){
        cout << "In-degree[" << i << "]:" << indegree[i] <<endl;
    }

    vector<int> result = bfs(v1, indegree);

    if(result.empty()){

        cout << "No Order:"<< endl;

    } else {
        cout <<"Order:";

        for(int i = 0; i < result.size(); i++){
            cout << result[i];
            if(result.size()-1 != i){
                cout << "->";
            }
        }
        cout << endl;
    }
}

vector<int> bfs(vector<vector<int>> &v1, vector<int> &in){

    queue<int> q;
    vector<int> result;
    int count = 0;
    int head = 0;
    vector<bool> visited(v1.size(), false);

    for(int i = 0; i < in.size(); i++){
        if(in[i] == 0){
            count += 1;
            q.push(i);
        }
    }

    while(!q.empty()){

        head = q.front();
        result.push_back(head);

        q.pop();

        for(int relative : v1[head]){
            in[relative]--;

            if(visited[relative] == true){
                return vector<int>();
            }

            if(in[relative] == 0){
                q.push(relative);
                visited[relative] = true;
                count += 1;
            }
        }
    }

    if(v1.size() > count){
        return vector<int>();
    }
    return result;
}
