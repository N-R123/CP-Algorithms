#include <bits/stdc++.h>
using namespace std;


class Edge
{     public:
	int startV;                                       // starting vertex of edge (v1)     
	int endV;                                         // ending vertex of edge (v2)        
	int weight;                                       // weight of edge                  
};

Edge* storeInputGraph(int nE)
{
	Edge *arr = new Edge[nE];                         // creating edge class array              
 
	for(int i=0; i<nE; i++)                           // taking input 
	{  int v1, v2, w;
	   cin>>v1>>v2>>w;                             
	   arr[i].startV = v1;                            // arr[i] = current edge of input graph          
	   arr[i].endV = v2;
	   arr[i].weight = w;  }
	
	return arr;
}

bool compare(Edge e1, Edge e2)
{   return (e1.weight < e2.weight);   }

int findRootParent(int currV, int *parentV)
{
	if(currV==parentV[currV])
	return currV;
	
	int r = findRootParent(parentV[currV], parentV);
	
	return r;
}

void findingMST_usingKruskalsAlgo(Edge *arr, int nV, int nE)
{
	sort(arr, arr+nE, compare);                       // i.e. sort "Edge class array arr" on the basis of "weights" using "compare function"
	Edge *arr_MST = new Edge[nV-1];
	
	int *parentV = new int[nV];                       // to apply union find approach       
	for(int i=0; i<nV; i++)
	parentV[i] = i;
	
	for(int nE_MST=0,i=0;  nE_MST!=nV-1;  i++)        // check if we can add current edge in MST (connected & no cycle) or not      
	{                                                 // arr[i] = current edge of input graph      
	   int startV_rp = findRootParent(arr[i].startV, parentV);   
	   int endV_rp = findRootParent(arr[i].endV, parentV); 
		                                                  
	   if(startV_rp != endV_rp)                       // arr_MST[i] = current edge of input graph               
	   {  arr_MST[nE_MST] = arr[i];                   // nE_MST = current no of edges in MST   
	      nE_MST++;
	      parentV[startV_rp] = endV_rp;  }
	} 
 
    cout<<"\nMST:"<<endl;                                                  
	for(int i=0; i<nV-1; i++)
	{   
	    if(arr_MST[i].startV < arr_MST[i].endV)       // printing smalller vertex first                   
	    cout<<arr_MST[i].startV<<" "<<arr_MST[i].endV<<" "<<arr_MST[i].weight<<endl;
	    else 
		cout<<arr_MST[i].endV<<" "<<arr_MST[i].startV<<" "<<arr_MST[i].weight<<endl; 
	} 
}


// considering edge value arr[i][j] = distance between vertex i & j                                        
// to print final MST, we wil use concept of parent vertex (printing by travelling from last vertex)   
// (weight = value of edge) (distance[i] = distance of vertex 'i' from its parentVertex / itsNearestVertex whichIsAlreadyVisited)                                   
                                                                                       
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                          // creating adjacency matrix                            
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                            // storing weighted graph                     
	{  int v1, v2, weight;
	   cin>>v1>>v2>>weight;
	   arr[v1][v2] = weight;
	   arr[v2][v1] = weight;  }
	
	return arr;
}
 
int minDistance_unvisitedVertex(int *distance, bool *visitedV, int nV)
{
	int minV = -1;
	
	for(int i=0; i<nV; i++)
	{  if(!visitedV[i] && (minV==-1 || distance[i]<distance[minV]))
       minV = i;  }
	
	return minV;
}

void findingMST_usingPrimsAlgo(int **arr, int nV)
{ 
	int *parentV = new int[nV];                        // parentVertex / nearestVertexFromVertex'i' whichIsAlreadyVisited               
	for(int i=0; i<nV; i++)
	parentV[i] = -1;
	
	int *distance = new int[nV];                       // distance[i] = distanceOfVertex'i' from parentVertex / nearestVertex whichIsAlreadyVisited
	for(int i=0; i<nV; i++)
	distance[i] = INT_MAX;                             // initially parentVertex of each vertex is at infinity 

	bool *visitedV = new bool[nV];                     // vertex 'i' is already visited or not                                    
	for(int i=0; i<nV; i++)
	visitedV[i] = false;
	                                                                                                                                                                
	distance[0] = 0;                                   // starting the traversal for MST from vertex 0                          
	parentV[0] = -1;
	for(int i=0; i<nV; i++)
	{                                                  // find unvisited nearestVertex                                                                                       
	   int minV = minDistance_unvisitedVertex(distance, visitedV, nV);
	   visitedV[minV] = true;                            
		                                                                                
	   for(int j=0; j<nV; j++)                         // making minVertex as parent of unvisited neighbourVertices if itIsNearestToThem  
	   {  if(arr[minV][j]==0 || visitedV[j])
	      continue;
		                                  
		  if(arr[minV][j] < distance[j])
		  {  parentV[j] = minV;
		     distance[j] = arr[minV][j];  }
	   }
	} 
 
    cout<<"\nMST:"<<endl;
	for(int i=1; i<nV; i++)                                 
	{   
	    if(parentV[i] < i)                             // printing smaller vertex first  
	    cout<<parentV[i]<<" "<<i<<" "<<distance[i]<<endl;
	    else 
		cout<<i<<" "<<parentV[i]<<" "<<distance[i]<<endl; 
	} 
}
 
