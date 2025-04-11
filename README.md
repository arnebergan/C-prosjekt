README fil:

Hva programmet gjør:
Formålet med programmet er å lage et enkelt spill som handler om å løse en labyrint på kortest mulig tid. 
Labyrinten er visualisert ved hjelp av animationwindow og det er en blå sirkel som beveger seg i henhold til brukerens input fra piltastene.
Før labyrinten kommer opp blir brukeren bedt om å skrive inn et brukernavnt som blir skrevet inn i en fil når labyrinten er fullført. 

Ressurser som er brukt:
Det er i hovedsak brukt tidligere øvinger i emnet og nettbaserte kilder som stackOverflow, cppreference og lignende.  
KI er svært lite brukt og ingen deler av koden er direkte skrevet av KI. 
Inkluderte bilioteker er som følger: "std_lib_facilities.h", "AnimationWindow.h", <chrono>, "widgets/Button.h", <vector> og <random>. 

Logikk bak implementasjon og viktigste klasser/funksjoner:
Programmet er delt inn i 5 filer i tilegg til main som har følgende funksjonalitet. 

Maze: Inneholder klassen Maze. Her er all funksjonalitet som har med selve labyrinten å gjøre. 
Lage den, funksjoner som henter hvor stor den er, om x og y koordinat er på en hvit eller svart rute osv. 

Character: Inneholder klassen Charcter. Det er her funksjonaliteten til sirkelen som skal komme til mål ligger. 
Filen inneholder altså kun funksjonalitet til sirkelen og har ingenting med det visuelle å gjøre. 

Map: Inneholder klassen Map. Her er alt med animationwindow skjer.
Den har funksjoner som tegner labyrinten den blå sirkelen, flytter grafisk den blå sirkelen og quitBtn. 

Game_functions: Inneholder Stopwatch og funksjonen move. Stopwatch er for å ta tiden og er hentet fra en tidligere øving. 
Mens move funksjonen inneholder inputs fra bruker og hva som skjer ved når tasten blir trykket inn. 

Fil: Inneholder klassen Fil. Her er alt som har med skriving til fil å gjøre. Også i hovedsak hentet fra tidligere øving. 

Main: Her blir først objekter laget og animationwindow blir konstruert. Deretter kommer while løkke som går kontinuerlig til spillet er ferdig.
Der brukes next_frame. Labyrinten, sirkelen, bevegelsen og sjekken om man vinner skjer altså i en kontinuerlig loop frem til man er ferdig. 

