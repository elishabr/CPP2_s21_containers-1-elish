#ifndef SRC_ASSOCIATIVE_CONTAINERS_CONTAINERS_S21MAP_H
#define SRC_ASSOCIATIVE_CONTAINERS_CONTAINERS_S21MAP_H

#include "../AVLTree.h"

namespace s21 {
  template <class Key, class T>
  class map : public AVLTree<std::pair<const Key, T>> {
    public:
      using key_type = Key;
      using mapped_type = T;
      using value_type = std::pair<const key_type, mapped_type>;
      using reference = value_type &;
      using const_reference = const value_type &;
      using iterator = typename AVLTree<value_type>::Iterator;
      using const_iterator = const typename  AVLTree<value_type>::Iterator;
      using size_type = size_t;

      map();
      //map(std::initializer_list<value_type> const &items);
      //map(const map &m);
      //map(map &&m);
      //~map();
      //operator=(map &&m);

      //void clear();
      //std::pair<iterator, bool> insert(const value_type& value);
      //std::pair<iterator, bool> insert(const Key& key, const T& obj);
      //std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
      //void erase(iterator pos);
      //void swap(map& other);
      //void merge(map& other);
      //bool contains(const Key& key);

      //T& at(const Key& key);
      //T& operator[](const Key& key);


  };
} // namespace s21

#include "S21Map.cc"

#endif //SRC_ASSOCIATIVE_CONTAINERS_CONTAINERS_S21MAP_H