#include "btree.h"

#include <iostream>

BTreeNode::BTreeNode(int nDegree, bool bLeaf) noexcept
	: m_nDegree(nDegree)
	, m_bLeaf(bLeaf)
{
	m_vecKeys.reserve(2 * m_nDegree - 1);
	m_vecChildNodes.reserve(2 * m_nDegree);
}

void BTreeNode::traverse() const
{
	for (auto idx = 0; idx < m_nCurrentKeys; ++idx)
	{
		if (!m_bLeaf)
			m_vecChildNodes[idx]->traverse();

		std::cout << ' ' << m_vecKeys[idx];
	}

	if (!m_bLeaf)
		m_vecChildNodes.back()->traverse();
}

const BTreeNode *BTreeNode::search(int nKey) const
{
	int idx = 0;
	while (idx < m_nCurrentKeys && m_vecKeys[idx] < nKey)
		++idx;

	if (m_vecKeys[idx] == nKey)
		return this;

	if (m_bLeaf)
		return nullptr;

	return m_vecChildNodes[idx]->search(nKey);
}

//////////////////////////////////////////////////////////////////////////

BTree::BTree(int nDegree) noexcept
	: m_nDegree(nDegree)
{
}

void BTree::traverse() const
{
	if (m_pRoot)
		m_pRoot->traverse();
}

const BTreeNode *BTree::search(int nKey) const
{
	return m_pRoot ? m_pRoot->search(nKey) : nullptr;
}
