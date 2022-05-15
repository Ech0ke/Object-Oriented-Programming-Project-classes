#include "pch.h"
#include "CppUnitTest.h"
#include "studentas.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTestV20


{
	TEST_CLASS(StudentoTestai)
	{
	public:
		
		TEST_METHOD(TestGetVardas)
		{
			Studentas a;
			std::string expected = "Aidas";
			a.setVardas(expected);
			Assert::AreEqual(expected, a.getVardas());
		}
		TEST_METHOD(TestVidurkis)
		{ 
			Studentas b;
			int expected = 3;
			b.setNd(5);
			b.setNd(8);
			b.setNd(9);
			Assert::AreEqual(expected, b.sizeNd());
		}
	};
}
