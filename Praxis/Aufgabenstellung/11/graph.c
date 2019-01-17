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

  // input vertecies that we want to get the shortest path of
  char input_x_of_src[64] = {};
  char input_y_of_src[64] = {};
  char input_x_of_dest[64] = {};
  char input_y_of_dest[64] = {};

  printf("Input x-coordinate of source vertex: ");
  fgets(input_x_of_src, 64, stdin);
  printf("Input y-coordinate of source vertex: ");
  fgets(input_y_of_src, 64, stdin);
  printf("Input x-coordinate of destination vertex: ");
  fgets(input_x_of_dest, 64, stdin);
  printf("Input y-coordinate of destination vertex: ");
  fgets(input_y_of_dest, 64, stdin);

  long x_of_src = strtol(input_x_of_src, 0, 10);
  long y_of_src = strtol(input_y_of_src, 0, 10);
  long x_of_dest = strtol(input_x_of_dest, 0, 10);
  long y_of_dest = strtol(input_y_of_dest, 0, 10);

  vertex src = {.x = x_of_src, .y = y_of_src};
  vertex dest = {.x = x_of_dest, .y = y_of_dest};

  vertex **shortest_path = malloc(sizeof(vertex *) * g.e_count);
  size_t path_len = dijkstra(shortest_path, &src, &dest, &g);

  printf("The shortest path goes through %zu vertices.\n", path_len);
  if (path_len > 0) {
    for (size_t i = 0; i < path_len; ++i) {
      printf("(%li, %li)\n", shortest_path[i]->x, shortest_path[i]->y);
    }
  } else {
    printf("There is no shortest path.\n");
  }

  // Check if vertices are part of g.
  // Only if the answer is yes we can calculate the shortest path.
  if (search_vert(x_of_src, y_of_src, g.v, g.v_count) == 0) {
    printf("Vertex (%li, %li) isn't part of the defined graph!\n", src.x,
           src.y);
    return EXIT_FAILURE;
  }

  if (search_vert(x_of_dest, y_of_dest, g.v, g.v_count) == 0) {
    printf("Vertex (%li, %li) isn't part of the defined graph!\n", src.x,
           src.y);
    return EXIT_FAILURE;
  }

  // calc shortest path

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
