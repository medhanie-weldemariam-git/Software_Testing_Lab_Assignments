#include "stdafx.h"
#include "CppUnitTest.h"
#include "ScoreComponent.cpp"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScoreComponentTest
{
	TEST_CLASS(ScoreComponentTest)
	{
		ScoreComponent* _sc;

	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			_sc = new ScoreComponent(NULL, NULL, NULL);

		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete _sc;
		}
		TEST_METHOD(ScoreTestAdd)
		{
			_sc->addScore(15);
			_sc->addScore(25);
			Assert::AreEqual(40, _sc->getScore(), L"Score didn't add");
		}
		TEST_METHOD(ScoreTestReset)
		{
			_sc->addScore(15);
			_sc->reset();
			_sc->addScore(20);
			Assert::AreEqual(20, _sc->getScore(), L"Score didn't reset");
		}
		TEST_METHOD(KillTestAdd)
		{
			_sc->addEnemyKill(15);
			_sc->addEnemyKill(25);
			Assert::AreEqual(40, _sc->getNrOfEnemiesKilled(), L"Kill didn't add");
		}
		TEST_METHOD(KillTestReset)
		{
			_sc->addEnemyKill(15);
			_sc->reset();
			_sc->addEnemyKill(20);
			Assert::AreEqual(20, _sc->getNrOfEnemiesKilled(), L"Kill didn't reset");
		}
		TEST_METHOD(TimeTestSet)
		{
			_sc->setTime(15.0f);
			_sc->setTime(25.0f);
			Assert::AreEqual(25.0f, _sc->getTime(), L"Time didn't set");
		}
		TEST_METHOD(TimeTestReset)
		{
			_sc->setTime(15.0f);
			_sc->reset();
			_sc->setTime(25.0f);
			Assert::AreEqual(25.0f, _sc->getTime(), L"Time didn't reset");
		}
	};
}