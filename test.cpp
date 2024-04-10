#include "pch.h"
#include<gtest/gtest.h>
#include<vector>
#include"correctresult.h"
#include"getmagnitudearray.h"
using namespace std;

int MaxConstantArray(const vector<int> num) {
	vector<int>dp(num.size());
	dp[0] = num[0];
	for (int i = 1; i < num.size(); i++) {
		if (num[i] < 0)dp[i] = dp[i - 1];
		else {
			int maxarr = 0;
			int maxj = num[i];
			for (int j = i; j >= 0; j--) {
				maxarr += num[j];
				maxj = max(maxj, maxarr);
			}
			dp[i] = max(maxj, dp[i - 1]);

		}
	}
	if (dp[dp.size() - 1] <= 0)return 0;
	return dp[dp.size() - 1];

}

TEST(MaxConstantArrayTest, Arraytest0) {
  EXPECT_EQ(MaxConstantArray({ 5 }), 5);
  EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest1){
	EXPECT_EQ(MaxConstantArray({ 1, 2, 3, 4, 5 }), 15);
	EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest2) {
	EXPECT_EQ(MaxConstantArray({ -2, 11, -4, 13, -5, -2 }), 20);
	EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest3) {
	EXPECT_EQ(MaxConstantArray({ 5 }), 5);
	EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest4) {
	EXPECT_EQ(MaxConstantArray({ -5 }), 0);
	EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest5) {
	EXPECT_EQ(MaxConstantArray({ 0, -2, 3, 5, -1, 2 }), 9);
	EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest6) {
	EXPECT_EQ(MaxConstantArray({ -5, -2, -3, 7, -4 }), 7);
	EXPECT_TRUE(true);
}

TEST(MaxConstantArrayTest, Arraytest7) {
	EXPECT_EQ(MaxConstantArray({ 2, 3, -1, 5, 6 }), 15);
	EXPECT_TRUE(true);
}


TEST(MaxConstantArrayTest, Arraytest8) {
	EXPECT_EQ(MaxConstantArray({ 2, 3, -1, 5, 6 }), 15);
	EXPECT_TRUE(true);
}

//获得正确答案的函数从LeetCode上获取
//一个数组里面有大于等于1000且小于10000个数据
TEST(MaxConstantArrayTest, Arraytest9) {
	vector<int>arr = generate_random_array4();
	EXPECT_EQ(MaxConstantArray(arr), maxSubArray(arr));
	EXPECT_TRUE(true);
}

//一个数组里面有大于等于10000且小于99999个数据
TEST(MaxConstantArrayTest, Arraytest10) {
	vector<int>arr = generate_random_array5();
	EXPECT_EQ(MaxConstantArray(arr), maxSubArray(arr));
	EXPECT_TRUE(true);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}