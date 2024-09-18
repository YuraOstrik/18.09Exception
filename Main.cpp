#include <iostream>
#include <cstring> 

using namespace std;

class Exception
{
protected:
    char m_message[100];

public:
    Exception(const char* message) {
        strcpy_s(m_message, message);
    }

    virtual const char* GetMessage() const {
        return m_message;
    }
};

class IndexEx : public Exception {
public:
    IndexEx(const char* message) : Exception(message) {}

    const char* GetMessage() const {
        return Exception::GetMessage();
    }
};

int main()
{
    int mas[3]{ 1, 2, 3 };

    try
    {
        for (int i = 0; i < 5; i++)
        {
            if (i >= 3) {
                throw IndexEx("Index exception");
            }
            cout << mas[i] << "\t";
        }

    }
    catch (const Exception exception)  
    {
        cout << exception.GetMessage() << endl;
    }

}



//class Foo
//{
//private:
//
//    int* m_array;
//    int m_size;
//
//public:
//
//    Foo(const int size);
//
//    ~Foo();
//
//    int GetElement(const int index);
//};
//
//
//Foo::Foo(const int size) : m_array(nullptr), m_size(0)
//{
//    if (size <= 0)
//    {
//        throw size;
//    }
//
//    m_array = new int[size];
//
//    for (int i = 0; i < size; ++i)
//    {
//        m_array[i] = i;
//    }
//
//    m_size = size;
//}
//
//Foo::~Foo()
//{
//    delete[] m_array;
//}
//
//int Foo::GetElement(const int index)
//{
//    if (index < 0 || index >= m_size)
//    {
//        throw "Incorrect index";
//    }
//
//    return m_array[index];
//}
//
//
//
//int main()
//{
//    try
//    {
//        cout << "Enter a size: ";
//
//        int size = 0;
//        cin >> size;
//
//        Foo obj(size);
//
//        cout << "Enter an index: ";
//
//        int index = 0;
//        cin >> index;
//
//        cout << obj.GetElement(index);
//    }
//    catch (char* exception)
//    {
//        cout << exception << endl;
//    }
//    catch (int exception)
//    {
//        cout << "Incorrect memory allocation size: " << exception << endl;
//    }
//
//    return 0;
//}
//
//
//
//
//
//
//
//
//









//int main()
//{
//	double a, b;
//	try
//	{
//		cin >> a >> b;
//		if (b == 0)
//		{
//			throw 0;
//		}
//		cout << a << " / " << b << " = " << a / b << endl;
//
//		int mas[3]{ 1,2,3 };
//		for (int i = 0; i <= 5; i++)
//		{
//			if (i >= 3)
//			{
//				throw "index error";
//			}
//			cout << mas[i] << "\t";
//		}
//		cout << endl;
//	}
//	catch (int a)
//	{
//		cout << "Division by " << a << "!!! \n";
//	}
//	catch (const char* error)
//	{
//		cout << endl << error << endl;
//	}
//	catch (...)// universal catch
//	{
//		cout << "\n!!! ERROR !!!\n";
//	}
//
//	return 0;
//}
//
//