#include<bits/stdc++.h>
using namespace std;


/*

Disjoint Set Algo / Union Find Algo
*considering index no of array elements {0,1,2...n-1} as vertices 
*dividing all vertices into some CCs, after merging sameValueIndexNoVerticesIntoOneCC
*ds[i] = index no of parent vertex (if'i'isNonRootNodeOfItsCC)
*ds[i] = -ve of no of vertices in its CC (if'i'isRootNodeOfItsCC)

ds = disjoint set
CC = Connected Component

*/


int ds[1000001];


int findRootParent(int i)
{
    if(ds[i] < 0) 
    return i;
    
    return findRootParent(ds[i]);
}


void mergeCCs(int i, int j)       // merging smaller CC with larger CC
{
    int iN=abs(ds[i]), jN=abs(ds[j]);
    
    if(iN > jN) 
    {   ds[i] = -(iN+jN);
        ds[j] = i;   }
    else
    {   ds[j] = -(iN+jN);
        ds[i] = j;   }
}


int main()
{
    int t;
    cin>>t;
    
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        memset(ds, -1, sizeof(ds)); 
        vector<pair<int,int>> v;     // stores CC pairs betweenWhichValueDifferenceShouldBe'1'  
        
        while(m--)
        {
            int i,j,c;
            cin>>i>>j>> c;
            --i; --j;
            
            int iRP = findRootParent(i);
            int jRP = findRootParent(j);
            
            if(c==1)                 // input'c==1' soDifferenceBetweenCC'iRP'andCC'jRP' shouldBe'1' 
            v.push_back({iRP, jRP});
            else if(c==0 && iRP==jRP) 
            continue; 
            else if(c==0 && iRP!=jRP) 
            mergeCCs(iRP,jRP);       // input'c==0' soMergeCC'iRP'andCC'jRP' ifTheyAreDifferent
        }
        
        
        int flag = 1;
        for(auto CC : v)
        {
            int i=CC.first, j=CC.second;
        
            int iRP = findRootParent(i);
            int jRP = findRootParent(j);
  
            if(iRP == jRP)           // ifAfterAllInput'c==0' theseBelongsToSameCC thenContradiction
            {   flag = 0;
                break;   }
        }
        
        if(flag==1)
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    } 
}


// valid only for +ve edge value graph  
// considering edge value arr[i][j] = distance between vertex i & j                                        
// (weight = value of edge) (distance[i] = distance of vertex 'i' from its parentVertex which is vertex 0 here) 
// minDistance between i & j = minDistanceOfVertex'i'FromVertex'0' - minDistanceOfVertex'j'FromVertex'0'                                   
                                                                                         
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                               // creating adjacency matrix  
	for(int i=0; i<nV; i++)  
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                 // storing weighted graph    
	{  int v1, v2, weight;
	   cin>>v1>>v2>>weight;
	   arr[v1][v2] = weight;
	   arr[v2][v1] = weight;  }
	
	return arr;
}
                                  
int minDistance_unvisitedVertex(int *distance, bool *visitedV, int nV)                 
{                                                           // calculating minDistance of eachVertex from vertex 0   
	int minV = -1;
	
	for(int i=0; i<nV; i++)
	{  if(!visitedV[i] && (minV==-1 || distance[i]<distance[minV]))
       minV = i;  }
	
	return minV;
}

void findingMinDistance_usingDijkstraAlgo(int **arr, int nV)
{  
	int *distance = new int[nV];                            // distance[i] = minDistanceOfVertex'i'FromVertex'0'   
	for(int i=0; i<nV; i++)
	distance[i] = INT_MAX;                                  // initially distance of vertex 'i' from vertex 0  is oo 

	bool *visitedV = new bool[nV];                          // vertex 'i' is already visited or not    
	for(int i=0; i<nV; i++)
	visitedV[i] = false;
	
	distance[0] = 0; 
	for(int i=0; i<nV; i++)
	{                                                       // find unvisited nearestVertex    
	   int minV = minDistance_unvisitedVertex(distance, visitedV, nV);
	   visitedV[minV] = true;
		   
	   for(int j=0; j<nV; j++)                              // exploring unvisited neighbourVertices of minVertex (which are connected to min vertex)  
	   {  if(arr[minV][j]==0 || visitedV[j])
	      continue;
		                                  
		  if(distance[minV] + arr[minV][j] < distance[j])
		  distance[j] = distance[minV] + arr[minV][j];  } 
	}                                                       // if distanceOf'j'via'minV' is least then update minDistanceOf'j'From'0'               
 
    cout<<"\n i  distance[i]"<<endl;
	for(int i=0; i<nV; i++)
	cout<<" "<<i<<"      "<<distance[i]<<endl; 
 
	delete [] visitedV;
	delete [] distance;
}
      
