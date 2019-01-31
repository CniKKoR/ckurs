typedef struct l_ele *LPtr;
typedef struct l_ele {
  int key;
  LPtr next;
} element;

LPtr liste;
int z;

LPtr create_element(int n);

void append(LPtr *l, int n) {
  if(*l) {
    if((*l)->key == n)  {
      return;
    } else {
      append(&((*l)->next), n);
    }
  } else {
    *l = create_element(n);
  }
}

void listinsert(LPtr *l, LPtr ele) {
  if(*l) {
    if((*l)->key < ele->key) {
      listinsert(&((*l)->next), ele);
    } else {
      ele->next = (*l)->next;
      (*l)->next = ele;
    }
  } else {
    *l = ele;
  }
}
