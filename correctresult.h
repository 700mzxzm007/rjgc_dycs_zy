#pragma once
#include<iostream>
#include<vector>
int maxSubArray(std::vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for (const auto& x : nums) {
        pre = std::max(pre + x, x);
        maxAns = std::max(maxAns, pre);
    }
    return maxAns;
}

