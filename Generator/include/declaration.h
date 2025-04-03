#pragma once
#include <string>
#include <unordered_set>
#include <zint.h>
#include <iostream>

using namespace std;

// 显示进度条
void display_progress_bar(int i, int count) {
    int progress = (i + 1) * 100 / count;
    std::cout << "\rGenerating QRCodes: [" << std::string(progress / 2, '=')
        << std::string(50 - progress / 2, ' ') << "] "
        << progress << "%" << std::flush;
};