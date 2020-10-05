#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int nim;
    char nama[30];
    float ipk;
    struct node *next;
};

typedef struct node node;
node *list;

node *deleteAfter(node * head, int nimDicari) {

    printf("Delete After\n");
    node *x;
    x = head;
    while(x->next != NULL) {
        if(x->nim == nimDicari) {
            node * temp = x->next;
            free(temp);
            x->next = x->next->next;
        } else {
            x = x->next;
        }
    }

    return head;
}

node *deleteLast(node * head) {
    printf("\n\nDelete Last\n");
    if(head == NULL) {
        printf("Data Kosong!\n");
    } else {
        node * temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    return head;
}

node *deleteFirst(node * head) {
    printf("\n\nDelete First\n");
    if(head == NULL) {
        printf("Data Kosong!\n");
    } else {
        head = head->next;
    }
    return head;
}

node *cariElemen(node *head, int nimDicari) {
    if(head != NULL) {
        node *temp;
        temp = head;
        while(temp != NULL) {
            if(temp->nim == nimDicari) {
                return temp;
            }
            temp = temp->next;
        }
    }
    printf("%d tidak ditemukan\n", nimDicari);
    return NULL;
}

node *addAfter(node * head, int nim, char nama[30], float ipk, int nimDicari) {
    node *temp = (node *) malloc(sizeof(node));
    temp->nim = nim;
    strcpy(temp->nama, nama);
    temp->ipk = ipk;
    temp->next = NULL;

    node *x;
    x = head;
    while(x != NULL) {
        if(x->nim == nimDicari) {
            temp->next = x->next;
            x->next = temp;
        }
        x = x->next;
    }

    return head;
}

node *addFirst(node *head, int nim, char nama[30], float ipk) {
    node *temp = (node *) malloc(sizeof(node));
    temp->nim = nim;
    strcpy(temp->nama, nama);
    temp->ipk = ipk;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    return head;
}

node *addLast(node *head, int nim, char nama[30], float ipk) {
    node *temp = (node *) malloc(sizeof(node));
    temp->nim = nim;
    strcpy(temp->nama, nama);
    temp->ipk = ipk;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else if (head->next == NULL) {
        head->next = temp;
    } else {
        node *x = head;
        while (x->next != NULL) {
            x = x->next;
        }
        x->next = temp;
    }
    return head;
}

void print(node *head) {
    if (head == NULL) {
        printf("list is empty");
    } else {
        node *q = head;
        printf("===============\n"
               "TAMPIL DATA\n"
               "===============\n");
        while (q != NULL) {
            printf("%d\n", q->nim);
            printf("%s\n", q->nama);
            printf("%f\n", q->ipk);
            printf("=====================\n");
            q = q->next;
        }

    }
}

int main() {

    list = addFirst(list, 619101004, "Rafli iqbal maulana", 3.9);
    list = addFirst(list, 619101006, "Joko Widodo", 3.8);
    list = addLast(list, 619101008, "Susilo Bambang Yudhyono", 3.7);

    node * prec = cariElemen(list, 619101004);
    if(prec != NULL) {
        list = addAfter(list, 619101010, "Soekarno", 3.6, 619101004);
    }

    list = addFirst(list, 619101004, "Agus Darmawan", 4);
    list = addLast(list, 619101004, "Wiwin Widaningsih", 5);
    prec = cariElemen(list, 619101008);
    if(prec != NULL) {
        list = addAfter(list, 619101010, "Hendra Maulana", 3.6, 619101008);
    }

    print(list);

    list = deleteFirst(list);
    print(list);

    list = deleteLast(list);
    print(list);


    printf("\n\n");
    prec = cariElemen(list, 619101008);
    if(prec != NULL) {
        list = deleteAfter(list, 619101008);
    }
    print(list);

    return 0;
}

