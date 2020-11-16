#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int fd;
    int pipefd[2];

    if(pipe(pipefd) != 0){
        perror("Cannot create pipe");
        exit(-1);
    }

    switch(fork()){

    case -1:
        perror("Cannot fork");
        exit(-1);
        break;

    case 0:

        close(pipefd[0]);
        close(1);
        dup(pipefd[1]);
        close(pipefd[1]);
        execlp("ls", "ls", NULL);

        exit(-1);
        break;

    default:

        switch(fork()){

        case -1:
            perror("Cannot fork");
            exit(-1);
            break;

        case 0:
            close(pipefd[1]);
            close(0);
            dup(pipefd[0]);
            close(pipefd[0]);

            fd = open("file.txt", O_CREAT|O_RDWR, 0655);

            close(1);
            dup(fd);
            close(fd);
            execlp("sort", "sort", "-d", NULL);

            exit(-1);
            break;

        default:
            close(pipefd[0]);
            close(pipefd[1]);
            wait(NULL);
            break;


        }

        wait(NULL);
        break;
    }

}
