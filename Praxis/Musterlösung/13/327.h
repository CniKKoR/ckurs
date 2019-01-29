typedef struct nodetype *BRtr;
typedef struct nodetype {
  int key;
  BRtr left, right;
} node;

void sum_keys(node *t) {
  if(t->right) {
    t->key += t->right.key;
    sum_keys(t->right);
  }
  if(t->left) {
    t->key += t->left.key;
    sum_keys(t->left);
  }
  if(t->key % 2 == 0) {
    BRtr *temp = t->right;
    t->left = t->right;
    t->right = temp;
  }
}
