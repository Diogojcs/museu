//Bibliotecas utilizadas 

#include <stdio.h> //estrtura basica
#include <stdlib.h> // função menu
#include <string.h> // funções de manipulação strings (strings são sequências de caracteres alfanuméricos)
#include <wchar.h> //  garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca C Padrão sejam declarados no namespace std
#include <time.h>  //manipulação de datas e horários de modo padrão.


//estrutura para endereço
typedef struct {
    char rua[30];
    char cep [8];
    char cidade[15];
    char estado [15];
 } end;

//estrutura para cadastro de cliente
typedef struct {
    char nome[50];
    int idade;
    char telefone[11];
    char arquivoVenda[100]; // Nome do arquivo para a venda
    end endereco;
} Cliente;

//estrutura para o ticket que o cliente irá comprar 
typedef struct {
    int id;
    char tipo[100];
    double preco;
} Ticket;



// Função para exibir o menu e obter a escolha do usuário
int menu() {
    int escolha;
    
    printf("\n\nBem-vindo ao Caixa do Museu\n\n");
    printf("1. Registrar Venda de Ticket\n");
    printf("2. Verificar Preco do Ticket\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    
    return escolha;
}


int main() {
    int opcao;
    int numVendas = 0; // Contador de vendas realizadas
    Cliente clientes[100]; // Array para armazenar informações de clientes
    Ticket tickets[6]; // Array para armazenar informações de tickets 


// informações de tickets para venda
    tickets[0].id = 1;
    strcpy(tickets[0].tipo, "Ticket - 100 anos da semana de arte moderna.");
    tickets[0].preco = 10.0;

    tickets[1].id = 2;
    strcpy(tickets[1].tipo, "Ticket - 150 anos de Santos Dumon");
    tickets[1].preco = 10.0;
    
    tickets[2].id = 3;
    strcpy(tickets[2].tipo, "Ticket - Jogos olimpicos de Paris 2024");
    tickets[2].preco = 10.0;

    tickets[3].id = 4;
    strcpy(tickets[3].tipo, "Ticket - Viagens espaciais");
    tickets[3].preco = 10.0;

    tickets[4].id = 5;
    strcpy(tickets[4].tipo, "Ticket - VIP - Acesso a todas as atrasoes");
    tickets[4].preco = 30.0;


    do {
        opcao = menu(); // Exibe o menu e obtém a escolha do funcionário

        switch (opcao) {

                         // opção de escolha 1
                          case 1:


    if (numVendas < 100) {
        printf("Voce escolheu Registrar Venda de Ticket.\n");

        // Solicita informações do cliente
        Cliente novoCliente;
        printf("Digite o nome do cliente: ");
        scanf("%s", novoCliente.nome);
        printf("Digite a data de nascimento do cliente: ");
        scanf("%d", &novoCliente.idade);
        printf("Digite o telefone do cliente: ");
        scanf("%s", novoCliente.telefone);

        // Adicione o cliente ao array de clientes
        clientes[numVendas] = novoCliente;

        // Selecione o tipo de ticket e registre a venda
        printf("\n\nSelecione o tipo de ticket:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s - R$%.2lf\n\n", tickets[i].id, tickets[i].tipo, tickets[i].preco);
        }
        int escolhaTicket;
        printf("Escolha o tipo de ticket:\n\n ");
        scanf("%d", &escolhaTicket);






        if (escolhaTicket >= 1 && escolhaTicket <= 5) { // Alterei o limite para 5
            printf("Venda registrada para %s. Preco do ticket: R$%.2lf\n\n", novoCliente.nome, tickets[escolhaTicket - 1].preco);





            // Código de registro de venda
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);

            char nomeArquivo[20]; // Variável para armazenar o nome do arquivo
            snprintf(nomeArquivo, sizeof(nomeArquivo), "%04d-%02d-%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

            // Constrói o caminho do arquivo com base na pasta "vendas" e no nome do arquivo
            char caminhoArquivo[100]; // Variável para armazenar o caminho do arquivo
            snprintf(caminhoArquivo, sizeof(caminhoArquivo), "vendas/%s", nomeArquivo);

            FILE *arquivo = fopen(caminhoArquivo, "a");
            if (arquivo != NULL) {
                // Escreve as informações da venda no arquivo
                fprintf(arquivo, "\n\nInformações da Venda:\n");
                fprintf(arquivo, "Nome do Cliente: %s\n", novoCliente.nome);
                fprintf(arquivo, "Idade do Cliente: %d\n", novoCliente.idade);
                fprintf(arquivo, "Telefone do Cliente: %s\n", novoCliente.telefone);

                // Adicionar outras informações da venda
                fprintf(arquivo, "Tipo de Ticket: %s\n", tickets[escolhaTicket - 1].tipo);
                fprintf(arquivo, "Preco do Ticket: R$%.2lf\n", tickets[escolhaTicket - 1].preco);

                // Fecha o arquivo
                fclose(arquivo);

                printf("Venda registrada em %s. Preco do ticket: R$%.2lf\n", nomeArquivo, tickets[escolhaTicket - 1].preco);
                numVendas++;

  
            } else {
                printf("Erro ao criar o arquivo de venda.\n");
            }
        } else {
            printf("Opção inválida de ticket.\n");
        }







    } else {
        printf("Não é possível registrar mais vendas. Limite alcançado.\n");
    }
    break;

                  // opção de escolha 2
                  case 2:



                printf("\n\n\n\n Voce escolheu Verificar Preco do Ticket.\n");
                // Adicione código para verificar preços dos tickets, se necessário
                
    
        // Exibir informações de todos os tickets
        printf("Informacoes dos Tickets:\n\n");
            for (int i = 0; i < 5; i++) {
        printf("%d\n", tickets[i].id);
        printf("Tipo: %s\n", tickets[i].tipo);
        printf("Preco: R$%.2lf\n", tickets[i].preco);
        printf("\n");
        }                                                       
                break;

            // opção de escolha 3
            case 3:


                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3); // Repetir até que o funcionário escolha sair (opção 3)

    return 0;
}



//PIM Matheus Benicio e Diogo Silva

