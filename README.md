# ProjetoDCC120
Projeto de "Water Sort Puzzle" em C para a disciplina DCC120 UFJF, utilizando apenas recursos aprendidos durante o semestre.

# O Código 

* IMPORTANTE: As bibliotecas "unistd.h" e "Windows.h" foram utilizadas apenas para propósitos estéticos, não interferindo na jogabilidade. 
* Main: 
  - 1. Gera potes em configuração 'perfeita'. Os potes são matrizes de 7 linhas por 4 colunas.
  - 2. Define a primeira fase (1). 
  - 3. Mostra a tela inicial por 5 segundos. 
  - 4. Mostra as instruções até que o usuario aperte uma tecla. 
  - 5. Utiliza da função srand. 
  - 6. Usa um loop para gerar os potes, com um loop do jogo dentro. 
  - 7. Mostra a tela final. 
-----

* Funcões: 

  - Tela: Mostra na tela a interface inicial do jogo. 
  
  - Instruçoes: Mostra na tela as instruções do jogo. 
  
  - GerarPotes: Partindo de uma configuração onde os potes estão perfeitamente organizados (todos os elementos com a mesma cor), utiliza-se a função 'rand' e a função 'jogo' para embaralhar as bolinhas. 
  
  - MostrarPotes: Mostra na tela a configuração atual dos potes. 
  
  - Checar: Confere se os potes estão todos com bolinhas da mesma cor, caso estejam, retorna 1. Caso contrário, retorna 0. 
  
  - ChecarStatus: Confere se o pote que o jogador selecionou para tirar 1 bolinha contém bolinhas e confere se o pote que o jogador selecionou para colocar
  1 bolinha tem espaço vazio.
  
  - TelaFinal: Mostra na tela a interface final e os créditos:
  
  -----
  
* Função 'jogo': 
  
  - 1. Recebe input do usuário (tirar, colocar), que seleciona de qual pote ele quer tirar 1 bolinha e em qual pote quer colocar. 
  - 2. Checa se os inputs são valido (maiores 0 e menores que 8)
  - 3. Checa os status dos potes com  a função 'checarStatus'
  - 4. Pega o primeiro valor não nulo do pote de número (tirar - 1) e coloca no primeiro valor nulo do pote de número (colocar - 1) 
  - 5. Mostra os potes
  - 6. Checa se o jogo está ganho. 
