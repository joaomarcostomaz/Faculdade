.data
   vetor: .word 1 1 1 1
   tamanho:    .word 4
   count_par:  .word 0
   count_impar: .word 0
.text
   jal x1, contador
   addi x14, x0, 0 # utilizado para correção
   beq x14, x10, FIM # Verifica # de pares
   beq x14, x11, FIM # Verifica # de ímpares
   
   contador: 
    # Inicializa os contadores e o indice
    li x10, 0
    li x11, 0
    li t2, 0
	la t0,vetor
    li t1,4
   loop:
      # Verifique se o índice i é menor que o tamanho do vetor
      beq t1, t2, loop_end

      lw t3, 0(t0)

      # Verifique se o valor em t3 é par ou ímpar
      # Se for par, incremente o contador de pares
      # Se for ímpar, incremente o contador de ímpares
      addi x31,x0,2
      rem t4, t3, x31  # t4 = t3 % 2
      beqz t4, par
      addi x11, x11, 1
      addi t2, t2, 1

      addi t0, t0, 4  
      beq x0, x0, loop

   par:
      addi x10, x10, 1
      # Atualize o índice i
      addi t2, t2, 1

      addi t0, t0, 4  
      beq x0, x0, loop
   
   loop_end:
      # Retorne para o endereço de retorno
      jalr x0, 0(x1)
FIM: addi x0, x0, 1