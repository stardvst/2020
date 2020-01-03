#include "btree.h"

#include <iostream>

BTreeNode::BTreeNode(std::size_t nDegree, bool bLeaf) noexcept
	: m_nDegree(nDegree)
	, m_bLeaf(bLeaf)
{
	m_vecKeys.resize(2 * m_nDegree - 1);
	m_vecChildNodes.resize(2 * m_nDegree);
}

void BTreeNode::insertNonFull(int nKey)
{
	int idx = m_nCurrentKeys - 1;

	if (m_bLeaf)
	{
		while (idx >= 0 && m_vecKeys[idx] > nKey)
		{
			m_vecKeys[idx + 1] = m_vecKeys[idx];
			--idx;
		}

		m_vecKeys[idx + 1] = nKey;
		++m_nCurrentKeys;
	}
	else
	{
		while (idx >= 0 && m_vecKeys[idx] > nKey)
			--idx;

		if (m_vecChildNodes[idx + 1]->m_nCurrentKeys == 2 * m_nDegree - 1)
		{
			splitChild(idx + 1, m_vecChildNodes[idx + 1]);

			if (m_vecKeys[idx + 1] < nKey)
				++idx;
		}

		m_vecChildNodes[idx + 1]->insertNonFull(nKey);
	}
}

void BTreeNode::splitChild(int nChildIdx, BTreeNode *pChildNode)
{
	auto pNewNode = new BTreeNode(pChildNode->m_nDegree, pChildNode->m_bLeaf);
	pNewNode->m_nCurrentKeys = m_nDegree - 1;

	for (auto idx = 0; idx < m_nDegree - 1; ++idx)
		pNewNode->m_vecKeys[idx] = pChildNode->m_vecKeys[idx + m_nDegree];

	if (!pChildNode->m_bLeaf)
	{
		for (auto idx = 0; idx < m_nDegree; ++idx)
			pNewNode->m_vecChildNodes[idx] = pChildNode->m_vecChildNodes[idx + m_nDegree];
	}

	pChildNode->m_nCurrentKeys = m_nDegree - 1;

	for (auto idx = m_nDegree; idx >= nChildIdx + 1; --idx)
		m_vecChildNodes[idx + 1] = m_vecChildNodes[idx];
	m_vecChildNodes[nChildIdx + 1] = pNewNode;

	for (int idx = m_nDegree - 1; idx >= nChildIdx; --idx)
		m_vecKeys[idx + 1] = m_vecKeys[idx];
	m_vecKeys[nChildIdx] = pChildNode->m_vecKeys[m_nDegree - 1];

	++m_nCurrentKeys;
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
		m_vecChildNodes[m_nCurrentKeys]->traverse();
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

BTree::BTree(std::size_t nDegree) noexcept
	: m_nDegree(nDegree)
{
}

void BTree::insert(int nKey)
{
	if (!m_pRoot)
	{
		m_pRoot = new BTreeNode(m_nDegree, true);
		m_pRoot->m_vecKeys[0] = nKey;
		m_pRoot->m_nCurrentKeys = 1;
		return;
	}

	if (m_pRoot->m_nCurrentKeys == 2 * m_nDegree - 1)
	{
		auto pNewNode = new BTreeNode(m_nDegree, false);
		pNewNode->m_vecChildNodes[0] = m_pRoot;
		pNewNode->splitChild(0, m_pRoot);

		int idx = 0;
		if (pNewNode->m_vecKeys[0] < nKey)
			++idx;
		pNewNode->m_vecChildNodes[idx]->insertNonFull(nKey);

		m_pRoot = pNewNode;
	}
	else
	{
		m_pRoot->insertNonFull(nKey);
	}
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
