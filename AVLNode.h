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
#ifndef AVL_NODE_H
#define AVL_NODE_H

// AVL 트리의 각 노드를 표현한다.
struct AVLNode {
    int key;                 // 노드에 저장되는 32-bit 정수 키
    int height;              // 해당 노드를 루트로 하는 부분 트리의 높이
    int subtreeSize;         // 해당 노드를 루트로 하는 부분 트리의 노드 수

    AVLNode* left;           // 왼쪽 자식
    AVLNode* right;          // 오른쪽 자식
    AVLNode* parent;         // 부모 노드
};

#endif // AVL_NODE_H
