// CSE 101 Winter 2018, PA 1 
// name:ZHAOKAI XU,   CHEN CHEN
// PID:A14738474      A53245506
// Sources of help: pesudocode from HW1
// Due: 1/25/2018


#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
using namespace std;

template <class T>
std::set<T> bfs(Graph<T>& g, T t) {
  std::set<T> res;

  // create a queue for BFS
  queue<T> queue;
  // visit the first vertex and enqueue it 
  g.vertices[t]->visited = true;
  queue.push(t);


  while (!queue.empty())
  {
  		//get the front vertex id and insert to set
  		T curr = queue.front();
  		res.insert(curr);
  		//pop the front 
  		queue.pop();

  		//check all neighbour vertices of curr, 
  		//if not visited, visit and add to queue
  		list<T> edge =(g.vertices[curr]->edges);

  		for ( auto it=edge.begin(); it!=edge.end(); ++it)
  		{
  			if (! (g.vertices[*it]->visited)  )
   			{
  				g.vertices[*it]->visited = true;
  				queue.push(*it);
  			}
  		}
  }
  
  return res;
}

