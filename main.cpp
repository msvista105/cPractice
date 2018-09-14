#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "screen_ui.h"

using namespace std;

int item_num = 5;

void *new_thread_test(void *args){
    usleep(1000000);
    int thread_num;
    char *buffer = "----sxm----\n\
        ------1--------  \
        ------2--------";
    thread_num = *((int *)args);
    cout<< "---- new_thread_test ----" << "thread_num is " << thread_num << endl;
    FILE *file = fopen("cpp_text","a+");//以附加方式打开读写文件，如不存在，则创建此文件
    if(file == NULL){
        cout<<"create cpp_text error" << endl;
        return NULL;
    }
    size_t len = fwrite(buffer,sizeof(char),strlen(buffer),file);
    cout<<"---- len " << len << " ----" << endl;
    return NULL;
}

void my_terminate_handle(){
    cout << "---- Exception !! quit !! ----" << endl;
    exit(1);
}

int main()
{
    set_terminate(my_terminate_handle);
    string strs[] = {"ab","cd","ed"};
    vector<string> str_vector;
    for(size_t i=0;i<sizeof(strs)/sizeof(strs[0]);i++){
        cout << "string["<<i<<"] is "<<strs[i]<<endl;
        str_vector.push_back(strs[i]);
    }
    //int size = str_vector.size();
    for(vector<string>::iterator it = str_vector.begin();it != str_vector.end();it++){
        cout<<" iterator:"<<*it<<endl;
    }
    pthread_t th;
    int thread_num = 9;
    //线程
    pthread_create(&th,NULL,new_thread_test,&thread_num);
    cout << "Hello world!" << endl;
    screen_ui ui(6);
    ui.show_ui();

    //arrays and pointer
    int int_array[3] = {9,10,11};
    int *p = int_array;
    //int int_array_2dims[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    cout<<"int_array[2]:"<< *(p+1) << "  sizeof int:" << sizeof(int) << " int_array.size:" << sizeof(int_array)/sizeof(int) <<endl;

    /**< 常量指针 */
    int *const p_const = int_array;
    cout << "p_const:" << *(p_const+2) << endl;
    /**< 指向常量的指针 */
    int const_int = 200;
    int const_int_2 = 300;
    const int *p_const_int = &const_int;
    p_const_int = &const_int_2;
    cout<< "p_const_int:" << *p_const_int << endl;

    /**< 输入赋值 */
    //char *cmd ;
    //int cmd_signal ;
    //scanf("%s%d",cmd,&cmd_signal);
    //printf("cmd is %s, cmd_signal is %d",cmd,cmd_signal);

    /**< 终止程序 */
    //terminate();

    /**< 拼接字符串和数字,格式化字符串输出 */
    //char *append_integer = "hello";
    char append_integer[30];
    sprintf(append_integer,"append_integer_sp%d",10);
    cout << "append_integer is " << append_integer << " strlen:" << strlen(append_integer) <<endl;

    return 0;
}
