/**
 * @file controllermenu.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar todas funções que controlam o menu
 * @version 0.1
 * @date 14/06/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "controllermenu.h"

#ifdef __gnu_linux__

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */
char getChar() {
    char character = 0;
    struct termios old = {0};
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&character,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return character;
}

#else

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */
char getChar() {
    DWORD mode, cc;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
    if (h == NULL)
        return 0; // console not found
    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}

#endif //__gnu_linux__

/**
 * @brief Create a Entry Queue object
 * 
 * @return EntryQueue* 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryQueue* createEntryQueue() {
    EntryQueue *newQueue = (EntryQueue *)malloc(sizeof(EntryQueue));
    newQueue->head = newQueue->tail = NULL;
    newQueue->size = 0;
    return newQueue;
}

/**
 * @brief Aloca a estrutura EntryNode
 * 
 * @return EntryNode* 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryNode* allocEntryNode() {
    return (EntryNode *)malloc(sizeof(EntryNode));
}

/**
 * @brief Informa se a lista passada como argumento é vazia
 * 
 * @param queue Uma fila
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyEntryQueue(EntryQueue *queue) {
    return (queue->head == NULL);
}

/**
 * @brief Devolve o tamanho da fila
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila
 */
int sizeEntryQueue(EntryQueue *queue) {
    return queue->size;
}

/**
 * @brief Executa a opção selecionada
 * 
 * @param queue ponteiro para uma estrutura que contém as 
 * informações de uma fila
 * @param option inteiro com a opcao escolhida
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post retorna funct da opção
 */
int executeEntry(EntryQueue *queue, int option, FILE *dataFile) {
    int i, ret;
    EntryNode *node = queue->head;
    for(i = 0; i < option; i++)
        node = node->prox;
    return (*(node->funct))(dataFile);
}

/**
 * @brief Realiza o controle de um menu previamente criado
 * 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int (ver se não é void)
 * @pre todas as informações do menu previamente carregadas e 
 * ponteiro para arquivo aberto
 * @post o menu chamado será executado, bem como a função selecionada
 */
int controlMenu(Menu *menu, FILE *dataFile) {
    char c;
    while(1) {
        system(CLEAR);
        printMenu(menu);
        c = getChar();
        if (c == UP) {
            if(menu->thisOption > 0)
                menu->thisOption--;    
            else
                menu->thisOption = menu->options - 1;
        }else if (c == DOWN) {
            if(menu->thisOption < menu->options - 1)
                menu->thisOption++;    
            else
                menu->thisOption = 0;
        }else if(isdigit(c)) {
            int option = c - '1';
            if (option >= 0 && option < menu->options) {
                menu->thisOption = option;
            }else {
                printLine();
                printAlignedCenter("Digito fora dos limites");
                printLine();
                printWaitMenu();
            }
        }else if(c == ENTER) {
            if(executeEntry(menu->queue, menu->thisOption, dataFile) == 0)
                return 1;
        }else{
            printLine();
            printAlignedRight("Entrada do teclado incorreta");
            printLine();
            printWaitMenu();
        }
    }
}