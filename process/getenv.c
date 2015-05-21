#include <stdlib.h>
#include <stdio.h>
int main(void){
    char *p;
    char *pp[] = {"COLUMNS", "DATEMSK", "HOME", "LANG"};
    int i;

    for( i = 0; i < 4; i++ ){
        if((p = getenv(pp[i])))
        printf("USER=%s\n",p);
    }
    return 0;
}
