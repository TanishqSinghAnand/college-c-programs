/* unit6_demo.c
   Demonstrates: pointers, malloc/calloc/realloc/free,
   self-referential struct (linked list), file I/O (text & binary),
   macros, and command-line arguments.
   Compile: gcc unit6_demo.c -o unit6_demo
   Run: ./unit6_demo 5 mydata.bin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------
   Preprocessor macros
   --------------------- */
#ifndef UNIT6_DEMO_H
#define UNIT6_DEMO_H
#endif

#define MAX_DEFAULT 5
#define OUT_TEXT_FILE "data_text.txt"
#define OUT_BIN_FILE  "data_bin.dat"

/* parameter macro (note: parentheses to avoid surprises) */
#define SQR(x) ((x) * (x))

/* ---------------------
   Self-referential struct
   --------------------- */
typedef struct Node {
    int data;
    struct Node *next;  /* pointer to next node (self-referential) */
} Node;

/* create a new node (allocated on heap) */
Node *create_node(int value) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p) {
        fprintf(stderr, "ERROR: malloc failed in create_node\n");
        exit(EXIT_FAILURE);
    }
    p->data = value;
    p->next = NULL;
    return p;
}

/* append to tail of list */
void append_node(Node **head_ref, int value) {
    Node *newnode = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = newnode;
        return;
    }
    Node *cur = *head_ref;
    while (cur->next) cur = cur->next;
    cur->next = newnode;
}

/* print linked list */
void print_list(Node *head) {
    printf("Linked list: ");
    Node *cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* free entire list */
void free_list(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

/* ---------------------
   File I/O helpers
   --------------------- */

/* write integer array to text file (human readable) */
void write_array_text(const char *filename, int *arr, size_t n) {
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("fopen"); exit(EXIT_FAILURE); }
    for (size_t i = 0; i < n; ++i)
        fprintf(fp, "%d\n", arr[i]);
    fclose(fp);
}

/* read integer array from text file into a dynamically allocated array
   returns pointer and sets *out_n to number of elements found.
   (simple implementation assumes one integer per line) */
int *read_array_text(const char *filename, size_t *out_n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("fopen"); return NULL; }
    size_t cap = 8;
    size_t cnt = 0;
    int *arr = (int *)malloc(cap * sizeof(int));
    if (!arr) { fclose(fp); return NULL; }

    while (fscanf(fp, "%d", &arr[cnt]) == 1) {
        cnt++;
        if (cnt >= cap) {
            cap *= 2;
            int *tmp = (int *)realloc(arr, cap * sizeof(int));
            if (!tmp) { free(arr); fclose(fp); return NULL; }
            arr = tmp;
        }
    }
    fclose(fp);
    *out_n = cnt;
    return arr;
}

/* write integer array to binary file using fwrite */
void write_array_binary(const char *filename, int *arr, size_t n) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) { perror("fopen"); exit(EXIT_FAILURE); }
    size_t written = fwrite(arr, sizeof(int), n, fp);
    if (written != n) { fprintf(stderr, "Warning: fwrite wrote %zu of %zu\n", written, n); }
    fclose(fp);
}

/* read integer array from binary file (allocates exact size) */
int *read_array_binary(const char *filename, size_t *out_n) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) { perror("fopen"); return NULL; }
    /* get size */
    fseek(fp, 0, SEEK_END);
    long bytes = ftell(fp);
    rewind(fp);
    if (bytes <= 0) { fclose(fp); *out_n = 0; return NULL; }
    size_t n = (size_t)(bytes / sizeof(int));
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) { fclose(fp); return NULL; }
    size_t read = fread(arr, sizeof(int), n, fp);
    if (read != n) { fprintf(stderr, "Warning: fread read %zu of %zu\n", read, n); }
    fclose(fp);
    *out_n = n;
    return arr;
}

/* ---------------------
   Main demo
   --------------------- */
