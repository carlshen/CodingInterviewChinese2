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

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
// 使用cpp11 array功能

#include <cstdio>
#include <iostream>
#include <array>

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(std::array <int, 5> numbers, int *duplication)
{
    if(numbers.size() <= 0)
        return false;

	std::size_t index = numbers.size();
	for (std::array<int, 5>::iterator it = numbers.begin(); it < numbers.end(); it++) {
		if (*it < 0 || *it > (index - 1)) {
			return false;
		}
	};
	for (std::size_t it = 0; it < index; it++)
    {
        while(it != numbers.at(it))
        {
            if(numbers.at(it) == numbers.at(numbers.at(it)))
            {
                *duplication = numbers.at(it);
                return true;
            }

            // 交换numbers[i]和numbers[numbers[i]]             
            int temp = numbers.at(it);
			numbers.at(it) = numbers.at(temp);
            numbers.at(temp) = temp;
        }
    }

    return false;
}

// ====================测试代码====================
bool contains(std::array <int, 1> numbers, int number)
{
	std::size_t index = numbers.size();
	for (std::size_t it = 0; it < index; it++)
    {
        if (number == numbers.at(it))
            return true;
    }

    return false;
}

void test(char* testName, std::array<int, 5> numbers, std::array<int, 1> expected, bool validArgument)
{
    printf("%s begins: ", testName);

	int duplication;
    bool validInput = duplicate(numbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, duplication))
                printf("Passed, with duplication %d \n", duplication);
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    std::array<int, 5> numbers = { 2, 1, 3, 1, 4 };
	std::array<int, 1> duplications = { 1 };
    test("Test1", numbers, duplications, true);
}

// 重复的数字是数组中最大的数字
void test2()
{
	std::array<int, 5> numbers = { 2, 4, 3, 1, 4 };
	std::array<int, 1> duplications = { 4 };
    test("Test2", numbers, duplications, true);
}

// 数组中存在多个重复的数字
void test3()
{
	std::array<int, 5> numbers = { 2, 4, 2, 1, 4 };
	std::array<int, 1> duplications = { 2 };
    test("Test3", numbers, duplications, true);
}

// 没有重复的数字
void test4()
{
	std::array<int, 5> numbers = { 2, 1, 3, 0, 4 };
	std::array<int, 1> duplications = { -1 }; // not in use in the test function
    test("Test4", numbers, duplications, false);
}

// 没有重复的数字
void test5()
{
	std::array<int, 5> numbers = { 2, 1, 3, 5, 4 };
	std::array<int, 1> duplications = { -1 }; // not in use in the test function
    test("Test5", numbers, duplications, false);
}

// 无效的输入
void test6()
{
	std::array<int, 5> numbers = { };
	std::array<int, 1> duplications = { -1 }; // not in use in the test function
    test("Test6", numbers, duplications, false);
}

void main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

	system("pause");
}