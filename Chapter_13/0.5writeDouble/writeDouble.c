#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int main()
{
    char* name = "list";
    double num[5] = {0.1, 0.2, 0.3, 0.2, 0.1};
    FILE* fp;

    if((fp = fopen(name, "w")) == NULL)
        exit(EXIT_FAILURE);    
/*向fp指定的文件中写入double类型的数字*/
    fwrite(num, sizeof(double), SIZE, fp);
    
    if(fclose(fp) != 0)
        exit(EXIT_FAILURE);   

    return 0;
}