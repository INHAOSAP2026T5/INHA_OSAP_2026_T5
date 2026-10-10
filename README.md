# avl-treel-project
AVL Tree implementation of STL set operations in C++
AVL Tree STL Set Project

1. Project Overview

본 프로젝트는 C++로 AVL Tree 기반의 정수형 Set을 구현하고, STL set과 관련된 기본 및 고급 연산을 제공하는 것을 목표로 한다.

AVL Tree의 균형 유지 기법을 활용하여 각 연산의 시간 복잡도를 O(log n)으로 유지한다.

2. Features

Basic Operations

Find(x): 키 x의 존재 여부와 깊이 반환

Insert(x): 키 x 삽입 및 깊이 반환

Empty(): 집합의 공백 여부 반환

Size(): 원소 개수 반환

Minimum(x): x를 루트로 하는 부분 트리의 최솟값과 깊이 반환

Maximum(x): x를 루트로 하는 부분 트리의 최댓값과 깊이 반환

Advanced Operations

Rank(x): 키 x의 깊이와 순위 반환

Erase(x): 키 x 삭제 및 삭제 전 깊이 반환

3. Tech Stack

Language: C++

Data Structure: AVL Tree

Version Control: Git, GitHub

Code Review: Pull Request

4. Project Structure

avl-tree-stl-project/
├── README.md
├── LICENSE
├── .gitignore
├── include/
│   └── avl_tree.h
├── src/
│   ├── avl_tree.cpp
│   └── main.cpp
└── tests/
    └── test_avl_tree.cpp

5. Branch Strategy

main: 검증이 완료된 통합 코드

feature/avl-node: 노드 구조 및 균형 조정

feature/insert-find: 삽입 및 탐색

feature/basic-operations: 기본 연산

feature/rank-erase: 순위 및 삭제 연산

feature/tests: 테스트 코드
기능별 브랜치에서 개발하고 Pull Request 및 코드 리뷰를 거쳐 main에 병합한다.

6. Development Rules

기능별 브랜치를 사용한다.
모든 변경 사항은 Pull Request로 제출한다.
Pull Request마다 최소 1명의 Reviewer를 지정한다.
코드 리뷰에서 발견된 문제를 수정한 후 병합한다.
코드 스타일과 라이선스 주석을 일관되게 유지한다.
각 기능의 정상 동작 및 예외 상황을 테스트한다.

7. Complexity Requirements

Empty(), Size(): O(1)

그 외 모든 연산: O(log n)

8. Team Members

Name

Role

팀원 1

담당 기능 작성

팀원 2

담당 기능 작성

팀원 3

담당 기능 작성

팀원 4

테스트 및 코드 리뷰

9. License

This project is licensed under the MIT License.
