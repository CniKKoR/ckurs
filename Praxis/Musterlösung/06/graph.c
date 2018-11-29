#include <stdlib.h>
#include <stdio.h>

typedef struct vertex {
    long x;
    long y;
} vertex;

typedef struct edge {
    vertex *from;
    vertex *to;
    int weight;
} edge;

typedef struct graph {
    size_t v_count;
    size_t e_count;
    vertex **v;
    edge **e;
} graph;

int main (void) {
    vertex v_1_1 = { .x = 1, .y = 1 };
    vertex v_1_3 = { .x = 1, .y = 3 };
    vertex v_3_3 = { .x = 3, .y = 3 };
    vertex v_3_1 = { .x = 3, .y = 1 };

    vertex **v_set = malloc(sizeof(void*) * 4);

    v_set[0] = &v_1_1;
    v_set[1] = &v_1_3;
    v_set[2] = &v_3_3;
    v_set[3] = &v_3_1;

    edge e_1_1_1_3 = { .from = &v_1_1, .to = &v_1_3, 1 };
    edge e_1_3_1_1 = { .from = &v_1_3, .to = &v_1_1, 1 };
    
    edge e_1_1_3_3 = { .from = &v_1_1, .to = &v_3_3, 1 };
    edge e_3_3_1_1 = { .from = &v_3_3, .to = &v_1_1, 1 };
    
    edge e_1_1_3_1 = { .from = &v_1_1, .to = &v_3_1, 1 };
    edge e_3_1_1_1 = { .from = &v_3_1, .to = &v_1_1, 1 };
    
    edge e_1_3_3_3 = { .from = &v_1_3, .to = &v_3_3, 1 };
    edge e_3_3_1_3 = { .from = &v_3_3, .to = &v_1_3, 1 };
    
    edge e_3_1_3_3 = { .from = &v_3_1, .to = &v_3_3, 1 };
    edge e_3_3_3_1 = { .from = &v_3_3, .to = &v_3_1, 1 };

    edge **e_set = malloc(sizeof(void*) * 10);

    e_set[0] = &e_1_1_1_3;
    e_set[1] = &e_1_3_1_1;
    e_set[2] = &e_1_1_3_3;
    e_set[3] = &e_3_3_1_1;
    e_set[4] = &e_1_1_3_1;
    e_set[5] = &e_3_1_1_1;
    e_set[6] = &e_1_3_3_3;
    e_set[7] = &e_3_3_1_3;
    e_set[8] = &e_3_1_3_3;
    e_set[9] = &e_3_3_3_1;

    graph g = { .v = v_set, .e = e_set, .v_count = 4, .e_count = 10 };

    for (size_t i = 0; i < g.v_count; ++i)
        printf("Vertex %zu: (%li,%li)\n", i, g.v[i]->x, g.v[i]->y);
    printf("\n");
    for (size_t i = 0; i < g.e_count; ++i)
        printf("Edge %zu: (%li,%li) -> (%li,%li)\n", i, g.e[i]->from->x, g.e[i]->from->y, g.e[i]->to->x, g.e[i]->to->y);

    return EXIT_SUCCESS;
}