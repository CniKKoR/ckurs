#include <stdio.h>
#include <stdlib.h>

#include "csvparser.h"
#include "graph_types.h"

int main() {
  CsvParser *csvparser = CsvParser_new("v.csv", ",", 1);
  CsvRow *row = (void *)0;

  // i will count the amount of verticies.
  size_t i = 0;
  vertex **v_list = malloc(sizeof(vertex *) * 32);
  while ((row = CsvParser_getRow(csvparser))) {
    char **rowFields = CsvParser_getFields(row);

    // We have to allocate v with malloc, as it otherwise would be deallocated
    // when going out of scope at the end of the while loop.
    vertex *v = malloc(sizeof(vertex));

    // convert strings retrieved from csv file to longs
    v->x = strtol(rowFields[0], NULL, 10);
    v->y = strtol(rowFields[1], NULL, 10);
    v_list[i] = v;

    CsvParser_destroy_row(row);
    ++i;
  }
  CsvParser_destroy(csvparser);

  CsvParser *csvparser2 = CsvParser_new("e.csv", ",", 1);

  // j will count the amount of edges.
  size_t j = 0;
  edge **e_list = malloc(sizeof(edge *) * 64);
  while ((row = CsvParser_getRow(csvparser2))) {
    char **rowFields = CsvParser_getFields(row);
    edge *e = malloc(sizeof(edge));

    // We want to avoid the duplication of information.
    // As we already have a list of verticies, we don't have
    // to store them again - instead we simply store a pointer
    // for the verticies.
    long x1 = strtol(rowFields[0], NULL, 10);
    long y1 = strtol(rowFields[1], NULL, 10);
    // Search for the pointer to the corresponding vertex in v_list.
    vertex *v1 = search_vert(x1, y1, v_list, i);
    long x2 = strtol(rowFields[2], NULL, 10);
    long y2 = strtol(rowFields[3], NULL, 10);
    vertex *v2 = search_vert(x2, y2, v_list, i);

    long weight = strtol(rowFields[4], NULL, 10);

    e->from = v1;
    e->to = v2;
    e->weight = weight;
    e_list[j] = e;

    CsvParser_destroy_row(row);
    ++j;
  }

  CsvParser_destroy(csvparser2);

  graph g = (graph){
      .v_count = i,
      .e_count = j,
      .v = v_list,
      .e = e_list,
  };

  for (size_t i = 0; i < g.v_count; ++i) {
    printf("Vert%zu: (%li, %li)\n", i, g.v[i]->x, g.v[i]->y);
  }

  for (size_t i = 0; i < g.e_count; ++i) {
    printf("Edge%zu: (%li, %li) -> (%li, %li)\n", i, g.e[i]->from->x,
           g.e[i]->from->y, g.e[i]->to->x, g.e[i]->to->y);
  }

  // free all the memory we allocated
  for (size_t i = 0; i < g.e_count; ++i) {
    free(g.e[i]);
  }

  for (size_t i = 0; i < g.e_count; ++i) {
    free(e_list[i]);
  }

  for (size_t i = 0; i < g.v_count; ++i) {
    free(g.v[i]);
  }

  for (size_t i = 0; i < g.v_count; ++i) {
    free(v_list[i]);
  }

  free(v_list);
  free(e_list);

  return EXIT_SUCCESS;
}

// Search for a specific vertex in an array of vertex pointers.
// Returns pointer to the vertex in question if it exists - if it doesn't
// it returns a NULL-ptr.
vertex *search_vert(long x, long y, vertex **v_list, size_t v_size) {
  vertex *match = (void *)0;

  for (size_t i = 0; i < v_size; ++i) {
    if (v_list[i]->x == x && v_list[i]->y == y) {
      match = v_list[i];
    }
  }

  return match;
}
