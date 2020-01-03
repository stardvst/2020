#pragma once

#include <vector>

class BTreeNode
{
	friend class BTree;
public:
	BTreeNode(std::size_t nDegree, bool bLeaf) noexcept;

	// Insert key in subtree rooted at this (non-full) node
	void insertNonFull(int nKey);

	// Split given (full) child, given index of it in child nodes
	void splitChild(int nChildIdx, BTreeNode *pChildNode);

	// Traverse subtree rooted at this node
	void traverse() const;

	// Searches for given value in subtree rooted at this node
	const BTreeNode *search(int nKey) const;

private:
	std::vector<int> m_vecKeys;
	std::vector<BTreeNode *> m_vecChildNodes;
	std::size_t m_nDegree = 0;
	int m_nCurrentKeys = 0;
	bool m_bLeaf = true;
};

class BTree
{
public:
	explicit BTree(std::size_t nDegree) noexcept;
	
	void insert(int nKey);
	void traverse() const;
	const BTreeNode *search(int nKey) const;

private:
	BTreeNode *m_pRoot = nullptr;
	std::size_t m_nDegree = 0;
};
