/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

template <typename V, typename E, typename W>
bool reachableDFS(V src, V dest, Graph<V, E, W>* g) {
    STLStack<V> stacked;
    STLHashTable<V, bool> beenTo;
    stacked.push(src);
    while(stacked.isEmpty() == false) {
        V now = stacked.pop();
        if (now == dest) {
            return true;
        }

        vector<V> adjacentList = g->getNeighbors(now);
            for(int i=0; i<adjacentList.size(); i++){
                if (!beenTo.contains(adjacentList[i])) {
                        beenTo.insert(adjacentList[i], true);
                        stacked.push(adjacentList[i]);
                    }
            }

    }
    return false;
}

template <typename V, typename E, typename W>
vector<V> shortestLengthPathBFS(V src, V dest, Graph<V, E, W>* g) {
    vector<V> pathCurr;
    STLQueue<V> q;
    STLHashTable<V,V> prev;
    V curr;
    bool connected = false;

    prev.insert(src, src);
    q.enqueue(src);

    while(q.isEmpty() == false){
            curr = q.dequeue();

        if (curr == dest){
            connected = true;
            V currNodePath;
            currNodePath = dest;
            STLStack<V> stacked;
            stacked.push(dest);
                while (currNodePath != src){
                    stacked.push(prev.get(currNodePath));
                }

                while(stacked.isEmpty() == false){
                    pathCurr.push_back(stacked.pop());
                }
            return pathCurr;

        }
        vector<V> adjacent = g->getNeighbors(curr);
        for(int i=0; i<adjacent.size(); i++){
            if(!prev.contains(adjacent[i])){
                prev.insert(adjacent[i], curr);
                q.enqueue(adjacent[i]);
            }
        }
    }
    if(connected == false){
            throw runtime_error("Unable to connect");
        }
    return pathCurr;
}


template <typename V, typename E, typename W>
Dictionary<V, W>* singleSourceShortestPath(V src, Graph<V, E, W>* g) {
    Dictionary<V, W>* weight = new STLHashTable<V, W>();
    STLMinPriority<W,V>* priorQ = new STLMinPriorityQueue<W, V> ();

    weight->insert(src, 0);
    priorQ->insert(0, src);

    while(priorQ.isEmpty() == false){
        int priorityNow = priorQ->peekPriority();
        V vertexNow = priorQ->remove();
        int currWeight = weight->get(vertexNow);

        if (currWeight == priorityNow){
            vector<Edge<V, E, W>> outgoingEdges = g->getOutgoingEdges(vertexNow);

           for(int i=0; i< outgoingEdges.size(); i++){
                V nextVertex = outgoingEdges[i].getDestination();
                int newWeight = currWeight + outgoingEdges[i].getWeight();
                    if(!weight->contains(nextVertex)){
                        weight->insert(nextVertex, newWeight);
                        priorQ->insert(newWeight, nextVertex);
                    }
                    else if(newWeight<weight->get(nextVertex)){
                        weight->update(nextVertex, newWeight);
                        priorQ->insert(newWeight, nextVertex);
                    }

           }

        }
    }

return weight;
}
