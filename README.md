# Pequeno resumo do projeto


• Para cada Aluno
- Nome completo
- CPF
- Idade (inteira em anos)
- Sexo
- Data de ingresso na escola (dia, mês e ano coletados do computador - sem digitação)
- Matrícula : valor inteiro e único a ser fornecido pelo usuário

• Para cada Curso
- Nome do curso
- Código do curso (inteiro e único gerado pelo computador e maior que 1000 )
- Carga horária do curso (inteiro)
- Valor da mensalidade (real em R$)

• Para a Matrícula escolar
- Identificação única do aluno
- Identificação única do curso onde o aluno está matriculado
- Situação do aluno no curso (cursando, concluído)
- Situação financeira do aluno no curso (regular, pendente, pago)
- Mês e ano da matrícula, a ser fornecida pelo usuário. 

Obs.: Um aluno só pode estar cursando um curso na escola, no entanto pode ter cursado mais de um
curso em períodos anteriores.

####################  Funcionalidades ####################
- Adiciona alunos e cursos em um arquivo binario separado, nao adiciona alunos ou cursos ja existentes
- Cria uma matricula de um aluno em um curso, o aluno nao pode ser matriculado 2 vezes no mesmo curso.
- Só exclui aluno se não estiver cursando algum curso, ou seja apenas os que tiverem terminado o curso.

####################  Relatorios  ####################
• (Relatorio 1) - Consulta simples sobre todos os arquivos existentes através da sua chave única ou
listar todos os dados já cadastrados;

• (Relatorio 2) - Relacionar todos os alunos de um curso específico fornecido pelo usuário. O usuário
poderá ainda informar se deseja obter este relatório somente para os alunos que estão
cursando ou os que já o concluíram ou ambas as situações. Este relatório deverá mostrar o
CPF, nome, situação do aluno no curso por extenso, além do próprio código do curso
consultado.

• (Relatorio 3) - Consultar todos os cursos existentes nesta escola por qualquer parte do nome do curso
fornecido pelo usuário ou por seu código (chave), onde todos os dados de cadastro do curso
deverão ser mostrado de maneira tabelar, com somente uma linha de cabeçalho. Esta
consulta só poderá ser realizada usando recursos de alocação dinâmica 
**OBS: Pesquisa dos dados dos Cursos cadastrados por seu nome. Esta pesquisa ocorrerá
por qualquer parte do nome do curso que seja digitado no seu programa.

• (Relatorio 4) - Apresentar todos os alunos que ingressaram na escola em um período de data (de...
até...) completa (dia/mês/ano) fornecido pelo usuário, onde será mostrado o nome, CPF,
idade, sexo por extenso e a data de ingresso na escola, em ordem alfabética.

• (Relatorio 5) - Pesquisar todos os estudantes que estão com a situação financeira indicada pelo
usuário, podendo está ser: regular (está com o pagamento das mensalidades em dia),
pendente (está com mensalidade(s) atrasada(s), pago (está com o curso completamente pago
até o seu final);

• (Relatorio 6) - Pesquisar os alunos que concluíram um curso fornecido pelo usuário em um
determinado ano. No caso de existirem vários alunos que satisfaçam a pesquisa, deverá ser
mostrada uma tabela ordenada, alfabeticamente, pelo nome dos alunos. Devem ser
apresentados os dados cadastrais dos alunos e mês e ano que ele se matriculou no curso. 

