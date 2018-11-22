// CSE 101 Winter 2018, PA 2
//
// Name: ZHAOKAI XU
// PID: A14738474
// Sources of Help: BOOK 
// Due: February 9th, 2018 at 11:59 PM
#ifndef __BITVEST_CPP__
#define __BITVEST_CPP__

#include <list>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include "Graph.hpp"
#include "Bitvest.hpp"
using namespace std;
// include more libraries as needed

// helper function to build the graph
template <class T>
void buildGraph(Graph<T>& g, list<Exchange> exchanges) {

	// traverse all edges
    for(auto it=exchanges.begin(); it!=exchanges.end(); it++){
	      
	      string v1 = it->in;
	      string v2 = it->out;
	      float w = it->rate;
	     
	      // create a vertex with a string id 
	      if (g.vertices.count(v1) == 0) {
	      	g.vertices[v1] =  new Vertex<T>(v1);
	      }
	      if (g.vertices.count(v2) == 0) {
	        g.vertices[v2] = new Vertex<T>(v2);
	      }

	      // insert the vertext 
	      g.vertices[v1]->edges.insert(v2);
	      g.set_weight(v1, v2, w);
    }
}

// we want to earn max value
bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
  //TODO: Implement an algorithm to determine if a profitable trade is possible

	//build the graph
	Graph<string> g;
	buildGraph( g, exchanges);

    // //initialization, initialize all vertices distance to min 0.0
    for(auto it = g.vertices.begin(); it != g.vertices.end(); it++)
    {
       it->second->distance = FLT_MAX;
    }

	string src = (exchanges.begin())->out;
    g.vertices[src]->visited = true;
    g.vertices[src]->distance = 0;

    //Relax all edges |V|-1 times repeatly
    for (int i = 1; i < g.vertices.size() ; i++)
    {
        // cout<<endl<<"itr "<< i<<endl;
        for (auto it=exchanges.begin(); it!=exchanges.end(); it++)
        {
            // cout <<"exchanges "<<it->in<< " "<<it->out<<endl;
            string u = it->in;
            string v = it->out;
            float weight = - ( log10(1-fees[u]) + log10(it->rate) + log10(1-fees[v]) );

//            g.vertices[u]->visited == true && 
            // use visted to check if the exchange edge 
            if ( g.vertices[v]->distance != false && g.vertices[u]->distance + weight < g.vertices[v]->distance)
            {
                g.vertices[v]->distance = g.vertices[u]->distance + weight;
                g.vertices[v]->prev = u;
                g.vertices[v]->visited = true;
                // cout<< "update from "<< u << "to "<< v<<endl;
                // cout << g.vertices[v]->distance << " = " <<weight<< "+"<< g.vertices[u]->distance<<endl;
        	}
        }
    }

    for (auto it=exchanges.begin(); it!=exchanges.end(); it++)
    {
        string u = it->in;
        string v = it->out;
        float weight = - ( log10(1-fees[u]) + log10(it->rate) + log10(1-fees[v]) );

        if (g.vertices[u]->distance + weight < g.vertices[v]->distance)
           return true;
    }

    return false;
}
#endif



