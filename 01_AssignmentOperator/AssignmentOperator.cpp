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
// ʹ��std::string��ʽ

// ������1����ֵ���������
// ��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������

#include<cstring>
#include<cstdio>
#include <iostream>

class CMyString
{
public:
    CMyString(const char* pData = nullptr);
	CMyString(std::string pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    std::string m_pData;
};

CMyString::CMyString(const char* pData)
{
	m_pData = std::string(pData);
}

CMyString::CMyString(std::string pData)
{
	m_pData = std::move(pData);
}

CMyString::CMyString(const CMyString &str)
{
	m_pData = std::move(str.m_pData);
}

CMyString::~CMyString()
{
	m_pData.clear();
}

CMyString& CMyString::operator = (const CMyString& str)
{
    if(this == &str)
        return *this;

	m_pData.clear();
    m_pData = std::move(str.m_pData);

    return *this;
}

// ====================���Դ���====================
void CMyString::Print()
{
	std::cout << m_pData.c_str() << std::endl;
}

void Test1()
{
	std::cout << "Test1 begins:" << std::endl;

    std::string text("Hello world");

    CMyString str1("Hello world");
    CMyString str2(str1);

    printf("The expected result is: %s.\n", text.c_str());

	std::cout << "The actual result is: " << std::endl;
    str2.Print();
	std::cout << "Test1 end." << std::endl;
}

// ��ֵ���Լ�
void Test2()
{
	std::cout << "Test2 begins:" << std::endl;

	std::string text("Hello world");

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text.c_str());

	std::cout << "The actual result is: " << std::endl;
    str1.Print();
	std::cout << "Test2 end." << std::endl;
}

// ������ֵ
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2(str1), str3(str1);

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

	system("pause");
    return 0;
}

