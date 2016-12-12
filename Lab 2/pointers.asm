
        # pointers.asm
# By David Broman, 2015-09-14
# This file is in the public domain


.macro	PUSH (%reg)
	addi	$sp,$sp,-4
	sw	%reg,0($sp)
.end_macro

.macro	POP (%reg)
	lw	%reg,0($sp)
	addi	$sp,$sp,4
.end_macro

.data


text1: 	  .asciiz "This is a string."
text2:	  .asciiz "Yet another thing."

.align 2
list1: 	.space 80
list2: 	.space 80
count:	.word  0

.text
main:
	jal	work
stop:	j	stop

# function work()
work:
	PUSH	($ra)
	la 	$a0,text1          #loads address to text1 in $a0
	la	$a1,list1          #loads address to list1 in $a1
	la	$a2,count          #loads address to count in $a2
	jal	copycodes          #stores the address of copycodes in $ra

	la 	$a0,text2          #loads address to text2 in $a0
	la	$a1,list2          #loads address to list2 in $a1
	la	$a2,count          #loads address to count in $a2
	jal	copycodes          #stores the address of copycodes in $ra
	POP	($ra)


# function copycodes()
copycodes:
loop:
	lb	$t0,0($a0)        #sign-extend value in $a0(text1) with 0, and store in $t0.
	beq	$t0,$0,done       #compare $0 and $t0, if equal branch to done.
	sw	$t0,0($a1)        #store word in register $t0 into $a1

	addi	$a0,$a0,1       # $a0 = $a0 + 1
	addi	$a1,$a1,4       # $a1 = $a1 + 4

	lw	$t1,0($a2)        # load the value which $a2 points to into $t1
	addi	$t1,$t1,1       # increase the value by one
	sw	$t1,0($a2)        # save the new value of count to the same address
	j	loop
done:
	jr	$ra               #jump to address of $ra
