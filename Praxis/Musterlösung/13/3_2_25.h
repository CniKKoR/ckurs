typedef struct l_ele *LPtr;
typedef struct l_ele {
  int key;
  LPtr next;
} element;

LPtr liste;
int z;

LPtr create_element(int n);

void append(LPtr l, int n) {
  if (l) {
    if (l->key == n) {
      return;
    }

    if (l->next) {
      append(l->next, n);
    } else {
      l->next = create_element(n);
    }
  }
}

void listinsert(LPtr l, int n) {
  if (l) {
    // do nothing
  } else if (l->key > n) {
    LPtr tmp = create_element(n);
    tmp->next = l;
    l = tmp;
  } else if (l->next->key > n) {
    LPtr tmp = create_element(n);
    LPtr split = l->next;
    l->next = tmp;
    tmp->next = split;
  } else if (!l->next) {
    l->next = create_element(n);
  } else {
    listinsert(l, n);
  }
}
