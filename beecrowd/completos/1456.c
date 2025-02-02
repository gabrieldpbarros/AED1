#include <stdio.h>
#include <string.h>

#define MEMORY_SIZE 30000
#define MAX_INPUT_SIZE 100000

void execute_brainfuck(const char *input, const char *code, int instance){
    unsigned char memory[MEMORY_SIZE] = {0}; // Inicializa todas as células da memória com zero
    unsigned char *ptr = memory; // Ponteiro para a memória
    const char *code_ptr = code; // Ponteiro para o código
    const char *input_ptr = input; // Ponteiro para a entrada
    char output[MAX_INPUT_SIZE] = {0}; // Armazena a saída
    int output_idx = 0; // Índice da saída

    printf("Instancia %d\n", instance);

    // Pilha de loops
    const char *loop_stack[MAX_INPUT_SIZE];
    int loop_top = -1;

    while(*code_ptr){
        switch(*code_ptr){
            case '>':
                if(ptr < memory + MEMORY_SIZE - 1)
                    ptr++;
                break;
            case '<':
                if(ptr > memory)
                    ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                output[output_idx++] = *ptr;
                break;
            case ',':
                *ptr = (*input_ptr) ? *(input_ptr++) : 0;
                break;
            case '[':
                if(*ptr)
                    loop_stack[++loop_top] = code_ptr; // Empilha o endereço do loop
                else{
                    int open_brackets = 1;
                    while(open_brackets){
                        code_ptr++;
                        if(*code_ptr == '[')
                            open_brackets++;
                        if(*code_ptr == ']')
                            open_brackets--;
                    }
                }
                break;
            case ']':
                if(*ptr)
                    code_ptr = loop_stack[loop_top]; // Volta para o início do loop
                else 
                    loop_top--; // Sai do loop
                break;
            case '#':
                for(int i = 0; i < 10; i++)
                    printf("%d ", memory[i]);
                printf("\n");
                break;
        }
        code_ptr++;
    }

    if(output_idx > 0)
        printf("%s\n", output);

    printf("\n"); // Linha em branco entre instâncias
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    for(int i = 1; i <= n; i++){
        char input[MAX_INPUT_SIZE] = {0};
        char code[MAX_INPUT_SIZE] = {0};

        getchar();
        
        // Lê a entrada para o programa
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove a quebra de linha

        // Lê o código Brainfuck
        fgets(code, MAX_INPUT_SIZE, stdin);
        code[strcspn(code, "\n")] = 0; // Remove a quebra de linha

        execute_brainfuck(input, code, i);
    }

    return 0;
}
