# V1.0.1
Programa dirba su 3 skirtingais konteineriais vector, list ir deque ir studentų duomenis saugo į bendrą ir blogų konteinerius.
Programos paleidžiamąjį failą main.exe galima sukurti atsidarius konsolę visų failų aplanke ir parašius komandą make vector, make list, make deque, priklausomai nuo konteinerio tipo.


Programos sparta
![1container1](https://user-images.githubusercontent.com/99315244/163714673-d412b7f0-5f6c-4404-9696-69b098ef6d92.png)
![1container2](https://user-images.githubusercontent.com/99315244/163714683-b411766b-2828-412f-bae0-7d2445d21565.png)
Programos atminties suvartojimas palyginus, jei naudoja 2 konteinerius - gerų ir blogų.
![1container3](https://user-images.githubusercontent.com/99315244/163714699-a73b73b0-4703-43ea-95bb-0e1c7d6b0240.png)

*Header failai:*  
  **file.h** - duomenų nuskaitymo iš failo funkcijos prototipas.  
  **functions.h**  - tarpinių (įvesties, išvesties ir t.t.).  
  **libraries_and_std.h** - bibliotekos, funkcijų prototipai ir std naudojamų komandų aprašas.  
  **manual.h** - ranka įvedamų duomenų funkcijos prototipas.  
  **struct.h** - studento struktūros failo nuskaitymui ir skaičiavimams.  
*Source failai:*  
**main.cpp** - pagrindinė funkcija iš kurios kreipiamasi į visas kitas funkcijas pagal naudotojo poreikį. Galima pasirinkti duomenis nuskaityti iš failo arba vesti ranka.  
**create_file.cpp** - studentų failo pagal vartotojo nustatymus generavimo funkcija.  
**file.cpp** - duomenų nuskaitymo iš failo funkcija. Patikrina, ar egzistuoja failas, iš kurio nuskaitomi duomenys, patikrina, ar failas netuščias ir apie tai infomuoja naudotoją. Jei viskas gerai, nuskaito duomenis.  
**manual.cpp** - leidžia vartotojui ranka vesti studento duomenis arba generuoti pažymius atsitiktinai.  
**functions.cpp** - tarpinės: vidurkio, medianos, įvesties, išvesties į konsolę ir t.t., funkcijos. 




