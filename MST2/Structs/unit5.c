#include <stdio.h>
#include <string.h>

// ------------------------------
// UNIT-5 DEMO: Structures, Unions,
// Enums, Bit-fields (All in one file)
// ------------------------------

// ------------------------------
// 1) STRUCT: grouping different types
// ------------------------------
struct Student {
    char name[30];
    int age;
    float marks;
};

// Function: print student (passed by value)
void printStudentByValue(struct Student s){
    // Access fields with dot operator
    printf("Student (by value): Name=%s | Age=%d | Marks=%.2f\n",
           s.name, s.age, s.marks);
}

// Function: update student's age (passed by reference)
void updateStudentByRef(struct Student *s, int newAge){
    // Use -> when you have pointer to struct
    s->age = newAge;
    // also append a suffix to show change
    strcat(s->name, " (updated)");
}

// Function: create and return a Student (shows returning structure)
struct Student createStudent(const char *name, int age, float marks){
    struct Student t;
    strncpy(t.name, name, sizeof(t.name)-1);
    t.name[sizeof(t.name)-1] = '\0';
    t.age = age;
    t.marks = marks;
    return t; // OK in C: returning struct
}

// Print an array of students
void printStudentsArray(struct Student arr[], int n){
    printf("\nArray of Students:\n");
    for(int i = 0; i < n; i++){
        printf("  [%d] %s, age=%d, marks=%.1f\n", i, arr[i].name, arr[i].age, arr[i].marks);
    }
}

// ------------------------------
// 2) UNION: same memory for all members
// ------------------------------
union Data {
    int i;
    float f;
    char str[20];
};

// Print union (by value)
void printUnionByValue(union Data d){
    // printing all members to show overlap effect
    printf("Union (by value): i=%d, f=%.3f, str=\"%s\"\n", d.i, d.f, d.str);
}

// Modify union (by reference)
void fillUnion(union Data *d){
    d->i = 0x41424344; // set int (will appear as bytes as string sometimes)
}

// ------------------------------
// 3) ENUM: named integer constants
// ------------------------------
enum Color { RED, GREEN, BLUE, YELLOW };
const char *colorName(enum Color c){
    switch(c){
        case RED: return "RED";
        case GREEN: return "GREEN";
        case BLUE: return "BLUE";
        case YELLOW: return "YELLOW";
        default: return "UNKNOWN";
    }
}

// ------------------------------
// 4) BIT-FIELDS: store exact bits
// ------------------------------
struct Flags {
    unsigned int isOnline : 1;  // 0 or 1
    unsigned int role     : 3;  // 0..7 (3 bits)
    unsigned int grade    : 4;  // 0..15 (4 bits)
    // these three fit in 1 byte (typically) or 1-4 bytes depending on compiler,
    // but they're packed more compactly than normal ints.
};

void printFlags(struct Flags f){
    printf("Flags: isOnline=%u, role=%u, grade=%u\n", f.isOnline, f.role, f.grade);
    printf(" sizeof(Flags) = %zu bytes\n", sizeof(f));
}

// ------------------------------
// MAIN: demonstrate everything
// ------------------------------
int main(void){
    printf("===== UNIT-5 DEMO: Structures, Unions, Enums, Bit-fields =====\n\n");

    // ---------- STRUCT: create and print ----------
    struct Student s1;
    strncpy(s1.name, "Alice", sizeof(s1.name)-1);
    s1.age = 18;
    s1.marks = 82.5f;

    printStudentByValue(s1);           // pass by value

    // ---------- PASS BY REFERENCE ----------
    printf("\n-- Update by reference --\n");
    printf("Before update: %s, age=%d\n", s1.name, s1.age);
    updateStudentByRef(&s1, 19);       // pass address
    printf("After update: %s, age=%d\n", s1.name, s1.age);

    // ---------- RETURNING STRUCT ----------
    struct Student s2 = createStudent("Bob", 20, 90.0f);
    printStudentByValue(s2);

    // ---------- ARRAY OF STRUCTS ----------
    struct Student cls[3];
    cls[0] = s1;
    cls[1] = s2;
    cls[2] = createStudent("Charlie", 17, 75.0f);
    printStudentsArray(cls, 3);

    // ---------- UNION ----------
    printf("\n-- UNION demo --\n");
    union Data d;
    // assign string first
    strcpy(d.str, "Hi");               // stored in same memory as i and f
    printUnionByValue(d);

    // assign integer: overwrites previous bytes
    d.i = 123456789;
    printUnionByValue(d);

    // assign float: again overwrites
    d.f = 3.14159f;
    printUnionByValue(d);

    // show passing union by reference to modify
    fillUnion(&d);
    printUnionByValue(d);
    // Note: union is useful when we want a variable to take multiple types,
    // but only one type/value at a time. Memory is shared.

    // ---------- ENUM ----------
    printf("\n-- ENUM demo --\n");
    enum Color fav = BLUE;
    printf("Favorite color enum value = %d => %s\n", fav, colorName(fav));
    fav = YELLOW;
    printf("Now fav = %d => %s\n", fav, colorName(fav));

    // ---------- BIT-FIELDS ----------
    printf("\n-- BIT-FIELD demo --\n");
    struct Flags F;
    F.isOnline = 1;
    F.role = 5;   // valid because role has 3 bits (0..7)
    F.grade = 12; // valid for 4 bits (0..15)
    printFlags(F);

    // Try overflowing a bit-field (behavior: truncated to available bits)
    printf("\n-- Bit-field overflow test (truncation) --\n");
    F.role = 15;  // 15 in binary is 1111; role has only 3 bits -> will be truncated to lower 3 bits (111 -> 7)
    F.grade = 300; // truncated to lower 4 bits
    printFlags(F);

    // ---------- WHY and WHEN to use each ----------
    printf("\n-- Quick summary --\n");
    printf("struct : group related but different typed data together (like object fields).\n");
    printf("union  : multiple members share same memory; only one member valid at a time; saves memory.\n");
    printf("enum   : named integer constants (improves readability).\n");
    printf("bitfld : pack boolean/ small-range fields into fewer bits (memory-critical usage).\n");

    printf("\n===== END OF DEMO =====\n");
    return 0;
}
