#include "S21Map.h"

template <class Key, class T>
s21::map<Key, T>::map():AVLTree<std::pair<const Key, T>>(){}