#include <gtest/gtest.h>
#include "ri.hpp"  

int main(int argc, char** argv) {  
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();  
}  

#include <vector>
using namespace std;

TEST(test, ri)
{
	vector<vector<int> > v1={{1,2},{3,4}};
	Solution s;
	s.rotate(v1);
	EXPECT_EQ(v1[1][1],2);
}
