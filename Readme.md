
			ENCODER - ARDUINO

	AÑADE VALORES CON EL DESPLAZAMIENTO DEL ENCODER
 	
			 CON BOTÓN RESET
 

 Manda por Serial el valor recogido por el encoder, empezando en el punto 0.
 Al presionar el botón se resetea Arduino, colocando el valor de nuevo en 0.
 (Arduino tarda de 2 a 4 segundo en reiniciar)



		CONEXIÓN ENCODER

	Encoder   Arduino       Arduino    Botón

	   |         |             |         |

	  Red ------ 5v           Gnd ------ \

	 Black ---- Gnd          Reset ----- |

	 Green ----- 2

	 White ----- 3


