#include<iostream>
#include<fstream>
#include <istream>
#include<sstream>
#include<cassert>
using namespace std;
#include"/usr/local/cs/cs251/react.h"
#include"State.h"

int main(){ 
    /*_read_global_mem_from_file("curr_state");
    for (int i = 0; i < 13; i++){
        cout << _global_mem[i];
    }*/

    ifstream is("curr_state");

    State s(is);
    cout << s.getUserHistory()[s.getNumOfUsers()-1]->size_in_bytes() << endl;

       
}