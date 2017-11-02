#include "stdafx.h"
#include "CppUnitTest.h"
#include <Player.cpp>
#include <PlayerAI.cpp>
#include "InputDeviceRightStub.h"
#include "InputDeviceLeftStub.h"
#include "InputDeviceUpStub.h"
#include "InputDeviceDownStub.h"
#include "InputDeviceTrueStub.h"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerAITest
{
	TEST_CLASS(PlayerAITest)
	{
		Player* _player;
		PlayerAI* _playerAI;
		InputDeviceRightStub* _inputDeviceRightStub;
		InputDeviceLeftStub* _inputDeviceLeftStub;
		InputDeviceUpStub* _inputDeviceUpStub;
		InputDeviceDownStub* _inputDeviceDownStub;
		InputDeviceTrueStub* _inputDeviceTrueStub;
	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			
		}
		TEST_METHOD_CLEANUP(tearDown)
		{

		}
		TEST_METHOD(TestRight)
		{
			_inputDeviceRightStub = new InputDeviceRightStub();
			_playerAI = new PlayerAI(_inputDeviceRightStub);
			_player = new Player(NULL, _playerAI);

			float preTickX = _player->getVelocity().x;
			_playerAI->tick(_player, 0.0f, NULL);
			float postTickX = _player->getVelocity().x;

			Assert::AreEqual(preTickX + PLAYER_ACCELERATION, postTickX, L"Didn't accelerate right");
		}
		TEST_METHOD(TestLeft)
		{
			_inputDeviceLeftStub = new InputDeviceLeftStub();
			_playerAI = new PlayerAI(_inputDeviceLeftStub);
			_player = new Player(NULL, _playerAI);

			float preTickX = _player->getVelocity().x;
			_playerAI->tick(_player, 0.0f, NULL);
			float postTickX = _player->getVelocity().x;

			Assert::AreEqual(preTickX - PLAYER_ACCELERATION, postTickX, L"Didn't accelerate left");
		}
		TEST_METHOD(TestUp)
		{
			_inputDeviceUpStub = new InputDeviceUpStub();
			_playerAI = new PlayerAI(_inputDeviceUpStub);
			_player = new Player(NULL, _playerAI);

			float preTickY = _player->getVelocity().y;
			_playerAI->tick(_player, 0.0f, NULL);
			float postTickY = _player->getVelocity().y;

			Assert::AreEqual(preTickY - PLAYER_ACCELERATION, postTickY, L"Didn't accelerate up");
		}
		TEST_METHOD(TestDown)
		{
			_inputDeviceDownStub = new InputDeviceDownStub();
			_playerAI = new PlayerAI(_inputDeviceDownStub);
			_player = new Player(NULL, _playerAI);

			float preTickY = _player->getVelocity().y;
			_playerAI->tick(_player, 0.0f, NULL);
			float postTickY = _player->getVelocity().y;

			Assert::AreEqual(preTickY + PLAYER_ACCELERATION, postTickY, L"Didn't accelerate down");
		}
		TEST_METHOD(TestShotFired)
		{
			_inputDeviceTrueStub = new InputDeviceTrueStub();
			_playerAI = new PlayerAI(_inputDeviceTrueStub);
			_player = new Player(NULL, _playerAI);
			_player->Ammo = 1;
			bool shot = _player->fire(0);
			_playerAI->tick(_player, 0.0f, NULL);
			

			Assert::AreEqual(true, shot, L"Shots didn't fire");
		}
		
	};
}