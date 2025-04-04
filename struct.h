#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    char pizza_id[10];
    char order_id[10];
    char pizza_name_id[50];
    int quantity;
    char order_date[20];
    char order_time[20];
    float unit_price;
    float total_price;
    char pizza_size[5];
    char pizza_category[30];
    char pizza_ingredients[150];
    char pizza_name[100];
} order;

#endif