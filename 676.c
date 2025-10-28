#include <stdio.h>
#include <string.h>
// Функция для рисования строки двух квадратов
void draw_squares_line(int side1, int side2, int line, char symbol, int filled, int spacing) {
    // Первый квадрат
    if (line < side1) {
        for (int j = 0; j < side1; j++) {
            if (filled || line == 0 || line == side1 - 1 || j == 0 || j == side1 - 1) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
    }
    else {
        // Пустое место если первый квадрат закончился
        for (int j = 0; j < side1; j++) {
            printf(" ");
        }
    }
    // Пробелы между квадратами
    for (int i = 0; i < spacing; i++) {
        printf(" ");
    }
    // Второй квадрат
    if (line < side2) {
        for (int j = 0; j < side2; j++) {
            if (filled || line == 0 || line == side2 - 1 || j == 0 || j == side2 - 1) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
    }
}
int calculate_area(int side) {
    return side * side;
}
void print_definition() {
    printf("\n=== ОПРЕДЕЛЕНИЕ ФИГУРЫ ===\n");
    printf("Квадрат - правильный четырёхугольник с равными сторонами\n");
    printf("и углами 90°. Площадь: S = a²\n");
}
int main() {
    char symbol;
    int side1, side2, side3;
    char fill_condition[10];
    printf("=== ПРОГРАММА: ДВА КВАДРАТА ===\n\n");
    printf("Введите символ: ");
    scanf_s(" %c", &symbol);
    printf("Введите сторону 1: ");
    scanf_s("%d", &side1);
    printf("Введите сторону 2: ");
    scanf_s("%d", &side2);
    printf("Введите сторону 3 (расстояние): ");
    scanf_s("%d", &side3);
    printf("Закрасить? (да/нет): ");
    scanf_s("%s", fill_condition);
    int filled = (strcmp(fill_condition, "да") == 0);
    // 1) Расчет площади
    printf("\n=== РАСЧЕТ ПЛОЩАДИ ===\n");
    printf("Квадрат 1: %d² = %d\n", side1, side1 * side1);
    printf("Квадрат 2: %d² = %d\n", side2, side2 * side2);
    printf("Общая площадь: %d\n", side1 * side1 + side2 * side2);
    // 2) Определение
    print_definition();
    // 3) Рисование
    printf("\n=== ВИЗУАЛИЗАЦИЯ ===\n");
    int max_height = (side1 > side2) ? side1 : side2;
    for (int i = 0; i < max_height; i++) {
        draw_squares_line(side1, side2, i, symbol, filled, side3);
        printf("\n");
    }
    return 0;
}