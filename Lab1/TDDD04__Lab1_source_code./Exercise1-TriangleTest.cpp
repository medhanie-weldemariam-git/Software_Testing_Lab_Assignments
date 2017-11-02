#include "stdafx.h"
#include "CppUnitTest.h"
#include <triangle.h>
#include "ToStringMap.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TraingleTest
{		
	TEST_CLASS(TraingleTest)
	{
		Triangle *_triangle;
	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			_triangle = new Triangle();
		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete _triangle;
		}
		TEST_METHOD(testEquilateral)
		{
			// Test if the triangle is eqilateral
			int sides[3] = { 3, 3, 3 };
			Assert::AreEqual(Triangle::EQUILATERAL, _triangle->getType(sides, 3), L"Trangle is not equlaterial");

			// Test if the triangle is not eqilateral
			int sides2[3] = { 2, 3, 3 };
			Assert::AreNotEqual(Triangle::EQUILATERAL, _triangle->getType(sides2, 3), L"Trangle is equlaterial");

			int sides3[3] = { 3, 2, 3 };
			Assert::AreNotEqual(Triangle::EQUILATERAL, _triangle->getType(sides3, 3), L"Trangle is equlaterial");

			int sides4[3] = { 3, 3, 2 };
			Assert::AreNotEqual(Triangle::EQUILATERAL, _triangle->getType(sides4, 3), L"Trangle is equlaterial");

			int sides5[3] = { 2, 3, 4 };
			Assert::AreNotEqual(Triangle::EQUILATERAL, _triangle->getType(sides5, 3), L"Trangle is equlaterial");
			
		}
		TEST_METHOD(testIsosceles)
		{
			// Test if the triangle is isosceles
			int sides1[3] = { 3, 3, 2 };
			Assert::AreEqual(Triangle::ISOSCELES, _triangle->getType(sides1, 3), L"Trangle is not Isosceles");

			int sides2[3] = { 3, 2, 3 };
			Assert::AreEqual(Triangle::ISOSCELES, _triangle->getType(sides2, 3), L"Trangle is not Isosceles");

			int sides3[3] = { 2, 3, 3 };
			Assert::AreEqual(Triangle::ISOSCELES, _triangle->getType(sides3, 3), L"Trangle is not Isosceles");

			// Test that it is not isosceles
			int sides4[3] = { 3, 3, 3 };
			Assert::AreNotEqual(Triangle::ISOSCELES, _triangle->getType(sides4, 3), L"Trangle is Isosceles");
		}
		TEST_METHOD(testScalene)
		{
			// Test if the triangle is scalene
			int sides1[3] = { 2, 3, 4 };
			Assert::AreEqual(Triangle::SCALENE, _triangle->getType(sides1, 3), L"Trangle is not scalene");
			
			// Test that it is not scalene
			int sides2[3] = { 2, 2, 3 };
			Assert::AreNotEqual(Triangle::SCALENE, _triangle->getType(sides2, 3), L"triangle is scalene"); 

			int sides3[3] = { 2, 3, 2 };
			Assert::AreNotEqual(Triangle::SCALENE, _triangle->getType(sides3, 3), L"Trangle is scalene");

			int sides4[3] = { 3, 2, 2 };
			Assert::AreNotEqual(Triangle::SCALENE, _triangle->getType(sides4, 3), L"Trangle is scalene");

			int sides5[3] = { 2, 2, 2 };
			Assert::AreNotEqual(Triangle::SCALENE, _triangle->getType(sides5, 3), L"Trangle is scalene");
			
		}
		TEST_METHOD(testInvalidTriangle)
		{
			int sides[3] = { 0, 0, 0 };

			/*
			* Method 1: Testing exceptional cases - Using try-catch block
			*/
			bool exceptionThrown = false;
			try
			{
				_triangle->getType(sides, 3);
			}
			catch (InvalidTriangleException& ex)
			{
				auto desc = ex.what();
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown, L"Exception not thrown");

			/*
			* Method 2: Testing exceptional cases - Using C++11 Lambda expression
			*/
			Assert::ExpectException<InvalidTriangleException>([&]
			{
				_triangle->getType(sides, 3);
			});
		}

		/*
		insert your test implementation here
		*/
	};
}