#
# Calculate sum from A to B.
#
# Authors: 
#	Victor Ostolaza & Macarena Oyague
#
#

.text
main:
	#
	# bool $t3, i $t4, acum $ t5
	#
	addi $t0, $t0, 2 # A = 2
	addi $t1, $t1, 5 # B = 5
loop:
	add $t5, $t0, $t4 # X = A + i
	slt $t3, $t1, $t5 # B < X ? 1 : 0
	bgtz $t3, exit    # bool > 0 ? exit : pass
	add $t2, $t2, $t5 # sum = sum + X
	addi $t4, $t4, 1  # i += 1
	j loop
exit:
	
	# Put your sum S into register $t2
end:	
	j	end	# Infinite loop at the end of the program. 

