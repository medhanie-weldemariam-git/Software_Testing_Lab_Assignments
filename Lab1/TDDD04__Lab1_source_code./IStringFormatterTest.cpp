#include "stdafx.h"
#include "CppUnitTest.h"
#include "main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TDDD04_lab1Btests
{		
	TEST_CLASS(IStringFormatterTest)
	{
		testIStringFormatter *formatter;
	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			formatter = new testIStringFormatter();
		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete formatter;
		}
		
		TEST_METHOD(leftString)
		{
			//test for leftString
			std::string test = "even";
			std::string s = formatter->leftString(test, 10, '+');
			Assert::AreEqual(std::string("even++++++"), s, L"not working");

			s = formatter->leftString(test, 1, '-');
			Assert::AreEqual(std::string("e"), s, L"not working");

			s = formatter->leftString(test, 4, '-');
			Assert::AreEqual(std::string("even"), s, L"not working");

			s = formatter->leftString(test, 5, '-');
			Assert::AreEqual(std::string("even-"), s, L"not working");

			s = formatter->leftString(test, 5, '-');
			Assert::AreNotEqual(std::string("even"), s, L"not working");
		}
		TEST_METHOD(rightString)
		{ 
			//test for rightString
			std::string test = "even";
			std::string s = formatter->rightString(test, 10, '+');
			Assert::AreEqual(std::string("++++++even"), s, L"not working");

			s = formatter->rightString(test, 1, '-');
			Assert::AreEqual(std::string("n"), s, L"not working");

			s = formatter->rightString(test, 4, '-');
			Assert::AreEqual(std::string("even"), s, L"not working");

			s = formatter->rightString(test, 2, '-');
			Assert::AreEqual(std::string("en"), s, L"not working");

			s = formatter->rightString(test, 5, '-');
			Assert::AreEqual(std::string("-even"), s, L"not working");

			s = formatter->rightString(test, 5, '-');
			Assert::AreNotEqual(std::string("even"), s, L"not working");
		}
		TEST_METHOD(centerStringEven)
		{
			//test for CenterString and even stringlength
			std::string test = "even";
			std::string s = formatter->centerString(test, 2, '+');
			Assert::AreEqual(std::string("ve"), s, L"not working");

			s = formatter->centerString(test, 4, '+');
			Assert::AreEqual(std::string("even"), s, L"not working");

			s = formatter->centerString(test, 6, '+');
			Assert::AreEqual(std::string("+even+"), s, L"not working");

			s = formatter->centerString(test, 1, '+');
			Assert::AreEqual(std::string("e"), s, L"not working");

			s = formatter->centerString(test, 3, '+');
			Assert::AreEqual(std::string("ven"), s, L"not working");

			s = formatter->centerString(std::string("evennn"), 3, '+');
			Assert::AreEqual(std::string("enn"), s, L"not working");

			s = formatter->centerString(test, 5, '+');
			Assert::AreEqual(std::string("even+"), s, L"not working");

			s = formatter->centerString(test, 7, '+');
			Assert::AreEqual(std::string("+even++"), s, L"not working");
		}
		TEST_METHOD(centerStringOdd)
		{
			//test for CenterString and odd stringlength
			std::string test = "oddly";
			std::string s = formatter->centerString(test, 1, '+');
			Assert::AreEqual(std::string("d"), s, L"not working");

			s = formatter->centerString(test, 3, '+');
			Assert::AreEqual(std::string("ddl"), s, L"not working");

			s = formatter->centerString(test, 7, '+');
			Assert::AreEqual(std::string("+oddly+"), s, L"not working");

			s = formatter->centerString(std::string("odd"), 2, '+');
			Assert::AreEqual(std::string("dd"), s, L"not working");

			s = formatter->centerString(std::string("odd"), 3, '+');
			Assert::AreEqual(std::string("odd"), s, L"not working");

			s = formatter->centerString(test, 4, '+');
			Assert::AreEqual(std::string("ddly"), s, L"not working");

			s = formatter->centerString(test, 6, '+');
			Assert::AreEqual(std::string("oddly+"), s, L"not working");

			s = formatter->centerString(test, 8, '+');
			Assert::AreEqual(std::string("+oddly++"), s, L"not working");

			s = formatter->centerString(std::string("odd"), 4, '*');
			Assert::AreEqual(std::string("odd*"), s, L"not working");

			s = formatter->centerString(std::string("odd"), 5, '*');
			Assert::AreEqual(std::string("*odd*"), s, L"not working");

			s = formatter->centerString(std::string("odd"), 6, '*');
			Assert::AreEqual(std::string("*odd**"), s, L"not working");


			
		}
	};
}