#include "stdafx.h"
#include "CppUnitTest.h"
#include <algorithm>
#include <GameObject.cpp>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameObjectTest
{
	TEST_CLASS(GameObjectTest)
	{
		GameObject* _go;

	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			_go = new GameObject(NULL, NULL);
		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete _go;
		}
		TEST_METHOD(TestOneHealth)
		{
			_go->Health = 1;
			Assert::AreEqual(false, _go->isDead(), L"Player is dead but has 1 health.");
		}
		TEST_METHOD(TestZeroHealth)
		{
			_go->Health = 0;
			Assert::AreEqual(true, _go->isDead(), L"Player is not dead but has 0 health.");
		}
		TEST_METHOD(TestMinusOneHealth)
		{
			_go->Health = -1;
			Assert::AreEqual(true, _go->isDead(), L"Player is not dead but has -1 health.");
		}
	};
}