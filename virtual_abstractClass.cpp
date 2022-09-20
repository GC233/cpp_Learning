

#include <iostream>
/* 2022.09.03 虚函数、纯虚函数、访问控制与继承*/
class Base
{
public:
    int g = 0;
    Base() = default;
    Base(int a, int b):a(a), b(b) {}
    virtual ~Base() = default; //析构应为虚函数
    virtual int geta() = 0; //纯虚函数，交给子类实现
private:
    int a;
protected:
    int b;
};

/*
class Pub_Derv :public Base
{
public:
    Pub_Derv(int a, int b, int c):Base(a, b), c(c){} //先初始化父类Base
private:
    int c;
};
*/
class Pub_Derv :private Base //私有继承，成员无法访问父类protected和public成员
{
public:
    Pub_Derv(int a, int b, int c) :Base(a, b), c(c) {} //先初始化父类Base
    int geta()
    {
        return this->b;   //private继承对访问直接父类没有影响
    }
private:
    int c;
};

class from_Pub_Derv :public Pub_Derv //访问间接父类会受到影响
{
public:
    from_Pub_Derv(int a, int b, int c) :Pub_Derv(a, b, c){} //先初始化父类Base
    int geta()
    {
        //return this->g;   //间接父类的public和protect成员会因直接父类的私有继承变为private对象
                          //同理，protected继承会使得间接父类public对象变为protected对象
    }
};
//int main()
//{
//    //Base* p = new Base();
//    std::cout << "Hello World!\n";
//}


