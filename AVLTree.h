/*
 * MIT License
 *
 * Copyright (c) 2026 [Team Name / Author Name]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *
 * SPDX-License-Identifier: MIT
 *
 * Author: [Author Name]
 * Date: 2026-11-12
 */
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "AVLNode.h"

#include <utility>

class AVLTree {
private:
    AVLNode* root;
    int node_count;

    // 높이 및 부분 트리 크기 관리
    int GetHeight(const AVLNode* node) const;
    int GetSubtreeSize(const AVLNode* node) const;
    void UpdateNode(AVLNode* node);
    int GetBalanceFactor(const AVLNode* node) const;

    // 회전 및 균형 복구
    AVLNode* RotateLeft(AVLNode* node);
    AVLNode* RotateRight(AVLNode* node);
    void Rebalance(AVLNode* node);

    // 내부 탐색 보조 함수
    AVLNode* FindNode(int key) const;
    AVLNode* FindMinimumNode(AVLNode* node) const;
    AVLNode* FindMaximumNode(AVLNode* node) const;
    int GetDepth(const AVLNode* node) const;

    // 메모리 해제
    void DestroyTree(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    // 복사 방지: 얕은 복사로 인한 중복 해제를 방지한다.
    AVLTree(const AVLTree& other) = delete;
    AVLTree& operator=(const AVLTree& other) = delete;

    // 기본 기능
    int Find(int key) const;
    int Insert(int key);
    bool Empty() const;
    int Size() const;
    std::pair<int, int> Minimum(int key) const;
    std::pair<int, int> Maximum(int key) const;

    // 고급 기능
    std::pair<int, int> Rank(int key) const;
    int Erase(int key);
};

#endif // AVL_TREE_H
