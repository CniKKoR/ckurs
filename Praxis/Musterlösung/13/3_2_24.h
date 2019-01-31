typedef struct elem *l_Ptr;
typedef struct elem {
  int key;
  l_Ptr next;
} l_elem;

int prim(int x) {
  for (size_t i = 2; i < x; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

void prim_ex(l_Ptr *l) {      // l points at the previous elements next-pointer
  if(*l) {                    // element exists
    if(prim((*l)->key)) {     // element is prim
      *l = (*l)->next;        // change previous next pointer
      prim_ex(l);             // execute prim_ex with new list (next-pointer changes)
    } else {
      prim_ex(&((*l)->next)); // execute prim_ex with adress of the next element
    }
  }
}
