#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <windows.h>

#include "screen_ui.h"

using namespace std;

const string str_x_name = "hello" "world";
const char* SAVED_FILE = "record";
const char* ERRO = "Error !!!";

int item_num = 5;
screen_ui ui(6);///ȫ�ֱ���

struct thread_args{
    screen_ui ui;
    int32_t pic_num;
};

void *wait_for_corrupt(void *args){
    cout << "wait_for_corrupt" << endl;
    int *count = 0;
    for(;;){
        //Sleep(2);
        //cout << " wait_for_corrupt count is " << (*count)++ << endl;
        cout << " wait_for_corrupt count is "  << endl;
    }
}

void *new_thread_test(void *args){
    //usleep(1000000);
    Sleep(1);
    cout << "\n new thread start ! " << endl;
    thread_args thread_num;
    char *buffer = "----sxm----\n\
        ------1--------  \
        ------2--------";
    thread_num = *((thread_args *)args);
    cout<< "\n---- new_thread_test ----" << "thread_num.pic_num is " << thread_num.pic_num << endl;
    thread_num.ui.show_ui();
    FILE *file = fopen("cpp_text","a+");//�Ը��ӷ�ʽ�򿪶�д�ļ����粻���ڣ��򴴽����ļ�
    if(file == NULL){
        cout<<"create cpp_text error" << endl;
        return NULL;
    }
    size_t len = fwrite(buffer,sizeof(char),strlen(buffer),file);
    fprintf(file,"\n progress %d ,sec %d",15,20);///����ʽ���ַ������뵽�����
    fclose(file);
    cout<<"---- len " << len << " ----" << endl;
    return NULL;
}

void my_terminate_handle(){
    cout << "---- Exception !! quit !! ----" << endl;
    FILE* fp = fopen(SAVED_FILE, "w");
    fwrite(ERRO,sizeof(char),strlen(ERRO),fp);
    fflush(fp);
    fclose(fp);
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


    ///-------------------------------------///
    /**< c++ �� */
    ui.show_ui();
    ui.overlay_background("vision_bk.png");

    //arrays and pointer
    int int_array[3] = {9,10,11};
    int *p = int_array;
    //int int_array_2dims[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    cout<<"int_array[2]:"<< *(p+1) << "  sizeof int:" << sizeof(int) << " int_array.size:" << sizeof(int_array)/sizeof(int) <<endl;

    ///-------------------------------------///
    /**< ����ָ�� */
    int *const p_const = int_array;
    cout << "p_const:" << *(p_const+2) << endl;
    *p_const = 10000;
    cout << "new p_const:" << *p_const << endl;
    /**< ָ������ָ�� */
    int const_int = 200;
    int const_int_2 = 300;
    const int *p_const_int = &const_int;
    p_const_int = &const_int_2;
    cout<< "p_const_int:" << *p_const_int << endl;

    ///-------------------------------------///
    /**< ���븳ֵ */
    /**
    char *cmd ;
    int cmd_signal ;
    scanf("%s%d",cmd,&cmd_signal);
    printf("cmd is %s, cmd_signal is %d",cmd,cmd_signal);
    **/

    ///-------------------------------------///
    /**< ��ֹ���� */
    //terminate();

    ///-------------------------------------///
    /**< ƴ���ַ���������,��ʽ���ַ������ */
    /**
    //char *append_integer = "hello";
    char append_integer[30];
    sprintf(append_integer,"append_integer_sp%d",10);
    cout << "append_integer is " << append_integer << " strlen:" << strlen(append_integer) <<endl;
    **/

    ///-------------------------------------///
    /**< goto ����*/
    /**
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << "---- goto i:" << i << " j:" << j << endl;
            if(i == 2 && j == 2){
                break;
            }
            if(i == 3 && j == 2){
                goto _out_for;
            }
        }
    }
    _out_for:
        cout << " _out_for " << endl;
    **/

    ///-------------------------------------///
    /**< int ��ռ�ֽ������Լ�int�����Сֵ */
    /**
    cout << "int :\t" << sizeof(int) << "\t min:" << numeric_limits<int>::min() << "\t max:" << numeric_limits<int>::max() << endl;

    cout << str_x_name << endl;
    **/

    /**< vector sscanf */
    /**
    vector<string> vec_strs;
    string array_strs[3] = {"hello-----------------------------------------haha--------break", "word" "!","end"};
    for(uint32_t i=0;i<sizeof(array_strs)/sizeof(string);i++){
        vec_strs.push_back(array_strs[i]);
    }
    cout << "vec_strs size is " << vec_strs.size() << " sizeof(string) is " << sizeof(string) << endl;
    for(vector<string>::iterator it = vec_strs.begin();it != vec_strs.end();it++){
        string str = *it;
        char strs[90];///�������飡��
        int ret = str.find("haha");
        if(ret != -1){///find the string
            cout << " str.substr(ret).c_str():" << str.substr(ret).c_str() << endl;
            sscanf(str.substr(ret).c_str(),"%s",strs);
            cout << " strs:" << strs << endl;
        }

        cout << " vec_strs :" << *it << " ret:" << ret << endl;
    }
    **/

    /**< pipe ���̼�ͨ�� -- windows û��fork ���� */
    /**< pid_t pid = fork();
    cout << " the pid is " << pid << endl; */


    /**< atoi ��asciiת��integer */
    int atoi_num = atoi("123459.87");
    cout << "atoi_num is " << atoi_num << endl;

    /**< ���쳣,�����쳣 */
    try{
        throw 13456;
    }catch(...){
        cout << "excepion !!!" << endl;
    }

    cout << "uint16_t.sizeof() is " << sizeof(uint16_t) << endl;

    //puts("------------------00000000--------------------");


    /**< ָ���ָ�� */
    char* char_ptr[] = {"aaa","bbb"} ;
    char char_array[50][50] = {"ab","cd"};
    vector<std::string> vector_str;
    vector_str.push_back("hmct-1");
    vector_str.push_back("hmct-2");
    int count = vector_str.size();
    char** char_ptr_ = (char**)malloc(count*sizeof(char*));
    for(int i=0;i<count;i++){
        char_ptr_[i] = (char*)malloc(strlen(vector_str[i].c_str()) * sizeof(char));
        strcpy(char_ptr_[i],vector_str[i].c_str());
    }

    screen_ui::print("-----------static method-----------------");



    ///-------------------------------------///
    /**< �߳� */
    /*
    ui.set_tag("1111");
    thread_args args;
    args.pic_num = 10;
    args.ui = ui;
    args.ui.set_tag("2222");
    pthread_t th;
    ///int thread_num = 9;
    ///pthread_create(&th,NULL,new_thread_test,&args);
    pthread_create(&th,NULL,wait_for_corrupt,NULL);
    */


    screen_ui::print("----------- string test -----------------");
    std::string ori_str("nihao");
    std::string f_name(ori_str);
    f_name.append("-- ok");
    printf("---- f_name : %s ---- \n",f_name.c_str());
    printf("---- f_name 2 : %s ---- \n",ori_str.c_str());

    //Error test !!!!!
    //char ss[5];
    //strcpy(ss,ERRO);





    return 0;
}
