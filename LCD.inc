;Write to the LCD Control register
WrLCC	movlw	0x04
		movwf	PORTE
		movf	Output,w
		movwf	PORTB
		movlw	0x00
		movwf	PORTE
		Call	Delay_50us
		movlw	0x04
		movwf	PORTE
		
		return


;Write to the LCD Data register
WrLCD	movlw	0x05
		movwf	PORTE
		movf	Output,w
		movwf	PORTB
		movlw	0x01
		movwf	PORTE
		Call	Delay_50us	
		movlw	0x05
		movwf	PORTE
		return




;Set up the LCD (send the init string)
;------------------------------
SetLCD	
		call	Delay_100ms	;Wait for LCD to init
		movlw	0x38		;2-line, 5x7, 8-bit mode
		movwf	Output
		call	WrLCC
		movlw	0x0C		;(was 0x0C. Disp on/Cursor on/blink)
		movwf	Output
		call	WrLCC
		movlw	0x01		;Clear the display
		movwf	Output
		call	WrLCC
		movlw	0x06		;Set shift-right behavior
		movwf	Output
		call	WrLCC
		movlw	0x02		;Return home
		movwf	Output
		call	WrLCC
		call	Delay_2ms
		return
		goto	$		;GUARD


Cls
		movlw	0x01		;Clear the display
		movwf	Output
		call	WrLCC
		call	Delay_2ms	;Per spec sheet
		return

QuickCls 	;Like Cls, but with no delay. Use only when
			;certain 2ms or more will pass before the LCD
			;is accessed again.
		movlw	0x01		;Clear the display
		movwf	Output
		call	WrLCC
		return


LCDGoto	;GOTO location in variable Output:
		;0x00 to 0x27 in first line (0x00 - 0x0F visible),
		;0x40 to 0x67 in second line (0x40 - 0x4F visible).
		bsf		Output, 7	;Set high bit of Output
		goto	WrLCC		;WrLCC will handle the return
							;(this saves a stack level)

