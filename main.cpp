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
#include "AVLTree.h"

#include <iostream>
#include <string>
#include <utility>

int main() {
    AVLTree tree;
    std::string command;
    int key;

    // EOF가 입력될 때까지 명령어를 읽고 해당 기능을 실행한다.
    while (std::cin >> command) {
        if (command == "Find") {
            std::cin >> key;
            std::cout << tree.Find(key) << '\\n';
        } else if (command == "Insert") {
            std::cin >> key;
            std::cout << tree.Insert(key) << '\\n';
        } else if (command == "Empty") {
            std::cout << (tree.Empty() ? 1 : 0) << '\\n';
        } else if (command == "Size") {
            std::cout << tree.Size() << '\\n';
        } else if (command == "Minimum") {
            std::cin >> key;
            std::pair<int, int> result = tree.Minimum(key);
            std::cout << result.first << ' ' << result.second << '\\n';
        } else if (command == "Maximum") {
            std::cin >> key;
            std::pair<int, int> result = tree.Maximum(key);
            std::cout << result.first << ' ' << result.second << '\\n';
        } else if (command == "Rank") {
            std::cin >> key;
            std::pair<int, int> result = tree.Rank(key);

            if (result.first == -1) {
                std::cout << -1 << '\\n';
            } else {
                std::cout << result.first << ' ' << result.second << '\\n';
            }
        } else if (command == "Erase") {
            std::cin >> key;
            std::cout << tree.Erase(key) << '\\n';
        }
    }

    return 0;
}

