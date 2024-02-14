//Напишите программу, которая проверяет два вектора в трехмерном
//пространстве на ортогональность и коллинеарность.
#include <stdio.h>
#include <stdlib.h>

//скалярное произведение
double dotProduct(double vec1[], double vec2[]) {
    double result = 0;
    for (int i = 0; i < 3; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

double isCollinear(double vec1[], double vec2[]) {
    float scalar = (float)vec1[0] / vec2[0];

    for (int i = 1; i < 3; i++) {
        if (vec2[i] * scalar != vec1[i]) {
            return 0;
        }
    }
    return 1;
}

double isOrthogonal(double vec1[], double vec2[]) {
    if (dotProduct(vec1, vec2) == 0) {
        return 1;
    }
    else {
        return 0;
    }
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

    if (isOrthogonal(vector1, vector2)) {
        printf("Вектора ортогональны.\n");
    }
    else {
        printf("Вектора не ортогональны.\n");
    }

    if (isCollinear(vector1, vector2)) {
        printf("Вектора коллинеарны.\n");
    }
    else {
        printf("Вектора не коллинеарны.\n");
    }
    return 0;
}