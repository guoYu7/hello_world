#include <iostream>
#include <cstdlib>
//c++ 11 之后有了标准的线程库：
//#include <thread>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int*)threadid);
    cout << "Hello Runoob!线程ID:" << tid <<" "<< endl;
    pthread_exit(NULL);
}

int main ()
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];// 用数组来保存i的值
    int rc;
    int i;
    for( i=0; i < NUM_THREADS; i++ ){
        cout << "main() : 创建线程:" << i <<" "<<endl;
        indexes[i] = i;
        // 传入的时候必须强制转换为void* 类型，即无类型指针
        ////参数依次是：     创建的线程id，线程参数，调用的函数，    传入的函数参数
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (rc){
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}


//#include <iostream>
//#include <pthread.h> //必须的头文件

//using namespace std;
//
//#define NUM_THREADS 5
//
//// 线程的运行函数
//void* say_hello(void* args)
//{
//    cout << "Hello Runoob！" << endl;
//    return 0;
//}
//
//int main()
//{
//    // 定义线程的 id 变量，多个变量使用数组
//    pthread_t tids[NUM_THREADS];
//    for(int i = 0; i < NUM_THREADS; ++i)
//    {
//        //参数依次是：         创建的线程id，线程参数，调用的函数，传入的函数参数
//        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
//        if (ret != 0)
//        {
//            cout << "pthread_create error: error_code=" << ret << endl;
//        }
//    }
//    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
//    pthread_exit(NULL);
//}
