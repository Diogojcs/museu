## Projeto de sistema de venda de ingresso  - Museu multitemático

##	Sistema de venda de ingressos

O projeto, determinado pelo professor da Unip - Universidade paulista, curso de Analise e desenvolvimento do sistema, exigiu a escolha de tecnologias considerando implicações financeiras. Optou-se por tecnologias de código aberto, como a linguagem de programação C (devido à familiaridade adquirida na faculdade).
Essa decisão, alinhada aos objetivos do projeto, visa reduzir custos e oferecer flexibilidade. Embora não esteja planejada a implementação de um banco de dados, considerações foram feitas para futuras possibilidades.
Vale ressaltar que, até o momento, não está prevista a implementação de um banco de dados no sistema, mas foram feitas considerações para que isso possa ser implementado futuramente.

![image](https://github.com/Diogojcs/museu/assets/122985524/9783037f-26f3-4840-98b3-8096c5ba5a72)

Figura 1 - Fluxograma

No fluxograma, é possível analisar o processo que envolve a aquisição de ingressos, a emissão dos tickets de entrada, bem como a entrada e saída, abordando alguns dos temas designados.


![image](https://github.com/Diogojcs/museu/assets/122985524/c50dcbde-c15a-4339-be70-cab65c48ce81)

Figura 2 - Pastas e Arquivos do Projeto

Na Figura 2, é possível observar a estrutura do projeto, com a seção principal desenvolvida em linguagem C e a pasta de vendas. Dentro dessa pasta, há um arquivo em formato de texto (TXT) contendo informações datadas, que compreendem todos os dados dos clientes e detalhes das compras feitas por eles, separadamente.


![image](https://github.com/Diogojcs/museu/assets/122985524/c28a876a-e41c-4b46-a8a6-22d4f62fd058)

Figura 3 - Menu inicial do projeto


A figura 3 representa o menu inicial do projeto em linguagem C apresenta um conjunto de opções para interação do usuário. Ao iniciar o programa, o menu é exibido na tela por meio da função `printf`. Cada linha representa uma funcionalidade disponível no sistema:

1. Registrar Venda de Ticket: Esta opção é destinada a efetuar a venda de ingressos para o museu. Antes de concluir essa operação, o programa solicita informações essenciais do cliente, como nome, telefone e idade. Esses detalhes são requisitados para cadastrar o cliente na base de dados, associando essas informações à transação de venda do ticket.
2. Verificar Preço do Ticket: Esta opção oferece ao usuário a oportunidade de verificar o preço do ingresso para o museu. Esta funcionalidade geralmente não inclui a coleta de informações do cliente, servindo apenas para informar o valor do ticket.
3.  Sair: Ao escolher esta opção, o programa é encerrado, proporcionando ao usuário uma saída do sistema.

Após apresentar as opções, o programa aguarda a entrada do usuário por meio da função `scanf`. Neste ponto, o usuário pode inserir um número inteiro correspondente à opção desejada. Se o usuário optar por registrar a venda do ticket (opção 1), será solicitado que forneça os dados do cliente para cadastrá-los na base de dados, antes de finalizar a transação.

## Venda de ingressos

A venda de ingressos é uma das funcionalidades principais do sistema. Ao selecionar a opção "Registrar Venda de Ticket" no menu, o programa permite ao usuário cadastrar a venda de ingressos para clientes.
Antes de finalizar a transação, o sistema solicita informações básicas do cliente, como nome, data de nascimento e telefone. Estes dados são inseridos pelo usuário para cadastrar o cliente na base de dados do sistema.
Posteriormente, o programa exibe uma lista pré-definida de tipos de ingressos disponíveis para venda. Após a escolha do cliente, o usuário seleciona o tipo de ingresso desejado pelo seu número correspondente.
Após a seleção do tipo de ingresso, o sistema registra a venda em um arquivo de texto, incluindo detalhes como o nome do cliente, idade, telefone, tipo de ticket escolhido e o preço do ingresso.
O código utiliza a data e hora atual para criar um arquivo de venda, onde são armazenadas as informações da transação. Vale ressaltar que a implementação poderia ser aprimorada com validações adicionais, como a verificação de limites de vendas, tratamento de erros e melhorias na interação com o usuário para tornar o sistema mais robusto e amigável.

![image](https://github.com/Diogojcs/museu/assets/122985524/963b5242-1c37-4e10-a374-44187062fda2)

Figura 4 - Registrando venda


Quando uma venda de ingresso é registrada, o programa gera um arquivo de texto (formato .txt) para armazenar as informações referentes a essa venda. Esse arquivo é criado com base na data atual e serve como um registro das transações realizadas.


![arquivotxt](https://github.com/Diogojcs/museu/assets/122985524/21efbd79-4174-45d0-94ce-0fc8025e3e71)

Figura 5 Arquivo txt para armazenar as vendas 

Detalhes sobre o arquivo gerado
O nome do arquivo é gerado a partir da data e hora em que a venda foi realizada. É criado usando a função `time` da biblioteca `time.h`.
 A nomenclatura segue o formato: `AAAA-MM-DD.txt`, onde 'AAAA' representa o ano, 'MM' o mês e 'DD' o dia da transação. Exemplo: `2023-10-28.txt`.

O arquivo gerado contém informações sobre a venda, incluindo detalhes do cliente e do ingresso adquirido.
   
As informações registradas no arquivo incluem:

1.	 Nome do cliente.
2.	 Idade do cliente.
3.	 Telefone do cliente.
4.	 Tipo de ingresso adquirido.
5.	 Preço do ingresso.


O arquivo é armazenado na pasta "vendas", conforme definido no código.
A estrutura do caminho do arquivo é formada concatenando o diretório "vendas" com o nome do arquivo gerado.

O arquivo é gerado no formato de texto simples (.txt). As informações são gravadas sequencialmente, em linhas separadas, facilitando a leitura e interpretação dos dados. A finalidade desse arquivo é manter um registro organizado e rastreável das vendas realizadas no sistema. Esses registros podem ser consultados posteriormente para análises, relatórios ou auditorias.
O uso desse arquivo permite manter um histórico de vendas, facilitando o acompanhamento das transações realizadas pelo sistema de venda de ingressos assim como visualizado na figura 5.
Na opção 02 está associada à funcionalidade "Verificar Preço do Ticket" dentro de um sistema de vendas de ingressos para um museu.
Quando o usuário seleciona a opção 2 no menu, o programa exibe informações sobre os diferentes tipos de ingressos disponíveis, fornecendo os detalhes dos tickets e seus preços correspondentes.


![image](https://github.com/Diogojcs/museu/assets/122985524/21329f94-84fe-4ac0-bfad-8b837e95b44c)

Figura 6 - Lista de ingressos e valores

A execução da opção 02 inclui as seguintes ações como mostra na figura 7:

1. Exibição de Informações de Tickets:
   - O programa mostra no console as informações referentes aos tipos de ingressos disponíveis para compra.
   - Para cada tipo de ingresso, são apresentados:
     - O identificador único do ticket.
     - O tipo de ticket ou a descrição do ingresso.
     - O preço associado a cada tipo de ingresso.

Essa funcionalidade permite que o vendedor ou atendente do museu consulte e informe aos clientes os tipos de ingressos disponíveis e seus respectivos preços. O objetivo é fornecer aos clientes em potencial uma visão clara e detalhada das opções de ingressos disponíveis, facilitando a escolha do ticket desejado com base nas informações exibidas.

