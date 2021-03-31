# Matrix Lang

### Passos para fazer a análise léxica

`$ flex analisador_lexico.flex`<br/>
`$ gcc lex.yy.c -lfl`<br/>
`$ ./a.out program.mx`<br/>

### Passos para fazer a análise sintática

`$ flex analisador_lexico.flex`<br/>
`$ gcc lex.yy.c -lfl`<br/>
`$ ./a.out program.mx`<br/>

Onde program.mx é o código-fonte do programa que será analisado.

### Exemplos de código
mergesort.mx<br/>
quicksort.mx<br/>
matrix_multiplication.mx<br/>
