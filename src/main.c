#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_LENGTH 10

const char* top_symbols[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

const char* left_symbols[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

bool tmp_field[FIELD_LENGTH][FIELD_LENGTH] = {false};

char* player_field[FIELD_LENGTH][FIELD_LENGTH];

int left, top;

int ships_count = 4;

/* cell occupation */
void cell_occupation(int left, int top);

/* fill 2d array*/
void fill_player_filed_with_o();

void insert_ship_to_player_field();

int main(void)
{
    srand((unsigned)time(NULL));
    fill_player_filed_with_o();

    insert_ship_to_player_field();
    insert_ship_to_player_field();
    insert_ship_to_player_field();
    insert_ship_to_player_field();

    printf("\n\n\n");

    /* print player field*/
    for (int i = 0; i < FIELD_LENGTH; i++)
    {
        for (int j = 0; j < FIELD_LENGTH; j++)
        {
            printf(" %s ", player_field[i][j]);
            if (j == 9) printf("\n");
        }
    }
    printf("\n\n\n");

    /* print tmp_field*/
    for (int i = 0; i < FIELD_LENGTH; i++)
    {
        for (int j = 0; j < FIELD_LENGTH; j++)
        {
            printf(" %d ", tmp_field[i][j]);
            if (j == 9) printf("\n");
        }
    }

    printf("\n");
}

void cell_occupation(int left, int top)
{
    tmp_field[left][top] = true;

    tmp_field[left + 1][top] = true;
    tmp_field[left - 1][top] = true;

    if (top + 1 <= 9)
    {
        tmp_field[left][top + 1] = true;
        tmp_field[left + 1][top + 1] = true;
        tmp_field[left - 1][top + 1] = true;
    }

    if (top - 1 >= 0 && top - 1 <= 9)
    {
        tmp_field[left][top - 1] = true;
        tmp_field[left + 1][top - 1] = true;
        tmp_field[left - 1][top - 1] = true;
    }
}

void fill_player_filed_with_o()
{
    for (int i = 0; i < FIELD_LENGTH; i++)
    {
        for (int j = 0; j < FIELD_LENGTH; j++)
        {
            player_field[i][j] = "o";
        }
    }
}

void insert_ship_to_player_field()
{
    int left, top;

    printf("%ld\n", sizeof(player_field));

    while (true)
    {
        left = rand() % FIELD_LENGTH;
        top = rand() % FIELD_LENGTH;

        if (!tmp_field[left][top])
        {
            cell_occupation(left, top);
            player_field[left][top] = "X";
            printf("%s %s\n", left_symbols[left], top_symbols[top]);
            break;
        }
    }
}

/* Сделать функцию для расположения двухпалубных кораблей на поле*/
