typedef struct b_node *node;
typedef struct b_node {
  int key;
  int pos;
  node left, right;
} b_node_type;
