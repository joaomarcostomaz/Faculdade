#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    char number[20];
} Contact;

int total = 0;
int idx = 0;

char filename[100];

Contact contacts[10*MAX];

void read_file() {
    FILE *file = fopen(filename, "rb");
    
    total = fread(contacts, sizeof(Contact), MAX, file);
    idx = total;

    fclose(file);
}

void save_file() {
    FILE *file = fopen(filename, "wb");

    for(int k = 0; k < idx; k++) 
        if(contacts[k].age != 0) 
            fwrite(&contacts[k], sizeof(Contact), 1, file);
        

    fclose(file);
}


int find(char name[]) {
    for(int k = 0; k < 10*MAX; k++)
        if(!strcmp(name, contacts[k].name))
            return k;

    return -1;
}


int main() {
    scanf("%s", filename);
    
    read_file();

    char name[50];
    int age;
    char number[20];

    char option[20];

    while(scanf("%s", option) != EOF) {
        if(!strcmp(option, "Inserir")) {
            scanf("%s %d %s", name, &age, number);
            

            if(total == MAX) {
                printf("Espaco insuficiente\n");
            } else {
                strcpy(contacts[idx].name, name);
                contacts[idx].age = age;
                strcpy(contacts[idx].number, number);

                printf("Registro %s %d %s inserido\n", contacts[idx].name, contacts[idx].age, contacts[idx].number);
                idx++;
                total++;
            }

            save_file();
        }

        if(!strcmp(option, "Exibir")) {
            scanf("%s", name);

            int i = find(name);

            if(i != -1) {
                printf("Registro %s %d %s exibido\n", contacts[i].name, contacts[i].age, contacts[i].number);
            } else {
                printf("Registro %s invalido\n", name);
            }
        }

        if(!strcmp(option, "Alterar")) {
            scanf("%s %d %s", name, &age, number);

            int i = find(name);

            if(i != -1) {
                strcpy(contacts[i].name, name);
                contacts[i].age = age;
                strcpy(contacts[i].number, number);

                printf("Registro %s %d %s alterado\n", contacts[i].name, contacts[i].age, contacts[i].number);
            } else {
                printf("Registro %s invalido\n", name);
            }

            save_file();
        }

        if(!strcmp(option, "Excluir")) {
            scanf("%s", name);

            int i = find(name);

            if(i != -1) {
                printf("Registro %s %d %s excluido\n", contacts[i].name, contacts[i].age, contacts[i].number);

                strcpy(contacts[i].name, "");
                contacts[i].age = 0;
                strcpy(contacts[i].number, "");

                total--;
            } else {
                printf("Registro %s invalido\n", name);
            }

            save_file();
        }
    }

    return 0;
}