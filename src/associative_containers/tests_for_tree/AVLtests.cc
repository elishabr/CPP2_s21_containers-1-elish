#include <gtest/gtest.h>

#include "../AVLTree.h"

TEST(Node, TestConstructors1) {
  // Arrange
  AVLTreeNode<int> node1;
  AVLTreeNode<double> node2;
  // Act
  // Assert
  EXPECT_EQ(node1.val_, 0);
  EXPECT_EQ(node2.val_, 0.0);
}

TEST(Node, TestConstructors2) {
  // Arrange
  AVLTreeNode<int> node1(1123);

  // Act
  // Assert
  EXPECT_EQ(node1.val_, 1123);
}

TEST(Tree, empty) {
  // Arrange
  AVLTree<int> tree;
  // Act
  // Assert
  EXPECT_EQ(tree.empty(), true);
}

TEST(Tree, UniversalInitialization) {
  // Arrange
  AVLTree<int> tree{1, 2, 3, 4, 5};
  // Act
  // Assert
  EXPECT_EQ(tree.empty(), false);
}

TEST(Tree, Insert) {
  // Arrange
  AVLTree<int> tree{1, 2, 3, 4, 5};
  // Act
  tree.insert(1);
  std::vector<std::vector<int>> items = tree.LevelOrder();
  for (std::vector<int> item : items) {
    for (int i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  // Assert
  EXPECT_EQ(tree.empty(), false);
}

TEST(Tree, Remove) {
  AVLTree<int> tree{1, 2, 3, 4, 5};
  // Act
  std::vector<std::vector<int>> items1 = tree.LevelOrder();
  for (std::vector<int> item : items1) {
    for (int i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  tree.Remove(1);
  std::vector<std::vector<int>> items2 = tree.LevelOrder();
  for (std::vector<int> item : items2) {
    for (int i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  EXPECT_EQ(tree.empty(), false);
}

TEST(Tree, size) {
  // Arrange
  AVLTree<int> tree{1, 2, 3, 4, 5};
  // Act
  std::cout << tree.size() << std::endl;
  // Assert
  EXPECT_EQ(tree.size(), 5);
}

// TEST(Tree, max_size) {
//   // Arrange
//   AVLTree<int> tree{1, 2, 3, 4, 5};
//   // Act
//   std::cout << tree.max_size() << std::endl;
//   // Assert
//   EXPECT_EQ(tree.max_size(), 230584300921369395);
// }

TEST(Tree, MoveConstructors) {
  // Arrange
  AVLTree<int> tree1{1, 2, 3, 4, 5};
  AVLTree<int> tree2(std::move(tree1));
  // Act
  std::vector<std::vector<int>> items2 = tree2.LevelOrder();
  for (std::vector<int> item : items2) {
    for (int i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  // Assert
  EXPECT_EQ(tree2.empty(), false);
}

TEST(Tree, Iterator1) {
  // Arrange
  AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  std::vector<std::vector<int>> items2 = tree1.LevelOrder();
  for (std::vector<int> item : items2) {
    for (int i : item) {
      std::cout << i << " -";
    }
    std::cout << std::endl;
  }
  AVLTree<int>::Iterator it = tree1.begin();
  for (; !it.EndOfList(); ++it) {
    std::cout << *it << std::endl;
  }
  // Assert
  EXPECT_EQ(--it, 8);
}

TEST(Tree, Iterator2) {
  // Arrange
  AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  AVLTree<int>::Iterator it1 = tree1.begin();
  AVLTree<int>::Iterator it2 = tree1.begin();

  // Assert
  EXPECT_EQ(it1++ == ++it2, false);
  EXPECT_EQ(it1++ != ++it2, true);
  EXPECT_EQ(*it1, 3);
}

TEST(Tree, Iterator3) {
  // Arrange
  AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  AVLTree<int>::Iterator it1 = tree1.begin();
  it1++;
  it1--;
  // Assert
  EXPECT_EQ(*it1, 1);
}

TEST(Tree, Iterator4) {
  // Arrange
  AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  AVLTree<int>::Iterator it1 = tree1.begin();
  for (; !it1.EndOfList(); ++it1) {
    std::cout << *it1 << " ";
  }
  std::cout << std::endl;
  --it1;
  for (; !it1.BeginOfList(); --it1) {
    std::cout << *it1 << " ";
  }
  std::cout << std::endl;
  // Assert
  EXPECT_EQ(*it1, 1);
}

TEST(Tree, Iterator5) {
  // Arrange
  AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  AVLTree<int>::Iterator it1 = tree1.end();
  AVLTree<int>::Iterator it2 = tree1.begin();
  for (; !it2.EndOfList(); ++it2) {
    *it2 = 3;
  }
  --it1;
  for (; !it1.BeginOfList(); --it1) {
    std::cout << *it1 << " ";
  }
  std::cout << std::endl;
  // Assert
  EXPECT_EQ(*it1, 3);
}

TEST(Tree, Iterator6) {
  // Arrange
  AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  AVLTree<int>::Iterator it1 = tree1.begin();
  for (; it1 != tree1.end(); ++it1) {
    std::cout << *it1 << " ";
  }
  std::cout << std::endl;
  // Assert
  --it1;
  EXPECT_EQ(*it1, 8);
}

TEST(Tree, Iterator7) {
  // Arrange
  const AVLTree<int> tree1{1, 2, 8, 3, 5, 7};
  // Act
  const AVLTree<int>::Iterator it1 = tree1.end();
  const AVLTree<int>::Iterator it2 = tree1.begin();
  for (; it2 != it1; it2++) {
    std::cout << *it2 << " ";
  }
  std::cout << std::endl;
  it2--;
  // Assert
  EXPECT_EQ(*it2, 8);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
