#
# Sum of Absolute Differences Algorithm
#
# Authors: 
#	Victor Ostolaza & Macarena Oyague
#
#

.text


main:


# Initializing data in memory... 
# Store in $s0 the address of the first element in memory
	# lui sets the upper 16 bits of thte specified register
	# ori the lower ones
	# (to be precise, lui also sets the lower 16 bits to 0, ori ORs it with the given immediate)
	     
	     # Inicializamos left_image
	     lui     $s0, 0x0000 # Address of first element in the vector
	     ori     $s0, 0x0000
	     addi   $t0, $0, 5	# left_image[0]	
	     sw      $t0, 0($s0)
	     addi   $t0, $0, 16	# left_image[1]		
	     sw      $t0, 4($s0)
	     addi   $t0, $0, 7	# left_image[2]	
	     sw      $t0, 8($s0)
	     addi   $t0, $0, 1	# left_image[3]		
	     sw      $t0, 12($s0)
	     addi   $t0, $0, 1	# left_image[4]	
	     sw      $t0, 16($s0)
	     addi   $t0, $0, 13	# left_image[5]		
	     sw      $t0, 20($s0)
	     addi   $t0, $0, 2	# left_image[6]	
	     sw      $t0, 24($s0)
	     addi   $t0, $0, 8  # left_image[7]		
	     sw      $t0, 28($s0)
	     addi   $t0, $0, 10	# left_image[8]		
	     sw      $t0, 32($s0)

# TODO1: initilize the rest of the memory.
	     # .....
	     # Inicializamos right_image
	     lw     $s1, 36($s0) # Address of first element in the vector
	     addi   $t0, $0, 4        # right_image[0]
         sw      $t0, 36($s0)
         addi   $t0, $0, 15        # right_image[1]
         sw      $t0, 40($s0)
         addi   $t0, $0, 8        # rigt_image[2]
            sw         $t0, 44($s0)
         addi   $t0, $0, 0        # right_image[3]
            sw         $t0, 48($s0)
         addi   $t0, $0, 2        # right_image[4]
            sw         $t0, 52($s0)
         addi   $t0, $0, 12        # right_image[5]
            sw         $t0, 56($s0)
         addi   $t0, $0, 3        # right_image[6]
            sw         $t0, 60($s0)
         addi   $t0, $0, 7        # right_image[7]
            sw         $t0, 64($s0)
         addi   $t0, $0, 11        # right_image[8]
            sw         $t0, 68($s0)
            

	# TODO4: Loop over the elements of left_image and right_image
	
	addi $s2, $0, 0 # $s2 = i = 0
	addi $s3, $0, 9	# $s3 = image_size = 9
	
loop:
	# Check if we have traversed all the elements 
	# of the loop. If so, jump to end_loop:
	beq $s2, $s3, end_loop
	
	# Load left_image{i} and put the value in the corresponding register
	# before doing the function call
	sll $t0, $s2, 2
	add $t0, $s0, $t0
    lw $a0, 0($t0)


	# Load right_image{i} and put the value in the corresponding register
	lui $s4, 0x0000 
    ori $s4, 0x0024
    
    sll $t0, $s2, 2
    add $t0, $s4, $t0 
    lw $a1, 0($t0)
	
	jal abs_diff
	
	#Store the returned value in sad_array[i]
	lui $s5, 0x0000 
    ori $s5, 0x0048
	
	sll $t0, $s2, 2
	addu $t0, $s5, $t0
	sw $v0, 0($t0)	
	# Increment variable i and repeat loop:
	addi $s2, $s2, 1
	j loop
		
end_loop:

	#TODO5: Call recursive_sum and store the result in $t2
	#Calculate the base address of sad_array (first argument
	#of the function call)and store in the corresponding register   
	
	addi $a0, $s5, 0
	
	# Prepare the second argument of the function call: the size of the array
	
	addi $a1, $s3, 0 
	
	jal recursive_sum

	#Store the returned value in $t2
	
	addi $t2, $v0, 0
	

end:	
	j	end	# Infinite loop at the end of the program. 




# TODO2: Implement the abs_diff routine here, or use the one provided
# FUNCION PROPIA
abs_diff:
	sub $t1, $a0, $a1
	abs $v0, $t1
	jr $ra

# TODO3: Implement the recursive_sum routine here, or use the one provided
recursive_sum:    
	    addi $sp, $sp, -8       # Adjust sp
        addi $t0, $a1, -1       # Compute size - 1
        sw   $t0, 0($sp)        # Save size - 1 to stack
        sw   $ra, 4($sp)        # Save return address
        bne  $a1, $zero, else   # size == 0 ?
        addi  $v0, $0, 0        # If size == 0, set return value to 0
        addi $sp, $sp, 8        # Adjust sp
        jr $ra                  # Return

else:     
	    add  $a1, $t0, $0		#update the second argument
        jal   recursive_sum 
        lw    $t0, 0($sp)       # Restore size - 1 from stack
        sll  $t1, $t0, 2        # Multiply size by 4
        add   $t1, $t1, $a0     # Compute & arr[ size - 1 ]
        lw    $t2, 0($t1)       # t2 = arr[ size - 1 ]
        add   $v0, $v0, $t2     # retval = $v0 + arr[size - 1]
        lw    $ra, 4($sp)       # restore return address from stack         
        addi $sp, $sp, 8        # Adjust sp
        jr $ra                  # Return
