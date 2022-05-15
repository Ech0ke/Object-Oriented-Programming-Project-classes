# V2.0

Programos diegimo instrukcija:
1. Atsisiunčiame ir paleidžiame "V2.0_x64.msi" savo kompiuteryje.   
Tada:   

![image](https://user-images.githubusercontent.com/99315244/168490195-a2624dda-5c6d-4e7e-869b-5eeda0a702cd.png)
![image](https://user-images.githubusercontent.com/99315244/168490240-884c5208-3365-45f0-b48a-10d5a4749eca.png)
![image](https://user-images.githubusercontent.com/99315244/168490249-ccfc24a5-8d7f-49b2-ad8d-ee77d1e1bd46.png)
![image](https://user-images.githubusercontent.com/99315244/168490260-1b06a7c4-0b25-4dff-9e7a-b3b1b427aff0.png)
![image](https://user-images.githubusercontent.com/99315244/168490284-c58fec65-5d85-475c-9b18-5cf725a1cbb7.png)

Programos veikimo sparta:   
![image](https://user-images.githubusercontent.com/99315244/168490550-23bbc513-7bbf-4565-8ad7-052f2cc70202.png)

Aprašas:   
Programoje yra abstrakčioji klasė "Zmogus", kuri saugo studento vardą ir pavardę.   
Programoje įgyvendinta rule-of-three: yra destruktorius, kopojavimo konstruktorius, priskyrimo operatorius.   
Programa dirba su vector konteineriu ir turi studento klasę su privačiais kintamaisiais ir viešu interfeisu (komandomis).
Programos paleidžiamąjį failą "main.exe" galima sukurti atsidarius konsolę visų failų aplanke ir parašyti komandą make vector.


*Header failai:*  
  **file.h**  duomenų nuskaitymo iš failo funkcijos antraštė. 
  **libraries_and_std.h** - bibliotekos ir std naudojamų komandų aprašas.  
  **manual.h** - ranka įvedamų duomenų funkcijos prototipas.  
  **studentas.h** - studento klasė, abstračioji žmogaus klasė ir kitos funkcijų antraštės.  
*Source failai:*  
**main.cpp** - pagrindinė funkcija iš kurios kreipiamasi į visas kitas funkcijas pagal naudotojo poreikį. Galima pasirinkti duomenis nuskaityti iš failo arba vesti ranka.  
**create_file.cpp** - studentų failo pagal vartotojo nustatymus generavimo funkcija.  
**file.cpp** - duomenų nuskaitymo iš failo funkcija. Patikrina, ar egzistuoja failas, iš kurio nuskaitomi duomenys, patikrina, ar failas netuščias ir apie tai infomuoja naudotoją. Jei viskas gerai, nuskaito duomenis.  
**manual.cpp** - leidžia vartotojui ranka vesti studento duomenis arba generuoti pažymius atsitiktinai.  
**functions.cpp** - įvairių, programoje būtinų funkcijų realizacijos (įvesties, išvesties ir t.t.).  
