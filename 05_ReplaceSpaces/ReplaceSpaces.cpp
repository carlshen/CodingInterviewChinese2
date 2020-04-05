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

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <cstdio>
#include <cstring>
#include <iostream>
using std::string;

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
std::string ReplaceBlank(std::string str)
{
    if(str.length() <= 0)
        return str;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = str.length();
    int numberOfBlank = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if(*it == ' ')
            ++ numberOfBlank;
    }
	//std::cout << "ReplaceBlank blank size: " << numberOfBlank << std::endl;

    /*newLength 为把空格替换成'%20'之后的长度*/
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

// ====================测试代码====================
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

// 空格在句子中间
void Test1()
{
	std::string str("hello world");
    Test("Test1", str, "hello%20world");
}

// 空格在句子开头
void Test2()
{
	std::string  str = " helloworld";
    Test("Test2", str, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	std::string  str = "helloworld ";
    Test("Test3", str, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	std::string  str = "hello  world";
    Test("Test4", str, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
	std::string  str = "";
    Test("Test6", str, "");
}

//传入内容为一个空格的字符串
void Test7()
{
	std::string str = " ";
    Test("Test7", str, "%20");
}

// 传入的字符串没有空格
void Test8()
{
	std::string str = "helloworld";
    Test("Test8", str, "helloworld");
}

// 传入的字符串全是空格
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

