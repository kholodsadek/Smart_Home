/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	LIB     	                                         */
/* SWC	            : 	BIT_MATH_H                                           */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_
#define SET_BIT(VAR,BIT) (VAR = (VAR | (1<<BIT)))
#define CLR_BIT(VAR,BIT) (VAR = VAR &~(1<<BIT))
#define GET_BIT(VAR,BIT) ((VAR >> BIT) & (1))
#define TOGGLE_BIT(VAR,BIT) (VAR = (VAR ^ (1<<BIT)))

#endif // _BIT_MATH_H_
