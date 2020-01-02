#pragma once

#include <vector>
#include <memory>

class BTreeNode
{
public:
	BTreeNode(int nDegree, bool bLeaf) noexcept;

	// Traverse subtree rooted at this node
	void traverse() const;

	// Searches for given value in subtree rooted at this node
	const BTreeNode *search(int nKey) const;

private:
	std::vector<int> m_vecKeys;
	std::vector<BTreeNode *> m_vecChildNodes;
	int m_nDegree = 0;
	int m_nCurrentKeys = 0;
	bool m_bLeaf;
};

class BTree
{
public:
	explicit BTree(int nDegree) noexcept;
	
	void traverse() const;

	const BTreeNode *search(int nKey) const;

private:
	std::unique_ptr<BTreeNode> m_pRoot{nullptr};
	int m_nDegree = 0;
};
