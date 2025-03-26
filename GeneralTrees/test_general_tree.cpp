#include <stdexcept>
#include <string>

// Adjust this include path if necessary. For example:
// #include "../../generalTree.hpp"
#include "generalTree.hpp"
#include "Google_tests/lib/googletest/include/gtest/gtest-message.h"
#include "Google_tests/lib/googletest/include/gtest/gtest-test-part.h"
#include "Google_tests/lib/googletest/include/gtest/gtest.h"
#include "Google_tests/lib/googletest/include/gtest/gtest_pred_impl.h"
#include "Google_tests/lib/googletest/include/gtest/internal/gtest-internal.h"

// Optional: If you need to directly reference node.hpp or tree.hpp, include them as well.
// #include "node.hpp"
// #include "tree.hpp"

// A test fixture that creates a fresh GeneralTree for each test.
class GeneralTreeTest : public ::testing::Test {
protected:
    GeneralTree*tree = nullptr; // We instantiate one tree per test.

    // You can override SetUp() if you need to do any common initialization:
    // void SetUp() override {
    //     // ...
    // }

    // Similarly, you can override TearDown() if you need cleanup.
    // void TearDown() override {
    //     // ...
    // }
};

//------------------------------------------------------------------------------
// Test 1: AddRoot - basic functionality
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, AddRootSuccess) {
    // Add a root node
    node* root = tree->addRoot(10);

    // Check the returned node
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->elem, 10);
    EXPECT_EQ(root->num_child, 0);
    EXPECT_EQ(root->parent, nullptr);

    // Attempt to retrieve the root from the tree object
    EXPECT_EQ(tree->root, root);
}

//------------------------------------------------------------------------------
// Test 2: AddRoot - adding a second root should throw
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, AddRootTwiceThrows) {
    tree->addRoot(10);
    // The second call should throw logic_error
    EXPECT_THROW(tree.addRoot(20), std::logic_error);
}

//------------------------------------------------------------------------------
// Test 3: AddChild - basic functionality
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, AddChildSuccess) {
    // Create a root first
    node* root = tree->addRoot(10);
    ASSERT_NE(root, nullptr);

    // Add a child
    node* child = tree.addChild(root, 20);
    ASSERT_NE(child, nullptr);
    EXPECT_EQ(child->elem, 20);
    EXPECT_EQ(child->parent, root);
    EXPECT_EQ(child->num_child, 0);

    // Verify parent's child array
    EXPECT_EQ(root->num_child, 1);
    EXPECT_EQ(root->children[0], child);

    // Add another child to the same root
    node* child2 = tree.addChild(root, 30);
    ASSERT_NE(child2, nullptr);
    EXPECT_EQ(child2->elem, 30);
    EXPECT_EQ(child2->parent, root);
    EXPECT_EQ(child2->num_child, 0);

    // Now root should have 2 children
    EXPECT_EQ(root->num_child, 2);
    EXPECT_EQ(root->children[1], child2);
}

//------------------------------------------------------------------------------
// Test 4: RemoveNode - removing a leaf node
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, RemoveLeafSuccess) {
    // Setup: root -> child1, child2
    node* root = tree->addRoot(10);
    node* child1 = tree->addChild(root, 20);
    node* child2 = tree->addChild(root, 30);

    // Remove child1, which is a leaf
    tree->removeNode(child1);

    // Now root should have only one child (child2)
    EXPECT_EQ(root->num_child, 1);
    EXPECT_EQ(root->children[0], child2);

    // Remove child2
    tree->removeNode(child2);

    // Now root should have no children
    EXPECT_EQ(root->num_child, 0);
}

//------------------------------------------------------------------------------
// Test 5: RemoveNode - removing a node with children should throw
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, RemoveNodeWithChildrenThrows) {
    // Setup: root -> child1 -> grandchild
    node* root = tree->addRoot(10);
    node* child1 = tree->addChild(root, 20);
    node* grandchild = tree->addChild(child1, 30);

    // Attempting to remove child1 (which has a child) should throw
    EXPECT_THROW(tree->removeNode(child1), std::logic_error);

    // Clean up by removing grandchild first
    tree->removeNode(grandchild);
    // Now child1 has no children, so we can remove it
    tree->removeNode(child1);

    // Finally, remove the root
    tree.removeNode(root);
}

//------------------------------------------------------------------------------
// Test 6: RemoveNode - removing the root with children should throw
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, RemoveRootWithChildrenThrows) {
    node* root = tree->addRoot(10);
    tree->addChild(root, 20);

    // Attempt to remove root while it has a child
    EXPECT_THROW(tree->removeNode(root), std::logic_error);
}

//------------------------------------------------------------------------------
// Test 7: RemoveNode - removing the root when it is alone
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, RemoveRootWhenAlone) {
    node* root = tree->addRoot(10);
    // Root has no children, so removal is valid
    EXPECT_NO_THROW(tree->removeNode(root));
    // The tree's root pointer should now be nullptr
    EXPECT_EQ(tree->root, nullptr);
}

//------------------------------------------------------------------------------
// Test 8: Verify the 'size' increments and decrements properly
//         (if you want to test internal 'size' logic).
//------------------------------------------------------------------------------
TEST_F(GeneralTreeTest, VerifyTreeSize) {
    // Start: empty tree
    // Since 'size' is private, we can't access it directly.
    // We can check it indirectly by counting node creation and removal.

    // 1) Add root
    node* root = tree->addRoot(10);
    // After this, total nodes: 1

    // 2) Add child1 and child2
    node* child1 = tree->addChild(root, 20);
    node* child2 = tree->addChild(root, 30);
    // total nodes: 3

    // 3) Remove child1
    tree->removeNode(child1);
    // total nodes: 2

    // 4) Remove child2
    tree->removeNode(child2);
    // total nodes: 1

    // 5) Remove root
    tree->removeNode(root);
    // total nodes: 0

    // We don't have a direct way to check 'size' except that removing nodes
    // is not throwing, and the tree is empty at the end.
    // If you wanted to expose or test 'size', you could add an accessor method
    // to the GeneralTree class. E.g., `int getSize() const { return size; }`
}

// The main() for Google Test can be omitted if you're using gtest_main.
// If you need your own main(), uncomment below:
/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
