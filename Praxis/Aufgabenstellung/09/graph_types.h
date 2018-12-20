#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex {
  long x;
  long y;
} vertex;

typedef struct edge {
  vertex *from;
  vertex *to;
  long weight;
} edge;

typedef struct graph {
  size_t v_count;
  size_t e_count;
  vertex **v;
  edge **e;
} graph;

// Search for a specific vertex in an array of vertex pointers.
// Returns pointer to the vertex in question if it exists - if it doesn't
// it returns a NULL-ptr.
vertex *search_vert(long x, long y, vertex **v_list, size_t v_size) {
  vertex *match = (void *)0;

  for (size_t i = 0; i < v_size; ++i) {
    if(v_list[i]) {
      if (v_list[i]->x == x && v_list[i]->y == y) {
        match = v_list[i];
        break;
      }
    }
  }

  return match;
}

// Compares two given vertex pointers
// whether they are representing the same vertex
// Returns true if they do, otherwise false
bool vertex_eq(vertex *a, vertex *b) {
  // TODO:
}

// Searches for an edge in an given array of pointers representing edges
// between two vertices given as pointer
// Returns the pointer of the edge in question if it exists -
// If it doesn't, it returns a NULL-ptr
edge *search_edge(vertex *from, vertex *to, edge **e_list, size_t e_size) {
  // TODO:
}

// Search for a specific vertex in an array of vertex pointers and
// return the index for the matching index or UINT_MAX, if the
// vertex isn't contained in the list.
size_t search_index(long x, long y, vertex **v_list, size_t v_size) {
  // TODO:
}


// Checks if all pointers in an given array of vertex pointers
// are NULL, if they are return true, otherwise false
bool vertex_array_all_null(vertex **v, size_t v_count) {
  // TODO:
}

// Searches for all neighbours of a vertex given as pointer
// in a graph also given as pointer, puts all neighbours in the
// given arrays of vertex pointers and returns the number of
// neighbours of this specific vertex
size_t get_neighbours(vertex **neighbours, vertex *vert, graph *g) {
  // TODO:
}

size_t dijkstra(edge **shortest_path, vertex *src, vertex *dest, graph *g) {
  // setup an arrays of vertex pointers as a queue
  vertex **q = malloc(sizeof (vertex *) * g->v_count);

  // Set our distance vector to the maximum value long can be.
  // We use this here instead of infinity.
  long *dist = malloc(g->v_count * sizeof(long));
  // TODO: fill array (dist) with "infinite" distances
  // TODO: put vertex pointer into the queue (q)

  // All previous vertices are undefined, so NULL-ptrs.
  vertex **prev = calloc(g->v_count, sizeof(vertex *));

  // source vertex has a distance of zero
  // TODO: set source distance to zero

  // repeat algorithm
  // stop when all pointers in the queue are NULL-ptr
  while (!vertex_array_all_null(q, g->v_count)) {
    // get vertex with the least distance (u)
    size_t index_of_u = 0;
    long min = LONG_MAX;
    // TODO: search for the index of the vertex in q with the shortest distance

    // and set it to NULL in q
    vertex *u = q[index_of_u];
    q[index_of_u] = (void *)0;

    // get all neighbours of vertex u
    vertex **neighbours_of_u = (void *)0;
    size_t neighbour_count = get_neighbours(neighbours_of_u, u, g);

    // calculate the distance to all neighbours of u
    // if it is shorter set the new distance to the new value
    // and make the previous vertex of this neighbour u
    for (size_t i = 0; i < neighbour_count; ++i) {
      size_t index_of_v = search_index(neighbours_of_u[i]->x,
                                       neighbours_of_u[i]->y, g->v, g->v_count);
      edge *edge_u_v = search_edge(u, neighbours_of_u[i], g->e, g->e_count);
      long alt = dist[index_of_u] + edge_u_v->weight;
      if (alt < dist[index_of_v]) {
        dist[index_of_v] = alt;
        prev[index_of_v] = g->v[index_of_u];
      }
    }

    free(neighbours_of_u);
  }

  // construct shortest path from distance matrix
  vertex *u = dest;
  size_t index_of_u = search_index(dest->x, dest->y, g->v, g->v_count);

  if (prev[index_of_u] != 0 || !vertex_eq(src, dest)) {
    vertex **shortest_path_rev = malloc(sizeof(vertex *) * g->e_count);
    size_t shortest_path_rev_elems = 0;

    while (u != 0) {
      // TODO: construct the path in reversed order
    }

    shortest_path = malloc(sizeof(edge *) * (shortest_path_rev_elems - 1));
    size_t shortest_path_elems = 0;
    // TODO: reverse the order and construct the actual path


    free(shortest_path_rev);
    free(dist);
    free(q);
    return shortest_path_elems;
  } else {
    shortest_path = (void *)0;
    free(dist);
    free(q);
    return 0;
  }
}
