;------------------------------------------------------------------------------
;
; Title:			ds30 Loader for PIC24 and dsPIC
;
; File description:	user init and exit code
;
; Copyright: 		Copyright © 2011, Mikael Gustafsson
;                                                                             
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;    This file is part of ds30 Loader.
;
;    ds30 Loader is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation.
;
;    ds30 Loader is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with ds30 Loader. If not, see <http://www.gnu.org/licenses/>.
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; UserInit()
; Description: this is executed immediately on start-up before the boot loader code
;------------------------------------------------------------------------------
 		.macro UserInit
			
			;----------------------------------------------------------------------
			; Make uart pins digital
			;----------------------------------------------------------------------
			.ifdecl ADPCFGL				
				;.error "Do you need to configure communication pins to be digital? If not, remove this line"
			.else
				.ifdecl AD1PCFGL
					;.error "Do you need to configure communication pins to be digital? If not, remove this line"
				.endif
			.endif 
			
			
			;----------------------------------------------------------------------
			; UART/CAN pps config
			;----------------------------------------------------------------------
			.ifdef HAS_PPS
				;.error "PPS is not configured. More information in the firmware manual."			;xxx remove this line when PPS is configured
			
				; ** IMPORTANT **
				;
				; THIS CODE IS JUST A TEMPLATE AND WILL MOST LIKELY NOT WORK FOR YOU, 
				; READ THE DATASHEET AND ALTER LINES MARKED WITH XXX
				;
				; ** IMPORTANT **
	
				; Receive, map pin (10 = 1010) to uart
				bclr	RPINR19, #U2RXR0		;xxx
				bset	RPINR19, #U2RXR1		;xxx
				bclr	RPINR19, #U2RXR2		;xxx
				bset	RPINR19, #U2RXR3		;xxx
				bclr	RPINR19, #U2RXR4		;xxx
				bclr	RPINR19, #U2RXR5		;xxx
						
				; Transmit, map uart to pin
				bset	RPOR8, #RP17R0			;xxx
				bclr	RPOR8, #RP17R1			;xxx
				bset	RPOR8, #RP17R2			;xxx
				bclr	RPOR8, #RP17R3			;xxx
				bclr	RPOR8, #RP17R4			;xxx
				bclr	RPOR8, #RP17R5			;xxx
			.endif	
		
		; End of macro
		.endm
		
		
;------------------------------------------------------------------------------
; UserExit()
; Description: this is executed right before the user application is loadaed
;------------------------------------------------------------------------------
 		.macro UserExit
 		
		
		; End of macro
		.endm
		

;------------------------------------------------------------------------------
; End of file
;------------------------------------------------------------------------------	
