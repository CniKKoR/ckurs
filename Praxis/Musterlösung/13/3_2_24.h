int prim(int x) {
  for (size_t i = 2; i < x; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

typedef struct elem *l_Ptr;
typedef struct elem {
  int key;
  l_Ptr next;
} l_elem;

void prim_ex(l_Ptr *l) {
  l_Ptr next = l->next;
  if (prim(next->key)) {
    free(l->next);
    l->next = next->next;
  }
}