/* 
 
Considering (arr[i].weight) = distance between vertex (arr[i].startV) & (arr[i].endV)                          
distance[i] = minDistanceOfVertex'i'FromVertex'0'

Iteration0: distance[i]Of(0'sNeighbours)WillBeUpdated,  
Iteration1: distance[i]Of(0'sNeighbours + 0'sNextNeighbours)WillBeUpdated 
Iteration2: distance[i]Of(0'sNeighbours + 0'sNextNeighbours + 0'sNextToNextNeighbours)WillBeUpdated 
Iteration3: distance[i]Of(0'sNeighbours + 0'sNextNeighbours + 0'sNextToNextNeighbours + 0'sNextToNextToNextNeighbours)WillBeUpdated 
    .                           .
    .                           .
	.                           .
    .                           .
    .                           .
    
(INT_MAX + integer) willCauseMemoryOverflow thatsWhyWeAreChecking (distance[v1]!=INT_MAX)
ifGraphContainsNegativeEdgeCycle thenShortestPathFindingAlgorithmsWillNotWork         
ifAfterRunningOneMoreIterationOf'j' distance[i]OfAnyVertexVaries thenItMeansGraphContainsNegativeEdgeCycle [MethodToDetectNegativeEdgeCycle]      
    
*/                               
                        
                                
class Edge                                                    // node of EdgeList  
{     public:
	int startV;                                               // starting vertex of edge (v1)     
	int endV;                                                 // ending vertex of edge (v2)        
	int weight;                                               // weight of edge                  
};


void findingMinDistance_usingBellmanFordAlgo(int nV, int nE, Edge *arr)
{                                                             // calculating minDistance of eachVertex from vertex 0  
	int *distance = new int[nV];                            
	for(int i=0; i<nV; i++)                             
	distance[i] = INT_MAX;                                    // initially distance of vertex 'i' from vertex 0  is oo 
	 
	 
	distance[0] = 0;   
	
	for(int i=0; i<nV; i++)                                   // In'i'thIterationOnAll'nE'Edges, pathUsingAtmost'i'EdgesWillBeConsidered
	{
		for(int j=0; j<nE; j++)                             
		{
			int v1 = arr[j].startV;
			int v2 = arr[j].endV;
			int w = arr[j].weight;
			
			if((distance[v1]!=INT_MAX) && ((distance[v1] + w) < distance[v2]))
			distance[v2] = distance[v1] + w;                 
		}
	}
	 
	for(int i=0; i<nV; i++)
    cout << distance[i] << endl; 
}

      
/*

using DP
valid for directed graph having +ve/0/-ve edge values
considering edge value arr[i][j] = distance between vertex i & j                                        
(weight = value of edge) (distance[i] = distance of vertex 'i' from its parentVertex which is vertex 0 here) 
minDistance between i & j = minDistanceOfVertex'i'FromVertex'0' - minDistanceOfVertex'j'FromVertex'0'     
distance[i][j] = minDistanceBetweenVertex'i'AndVertex'j'

(INT_MAX + integer) willCauseMemoryOverflow thatsWhyWeAreChecking (distance[i][k]!=INT_MAX) & (distance[k][j]!=INT_MAX)                                            
keep for loop of k on top, otherwise error, bczThen updationOf'k'AsIntermediateVertexForAll'i'&'j' in'k'thIteration 

*/                              
                                         
                                                                                                            
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                    // creating adjacency matrix  
	for(int i=0; i<nV; i++)  
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = INT_MAX;	}                  // directed graph
	
	for(int i=0; i<nE; i++)                      // storing weighted graph    
	{  int v1, v2, weight;
	   cin>>v1>>v2>>weight;
	   arr[v1][v2] = weight;  }                 
	
	return arr;
}
      
                           
void findingMinRelativeDistance_usingFloydWarshallAlgo(int **arr, int nV)
{
	int **distance = new int*[nV];
	for(int i=0; i<nV; i++)
	{   distance[i] = new int[nV];
	 
	 	for(int j=0; j<nV; j++)
	 	{   if(i==j)
            distance[i][j] = 0;
            else
		    distance[i][j] = arr[i][j];   }      // initially (minDistanceBetween'i'And'j' = EdgeValue'arr[i][j]')
    }
	                                                                                     
	for(int k=0; k<nV; k++)                      // considering'k'AsIntermediateVertex updatingMinDistanceBetweenAll'i'&'j' 
	{   for(int i=0; i<nV; i++)                  // keep for loop of k on top, otherwise error 
    	{	for(int j=0; j<nV; j++)            
	    	{ 
		     	if((distance[i][k]!=INT_MAX) && (distance[k][j]!=INT_MAX) && ((distance[i][k] + distance[k][j]) < distance[i][j]))
		    	distance[i][j] = distance[i][k] + distance[k][j];
		    }
		}
	}
	                                                                            
				                                                                                     
	for(int i=0; i<nV; i++)
	{   for(int j=0; j<nV; j++)
		{
			if(distance[i][j]==INT_MAX)
			cout<<"INF ";                        // INF = infinity
			else
			cout<<distance[i][j]<<" ";
		} 
		cout<<endl;
	} 
}





 
