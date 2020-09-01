#include<string>
#include "pch.h"
#include "CppUnitTest.h"
#include "../FileLettersAnalyzer/LettersAnalyzer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLettersAnalyzer
{
	TEST_CLASS(UnitTestLettersAnalyzer)
	{
	public:

		TEST_METHOD(TestIsRusEngLetter)
		{
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('a'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('b'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('c'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('z'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('A'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('B'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('Y'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('Z'), true);

			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('à'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('ã'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('ÿ'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('À'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('Ä'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('Þ'), true);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('ß'), true);

			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('4'), false);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('*'), false);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter(']'), false);
			Assert::AreEqual(LettersAnalyzer::isRusEngLetter('@'), false);
		}

		TEST_METHOD(TestAddLetter)
		{
			LettersAnalyzer analyzer;
			analyzer.addLetter('a');
			analyzer.addLetter('b');
			analyzer.addLetter('c');
			analyzer.addLetter('b');
			analyzer.addLetter('&');
			analyzer.addLetter('4');

			vector<CharacterCounter> expectedResult{
				CharacterCounter('a'),
				CharacterCounter('b'),
				CharacterCounter('c'),
			};
			expectedResult[1].addCharInstance();

			vector<CharacterCounter> result = analyzer.getLetters();

			//compare vector manually
			bool flag = true;
			if (result.size() != expectedResult.size()) {
				flag = false;
			}
			for (int i = 0; i < result.size(); i++) {
				if (result[i] != expectedResult[i]) {
					flag = false;
				}
			}

			Assert::AreEqual(flag, true);
		}

		TEST_METHOD(TestSortByDescendingCount)
		{
			LettersAnalyzer analyzer;
			analyzer.addLetter('a');
			analyzer.addLetter('b');
			analyzer.addLetter('c');
			analyzer.addLetter('b');
			analyzer.addLetter('b');
			analyzer.addLetter('c');

			vector<CharacterCounter> expectedResult{
				CharacterCounter('b'),
				CharacterCounter('c'),
				CharacterCounter('a'),
			};
			expectedResult[0].addCharInstance();
			expectedResult[0].addCharInstance();
			expectedResult[1].addCharInstance();

			analyzer.sortByDescendingCount();
			vector<CharacterCounter> result = analyzer.getLetters();

			//compare vector manually
			bool flag = true;
			if (result.size() != expectedResult.size()) {
				flag = false;
			}
			for (int i = 0; i < result.size(); i++) {
				if (result[i] != expectedResult[i]) {
					flag = false;
				}
			}

			Assert::AreEqual(flag, true);
		}

		TEST_METHOD(TestAddFromString)
		{
			LettersAnalyzer analyzer;
			analyzer.addFromString("abcbbda");

			vector<CharacterCounter> expectedResult{
				CharacterCounter('a'),
				CharacterCounter('b'),
				CharacterCounter('c'),
				CharacterCounter('d'),
			};
			expectedResult[0].addCharInstance();
			expectedResult[1].addCharInstance();
			expectedResult[1].addCharInstance();

			vector<CharacterCounter> result = analyzer.getLetters();

			//compare vector manually
			bool flag = true;
			if (result.size() != expectedResult.size()) {
				flag = false;
			}
			for (int i = 0; i < result.size(); i++) {
				if (result[i] != expectedResult[i]) {
					flag = false;
				}
			}

			Assert::AreEqual(flag, true);
		}

		TEST_METHOD(TestToString)
		{
			LettersAnalyzer analyzer;
			analyzer.addLetter('a');
			analyzer.addLetter('b');
			analyzer.addLetter('c');
			analyzer.addLetter('b');
			analyzer.addLetter('b');
			analyzer.addLetter('c');

			analyzer.sortByDescendingCount();
			string result = analyzer.toString();
			string expectedResult = "b - 3\nc - 2\na - 1\n";

			Assert::AreEqual(result, expectedResult);
		}
	};
}