
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int minDistance(int distance[], bool visited[])
{
    // Initialize min value
    int min = INT_MAX;
    int min_index;
  
    for (int i = 0; i < 6; i++){
        if (visited[i] == false && distance[i] <= min){
            min = distance[i];
            min_index = i;
        }}
    return min_index;
    
}

void printSolution(int dist[], int s)
{   
    cout << "distances from "<< s <<" town to others" << endl;
    cout << "town\t distance" << endl;
    float avg;
    for (int i = 0; i < 6; i++){
        if(i!=s){
            cout << i << " \t\t\t" << dist[i] << endl;
            avg = avg + dist[i];
        }
    }
    cout << "\n";
    cout << "\n";
    cout << "avg is " << avg/5.0;
}

void dijkstra(int graph[6][6], int s)
{
    int distance[6];
    bool visited[6];

    for (int i = 0; i < 6; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[s] = 0;
  
    for (int count = 0; count < 6; count++) {
        
        int d = minDistance(distance, visited);
        //distance[d] = graph[]
        visited[d] = true;

        for (int v = 0; v < 6; v++){

            if (!visited[v] && graph[d][v] && distance[d] != INT_MAX && distance[d] + graph[d][v] < distance[v]){
                distance[v] = distance[d] + graph[d][v];
                }
    }}
    
  
    // print the constructed distance array
    printSolution(distance,s);
}

int main(){
    vector<vector<int>> answer;
    int graph[6][6] = { { 0,10,0,0,15,5 },
                        { 10,0,10,30,0,0 },
                        { 0,10,0,12,5,0 },
                        { 0,30,12,0,0,20 },
                        { 15,0,5,0,0,0 },
                        { 5,0,0,20,0,0 } };
 
    int start_position = 4;
    dijkstra(graph, start_position);
    return 0;
}