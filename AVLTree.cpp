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
//6. destoryTree
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

AVLNode* AVLTree::FindNode(int key)const {
    //1. 현재 노드 설정: 루트 노드(루트 노드 부터 탐색 진행)
    AVLNode* current = root;

    //2. 노드가 존재하는 동안 반복
    while (current != nullptr) {
        //3. key가 일치하면 반환
        if (key == current->key) {
            return current;
        }
        //4. 키를 비교하여 이동
        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    //5. 노드를 찾지 못했을 시
    return nullptr;
}

AVLNode* AVLTree::FindMinimumNode(AVLNode* node)const {
    //1. null 검사
    if (node == nullptr) {
        return nullptr;
    }
    //2. 왼쪽 자식이 존재하는 동안 반복
    while (node->left != nullptr) {
        node = node->left;
    }
    //3. 최솟값 반환 (가장 왼쪽 노드가 최솟값)
    return node;
}

AVLNode* AVLTree::FindMaximumNode(AVLNode* node)const {
    //1. null 검사
    if (node == nullptr) {
        return nullptr;
    }
    //2. 오른쪽 자식이 존재하는 동안 반복
    while (node->right != nullptr) {
        node = node->right;
    }
    //3. 최댓값 반환(가장 오른쪽 노드가 최댓값)
    return node;
}
int AVLTree::GetDepth(const AVLNode* node)const {
    //1. null 검사
    if (node == nullptr) {
        return -1;
    }
    //2. 깊이 초기화
    const AVLNode* current = node;
    int depth=0;
    //3. 부모 노드로 이동
    while (current->parent != nullptr) {
        current = current->parent;
        ++depth;
    }
    //4. 깊이 반환
    return depth;
}
void AVLTree::DestroyTree(AVLNode* node) {
    //1. null 검사
    if (node == nullptr) {
        return;
    }
    //2. 왼쪽 서브트리 해제
    DestroyTree(node->left);
    //3. 오른쪽 서브트리 해제
    DestroyTree(node->right);
    //4. 현재 노드 해제 (후위 순회)
    delete node;
}

int AVLTree::GetHeight(const AVLNode* node) const {
  // 과제 명세에 따라 외부 노드(nullptr)의 높이는 0이다.
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int AVLTree::GetSubtreeSize(const AVLNode* node) const {
  if (node == nullptr) {
    return 0;
  }
  return node->subtree_size;
}

void AVLTree::UpdateNode(AVLNode* node) {
  if (node == nullptr) {
    return;
  }
  
  int left_height = GetHeight(node->left);
  int right_height = GetHeight(node->right);
  // 이항 연산자 전후 공백 유지
  node->height = ((left_height > right_height) ? left_height : right_height) + 1;
  
  int left_size = GetSubtreeSize(node->left);
  int right_size = GetSubtreeSize(node->right);
  node->subtree_size = left_size + right_size + 1;
}

int AVLTree::GetBalanceFactor(const AVLNode* node) const {
  if (node == nullptr) {
    return 0;
  }
  return GetHeight(node->left) - GetHeight(node->right);
}

AVLNode* AVLTree::RotateLeft(AVLNode* node) {
  AVLNode* right_child = node->right;
  AVLNode* right_left = right_child->left;
  
  right_child->left = node;
  node->right = right_left;
  
  // 부모 포인터 업데이트
  right_child->parent = node->parent;
  node->parent = right_child;
  if (right_left != nullptr) {
    right_left->parent = node;
  }
  
  UpdateNode(node);
  UpdateNode(right_child);
  
  return right_child;
}

AVLNode* AVLTree::RotateRight(AVLNode* node) {
  AVLNode* left_child = node->left;
  AVLNode* left_right = left_child->right;
  
  left_child->right = node;
  node->left = left_right;
  
  // 부모 포인터 업데이트
  left_child->parent = node->parent;
  node->parent = left_child;
  if (left_right != nullptr) {
    left_right->parent = node;
  }
  
  UpdateNode(node);
  UpdateNode(left_child);
  
  return left_child;
}

void AVLTree::Rebalance(AVLNode* node) {
  while (node != nullptr) {
    UpdateNode(node);
    int balance = GetBalanceFactor(node);
    
    AVLNode* next_parent = node->parent;
    AVLNode* new_sub_root = node;
    
    if (balance > 1) {
      // y의 두 자식 높이가 같을 때(balance == 0)는 Single Rotation(LL)을 수행
      if (GetBalanceFactor(node->left) < 0) {
        node->left = RotateLeft(node->left);
      }
      new_sub_root = RotateRight(node);
    } else if (balance < -1) {
      // y의 두 자식 높이가 같을 때(balance == 0)는 Single Rotation(RR)을 수행
      if (GetBalanceFactor(node->right) > 0) {
        node->right = RotateRight(node->right);
      }
      new_sub_root = RotateLeft(node);
    }
    
    // 회전이 발생하여 서브트리의 루트가 변경된 경우 부모와 연결
    if (new_sub_root != node) {
      if (next_parent == nullptr) {
        root = new_sub_root;
      } else if (next_parent->left == node) {
        next_parent->left = new_sub_root;
      } else {
        next_parent->right = new_sub_root;
      }
    }
    
    // 조상 노드로 거슬러 올라가며 균형 복구 계속 진행
    node = next_parent;
  }
}
// 주의:
// - 과제 명세에서 외부 노드(nullptr)의 높이는 0이다.
// - 루트의 깊이는 0이다.
// - Minimum/Maximum은 전달받은 key 노드가 루트인 부분 트리에서 수행한다.
// - Rank는 (노드 깊이, 순위)를 반환한다.
// - Find/Insert/Erase는 깊이를 반환하고, 대상이 없거나 중복 삽입이면 -1을 반환한다.
// - 실제 함수 정의는 팀원들이 아래에 추가한다.
