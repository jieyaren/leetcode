#include <gtest/gtest.h>

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/*
������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
����	C4996	'std::tr1': warning STL4002 : The non - Standard std::tr1 namespace and TR1 - only machinery are deprecated and will be REMOVED.You can define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.lintcode	D : \code\vcpkg\installed\x86 - windows\include\gtest\gtest - printers.h	605
*/