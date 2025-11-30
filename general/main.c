// #include <stdio.h>

int main() {
    int cash, five_hundo, two_hundo, one_hundo, fifty, twenty, ten, five, two, one;

    printf("Enter cash amount (in rupees): ");
    scanf("%d", &cash);

    five_hundo = cash / 500;
    cash = cash % 500;
    printf("%d five hundred notes\n", five_hundo);

    two_hundo = cash / 200;
    cash = cash % 200;
    printf("%d two hundred notes\n", two_hundo);

    one_hundo = cash / 100;
    cash = cash % 100;
    printf("%d one hundred notes\n", one_hundo);

    fifty = cash / 50;
    cash = cash % 50;
    printf("%d fifty notes\n", fifty);

    twenty = cash / 20;
    cash = cash % 20;
    printf("%d twenty notes\n", twenty);

    ten = cash / 10;
    cash = cash % 10;
    printf("%d ten notes\n", ten);

    five = cash / 5;
    cash = cash % 5;
    printf("%d five coins\n", five);

    two = cash / 2;
    cash = cash % 2;
    printf("%d two coins\n", two);

    one = cash / 1;
    cash = cash % 1;
    printf("%d one coins\n", one);
    return 0;
}