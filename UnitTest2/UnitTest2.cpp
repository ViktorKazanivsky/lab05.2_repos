#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2/Lab_5.02.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double z;
			z = A(0.5, 1, 12.0);
			Assert::AreEqual(z, 1.0);
		}
	};
}