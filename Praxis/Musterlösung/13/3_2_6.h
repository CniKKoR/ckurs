typedef struct ele *node;
typedef struct ele {
  int key;
  node left, right;
} b_ele;

node Tree;
int anz;

int blatt(node t) {
  if(t.left || t.right) {
    return 0;
  }
  return 1;
}

int anzahl(node t) {
  int n = 0;
  if(blatt(t.left) && blatt(t.right) {
    return 0;
  } else {
    if(!blatt(t.left) && !blatt(t.right)) ++n;
    return n + anzahl(t.left) + anzahl(t.right);
  }
}
