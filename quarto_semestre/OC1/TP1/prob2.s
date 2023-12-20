  .data
        vetor:  .word 200, 190, 340, 100 # exemplo
        tamanho:    .word 4
        limite:     .word 200
        count:      .word 0
   .text
        jal ra, main 
        addi a4, x0, 3
        beq a4, t0, FIM # Verifica a quantidade de salários acima do limiar.
        main:
        addi x2, x2,-4
        sw ra, 0(x2)
        la a0, vetor      # Endereço do vetor "salario"
        lw a1, tamanho       # Tamanho do vetor
        lw a2, limite      # Valor limite
        lw t3, count      # Endereço do contador "count"
        
        jal ra, aplica_reajuste
        lw ra, 0(x2)
        addi x2,x2,4
        jalr x0,0(ra)

        aplica_reajuste:

        # Inicialize tudo como 0
        li t4, 0
        li x9, 0
        loop:

        bge x9, a1, loop_end
        lw t6, 0(a0)
        srli x30, t6, 1
        add t6, t6, x30

        # Armazene o novo salário de volta no vetor "salario[x9]"
        sw t6, 0(a0)

        # Compare o novo salário com o limite
        bge t6, a2, increment_count

        # Atualize o índice "i" e o endereço do vetor "salario" para a próxima iteração
        addi x9, x9, 1
        addi a0, a0, 4  
        beq x0,x0,loop

        increment_count:
        addi t4, t4, 1

        # Atualize o índice "i" e o endereço do vetor "salario" para a próxima iteração
        addi x9, x9, 1
        addi a0, a0, 4  
        beq x0,x0,loop

        loop_end:
        # Armazene o valor final do contador "count" em t3 (endereço passado por referência)
        add t0,x0,t4
        jr ra

        FIM: addi x0, x0, 1