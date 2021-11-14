#include <stdio.h>
    /*------------------------------
Função: Dia da Semana
Descrição: Descobre o Dia da Semana da data especificada a partir do ano de 2000
Entrada: Dia, Mês e Ano
Saída: Dia da Semana (0 = sabado, 1 = domingo, 2 = segunda, 3 = terça, 4 = quarta, 5 = quinta, 6 = sexta) 
--------------------------------------------*/
 int DiaSemana (int D, int M, int A)
 {
	unsigned int k;
	unsigned int diaSem;
	unsigned int resposta;
	if (M==1) //Para os meses de Janeiro e Feveiro, a conta deve levar em conta os meses "13 e 14" do ano anterior. Fonte: https://www.youtube.com/watch?v=u7NAy_kDZ3A&app=desktop
	{
		M = M + 12;
		A--;
	}
	if (M==2)
	{
		M = M + 12;
		A--;
	}
	k=D+2*M+(3*(M+1)/5)+A+(A/4)-(A/100)+(A/400)+2; 
	diaSem= k%7;
	resposta = diaSem;
	return(resposta);
}
	
	/*----------------------------------------
Função: Preço Total do PetShop
Descrição: Calcula o preço total por Petshop no dia da semana específico
Entrada: Dia da semana, Código do pet shop, quantidade de cães pequenos e quantidade de cães grandes
Saída: Preço total do Petshop
-------------------------------------------*/
int precototal (int DiaDaSemana, int petshop, int QuantCaesPeqns, int QuantCaesGrnds) 
//petshop = código do petshop (1 = Meu Canino Feliz, 2 = Vai Rex, 3 = ChowChawgas)
{
	int ValorCaoPeq; //valor cão pequeno
	int ValorCaoGrnd; //valor cão grande
	DiaDaSemana = ((DiaDaSemana==0)|(DiaDaSemana==1)) ? 0 : 1; //descobre se o dia da semana é fim de semana. Se sim, atribui 0 à dia da semana (0 = fim de semana). Se não, atribui 1 (1 = dia útil - segunda a sexta)
	ValorCaoPeq = ((DiaDaSemana==0)&(petshop==1)) ? 20*1.2 : ValorCaoPeq; //define os valores baseados em petshop e dia da semana
	ValorCaoPeq = (((DiaDaSemana==0)&(petshop==2))|((DiaDaSemana==1)&(petshop==1))) ? 20 : ValorCaoPeq;
	ValorCaoPeq = ((DiaDaSemana==1)&(petshop==2)) ? 15 : ValorCaoPeq;
	ValorCaoPeq = (petshop==3) ? 30 : ValorCaoPeq;
	ValorCaoGrnd = ((DiaDaSemana==0)&(petshop==1)) ? 40*1.2 : ValorCaoGrnd;
	ValorCaoGrnd = ((DiaDaSemana==0)&(petshop==2)) ? 55 : ValorCaoGrnd;
	ValorCaoGrnd = ((DiaDaSemana==1)&(petshop==1)) ? 40 : ValorCaoGrnd;
	ValorCaoGrnd = ((DiaDaSemana==1)&(petshop==2)) ? 50 : ValorCaoGrnd;
	ValorCaoGrnd = (petshop==3) ? 45 : ValorCaoGrnd;
	int resposta = ValorCaoPeq*QuantCaesPeqns + ValorCaoGrnd*QuantCaesGrnds;
	return resposta;
}
	/*----------------------------------------
Função: Melhor Preço
Descrição: Descobre qual Petshop está com o melhor preço e em caso de empate envia para o petshop mais proximo
Entrada: Preço dos 3 petshops
Saída: Petshop com o melhor custo beneficio
-------------------------------------------*/
int melhorpreco (int petshop1, int petshop2, int petshop3)
{
	if ((petshop1<petshop2)&(petshop1<petshop3)) //Se o preço no primeiro petshop for mais barato que nos outros 2, retorna o primeiro
	{
		return 1;
	}
	if (((petshop2<petshop3)&(petshop2<petshop1))|((petshop2<petshop3)&(petshop2=petshop1))) //Se o preço no segundo petshop for mais barato, retorna o segundo. Também retorna se o preço no segundo for igual ao preço no primeiro, visto que o segundo petshop é mais perto.
	{
		return 2;
	}
	else //Nos demais casos, o terceiro pet shop é mais vantajoso
	{
		return 3;
	}
	
}

void main() 
{
	int QuantCaesPeqns; //quantidade de cães pequenos
	int QuantCaesGrnds; //quantidade de cães grandes
	int dia;
	int mes;
	int ano;
	char barra; //absorve as barras do formato XX/XX/XXXX
	printf("PROCESSO SELETIVO DTI DIGITAL - TESTE PRATICO\n\n");
	printf("Candidato: Carlos Henrique de Oliveira e Silva\n\n");
	printf("Descubra qual petshop eh a melhor opcao para voce, tendo em vista:\n\n");
	printf("- Data\n");
	printf("- Quantidade de caes pequenos\n");
	printf("- Quantidade de caes grandes\n\n");
	printf("Insira a data no formato dd/mm/aaaa: ");
	scanf("%d%c%d%c%d", &dia,&barra,&mes,&barra,&ano);
	printf("\nInsira a quantidade de caes pequenos: ");
	scanf("%d", &QuantCaesPeqns);
	printf("\nInsira a quantidade de caes grandes: ");
	scanf("%d", &QuantCaesGrnds);
	printf("----------------------------------------\n");
	int DiaDaSemana = DiaSemana(dia, mes, ano); //descobre o dia da semana
	int petshop1 = precototal (DiaDaSemana, 1, QuantCaesPeqns, QuantCaesGrnds); //calcula preço no petshop1
	int petshop2 = precototal (DiaDaSemana, 2, QuantCaesPeqns, QuantCaesGrnds); //calcula preço no petshop2
	int petshop3 = precototal (DiaDaSemana, 3, QuantCaesPeqns, QuantCaesGrnds); //calcula preço no petshop3
	int precofinal; //recebe o melhor preço final
	int petshop = melhorpreco (petshop1, petshop2, petshop3); //descobre o petshop de melhor custo beneficio
	printf("\n\nO petshop com melhor custo/beneficio nesse dia eh o ");
	switch(petshop)
	{
		case 1:
		printf("Petshop Meu Canino Feliz!\n");
		precofinal = petshop1;
		break;
		case 2:
		printf("Petshop Vai Rex!\n");
		precofinal = petshop2;
		break;
		case 3:
		printf("Petshop ChowChawgas!\n");
		precofinal = petshop3;
		break;
		default:
		printf("ERRO!");
		precofinal = 0;
		break;
	}
	printf("\nO valor total dos banhos serah de R$%i,00\n\n", precofinal);
}
