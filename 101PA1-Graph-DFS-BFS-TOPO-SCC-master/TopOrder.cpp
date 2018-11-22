// CSE 101 Winter 2018, PA 1 
// name:ZHAOKAI XU,		CHEN CHEN
// PID:A14738474  		A53245506
// Sources of help: pesudocode from HW1
// Due: 1/25/2018

#include "Graph.hpp"
// include more libraries as needed
#include <map>
#include <stack>
#include <list>
#include <iostream>
using namespace std;

/*
	High level description:
	call dfs for all vertices that has not been visited
	traversing using pre and post, put the vertices with highest post
	number to the topoStack
	if the pre and post both existed, that means the vertex 
	has been globally visited
	pop the topoStack and this will be the topo order 
*/
template <class T>
bool dfs(Graph<T>& g, T t, int& count, stack<T> & topoStack) {

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
  			// check if there is a cycle 
  			// if it only has the pre number but no post number, 
  			// which means already visited, then cycle
  			if ( g.vertices[*it]->pre !=0 and g.vertices[*it]->post == 0)
  					return true;

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
  			topoStack.push(curr);  			
  			stack.pop();
  			//postvisit
  			g.vertices[curr]->post = count++;
  			//cerr << curr<<" pre "<< g.vertices[curr]->pre<<" post "<<g.vertices[curr]->post<<endl;
  		}
  } 

  return false;
}


template <class T>
std::list<T> top_order(Graph<T>& g) {
  
  	std::list<T> res;
 	// TODO: Implement TopOrder
 	
 	//create a stack for traversing the topo order
	stack<T> topoStack;
	//counter for pre and post number 
	int count = 1;

	// set the pre and post of all vertices to 0
	for(auto it=g.vertices.begin();it!=g.vertices.end();it++)
 	{
 		it->second->pre = it->second->post = 0;
 	}
 
 	//run dfs for all vertices that has not been globally visited yet
 	for(auto it=g.vertices.begin();it!=g.vertices.end();it++)
 	{
 		if( it->second->post == 0 )	 
 		{
 			// calling dfs  
 			bool hasCycle = dfs( g, it->first , count, topoStack);
			// if there is a cycle, it is not a DAG, so return empty set
	 		if (hasCycle)
	 			return res;
 		}
 	}

 	// put number from stack to res
 	while(!topoStack.empty())
 	{
 		res.push_back(topoStack.top());
 		topoStack.pop();
 	}

  return res;
}








