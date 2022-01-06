#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include <cstdio>

#define nullptr NULL
using namespace std;

int nodes_count;

template<typename T>
struct Tree {
  int id;
  T value;

  int height;
  int tree_rank;
  Tree<T>* left;
  Tree<T>* right;
  Tree<T>* parent;

  static Tree<T>* root;

  Tree():
          id(nodes_count++),
          value(),
          height(0),
          tree_rank(1),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}

  Tree(T node_value):
          id(nodes_count++),
          value(node_value),
          height(0),
          tree_rank(1),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}

  Tree(Tree<T>* left_child,
       Tree<T>* right_child):  id(nodes_count++),
                            value(),
                            height(0),
                            tree_rank(1),
                            left(addLeft(left_child)),
                            right(addRight(right_child)),
                            parent(nullptr) {
    updateHeight();
  }

  static void addNode(Tree<T>* new_node) {
    if(!root) {
      Tree<T>::root = new_node;
      return;
    }

    Tree<T>* current;
    Tree<T>* next = root;
    do {
      current = next;
      if(new_node->value < current->value)
        next = current->left;
      else
        next = current->right;
    } while(next != nullptr);

    if(new_node->value < current->value)
        current->addLeft(new_node);
      else
        current->addRight(new_node);

    current = new_node;
    while(current != nullptr) {
      current->updateHeight();
      current->balance();
      current = current->parent;
    }
  }

  static Tree<T>* upperBound(const T value) {
    Tree<T>* current = Tree<T>::root;
    Tree<T>* last = nullptr;


    while(current) {
      if (value < current->value) {
        if (current->left)
          current = current->left;
        else
          break;
      } else {
        if (current->value < value) {
          last = current;
          if (current->right)
            current = current->right;
          else
            break;
        }
      }

    }

    return last;
  }

  static Tree<T>* next(Tree<T>* node) {
    if(node->right != nullptr )
      return minValue(node->right);

    Tree<T>* par = node->parent;
    while(par != nullptr && node == par->right) {
       node = par;
       par = par->parent;
    }

    return par;
  }

  static Tree<T>* minValue(Tree<T>* node) {
     Tree<T>* current = node;

    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  void balance() {
    int lh = leftHeight();
    int rh = rightHeight();
    if(rh - lh >= 2) {
      if(right->leftHeight() <= right->rightHeight())
        smallLeft();
      else
        bigLeft();
      return;
    }

    if(lh - rh >= 2) {
      if(left->leftHeight() >= left->rightHeight())
        smallRight();
      else
        bigRight();
    }
    updateHeight();
  }

  int getRank() {
    int rank = leftRank();
    Tree<T>* prev = this;
    Tree<T>* current = this->parent;
    while(current != nullptr) {
      if(prev == current->right)
        rank += current->leftRank() + 1;
      prev = current;
      current = current->parent;
    }
    return rank;
  }

  bool hasLeft() { return left != nullptr; }
  bool hasRight() { return right != nullptr; }
  bool hasParent() { return parent != nullptr; }
  int leftHeight() { return hasLeft()?left->height:-1; }
  int rightHeight() { return hasRight()?right->height:-1; }
  int leftRank() { return hasLeft()?left->tree_rank:0; }
  int rightRank() { return hasRight()?right->tree_rank:0; }

  Tree<T>* addLeft(Tree* child) {
    if(child != nullptr) child->parent = this;
    left = child;
    updateHeight();
    return left;
  }

  Tree<T>* addRight(Tree* child) {
    if(child != nullptr) child->parent = this;
    right = child;
    updateHeight();
    return right;
  }

  Tree<T>* releaseLeft() {
    Tree<T>* child = left;
    if(child) child->parent = nullptr;
    left = nullptr;
    updateHeight();
    return child;
  };

  Tree<T>* releaseRight() {
    Tree<T>* child = right;
    if(child) child->parent = nullptr;
    right = nullptr;
    updateHeight();
    return child;
  };

  void replaceChild(Tree<T>* old_child, Tree<T>* new_child) {
    if(left == old_child) left = new_child;
    if(right == old_child) right = new_child;
    if(new_child) new_child->parent = this;
    updateHeight();
  }

  void updateHeight() {
    tree_rank = 1;
    height = 0;
    if(hasLeft()) {
      height = max(height, left->height + 1);
      tree_rank += left->tree_rank;
    }

    if(hasRight()) {
      height = max(height, right->height + 1);
      tree_rank += right->tree_rank;
    }
  };

  void smallLeft() {
    if(!hasRight())
      return;

    Tree<T>* old_node = this;
    Tree<T>* old_parent = this->parent;

    Tree<T>* new_node = releaseRight();

    addRight(new_node->releaseLeft());
    new_node->addLeft(old_node);

    if(old_parent)
      old_parent->replaceChild(old_node, new_node);
    else
      Tree<T>::root = new_node;
  }

  void smallRight() {
    if(!hasLeft())
      return;

    Tree<T>* old_node = this;
    Tree<T>* old_parent = this->parent;

    Tree<T>* new_node = releaseLeft();

    addLeft(new_node->releaseRight());
    new_node->addRight(old_node);

    if(old_parent)
      old_parent->replaceChild(old_node, new_node);
    else
      Tree<T>::root = new_node;
  }

  void bigLeft() {
    if(!hasRight() || !right->hasLeft()) return;
    right->smallRight();
    smallLeft();
  }

  void bigRight() {
    if(!hasLeft() || !left->hasRight()) return;
    left->smallLeft();
    smallRight();
  }

  private: Tree(const Tree<T>& other);
};

template <typename T>
Tree<T>* Tree<T>::root = nullptr;

typedef pair<long long, long long> PLL;

long long n, m, room;
const long long INF = 1000*1000*1000 + 42;
char c;

int main() {
    freopen("in.txt","r",stdin);
    freopen("outAC.txt","w",stdout);

  scanf("%lld %lld\n", &n, &m);

  for(int i = 0; i < m; ++i) {
    scanf("%c %lld\n", &c, &room);

    PLL rr = make_pair(room, INF);
    Tree<PLL>* node = Tree<PLL>::upperBound(rr);
    if (c == 'L') {
      long long res;
      if (!node) {
        res = room;
      } else {
        res = room + node->getRank();
        if (node->value < rr)
          ++res;
      }
      printf("%lld\n", res);
    } else {
      if (node && node->value.first == room) {
        rr.second = node->value.second + 1;
      } else {
        rr.second = 0;
      }

      Tree<PLL>* new_node = new Tree<PLL>(rr);
      Tree<PLL>::addNode(new_node);
      Tree<PLL>* prev = new_node;
      new_node = Tree<PLL>::next(new_node);
      while (new_node != nullptr) {
        new_node->value.first -= 1;
        if (prev->value.first == new_node->value.first) {
          new_node->value.second = prev->value.second + 1;
        }
        prev = new_node;
        new_node = Tree<PLL>::next(new_node);
      }
    }
  }
  return 0;
}
