#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char word[17];
    int value;
} instance;

int compare_strings(instance **dictionary, char *string, int dictionary_size){
    for(int i = 0; i < dictionary_size; i++)
        if(strcmp(dictionary[i]->word, string) == 0)
            return dictionary[i]->value;

    return 0;
}

int main(){
    int qt_parameters, qt_inputs, i;
    scanf("%d %d", &qt_parameters, &qt_inputs);
    getchar();

    double *wages = calloc(qt_inputs, sizeof(double));
    instance **dictionary = malloc(qt_parameters * sizeof(instance*));
    char *entrada = malloc(25 * sizeof(char));

    for(i = 0; i < qt_parameters; i++){
        dictionary[i] = malloc(sizeof(instance));

        fgets(entrada, 25, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        char *token = strtok(entrada, " ");
        strcpy(dictionary[i]->word, token);

        token = strtok(NULL, " ");
        dictionary[i]->value = atoi(token);
    }
    free(entrada);

    entrada = malloc(100 * sizeof(char));
    for(i = 0; i < qt_inputs; i++){
        scanf("%s", entrada);
        while(strcmp(entrada, ".") != 0){
            wages[i] += compare_strings(dictionary, entrada, qt_parameters);
            scanf("%s", entrada);
        }
    }
    
    free(entrada);

    for(i = 0; i < qt_inputs; i++)
        printf("%0.f\n", wages[i]);

    for(i = 0; i < qt_parameters; i++)
        free(dictionary[i]);
    free(dictionary);
    free(wages);

    return 0;
}