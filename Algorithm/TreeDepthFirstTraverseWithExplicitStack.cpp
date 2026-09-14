// use explicitly allocated stack to depth-first traverse a tree
// can prevent thread stack overflow compared to recursive traversal
#include <stack>
#include <stddef.h>
#include <stdio.h>
struct Node {
  Node *firstChild;
  Node *nextSibling;
  unsigned value;
};
void ProcessNode(void *arg, Node *node) {
  printf("%u ", node->value);
  *(unsigned *)arg += node->value;
}
using TraverseFn = void (*)(void *, Node *root);
void RecursiveTraverse(void *arg, Node *root) {
  if (root->firstChild)
    RecursiveTraverse(arg, root->firstChild);
  ProcessNode(arg, root);
  if (root->nextSibling)
    RecursiveTraverse(arg, root->nextSibling);
}
void ExplicitStackTraverse(void *arg, Node *root) {
  std::stack<Node *> stk;
  Node *n = root;

  while (1) {
    while (n->firstChild) {
      stk.push(n);
      // printf("push(%u)\n", curr->value);
      n = n->firstChild;
    }
    ProcessNode(arg, n);
    while (1) {
      if (n->nextSibling) {
        n = n->nextSibling;
        break;
      }
      if (stk.empty())
        return;
      n = stk.top();
      stk.pop();
      // printf("pop(%u)\n", curr->value);
      ProcessNode(arg, n);
    }
  }
}
void Test1(TraverseFn fn) {
  Node n[]{
      {&n[1], NULL, 0}, {&n[3], &n[2], 1}, {&n[5], NULL, 2},
      {NULL, &n[4], 3}, {NULL, NULL, 4},   {NULL, NULL, 5},
  };
  unsigned sum = 0;
  fn(&sum, n);
  putchar('\n');
  if (sum != 15) {
    printf("sum=%u!=15\n", sum);
  }
}
void Test2(TraverseFn fn) {
  Node n[]{
      {&n[1], NULL, 0}, {&n[3], &n[2], 1}, {NULL, NULL, 2},
      {NULL, &n[4], 3}, {NULL, &n[5], 4},  {NULL, NULL, 5},
  };
  unsigned sum = 0;
  fn(&sum, n);
  putchar('\n');
  if (sum != 15) {
    printf("sum=%u!=15\n", sum);
  }
}
void Test3(TraverseFn fn) {
  Node n[]{
      {&n[1], NULL, 0}, {NULL, &n[2], 1},  {&n[4], &n[3], 2}, {&n[7], NULL, 3},
      {NULL, &n[5], 4}, {&n[8], &n[6], 5}, {NULL, NULL, 6},   {&n[9], NULL, 7},
      {NULL, NULL, 8},  {NULL, NULL, 9},
  };
  unsigned sum = 0;
  fn(&sum, n);
  putchar('\n');
  if (sum != 45) {
    printf("sum=%u!=45\n", sum);
  }
}
int main() {
  Test1(RecursiveTraverse);
  Test2(RecursiveTraverse);
  Test3(RecursiveTraverse);
  Test1(ExplicitStackTraverse);
  Test2(ExplicitStackTraverse);
  Test3(ExplicitStackTraverse);
}
