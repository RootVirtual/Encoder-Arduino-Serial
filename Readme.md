
			ENCODER - ARDUINO

	A�ADE VALORES CON EL DESPLAZAMIENTO DEL ENCODER
 	
			 CON BOT�N RESET
 

 Manda por Serial el valor recogido por el encoder, empezando en el punto 0.
 Al presionar el bot�n se resetea Arduino, colocando el valor de nuevo en 0.
 (Arduino tarda de 2 a 4 segundo en reiniciar)



		CONEXI�N ENCODER

	Encoder   Arduino       Arduino    Bot�n

	   |         |             |         |

	  Red ------ 5v           Gnd ------ \

	 Black ---- Gnd          Reset ----- |

	 Green ----- 2

	 White ----- 3


