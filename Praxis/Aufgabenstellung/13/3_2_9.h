typedef struct node *B_Ptr;
typedef struct node {
  int key;
  int weight;
  B_Ptr left, right;
} bnodetype;

B_Ptr Tree;

void teilsumme(B_Ptr t);

void gewicht(B_Ptr t);
