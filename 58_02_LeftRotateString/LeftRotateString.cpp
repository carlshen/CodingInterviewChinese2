/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������58������������ת�ַ���
// ��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ���"abcdefg"����
// ��2���ú�������������ת2λ�õ��Ľ��"cdefgab"��

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

// ====================���Դ���====================
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

// ���ܲ���
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// �߽�ֵ����
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// �߽�ֵ����
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// ³���Բ���
void Test4()
{
    Test("Test4", "", 6, "");
}

// ³���Բ���
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// ³���Բ���
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

