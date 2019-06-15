Ceci est un projet de conception des systèmes électronique d'un vélo électrique.

L'ensemble du projet est open source et open hardware.

Cahier des charges :

	- un circuit BMS communicant
	- un contrôleur (hôte) moteur/générateur électrique
	- un circuit info cycliste (tableau de bord(TDB))
	
Le circuit BMS communicant : 
	- jusqu'a 50v (au-delà tension dangereuse)
	- monitoring de la tension de chaque cellule
	- monitoring temperature du pack batterie
	- monitoring du courant entrant/sortant du pack
	- communication SPI/I2C/UART avec le contrôleur moteur
	- protection clasique BMS (short-circuit, overcharge, undercharge, overcurrent, overheating)
	- chargeur intégré dans le pack (19v/12v/5v)
	- possibilité de couper le circuit pour une conso minimale
	- circuit d'équilibrage des cellules
	
Le contrôleur :
	- communication avec les esclave (TDB, BMS)
	- contrôle de 2 moteur brushless triphasé (moteur ou générateur) (avec option capteur hall)
	- communication via port usb ou port serie pour parametrage via logiciel pc
	- frein régénératif progressif et paramétrable en fonction de la batterie
	- recharge en pédalant (compensation des conso éclairage, voir très legère recharge batterie)
	- analyse du pédalage grace au capteur PAS
	- calcul vitesse
	- calcul d'infos utiles (courant, capacité restante, puissance cycliste vs puissance elec, etc...)
	- module bluetooth pour communiquer avec un smartphone
	- mode antivol (mise en court-circuit des bobines moteur)
	- retour sonore type esc aeromodélisme
	- gestion de l'éclairage partie AR
	
Le TDB (optionnel):
	- affichage des infos cycliste classique (vitesse, distance, rpm etc)
	- récupération et affichage d'infos via smartphone tel que rythme cardiaque
	- gestion de l'éclairage AV
	- mesure de la position de l'accélérateur
	- lecture position levier de frein
	- Affichage des données énergétique
	- lecture position comodo d'éclairage
	- antivol numérique par code pin ou séquence comodo
	- communication avec le contrôleur
	
	
Microcontroleur BMS : PIC16(L)F19175/76
Microcontrôleur controleur : dsPIC33CK256MP203 (version mémoire plus faible sera revu si la mémoire est surdimensionnée)
Microcontrôleur TDB : arduino pro mini
	
Mosfet des esc : IRFR3607TRPBF ou igbt FGH60N60 (dispo aliexpress)
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	