# Object-Oriented-Programming-Project
Versija V0.1
Programą sudaro 2 failai: **main.cpp** ir **masyvai.cpp**.
**main.cpp** aprašyta programos realizacija su namų darbų saugojimu į vektorių konteinerį.
Pradžioje paklausiama, kiek bus studentų, tiek ir sukuriama dinaminių studento struktūros masyvų. Studento struktūra susideda iš:
vardo, pavardės, namų darbų konteinerio, egzamino balo, namų darbų rezultatų sumos, apskaičiuoto galutinio balo naudojant vidurkį ir medianą.
Įvedus kiek yra studentų, prašoma pirmojo vardo ir pavardės, po to paklausiama, kaip vartotojas nori įvesti studento rezultatus (namų darbų ir egzamino). "While" ciklo pagalba gavus teisingą pasirinkimą iš 2 siūlomų variantų (įvedimo ranka ar generuojamų atsitiktinai), prašoma įvesti pažymį arba parodomas sugeneruotas pažymys ir iškeliama užklausa, ar dar yra pažymių.
Gavus visus namų darbų rezultatus, užklausiamas arba sugeneruojamas egzamino balas. Po to, jei dar yra studentų, užklausiamas kitas studento vardas, pavardė ir t.t. Tada kreipiamasi į vidurkio bei medianos funkcijas, kad apskaičiuoti galutinį balą.
Skaičiuojant medianą, namų darbų vektorių konteineris išrūšiuojamas pažymių didėjimo tvarka funkcijos "sort" pagalba.
Galiausiai suskaičiuojamas galutinis pažymys. Programa užklausia vartotojo, kaip jis norės matyti rezultatus. "Switch" operatoriaus pagalba, programa gavus įvestį "1" - atspausdina tik mokinių galutinius balus, "2" - atspausdina galutinį balą, kuris apskaičiuojamas naudojant namų darbų medianą, "3" atspausdina "1" ir "2" variantus kartu.

**masyvai.cpp** yra užkomentuotas, nes nekūriau atskiro projekto ir neužkomentavus dubliuotųsi priskyrimai, bendrai projektas nepasileistų. Norint paleisti **masyvai.cpp**, reikia užkomentuoti **main.cpp** ir atkomentuoti **masyvai.cpp**. Ši programos realizacija įgyvndinta tokiu pat principu kaip ir **main.cpp**, tik namų darbų rezultatai saugomi į statinį masyvą ir skaičiuojama kiek yra įvesta namų darbų pažymių, kad paskui efektyviai apskaičiuoti medianą ir vidurkį.

