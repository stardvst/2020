#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProjectMath
{
	TEST_CLASS(UnitTestMult)
	{
	public:
		TEST_METHOD(TestMultiply)
		{
			int i = 12, j = 0;
			int mult = i * j;
			//Assert::AreEqual(mult, 1); // fail
			Assert::AreEqual(mult, 0);
		}
	};

	TEST_CLASS(UnitTestAdd)
	{
	public:
		TEST_METHOD(TestAdd)
		{
			int i = 12, j = 5;
			int sum = i + j;
			//Assert::AreEqual(sum, 24); // fail
			Assert::AreEqual(sum, 17);
		}
	};
}
