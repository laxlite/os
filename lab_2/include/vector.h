#include<stddef.h>

typedef struct 
{
    double* data;
    __uint128_t size;
} Vector;

Vector create_vector(size_t size);
Vector create_vector(size_t size, double number);
Vector create_vector(Vector* src);
Vector create_vector(double* array)

Vector dot_product(Vector* vec_1, Vector* vec_2);
Vector vec_sum(Vector* vec_1, Vector* vec_2);
Vector vec_unary_minus(Vector* vec);

Vector delete_vector();