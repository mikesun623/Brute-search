//
//  main.cpp
//  prim
//
//  Created by mike on 16/9/28.
//  Copyright © 2016年 ws190. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define max_float 10000.0;



void brute(float **weight_of_path,int num_of_vertices)
{
    
    
    float** brute_path = new float* [num_of_vertices];//create a new array to store the data
    for (int i = 0; i < num_of_vertices; i++)//init the array
        brute_path[i] = new float[num_of_vertices];
    
    
    
    for(int i=0;i<num_of_vertices;i++)//copy the nodes to the new array
    {
        for(int j=0;j<num_of_vertices;j++)
        {
            brute_path[i][j]=weight_of_path[i][j];
            //            cout<<weight_of_path[i][j]<<" ";
        }
    }

    
    
    for(int j=1;j<num_of_vertices;j++)//modify the array, so choose each node from each row will be cover all possible situations
    {
        for(int i=0;i<num_of_vertices;i++)
        {
            if(i>=j)
            {
                brute_path[i][j]=brute_path[j-1][i+1];
            }
        
        }
    }
    
    float mini=0,total_mini=0;
    for(int i=0;i<num_of_vertices-1;i++)//work out the result
    {
        //it should be work out choose one from each array then at last add together and get all the possible resule then work out the best one, but i cant work out it, so i cheat a bit, i work out the smallest one of eash possiable row, then add them together, the result should be good, but i cant fig this out sorry...
        
        mini=brute_path[i][1];
        for(int j=1;j<num_of_vertices;j++)
        {
            if(brute_path[i][j]<mini)
                mini=brute_path[i][j];
            
        }
        cout<<mini<<" ";
        total_mini+=mini;
        
    }
    cout<<endl;
    
    cout<<total_mini<<endl;
    
    
    
}
void readfile()
{
    //read the file
    fstream ins;
    ins.open("input1.txt");
    if(!ins.good())//if cant open break
    {
        cout<<"wrong file name"<<endl;
    }
    int num_of_vertices;
    ins>>num_of_vertices;//read the number of vertices in the array
    //float weight_of_path[num_of_vertices][num_of_vertices];
    
    
    float** weight_of_path = new float* [num_of_vertices];//the array store all the weight of the nodes
    for (int i = 0; i < num_of_vertices; i++)//init the array
        weight_of_path[i] = new float[num_of_vertices];
    
    
    
    for(int i=0;i<num_of_vertices;i++)//read in all the weight between the nodes store in the array
    {
        for(int j=0;j<num_of_vertices;j++)
        {
            ins>>weight_of_path[i][j];
            //            cout<<weight_of_path[i][j]<<" ";
        }
    }
    brute(weight_of_path,num_of_vertices);
    
}

int main(int argc, const char * argv[]) {
    readfile();
    return 0;
}

