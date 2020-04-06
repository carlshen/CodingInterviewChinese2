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

// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <stdio.h>
#include <iostream>
#include <cstring>
using std::string;

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(string str)
{
    if(str.empty())
        return false;

	size_t originalLength = str.length();
	//std::cout << "isNumeric size: " << originalLength << std::endl;
	size_t index = 0;
	// +- in the first place
	if (str.at(index) == '+' || str.at(index) == '-') {
		index++;
	}
	/*if (str[index] == '+' || str[index] == '-') {
		index++;
	}*/
	// some integers
	bool numeric = false;
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
		index++;
		numeric = true;
	}
    // 如果出现'.'，接下来是数字的小数部分
    if(str[index] == '.')
    {
        ++index;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
		while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
			index++;
			numeric = true;
		}
    }

    // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
    if(str[index] == 'e' || str[index] == 'E')
    {
		index++;
		// e/E also can have +- 
		if (str[index] == '+' || str[index] == '-') {
			index++;
		}
        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
		while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
			index++;
			if (numeric) {
				numeric = true;
			}
		}
    }

    return numeric && str[index] == '\0';
}

// ====================测试代码====================
void Test(const char* testName, string str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

	if (!str.empty()) {
		std::cout << "test string: " << str.c_str() << std::endl;
		std::cout << "test expected: " << expected << std::endl;
	}
    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

	system("pause");
    return 0;
}
