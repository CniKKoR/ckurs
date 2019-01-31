typedef struct elem *l_Ptr;
typedef struct elem {
  int key;
  l_Ptr next;
} l_elem;

l_Ptr liste;

int prim(x);

void prim_ex(l_Ptr l);
