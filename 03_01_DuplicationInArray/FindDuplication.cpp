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

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��
// ʹ��cpp11 array����

#include <cstdio>
#include <iostream>
#include <array>

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
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

            // ����numbers[i]��numbers[numbers[i]]             
            int temp = numbers.at(it);
			numbers.at(it) = numbers.at(temp);
            numbers.at(temp) = temp;
        }
    }

    return false;
}

// ====================���Դ���====================
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

// �ظ�����������������С������
void test1()
{
    std::array<int, 5> numbers = { 2, 1, 3, 1, 4 };
	std::array<int, 1> duplications = { 1 };
    test("Test1", numbers, duplications, true);
}

// �ظ�����������������������
void test2()
{
	std::array<int, 5> numbers = { 2, 4, 3, 1, 4 };
	std::array<int, 1> duplications = { 4 };
    test("Test2", numbers, duplications, true);
}

// �����д��ڶ���ظ�������
void test3()
{
	std::array<int, 5> numbers = { 2, 4, 2, 1, 4 };
	std::array<int, 1> duplications = { 2 };
    test("Test3", numbers, duplications, true);
}

// û���ظ�������
void test4()
{
	std::array<int, 5> numbers = { 2, 1, 3, 0, 4 };
	std::array<int, 1> duplications = { -1 }; // not in use in the test function
    test("Test4", numbers, duplications, false);
}

// û���ظ�������
void test5()
{
	std::array<int, 5> numbers = { 2, 1, 3, 5, 4 };
	std::array<int, 1> duplications = { -1 }; // not in use in the test function
    test("Test5", numbers, duplications, false);
}

// ��Ч������
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