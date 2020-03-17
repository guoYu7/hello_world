//
// Created by Zhangjun on 2020/3/17.
//

#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    Student(int n, string nam, float s) {
        num = n;
        name = nam;
        score = s;
    }
    virtual void display(){
        cout << "num:" << num <<endl;
        cout << "name:"<< name <<endl;
        cout <<"score:" << score << endl<<endl;
    }
protected:
    int num;
    string name;
    float score;
};


class Graduate :public Student {
public:
    Graduate(int n, string nam, float s, float p):Student(n,nam,s),pay(p){}
    void display(){
        cout << "num:" << num <<endl;
        cout << "name:"<< name <<endl;
        cout << "score:" << score << endl;
        cout << "pay = " << pay << endl<<endl;
    }
private:
    float pay;
};

int main() {
    Student stud1(1001, "Li", 87.5);
    Graduate grad1(2001, "Wang", 98.5, 563.5);

    Student *pt = &stud1;//基类指针
    pt->display();

    pt = &grad1;//指向派生类的基类指针
    pt->display();

    grad1.display();

    return 0;
}
