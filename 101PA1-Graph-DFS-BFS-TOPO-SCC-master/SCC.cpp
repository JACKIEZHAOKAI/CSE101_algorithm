// CSE 101 Winter 2018, PA 1 
// name:ZHAOKAI XU,		CHEN CHEN
// PID:A14738474  		A53245506
// Sources of help: pesudocode from HW1
// Due: 1/25/2018

#include <stack>
#include <set>
#include <iostream>
#include <string>

#include "Graph.hpp"
using namespace std;


/*
	High level description:
	run DFS on the reverse graph 
		for all vertices in order to decreasing post number
			if not visited
				dfs 
				output nodes in SCC
*/
template <class T>
void findPostdfs(Graph<T>& g, T t, int& count, stack<T> & H_PostNum) {

  //previst the first vertex
  g.vertices[t]->pre = count++;

  // create a stack for DFS
  stack<T> stack;
  stack.push(t);

  while (!stack.empty())
  {
  		//get the front vertex id and insert to set
  		T curr = stack.top();

  		//use the flag to traverse the postvisit
  		bool flag = 0;

  		list<T> edge =(g.vertices[curr]->edges);

  		//check all neighbour vertices of curr
		for ( auto it=edge.begin(); it!=edge.end(); it++)
  		{
  			// check if there is a cycle, keep exploring next neighbour
  			if ( g.vertices[*it]->pre !=0 and g.vertices[*it]->post == 0)
  				continue;

  			// if not globally visited yet
  			if ( g.vertices[*it]->post == 0)
 			{
 				//previst 
 				g.vertices[*it]->pre = count++;
 				//visit and push to stack
				stack.push(*it);
				flag = 1;
				break;
			}
  		}

  		//if the vertices is visited in the dfs
  		if(flag == 0)
  		{
  			H_PostNum.push(curr);  			
  			stack.pop();
  			//postvisit
  			g.vertices[curr]->post = count++;
  		}

  } 

  return;
}

template <class T>
std::set<T>  DFS(Graph<T>& g, T t) {
  std::set<T> res;

  // create a stack for DFS
  stack<T> stack;
  // visit the first vertex and enqueue it 
  g.vertices[t]->visited = true;
  stack.push(t);

  while (!stack.empty())
  {
  		//get the front vertex id and insert to set
  		T curr = stack.top();
  		res.insert(curr);
  		//pop the front 
  		stack.pop();

  		//check all neighbour vertices of curr, 
  		//if not visited, visit and add to stack
  		list<T> edge =(g.vertices[curr]->edges);

  		for ( auto it=edge.begin(); it!=edge.end(); ++it)
  		{
  			if (! (g.vertices[*it]->visited)  )
   			{
  				g.vertices[*it]->visited = true;
  				stack.push(*it);
  			}
  		}
  }
  
  return res;
}


template <class T>
std::list<std::set<T> > scc(Graph<T>& g){
   
    std::list<std::set<T> > sccs;
    // TODO: Implement SCC

    //create a stack for traversing the topo order
	stack<T> H_PostNum;
	//counter for pre and post number 
	int count = 1;

 	//reverse the graph
	Graph<T> reversed_g = g.reverse_graph();
       
	// set the pre and post of all vertices to 0
	for(auto it=reversed_g.vertices.begin();it!=reversed_g.vertices.end();it++)
 	{
 		it->second->pre = it->second->post = 0;
 	}

 	//run dfs for all vertices on the reversed graph
 	//put to stack H_PostNum in decending order of post humber
 	for(auto it=reversed_g.vertices.begin();it!=reversed_g.vertices.end();it++)
 	{
 		if( it->second->post == 0 )	 
 			findPostdfs( reversed_g, it->first , count, H_PostNum);
 		
	}


 	//for all vertices in order to decreasing post number
	//if not visited, run dfs and output nodes in SCC
 	while( !H_PostNum.empty())
 	{	
 		T  id = H_PostNum.top();
 	
 		if ( ! (g.vertices[id]->visited ))
 			sccs.push_back( DFS(g,id) );

 		H_PostNum.pop();
 	}
	
    return sccs;
}




