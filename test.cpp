#include <gtest/gtest.h>
  
int main(int argc, char** argv) {  
    testing::InitGoogleTest(&argc, argv);  
  
    // Runs all tests using Google Test.  
    return RUN_ALL_TESTS();  
}  

TEST(test, test)
{
    EXPECT_TRUE((3));
    EXPECT_TRUE((5));
    EXPECT_TRUE((11));
    EXPECT_TRUE((23));
    EXPECT_TRUE((17));
}