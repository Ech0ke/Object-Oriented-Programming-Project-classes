# V1.2
Programoje įgyvendinta rule-of-three: yra destruktorius, kopojavimo konstruktorius, priskyrimo operatorius.
Programa dirba su vector konteineriu ir turi studento klasę su privačiais kintamaisiais ir viešu interfeisu (komandomis).
Programos paleidžiamąjį failą "main.exe" galima sukurti atsidarius konsolę visų failų aplanke ir parašyti komandą make vector.


Programos sparta

![class](https://user-images.githubusercontent.com/99315244/166628854-2b31c3f3-274b-446f-91ea-c8fe4d20026c.png)


*Header failai:*  
  **file.h**  duomenų nuskaitymo iš failo funkcijos antraštė. 
  **libraries_and_std.h** - bibliotekos ir std naudojamų komandų aprašas.  
  **manual.h** - ranka įvedamų duomenų funkcijos prototipas.  
  **studentas.h** - studento klasė ir kitos funkcijų antraštės.  
*Source failai:*  
**main.cpp** - pagrindinė funkcija iš kurios kreipiamasi į visas kitas funkcijas pagal naudotojo poreikį. Galima pasirinkti duomenis nuskaityti iš failo arba vesti ranka.  
**create_file.cpp** - studentų failo pagal vartotojo nustatymus generavimo funkcija.  
**file.cpp** - duomenų nuskaitymo iš failo funkcija. Patikrina, ar egzistuoja failas, iš kurio nuskaitomi duomenys, patikrina, ar failas netuščias ir apie tai infomuoja naudotoją. Jei viskas gerai, nuskaito duomenis.  
**manual.cpp** - leidžia vartotojui ranka vesti studento duomenis arba generuoti pažymius atsitiktinai.  
**functions.cpp** - įvairių, programoje būtinų funkcijų realizacijos (įvesties, išvesties ir t.t.).  



