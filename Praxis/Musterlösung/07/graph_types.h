
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

vertex *search_vert(long x, long y, vertex **v_list, size_t v_size);
