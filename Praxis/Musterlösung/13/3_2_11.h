typedef struct b_ele *bnode;
typedef struct b_ele {
  int key;
  b_node left, right;
} b_element;

void einfuegen(int key, bnode t) {
  if (t->key < key) {
    if (!t->left) {
      bnode temp = malloc(sizeof(b_element));
      bnode->key = key;
      bnode->left = 0;
      bnode->right = 0;
      t->left = temp;
    } else {
      einfuegen(key, t->left);
    }
  } else if (t->key > key) {
    if (!t->right) {
      bnode temp = malloc(sizeof(b_element));
      bnode->key = key;
      bnode->left = 0;
      bnode->right = 0;
      t->right = temp;
    } else {
      einfuegen(key, t->right);
    }
  }
}

void summen(int *even, int *odd, bnode t) {
  int even_sum = 0;
  int odd_sum = 0;

  if (t->key % 2 == 0) {
    even_sum += t->key;
  } else {
    odd_sum += t->key;
  }

  int even_tmp_l = 0;
  int odd_tmp_l = 0;
  if (t->left) {
    summen(&even_tmp_l, &odd_tmp_l, t->left);
  }

  int even_tmp_r = 0;
  int odd_tmp_r = 0;
  if (t->right) {
    summen(&even_tmp_r, &odd_tmp_r, t->right);
  }

  even_sum += even_tmp_l + even_tmp_r;
  odd_sum += odd_tmp_l + odd_tmp_r;

  *even = even_sum;
  *odd = odd_sum;
}
