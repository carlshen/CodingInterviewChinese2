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

// ������20����ʾ��ֵ���ַ���
// ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
// �ַ�����+100������5e2������-123������3.1416������-1E-16������ʾ��ֵ������12e����
// ��1a3.14������1.2.3������+-5������12e+5.4��������

#include <stdio.h>
#include <iostream>
#include <cstring>
using std::string;

// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
// �����������������ţ�Ҳ����û�У�����B��һ���޷�������
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
    // �������'.'�������������ֵ�С������
    if(str[index] == '.')
    {
        ++index;

        // ����һ�д�����||��ԭ��
        // 1. С������û���������֣�����.123����0.123��
        // 2. С����������û�����֣�����233.����233.0��
        // 3. ��ȻС����ǰ��ͺ�����������֣�����233.666
		while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
			index++;
			numeric = true;
		}
    }

    // �������'e'����'E'�����������ŵ������ֵ�ָ������
    if(str[index] == 'e' || str[index] == 'E')
    {
		index++;
		// e/E also can have +- 
		if (str[index] == '+' || str[index] == '-') {
			index++;
		}
        // ����һ�д�����&&��ԭ��
        // 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
        // 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4
		while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
			index++;
			if (numeric) {
				numeric = true;
			}
		}
    }

    return numeric && str[index] == '\0';
}

// ====================���Դ���====================
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
