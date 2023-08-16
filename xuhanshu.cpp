#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base display()" << endl;
    }
private:
    int i = 0;
};

class Derived : public Base {
public:
    void display() { // 子类实现了父类的虚函数，但未声明为virtual
        cout << "Derived display()" << endl;
    }
};

int main() {
    Base* ptr = new Derived(); // 创建Derived对象并使用Base类型的指针指向它
    ptr->display(); // 调用父类中的display函数

    Derived* ptr1 = new Derived();
    ptr1->display();
    cout<<"sizeof(Base) = "<<sizeof(Base)<<endl;
    cout<<"sizeof(Derived) = "<<sizeof(Derived)<<endl;
    delete ptr;
    return 0;
}
