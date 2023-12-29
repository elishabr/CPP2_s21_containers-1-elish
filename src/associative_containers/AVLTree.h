#ifndef SRC_ASSOCIATIVE_CONTAINERS_AVLTREE_H
#define SRC_ASSOCIATIVE_CONTAINERS_AVLTREE_H

#include <cstddef>
#include <iostream>
#include <queue>   //help
#include <stack>   //help
#include <vector>  //help

template <typename T>
struct AVLTreeNode {
  using size_type = size_t;

  int balanceFactor_;
  size_type height_;
  T val_;
  AVLTreeNode<T>* right_;
  AVLTreeNode<T>* left_;
  AVLTreeNode();
  explicit AVLTreeNode(const T& x);
  ~AVLTreeNode();
};

template <class T>
class AVLTree {
  // using key_type = Key;
  // using value_type = Value;
  // using reference = value_type&;
  // using const_reference = const value_type&;
 public:
  class Iterator;
  class ConstIterator;
  using iterator = Iterator;
  using size_type = size_t;
  using const_iterator = const Iterator;

 private:
  AVLTreeNode<T>* root_;

  size_type Height(AVLTreeNode<T>* node) const;
  int BFactor(AVLTreeNode<T>* node) const;
  void FixHeight(AVLTreeNode<T>* node) const;
  size_type NodeCount(AVLTreeNode<T> const* node) const;
  AVLTreeNode<T>* SingleRotateRight(AVLTreeNode<T>* node);
  AVLTreeNode<T>* SingleRotateLeft(AVLTreeNode<T>* node);
  AVLTreeNode<T>* Balance(AVLTreeNode<T>* node);
  virtual AVLTreeNode<T>* AVLInsert(AVLTreeNode<T>* node, T data);
  virtual AVLTreeNode<T>* FindMin(AVLTreeNode<T>* node);
  virtual AVLTreeNode<T>* RemoveMin(AVLTreeNode<T>* node);
  virtual AVLTreeNode<T>* AVLRemove(AVLTreeNode<T>* node, T data);

 public:
  ~AVLTree();
  AVLTree();
  AVLTree(const AVLTree<T>& other);
  AVLTree(AVLTree<T>&& other) noexcept;
  AVLTree(std::initializer_list<T> const& items);
  AVLTree<T>& operator=(const AVLTree<T>& tree);
  AVLTree<T>& operator=(AVLTree<T>&& m) noexcept;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  virtual void insert(const T data);
  void Remove(const T data);
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  std::vector<std::vector<T>> LevelOrder();  // TODO временно для тестов

  class Iterator {
   protected:
    mutable bool iterationComplete;

   private:
    mutable std::stack<AVLTreeNode<T>*> stackNode;  // TODO заменить на свой
    mutable std::stack<AVLTreeNode<T>*> stackNodeRevers;
    AVLTreeNode<T>* root_;
    mutable AVLTreeNode<T>* current_;
    AVLTreeNode<T>* GoFarLeft(AVLTreeNode<T>* node) const;
    void Next() const;
    void Last() const;
    void Reset() const;
    T Data() const;
    void swap(AVLTree<T>::Iterator& other);

   public:
    Iterator();
    Iterator(AVLTreeNode<T>* root);
    Iterator(const AVLTree<T>::Iterator& other);
    Iterator(AVLTree<T>::Iterator&& other) noexcept;
    AVLTree<T>::Iterator& operator=(const AVLTree<T>::Iterator& other);
    AVLTree<T>::Iterator& operator=(AVLTree<T>::Iterator&& other) noexcept;
    bool EndOfList() const;
    bool BeginOfList() const;

    T& operator++();
    T operator++(int) const;
    T& operator--();
    T operator--(int) const;
    T& operator*();
    const T& operator*() const;
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
  };
};

#include "AVLIterator.cc"
#include "AVLTree.cc"
#endif  // SRC_ASSOCIATIVE_CONTAINERS_AVLTREE_H