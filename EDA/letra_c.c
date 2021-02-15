#include <stdio.h>
void contrario() {
    char c;
    scanf("%c", &c);
    if (c != '\n') {
        contrario();
        printf("%c", c);
    }
    
}
int main() {
    contrario();
    printf("\n");
    return 0;
}