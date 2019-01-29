typedef struct b_node *node;
typedef struct b_node {
  int key;
  int pos;
  node left, right;
} b_node_type;

void insert(node *t, int n, int pos) {
  if (!t) {
    t = malloc(sizeof(node));
    t->pos = pos;
    t->key = n;
    return;
  }
  if (n == t->key) {
    t->pos = pos;
    return;
  }
  if (n < t->key) {
    insert(t->left, n, -1);
  } else {
    insert(t->right, n, 1);
  }
}
