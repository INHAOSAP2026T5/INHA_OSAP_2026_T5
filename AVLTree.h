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
 * Date: 2026-11-09
 */
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <utility>
#include "AVLNode.h"

class AVLTree {
private:
    AVLNode* root;
    int nodeCount;

    // 높이 및 부분 트리 크기 관리
    int getHeight(const AVLNode* node) const;
    int getSubtreeSize(const AVLNode* node) const;
    void updateNode(AVLNode* node);
    int getBalanceFactor(const AVLNode* node) const;

    // 회전 및 균형 복구
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    void rebalance(AVLNode* node);

    // 내부 탐색 보조 함수
    AVLNode* findNode(int key) const;
    AVLNode* findMinimumNode(AVLNode* node) const;
    AVLNode* findMaximumNode(AVLNode* node) const;
    int getDepth(const AVLNode* node) const;

    // 메모리 해제
    void destroyTree(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    // 복사 방지: 얕은 복사로 인한 중복 해제를 방지한다.
    AVLTree(const AVLTree& other) = delete;
    AVLTree& operator=(const AVLTree& other) = delete;

    // 기본 기능
    int find(int key) const;
    int insert(int key);
    bool empty() const;
    int size() const;
    std::pair<int, int> minimum(int key) const;
    std::pair<int, int> maximum(int key) const;

    // 고급 기능
    std::pair<int, int> rank(int key) const;
    int erase(int key);
};

#endif // AVL_TREE_H