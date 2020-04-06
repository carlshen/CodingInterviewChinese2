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

// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

#include <cstdio>
#include <iostream>
#include <string>

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

std::string ReverseSentence(std::string str)
{
    if(str.empty())
        return str;

	std::string pData(str);
	// ��ת��������
	Reverse(pData, pData.begin(), --pData.end());
	//std::cout << "ReverseSentence pData: " << pData.c_str() << std::endl;

    // ��ת�����е�ÿ������
	std::string::iterator pBegin = pData.begin();
	std::string::iterator pEnd = pData.begin();
	std::string::iterator pStop = pData.end();
    while(pBegin != pStop)
    {
		if(*pBegin == ' ')
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ')
        {
            Reverse(pData, pBegin, --pEnd);
			//std::cout << "Reverse pData: " << pData.c_str() << std::endl;
            pBegin = ++pEnd;
        }
		else if (pEnd == (pStop-1))
		{
			Reverse(pData, pBegin, pEnd);
			//std::cout << "end pData: " << pData.c_str() << std::endl;
			pBegin = ++pEnd;
		}
        else
            pEnd ++;
    }

    return pData;
}

// ====================���Դ���====================
void Test(const char* testName, std::string input, std::string expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

	/*if ((input.empty() && expectedResult.empty())) {
		printf("Passed.\n\n");
		return;
	}*/
	std::cout << "before input: " << input.c_str() << std::endl;
	std::cout << "before expectedResult: " << expectedResult.c_str() << std::endl;
	std::string result = ReverseSentence(input);
	std::cout << "after reverse input: " << result.c_str() << std::endl;

    if((input.empty() && expectedResult.empty())
        || (!input.empty() && (result == expectedResult)))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
	std::string input = "I am a student.";
	std::string expected = "student. a am I";

    Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
	std::string input = "Wonderful";
	std::string expected = "Wonderful";

    Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
	std::string input = "We are students.";
	std::string expected = "students. are We";
    Test("Test3", input, expected);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
    Test("Test4", "", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
	std::string input = "   ";
	std::string expected = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

	system("pause");
    return 0;
}

