/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <cstdio>
#include <iostream>
using std::string;

void Reverse(std::string pData, std::string::iterator pBegin, std::string::iterator pEnd)
{
	if (pData.empty())
		return;
	if (pBegin >= pEnd)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++, pEnd--;
	}
}

string LeftRotateString(string pStr, int n)
{
	if (pStr.empty())
		return pStr;
	if (n <= 0 || n >= pStr.length()) {
		return pStr;
	}
	std::string pData(pStr);
	std::string::iterator pBegin = pData.begin();
	std::string::iterator pEnd = pBegin + n - 1;
	// reverse left part n
	Reverse(pData, pBegin, pEnd);
	//std::cout << "LeftRotateString pData: " << pData.c_str() << std::endl;
	pBegin = pEnd + 1;
	pEnd = pData.end() - 1;
	// reverse right part size - n
	Reverse(pData, pBegin, pEnd);
	//std::cout << "LeftRotateString pData: " << pData.c_str() << std::endl;
	pBegin = pData.begin();
	// rever all
	Reverse(pData, pBegin, pEnd);
	//std::cout << "LeftRotateString pData: " << pData.c_str() << std::endl;

    return pData;
}

// ====================测试代码====================
void Test(const char* testName, string input, int num, string expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

	std::cout << "before num: " << num << " , input: " << input.c_str() << std::endl;
	std::cout << "before expectedResult: " << expectedResult.c_str() << std::endl;
	string result = LeftRotateString(input, num);
	std::cout << "after reverse result: " << result.c_str() << std::endl;

    if((input.empty() && expectedResult.empty())
        || (!input.empty() && result == expectedResult))
		std::cout << "Passed." << std::endl;
    else
		std::cout << "Failed. " << std::endl;
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", "", 6, "");
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

	system("pause");
    return 0;
}

