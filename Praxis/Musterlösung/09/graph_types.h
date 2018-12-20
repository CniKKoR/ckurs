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
    if (v_list[i]) {
      if (v_list[i]->x == x && v_list[i]->y == y) {
        match = v_list[i];
        break;
      }
    }
  }

  return match;
}

// Checks if the supplied vertices a and b are equal.
bool vertex_eq(vertex *a, vertex *b) {
  if (a->x == b->x && a->y == b->y) {
    return true;
  } else {
    return false;
  }
}

// Searches for an edge that is defined by the two vertices to and from within
// the supplied list of edges "e_list".
// e_size denotes the size of e_list.
// If the edge is not in e_list, a NULL-ptr is returned.
edge *search_edge(vertex *from, vertex *to, edge **e_list, size_t e_size) {
  edge *match = (void *)0;

  for (size_t i = 0; i < e_size; ++i) {
    if (vertex_eq(from, e_list[i]->from) && vertex_eq(to, e_list[i]->to)) {
      match = e_list[i];
      break;
    }
  }

  return match;
}

// Search for a specific vertex in an array of vertex pointers and
// return the index for the matching index or UINT_MAX, if the
// vertex isn't contained in the list.
size_t search_index(long x, long y, vertex **v_list, size_t v_size) {
  size_t index = UINT_MAX;

  for (size_t i = 0; i < v_size; ++i) {
    if (v_list[i]) {
      if (v_list[i]->x == x && v_list[i]->y == y) {
        index = i;
      }
    }
  }

  return index;
}

// Check if the supplied array of vertex pointers only contains
// NULL values.
bool vertex_array_all_null(vertex **v, size_t v_count) {
  for (size_t i = 0; i < v_count; ++i) {
    if (v[i]) {
      return false;
    }
  }

  return true;
}

// Get the neighbours of vertex "vert" within a graph "g".
// The array of vertex pointers "neighbours" will be filled accordingly.
// Memory management for neighbours isn't handled by this function.
// The function returns the amount of neighbours that were found.
size_t get_neighbours(vertex **neighbours, vertex *vert, graph *g) {
  size_t insert_count = 0;
  for (size_t i = 0; i < g->e_count; ++i) {
    if (vertex_eq(vert, g->e[i]->from)) {
      neighbours[insert_count] = g->e[i]->to;
      ++insert_count;
    }
  }

  return insert_count;
}

// Finds the shortest path from a vertex "src" to a vertex "dest" in a graph
// "g", by employing Dijkstra's algorithm. It will fill the vertex pointer array
// "shortest_path" accordingly with the vertices that need to be traversed. The
// function returns the amount of defined vertex pointers in shortest_path.
size_t dijkstra(vertex **shortest_path, vertex *src, vertex *dest, graph *g) {
  vertex **q = malloc(sizeof(vertex *) * g->v_count);

  // Set our distance vector to the maximum value long can be.
  // We use this here instead of infinity.
  long *dist = malloc(g->v_count * sizeof(long));
  for (size_t i = 0; i < g->v_count; ++i) {
    q[i] = g->v[i];
    dist[i] = LONG_MAX;
  }

  // All previous vertices are undefined, so NULL-ptrs.
  vertex **prev = calloc(g->v_count, sizeof(vertex *));

  // source vertex has a distance of zero
  dist[search_index(src->x, src->y, q, g->v_count)] = 0;

  while (!vertex_array_all_null(q, g->v_count)) {
    size_t index_of_u = 0;
    long min = LONG_MAX;
    for (size_t i = 0; i < g->v_count; ++i) {
      if (q[i] != 0) {
        if (dist[i] < min) {
          min = dist[i];
          index_of_u = i;
        }
      }
    }

    // get vertex with the least distance (u)
    // and set it to NULL in q
    vertex *u = q[index_of_u];
    q[index_of_u] = (void *)0;

    // get all neighbour vertices of u
    vertex **neighbours_of_u = malloc(sizeof(vertex *) * (g->v_count - 1));
    size_t neighbour_count = get_neighbours(neighbours_of_u, u, g);

    for (size_t i = 0; i < neighbour_count; ++i) {
      vertex *vert_in_q = search_vert(neighbours_of_u[i]->x,
                                      neighbours_of_u[i]->y, q, g->v_count);

      // we have to make sure that the neighbours are still in q
      if (vert_in_q) {
        size_t index_of_v = search_index(
            neighbours_of_u[i]->x, neighbours_of_u[i]->y, g->v, g->v_count);
        edge *edge_u_v = search_edge(u, neighbours_of_u[i], g->e, g->e_count);
        long alt = dist[index_of_u] + edge_u_v->weight;
        if (alt < dist[index_of_v]) {
          dist[index_of_v] = alt;
          prev[index_of_v] = g->v[index_of_u];
        }
      }
    }

    free(neighbours_of_u);
  }

  // construct shortest path from distance matrix
  vertex *u = dest;
  size_t index_of_u = 0;

  if (prev[index_of_u] || !vertex_eq(src, dest)) {
    // this will be our shortest path in reverse
    vertex **shortest_path_rev = malloc(sizeof(vertex *) * g->e_count);
    size_t shortest_path_rev_elems = 0;

    while (u) {
      index_of_u = search_index(u->x, u->y, g->v, g->v_count);
      shortest_path_rev[shortest_path_rev_elems] = u;
      ++shortest_path_rev_elems;
      u = prev[index_of_u];
    }

    // reverse the reversed shortest path to get the shortest path
    size_t shortest_path_elems = 0;
    for (int i = shortest_path_rev_elems - 1; i >= 0; --i) {
      shortest_path[shortest_path_elems] = shortest_path_rev[i];
      ++shortest_path_elems;
    }

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
