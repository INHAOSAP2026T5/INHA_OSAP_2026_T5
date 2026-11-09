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
#include <iostream>
#include <string>
#include <utility>
#include "AVLTree.h"

using namespace std;

int main() {
    AVLTree tree;
    string command;
    int key;

    // 명령어를 입력받아 해당 AVLTree 함수를 호출한다.
    // 입력은 EOF가 들어올 때까지 반복한다.
    while (cin >> command) {
        if (command == "Find") {
            cin >> key;
            cout << tree.find(key) << '\n';
        }
        else if (command == "Insert") {
            cin >> key;
            cout << tree.insert(key) << '\n';
        }
        else if (command == "Empty") {
            cout << (tree.empty() ? 1 : 0) << '\n';
        }
        else if (command == "Size") {
            cout << tree.size() << '\n';
        }
        else if (command == "Minimum") {
            cin >> key;
            pair<int, int> result = tree.minimum(key);
            cout << result.first << ' ' << result.second << '\n';
        }
        else if (command == "Maximum") {
            cin >> key;
            pair<int, int> result = tree.maximum(key);
            cout << result.first << ' ' << result.second << '\n';
        }
        else if (command == "Rank") {
            cin >> key;
            pair<int, int> result = tree.rank(key);
            if (result.first == -1) {
                cout << -1 << '\n';
            } else {
                cout << result.first << ' ' << result.second << '\n';
            }
        }
        else if (command == "Erase") {
            cin >> key;
            cout << tree.erase(key) << '\n';
        }
        else {
            // 정의되지 않은 명령어는 과제 명세에 없으므로 별도 출력하지 않는다.
        }
    }

    return 0;
}