int main(int argc, char *argv[]) {
    printf("=== Unit-6 Demo: Pointers, Dynamic Memory, Self-ref Struct, File I/O, Macros ===\n\n");

    /* -----------
       Command-line arguments
       Usage: ./unit6_demo [size] [binary_filename]
       ----------- */
    int size = MAX_DEFAULT;
    const char *bin_filename = OUT_BIN_FILE;

    if (argc >= 2) {
        size = atoi(argv[1]);
        if (size <= 0) size = MAX_DEFAULT;
    }
    if (argc >= 3) {
        bin_filename = argv[2];
    }
    printf("Using array size = %d\n", size);
    printf("Binary filename = %s\n\n", bin_filename);

    /* ------------------
       Dynamic array with malloc
       ------------------ */
    printf("-- malloc example (uninitialized memory) --\n");
    int *arr = (int *)malloc(size * sizeof(int)); /* malloc: bytes not zeroed */
    if (!arr) { perror("malloc"); return EXIT_FAILURE; }

    /* initialize using pointer arithmetic */
    for (int i = 0; i < size; ++i) {
        *(arr + i) = i + 1;  /* same as arr[i] = i+1; */
    }
    printf("Array filled with 1..%d using malloc\n", size);

    /* show SQR macro */
    printf("SQR(3) macro expands to %d\n\n", SQR(3));

    /* ------------------
       calloc example (zeroed memory)
       ------------------ */
    printf("-- calloc example (zero-initialized) --\n");
    int *zarr = (int *)calloc(size, sizeof(int));
    if (!zarr) { perror("calloc"); free(arr); return EXIT_FAILURE; }
    printf("First element of calloc'ed array (should be 0) = %d\n\n", zarr[0]);

    /* ------------------
       realloc example: grow arr to size*2
       ------------------ */
    printf("-- realloc example (grow array) --\n");
    int newSize = size * 2;
    int *tmp = (int *)realloc(arr, newSize * sizeof(int));
    if (!tmp) {
        perror("realloc");
        free(arr); free(zarr);
        return EXIT_FAILURE;
    }
    arr = tmp;
    /* initialize new slots */
    for (int i = size; i < newSize; ++i) arr[i] = i + 1;
    printf("Array grown to %d elements with realloc\n\n", newSize);

    /* ------------------
       Write array to text and binary files
       ------------------ */
    write_array_text(OUT_TEXT_FILE, arr, newSize);
    printf("Wrote %d ints to text file '%s'\n", newSize, OUT_TEXT_FILE);

    write_array_binary(bin_filename, arr, newSize);
    printf("Wrote %d ints to binary file '%s'\n\n", newSize, bin_filename);

    /* ------------------
       Read back binary file to verify
       ------------------ */
    size_t nread = 0;
    int *readback = read_array_binary(bin_filename, &nread);
    if (readback) {
        printf("Read back %zu ints from binary file. First 5 values: ", nread);
        for (size_t i = 0; i < (nread < 5 ? nread : 5); ++i) printf("%d ", readback[i]);
        printf("\n\n");
        free(readback);
    }

    /* ------------------
       Self-referential struct: simple linked list
       ------------------ */
    printf("-- Linked list (self-referential struct) --\n");
    Node *head = NULL;
    /* append a few numbers using arr values */
    for (int i = 0; i < 5; ++i) append_node(&head, arr[i]);
    print_list(head);

    /* ------------------
       Demonstrate pointers: pointer to pointer
       ------------------ */
    printf("\n-- Pointer demonstration --\n");
    int val = 42;
    int *p = &val;
    int **pp = &p;
    printf("val = %d, *p = %d, **pp = %d\n", val, *p, **pp);

    /* ------------------
       Free everything
       ------------------ */
    free_list(head);
    free(arr);    /* free memory from realloc/malloc */
    free(zarr);   /* free calloc memory */

    printf("\nAll dynamic memory freed. Demo complete.\n");
    return 0;
}
