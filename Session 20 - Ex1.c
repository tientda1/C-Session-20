#include <stdio.h>
typedef struct {
    int id;
    char name[100];
    char author[100];
    float price;
    char category[50];
} Book;

Book books[100];
int currentLength = 0;
void displayBooks() {
    printf("Danh sach sach:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("Ma sach: %d, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The Loai: %s\n", 
                books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
    }
}
void addBookAtPosition(int position) {
    if (position < 0 || position > currentLength) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    if (currentLength >= 100) {
        printf("Khong the them sach moi. Mang da day.\n");
        return;
    }
    for (int i = currentLength; i > position; i--) {
        books[i] = books[i - 1];
    }
    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%d", &books[position].id);
    printf("Ten sach: ");
    scanf(" %[^\n]", books[position].name);
    printf("Tac gia: ");
    scanf(" %[^\n]", books[position].author);
    printf("Gia tien: ");
    scanf("%f", &books[position].price);
    printf("The Loai: ");
    scanf(" %[^\n]", books[position].category);
    currentLength++;
}
void deleteBookById(int id) {
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < currentLength - 1; j++) {
                books[j] = books[j + 1];
            }
            currentLength--;
            break;
        }
    }
    if (!found) {
        printf("Sach voi ma %d khong ton tai.\n", id);
    }
}

void updateBookById(int id) {
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("Nhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            scanf(" %[^\n]", books[i].name);
            printf("Tac gia: ");
            scanf(" %[^\n]", books[i].author);
            printf("Gia tien: ");
            scanf("%f", &books[i].price);
            printf("The Loai: ");
            scanf(" %[^\n]", books[i].category);
            break;
        }
    }
    if (!found) {
        printf("Sach voi ma %d khong ton tai.\n", id);
    }
}
void sortBooksByPrice(int ascending) {
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if ((ascending && books[i].price > books[j].price) || (!ascending && books[i].price < books[j].price)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void searchBookByName(char *name) {
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (strstr(books[i].name, name) != NULL) {
            found = 1;
            printf("Ma sach: %d, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The Loai: %s\n", 
                    books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ten '%s'.\n", name);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia(tang/giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong sach: ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap thong tin sach %d:\n", i + 1);
                    printf("Ma sach: ");
                    scanf("%d", &books[currentLength].id);
                    printf("Ten sach: ");
                    scanf(" %[^\n]", books[currentLength].name);
                    printf("Tac gia: ");
                    scanf(" %[^\n]", books[currentLength].author);
                    printf("Gia tien: ");
                    scanf("%f", &books[currentLength].price);
                    printf("The Loai: ");
                    scanf(" %[^\n]", books[currentLength].category);
                    currentLength++;
                }
                break;
            }
            case 2:
                displayBooks();
                break;
            case 3: {
                printf("Nhap vi tri can them sach: ");
                int position;
                scanf("%d", &position);
                addBookAtPosition(position);
                break;
            }
            case 4: {
                printf("Nhap ma sach can xoa: ");
                int id;
                scanf("%d", &id);
                deleteBookById(id);
                break;
            }
            case 5: {
                printf("Nhap ma sach can cap nhat: ");
                int id;
                scanf("%d", &id);
                updateBookById(id);
                break;
            }
            case 6: {
                printf("Chon cach sap xep (1: Tang, 0: Giam): ");
                int ascending;
                scanf("%d", &ascending);
                sortBooksByPrice(ascending);
                break;
            }
            case 7: {
                printf("Nhap ten sach can tim: ");
                char name[100];
                scanf(" %[^\n]", name);
                searchBookByName(name);
                break;
            }
            case 8:
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
    return 0;
}

