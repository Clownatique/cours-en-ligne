#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
  int pid_fils = fork();
  if (fork()== 0){
    for (int i = 0 ; i<10;i++){
      cout<<i<<endl;
      sleep(1);
    }
    cout<<"fin du pere"<<endl;
  }
  for (char sortie = 'a'; sortie < 'i';sortie++){
    cout<<sortie<<endl;
  }    
  cout<<"fin du fils"<<endl;
  cout<<flush;
  return 0;
}

