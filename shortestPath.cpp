#include<bits/stdc++.h>
#include<string>
using namespace std;
# define INF 999

void displayMainMenu(int& choice, int& location);
void displayMainMenu2(int& choice, int& destination);


//----------------------------------------------------------------------------- 
// This class represents a directed graph using 
// adjacency list representation
//-----------------------------------------------------------------------------
class Graph
{
    int V;    // Number of vertices
 
    
    list< pair<int, int> > *adj;   //The vertex and weight pair for every edge
 
public:
    Graph(int V);  // Constructor
 
    void addEdge(int u, int v, int w);
 
    void shortestPath(int src, string City[], int dest);
};
//-----------------------------------------------------------------------------
// Allocates the memory for the adjacency list
//----------------------------------------------------------------------------- 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
//-----------------------------------------------------------------------------
// Adds edges to the graph
//----------------------------------------------------------------------------- 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
//-----------------------------------------------------------------------------
// Prints the shortest path from one city to another
//----------------------------------------------------------------------------- 
void Graph::shortestPath(int src, string City[], int dest)
{
    set< pair<int, int> > setds; // Creates a set to store vertices 
                                 // that are being prerocessed
 
    vector<int> dist(V, INF); // Create a vector for distances and 
                              // initialize all distances as infinite
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till all shortest distances are finalized
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex and is taken out of the set
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        // The vertex is stored in the second part of the pair (it
        // has to be done this way to keep the vertices
        // sorted (distance must be the first item
        // in the pair)
        int u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //  If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight)
            {
                //  If distance of v is not  then it must be in
                //  our set.
                if (dist[v] != INF)
                {
                    setds.erase(setds.find(make_pair(dist[v], v)));
                }
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    
    cout << endl;
    cout << "The shortest path from " << City[src] << " to "
         << City[dest] << " is " << dist[dest] << " fathoms." << endl;
}
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------- 
int main()
{
    int V = 9;
    int choice = 0;
    int location = 0;
    int destination = 0;

    string City[9] = {"Hogwarts","Mordor","Narnia",
                      "Bikini Bottom","Winterfell","Bat Cave",
                      "Hyperbolic Time Chamber","Fortress of Solitude","Shrek's Swamp"};

    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);


    while (choice != V)
    {
        displayMainMenu(choice, location);
        
        if (choice != V)
        {
            displayMainMenu2(choice, destination);
            if (choice != V)
            {
                g.shortestPath(location, City, destination);
            }
        }
    }
    cout << endl;
    cout << "Program Terminated" <<endl;
    cin >>  choice; //to stop immediate exiting


    return 0;
}
//-----------------------------------------------------------------------------
// Displays first menu and gets the starting location
//----------------------------------------------------------------------------- 
void displayMainMenu(int& choice, int& location)
{
    cout << "*********************************************" << endl;
    cout << "                 Main Menu                   " << endl;
    cout << "*********************************************" << endl;
    cout << "Choose a starting location: " << endl;
    cout << "0) Hogwarts" << endl;
    cout << "1) Mordor" << endl;
    cout << "2) Narnia" << endl;
    cout << "3) Bikini Bottom" << endl;
    cout << "4) Wintefell" << endl;
    cout << "5) Bat Cave" << endl;
    cout << "6) Hyperbolic Time Chamber" << endl;
    cout << "7) Fortress of Solitude" << endl;
    cout << "8) Shrek's Swamp" << endl;    
    cout << "9) EXIT" << endl << endl;
    cout << "Origin: ";
    cin >> choice;
    location  = choice;
}
//-----------------------------------------------------------------------------
// Displays second menu and gets the ending location
//-----------------------------------------------------------------------------
void displayMainMenu2(int& choice, int& destination)
{
    cout << "Destination: ";
    cin >> choice;
    destination = choice;
}
