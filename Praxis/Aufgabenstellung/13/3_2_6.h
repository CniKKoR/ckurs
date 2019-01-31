typedef struct ele *node;
typedef struct ele {
  int key;
  node left, right;
} b_ele;

node Tree;
int anz;

int blatt(node t);

int anzahl(node t);
