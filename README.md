# 1v1 duel

## Descriere proiect
1v1 duel este un joc tip duel turn based între 2 jucători. Fiecare jucător își alege caracterul și  se folosește de actiunile
acestuia cât de bine poate pentru a câștiga duelul.

## Descriere tehnica

Aplicatia se bazeaza pe principiile de programare orientata pe obiect. Jocul este stabilit si inceput de clasa `Game`.
Prin aceasta clasa se adauga 2 jucatori din clasa `Player` care au ca referinta un caracter definit prin clasa `Character`
si clasele derivate `Swordsman`, `Archer`, `Mage`, care implementeaza atacuri specifice

## Rularea proiectului
Pentru a clona local proiectul folosiți:
```
git clone https://github.com/ralexgt/OOP.git
```
---
Pentru build veți avea nevoie de CMake si cel putin g++-11.

Pentru build-ul initial folosiți:
```
cmake -S . -B build
```
Pentru compilare folosiți:
```
cmake --build build -j6
```
Pentru rulare se va folosi din rădăcina proiectului:
```
./build/oop
```

## Utilizare
La rularea jocului, implicit vor fi adăugați 2 jucatori. Jocul are loc in linia de comanda.
Pe rând, jucătorii vor fi îndemnați să își aleagă una
dintre cele 3 clase: Swordsman, Archer, Mage. Dupa ce amândoi jucătorii își aleg clasa duelul începe și jucătorii au
opțiunile de a ataca normal, a folosi o abilitate specială care costă resurse (de exemplu mana) sau a se odihni pentru
a își regenera o parte din viață și resurse (în acest exemplu mana).

## Milestone #0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Milestone #1

#### Cerințe
- [x] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [x] constructori de inițializare cu parametri
- [x] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare a claselor definite:
  - preferabil sub formă de teste unitare, mai ales dacă vorbim de aplicații consolă
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Milestone #2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [x] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [x] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [x] apelarea constructorului din clasa de bază din constructori din derivate
  - [x] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [x] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [x] smart pointers (recomandat, opțional)
- [x] excepții
  - [x] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [x] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [x] funcții și atribute `static`
- [x] STL
- [x] cât mai multe `const`
- [x] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [x] tag de `git`: de exemplu `v0.2`

## Milestone #3

#### Cerințe
- [x] 2 șabloane de proiectare (design patterns)
- [x] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [x] tag de `git`: de exemplu `v0.3` sau `v1.0`