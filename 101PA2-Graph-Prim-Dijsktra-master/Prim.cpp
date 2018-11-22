// CSE 101 Winter 2018, PA 2
//
// Name: ZHAOKAI XU
// PID: A14738474
// Sources of Help: BOOK 
// Due: February 9th, 2018 at 11:59 PM

#ifndef __PRIM_CPP__
#define __PRIM_CPP__

#include "Graph.hpp"
#include <queue>
#include <set>
#include <vector>
using namespace std;

// Redefine distance to be the cost of each vertex
template <class T>
float prim(Graph<T>& g, T src) {

	// TODO: Implement Prim's Algorithm
	float totalCost = 0.0;
	g.vertices[src]->distance = 0;
	g.vertices[src]->visited = true;

	// apply the alarm class. 
	// for each neighbor v of source:  // add all initial edges to Q                   
	// 	      Q.add(Alarm(source, v, weight(source->v)))
	priority_queue <Alarm<T>,vector<Alarm<T>>> toExplore;
	for(auto it=g.vertices[src]->edges.begin(); it!=g.vertices[src]->edges.end(); it++)
	{
		Alarm<T> alarm(src, *it, g.get_weight(src,*it));
		toExplore.push(alarm);
	}


	while ( !toExplore.empty() ) {

		//visit the dest of the top alarm in PQ
		Alarm<T> curr_alarm = toExplore.top();
		toExplore.pop();

		if (g.vertices[curr_alarm.dest]->visited == false)
		{
			//visit the vertex and update prev and dist of curr's neighbours
			g.vertices[curr_alarm.dest]->visited = true;
			g.vertices[curr_alarm.dest]->prev = curr_alarm.src;
			g.vertices[curr_alarm.dest]->distance = (g.vertices[curr_alarm.src]->distance) 
			+ g.get_weight(curr_alarm.src, curr_alarm.dest);

			//calculate total cost of the Min Spanning tree, by adding the weight
			totalCost += g.get_weight(curr_alarm.src, curr_alarm.dest);

			for (auto it = (g.vertices[curr_alarm.dest]->edges).begin(); 
				it != (g.vertices[curr_alarm.dest]->edges).end(); ++it)
			{	 
				// calculate the cost, store as time in alarm in PQ
				float time =  g.get_weight(curr_alarm.dest, *it);
				Alarm<T> mext_alarm = Alarm<T>(curr_alarm.dest, (*it), time);
				toExplore.push(mext_alarm);
			}
		}
	} 

	return totalCost;
}

#endif
