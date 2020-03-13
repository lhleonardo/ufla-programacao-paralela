#include <iostream>  
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;  
int main(  ){  
    pid_t pid;
    pid = fork();
    
    if (pid == 0) {
        cout << "firefox aberto!" << endl;
        execlp("/usr/bin/firefox", "", NULL);
        
    } else if (pid > 0) {
        cout << "Processo pai " << getpid() << " esperando processo filho abrir firefox..." << endl;
        wait(NULL);
        cout << "Processo pai encerrado pois firefox foi aberto." << endl;
    }
    
    return 0;
}
