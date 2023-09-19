//Bibliotecas utilizadas 

#include <stdio.h> //estrtura basica
#include <stdlib.h> // função menu
#include <string.h> // funções de manipulação strings (strings são sequências de caracteres alfanuméricos)

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
    
    printf("Bem-vindo ao Caixa do Museu\n\n");
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
    Ticket tickets[6]; // Array para armazenar informações de tickets (até 5 tipos diferentes)


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
    strcpy(tickets[3].tipo, "Ticket - Tema ainda a ser definido");
    tickets[3].preco = 10.0;

    tickets[4].id = 5;
    strcpy(tickets[4].tipo, "Ticket - VIP");
    tickets[4].preco = 30.0;


    do {
        opcao = menu(); // Exibe o menu e obtém a escolha do funcionário

        switch (opcao) {
            case 1:
                if (numVendas < 100) {
                    printf("Voce escolheu Registrar Venda de Ticket.\n");

                    // Solicita informações do cliente
                    Cliente novoCliente;
                    printf("Digite o nome do cliente: ");
                    scanf("%s", novoCliente.nome);
                    printf("Digite a idade do cliente: ");
                    scanf("%d", &novoCliente.idade);
                    printf("Digite o telefone do cliente: ");
                    scanf("%s", novoCliente.telefone);

                    // Solicita informações do endereço do cliente
                    printf("Digite o nome da rua: ");
                    scanf("%s", novoCliente.endereco.rua);
                    printf("Digite o CEP: ");
                    scanf("%s", novoCliente.endereco.cep);
                    printf("Digite a cidade: ");
                    scanf("%s", novoCliente.endereco.cidade);
                    printf("Digite o estado: ");
                    scanf("%s", novoCliente.endereco.estado);

                    // Adicione o cliente ao array de clientes
                    clientes[numVendas] = novoCliente;

                    // Selecione o tipo de ticket e registre a venda
                    printf("Selecione o tipo de ticket:\n");
                    for (int i = 0; i < 5; i++) {
                        printf("%d. %s - R$%.2lf\n", tickets[i].id, tickets[i].tipo, tickets[i].preco);
                    }
                    int escolhaTicket;
                    printf("Escolha o tipo de ticket: ");
                    scanf("%d", &escolhaTicket);
                    if (escolhaTicket >= 1 && escolhaTicket <= 2) {
                        printf("Venda registrada para %s. Preço do ticket: R$%.2lf\n", novoCliente.nome, tickets[escolhaTicket - 1].preco);
                        numVendas++;
                    } else {
                        printf("Opção inválida.\n");
                    }
                } else {
                    printf("Não é possível registrar mais vendas. Limite alcançado.\n");
                }
                break;
            case 2:
                printf("Você escolheu Verificar Preço do Ticket.\n");
                // Adicione código para verificar preços dos tickets, se necessário
                break;
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