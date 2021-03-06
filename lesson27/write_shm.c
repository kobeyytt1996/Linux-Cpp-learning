#include <sys/ipc.h>
       #include <sys/shm.h>
       #include <stdio.h>
       #include <string.h>

int main() {
    int shmid = shmget(100, 4096, IPC_CREAT | 0644);

    void *ptr = shmat(shmid, NULL, 0);

    char *str = "hello world";

    memcpy(ptr, str, strlen(str) + 1);

    printf("任意键继续\n");
    getchar();

    shmdt(ptr);

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}