
#include <iostream>
#include <vector>
using std::string;
using std::vector;
/*   2022.9.19 运算符重载   
如++、--、+-等运算符成员函数类型应为对象类型的引用

*/
class StrBlobPtr
{
public:
    StrBlobPtr(){}
    StrBlobPtr(int a) :curr(a){}
    string& operator[](int index)
    {
        if (s.size() > index)
        {
            return s[index];
        }
    }
    StrBlobPtr& operator++()  //++重载
    {
        ++curr;
        return *this;
    }

    void print_Cur()
    {
        if (s.size() > curr)
        {
            std::cout << s[curr] << std::endl;
        }
    }
    
private:
    vector<string> s={"abc", "def", "ghi"};
    int curr = 0;
};
int main()
{
    StrBlobPtr s(0);
    s.print_Cur();
    s.operator++();
    s.print_Cur();
    s[2] = "avc";
    //std::cout << s[2] << std::endl;
    

}


