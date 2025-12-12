#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bank {
    char* batteries;
    int count;
} Bank;

typedef struct PowerBanks {
    Bank* banks;
    int num_elements;
    int capacity;
} PowerBanks;

void init_PowerBanks(PowerBanks* arr, int initial_capacity) {
    arr->banks = malloc(sizeof(Bank) * initial_capacity);
    arr->num_elements = 0;
    arr->capacity = initial_capacity;
};

void append(PowerBanks* arr, Bank ele) {
    if (arr->num_elements == arr->capacity) {
        arr->capacity *= 2;
        arr->banks = realloc(arr->banks, sizeof(Bank) * arr->capacity);
    }
    arr->banks[arr->num_elements++] = ele;
};

void free_Banks(Bank* arr) {
    free(arr->batteries);
};

void free_PowerBanks(PowerBanks* arr) {
    for (int i = 0; i < arr->num_elements; i++) {
        free_Banks(&arr->banks[i]);
    }
    free(arr->banks);
};

int total_output_joltage(PowerBanks* banks) {
    int total_joltage = 0;
    for (int i = 0; i < banks->num_elements; i++) {
        int max_in_bank = 0;

        for (int j = 0; j < banks->banks[i].count - 1; j++) {
            int first = banks->banks[i].batteries[j] - '0';

            for (int k = j + 1; k < banks->banks[i].count; k++) {
                int second = banks->banks[i].batteries[k] - '0';
                int joltage = (10 * first) + second;

                if (joltage > max_in_bank) max_in_bank = joltage;
            };
        };

        total_joltage += max_in_bank;
    }
    return total_joltage;
};

int main(void) {
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        perror("input.txt");
        return 1;
    }

    char* batteries_in_bank = NULL;
    size_t len = 0;
    PowerBanks banks;
    init_PowerBanks(&banks, 4);

    while(getline(&batteries_in_bank, &len, f) != -1) {
        size_t line_len = strlen(batteries_in_bank);
        if (line_len > 0 && batteries_in_bank[line_len - 1] == '\n') {
            batteries_in_bank[line_len - 1] = '\0';
            line_len--;
        }

        Bank b;
        b.batteries = strdup(batteries_in_bank);
        b.count = strlen(batteries_in_bank);
        append(&banks, b);
    };

    printf("Total output joltage: %i", total_output_joltage(&banks));
    free(batteries_in_bank);
    free_PowerBanks(&banks);
    return 0;
}

