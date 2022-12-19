#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "State.h"
#include"/usr/local/cs/cs251/react.h"


void _receive_and_send() {
  // initialization
  _read_event_info_file("event_info");
  if (_just_starting()) _read_global_mem_from_file("startup_mem");
  else _read_global_mem_from_file("begin_mem");

  istringstream iss(_global_mem + 376);
  State state(iss);
  int size = 0;
  for (int i = 0; i < state.getNumOfUsers(); i++){
      size += state.getUserHistory()[i]->numOfPosts;    
      cout << "Post index " << state.offset_for_posts(size)[i]<< endl;
    }
  //state.offset_for_posts();


  //string s2(_global_mem, 30);
  //cout << "numberOfUsers" << state.getNumOfUsers() << endl;

  // event handling and display
  state.update(); 
  cout << "Number: " << state.getNumOfUsers() << endl;

  ostringstream oss1;
  state.writeTo(oss1);
  string s1 = oss1.str();
  s1.copy(_global_mem + 376, s1.length());
  //cout << s1 << endl;

  _write_global_mem_to_file("end_mem");
  string tilde_20 = "~~~~~~~~~~~~~~~~~~~~";
  tilde_20.copy(_global_mem + 355, tilde_20.length()); // place holder for post indext inpiut taken automatically upon click on the post. 
  string tilde_des_50 = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  tilde_des_50.copy(_global_mem + 89, tilde_des_50.length()); // place holder for description inout for creating new post
  tilde_20.copy(_global_mem + 151, tilde_20.length()); // place holder for categpry input for creating new post
  tilde_20.copy(_global_mem + 180, tilde_20.length()); // place holder for price input for creating new post
  string tilde_10 = "~~~~~~~~~~";
  tilde_10.copy(_global_mem + 213, tilde_10.length()); // place holder for share/ISO input for creating new post
  string tilde_100 = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  tilde_100.copy(_global_mem + 233, tilde_100.length()); // place holder for sending message with request
  _write_global_mem_to_file("begin_mem");
  tilde_20.copy(_global_mem + 22, tilde_20.length()); // place holder for username input
  tilde_20.copy(_global_mem + 54, tilde_20.length()); // place holder for password inoput
  _write_global_mem_to_file("startup_mem");
  _write_global_yaml_to_file("react.yaml");
  // print out _global_mem from [4] to [30]
  //string s1(_global_mem , 800);
  //cout << s1 << endl;

  delete [] _global_mem;
}

int main() {
  _receive_and_send();
}