#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void n_bombasM(int n, char mapa_matriz[][n]){
  //função utilizada para alocar as os ? em suas devidos coordenadas
  //mapa do campo minado
  for (int linha = 1; linha <= n; linha++){
    for (int coluna = 1; coluna <= n; coluna++){
      mapa_matriz[linha][coluna] = '?';
    }
  }
  
}
void n_bombas(int l,int c, int n,char M[][n]){
  //função utilizada para alocar as bombas em suas devidos coordenadas
  //mapa do campo minado
  //mapa da mina -/ second matriz
  for (int linha = 1; linha <= l; linha++){
    for (int coluna = 1; coluna <= c; coluna++){
      M[linha][coluna] = '?';
    }
  }
  int contagem_minas = 0.2 * (n*n);
  while (contagem_minas > 0){
    // gera coordenadas aleatórias das minas e loca as minas em tais coordenadas
    int linha = rand() % n + 1;
    int coluna = rand() % n + 1 ;
    if (M[coluna][linha] == '*'){
      continue;
    }
    M[coluna][linha] = '*';
    --contagem_minas;
  }
}
void imprime_mat(int  n,char M[][n]){
  //função utilizada para imprimir a matriz durante o jogo
  printf("\n");
  for (int linha = 1; linha <= n; linha++){
    if(linha < 10){
        printf(" %d |", linha);
    }else{
        printf(" %d|", linha);
    }
    for (int coluna = 1; coluna <= n; coluna++){
      printf("%c  ", M[linha][coluna]);
    }
    printf("\n");
  }
  printf("   ");
    for(int i = 0; i < n; i++){
        printf("---");
    }
    printf("\n    ");
    for(int i = 0; i < n; i++){
        printf("%d  ", i+1);
    }
    printf("\n");
}
void imp_Derrota(int ordem,char mapa[][ordem],char mapa_bombas_matriz[][ordem]){
  //função utilizada para impressão do mapa após o usuário perder
  printf("\n");
  for (int linha = 1; linha <= ordem; linha++){
    if(linha < 10){
        printf(" %d |", linha);
        //este if é para ver a coluna da ordeeem pois para não ficar desalinhado
    }else{
        printf(" %d|", linha);
    }
    for (int coluna = 1; coluna <= ordem; coluna++){
      if(mapa[linha][coluna] == '?' && mapa_bombas_matriz[linha][coluna] != '*'){
        printf("%c  ",mapa[linha][coluna]);
      }else{
        if(mapa_bombas_matriz[linha][coluna] == '*' && mapa[linha][coluna] == '?'){
          printf("%c  ",mapa_bombas_matriz[linha][coluna]);
        }else{
          printf("%c  ",mapa[linha][coluna]);
        }
      }
    }
    printf("\n");
  }
  printf("   ");
    for(int i = 0; i < ordem; i++){
        printf("---");
    }
    printf("\n    ");
    for(int i = 0; i < ordem; i++){
        printf("%d  ", i+1);
    }
    printf("\n");
}
void imp_Vitoria(int ordem,char mapa_bombas_matriz[][ordem],char mapa[][ordem]){
  //função utilizada para impressão do mapa após o usuário ganhar
  printf("\n");
  for (int linha = 1; linha <= ordem; linha++){
    if(linha < 10){
        //este if é para ver a coluna da ordeeem pois para não ficar desalinhado
        printf(" %d |", linha);
    }else{
        printf(" %d|", linha);
    }
    for (int coluna = 1; coluna <= ordem; coluna++){
      if(mapa_bombas_matriz[linha][coluna] == '?' && mapa[linha][coluna] != '?'){
        printf("%c  ",mapa[linha][coluna]);
      }else{
        if(mapa[linha][coluna] == '?' && mapa_bombas_matriz[linha][coluna] != '*'){
          mapa_bombas_matriz[linha][coluna] = '1';
          printf("%c  ",mapa_bombas_matriz[linha][coluna]);
        }else{
          printf("%c  ",mapa_bombas_matriz[linha][coluna]);
        }
          
      }
    }
    printf("\n");
  }
  printf("   ");
    for(int i = 0; i < ordem; i++){
        printf("---");
    }
    printf("\n    ");
    for(int i = 0; i < ordem; i++){
        printf("%d  ", i+1);
    }
    printf("\n");
}
void atualiza_mapa(int ordem,char mapa_matriz[][ordem], char mapa_bombas_matriz[][ordem], int linha, int coluna){
  //função utilizada para atualizar durante o jogo,o contador e mostrar as casas vizinhas
  int cont = 0;
  if (linha - 1 >= 0 && coluna - 1 >= 0 && mapa_bombas_matriz[linha - 1][coluna - 1] == '*'){ 
    cont++;
  }
  if (linha - 1 >= 0 && mapa_bombas_matriz[linha - 1][coluna] == '*'){
    cont++;
  }
  if (linha - 1 >= 0 && coluna + 1 < ordem && mapa_bombas_matriz[linha - 1][coluna + 1] == '*'){
    cont++;
  }
  if (coluna - 1 >= 0 && mapa_bombas_matriz[linha][coluna - 1] == '*'){
    cont++;
  }
  if (coluna + 1 < ordem && mapa_bombas_matriz[linha][coluna + 1] == '*'){
    cont++;
  }
  if (linha + 1 < ordem && coluna - 1 >= 0 && mapa_bombas_matriz[linha + 1][coluna - 1] == '*'){
    cont++;
  }
  if (linha + 1 < ordem && mapa_bombas_matriz[linha + 1][coluna] == '*'){
    cont++;
  }
  if (linha + 1 < ordem && coluna + 1 < ordem && mapa_bombas_matriz[linha + 1][coluna + 1] == '*'){
    cont++;
  }
  mapa_matriz[linha][coluna] = cont + '0';
}
int main(){
    int ordem = 0;
    printf("Digite o ordemanho da matriz desejada: ");
    scanf("%d",&ordem);
    srand((unsigned int)time(NULL));
    char mapa_matriz[ordem][ordem];
    char mapa_bombas_matriz[ordem][ordem];
    int contagem_minas;
    int l = ordem;
    int c = ordem;
    n_bombasM(ordem,mapa_matriz);
    n_bombas(l,c,ordem, mapa_bombas_matriz); 
    int cont_compara = 0;
    while (1){
    //imprime_mat(ordem, mapa_bombas_matriz); // para teste foi utilizado, ele imprime as locs das bombas para certificar q o jogo está funcionando
      printf("\n");
      imprime_mat(ordem,mapa_matriz);
      printf(" Digite a linha e coluna desejada: ");
      int linha = 1 ;
      int coluna = 1;
      scanf("%d %d",&linha,&coluna);
      if (linha <= 0 || linha > ordem || coluna <= 0 || coluna > ordem ){
        printf(" Entrada invalida \n");
        continue;
      }if (mapa_matriz[linha][coluna] != '?'){
        printf(" Esta posição já foi virada! \n");
        continue;
      }
      //se pisar na mina ele entra neste if abaixo.
      if (mapa_bombas_matriz[linha][coluna] == '*'){
        printf("VOCE PERDEU! FIM DE JOGO !\n");
        imp_Derrota(ordem,mapa_matriz,mapa_bombas_matriz);
        break;
      }
      cont_compara++;
      contagem_minas = 0.2 * (ordem*ordem);
      //se nao pizar em nenhuma mina e atingir os 80% ou seja desvendar as locs das bmbas sem virar a posição ele entra neste if
      //o blanck ele é um contador que compara com os 20% de bomba
      if (cont_compara == ordem * ordem - contagem_minas){
        printf("PARABENS! VOCE VENCEU!\n");
        imp_Vitoria(ordem,mapa_bombas_matriz,mapa_matriz);
        break;
      }
      //atualiza o mapa com as posições
      atualiza_mapa(ordem,mapa_matriz, mapa_bombas_matriz, linha, coluna);
    }
    
    return 0;
}
