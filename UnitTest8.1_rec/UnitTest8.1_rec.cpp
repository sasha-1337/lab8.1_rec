#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1_rec/lab8.1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
	TEST_CLASS(UnitTest81rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			int count = 17;

			char* s = "sasha.stu..de..nt";

			t = Find_Dot(s, count, 0);
			Assert::AreEqual(t, 13);
		}
	};
}
