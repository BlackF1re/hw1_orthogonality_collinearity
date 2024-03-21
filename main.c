//Напишите программу, которая проверяет два вектора в трехмерном
//пространстве на ортогональность и коллинеарность.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Два вектора ортогональны, если скалярное произведение равно 0. Скалярное произведение - сумма последовательных произведений координат двух векторов.
bool isOrthogonal(double vec1[], double vec2[]) {
    double result = 0;
    for (int i = 0; i < 3; i++) {
        result += vec1[i] * vec2[i];
    }
    if (result == 0)
        return true;
    else return false;
}

//два ненулевых вектора коллинеарны тогда и только тогда, когда их векторное произведение равно нулевому вектору.
int isCollinear(double vec1[], double vec2[]) {
    double zeroVector[] = { 0, 0, 0 };
    double result[] = { 0, 0, 0 };
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

    if (result[0] == 0 && result[1] == 0 && result[2] == 0)
        return true;
    else return false;
}

int main() {
    SetConsoleOutputCP(1251);
    double vector1[] = {0, 0, 0};
    double vector2[] = {0, 0, 0};

    FILE* file = fopen("vectors_set.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(file, "%lf %lf %lf\n", &vector1[0], &vector1[1], &vector1[2]);
    fscanf(file, "%lf %lf %lf\n", &vector2[0], &vector2[1], &vector2[2]);
    fclose(file);

    if (isOrthogonal(vector1, vector2) == true) printf("Вектора ортогональны.\n");
    else printf("Вектора не ортогональны.\n");

    if (isCollinear(vector1, vector2) == true) printf("Вектора коллинеарны.\n");
    else printf("Вектора не коллинеарны.\n");
    return 0;
}