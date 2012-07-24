#include p16f722.inc

	__CONFIG _CONFIG1, _DEBUG_OFF & _PLL_EN & _BOR_OFF & _CP_OFF & _MCLR_EN & _PWRT_DIS & _WDT_OFF & _INTOSC
	__CONFIG _CONFIG2, _VCAP_RA6

#define BUTTON PORTB, 0

	org 0x00

; wait constant, closer to 0xff is faster
waitcst equ 0xff - (0xff / 4)

; general purpose memory starts at 0x20
imgstlow   equ 0x70
imgsthigh  equ 0x71
imgendlow  equ 0x72
imgendhigh equ 0x73
imgid      equ 0x74
btndown equ 0x75
vwait1  equ 0x76
vwait2  equ 0x77

	goto start
	goto start
	goto start
	goto start
	goto start

start:
	; disable analogs
	banksel ANSELA
	clrf ANSELA
	clrf ANSELB

	; enable digital outputs, except for the button
	banksel TRISA
	movlw 0x01
	clrf TRISA
	movwf TRISB
	clrf TRISC

	; default to all off
	banksel PORTA
	clrf PORTA
	clrf PORTB
	clrf PORTC

	; start at the first column of the first image
	clrf imgid

	banksel PMADRL
	movlw img0start & 0xff
	movwf PMADRL
	movwf imgstlow
	movlw img0start >> 8
	movwf PMADRH
	movwf imgsthigh

	movlw img0end & 0xff
	movwf imgendlow
	movlw img0end >> 8
	movwf imgendhigh

	clrf btndown

loop:

	; sleep appropriately
	movlw waitcst
	movwf vwait1
wait1:
	clrf vwait2
wait2:
	incfsz vwait2, F
	goto wait2
	incfsz vwait1, F
	goto wait1

	; change PORTS A, B, and C
	banksel PMCON1
	bsf PMCON1, RD
	nop
	nop
	banksel PMDATL
	movf PMDATL, W
	banksel PORTC
	movwf PORTC
	banksel PMDATL
	movf PMDATH, W
	banksel PORTA
	movwf PORTA

	banksel PMDATL
	incfsz PMADRL, F
	goto noinchigh1
	incf PMADRH, F
noinchigh1:
	banksel PMCON1
	bsf PMCON1, RD
	nop
	nop
	banksel PMDATL
	movf PMDATL, W
	banksel PORTB
	movwf PORTB

	; increment
	banksel PMDATL
	incfsz PMADRL, F
	goto noinchigh2
	incf PMADRH, F
noinchigh2:
	
	; see if we're at the end of the image
	movf imgendhigh, W
	subwf PMDATH, W
	btfss STATUS, Z
	goto aftereoi

	movf imgendlow, W
	subwf PMDATL, W
	btfss STATUS, Z
	goto aftereoi

	; we are, so we need to reload
	movf imgstlow, W
	movwf PMDATL
	movf imgsthigh, W
	movwf PMDATH

aftereoi:
	; see if we need to change images	

	banksel PORTA
	btfss BUTTON
	goto nobutton

	btfsc btndown, 0
	goto loop

	bsf btndown, 0

	; time to change images!
	incf imgid, F
	movlw imgcnt
	subwf imgid, W
	btfsc STATUS, Z
	clrf imgid

	; load image size
	banksel PMADRH
	movlw images & 0xff
	movwf PMADRL
	movlw images >> 8
	movwf PMADRH
	
	movf imgid, W
	addwf PMADRL, F
	btfsc STATUS, C
	incf PMADRH, F

	banksel PMCON1
	bsf PMCON1, RD
	nop
	nop
	banksel PMDATL
	movf PMDATL, W
	movwf imgstlow
	movf PMDATH, W
	movwf imgsthigh

	incfsz PMADRL, F
	goto noinchigh3
	incf PMADRH, F
noinchigh3:
	banksel PMCON1
	bsf PMCON1, RD
	nop
	nop
	banksel PMDATL
	movf PMDATL, W
	movwf imgendlow
	movf PMDATH, W
	movwf imgendhigh

	goto loop

nobutton:
	clrf btndown
	goto loop

#include "images.inc"

	END
