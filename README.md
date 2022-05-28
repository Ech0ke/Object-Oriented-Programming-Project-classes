# Vektorius
Padaryta std::vector konteinerio kopija. Veikia visos pagrindinės funkcijos kaip ir std::vector.

**std::vector ir Vector greičio playginimas:**   
![image](https://user-images.githubusercontent.com/99315244/170817615-030c9b17-6e40-47f2-b792-27d69911e555.png)

Pirminė išvada: mano sukurtas vektorius greičiau sudeda elementus į konteinerį, nei std::vector.   

**Tyrimas su klase Studentas:**   
 
 ![image](https://user-images.githubusercontent.com/99315244/170817977-1a95c733-2c63-4544-b1d3-c57a889fdf7d.png)

Galutinė išvada: naudojant savo vektorių klasėje, jis veikia lėčiau už srd::vector, tačiau skirtumas nėra didelis.   

*Header failai:*  
  **file.h**  duomenų nuskaitymo iš failo funkcijos antraštė. 
  **libraries_and_std.h** - bibliotekos ir std naudojamų komandų aprašas.  
  **manual.h** - ranka įvedamų duomenų funkcijos prototipas.  
  **studentas.h** - studento klasė, abstračioji žmogaus klasė ir kitos funkcijų antraštės.   
  **Vector.h** - savo vektoriaus konteinerio realizacija.   
*Source failai:*  
**main.cpp** - pagrindinė funkcija iš kurios kreipiamasi į visas kitas funkcijas pagal naudotojo poreikį. Galima pasirinkti duomenis nuskaityti iš failo arba vesti ranka.  
**create_file.cpp** - studentų failo pagal vartotojo nustatymus generavimo funkcija.  
**file.cpp** - duomenų nuskaitymo iš failo funkcija. Patikrina, ar egzistuoja failas, iš kurio nuskaitomi duomenys, patikrina, ar failas netuščias ir apie tai infomuoja naudotoją. Jei viskas gerai, nuskaito duomenis.  
**manual.cpp** - leidžia vartotojui ranka vesti studento duomenis arba generuoti pažymius atsitiktinai.  
**functions.cpp** - įvairių, programoje būtinų funkcijų realizacijos (įvesties, išvesties ir t.t.).  


