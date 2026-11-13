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
 * Author: [BAEKHAHYUN]
 * Date: 2026-11-09
 */
#include "AVLTree.h"

// 이 파일에는 함수의 구현을 작성한다.
// 현재는 팀원별 구현을 위해 선언부와 구현 위치만 준비한 상태이다.
//
// 구현 대상:
// 1. 생성자 / 소멸자
// 2. getHeight, getSubtreeSize, updateNode, getBalanceFactor
// 3. rotateLeft, rotateRight, rebalance
// 4. findNode, findMinimumNode, findMaximumNode, getDepth
// 5. find, insert, empty, size, minimum, maximum, rank, erase
int AVLTree::Insert(int key) {
    AVLNode* parent = nullptr;
    AVLNode* current = root;

    // 1. 삽입 위치 탐색 및 중복 키 검사
    while (current != nullptr) {
        parent = current;

        if (key == current->key) {
            return -1;
        }

        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // 2. 새로운 노드 생성
    AVLNode* new_node = new AVLNode{
        key,
        1,          // height
        1,          // subtree_size
        nullptr,    // left
        nullptr,    // right
        parent      // parent
    };

    // 3. 부모 노드와 연결
    if (parent == nullptr) {
        root = new_node;
    } else if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    ++node_count;

    // 4. 조상 노드의 높이 및 균형 복구
    if (parent != nullptr) {
        Rebalance(parent);
    }

    // 5. 회전이 완료된 트리에서 삽입 노드의 깊이 반환
    return GetDepth(FindNode(key));
}
// 6. destroyTree
//
// 주의:
// - 과제 명세에서 외부 노드(nullptr)의 높이는 0이다.
// - 루트의 깊이는 0이다.
// - Minimum/Maximum은 전달받은 key 노드가 루트인 부분 트리에서 수행한다.
// - Rank는 (노드 깊이, 순위)를 반환한다.
// - Find/Insert/Erase는 깊이를 반환하고, 대상이 없거나 중복 삽입이면 -1을 반환한다.
// - 실제 함수 정의는 팀원들이 아래에 추가한다.
