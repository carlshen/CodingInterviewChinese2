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

// 面试题2：实现Singleton模式
// 题目：设计一个类，我们只能生成该类的一个实例。

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Singleton
{
public:
	template<typename... Args>
	static T* Instance(Args&&... args)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(std::forward<Args>(args)...);

		return m_pInstance;
	}

	static T* GetInstance()
	{
		if (m_pInstance == nullptr)
			throw std::logic_error("the instance is not init, please initialize the instance first");

		return m_pInstance;
	}

	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

private:
	Singleton(void);
	virtual ~Singleton(void);
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
private:
	static T* m_pInstance;
};

template <class T> T*  Singleton<T>::m_pInstance = nullptr;

struct A {
	A(const string&) { cout << "lvalue" << endl; }
	A(string&& x) { cout << "rvalue" << endl; }
};

struct B {
	B(const string&) { cout << "lvalue" << endl; }
	B(string&& x) { cout << "rvalue" << endl; }
};

struct C {
	C(int x, double y) { cout << "x = " << x << ",y = " << y << endl; }
	void Fun() { cout << "test" << endl; }
};

int main()
{
	string str = "bb";
	Singleton<A>::Instance(str);
	Singleton<B>::Instance(std::move(str));

	Singleton<C>::Instance(1, 3, 14);
	//Singleton<C>::GetInstance->Fun();

	// release
	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();

	return 0;
}
