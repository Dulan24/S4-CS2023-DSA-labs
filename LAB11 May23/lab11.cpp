
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
  
int mini(vector<vector<int>> path, bool visited[6]){
    int size = path.size();
    int minimum_index = -1;
    vector<int> minimum = path[0];
    for(int i=0; i<size; i++){
        if(path[i][0]<=minimum[0]){
            if (!visited[path[i][2]]) {
                minimum = path[i];
                minimum_index = i;

            }
        }
    }
    return minimum_index;
}

void printvector(vector<vector<int>> vec){
    int size = vec.size();
    cout << "start \t end \t weight" << endl; 
    for(int i=0; i<size; i++){
        cout << vec[i][1] << "\t"  << vec[i][2] << "\t" << vec[i][0] << endl;
    }
}

vector<vector<int>> primMST(int graph[6][6], int start_pos){
    
    bool array[6] = {false};
    array[start_pos] = true;
    vector<vector<int>> path;
    vector<vector<int>> answer;
    
    for (int i=0; i<6; i++){
        
        for (int j=0; j<6; j++){
            if (graph[start_pos][j]!=0 && !array[j]){
                vector<int> edge{graph[start_pos][j],start_pos,j};
                path.push_back(edge);
            }
        }
        //printvector(path);
        int minimum_index = mini(path, array);
        if (minimum_index == -1)  break;
        //cout <<"test\n";
        vector<int> min_edge = path[minimum_index];
        
        //cout << "min"<<min_edge[1] << "\t"  << min_edge[2] << "\t" << min_edge[0] << endl;
        answer.push_back(min_edge);
        array[min_edge[2]] = true;
        path.erase(path.begin()+minimum_index);
        start_pos = min_edge[2];
    }
    //printvector(answer);
    return answer;
}



int main()
{
    vector<vector<int>> answer;
    int graph[6][6] = { { 0,3,0,0,0,1 },
                        { 3,0,2,1,10,0 },
                        { 0,2,0,3,0,5 },
                        { 0,1,3,0,5,0 },
                        { 0,10,0,5,0,4 },
                        { 1,0,5,0,4,0 } };
 
    int start_position = 0;
    answer = primMST(graph,start_position);
    printvector(answer);
    return 0;
}