// CSE 101 Winter 2018, PA 1 
// name:ZHAOKAI XU,		CHEN CHEN
// PID:A14738474  		A53245506
// Sources of help: pesudocode from HW1
// Due: 1/25/2018

#include "Graph.hpp"
#include <stack>
#include <iostream>
#include <map>
#include <list>
#include <set>

using namespace std;

template <class T>
std::set<T> dfs(Graph<T>& g, T t) {
  std::set<T> res;

  // TODO: Implement DFS
  
  int count = 1;
  // visit the first vertex 
  g.vertices[t]->visited = true;
  
  //previst
  g.vertices[t]->pre = count++;

  // create a stack for DFS
  stack<T> stack;
  stack.push(t);

  while (!stack.empty())
  {
  		//get the front vertex id and insert to set
  		T curr = stack.top();
  		res.insert(curr);

  		//use the flag to traverse the postvisit
  		bool flag = 0;

  		list<T> edge =(g.vertices[curr]->edges);

  		//check all neighbour vertices of curr
		for ( auto it=edge.begin(); it!=edge.end(); it++)
  		{
  			if (! (g.vertices[*it]->visited) )
 			{
 				//previst 
 				g.vertices[*it]->pre = count++;

 				//visit and push to stack
				g.vertices[*it]->visited = true;
				stack.push(*it);

				flag = 1;
				break;
			}
  		}
  		//if the vertices is visited
  		if(flag == 0)
  		{
  			stack.pop();
  			//postvisit
  			g.vertices[curr]->post = count++;
  		}
  }

  // for (auto it = g.vertices.begin(); it!=g.vertices.end();it++)
  // {
  // 		cout<<"id "<<it->second->id<<" pre"<< it->second->pre <<" post" <<it->second->post<<endl;
  // }

  return res;
}

