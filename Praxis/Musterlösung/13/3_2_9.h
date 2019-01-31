typedef struct node *B_Ptr;
typedef struct node {
  int key;
  int weight;
  B_Ptr left, right;
} bnodetype;

B_Ptr Tree;

void teilsumme(B_Ptr t) {
  if (t) {
    if (t->left || t->right) {

      teilsumme(t->left);
      teilsumme(t->right);

      if (!t->left && t->right) {
        t->weight = t->right->key;
      } else if (t->left && !t->right) {
        t->weight = t->left->key;
      } else {
        t->weight = t->left->key + t->right->key;
      }
    } else {
      t->weight = 0;
    }
  }
}


int summe(B_Ptr t) {
  if (t) {
    return t->key + summe(t->left) + summe(t->right);
  } else {
    return 0;
  }
}

void gewicht(B_Ptr t) {
  if (t) {
    int left = summe(t->left);
    int right = summe(t->right);

    if (left == right) {
      t->weight = 0;
    } else if (left < right) {
      t->weight = 1;
    } else { // left > right
      t->weight = -1;
    }

    gewicht(t->left);
    gewicht(t->right);
  }
}
