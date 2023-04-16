#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 200

typedef struct dados{
	int codigo;
	char titulo[30];                    
	char descricao[100];
	int ano;
	int status;
	char gerenteResp[30];
	char cliente[30];
	float orcamento;
	char dataPrazoFinal[10]; 
}dadosProjeto;

int posicao = 0;

void cadastrarProjeto(dadosProjeto cadastro[MAX]);
void buscarCodigo(dadosProjeto cadastro[MAX]);
void projetosEmEspera(dadosProjeto cadastro[MAX]);
void projetosEmExecucao(dadosProjeto cadastro[MAX]);
void projetosConcluidos(dadosProjeto cadastro[MAX]);
void listaTodosProjetos(dadosProjeto cadastro[MAX]);

void logoProg(){
	printf("\n   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	printf("\n   XX                    LOYALTY TECH                         XX");
	printf("\n   XX                CADASTRO DE PROJETOS                     XX");
	printf("\n   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	printf("\n");
}

void menu(){
	printf("\n 1 - Cadastrar projetos.");
	printf("\n 2 - Pesquisar o projeto pelo código cadastrado");
	printf("\n 3 - Mostrar os projetos que estão aguardando serem inicializados.");
	printf("\n 4 - Mostrar os projetos que estão em execução.");
	printf("\n 5 - Mostrar os projetos que estão concluídos.");
	printf("\n 6 - Mostrar todos os projetos cadastrados.");
	printf("\n 7 - Sair.");
	printf("\n");
	printf("\n Digite o número da opção desejada:");
}

void cadastrarProjeto(dadosProjeto cadastro[MAX]){
	system("cls");
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	printf("\n   <>              CADASTRAR NOVOS PROJETOS              <>");
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	char resp = 's';
	int opcaoStatus = 0;
	while(resp =='s' && posicao <= MAX){
		posicao++;
		printf("\n\nCódigo do projeto: %d ", posicao);
		cadastro[posicao].codigo = posicao;
		fflush(stdin);
		printf("\nInforme o título do projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].titulo);		
		printf("\nInforme a descrição do projeto: ");
		gets(cadastro[posicao].descricao);
		fflush(stdin);
		printf("\nInforme o ano do início do projeto: ");
		scanf("%d", &cadastro[posicao].ano);
		fflush(stdin);
		do {
			printf("\nInforme o status do projeto.\n1-Aguardando início 2-Em execução 3-Finalizado: ");
			scanf("%d", &opcaoStatus);
		if(opcaoStatus >= 1 && opcaoStatus <= 3)
				cadastro[posicao].status = opcaoStatus;
				fflush(stdin);
		} while(opcaoStatus < 1 || opcaoStatus > 3);

		printf("\nInforme o nome do gerente responsável pelo projeto: ");
		gets(cadastro[posicao].gerenteResp);	
		fflush(stdin);
		printf("\nInforme o nome do cliente e/ou patrocinador: ");
		gets(cadastro[posicao].cliente);
		fflush(stdin);
		printf("\nInforme o valor do orçamento do projeto: ");
		scanf("%f", &cadastro[posicao].orcamento);
		fflush(stdin);
		printf("\nInforme a data do prazo definido para a entrega do projeto (xx/xx/xxxx): ");
		gets(cadastro[posicao].dataPrazoFinal);
		fflush(stdin);
		printf("-------------------------------------------------------------------------------------------\n");

		if(posicao < MAX){
			printf("\n Continuar o cadastro? [s]Sim ou [n]Não : ");
			scanf("%c", &resp);
			fflush(stdin);
			
			printf("-------------------------------------------------------------------------------------------\n");
		}else{
			printf("\n\nSolicitação inválida. Limite máximo de cadastro atingido! ");
			system("pause");
			resp = 'n';
		}
	}
}	

void buscarCodigo(dadosProjeto cadastro[MAX]){
	system("cls");
	int codigo, encontrado;
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	printf("\n   <>           PROCURA POR CÓDIGO DO PROJETO            <>");
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	printf("\n\n Digite o código do Projeto: ");
	scanf("%d", &codigo);
	encontrado = 0;
	int j = 1;
	while((encontrado == 0) && (j <= posicao)){
		if(codigo == cadastro[j].codigo){
			printf("\n\nCódigo: %d", cadastro[j].codigo);
			printf("\nTítulo: %s", cadastro[j].titulo);
			printf("\nDescrição: %s", cadastro[j].descricao);
			printf("\nAno: %d", cadastro[j].ano);
			printf("\nStatus: %d", cadastro[j].status);
			printf("\nGerente Reponsável: %s", cadastro[j].gerenteResp);
			printf("\nCliente: %s", cadastro[j].cliente);
			printf("\nOrçamento: %.2f", cadastro[j].orcamento);
			printf("\nPrazo final: %s", cadastro[j].dataPrazoFinal);
			printf("\n---------------------------------------------------------------------------------\n");
			encontrado = 1;
			system("pause");
		}
		j++;
	}
	if(encontrado == 0){
		printf("\nCadastro não encontrado com o código %d solicitado. \n", codigo);
		system("pause");
	}
}

void listarProjetosPorStatus(dadosProjeto cadastro[MAX], int status){
	system("cls");
	int encontrou = 0;
	int num = 1;
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	if(status == 1){	
		printf("\n   <>             PROJETOS AGUARDANDO INÍCIO             <>");
	}else if(status == 2){	
		printf("\n   <>                PROJETOS EM EXECUÇÃO                <>");
	}else if(status == 3){	
		printf("\n   <>                PROJETOS FINALIZADOS                <>");
	}	
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	while(num <= posicao){
		if(cadastro[num].status == status){
			printf("\n\nCódigo: %d", cadastro[num].codigo);
			printf("\nTítulo: %s", cadastro[num].titulo);
			printf("\nDescrição: %s", cadastro[num].descricao);
			printf("\nAno: %d", cadastro[num].ano);
			printf("\nStatus: %d", cadastro[num].status);
			printf("\nGerente Reponsável: %s", cadastro[num].gerenteResp);
			printf("\nCliente: %s", cadastro[num].cliente);
			printf("\nOrçamento: %.2f", cadastro[num].orcamento);
			printf("\nPrazo final: %s", cadastro[num].dataPrazoFinal);
			printf("\n---------------------------------------------------------------------------------\n");
			encontrou = 1;
		}
		num++;
	}
	if(encontrou == 0){
		printf("\n\n Sem Projeto cadastrado.\n");
	}
	system("pause");
}	

void listaTodosProjetos(dadosProjeto cadastro[MAX]){
	system("cls");
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	printf("\n   <>             LISTA DE TODOS OS PROJETOS             <>");
	printf("\n   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	int linha = 1;
	int encontrou = 0;
	if(posicao >= 0){
		while(linha <= posicao){
			printf("\n\nCódigo: %d", cadastro[linha].codigo);
			printf("\nTítulo: %s", cadastro[linha].titulo);
			printf("\nDescrição: %s", cadastro[linha].descricao);
			printf("\nAno: %d", cadastro[linha].ano);
			printf("\nStatus: %d", cadastro[linha].status);
			printf("\nGerente Reponsável: %s", cadastro[linha].gerenteResp);
			printf("\nCliente: %s", cadastro[linha].cliente);
			printf("\nOrçamento: %.2f", cadastro[linha].orcamento);
			printf("\nPrazo final: %s", cadastro[linha].dataPrazoFinal);
			printf("\n---------------------------------------------------------------------------------\n");
			linha++;	
		}
	}
	if(encontrou == 0){
		printf("\n\n Sem Projeto cadastrado.\n");
	}
	system("pause");
}	

int main(){
	setlocale(LC_ALL, "Portuguese");
	dadosProjeto cadastro[MAX];
	int selecionar;
	
	do{
		system("cls");
		logoProg();
		menu();
		scanf("%d", &selecionar);
		
		switch(selecionar){
			case 1:
				cadastrarProjeto(cadastro);
				break;
			case 2:
				buscarCodigo(cadastro);
				break;
			case 3:
				listarProjetosPorStatus(cadastro, 1);
				break;
			case 4:
				listarProjetosPorStatus(cadastro, 2);
				break;
			case 5:
				listarProjetosPorStatus(cadastro, 3);
				break; 
			case 6:
				listaTodosProjetos(cadastro);
				break;
			case 7:
				printf("\n Saindo do programa.\n");
				system("Pause");
				break;
			default:
				printf("\nOpção Inválida.\n");
				system("Pause");
				break;
		}
	}while(selecionar!=7);
	return 0;
}
		
		


