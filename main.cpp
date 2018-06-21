#include <gtest/gtest.h>
#include <gmock/gmock.h>
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	//testing::InitGoogleMock(&argc, argv);
#if defined(_MSC_VER)
	if (RUN_ALL_TESTS())
		system("pause");
#else
	return RUN_ALL_TESTS();
#endif
}