#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){
    //declare variabel
    string Line, Tipe[3] = {"Information", "Warning", "Error"}, target_file;
    size_t awal=0;
    fstream Windows, target;

    //membuat atau me-reset file tujuan
    for(int i=0; i<3; ++i){
        target_file = Tipe[i] + ".txt";
        target.open(target_file, ios::out);
        target<< "||file "<< Tipe[i]<< " Log||"<<endl<<endl;//keterangan file
        target.close();
    }

    Windows.open("Windows Log.txt", ios::in);//membaca file windows log
    while (getline(Windows, Line)){
        for(int i=0; i<3; ++i){
            if(Line.find(Tipe[i])==awal){//cek jenis log
                target_file = Tipe[i] + ".txt";
                target.open(target_file, ios::app);//append line tersebut ke file target
                target<< Line<<endl;
                target.close();
                break;
            }
        }
    }
    Windows.close();
    return 0;
}

