/*
普通文件输入输出。


*/
#include <iostream>

#include "fstream"
#include "string.h"

using namespace std;

//以二进制文件读写
//write ( char * buffer, streamsize size );
//read ( char * buffer, streamsize size );
class Teacher
{
public:
   Teacher(){

      age= 22;

      strcpy(name,"");


   }
   Teacher(int _age, char *_name){

      age= _age;

      strcpy(name,_name);


   }
   void printT(){

       cout<<"age:"<<age<<"name:"<<name<<endl;

   }

private:

    int age;

    char name[32];

};
int main(){

    const char *fname = "D:/11.dat";

    ofstream fout(fname,ios::binary);//建立一个输出流对象。

    if(!fout){

        cout<<"open failed"<<endl;

        return 0;

    }
    Teacher t1(32,"T1");

    Teacher t2(34,"yzn");

    Teacher t3(37,"yzn1");

    fout.write((char *)&t1,sizeof(t1));

    fout.write((char *)&t2,sizeof(t2));

    fout.write((char *)&t3,sizeof(t3));

    fout.close();


    //输入

    ifstream fin(fname);//建立一个输入流对象 和文件关联

    Teacher tmp;

    fin.read((char*)&tmp,sizeof(Teacher));

    tmp.printT();

    fin.read((char*)&tmp,sizeof(Teacher));

    tmp.printT();

    fin.close();

}







//普通文件输入输出。
int main91()
{
   const char *fname = "D:/5.txt";
    ofstream f(fname,ios::app|ios::ate);//建一个输出流对象，和文件关联。

    f<<"helloc"<<endl;
    f<<"hello"<<endl;

    f<<"helloc111"<<endl;

    //读文件

    ifstream fin(fname);//建立一个输入流对象，和文件关联

    char ch;

    while(fin.get(ch)){

        cout<<ch;

    }
    fin.close();



    return 0;
}

