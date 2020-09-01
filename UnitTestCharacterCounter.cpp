#include<string>
#include "pch.h"
#include "CppUnitTest.h"
#include "../FileLettersAnalyzer/CharacterCounter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCharacterCounter
{
	TEST_CLASS(UnitTestCharacterCounter)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			CharacterCounter characterCounter('a');
			Assert::AreEqual(characterCounter.getCount(), 1);
			Assert::AreEqual(characterCounter.getCharValue(), 'a');


			CharacterCounter characterCounter1('ô');
			Assert::AreEqual(characterCounter1.getCount(), 1);
			Assert::AreEqual(characterCounter1.getCharValue(), 'ô');
		}

		TEST_METHOD(TestAddCharInstance)
		{
			CharacterCounter characterCounter('a');
			characterCounter.addCharInstance();
			Assert::AreEqual(characterCounter.getCount(), 2);


			characterCounter.addCharInstance();
			Assert::AreEqual(characterCounter.getCount(), 3);


			for (int i = 0; i < 1000; i++) {
				characterCounter.addCharInstance();
			}
			Assert::AreEqual(characterCounter.getCount(), 1003);
		}

		TEST_METHOD(TestToString)
		{
			CharacterCounter characterCounter('a');
			std::string expectedString = "a - 1";
			Assert::AreEqual(characterCounter.toString(), expectedString);


			for (int i = 0; i < 4; i++) {
				characterCounter.addCharInstance();
			}
			expectedString = "a - 5";
			Assert::AreEqual(characterCounter.toString(), expectedString);
		}
	};
}
