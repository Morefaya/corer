# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.s                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 15:56:18 by rabougue          #+#    #+#              #
#    Updated: 2016/12/19 17:52:45 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "corewar"
.comment ""

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:		live %1
		zjmp %:live
