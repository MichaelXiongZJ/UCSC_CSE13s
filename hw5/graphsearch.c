#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;

  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}

//free the LLint
void set_delete(LLint *set){
  while(set){
    LLint* prev = set;
    set = set->next;
    free(prev);
  }
}

// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
LLPath *enqueue_path(LLPath *q, Path path) {
  // YOUR CODE HERE
  //used class demo as reference
  if(!q){
    LLPath* out = (LLPath*)calloc(1, sizeof(LLPath));
    out->val = path;
    return out;
  }
  LLPath *here = q;
  while (here->next != NULL) {
    here = here->next;
  }
  LLPath* newpath = (LLPath*)calloc(1, sizeof(LLPath));
  newpath->val = path;
  here->next = newpath;
  return q;
}

//enqueue but for dfs, add element to the top instead of bottom
LLPath *enqueue_dfs_path(LLPath *q, Path path) {
  // YOUR CODE HERE
  //used class demo as reference
  if(!q){
    LLPath* out = (LLPath*)calloc(1, sizeof(LLPath));
    out->val = path;
    return out;
  }
  LLPath* newfront = (LLPath*)calloc(1, sizeof(LLPath));
  newfront->val = path;
  newfront->next = q;
  return newfront;
}

bool dequeue_path(LLPath **q, Path *ret) {
  // YOUR CODE HERE
  //used class demo as reference
  if(!q || !(*q)){
    return false;
  }
  *ret = (*q)->val;
  LLPath *freeme = *q;
  *q = (*q)->next;
  free(freeme);
  return true;
}

// We wrote these in class.
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int *));
  for (int i = 0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

//free the Graph
void graph_delete(Graph **g){
  for(int i = (*g)->vertices - 1; i >= 0; i--){
    free((*g)->matrix[i]);
  }
  free((*g)->matrix);
  free(*g);
  *g = NULL;
}

void graph_add_edge(Graph *g, int i, int j) { g->matrix[i][j] = 1; }

bool graph_has_edge(Graph *g, int i, int j) { return g->matrix[i][j]; }

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;

  for (int i = 0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)");
  }
  for (int i = 0; i < path.steps; i++) {
    printf("%s%d", (i == 0) ? "" : " -> ", path.vertices_visited[i]);
  }
  puts("");
}

//free the LLPath
void path_delete(LLPath *llpath){
  while (llpath != NULL){
    Path temp;
    dequeue_path(&llpath, &temp);
  }
}


// Breadth-first search!
Path graph_find_path_bfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  //used class demo as reference
  LLint *visited = NULL;
  LLPath *to_visit = NULL;  

  Path init = {1, {i}};
  to_visit = enqueue_path(to_visit, init);

  while (to_visit != NULL) {
    Path current;
    dequeue_path(&to_visit, &current);

    //PATH FOUND
    if(current.vertices_visited[current.steps-1] == j){
      set_delete(visited);
      path_delete(to_visit);
      return current;
    }
    visited = add_to_set(visited, current.vertices_visited[current.steps-1]);
    for(int j = 0; j < g->vertices; j++){
      if(graph_has_edge(g, current.vertices_visited[current.steps-1], j)){
        if(!set_contains(visited, j)){
          Path temp = path_extend(current, j);
          to_visit = enqueue_path(to_visit, temp);
        }
      }
    }
  }
  //PATH NOT FOUND
  set_delete(visited);
  path_delete(to_visit);
  Path nullpath = {0};
  return nullpath;
}

// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  LLint *visited = NULL;
  LLPath *to_visit = NULL;  

  Path init = {1, {i}};
  to_visit = enqueue_dfs_path(to_visit, init);

  while (to_visit != NULL) {
    Path current;
    dequeue_path(&to_visit, &current);
    
    //PATH FOUND
    if(current.vertices_visited[current.steps-1] == j){
      set_delete(visited);
      path_delete(to_visit);
      return current;
    }
    visited = add_to_set(visited, current.vertices_visited[current.steps-1]);
    for(int j = 0; j < g->vertices; j++){
      if(graph_has_edge(g, current.vertices_visited[current.steps-1], j)){
        if(!set_contains(visited, j)){
          Path temp = path_extend(current, j);
          to_visit = enqueue_dfs_path(to_visit, temp);
        }
      }
    }
  }
  //PATH NOT FOUND
  set_delete(visited);
  path_delete(to_visit);
  Path nullpath = {0};
  return nullpath;
}
