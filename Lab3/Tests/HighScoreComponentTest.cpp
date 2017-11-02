#include "stdafx.h"
#include "CppUnitTest.h"
#include <HighScoreComponent.cpp>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HighscoreTest
{
	TEST_CLASS(HighscoreTest)
	{
		HighScoreComponent* _highScoreComponent;
		std::vector<int> vec;

	public:
		TEST_METHOD_INITIALIZE(setUp)
		{

			_highScoreComponent = new HighScoreComponent(NULL, NULL, NULL, NULL, NULL, NULL);
			vec.clear();

		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete _highScoreComponent;
		}
		TEST_METHOD(TestInsertZeroScore)
		{
			_highScoreComponent->submitScore(0);
			
			Assert::AreEqual(vectorToString(vec), vectorToString(_highScoreComponent->scores()), L"HighScore added a zero result");
		}
		TEST_METHOD(TestInsertNonZeroScore)
		{
			_highScoreComponent->submitScore(10);
			
			vec.push_back(10);
			Assert::AreEqual(vectorToString(vec), vectorToString(_highScoreComponent->scores()), L"HighScore didn't add a non-zero result");
		}
		TEST_METHOD(TestInsertMoreThanTenScores)
		{
			for (int i = 1; i <= 13; i++){
				_highScoreComponent->submitScore(10);
			}
			
			for (int i = 1; i <= 10; i++){
				vec.push_back(10);
			}
			
			Assert::AreEqual(vectorToString(vec), vectorToString(_highScoreComponent->scores()), L"Added more than 10 scores");
		}
		TEST_METHOD(TestOrderingOfScores)
		{
			for (int i = 3; i > 0; i--){
				_highScoreComponent->submitScore(10*i);
			}
			
			for (int i = 3; i > 0; i--){
				vec.push_back(10 * i);
			}
			std::sort(vec.begin(), vec.end());
			std::reverse(vec.begin(), vec.end());
			Assert::AreEqual(vectorToString(vec), vectorToString(_highScoreComponent->scores()), L"Didn't order the scores");
		}
		TEST_METHOD(TestLastScoreIndex)
		{
			for (int i = 3; i > 0; i--){
				_highScoreComponent->submitScore(10 * i);
			}
			_highScoreComponent->submitScore(25);

			Assert::AreEqual(1, _highScoreComponent->lastScoreIndex(), L"Didn't get the right score index.");
		}
		TEST_METHOD(TestWriteScoresToFile)
		{
			for (int i = 1; i <= 5; i++){
				_highScoreComponent->submitScore(10);
			}
			bool wtf = _highScoreComponent->writeToFile("testwrite.txt");
			
			Assert::AreEqual(true, wtf, L"Didn't write the scores to file");
		}
		TEST_METHOD(TestReadScoresFromFile)
		{
			
			for (int i = 1; i <= 5; i++){
				vec.push_back(10);
			}
			_highScoreComponent->readFromFile("testread.txt");

			Assert::AreEqual(vectorToString(vec), vectorToString(_highScoreComponent->scores()), L"Didn't read the scores from file");
		}

		std::string vectorToString(std::vector<int> vec) {
			std::string str;
			if (!vec.empty()){
				std::ostringstream oss;
				std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<int>(oss, ","));

				oss << vec.back();
				str = oss.str();
			}
			return str;
		}
		
	};
}