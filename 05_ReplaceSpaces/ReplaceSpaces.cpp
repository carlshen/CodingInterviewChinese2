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

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <cstdio>
#include <cstring>
#include <iostream>
using std::string;

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
std::string ReplaceBlank(std::string str)
{
    if(str.length() <= 0)
        return str;

    /*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
    int originalLength = str.length();
    int numberOfBlank = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if(*it == ' ')
            ++ numberOfBlank;
    }
	//std::cout << "ReplaceBlank blank size: " << numberOfBlank << std::endl;

    /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
    size_t newLength = originalLength + numberOfBlank * 2;
	string result(str);
	result.resize(newLength);

	size_t indexOfOriginal = originalLength;
	size_t indexOfNew = newLength;
	//std::cout << "ReplaceBlank originalLength size: " << originalLength << std::endl;
	//std::cout << "ReplaceBlank newLength size: " << newLength << std::endl;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
			result[indexOfNew --] = '0';
			result[indexOfNew --] = '2';
			result[indexOfNew --] = '%';
        }
        else
        {
			result[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
	return result;
}

// ====================���Դ���====================
void Test(char* testName, std::string str, std::string expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
	if (expected.empty() && str.empty()) {
		printf("passed.\n");
		return;
	}

	std::string result = ReplaceBlank(str);
	std::cout << "ReplaceBlank result: " << result.c_str() << std::endl;

    if(!expected.empty() && result.empty())
        printf("failed.\n");
    else if(expected.empty() && !result.empty())
        printf("failed.\n");
    else if(result == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
	std::string str("hello world");
    Test("Test1", str, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	std::string  str = " helloworld";
    Test("Test2", str, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	std::string  str = "helloworld ";
    Test("Test3", str, "helloworld%20");
}

// �����������ո�
void Test4()
{
	std::string  str = "hello  world";
    Test("Test4", str, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	std::string  str = "";
    Test("Test6", str, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	std::string str = " ";
    Test("Test7", str, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	std::string str = "helloworld";
    Test("Test8", str, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
	std::string  str = "   ";
    Test("Test9", str, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
	//Test5();
    Test6();
    Test7();
    Test8();
    Test9();

	system("pause");
    return 0;
}

