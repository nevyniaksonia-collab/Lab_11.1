#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <cstdio> 
#define UNIT_TEST 
#include "../Lab_11.1/Lab_11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(CountInFileTests)
{
public:

    // Допоміжна функція для створення файлу з потрібним змістом
    void CreateTestFile(const string& filename, const string& content)
    {
        ofstream fout(filename);
        fout << content;
        fout.close();
    }
    TEST_METHOD(Test_PairsFound)
    {
        string fileName = "test_normal.txt";
        CreateTestFile(fileName, "noon onion");

        int result = CountInFile(fileName.c_str());

        Assert::AreEqual(4, result);

        remove(fileName.c_str());
    }

    TEST_METHOD(Test_NoPairs)
    {
        string fileName = "test_empty_logic.txt";
        CreateTestFile(fileName, "Hello world! Just text.");

        int result = CountInFile(fileName.c_str());

        Assert::AreEqual(0, result);
        remove(fileName.c_str());
    }

    TEST_METHOD(Test_Overlap)
    {
        string fileName = "test_overlap.txt";
        CreateTestFile(fileName, "non");

        int result = CountInFile(fileName.c_str());

        Assert::AreEqual(2, result);
        remove(fileName.c_str());
    }

    TEST_METHOD(Test_EmptyFile)
    {
        string fileName = "test_zero.txt";
        CreateTestFile(fileName, ""); 

        int result = CountInFile(fileName.c_str());

        Assert::AreEqual(0, result);
        remove(fileName.c_str());
    }

    TEST_METHOD(Test_MissingFile)
    {
        
        remove("ghost_file.txt");

        int result = CountInFile("ghost_file.txt");

        Assert::AreEqual(-1, result);
    }
};