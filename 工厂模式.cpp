//
// Created by Zhangjun on 2020/3/17.
//
#include <iostream>
using namespace std;

//　　简单工厂模式，工厂类是创建产品的，它决定创建哪一种产品，
//就像领导决定采用那种技术方案样。举个例子，现在有宝马车和奔驰车两种车需要生产，
//但是只有一个工厂，且只能在同一时间生产一种车，这时就有工厂决定生产那种车了。
//例子虽然不是十分恰当，但是会其意即可。
enum CarType{BENZ, BMW};

class Car//车类
{
public:
    virtual void createdCar(void) = 0;
};

class BenzCar : public Car //奔驰车
{
public:
    BenzCar()
    {
        cout<<"Benz::Benz()"<<endl;
    }
    virtual void createdCar(void)
    {
        cout<<"BenzCar::createdCar()"<<endl;
    }
    ~BenzCar()
    {

    }
};

class BmwCar : public Car //宝马车
{
public:
    BmwCar()
    {
        cout<<"Bmw::Bmw()"<<endl;
    }
    virtual void createdCar(void)
    {
        cout<<"BmwCar::createdCar()"<<endl;
    }
};


class CarFactory //车厂
{
public:
    Car* createSpecificCar(CarType type)
    {
        switch(type)
        {
            case BENZ://生产奔驰车
                return (new BenzCar());
                break;
            case BMW://生辰宝马车
                return (new BmwCar());
                break;
            default:
                return NULL;
                break;
        }
    }
};

int main(int argc, char** argv)
{
    CarFactory carfac;
    Car* specificCarA = carfac.createSpecificCar(BENZ);//看到网上众多示例在new后没有delete，感觉不是特别严谨
    Car* specificCarB = carfac.createSpecificCar(BMW);

    delete specificCarA; delete specificCarB;

    return 0;
}

//工厂方法模式　工厂方法模式：不再只由一个工厂类决定那一个产品类应当被实例化,
// 这个决定权被交给子类去做。当有新的产品（新型汽车）产生时，只要按照抽象产品角色、
// 抽象工厂角色提供的方法来生成即可（新车型可以用一个新类继承创建产品即可），
// 那么就可以被客户使用，而不必去修改任何已有的代 码。
#include <iostream>
using namespace std;

class Car//车类
{
public:
    virtual void createdCar(void) = 0;
};

class BenzCar : public Car //奔驰车
{
public:
    BenzCar()
    {
        cout<<"Benz::Benz()"<<endl;
    }
    virtual void createdCar(void)
    {
        cout<<"BenzCar::createdCar()"<<endl;
    }
    ~BenzCar()
    {

    }
};

class BmwCar : public Car //宝马车
{
public:
    BmwCar()
    {
        cout<<"Bmw::Bmw()"<<endl;
    }
    virtual void createdCar(void)
    {
        cout<<"BmwCar::createdCar()"<<endl;
    }
};


class Factory//车厂
{
public:
    virtual Car* createSpecificCar(void) = 0;
};

class BenzFactory : public Factory//奔驰车厂
{
public:
    virtual Car* createSpecificCar(void)
    {
        return (new BenzCar());
    }
};

class BmwFactory : public Factory//宝马车厂
{
public:
    virtual Car* createSpecificCar(void)
    {
        return (new BmwCar());
    }
};


int main(int argc, char** argv)
{
    Factory* factory = new BenzFactory();
    Car* specificCarA = factory->createSpecificCar();
    factory = new BmwFactory();
    Car* specificCarB = factory->createSpecificCar();

    delete factory; delete specificCarA; delete specificCarB;

    return 0;
}

