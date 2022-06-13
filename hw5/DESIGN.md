enqueue
    similiar to class demo, allocate a new LLPath if q is null, puts the path into it and return. If q is not null, then append the linked list by putting it in the bottom and return.

dequeue
    also similiar to class demo, return false if node is null, and puts the first element into to *ret and free the memory.

BFS
    as the given persudo code:
        keep a set of vertices that we have visited
        keep a queue of vertices that we want to visit
        put the starting vertex into the queue
        while there are more places to visit in the queue:
            dequeue the next place to visit
            see if it is our intended destination -- if it is, return success!
            otherwise, make sure it is in the set of visited nodes
            enqueue each of its neighbors that have not been visited
        return false if the queue becomes empty (we ran out of options)

DFS
    similiar design as BFS but the queue will be made in different order. (on top instead of bottom)

List of helper funcitons
    set_delete()
    path_delete()
    graph_delete()