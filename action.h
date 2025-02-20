#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include <math.h>

typedef struct stock{
    char name[MAX_CHAR];
    int price;
    int amount;
    struct stock *next; 
}l_stock;

typedef struct user{
    int clientfd; // thread_id
    int id;
    char username[MAX_CHAR];
    char password[MAX_CHAR];
    int balance;
    int status;
    int is_online;
    int pass_incorrect;
    l_stock *stock;
    struct user *next;
}l_user;

l_user *create_user(int id, char username[MAX_CHAR], char password[MAX_CHAR], int balance, int status, l_stock* stock);
l_stock *create_stock(char name[MAX_CHAR], int amount, int price);
void add_stock(l_stock **stock, l_stock *node);
void add_user(l_user **head, l_user *node);

void print_list();
void error(char *s);

l_user *current_user;
l_user *get_account(char username[MAX_CHAR]);
int sign_in(char username[MAX_CHAR], char password[MAX_CHAR], int clientfd);
int check_pass(l_user *account, char password[MAX_CHAR]);
int has_account(char username[MAX_CHAR]);
void log_out(char username[MAX_CHAR]);
l_user *trade_user(char id[MAX_CHAR]);
char* user_stock_list(char id[MAX_CHAR]);
int direct_trade(l_user *current_user, l_user *trader, char stock_name[MAX_CHAR], int price, int type);
char* online_users(char username[MAX_CHAR]);