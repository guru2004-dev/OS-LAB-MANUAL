#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void simulate_process() {
    printf("\nSimulating Process Task...");
    delay(1000);
    printf("\nProcess completed.\n");
}

void file_management() {
    FILE *fp;
    char data[100];
    fp = fopen("demo.txt", "w");
    if (fp == NULL) {
        printf("File creation failed!\n");
        return;
    }
    printf("Enter some text to save to file: ");
    fflush(stdin);
    gets(data);
    fprintf(fp, "%s", data);
    fclose(fp);
    printf("Data written to file successfully.\n");

    fp = fopen("demo.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    printf("\nReading from file:\n");
    while (fgets(data, sizeof(data), fp)) {
        printf("%s", data);
    }
    fclose(fp);
}

void io_system() {
    char name[50];
    int age;
    printf("\n---User Input Demo ---\n");
    printf("Enter your name: ");
    fflush(stdin);
    gets(name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("\n---Output ---\n");
    printf("Hello %s! You are %d years old.\n", name, age);
}

void main() {
    clrscr();
    printf("=== Turbo C++ Simulation of UNIX Concepts ===\n");
    printf("\n1. Simulating Process Management");
    simulate_process();
    printf("\n2. File Management");
    file_management();
    printf("\n3. I/O System Call Simulation");
    io_system();
    printf("\nProgram Complete.");
    getch();
}
