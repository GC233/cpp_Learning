// const_cast.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using std::cout;
using std::endl;
/*  2022.9.1 const_cast, static_cast,  reinterpreter_cast, dynamic_cast  */
class Test
{
public:
    int geti() const
    {
        //this->i--;   const成员函数不能修改成员
        cout << i << endl;
        const_cast<Test*>(this)->i++; //通过const_cast移除this的const属性
        cout << i << endl;
        return i;
    }
    virtual void printi()
    {

    }
private:
    int i = 0;
};

class TestChildren:public Test
{

};
int printi(int* i)
{
    cout << *i << endl;
    return (* i) + 1;
}
int main()
{
    Test t;
    cout << t.geti() << endl;
    const int i = 1;
    cout << printi(const_cast<int*>(&i)) << endl;
    /* dynamic_cast用于类继承层次间的指针或引用转换。
    主要还是用于执行“安全的向下转型，即将父类指针转化为子类指针（safe downcasting）*/
    cout << "----------**************----------" << endl;
    Test* t1 = new TestChildren;
    TestChildren* t2 = dynamic_cast<TestChildren*>(t1); //t1指向对象必须有virtual函数
    t2->geti();
    cout << "----------**************----------" << endl;
    Test* t3 = new Test;
    TestChildren* t4 = dynamic_cast<TestChildren*>(t3); //这样将子类指针指向父类是不安全的，返回nullptr
    if (t4 == nullptr)
    {
        cout << "转换失败" << endl;
    }
    else
    {
        t4->geti();
    }
    cout << "----------**************----------" << endl;
    TestChildren* t5 = (TestChildren*)(t1); //强制类型转换不检查子类和父类的关系
    t5->geti();

}

