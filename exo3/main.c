#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(){
    char str[256];
    int pipefd_son[2];
    int pipefd_father[2];
    int i;

    if(pipe(pipefd_son) != 0){
        perror("Cannot create a pipe");
        exit(-1);
    }

    if(pipe(pipefd_father) != 0){
        perror("Cannot create a pipe");
        exit(-1);
    }


    switch(fork()){

        case -1:
            perror("Fork error");
            exit(-1);
            break;

        case 0:
            close(pipefd_father[0]);
            close(pipefd_son[1]);

            read(pipefd_son[0], str, 256);

            i = 0;
            while (i < 256){
                str[i] = toupper(str[i]);
                i++;
            }

            write(pipefd_father[1], str, 256);

            close(pipefd_son[0]);
            close(pipefd_father[1]);
            exit(0);
            break;

        default:
            close(pipefd_son[0]);
            close(pipefd_father[1]);

            printf("Enter string:\n");
            scanf("%[^\n]s", str);
            write(pipefd_son[1], str, 256);

            read(pipefd_father[0], str, 256);
            printf("%s\n", str);

            wait(NULL);
            close(pipefd_father[0]);
            close(pipefd_son[1]);
            break;
    }

    return 0;
}
