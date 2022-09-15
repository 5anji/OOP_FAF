#include "rbtree.h"

int main() {
    uint8_t variant;
    char log[255];
    FILE* file;
    file = fopen("./.log", "r");

    while (fgets(log, 255, file)) {
        int temp = atoi(log);
        insert(temp);
    }
    fclose(file);

    // cleanup file
    file = fopen("./.log", "w+");
    fclose(file);

    do {
        printf("\033[32mMenu:\033[0m\n1) search (it returns the node pointer, will display data and it's color)\n2) inorder (display sorted)\n3) preorder\n4) postorder\n5) insert\n6) delete\n0) exit\n\nInput >>> ");

        scanf("%hhd", &variant);

        switch (variant) {
        case 1: {
            int temp;
            printf("Print key: ");
            scanf("%d", &temp);
            printf("%ld (data) - %c (color)\n", search(temp)->data, search(temp)->color);
        } break;
        case 2:
            inorder();
            break;
        case 3:
            preorder();
            break;
        case 4:
            postorder();
            break;
        case 5: {
            char temp[4];
            printf("Print key: ");
            scanf("%s", temp);
            file = fopen("./.log", "a+");
            fprintf(file, "%s\n", temp);
            fclose(file);
            insert(atoi(temp));
        } break;
        case 6: {
            int temp;
            printf("Print key: ");
            scanf("%d", &temp);
            delete_node(temp);
        } break;

        case 0:
            printf("Exited\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (variant != 0);

    return 0;
}
