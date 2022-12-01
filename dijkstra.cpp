#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int mNodes = 0;
    int SourceNode = 0;

    cout << "Enter number of nodes : ";
    cin >> mNodes;

    cout << "Enter adjacency matrix :" << endl;
    int Graph[mNodes][mNodes];
    for(int i=0; i<mNodes; i++ )
    {
        for(int j=0; j<mNodes; j++)
        {
            cin >> Graph[i][j];
        }
    }

    cout << "Enter source node : " ;
    cin >> SourceNode;

    int Visited[mNodes] ;  // Array to keep track of visited nodes
    int Distance[mNodes] ; 

    for(int i=0; i< mNodes; i++)   // Initializing visited and distance array
    {
        Visited[i] = 0;
        Distance[i] = INT_MAX;
    }

    int r = SourceNode;  // Temporary source node
    Visited[r] = 1;
    Distance[r] =0;
    int x = 1;           // Integer which stores number of nodes visited

    while(x != mNodes)
    {
        // Updating distances.
        for(int i=0; i<mNodes ; i++)
        {
            if(Graph[r][i] !=0 && Visited[i] != 1 && Distance[r]+Graph[r][i] < Distance[i])
                Distance[i] = Distance[r]+Graph[r][i];
        }
        
        // Finding least distance
        int leastNo = INT_MAX;
        r = 0;
        for(int i=0; i<mNodes; i++)
        {
            if(Distance[i] != 0 && Visited[i] != 1 && leastNo > Distance[i] )
            {
                leastNo = Distance[i];
                r = i;
            }
        }
        Visited[r] = 1;
        x++;
    }

    cout << "Distance from source node '" << SourceNode << "' to node " << endl;
    for(int i=0; i<mNodes; i++)
    {
        cout << i << " is " << Distance[i] << endl;
    }
}
