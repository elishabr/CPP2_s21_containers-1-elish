#ifndef SRC_ASSOCIATIVE_CONTAINERS_CONTAINERS_MULTISET_S21_MULTISET_H
#define SRC_ASSOCIATIVE_CONTAINERS_CONTAINERS_MULTISET_S21_MULTISET_H

#include "../AVLTree.h"

namespace s21 {

template <typename Key>
class multiset : public AVLTree<Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const Key&;
  using iterator = const typename multiset<Key>::Iterator;
  using size_type = size_t;

 public:
  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset<value_type>& other);
  multiset(multiset<value_type>&& other) noexcept;
  virtual ~multiset() override;
  multiset<value_type>& operator=(const multiset<value_type>& other);
  multiset<value_type>& operator=(multiset<value_type>&& other) noexcept;

  iterator insert(const value_type& value);

  bool contains(const key_type& key) const;
  void erase(iterator pos);
  void merge(const multiset<value_type>& other);

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  iterator find(const key_type& key) const;
  size_type count(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);
  std::pair<iterator, iterator> equal_range(const Key& key);
};
}  // namespace s21

#include "s21_multiset.cc"

#endif  // SRC_ASSOCIATIVE_CONTAINERS_CONTAINERS_MULTISET_S21_MULTISET_H