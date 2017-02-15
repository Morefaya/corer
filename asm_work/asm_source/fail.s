.name "corewar"
.comment ""

l2:



		sti 	   r-1, %:live, %-9223372036854775807
#						%9223372036854775807
		and r1, %0, r1

live:		live %1
		zjmp %:live
